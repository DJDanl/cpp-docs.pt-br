---
title: Anotando estruturas e classes
ms.date: 06/28/2019
ms.topic: conceptual
f1_keywords:
- _Field_size_bytes_part_
- _Field_size_bytes_full_opt_
- _Field_size_bytes_
- _Field_size_opt_
- _Field_size_part_
- _Field_size_bytes_part_opt_
- _Field_range_
- _Field_size_part_opt_
- _Field_size_
- _Field_size_bytes_opt_
- _Struct_size_bytes_
- _Field_size_bytes_full_
- _Field_size_full_
- _Field_size_full_opt_
- _Field_z_
ms.assetid: b8278a4a-c86e-4845-aa2a-70da21a1dd52
ms.openlocfilehash: e6b08c18d2524f1240eed99dd45320a7f4c00ac3
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77417475"
---
# <a name="annotating-structs-and-classes"></a>Anotando estruturas e classes

Você pode anotar os membros de struct e de classe usando anotações que agem como invariáveis – eles devem ser verdadeiros em qualquer chamada de função ou entrada/saída de função que envolva a estrutura delimitadora como um parâmetro ou um valor de resultado.

## <a name="struct-and-class-annotations"></a>Anotações de struct e classe

- `_Field_range_(low, high)`

     O campo está no intervalo (inclusivo) de `low` para `high`.  Equivalente a `_Satisfies_(_Curr_ >= low && _Curr_ <= high)` aplicado ao objeto anotado usando as condições anteriores ou posteriores.

- `_Field_size_(size)`, `_Field_size_opt_(size)`, `_Field_size_bytes_(size)`, `_Field_size_bytes_opt_(size)`

     Um campo que tem um tamanho gravável em elementos (ou bytes) conforme especificado por `size`.

- `_Field_size_part_(size, count)`, `_Field_size_part_opt_(size, count)`, `_Field_size_bytes_part_(size, count)``_Field_size_bytes_part_opt_(size, count)`

     Um campo que tem um tamanho gravável em elementos (ou bytes) conforme especificado por `size`e o `count` desses elementos (bytes) que são legíveis.

- `_Field_size_full_(size)`, `_Field_size_full_opt_(size)`, `_Field_size_bytes_full_(size)`, `_Field_size_bytes_full_opt_(size)`

     Um campo que tem o tamanho legível e gravável em elementos (ou bytes) conforme especificado por `size`.

- `_Field_z_`

     Um campo que tem uma cadeia de caracteres terminada em nulo.

- `_Struct_size_bytes_(size)`

     Aplica-se à declaração struct ou Class.  Indica que um objeto válido desse tipo pode ser maior que o tipo declarado, com o número de bytes sendo especificado por `size`.  Por exemplo:

    ```cpp

    typedef _Struct_size_bytes_(nSize)
    struct MyStruct {
        size_t nSize;
        ...
    };

    ```

     O tamanho do buffer, em bytes de um parâmetro `pM` do tipo `MyStruct *`, é então usado como:

    ```cpp
    min(pM->nSize, sizeof(MyStruct))
    ```

## <a name="example"></a>Exemplo

```cpp
#include <sal.h>

// This _Struct_size_bytes_ is equivalent to what below _Field_size_ means.
_Struct_size_bytes_(__builtin_offsetof(MyBuffer, buffer) + bufferSize * sizeof(int))
struct MyBuffer
{
    static int MaxBufferSize;

    _Field_z_
    const char* name;

    int firstField;

    // ... other fields

    _Field_range_(1, MaxBufferSize)
    int bufferSize;

    _Field_size_(bufferSize)        // Prefered way - easier to read and maintain.
    int buffer[]; // Using C99 Flexible array member
};
```

Observações para este exemplo:

- `_Field_z_` é equivalente a `_Null_terminated_`.  `_Field_z_` para o campo nome especifica que o campo nome é uma cadeia de caracteres terminada em nulo.
- `_Field_range_` para `bufferSize` especifica que o valor de `bufferSize` deve estar entre 1 e `MaxBufferSize` (ambos incluídos).
- Os resultados finais das anotações de `_Struct_size_bytes_` e `_Field_size_` são equivalentes. Para estruturas ou classes que têm um layout semelhante, `_Field_size_` é mais fácil de ler e manter, pois ela tem menos referências e cálculos do que a anotação de `_Struct_size_bytes_` equivalente. `_Field_size_` não requer conversão para o tamanho do byte. Se o tamanho do byte for a única opção, por exemplo, para um campo de ponteiro void, `_Field_size_bytes_` poderá ser usado. Se ambos os `_Struct_size_bytes_` e `_Field_size_` existirem, ambos estarão disponíveis para ferramentas. Cabe à ferramenta o que fazer se as duas anotações discordarem.

## <a name="see-also"></a>Confira também

- [Usando anotações de SAL para reduzir defeitos de código do C/C++](../code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects.md)
- [Noções básicas de SAL](../code-quality/understanding-sal.md)
- [Anotando parâmetros de função e valores de retorno](../code-quality/annotating-function-parameters-and-return-values.md)
- [Anotando o comportamento da função](../code-quality/annotating-function-behavior.md)
- [Anotando o comportamento de bloqueio](../code-quality/annotating-locking-behavior.md)
- [Especificando quando e onde uma anotação se aplica](../code-quality/specifying-when-and-where-an-annotation-applies.md)
- [Funções intrínsecas](../code-quality/intrinsic-functions.md)
- [Práticas recomendadas e exemplos](../code-quality/best-practices-and-examples-sal.md)
