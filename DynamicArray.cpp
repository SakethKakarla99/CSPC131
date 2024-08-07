#include<iostream>
#include<memory>

  class DynamicArray {
  private:
  int size;
  std::unique_ptr<int[]> dynamic_array;
  int capacity;
  public:
  DynamicArray(int capacity_): size(0), capacity(capacity_) {
  dynamic_array = std::make_unique<int[]>(capacity);
  }
  void insert(int value){
  if(size==capacity){
  resize();
  }
  dynamic_array[size] = value;
  size++;
  }
  void resize(){
  capacity *= 2;
  std::unique_ptr<int[]> new_dynamic_array =
  std::make_unique<int[]>(capacity);
  for(int i=0; i<size; i++){
  new_dynamic_array[i] = dynamic_array[i];
  }
  dynamic_array = std::move(new_dynamic_array);
  }
void Traverse(){
for(int i=0; i<size; i++){
std::cout<<dynamic_array[i]<<" ";
}
std::cout<<std::endl;
}
void pop(){
if(size>0){
size--;
}
if(size<capacity/4){
shrink();
}
}
void shrink(){
capacity /= 2;
std::unique_ptr<int[]> new_dynamic_array =
std::make_unique<int[]>(capacity);
for(int i=0; i<size; i++){
new_dynamic_array[i] = dynamic_array[i];
}
dynamic_array = std::move(new_dynamic_array);
}
void gerCapacity(){
std::cout<<capacity<<std::endl;
}
};
int main(){
DynamicArray d(2);
d.insert(1);
d.insert(2);
d.gerCapacity();
d.insert(3);
d.gerCapacity();
d.insert(4);
d.insert(5);
d.gerCapacity();
d.Traverse();
d.pop();
d.pop();
d.pop();
d.pop();
d.gerCapacity();
d.Traverse();
return 0;
}