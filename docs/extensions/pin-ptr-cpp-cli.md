---
title: pin_ptr (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- pin_ptr_cpp
- stdcli::language::pin_ptr
- pin_ptr
helpviewer_keywords:
- pinning pointers
- pin_ptr keyword [C++]
ms.assetid: 6c2e6c73-4ec2-4dce-8e1f-ccf3a9f9d0aa
ms.openlocfilehash: a8c6733a9f6e5c9650333f96a92ff18eedb9c356
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516491"
---
# <a name="pin_ptr-ccli"></a>pin_ptr (C++/CLI)

Declara um *ponteiro de fixação*, que é usado apenas com o Common Language Runtime.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

(Não há comentários para esse recurso de linguagem que se apliquem a todos os tempos de execução.)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

(Esse recurso de linguagem não é compatível com o Windows Runtime.)

## <a name="common-language-runtime"></a>Common Language Runtime

Um *ponteiro de fixação* é um ponteiro interior que impede o objeto apontado de se mover no heap coletado pela lixeira. Ou seja, o Common Language Runtime não altera o valor de um ponteiro de fixação. Isso é obrigatório ao transmitir o endereço de uma classe gerenciada para uma função não gerenciada, para que o endereço não seja alterado de maneira inesperada durante a resolução da chamada da função não gerenciada.

### <a name="syntax"></a>Sintaxe

```cpp
[cli::]pin_ptr<cv_qualifiertype>var = &initializer;
```

### <a name="parameters"></a>Parâmetros

*cv_qualifier*<br/>
Qualificadores **const** ou **volatile**. Por padrão, um ponteiro de fixação é **volatile**. É redundante, mas não é um erro declarar um ponteiro de fixação **volatile**.

*type*<br/>
O tipo de *inicializador*.

*var*<br/>
O nome da variável **pin_ptr**.

*initializer*<br/>
Um membro de um tipo de referência, um elemento de uma matriz gerenciada ou qualquer outro objeto que você possa atribuir a um ponteiro nativo.

### <a name="remarks"></a>Comentários

Um **pin_ptr** representa um superconjunto da funcionalidade de um ponteiro nativo. Portanto, qualquer coisa que possa ser atribuída a um ponteiro nativo também pode ser atribuída a um **pin_ptr**. Um ponteiro interno tem permissão para realizar o mesmo conjunto de operações que os ponteiros nativos, incluindo comparação e aritmética de ponteiros.

Um objeto ou subobjeto de uma classe gerenciada pode ser fixado, caso em que o Common Language Runtime não o move durante a coleta de lixo. O principal uso dele é passar um ponteiro para dados gerenciados como um parâmetro real de uma chamada de função não gerenciada. Durante um ciclo de coleta, o tempo de execução inspeciona os metadados criados para o ponteiro de fixação e não move o item para o qual ele aponta.

A fixação de um objeto também fixa seus campos de valor; ou seja, campos de tipo de valor ou primitivos. No entanto, os campos declarados com o identificador de acompanhamento (`%`) não são fixados.

Fixar um subobjeto definido em um objeto gerenciado tem o efeito de fixar todo o objeto.

Se o ponteiro de fixação for reatribuído para apontar para um novo valor, a instância anterior apontada não será mais considerada fixada.

Um objeto é fixado apenas enquanto um **pin_ptr** aponta para ele. O objeto não está mais fixado quando seu ponteiro de fixação sai do escopo ou é definido como [nullptr](nullptr-cpp-component-extensions.md). Após o **pin_ptr** sair do escopo, o objeto que foi fixado pode ser movido no heap pelo coletor de lixo. Nenhum ponteiro nativo que ainda aponte para o objeto será atualizado, e cancelar a referência a um deles pode gerar uma exceção irrecuperável.

Se nenhum ponteiro de fixação apontar para o objeto (todos os ponteiros de fixação saíram do escopo, foram reatribuídos para apontar para outros objetos ou foram designados como [nullptr](nullptr-cpp-component-extensions.md)), o objeto não será fixado.

Um ponteiro de fixação pode apontar para um identificador de referência, um tipo de valor, um identificador de tipo convertido boxing, um membro de um tipo gerenciado ou um elemento de uma matriz gerenciada. Ele não pode apontar para um tipo de referência.

Extrair o endereço de um **pin_ptr** que aponta para um objeto nativo causa um comportamento indefinido.

Ponteiros de fixação só podem ser declarados como variáveis locais não estáticas na pilha.

Ponteiros de fixação não podem ser usados como:

- parâmetros de função

- tipo de retorno de uma função

- membro de uma classe

- tipo de destino de uma conversão.

**pin_ptr** fica no namespace `cli`. Saiba mais em [Namespaces de plataforma, padrão e cli](platform-default-and-cli-namespaces-cpp-component-extensions.md).

Saiba mais sobre ponteiros internos em [interior_ptr (C++/CLI)](interior-ptr-cpp-cli.md).

Saiba mais sobre ponteiros de fixação em [Como fixar ponteiros e matrizes](how-to-pin-pointers-and-arrays.md) e [Como declarar ponteiros de fixação e tipos de valor](how-to-declare-pinning-pointers-and-value-types.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir usa **pin_ptr** para restringir a posição do primeiro elemento de uma matriz.

```cpp
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

```Output
45
```

O exemplo a seguir mostra que um ponteiro interior pode ser convertido em um ponteiro de fixação e que o tipo de retorno do operador address-of (`&`) é um ponteiro interior quando o operando está no heap gerenciado.

```cpp
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

```Output
1
```

O exemplo a seguir mostra que um ponteiro de fixação pode ser convertido em outro tipo.

```cpp
// pin_ptr_3.cpp
// compile with: /clr
using namespace System;

ref class ManagedType {
public:
   int i;
};

int main() {
   ManagedType ^mt = gcnew ManagedType;
   pin_ptr<int> pt = &mt->i;
   *pt = 8;
   Console::WriteLine(mt->i);

   char *pc = ( char* ) pt;
   *pc = 255;
   Console::WriteLine(mt->i);
}
```

```Output
8
255
```