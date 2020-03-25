---
title: Operador __alignof
ms.date: 12/17/2018
f1_keywords:
- __alignof_cpp
- alignof_cpp
- __alignof
- _alignof
helpviewer_keywords:
- alignas [C++]
- alignment of structures
- __alignof keyword [C++]
- alignof [C++]
- types [C++], alignment requirements
ms.assetid: acb1eed7-6398-40bd-b0c5-684ceb64afbc
ms.openlocfilehash: 6bddce29dd97d965303a58cc72aa97dfe8cbd8d7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181532"
---
# <a name="__alignof-operator"></a>Operador __alignof

O c++ 11 apresenta o operador **alignof** que retorna o alinhamento, em bytes, do tipo especificado. Para portabilidade máxima, você deve usar o operador alignof em vez do operador de __alignof específico da Microsoft.

**Seção específica da Microsoft**

Retorna um valor do tipo `size_t` que é o requisito de alinhamento do tipo.

## <a name="syntax"></a>Sintaxe

```cpp
  __alignof( type )
```

## <a name="remarks"></a>Comentários

Por exemplo:

|Expression|Valor|
|----------------|-----------|
|**__alignof (Char)**|1|
|**__alignof (curto)**|2|
|**__alignof (int)**|4|
|**__alignof (\__int64)**|8|
|**__alignof (float)**|4|
|**__alignof (duplo)**|8|
|**__alignof (Char\*)**|4|

O valor de **__alignof** é o mesmo que o valor de `sizeof` para tipos básicos. Considere, no entanto, este exemplo:

```cpp
typedef struct { int a; double b; } S;
// __alignof(S) == 8
```

Nesse caso, o valor de **__alignof** é o requisito de alinhamento do maior elemento na estrutura.

De maneira semelhante, para

```cpp
typedef __declspec(align(32)) struct { int a; } S;
```

`__alignof(S)` é igual a `32`.

Um uso para **__alignof** seria como um parâmetro para uma de suas próprias rotinas de alocação de memória. Por exemplo, dada a seguinte estrutura definida `S`, você poderia chamar uma rotina de alocação de memória de nome `aligned_malloc` para alocar memória em um limite de alinhamento específico.

```cpp
typedef __declspec(align(32)) struct { int a; double b; } S;
int n = 50; // array size
S* p = (S*)aligned_malloc(n * sizeof(S), __alignof(S));
```

Para compatibilidade com versões anteriores, **_alignof** é um sinônimo para **__alignof** , a menos que a opção de compilador [/za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

Para obter mais informações sobre como modificar o alinhamento, consulte:

- [pack](../preprocessor/pack.md)

- [align](../cpp/align-cpp.md)

- [__unaligned](../cpp/unaligned.md)

- [/Zp (alinhamento de membro do struct)](../build/reference/zp-struct-member-alignment.md)

- [Exemplos de alinhamento de estrutura](../build/x64-software-conventions.md#examples-of-structure-alignment) (específico para x64)

Para obter mais informações sobre as diferenças no alinhamento no código para x86 e x64, consulte:

- [conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
