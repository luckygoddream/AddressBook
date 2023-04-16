/**
 * 通讯录管理系统
 */
#include <iostream>
using namespace std;
#include <unistd.h>
#define MAX 1000
//联系人结构体
struct Person{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct AddressBoods{
    Person personArr[MAX];
    int size;

};

void addPerson(AddressBoods * abs){
    if (abs->size == MAX){
        cout << "通讯录已满，无法添加" <<endl;
    } else{
        //添加联系人
        string name ;
        cout<<"请输入姓名: " <<endl;
        cin >> name;
        abs->personArr[abs->size].name = name;
        cout<<"请输入性别: " <<endl;
        cout<<"1----男" <<endl;
        cout<<"2----女" <<endl;
        int sex = 0;
        while (true){
            //输入错误重新输入
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->personArr[abs->size].sex = sex;
                break;
            }
            cout << "请输入正确的性别！！！" <<endl;
        }
        cout<<"请输入年龄: " <<endl;
        int age = 0;
        cin >> age;
        abs->personArr[abs->size].age = age;

        cout<<"请输入联系电话: " <<endl;
        string phone ;
        cin >> phone;
        abs->personArr[abs->size].phone = phone;

        cout<<"请输入家庭住址: " <<endl;
        string address ;
        cin >> address;
        abs->personArr[abs->size].address = address;
        //更新通讯录人数
        abs->size++;
        cout << "添加成功" << endl;
    }
//    pause();
//    //清屏
//    system("clear");
}

void showPerson(AddressBoods * abs){
    if (abs->size == 0){
        cout<< "当前记录为空" << endl;
    } else {
        for (int i = 0; i < abs->size; i++) {
            cout<< "姓名：" << abs->personArr[i].name <<"\t";
            cout<< "年龄：" << abs->personArr[i].age <<"\t";cout<< "性别：" <<( abs->personArr[i].sex == 1 ? "男" : "女")<<"\t";

        }
    }
}

//判断是否存在
int isExist(AddressBoods * abs, string name){
    for (int i = 0; i < abs->size; i++) {
        if (abs->personArr[i].name == name){
            return i;
        } else {
            return -1;
        }
    }
}

void deletePerson(AddressBoods * abs){
    cout<< "请输入要删除的人" <<endl;
    string name;
    cin >> name;
    int i = isExist(abs,name);
    if (i == -1){
        cout << "查无此人" << endl;
    } else{
        for (int j = i; j < abs->size; j++) {
            abs->personArr[i] = abs->personArr[i+1];
        }
    }
    //删了通讯录人数记得减1
    abs->size--;
//    pause();
//    //清屏
//    system("clear");

}
void findPerson(AddressBoods * abs){
    cout<< "请输入需要查找的联系人" << endl;
    string name ;
    cin >> name;
    int i = isExist(abs,name);
    if (i != -1){
        Person person =  abs->personArr[i];
        cout<< "姓名：" << person.name <<"\t";
        cout<< "年龄：" << person.age <<"\t";cout<< "性别：" <<(person.sex == 1 ? "男" : "女")<<"\t";
    }
//    pause();
//    //清屏
//    system("clear");
}

void modifyPerson(AddressBoods * abs){
    cout<< "请输入需要修改的联系人" << endl;
    string name ;
    cin >> name;
    int i = isExist(abs,name);
    if (i == -1){
        cout << "查无此人" << endl;
    } else{
        //添加联系人
        string name ;
        cout<<"请输入姓名: " <<endl;
        cin >> name;
        abs->personArr[abs->size].name = name;
        cout<<"请输入性别: " <<endl;
        cout<<"1----男" <<endl;
        cout<<"2----女" <<endl;
        int sex = 0;
        while (true){
            //输入错误重新输入
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->personArr[abs->size].sex = sex;
                break;
            }
            cout << "请输入正确的性别！！！" <<endl;
        }
        cout<<"请输入年龄: " <<endl;
        int age = 0;
        cin >> age;
        abs->personArr[abs->size].age = age;

        cout<<"请输入联系电话: " <<endl;
        string phone ;
        cin >> phone;
        abs->personArr[abs->size].phone = phone;

        cout<<"请输入家庭住址: " <<endl;
        string address ;
        cin >> address;
        abs->personArr[abs->size].address = address;

        cout << "修改成功" << endl;
    }
//    pause();
//    //清屏
//    system("clear");
}

void cleanPerson(AddressBoods * abs){
    abs->size = 0;
    cout << "通讯录清空成功" <<endl;
//    pause();
//    //清屏
//    system("clear");
}

//菜单
void sendMenu(){
    cout << "***********************"<<endl;
    cout << "***** 1、添加联系人 *****" <<endl;
    cout << "***** 2、显示联系人 *****" <<endl;
    cout << "***** 3、删除联系人 *****" <<endl;
    cout << "***** 4、查找联系人 *****" <<endl;
    cout << "***** 5、修改联系人 *****" <<endl;
    cout << "***** 6、清空联系人 *****" <<endl;
    cout << "***** 0、退出通讯录 *****" <<endl;
    cout << "***********************"<<endl;

}




int main() {

    //创建通讯录结构体变量
    AddressBoods abs;
    abs.size = 0;

    int select = 0;//用户选择操作
    while (true){
        sendMenu();
        cin >> select;
        switch (select) {
            case 1:
                addPerson(&abs);//地址传递
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
                deletePerson(&abs);
                break;
            case 4:
                findPerson(&abs);
                break;
            case 5:
                modifyPerson(&abs);
                break;
            case 6:
                cleanPerson(&abs);
                break;
            case 0:
                cout << "欢迎下次使用" <<endl;
                break;
            default:
                break;
        }

    }


    pause();
    return 0;
}
