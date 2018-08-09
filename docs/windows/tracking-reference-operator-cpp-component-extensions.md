---
title: Acompanhamento de referência de operador (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- '%'
dev_langs:
- C++
helpviewer_keywords:
- tracking references
- '% tracking reference [C++]'
ms.assetid: 142a7269-ab69-4b54-a6d7-833bef06228f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 66d97de05956df985f4c0d699682210721b60c82
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011836"
---
# <a name="tracking-reference-operator-c-component-extensions"></a>Operador de Referência de Acompanhamento (Extensões de Componentes C++)
Um *referência de rastreamento* (`%`) se comporta como uma referência comum do C++ (`&`), exceto que quando um objeto é atribuído a uma referência de rastreamento, a contagem de referência do objeto é incrementada.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
 Uma referência de rastreamento tem as seguintes características.  
  
-   Atribuição de um objeto para uma referência de rastreamento faz com que a contagem de referência do objeto a ser incrementado.  
  
-   Uma referência nativa (`&`) é o resultado quando você remove a referência um `*`. Uma referência de rastreamento (`%`) é o resultado quando você remove a referência um `^`. Desde que você tenha um `%` a um objeto, o objeto ficará ativo na memória.  
  
-   O ponto final (`.`) o operador de acesso de membro é usado para acessar um membro do objeto.  
  
-   Referências de acompanhamento são válidas para identificadores e tipos de valor (por exemplo `String^`).  
  
-   Uma referência de rastreamento não pode ser atribuída um valor nulo ou **nullptr** valor. Uma referência de rastreamento pode ser reatribuída a outro objeto válido quantas vezes forem necessárias.  
  
-   Uma referência de rastreamento não pode ser usada como um operador unário de tomada de endereço.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Uma referência de rastreamento se comporta como uma referência padrão do C++, exceto que um % é contado por referência. O trecho a seguir mostra como converter entre % e ^ tipos:  
  
```cpp  
Foo^ spFoo = ref new Foo();  
Foo% srFoo = *spFoo;  
Foo^ spFoo2 = %srFoo;  
```  
  
 O exemplo a seguir mostra como passar um ^ para uma função que usa um %.  
  
```cpp  
ref class Foo sealed {};  
  
    // internal or private  
    void UseFooHelper(Foo% f)  
    {  
        auto x = %f;  
    }  
  
    // public method on ABI boundary  
    void UseFoo(Foo^ f)  
    {  
        if (f != nullptr) { UseFooHelper(*f); }  
    }  
```  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 No C + + / CLI, você pode usar uma referência de rastreamento a um identificador ao associar a um objeto de um tipo CLR na heap coletado como lixo.  
  
 No CLR, o valor de uma referência de acompanhamento de variável é atualizada automaticamente sempre que o coletor de lixo move o objeto referenciado.  
  
 Uma referência de rastreamento pode ser declarada somente na pilha. Uma referência de rastreamento não pode ser um membro de uma classe.  
  
 Não é possível ter uma referência de C++ nativa em um objeto no heap coletado como lixo.  
  
 Para obter mais informações sobre referências de acompanhamento no C + + / CLI, consulte:  
  
-   [Como usar referências de acompanhamento no C++/CLI](../dotnet/how-to-use-tracking-references-in-cpp-cli.md)
  
### <a name="examples"></a>Exemplos  
  
 O exemplo a seguir para C + + c++ CLI mostra como usar uma referência de rastreamento com tipos nativos e gerenciados.  
  
```cpp  
// tracking_reference_1.cpp  
// compile with: /clr  
ref class MyClass {  
public:  
   int i;  
};  
  
value struct MyStruct {  
   int k;  
};  
  
int main() {  
   MyClass ^ x = ref new MyClass;  
   MyClass ^% y = x;   // tracking reference handle to reference object   
  
   int %ti = x->i;   // tracking reference to member of reference type  
  
   int j = 0;  
   int %tj = j;   // tracking reference to object on the stack  
  
   int * pi = new int[2];  
   int % ti2 = pi[0];   // tracking reference to object on native heap  
  
   int *% tpi = pi;   // tracking reference to native pointer  
  
   MyStruct ^ x2 = ref new MyStruct;  
   MyStruct ^% y2 = x2;   // tracking reference to value object  
  
   MyStruct z;  
   int %tk = z.k;   // tracking reference to member of value type  
  
   delete[] pi;  
}  
```  
  
 O exemplo a seguir para C + + c++ CLI mostra como associar uma referência de rastreamento para uma matriz.  
  
```cpp  
// tracking_reference_2.cpp  
// compile with: /clr  
using namespace System;  
  
int main() {  
   array<int> ^ a = ref new array<Int32>(5);  
   a[0] = 21;  
   Console::WriteLine(a[0]);  
   array<int> ^% arr = a;  
   arr[0] = 222;  
   Console::WriteLine(a[0]);  
}  
```  
  
```Output  
21  
222  
```