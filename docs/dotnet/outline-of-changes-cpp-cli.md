---
title: "Destaques de altera&#231;&#245;es (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: c0bbbd6b-c5c4-44cf-a6ca-c1010c377e9d
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Destaques de altera&#231;&#245;es (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esse contorno mostra exemplos de algumas das alterações no idioma das extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  Siga o link que rastreia cada item para obter mais informações.  
  
## Nenhum palavra\-chave dupla de sublinhado  
 O sublinhado vezes na frente de todas as palavras\-chave foi removido, com uma exceção.  Assim, `__value``value`se torna, se torna e `__interface``interface`, e assim por diante.  Para evitar conflitos de nome entre palavras\-chave e identificadores no código de usuário, as palavras\-chave são tratados primariamente como sensíveis ao contexto.  
  
 Consulte [Palavras\-chave da linguagem \(C\+\+\/CLI\)](../Topic/Language%20Keywords%20\(C++-CLI\).md) para maiores informações.  
  
## Declarações da classe  
 Sintaxe gerenciado de extensões:  
  
```  
__gc class Block {};                           // reference class  
__value class Vector {};                       // value class  
__interface I {};                        // interface class  
__gc __abstract class Shape {};                // abstract class  
__gc __sealed class Shape2D : public Shape {}; // derived class  
```  
  
 Nova sintaxe:  
  
```  
ref class Block {};                // reference class  
value class Vector {};             // value class  
interface class I {};        // interface class  
ref class Shape abstract {};       // abstract class  
ref class Shape2D sealed: Shape{}; // derived class  
```  
  
 Consulte [Tipos gerenciados \(C\+\+\/CL\)](../dotnet/managed-types-cpp-cl.md) para maiores informações.  
  
## Declaração de objeto  
 Sintaxe gerenciado de extensões:  
  
```  
public __gc class Form1 : public System::Windows::Forms::Form {  
private:  
   System::ComponentModel::Container __gc *components;  
   System::Windows::Forms::Button   __gc *button1;  
   System::Windows::Forms::DataGrid __gc *myDataGrid;     
   System::Data::DataSet  __gc *myDataSet;  
};  
```  
  
 Nova sintaxe:  
  
```  
public ref class Form1 : System::Windows::Forms::Form {  
   System::ComponentModel::Container^ components;  
   System::Windows::Forms::Button^ button1;  
   System::Windows::Forms::DataGrid^ myDataGrid;  
   System::Data::DataSet^ myDataSet;  
};  
```  
  
 Consulte [Declaração de um objeto de classe de referência CLR](../dotnet/declaration-of-a-clr-reference-class-object.md) para maiores informações.  
  
### Alocação gerenciado do heap  
 Sintaxe gerenciado de extensões:  
  
```  
Button* button1 = new Button; // managed heap  
int *pi1 = new int;           // native heap  
Int32 *pi2 = new Int32;       // managed heap  
```  
  
 Nova sintaxe:  
  
```  
Button^ button1 = gcnew Button;        // managed heap  
int * pi1 = new int;                   // native heap  
Int32^ pi2 = gcnew Int32;              // managed heap  
```  
  
 Consulte [Declaração de um objeto de classe de referência CLR](../dotnet/declaration-of-a-clr-reference-class-object.md) para maiores informações.  
  
### Uma referência a um objeto de controle  
 Sintaxe gerenciado de extensões:  
  
```  
// OK: we set obj to refer to no object  
Object * obj = 0;  
  
// Error: no implicit boxing  
Object * obj2 = 1;  
```  
  
 Nova sintaxe:  
  
```  
// Incorrect Translation  
// causes the implicit boxing of both 0 and 1  
Object ^ obj = 0;  
Object ^ obj2 = 1;  
  
// Correct Translation  
// OK: we set obj to refer to no object  
Object ^ obj = nullptr;  
  
// OK: we initialize obj2 to an Int32^  
Object ^ obj2 = 1;  
```  
  
 Consulte [Declaração de um objeto de classe de referência CLR](../dotnet/declaration-of-a-clr-reference-class-object.md) para maiores informações.  
  
