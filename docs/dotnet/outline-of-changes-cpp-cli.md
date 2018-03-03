---
title: "Destaques de alterações (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: c0bbbd6b-c5c4-44cf-a6ca-c1010c377e9d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: fdc0015bda5f0a6678b1d274c79445aba4e4aab0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="outline-of-changes-ccli"></a>Destaques de alterações (C++/CLI)
Essa estrutura de tópicos mostra exemplos de algumas das alterações na linguagem de extensões gerenciadas para C++ para Visual C++. Siga o link que acompanha cada item para obter mais informações.  
  
## <a name="no-double-underscore-keywords"></a>Nenhuma palavra-chave sublinhado duplo  
 O sublinhado duplo na frente de todas as palavras-chave tiver sido removido, com uma exceção. Portanto, `__value` se torna `value`, e `__interface` torna-se `interface`, e assim por diante. Para evitar conflitos de nomes entre as palavras-chave e os identificadores no código do usuário, as palavras-chave principalmente são tratadas como contextual.  
  
 Consulte [palavras-chave (C + + CLI)](../dotnet/language-keywords-cpp-cli.md) para obter mais informações.  
  
## <a name="class-declarations"></a>Declarações de classe  
 Sintaxe de extensões gerenciada:  
  
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
  
 Consulte [tipos gerenciados (C + + CL)](../dotnet/managed-types-cpp-cl.md) para obter mais informações.  
  
## <a name="object-declaration"></a>Declaração de objeto  
 Sintaxe de extensões gerenciada:  
  
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
  
 Consulte [declaração de um objeto de classe de referência CLR](../dotnet/declaration-of-a-clr-reference-class-object.md) para obter mais informações.  
  
### <a name="managed-heap-allocation"></a>Alocação de Heap gerenciado  
 Sintaxe de extensões gerenciada:  
  
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
  
 Consulte [declaração de um objeto de classe de referência CLR](../dotnet/declaration-of-a-clr-reference-class-object.md) para obter mais informações.  
  
### <a name="a-tracking-reference-to-no-object"></a>Uma referência de rastreamento para nenhum objeto  
 Sintaxe de extensões gerenciada:  
  
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
  
 Consulte [declaração de um objeto de classe de referência CLR](../dotnet/declaration-of-a-clr-reference-class-object.md) para obter mais informações.  
  
## <a name="array-declaration"></a>Declaração de matriz  
 A matriz do CLR foi reprojetada. É semelhante a stl `vector` coleção do modelo, mas mapeia para subjacente `System::Array` classe - ou seja, não é uma implementação de modelo.  
  
 Consulte [declaração de uma matriz de CLR](../dotnet/declaration-of-a-clr-array.md) para obter mais informações.  
  
### <a name="array-as-parameter"></a>Matriz como parâmetro  
 Sintaxe de matriz de extensões gerenciada:  
  
```  
void PrintValues( Object* myArr __gc[]);   
void PrintValues( int myArr __gc[,,]);   
```  
  
 Nova sintaxe de matriz:  
  
```  
void PrintValues( array<Object^>^ myArr );  
void PrintValues( array<int,3>^ myArr );  
```  
  
### <a name="array-as-return-type"></a>Matriz como tipo de retorno  
 Sintaxe de matriz de extensões gerenciada:  
  
```  
Int32 f() [];   
int GetArray() __gc[];  
```  
  
 Nova sintaxe de matriz:  
  
```  
array<Int32>^ f();  
array<int>^ GetArray();  
```  
  
### <a name="shorthand-initialization-of-local-clr-array"></a>Inicialização de forma abreviada de matriz CLR Local  
 Sintaxe de matriz de extensões gerenciada:  
  
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
  
### <a name="explicit-clr-array-declaration"></a>Declaração de matriz CLR explícita  
 Sintaxe de matriz de extensões gerenciada:  
  
```  
Object* myArray[] = new Object*[2];  
String* myMat[,] = new String*[4,4];  
```  
  
 Nova sintaxe de matriz:  
  
```  
array<Object^>^ myArray = gcnew array<Object^>(2);  
array<String^,2>^ myMat = gcnew array<String^,2>(4,4);  
```  
  
 Novo idioma: inicialização de matriz explícita que segue gcnew  
  
```  
// explicit initialization list follow gcnew   
// is not supported in Managed Extensions  
array<Object^>^ myArray =   
   gcnew array<Object^>(4){ 1, 1, 2, 3 };  
```  
  
## <a name="scalar-properties"></a>Propriedades escalares  
 Sintaxe de propriedade extensões gerenciada:  
  
```  
public __gc __sealed class Vector {  
   double _x;  
  
public:  
   __property double get_x(){ return _x; }  
   __property void set_x( double newx ){ _x = newx; }  
};  
```  
  
 Nova sintaxe de propriedade:  
  
```  
public ref class Vector sealed {   
   double _x;  
  
public:  
   property double x   
   {  
      double get()             { return _x; }  
      void   set( double newx ){ _x = newx; }  
   } // Note: no semi-colon  
};  
```  
  
 Novo idioma: propriedades triviais  
  
```  
public ref class Vector sealed {   
public:  
   // equivalent shorthand property syntax  
   // backing store is not accessible  
   property double x;   
};  
```  
  
 Consulte [declaração de propriedade](../dotnet/property-declaration.md) para obter mais informações.  
  
## <a name="indexed-properties"></a>Propriedades indexadas  
 Extensões gerenciadas indexados a sintaxe da propriedade:  
  
