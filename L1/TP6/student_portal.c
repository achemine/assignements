#include <stdio.h>
#include <string.h>
#include <time.h>
#define BIN_FILE "students.bin"
#define CSV_FILE "students.csv" // BONUS
#define LOG_FILE "activity.log"
#define TOTAL_CREDITS_REQUIRED 120
#define MAX_RECORDS 100

typedef struct
{
    int id;
    char name[50];
    float gpa;
    int credits_completed;
    int deleted; // tombstone: 0 = active, 1 = soft-deleted
} Student;

// prototypes
void log_action(const char *action, const char *detail);
void save_all(Student registry[], int total);
int load_all(Student registry[]);
void update_gpa(int student_id, float new_gpa);
void soft_delete(int id);
void display_from_file(void);
void compact(void);
void search_by_id(int id); // BONUS
void export_to_csv(void);  // BONUS
float graduation_progress(Student s);
void print_student_card(Student s);

int main(void)
{
    int choice;
    do
    {
        printf("\n=== University Portal -- Persistence ===\n");
        printf("1. Save 3 sample students to binary file\n");
        printf("2. Load and display from file\n");
        printf("3. Update a student GPA (in-place)\n");
        printf("4. Soft-delete a student (tombstone)\n");
        printf("5. Compact file (remove deleted records)\n");
        printf("6. View activity log\n");
        printf("7. Search by ID (fseek)\n"); // BONUS
        printf("8. Export to CSV\n");        // BONUS
        printf("0. Exit\n> ");
        if (scanf("%d", &choice) != 1)
            break;

        if (choice == 1)
        {
            Student arr[3] = {
                {1001, "Alice", 3.8f, 90, 0},
                {1002, "Bob", 2.9f, 60, 0},
                {1003, "Carol", 1.7f, 45, 0}};
            save_all(arr, 3);
            printf("3 sample students saved.\n");
        }
        else if (choice == 2)
        {
            display_from_file();
        }
        else if (choice == 3)
        {
            int id;
            float gpa;
            printf("Student ID: ");
            scanf("%d", &id);
            printf("New GPA: ");
            scanf("%f", &gpa);
            update_gpa(id, gpa);
        }
        else if (choice == 4)
        {
            int id;
            printf("Student ID to delete: ");
            scanf("%d", &id);
            soft_delete(id);
        }
        else if (choice == 5)
        {
            compact();
        }
        else if (choice == 6)
        {
            FILE *f = fopen(LOG_FILE, "r");
            if (!f)
            {
                printf("No log yet.\n");
                continue;
            }
            char line[300];
            while (fgets(line, sizeof(line), f))
                printf("%s", line);
            fclose(f);
        }
        else if (choice == 7)
        { // BONUS
            int id;
            printf("Student ID to search: ");
            scanf("%d", &id);
            search_by_id(id);
        }
        else if (choice == 8)
        { // BONUS
            export_to_csv();
        }
        else if (choice != 0)
        {
            printf("Invalid option. Try again.\n");
        }
    } while (choice != 0);
    printf("Goodbye.\n");
    return 0;
}

// Step 3.1 - log_action: append timestamped entry to activity.log
void log_action(const char *action, const char *detail)
{
    FILE *f = fopen(LOG_FILE, "a");
    if (!f)
        return;
    char buf[30];
    time_t t = time(NULL);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&t));
    fprintf(f, "[%s] %-12s | %s\n", buf, action, detail);
    fclose(f);
}

// Step 3.2 - save_all: write count + all records to binary file
void save_all(Student registry[], int total)
{
    FILE *f = fopen(BIN_FILE, "wb");
    if (!f)
    {
        printf("Cannot open file for writing.\n");
        return;
    }
    fwrite(&total, sizeof(int), 1, f);
    fwrite(registry, sizeof(Student), total, f);
    fclose(f);
    log_action("SAVE", "Full registry saved to binary file");
}

// Step 3.2 - load_all: read count + records from binary file
int load_all(Student registry[])
{
    FILE *f = fopen(BIN_FILE, "rb");
    if (!f)
    {
        printf("Cannot open file for reading.\n");
        return 0;
    }
    int n = 0;
    fread(&n, sizeof(int), 1, f);
    fread(registry, sizeof(Student), n, f);
    fclose(f);
    log_action("LOAD", "Registry loaded from binary file");
    return n;
}

// Step 3.3 - update_gpa: in-place update using fseek
void update_gpa(int student_id, float new_gpa)
{
    FILE *f = fopen(BIN_FILE, "rb+");
    if (!f)
    {
        printf("Cannot open file.\n");
        return;
    }
    int n = 0;
    fread(&n, sizeof(int), 1, f);
    for (int i = 0; i < n; i++)
    {
        long pos = sizeof(int) + (long)i * sizeof(Student);
        fseek(f, pos, SEEK_SET);
        Student s;
        fread(&s, sizeof(Student), 1, f);
        if (s.id == student_id && !s.deleted)
        {
            float old = s.gpa;
            s.gpa = new_gpa;
            fseek(f, pos, SEEK_SET);
            fwrite(&s, sizeof(Student), 1, f);
            char detail[100];
            sprintf(detail, "ID %d (%s): GPA %.2f -> %.2f",
                    s.id, s.name, old, new_gpa);
            log_action("UPDATE_GPA", detail);
            printf("GPA updated successfully.\n");
            fclose(f);
            return;
        }
    }
    printf("Student ID %d not found.\n", student_id);
    fclose(f);
}