## Declaração de matriz  
 A matriz de CLR foi alto.  É semelhante à coleção do modelo de `vector` de stl, mas mapeia para `System::Array` subjacente classificação \- isto é, não é uma implementação do modelo.  
  
 Consulte [Declaração de uma matriz CLR](../dotnet/declaration-of-a-clr-array.md) para maiores informações.  
  
### Matriz como o parâmetro  
 Sintaxe gerenciado da matriz de extensões:  
  
```  
void PrintValues( Object* myArr __gc[]);   
void PrintValues( int myArr __gc[,,]);   
```  
  
 Nova sintaxe de matriz:  
  
```  
void PrintValues( array<Object^>^ myArr );  
void PrintValues( array<int,3>^ myArr );  
```  
  
### Matriz como o tipo de retorno  
 Sintaxe gerenciado da matriz de extensões:  
  
```  
Int32 f() [];   
int GetArray() __gc[];  
```  
  
 Nova sintaxe de matriz:  
  
```  
array<Int32>^ f();  
array<int>^ GetArray();  
```  
  
### Inicialização de taquigrafia da matriz de CLR types local  
 Sintaxe gerenciado da matriz de extensões:  
  
```  
int GetArray() __gc[] {  
   int a1 __gc[] = { 1, 2, 3, 4, 5 };  
   Object* myObjArray __gc[] = { __box(26), __box(27), __box(28),  
                                 __box(29), __box(30) };  
  
   return a1;  
}  
```  
  
 Nova sintaxe de matriz:  
  
```  
array<int>^ GetArray() {  
   array<int>^ a1 = {1,2,3,4,5};  
   array<Object^>^ myObjArray = {26,27,28,29,30};  
  
   return a1;  
}  
```  
  
### Declaração explícita de matriz de CLR  
 Sintaxe gerenciado da matriz de extensões:  
  
```  
Object* myArray[] = new Object*[2];  
String* myMat[,] = new String*[4,4];  
```  
  
 Nova sintaxe de matriz:  
  
```  
array<Object^>^ myArray = gcnew array<Object^>(2);  
array<String^,2>^ myMat = gcnew array<String^,2>(4,4);  
```  
  
 Novo à linguagem: inicialização explícita da matriz que segue o gcnew  
  
```  
// explicit initialization list follow gcnew   
// is not supported in Managed Extensions  
array<Object^>^ myArray =   
   gcnew array<Object^>(4){ 1, 1, 2, 3 };  
```  
  
## Propriedades escalares  
 Sintaxe de propriedade gerenciada de extensões:  
  
```  
public __gc __sealed class Vector {  
   double _x;  
  
public:  
   __property double get_x(){ return _x; }  
   __property void set_x( double newx ){ _x = newx; }  
};  
```  
  
 Nova sintaxe da propriedade:  
  
```  
public ref class Vector sealed {   
   double _x;  
  
public:  
   property double x   
   {  
      double get()             { return _x; }  
      void   set( double newx ){ _x = newx; }  
   } // Note: no semi-colon …  
};  
```  
  
 Novo à linguagem: propriedades triviais  
  
```  
public ref class Vector sealed {   
public:  
   // equivalent shorthand property syntax  
   // backing store is not accessible  
   property double x;   
};  
```  
  
 Consulte [Declaração da propriedade](../dotnet/property-declaration.md) para maiores informações.  
  
## Propriedades indexadas  
 As extensões gerenciadas indexados a sintaxe da propriedade:  
  
```  
public __gc class Matrix {  
   float mat[,];  
  
public:   
   __property void set_Item( int r, int c, float value) { mat[r,c] = value; }  
   __property int get_Item( int r, int c ) { return mat[r,c]; }  
};  
```  
  
 Nova sintaxe indexada da propriedade:  
  
