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
ms.openlocfilehash: 8a771b8bfc067966c3c054700538ebf180a5eb23
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233607"
---
# <a name="references-c"></a>Referências (C++)

Uma referência, como um ponteiro, armazena o endereço de um objeto localizado em outro lugar na memória. Ao contrário de um ponteiro, uma referência após ser inicializada não pode ser feita para fazer referência a um objeto diferente ou definir como NULL. Há dois tipos de referências: referências lvalue que se referem a uma variável nomeada e referências a rvalue que se referem a um [objeto temporário](../cpp/temporary-objects.md). O operador & significa uma referência lvalue e o operador && significa uma referência rvalue ou uma referência universal (rvalue ou lvalue), dependendo do contexto.

As referências podem ser declaradas usando a seguinte sintaxe:

> \[*especificadores de classe de armazenamento*] \[ *CV-qualificadores*] *tipo-especificadores* \[ *MS-modificador*] expressão de *Declarador* \[ **=** *expression*]**;**

Qualquer declarador válido que especifique uma referência pode ser usado. A menos que se trate de uma referência para um tipo de matriz ou função, a seguinte sintaxe simplificada se aplica:

> \[*especificadores de classe de armazenamento*] \[ *CV-Qualifiers*] *tipo-especificadores* \[ **&** ou **&&** ] \[ *CV-Qualifiers*] expressão de *identificador* \[ **=** *expression*]**;**

As referências são declaradas usando a seguinte sequência:

1. Os especificadores da declaração:

   - Um especificador de classe de armazenamento opcional.

   - **`const`** Qualificadores e/ou opcionais **`volatile`** .

   - O especificador de tipo: o nome de um tipo.

1. O declarador:

   - Um modificador opcional específico da Microsoft. Para obter mais informações, consulte [modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md).

   - O **&** operador or **&&** .

   - Opcional **`const`** e/ou **`volatile`** qualificadores.

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

## <a name="see-also"></a>Confira também

[Argumentos da função de tipo de referência](../cpp/reference-type-function-arguments.md)<br/>
[Função de tipo de referência retorna](../cpp/reference-type-function-returns.md)<br/>
[Referências a ponteiros](../cpp/references-to-pointers.md)
