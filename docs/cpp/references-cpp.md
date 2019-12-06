---
title: Referências (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- objects [C++], referencing
- references [C++]
- references, to pointers
- declarations, references
- references, declaring
- referencing objects, declarator syntax
ms.assetid: 68156f7f-97a0-4b66-b26d-b25ade5e3bd8
ms.openlocfilehash: 2353f0861f0f249416d0bb84a7a951b1cb6d64bc
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857327"
---
# <a name="references-c"></a>Referências (C++)

Uma referência, como um ponteiro, armazena o endereço de um objeto localizado em outro lugar na memória. Ao contrário de um ponteiro, uma referência após ser inicializada não pode ser feita para fazer referência a um objeto diferente ou definir como NULL. Há dois tipos de referências: referências lvalue que se referem a uma variável nomeada e referências a rvalue que se referem a um [objeto temporário](../cpp/temporary-objects.md). O operador & significa uma referência lvalue e o operador & & significa uma referência rvalue ou uma referência universal (rvalue ou lvalue), dependendo do contexto.

As referências podem ser declaradas usando a seguinte sintaxe:

> \[*storage-class-specifiers*] \[*cv-qualifiers*] *type-specifiers* \[*ms-modifier*] *declarator* \[ **=** *expression*] **;**

Qualquer declarador válido que especifique uma referência pode ser usado. A menos que se trate de uma referência para um tipo de matriz ou função, a seguinte sintaxe simplificada se aplica:

> \[*especificadores de classe de armazenamento*] \[*CV-Qualifiers*] *tipo-especificadores* \[ **&** ou **&&** ] \[ID *de qualificadores CV],* *identificador* \[*expressão*de **=** ] **;**

As referências são declaradas usando a seguinte sequência:

1. Os especificadores da declaração:

   - Um especificador de classe de armazenamento opcional.

   - Qualificadores **const** e/ou **voláteis** opcionais.

   - O especificador de tipo: o nome de um tipo.

1. O declarador:

   - Um modificador opcional específico da Microsoft. Para obter mais informações, consulte [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).

   - O operador de **&** ou operador de **&&** .

   - **Const** e/ou **volatile** qualificadores opcionais.

   - O identificador.

1. Um inicializador opcional.

Os formulários declaradores mais complexos para ponteiros para matrizes e funções também se aplicam a referências a matrizes e funções. Para obter mais informações, consulte [ponteiros](../cpp/pointers-cpp.md).

Vários declaradores e inicializadores podem aparecer em uma lista separada por vírgulas após um único especificador de declaração. Por exemplo:

```cpp
int &i;
int &i, &j;
```

As referências, os ponteiros e os objetos podem ser declarados juntos:

```cpp
int &ref, *ptr, k;
```

Uma referência contém o endereço de um objeto, mas se comporta sintaticamente como um objeto.

No programa a seguir, observe que o nome do objeto, `s`, e a referência ao objeto, `SRef`, podem ser usados de forma idêntica em programas:

## <a name="example"></a>Exemplo

```cpp
// references.cpp
#include <stdio.h>
struct S {
   short i;
};

int main() {
   S  s;   // Declare the object.
   S& SRef = s;   // Declare the reference.
   s.i = 3;

   printf_s("%d\n", s.i);
   printf_s("%d\n", SRef.i);

   SRef.i = 4;
   printf_s("%d\n", s.i);
   printf_s("%d\n", SRef.i);
}
```

```Output
3
3
4
4
```

## <a name="see-also"></a>Consulte também

[Argumentos de função de tipo de referência](../cpp/reference-type-function-arguments.md)<br/>
[Retornos de função de tipo de referência](../cpp/reference-type-function-returns.md)<br/>
[Referências a ponteiros](../cpp/references-to-pointers.md)