```  
public ref class Matrix {  
   array<float, 2>^ mat;  
  
public:  
   property float Item [int,int] {  
      float get( int r, int c ) { return mat[r,c]; }  
      void set( int r, int c, float value ) { mat[r,c] = value; }  
   }  
};  
```  
  
 Novo à linguagem: propriedade indexada nível classe  
  
```  
public ref class Matrix {  
   array<float, 2>^ mat;  
  
public:  
   // ok: class level indexer now  
   //     Matrix mat;  
   //     mat[ 0, 0 ] = 1;   
   //  
   // invokes the set accessor of the default indexer  
  
   property float default [int,int] {  
      float get( int r, int c ) { return mat[r,c]; }  
      void set( int r, int c, float value ) { mat[r,c] = value; }  
   }  
};  
```  
  
 Consulte [Declaração do índice de propriedade](../dotnet/property-index-declaration.md) para maiores informações.  
  
## Operadores sobrecarregados  
 Sintaxe gerenciado de sobrecarga do operador DMX:  
  
```  
public __gc __sealed class Vector {  
public:  
   Vector( double x, double y, double z );  
  
   static bool    op_Equality( const Vector*, const Vector* );  
   static Vector* op_Division( const Vector*, double );  
};  
  
int main() {  
   Vector *pa = new Vector( 0.231, 2.4745, 0.023 );  
   Vector *pb = new Vector( 1.475, 4.8916, -1.23 );   
  
   Vector *pc = Vector::op_Division( pa, 4.8916 );  
  
   if ( Vector::op_Equality( pa, pc ))  
      ;  
}  
```  
  
 Nova sintaxe da sobrecarga do operador:  
  
```  
public ref class Vector sealed {  
public:  
   Vector( double x, double y, double z );  
  
   static bool    operator ==( const Vector^, const Vector^ );  
   static Vector^ operator /( const Vector^, double );  
};  
  
int main() {  
   Vector^ pa = gcnew Vector( 0.231, 2.4745, 0.023 );  
   Vector^ pb = gcnew Vector( 1.475, 4.8916, -1.23 );  
  
   Vector^ pc = pa / 4.8916;  
   if ( pc == pa )  
      ;  
}  
```  
  
 Consulte [Operadores sobrecarregados](../dotnet/overloaded-operators.md) para maiores informações.  
  
## Operadores de conversão  
 Sintaxe gerenciado do operador de conversão de extensões:  
  
```  
__gc struct MyDouble {  
   static MyDouble* op_Implicit( int i );   
   static int op_Explicit( MyDouble* val );  
   static String* op_Explicit( MyDouble* val );   
};  
```  
  
 Nova sintaxe de operador de conversão:  
  
```  
ref struct MyDouble {  
public:  
   static operator MyDouble^ ( int i );  
   static explicit operator int ( MyDouble^ val );  
   static explicit operator String^ ( MyDouble^ val );  
};  
```  
  
 Consulte [Alterações feitas em operadores da conversão](../dotnet/changes-to-conversion-operators.md) para maiores informações.  
  
## Substituição explícita de um membro da interface  
 Sintaxe explícita de substituição de extensões gerenciadas:  
  
```  
public __gc class R : public ICloneable {  
   // to be used through ICloneable  
   Object* ICloneable::Clone();  
  
   // to be used through an R  
   R* Clone();  
};  
```  
  
 Nova sintaxe explícita de substituição:  
  
```  
public ref class R : public ICloneable {  
   // to be used through ICloneable  
   virtual Object^ InterfaceClone() = ICloneable::Clone;  
  
   // to be used through an R   
   virtual R^ Clone();  
};  
```  
  
 Consulte [Substituição explícita de um membro de interface](../dotnet/explicit-override-of-an-interface-member.md) para maiores informações.  
  
## Funções \(virtual private networks\)  
 Sintaxe virtual privada da função de extensões gerenciadas:  
  
