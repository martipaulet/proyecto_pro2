#include "CourseSet.hh"


CourseSet::CourseSet() {
}

void CourseSet::AddFromConsole() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        Course aux;
        int sc;
        cin >> sc;
        for (int j = 0; j < sc; ++j) {
            string s;
            cin >> s;
            aux.InsertOnList(s);                //Hacer en hh tambien
        }
        Course_vec.push_back(aux);
    }
}

void CourseSet::ListCourseSet(){
    int size = Size();
    for (int i = 0; i < size; ++i) {
            Course_vec[i].PrintCourse(i);
    }
}

int CourseSet::ListCourse(int id_course){
    if (0 < id_course and id_course <= Course_vec.size()) {
        Course_vec[id_course-1].PrintCourse(id_course-1);
        return 0;
    }
    return -1;
}


int CourseSet::Size() const {
    return Course_vec.size();
}