```  
public __gc class Matrix {  
   float mat[,];  
  
public:   
   __property void set_Item( int r, int c, float value) { mat[r,c] = value; }  
   __property int get_Item( int r, int c ) { return mat[r,c]; }  
};  
```  
  
 Nova sintaxe de propriedade indexada:  
  
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
  
 Novo idioma: propriedade indexada de nível de classe  
  
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
  
 Consulte [declaração de propriedade de índice](../dotnet/property-index-declaration.md) para obter mais informações.  
  
## <a name="overloaded-operators"></a>Operadores sobrecarregados  
 Sintaxe de sobrecarga de operador de extensões gerenciada:  
  
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
  
 Nova sintaxe de sobrecarga de operador:  
  
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
  
 Consulte [operadores sobrecarregados](../dotnet/overloaded-operators.md) para obter mais informações.  
  
## <a name="conversion-operators"></a>Operadores de conversão  
 Sintaxe de operador de conversão de extensões gerenciada:  
  
```  
__gc struct MyDouble {  
   static MyDouble* op_Implicit( int i );   
   static int op_Explicit( MyDouble* val );  
   static String* op_Explicit( MyDouble* val );   
};  
```  
  
 Nova sintaxe do operador de conversão:  
  
```  
ref struct MyDouble {  
public:  
   static operator MyDouble^ ( int i );  
   static explicit operator int ( MyDouble^ val );  
   static explicit operator String^ ( MyDouble^ val );  
};  
```  
  
 Consulte [altera para os operadores de conversão](../dotnet/changes-to-conversion-operators.md) para obter mais informações.  
  
## <a name="explicit-override-of-an-interface-member"></a>Substituição explícita de um membro de interface  
 Extensões gerenciadas explícita substituem sintaxe:  
  
```  
public __gc class R : public ICloneable {  
   // to be used through ICloneable  
   Object* ICloneable::Clone();  
  
   // to be used through an R  
   R* Clone();  
};  
```  
  
 Nova sintaxe de substituição explícita:  
  
```  
public ref class R : public ICloneable {  
   // to be used through ICloneable  
   virtual Object^ InterfaceClone() = ICloneable::Clone;  
  
   // to be used through an R   
   virtual R^ Clone();  
};  
```  
  
 Consulte [substituição explícita de um membro de Interface](../dotnet/explicit-override-of-an-interface-member.md) para obter mais informações.  
  
## <a name="private-virtual-functions"></a>Funções virtuais particulares  
 Sintaxe de função virtual particular extensões gerenciada:  
  
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
  
 Nova sintaxe de função virtual privada  
  
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
  
 Consulte [privada Virtual funções](../dotnet/private-virtual-functions.md) para obter mais informações.  
  
## <a name="clr-enum-type"></a>Tipo enum CLR  
 Sintaxe de enum extensões gerenciada:  
  
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
  
 Além dessa alteração sintática pequena, o comportamento do tipo enum CLR foi alterado de várias maneiras:  
  
-   Não há suporte para a declaração de encaminhamento de um enum CLR.  
  
-   A resolução de sobrecarga entre os tipos aritméticos internos e a hierarquia de classe de objeto inverteu entre extensões gerenciadas e Visual C++. Como um efeito colateral, o CLR enums implicitamente não são convertidos em tipos aritméticos.  
  
-   A nova sintaxe, um enum CLR mantém seu próprio escopo, que não é o caso em extensões gerenciadas. Anteriormente, enumeradores eram visíveis no escopo contentor do enum; Agora, os enumeradores são encapsuladas dentro do escopo do enum.  
  
 Consulte [tipo Enum CLR](../dotnet/clr-enum-type.md) para obter mais informações.  
  
## <a name="removal-of-box-keyword"></a>Remoção de palavra-chave de box  
 Extensões gerenciadas conversão boxing de sintaxe:  
  
```  
Object *o = __box( 1024 ); // explicit boxing  
```  
  
 Nova sintaxe de conversão boxing:  
  
```  
Object ^o = 1024; // implicit boxing  
```  
  
 Consulte [um controle identificador para um valor demarcado](../dotnet/a-tracking-handle-to-a-boxed-value.md) para obter mais informações.  
  
## <a name="pinning-pointer"></a>Ponteiro de fixação  
 Sintaxe de ponteiro de fixação de extensões gerenciadas:  
  
```  
__gc struct H { int j; };  
  
int main() {  
   H * h = new H;  
   int __pin * k = & h -> j;  
};  
```  
  
 Nova sintaxe de ponteiro de fixação:  
  
```  
ref struct H { int j; };  
  
int main() {  
   H^ h = gcnew H;  
   pin_ptr<int> k = &h->j;  
}  
```  
  
 Consulte [semântica do tipo de valor](../dotnet/value-type-semantics.md) para obter mais informações.  
  
## <a name="typeof-keyword-becomes-typeid"></a>TypeOf palavra-chave se torna typeid  
 Sintaxe de typeof extensões gerenciada:  
  
```  
Array* myIntArray =   
   Array::CreateInstance( __typeof(Int32), 5 );  
```  
  
 Nova sintaxe typeid:  
  
```  
Array^ myIntArray =   
   Array::CreateInstance( Int32::typeid, 5 );  
```  
  
 Consulte [typeof vai até t:: TypeId](../dotnet/typeof-goes-to-t-typeid.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [C + + CLI Primer de migração](../dotnet/cpp-cli-migration-primer.md)   
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)