```  
__gc class Base {  
private:  
   // inaccessible to a derived class  
   virtual void g();   
};  
  
__gc class Derived : public Base {  
public:  
   // ok: g() overrides Base::g()  
   virtual void g();  
};  
```  
  
 Nova sintaxe virtual privada da função  
  
```  
ref class Base {  
private:  
   // inaccessible to a derived class  
   virtual void g();   
};  
  
ref class Derived : public Base {  
public:  
   // error: cannot override: Base::g() is inaccessible  
   virtual void g() override;  
};  
```  
  
 Consulte [Funções virtuais particulares](../Topic/Private%20Virtual%20Functions.md) para maiores informações.  
  
## Tipo de enum de CLR  
 Sintaxe gerenciado de enum de extensões:  
  
```  
__value enum e1 { fail, pass };  
public __value enum e2 : unsigned short  {   
   not_ok = 1024,   
   maybe, ok = 2048   
};    
```  
  
 Nova sintaxe de enum:  
  
```  
enum class e1 { fail, pass };  
public enum class e2 : unsigned short {   
   not_ok = 1024,  
   maybe, ok = 2048   
};  
```  
  
 Além dessa alteração sintática pequena, o comportamento do tipo de enum de CLR foi alterado em várias maneiras:  
  
-   Uma declaração frente de um enum de CLR não tem mais suporte.  
  
-   A resolução de sobrecarga entre aritmética interno tipo e a hierarquia da classe de objeto inverteu entre extensões gerenciadas e [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  Como efeito colateral, os enum de CLR não são convertidos implicitamente em tipos aritméticos.  
  
-   Na nova sintaxe, uma enum de CLR mantém seu próprio escopo, que não é o caso em extensões gerenciadas.  Anteriormente, os enumeradores eram visíveis dentro do escopo de conteúdo de enum; agora, os enumeradores são encapsulados no escopo de enum.  
  
 Consulte [Tipo enum CLR](../dotnet/clr-enum-type.md) para maiores informações.  
  
## Remoção da palavra\-chave de \_\_box  
 Extensões gerenciadas e que a sintaxe:  
  
```  
Object *o = __box( 1024 ); // explicit boxing  
```  
  
 Nova sintaxe do com:  
  
```  
Object ^o = 1024; // implicit boxing  
```  
  
 Consulte [Uma manipulação de acompanhamento de um valor demarcado](../dotnet/a-tracking-handle-to-a-boxed-value.md) para maiores informações.  
  
## Fixando o ponteiro  
 Extensões gerenciadas que fixam a sintaxe do ponteiro:  
  
```  
__gc struct H { int j; };  
  
int main() {  
   H * h = new H;  
   int __pin * k = & h -> j;  
};  
```  
  
 Nova sintaxe fixando\-se do ponteiro:  
  
```  
ref struct H { int j; };  
  
int main() {  
   H^ h = gcnew H;  
   pin_ptr<int> k = &h->j;  
}  
```  
  
 Consulte [Semântica do tipo de valor](../Topic/Value%20Type%20Semantics.md) para maiores informações.  
  
## A palavra\-chave de \_\_typeof se torna typeid  
 Sintaxe gerenciado de typeof de extensões:  
  
```  
Array* myIntArray =   
   Array::CreateInstance( __typeof(Int32), 5 );  
```  
  
 Nova sintaxe de typeid:  
  
```  
Array^ myIntArray =   
   Array::CreateInstance( Int32::typeid, 5 );  
```  
  
 Consulte [typeof vai até T::typeid](../dotnet/typeof-goes-to-t-typeid.md) para maiores informações.  
  
## Consulte também  
 [Primer de migração C\+\+\/CLI](../dotnet/cpp-cli-migration-primer.md)   
 [\(NOTINBUILD\)Managed Extensions for C\+\+ Syntax Upgrade Checklist](http://msdn.microsoft.com/pt-br/edbded88-7ef3-4757-bd9d-b8f48ac2aada)   
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)