// Step 3.4 - soft_delete: tombstone technique
void soft_delete(int id)
{
    FILE *f = fopen(BIN_FILE, "rb+");
    if (!f)
    {
        printf("Cannot open file.\n");
        return;
    }
    int n = 0;
    fread(&n, sizeof(int), 1, f);
    for (int i = 0; i < n; i++)
    {
        long pos = sizeof(int) + (long)i * sizeof(Student);
        fseek(f, pos, SEEK_SET);
        Student s;
        fread(&s, sizeof(Student), 1, f);
        if (s.id == id && !s.deleted)
        {
            s.deleted = 1;
            fseek(f, pos, SEEK_SET);
            fwrite(&s, sizeof(Student), 1, f);
            char detail[100];
            sprintf(detail, "ID %d (%s) marked as deleted", s.id, s.name);
            log_action("DELETE", detail);
            printf("Student %s (ID %d) soft-deleted.\n", s.name, s.id);
            fclose(f);
            return;
        }
    }
    printf("Student ID %d not found.\n", id);
    fclose(f);
}

// Step 3.5 - display_from_file: show only active records
void display_from_file(void)
{
    FILE *f = fopen(BIN_FILE, "rb");
    if (!f)
    {
        printf("No binary file found.\n");
        return;
    }
    int n = 0;
    fread(&n, sizeof(int), 1, f);
    printf("# ID Name GPA Credits\n");
    printf("--------------------------------------------------------\n");
    int shown = 0;
    for (int i = 0; i < n; i++)
    {
        Student s;
        fread(&s, sizeof(Student), 1, f);
        if (!s.deleted)
        {
            printf("[%d] ID: %d | %s | GPA: %.2f | Credits: %d\n",
                   i, s.id, s.name, s.gpa, s.credits_completed);
            shown++;
        }
    }
    if (shown == 0)
        printf("No active students in file.\n");
    fclose(f);
    log_action("LOAD", "Registry loaded from binary file");
}

// Step 3.6 - compact: permanently remove tombstone records
void compact(void)
{
    FILE *src = fopen(BIN_FILE, "rb");
    if (!src)
    {
        printf("Cannot open source file.\n");
        return;
    }
    FILE *tmp = fopen("tmp_compact.bin", "wb");
    if (!tmp)
    {
        fclose(src);
        return;
    }
    int n = 0;
    fread(&n, sizeof(int), 1, src);
    Student active[MAX_RECORDS];
    int ac = 0, dc = 0;
    for (int i = 0; i < n; i++)
    {
        Student s;
        fread(&s, sizeof(Student), 1, src);
        if (!s.deleted)
            active[ac++] = s;
        else
            dc++;
    }
    fclose(src);
    fwrite(&ac, sizeof(int), 1, tmp);
    fwrite(active, sizeof(Student), ac, tmp);
    fclose(tmp);
    remove(BIN_FILE);
    rename("tmp_compact.bin", BIN_FILE);
    char detail[100];
    sprintf(detail, "%d deleted records removed, %d active kept", dc, ac);
    log_action("COMPACT", detail);
    printf("Compaction done: %d removed, %d kept.\n", dc, ac);
}

// BONUS - search_by_id: jump directly to each record using fseek
void search_by_id(int id)
{
    FILE *f = fopen(BIN_FILE, "rb");
    if (!f)
    {
        printf("No binary file found.\n");
        return;
    }
    int n = 0;
    fread(&n, sizeof(int), 1, f);
    for (int i = 0; i < n; i++)
    {
        long pos = sizeof(int) + (long)i * sizeof(Student);
        fseek(f, pos, SEEK_SET); // jump directly to record i
        Student s;
        fread(&s, sizeof(Student), 1, f);
        if (s.id == id && !s.deleted)
        {
            printf("[%d] ID: %d | %s | GPA: %.2f | Credits: %d\n",
                   i, s.id, s.name, s.gpa, s.credits_completed);
            fclose(f);
            return;
        }
    }
    printf("Student ID %d not found (or deleted).\n", id);
    fclose(f);
}

// BONUS - export_to_csv: write active records to students.csv
void export_to_csv(void)
{
    FILE *bin = fopen(BIN_FILE, "rb");
    if (!bin)
    {
        printf("No binary file found.\n");
        return;
    }
    FILE *csv = fopen(CSV_FILE, "w");
    if (!csv)
    {
        fclose(bin);
        printf("Cannot create CSV.\n");
        return;
    }
    fprintf(csv, "ID,Name,GPA,Credits\n");
    int n = 0;
    fread(&n, sizeof(int), 1, bin);
    int exported = 0;
    for (int i = 0; i < n; i++)
    {
        Student s;
        fread(&s, sizeof(Student), 1, bin);
        if (!s.deleted)
        {
            fprintf(csv, "%d,%s,%.2f,%d\n",
                    s.id, s.name, s.gpa, s.credits_completed);
            exported++;
        }
    }
    fclose(bin);
    fclose(csv);
    char detail[100];
    sprintf(detail, "%d active records exported to %s", exported, CSV_FILE);
    log_action("EXPORT_CSV", detail);
    printf("Exported %d active students to %s.\n", exported, CSV_FILE);
}

float graduation_progress(Student s)
{
    return ((float)s.credits_completed / TOTAL_CREDITS_REQUIRED) * 100.0f;
}
void print_student_card(Student s)
{
    printf("\n+--------------------------------+\n");
    printf(" STUDENT ID : %d\n", s.id);
    printf(" NAME : %s\n", s.name);
    printf(" GPA : %.2f\n", s.gpa);
    printf(" PROGRESS : %.1f%% (%d / %d credits)\n",
           graduation_progress(s), s.credits_completed, TOTAL_CREDITS_REQUIRED);
    printf("+--------------------------------+\n");
}
