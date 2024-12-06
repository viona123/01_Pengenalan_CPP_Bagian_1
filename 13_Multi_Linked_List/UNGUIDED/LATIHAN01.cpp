#include <iostream>
#include <string>

using namespace std;

struct ProjectNode {
    string project_name;
    int duration;  // Durasi dalam bulan
    ProjectNode* next;

    ProjectNode(string name, int dur) : project_name(name), duration(dur), next(nullptr) {}
};

struct EmployeeNode {
    string employee_name;
    string employee_id;
    ProjectNode* projects;  
    EmployeeNode* next;

    EmployeeNode(string name, string id) : employee_name(name), employee_id(id), projects(nullptr), next(nullptr) {}
};

class EmployeeProjectManager {
private:
    EmployeeNode* head;  

public:
    EmployeeProjectManager() : head(nullptr) {}

    void addEmployee(string name, string id) {
        EmployeeNode* new_employee = new EmployeeNode(name, id);
        if (!head) {
            head = new_employee;
        } else {
            EmployeeNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_employee;
        }
    }

    void addProjectToEmployee(string employee_id, string project_name, int duration) {
        EmployeeNode* employee = findEmployee(employee_id);
        if (employee) {
            ProjectNode* new_project = new ProjectNode(project_name, duration);
            if (!employee->projects) {
                employee->projects = new_project;
            } else {
                ProjectNode* current = employee->projects;
                while (current->next) {
                    current = current->next;
                }
                current->next = new_project;
            }
        } else {
            cout << "Employee with ID " << employee_id << " not found." << endl;
        }
    }

    EmployeeNode* findEmployee(string employee_id) {
        EmployeeNode* current = head;
        while (current) {
            if (current->employee_id == employee_id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void removeProjectFromEmployee(string employee_id, string project_name) {
        EmployeeNode* employee = findEmployee(employee_id);
        if (employee) {
            ProjectNode* current = employee->projects;
            ProjectNode* prev = nullptr;
            while (current) {
                if (current->project_name == project_name) {
                    if (prev) {
                        prev->next = current->next;
                    } else {
                        employee->projects = current->next;
                    }
                    delete current;
                    cout << "Project " << project_name << " removed from employee " << employee->employee_name << "." << endl;
                    return;
                }
                prev = current;
                current = current->next;
            }
            cout << "Project " << project_name << " not found for employee " << employee->employee_name << "." << endl;
        } else {
            cout << "Employee with ID " << employee_id << " not found." << endl;
        }
    }

    void displayData() {
        EmployeeNode* current_employee = head;
        while (current_employee) {
            cout << "Employee: " << current_employee->employee_name << " (ID: " << current_employee->employee_id << ")" << endl;
            ProjectNode* current_project = current_employee->projects;
            while (current_project) {
                cout << "  Project: " << current_project->project_name << ", Duration: " << current_project->duration << " months" << endl;
                current_project = current_project->next;
            }
            current_employee = current_employee->next;
        }
    }

    ~EmployeeProjectManager() {
        EmployeeNode* current_employee = head;
        while (current_employee) {
            ProjectNode* current_project = current_employee->projects;
            while (current_project) {
                ProjectNode* temp = current_project;
                current_project = current_project->next;
                delete temp;
            }
            EmployeeNode* temp = current_employee;
            current_employee = current_employee->next;
            delete temp;
        }
    }
};

int main() {
    EmployeeProjectManager manager;

    cout << "1. Masukkan data pegawai berikut:" << endl;
    manager.addEmployee("Andi", "P001");
    manager.addEmployee("Budi", "P002");
    manager.addEmployee("Citra", "P003");
    cout << "  - Pegawai 1: Nama = \"Andi\", ID = \"P001\"." << endl;
    cout << "  - Pegawai 2: Nama = \"Budi\", ID = \"P002\"." << endl;
    cout << "  - Pegawai 3: Nama = \"Citra\", ID = \"P003\"." << endl;

    cout << "\n2. Tambahkan proyek ke pegawai:" << endl;
    manager.addProjectToEmployee("P001", "Aplikasi Mobile", 12);
    manager.addProjectToEmployee("P002", "Sistem Akuntansi", 8);
    manager.addProjectToEmployee("P003", "E-commerce", 10);
    cout << "  - Proyek 1: Nama = \"Aplikasi Mobile\", Durasi = 12 bulan (Untuk Andi)." << endl;
    cout << "  - Proyek 2: Nama = \"Sistem Akuntansi\", Durasi = 8 bulan (Untuk Budi)." << endl;
    cout << "  - Proyek 3: Nama = \"E-commerce\", Durasi = 10 bulan (Untuk Citra)." << endl;

    cout << "\n3. Tambahkan proyek baru:" << endl;
    manager.addProjectToEmployee("P001", "Analisis Data", 6);
    cout << "  - Proyek 4: Nama = \"Analisis Data\", Durasi = 6 bulan (Untuk Andi)." << endl;

    cout << "\n4. Hapus proyek baru:\"Aplikasi Mobile\" dari Andi." << endl;
    manager.removeProjectFromEmployee("P001", "Aplikasi Mobile");

    cout << "\n5. Tampilkan data pegawai dan proyek mereka." << endl;
    manager.displayData();

    return 0;
}

