---
title: Ponteiros const e volatile
ms.date: 11/19/2019
helpviewer_keywords:
- volatile keyword [C++], and pointers
- pointers, and const
- pointers, and volatile
- const keyword [C++], volatile pointers
ms.assetid: 0c92dc6c-400e-4342-b345-63ddfe649d7e
ms.openlocfilehash: a8fd25777d1169ba281fbee173c1c8f5673c8b56
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227563"
---
# <a name="const-and-volatile-pointers"></a>Ponteiros const e volatile

As palavras-chave [const](const-cpp.md) e [volatile](volatile-cpp.md) alteram como os ponteiros são tratados. A **`const`** palavra-chave especifica que o ponteiro não pode ser modificado após a inicialização; o ponteiro é protegido contra modificações posteriormente.

A **`volatile`** palavra-chave especifica que o valor associado ao nome que se segue pode ser modificado por ações diferentes daquelas no aplicativo do usuário. Portanto, a **`volatile`** palavra-chave é útil para declarar objetos na memória compartilhada que pode ser acessada por vários processos ou áreas de dados globais usadas para comunicação com rotinas de serviço de interrupção.

Quando um nome é declarado como **`volatile`** , o compilador recarrega o valor da memória toda vez que é acessado pelo programa. Isso reduz drasticamente as otimizações possíveis. No entanto, quando o estado de um objeto pode ser alterado inesperadamente, é a única maneira de assegurar o desempenho previsível do programa.

Para declarar o objeto apontado pelo ponteiro como **`const`** ou **`volatile`** , use uma declaração do formulário:

```cpp
const char *cpch;
volatile char *vpch;
```

Para declarar o valor do ponteiro — ou seja, o endereço real armazenado no ponteiro — como **`const`** ou **`volatile`** , use uma declaração do formulário:

```cpp
char * const pchc;
char * volatile pchv;
```

A linguagem C++ impede atribuições que permitiriam a modificação de um objeto ou ponteiro declarado como **`const`** . Essas atribuições removeriam as informações com as quais o objeto ou o ponteiro foi declarado, violando assim a intenção da declaração original. Considere as seguintes declarações:

```cpp
const char cch = 'A';
char ch = 'B';
```

Dadas as declarações anteriores de dois objetos ( `cch` , do tipo **const char**e `ch` , do tipo **Char)**, as seguintes declarações/inicializações são válidas:

```cpp
const char *pch1 = &cch;
const char *const pch4 = &cch;
const char *pch5 = &ch;
char *pch6 = &ch;
char *const pch7 = &ch;
const char *const pch8 = &ch;
```

As seguintes declarações/inicializações são errôneas.

```cpp
char *pch2 = &cch;   // Error
char *const pch3 = &cch;   // Error
```

A declaração de `pch2` declara um ponteiro em que um objeto constante pode ser modificado e, portanto, não é permitida. A declaração de `pch3` especifica que o ponteiro é constante, não o objeto; a declaração não é permitida pelo mesmo motivo que a `pch2` declaração não é permitida.

As oito atribuições a seguir mostram a atribuição por ponteiro e a alteração do valor do ponteiro para as declarações anteriores; por enquanto, suponha que a inicialização estava correta para `pch1` a `pch8`.

```cpp
*pch1 = 'A';  // Error: object declared const
pch1 = &ch;   // OK: pointer not declared const
*pch2 = 'A';  // OK: normal pointer
pch2 = &ch;   // OK: normal pointer
*pch3 = 'A';  // OK: object not declared const
pch3 = &ch;   // Error: pointer declared const
*pch4 = 'A';  // Error: object declared const
pch4 = &ch;   // Error: pointer declared const
```

Ponteiros declarados como **`volatile`** , ou como uma combinação de **`const`** e **`volatile`** , obedecem às mesmas regras.

Ponteiros para **`const`** objetos geralmente são usados em declarações de função da seguinte maneira:

```cpp
errno_t strcpy_s( char *strDestination, size_t numberOfElements, const char *strSource );
```

A instrução anterior declara uma função, [strcpy_s](../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md), onde dois dos três argumentos são do tipo ponteiro para **`char`** . Como os argumentos são passados por referência e não por valor, a função seria livre para modificar `strDestination` e `strSource` se `strSource` não fosse declarada como **`const`** . A declaração de `strSource` como **`const`** garante o chamador que `strSource` não pode ser alterado pela função chamada.

> [!NOTE]
> Como há uma conversão padrão de *TypeName* <strong>\*</strong> para **`const`** *TypeName* <strong>\*</strong> , é legal passar um argumento do tipo `char *` para [strcpy_s](../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md). No entanto, o inverso não é verdadeiro; Não existe conversão implícita para remover o **`const`** atributo de um objeto ou ponteiro.

Um **`const`** ponteiro de um determinado tipo pode ser atribuído a um ponteiro do mesmo tipo. No entanto, um ponteiro não **`const`** pode ser atribuído a um **`const`** ponteiro. O código a seguir mostra atribuições corretas e incorretas:

```cpp
// const_pointer.cpp
int *const cpObject = 0;
int *pObject;

int main() {
pObject = cpObject;
cpObject = pObject;   // C3892
}
```

O exemplo a seguir mostra como declarar um objeto como const se você tiver um ponteiro para um ponteiro para um objeto.

```cpp
// const_pointer2.cpp
struct X {
   X(int i) : m_i(i) { }
   int m_i;
};

int main() {
   // correct
   const X cx(10);
   const X * pcx = &cx;
   const X ** ppcx = &pcx;

   // also correct
   X const cx2(20);
   X const * pcx2 = &cx2;
   X const ** ppcx2 = &pcx2;
}
```

## <a name="see-also"></a>Confira também

[Ponteiros](pointers-cpp.md) 
 do [Ponteiros brutos](raw-pointers.md)
