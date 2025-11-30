//
// Created by revanth on 30.11.25.
//

#include "smart_pointers.hpp"

unique_ptr<vector<shared_ptr<Test>>> make()
{
    return make_unique<vector<shared_ptr<Test>>>();
}

void fill(vector<shared_ptr<Test>> &ptrobj, int num){
    int tmp;
    for(int i=1;i<=num;i++)
    {
        cout<< "Enter data point ["<< i<<"] : ";
        cin>>tmp;
        //shared_ptr<Test> ptr = make_shared<Test>(tmp);
        //ptrobj.push_back(tmp);
        //ptrobj = make();
        ptrobj.push_back(make_shared<Test>(tmp));
    }
}

void display(const std::vector<std::shared_ptr<Test>>&vec) {
    std::cout << "\nDisplaying vector data" << std::endl;
    std::cout << "=======================" << std::endl;
    for (const auto &ptr: vec)
        std::cout << ptr->get_data() << std::endl;

    std::cout << "=======================" << std::endl;
}


int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}