---
title: "Operador Handle to Object (^) (extens&#245;es de componentes C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "^ handle to object [C++]"
ms.assetid: 70c411e6-be57-4468-a944-6ea7be89f392
caps.latest.revision: 26
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador Handle to Object (^) (extens&#245;es de componentes C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O *declarator de gerenciamento* \(`^`, pronunciado "hat"\), altera o [especificador](../cpp/overview-of-declarators.md) de tipo para indicar que o objeto declarado deve ser excluído automaticamente quando o sistema determinar que o objeto não está mais acessível.  
  
## Acessando o objeto declarado  
 Uma variável declarada com o declarator de gerenciamento se comporta como um ponteiro para o objeto.  No entanto, os pontos variáveis ao objeto inteiro não podem apontar para um membro do objeto, e não oferecem suporte a aritmética do ponteiro.  Use o operador de engano \(`*`\) para acessar o objeto, e o operador de acesso a membro de seta \(`->`\) para acessar um membro do objeto.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 O compilador usa o mecanismo de *contagem de referência* COM para determinar se o objeto não está sendo usado e pode ser excluído.  Isso é possível porque um objeto que é derivado de uma interface de Tempo de Execução do Windows é realmente um objeto COM.  A contagem de referência é incrementada quando o objeto é criado ou copiado, e reduzida quando o objeto é definido como nulo ou sai do escopo.  Se a contagem de referência chegar a zero, o objeto será excluído automaticamente e imediatamente.  
  
 A vantagem do declarator de gerenciamento é que no COM é necessário gerenciar explicitamente a contagem de referência para um objeto, o que é um processo tedioso e passível de erros.  Ou seja, para incrementar e reduzir a contagem de referência, é necessário chamar os métodos AddRef\(\) e Release\(\) do objeto.  No entanto, se você declarar um objeto com o declarator de forma, o compilador do Visual C\+\+ gerará um código que ajusta automaticamente a contagem de referência.  
  
 Para obter informações sobre como criar uma instância de um objeto, consulte [ref new](../windows/ref-new-gcnew-cpp-component-extensions.md).  
  
## Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 O sistema usa o mecanismo de *coletor de lixo* CLR para determinar se o objeto não está sendo usado e pode ser excluído.  O Common Language Runtime mantém uma heap em que atribui objetos, e usa referências gerenciadas \(variáveis\) em seu programa para indicar o local dos objetos na heap.  Quando um objeto não é mais utilizado, a memória ocupada pelo mesmo na heap é liberada.  Periodicamente, o coletor de lixo compacta a heap para melhorar o uso da memória liberada.  Compactar a heap poderá mover os objetos na heap, invalidando os locais referenciados por referências gerenciadas.  No entanto, o coletor de lixo está ciente do local de todas as referências gerenciadas, e as atualiza automaticamente para indicar o local atual dos objetos na heap.  
  
 Como os ponteiros nativos de C\+\+ \(`*`\) e as referências \(`&`\) são referências não gerenciadas, o coletor de lixo não pode atualizar automaticamente os endereços para os quais eles apontam.  Para resolver esse problema, use o declarator de gerenciamento para especificar uma variável da qual o coletor de lixo está ciente e que pode ser atualizada automaticamente.  
  
 No Visual C\+\+ 2002 e Visual C\+\+ 2003, `__gc *` era usado para declarar um objeto na heap gerenciada.  `^` substitui `__gc *` na nova sintaxe.  
  
 Para obter mais informações, consulte [Como declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).  
  
### Exemplos  
 **Exemplo**  
  
 Este exemplo mostra como criar uma instância de um tipo de referência na heap gerenciada.  Este exemplo também mostra que você pode inicializar um identificador com outro, resultando em duas referências para o mesmo objeto na heap gerenciada do lixo coletado.  Observe que atribuir [nullptr](../windows/nullptr-cpp-component-extensions.md) a uma alça não marca o objeto para a coleta de lixo.  
  
```  
// mcppv2_handle.cpp  
// compile with: /clr  
ref class MyClass {  
public:  
   MyClass() : i(){}  
   int i;  
   void Test() {  
      i++;  
      System::Console::WriteLine(i);  
   }  
};  
  
int main() {  
   MyClass ^ p_MyClass = gcnew MyClass;  
   p_MyClass->Test();  
  
   MyClass ^ p_MyClass2;  
   p_MyClass2 = p_MyClass;  
  
   p_MyClass = nullptr;  
   p_MyClass2->Test();     
}  
```  
  
 **Saída**  
  
 **1**   
**2** **Exemplo**  
  
 O exemplo a seguir mostra como declarar um identificador para um objeto na heap gerenciada, onde o tipo de objeto é um tipo de valor convertido.  O exemplo também mostra como obter o tipo de valor do objeto convertido.  
  
```  
// mcppv2_handle_2.cpp  
// compile with: /clr  
using namespace System;  
  
void Test(Object^ o) {  
   Int32^ i = dynamic_cast<Int32^>(o);  
  
   if(i)  
      Console::WriteLine(i);  
   else  
      Console::WriteLine("Not a boxed int");  
}  
  
int main() {  
   String^ str = "test";  
   Test(str);  
  
   int n = 100;  
   Test(n);  
}  
```  
  
 **Saída**  
  
  **Não um int convertido**  
 **100** **Exemplo**  
  
 Este exemplo mostra que a linguagem comum do C\+\+ de usar um ponteiro de void\* para apontar para um objeto arbitrário foi substituída por Object^, que pode conter um identificador para qualquer classe de referência.  Também mostra que todos os tipos, como matrizes e representantes, podem ser convertidos em um objeto.  
  
```  
// mcppv2_handle_3.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Collections;  
public delegate void MyDel();  
ref class MyClass {  
public:  
   void Test() {}  
};  
  
void Test(Object ^ x) {  
   Console::WriteLine("Type is {0}", x->GetType());  
}  
  
int main() {  
   // handle to Object can hold any ref type  
   Object ^ h_MyClass = gcnew MyClass;  
  
   ArrayList ^ arr = gcnew ArrayList();  
   arr->Add(gcnew MyClass);  
  
   h_MyClass = dynamic_cast<MyClass ^>(arr[0]);  
   Test(arr);  
  
   Int32 ^ bi = 1;  
   Test(bi);  
  
   MyClass ^ h_MyClass2 = gcnew MyClass;  
  
   MyDel^ DelInst = gcnew MyDel(h_MyClass2, &MyClass::Test);  
   Test(DelInst);  
}  
```  
  
 **Saída**  
  
  **O tipo é System.Collections.ArrayList**  
 **O tipo é System.Int32**  
 **O tipo é MyDel** **Exemplo**  
  
 Este exemplo mostra que um identificador pode ser desreferenciado e que um membro pode ser acessado através de um identificador desreferenciado.  
  
```  
// mcppv2_handle_4.cpp  
// compile with: /clr  
using namespace System;  
value struct DataCollection {  
private:  
   int Size;  
   array<String^>^ x;  
  
public:  
   DataCollection(int i) : Size(i) {  
      x = gcnew array<String^>(Size);  
      for (int i = 0 ; i < Size ; i++)  
         x[i] = i.ToString();  
   }  
  
   void f(int Item) {  
      if (Item >= Size)  
      {  
         System::Console::WriteLine("Cannot access array element {0}, size is {1}", Item, Size);  
         return;  
      }  
      else  
         System::Console::WriteLine("Array value: {0}", x[Item]);  
   }  
};  
  
void f(DataCollection y, int Item) {  
   y.f(Item);  
}  
  
int main() {  
   DataCollection ^ a = gcnew DataCollection(10);  
   f(*a, 7);   // dereference a handle, return handle's object  
   (*a).f(11);   // access member via dereferenced handle  
}  
```  
  
 **Saída**  
  
  **Valor de matriz: 7**  
 **Não é possível acessar o elemento 11 da matriz, o tamanho é 10** **Exemplo**  
  
 Este exemplo mostra que uma referência nativa \(`&`\) não pode associar\-se a um membro de `int` de um tipo gerenciado, pois `int` pode ser armazenado na heap do lixo coletado, e as referências nativas não acompanham o movimento do objeto na heap gerenciada.  Isso pode ser corrigido usando uma variável local ou alterando `&` para `%`, tornando\-o uma referência de rastreamento.  
  
```  
// mcppv2_handle_5.cpp  
// compile with: /clr  
ref struct A {  
   void Test(unsigned int &){}  
   void Test2(unsigned int %){}  
   unsigned int i;  
};  
  
int main() {  
   A a;  
   a.i = 9;  
   a.Test(a.i);   // C2664  
   a.Test2(a.i);   // OK  
  
   unsigned int j = 0;  
   a.Test(j);   // OK  
}  
```  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)   
 [Tracking Reference Operator](../windows/tracking-reference-operator-cpp-component-extensions.md)