---
title: pin_ptr (C + + CLI) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- pin_ptr_cpp
- stdcli::language::pin_ptr
- pin_ptr
dev_langs:
- C++
helpviewer_keywords:
- pinning pointers
- pin_ptr keyword [C++]
ms.assetid: 6c2e6c73-4ec2-4dce-8e1f-ccf3a9f9d0aa
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7205718a3564a3929fe2a9f8b7d8049a320ae1cd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pinptr-ccli"></a>pin_ptr (C++/CLI)
Declara um *ponteiro de fixação*, que é usado apenas com o common language runtime.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 (Não há nenhum comentários para esse recurso de idioma que se aplicam a todos os tempos de execução).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 (Esse recurso de idioma não é suportado no Windows Runtime.)  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 Um *ponteiro de fixação* é um ponteiro interior que impede que o objeto apontado movam no heap coletado como lixo. Ou seja, o valor de um ponteiro de fixação não é alterado pelo common language runtime. Isso é necessário quando você passa o endereço de uma classe gerenciada para uma função não gerenciada para que o endereço não será alterado inesperadamente durante a resolução da chamada de função não gerenciada.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
[cli::]pin_ptr<cv_qualifiertype>var = &initializer;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *cv_qualifier*  
 `const`ou `volatile` qualificadores. Por padrão, é um ponteiro de fixação `volatile`. Ela é redundante, mas não um erro para declarar um ponteiro de fixação `volatile`.  
  
 *type*  
 O tipo de `initializer`.  
  
 *var*  
 O nome do `pin_ptr` variável.  
  
 *initializer*  
 Um membro de um tipo de referência, o elemento de uma matriz gerenciada, ou qualquer outro objeto que você pode atribuir a um ponteiro nativo.  
  
### <a name="remarks"></a>Comentários  
 Um `pin_ptr` representa um subconjunto da funcionalidade de um ponteiro nativo. Portanto, qualquer coisa que pode ser atribuído a um ponteiro nativo também pode ser atribuída a um `pin_ptr`. Um ponteiro interior tem permissão para executar o mesmo conjunto de operações, como ponteiros nativos, incluindo a comparação e a aritmética de ponteiro.  
  
 Um objeto ou subsistema de uma classe gerenciada podem ser fixados, caso em que o common language runtime não moverá-lo durante a coleta de lixo. O principal uso é transmitir um ponteiro para dados gerenciados como um parâmetro real de uma chamada de função não gerenciada. Durante um ciclo de coleta, o tempo de execução irá inspecionar os metadados criados para o ponteiro de fixação e não será movido para o item que ele aponte para.  
  
 A fixação de um objeto também fixa seus campos de valor; Isto é, campos de primitivo ou valor de tipo. No entanto, os campos são declarados pelo manipulador de acompanhamento (`%`) não está fixado.  
  
 A fixação de um Subobjeto definido em um objeto gerenciado tem o efeito de fixar o objeto inteiro.  
  
 Se o ponteiro de fixação é reatribuído para apontar para um novo valor, a instância anterior apontada não é mais considerada fixado.  
  
 Um objeto é fixado apenas enquanto um `pin_ptr` aponta para ela. O objeto não é fixado quando o ponteiro de fixação sai do escopo ou é definido como [nullptr](../windows/nullptr-cpp-component-extensions.md). Após o `pin_ptr` sai do escopo, o objeto que foi fixado pode ser movidos no heap pelo coletor de lixo. Qualquer ponteiros nativos que apontarão para o objeto não serão atualizados e desalocar referenciar um deles pode gerar uma exceção irrecuperável.  
  
 Se nenhum ponteiros de fixação apontam para o objeto (todos os ponteiros de fixação deu fora do escopo, reatribuídos para apontar para outros objetos ou foram atribuídos [nullptr](../windows/nullptr-cpp-component-extensions.md)), o objeto é garantia de não ser fixado.  
  
 Um ponteiro de fixação pode apontar para um identificador de referência, tipo de valor ou identificador de tipo demarcado, membro de um tipo gerenciado ou um elemento de uma matriz gerenciada. Ele não pode apontar para um tipo de referência.  
  
 Obter o endereço de um `pin_ptr` que aponta para um objeto nativo faz com que um comportamento indefinido.  
  
 Ponteiros de fixação só podem ser declarados como variáveis locais não-estático na pilha.  
  
 Ponteiros de fixação não podem ser usados como:  
  
