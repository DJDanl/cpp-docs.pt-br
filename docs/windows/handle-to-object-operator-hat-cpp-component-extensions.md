---
title: "Operador Handle to Object (^) (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: ^ handle to object [C++]
ms.assetid: 70c411e6-be57-4468-a944-6ea7be89f392
caps.latest.revision: "26"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3e760181f48e4bfd197514b152701e94ac6e94a2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="handle-to-object-operator---c-component-extensions"></a>Operador Handle to Object (^) (Extensões de Componentes C++)
O *tratar declarador* (`^`, ou "hat"), modifica o tipo [especificador](../cpp/overview-of-declarators.md) significa que o objeto declarado deve ser excluído automaticamente quando o sistema determina que o objeto é não é mais acessível.  
  
## <a name="accessing-the-declared-object"></a>Acessando o objeto declarado  
 Uma variável declarada com o identificador declarador se comporta como um ponteiro para o objeto. No entanto, o variável aponta para o objeto inteiro, não pode apontar para um membro do objeto e não dá suporte a aritmética de ponteiro. Use o operador de indireção (`*`) para acessar o objeto e o operador de acesso de membro de seta (`->`) para acessar um membro do objeto.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 O compilador usa o COM *contagem de referência* mecanismo para determinar se o objeto não está mais sendo usado e pode ser excluído. Isso é possível porque um objeto que é derivado de uma interface de tempo de execução do Windows é realmente um objeto COM. A contagem de referência é incrementada quando o objeto é criado ou copiado e reduzido quando o objeto é definido como null ou sai do escopo. Se a contagem de referência chegar a zero, o objeto é automaticamente e imediatamente excluído.  
  
 A vantagem de declarador o identificador é que, em COM você deve gerenciar explicitamente a contagem de referência para um objeto, que é um processo propenso entediante e erro. Ou seja, para incrementar e decrementar a contagem de referência, você deve chamar os métodos de AddRef e Release () do objeto. No entanto, se você declarar um objeto com o declarador de identificador, o compilador do Visual C++ gera código que se ajusta automaticamente a contagem de referência.  
  
 Para obter informações sobre como criar uma instância de um objeto, consulte [ref novo](../windows/ref-new-gcnew-cpp-component-extensions.md).  
  
## <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 O sistema usa o CLR *coletor de lixo* mecanismo para determinar se o objeto não está mais sendo usado e pode ser excluído. O common language runtime mantém uma pilha em que ele aloca objetos e referências gerenciado usa (variáveis) em seu programa indicam o local dos objetos no heap. Quando um objeto não é mais usado, a memória ocupado por ele no heap será liberada. Periodicamente, o coletor de lixo compacta heap para melhor uso de memória liberada. A compactação de heap pode mover objetos no heap, o que invalida o locais referenciado por referências gerenciadas. No entanto, o coletor de lixo está ciente do local de todas as referências gerenciadas e os atualiza automaticamente para indicar o local atual dos objetos no heap.  
  
 Como ponteiros nativos do C++ (`*`) e referências (`&`) não são gerenciadas referências, o coletor de lixo não pode atualizar automaticamente os endereços que eles apontem para. Para resolver esse problema, use o declarador de identificador para especificar uma variável que o coletor de lixo está ciente de e pode atualizar automaticamente.  
  
 No Visual C++ 2002 e 2003 do Visual C++, `__gc *` foi usado para declarar um objeto no heap gerenciado.  O `^` substitui `__gc *` na nova sintaxe.  
  
 Para obter mais informações, consulte [como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md).  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 Este exemplo mostra como criar uma instância de um tipo de referência no heap gerenciado.  Este exemplo também mostra que você pode inicializar um identificador com outra, resultando em duas referências para o mesmo objeto no heap gerenciado, coletados como lixo. Observe que atribuir [nullptr](../windows/nullptr-cpp-component-extensions.md) um identificador não marca o objeto para coleta de lixo.  
  
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
  
```Output  
1  
2  
```  
  
 **Exemplo**  
  
 O exemplo a seguir mostra como declarar um identificador para um objeto no heap gerenciado, onde o tipo de objeto é um tipo de valor Demarcado. O exemplo também mostra como obter o tipo de valor do objeto Demarcado.  
  
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
  
```Output  
Not a boxed int  
100  
```  
  
 **Exemplo**  
  
 Este exemplo mostra que o idioma C++ comuns de usar um ponteiro void * para apontar para um objeto arbitrário é substituído pelo objeto ^, que pode conter um identificador para qualquer classe de referência. Ele também mostra que todos os tipos, como matrizes e delegados, podem ser convertidos em um identificador de objeto.  
  
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
  
```Output  
Type is System.Collections.ArrayList  
  
Type is System.Int32  
  
Type is MyDel  
```  
  
 **Exemplo**  
  
 Este exemplo mostra que um identificador de referência pode ser cancelado e que um membro pode ser acessado por meio de um identificador desreferenciado.  
  
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
  
```Output  
Array value: 7  
  
Cannot access array element 11, size is 10  
```  
  
 **Exemplo**  
  
 Este exemplo mostra que uma referência nativa (`&`) não é possível associar um `int` membro de um tipo gerenciado, como o `int` podem ser armazenados no heap lixo coletado e referências nativo não acompanham os movimentos de objeto no heap gerenciado. A correção é usar uma variável local ou para alterar `&` para `%`, tornando-a como uma referência de rastreamento.  
  
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
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)   
 [Operador de referência de rastreamento](../windows/tracking-reference-operator-cpp-component-extensions.md)