-   parâmetros de função  
  
-   o tipo de retorno de uma função  
  
-   um membro de uma classe  
  
-   o tipo de destino de uma conversão.  
  
 `pin_ptr`está no `cli` namespace. Para obter mais informações, consulte [plataforma, padrão e cli Namespaces](../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md).  
  
 Para obter mais informações sobre ponteiros internos, consulte [interior_ptr (C + + CLI)](../windows/interior-ptr-cpp-cli.md).  
  
 Para obter mais informações sobre como fixar ponteiros, consulte [como: Fixar ponteiros e matrizes](../windows/how-to-pin-pointers-and-arrays.md) e [como: declarar ponteiros de fixação e tipos de valor](../windows/how-to-declare-pinning-pointers-and-value-types.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo a seguir usa `pin_ptr` para restringir a posição do primeiro elemento de uma matriz.  
  
```  
// pin_ptr_1.cpp  
// compile with: /clr   
using namespace System;  
#define SIZE 10  
  
#pragma unmanaged  
// native function that initializes an array  
void native_function(int* p) {  
   for(int i = 0 ; i < 10 ; i++)  
    p[i] = i;  
}  
#pragma managed  
  
public ref class A {  
private:  
   array<int>^ arr;   // CLR integer array  
  
public:  
   A() {  
      arr = gcnew array<int>(SIZE);  
   }  
  
   void load() {  
   pin_ptr<int> p = &arr[0];   // pin pointer to first element in arr  
   int* np = p;   // pointer to the first element in arr  
   native_function(np);   // pass pointer to native function  
   }  
  
   int sum() {  
      int total = 0;  
      for (int i = 0 ; i < SIZE ; i++)  
         total += arr[i];  
      return total;  
   }  
};  
  
int main() {  
   A^ a = gcnew A;  
   a->load();   // initialize managed array using the native function  
   Console::WriteLine(a->sum());  
}  
```  
  
 **Saída**  
  
```Output  
45  
```  
  
 **Exemplo**  
  
 O exemplo a seguir mostra que um ponteiro interior pode ser convertido em um ponteiro de fixação e que o tipo de retorno do operador address-of (`&`) é um ponteiro interior quando o operando for no heap gerenciado.  
  
```  
// pin_ptr_2.cpp  
// compile with: /clr  
using namespace System;  
  
ref struct G {  
   G() : i(1) {}  
   int i;  
};  
  
ref struct H {  
   H() : j(2) {}  
   int j;  
};  
  
int main() {  
   G ^ g = gcnew G;   // g is a whole reference object pointer  
   H ^ h = gcnew H;  
  
   interior_ptr<int> l = &(g->i);   // l is interior pointer  
  
   pin_ptr<int> k = &(h->j);   // k is a pinning interior pointer  
  
   k = l;   // ok  
   Console::WriteLine(*k);  
};  
```  
  
 **Saída**  
  
```Output  
1  
```  
  
 **Exemplo**  
  
 O exemplo a seguir mostra que um ponteiro de fixação pode ser convertido em outro tipo.  
  
```  
// pin_ptr_3.cpp  
// compile with: /clr  
using namespace System;  
  
ref class ManagedType {  
public:  
   int i;  
};  
  
int main() {  
   ManagedType ^mt = gcnew ManagedType;  
   pin_ptr< int > pt = &mt->i;  
   *pt = 8;  
   Console::WriteLine(mt->i);  
  
   char *pc = ( char* ) pt;  
   *pc = 255;  
   Console::WriteLine(mt->i);  
}  
```  
  
 **Saída**  
  
```Output  
8  
255  
```