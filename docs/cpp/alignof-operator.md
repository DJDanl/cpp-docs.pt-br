---
title: Operador alignof
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
ms.openlocfilehash: 6a2046774674858211ae89abb9b4cfc7b09c0a6d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227628"
---
# <a name="alignof-operator"></a>Operador alignof

O **`alignof`** operador retorna o alinhamento em bytes do tipo especificado como um valor do tipo **`size_t`** .

## <a name="syntax"></a>Sintaxe

```cpp
alignof( type )
```

## <a name="remarks"></a>Comentários

Por exemplo:

| Expression | Valor |
|--|--|
| **`alignof( char )`** | 1 |
| **`alignof( short )`** | 2 |
| **`alignof( int )`** | 4 |
| **`alignof( long long )`** | 8 |
| **`alignof( float )`** | 4 |
| **`alignof( double )`** | 8 |

O **`alignof`** valor é o mesmo que o valor para **`sizeof`** para tipos básicos. Considere, no entanto, este exemplo:

```cpp
typedef struct { int a; double b; } S;
// alignof(S) == 8
```

Nesse caso, o **`alignof`** valor é o requisito de alinhamento do maior elemento na estrutura.

De maneira semelhante, para

```cpp
typedef __declspec(align(32)) struct { int a; } S;
```

`alignof(S)` é igual a `32`.

Um uso para **`alignof`** seria como um parâmetro para uma de suas próprias rotinas de alocação de memória. Por exemplo, dada a seguinte estrutura definida `S`, você poderia chamar uma rotina de alocação de memória de nome `aligned_malloc` para alocar memória em um limite de alinhamento específico.

```cpp
typedef __declspec(align(32)) struct { int a; double b; } S;
int n = 50; // array size
S* p = (S*)aligned_malloc(n * sizeof(S), alignof(S));
```

Para obter mais informações sobre como modificar o alinhamento, consulte:

- [pack](../preprocessor/pack.md)

- [alinha](../cpp/align-cpp.md)

- [__unaligned](../cpp/unaligned.md)

- [/ZP (alinhamento de membro de struct)](../build/reference/zp-struct-member-alignment.md)

- [Exemplos de alinhamento de estrutura](../build/x64-software-conventions.md#examples-of-structure-alignment) (específico para x64)

Para obter mais informações sobre as diferenças no alinhamento no código para x86 e x64, consulte:

- [conflitos com o compilador x86](../build/x64-software-conventions.md#conflicts-with-the-x86-compiler)

### <a name="microsoft-specific"></a>Específico da Microsoft

**`alignof`** e **`__alignof`** são sinônimos no compilador da Microsoft. Antes de se tornar parte do padrão no C++ 11, o operador específico da Microsoft **`__alignof`** fornecia essa funcionalidade. Para portabilidade máxima, você deve usar o **`alignof`** operador em vez do operador específico da Microsoft **`__alignof`** .

Para compatibilidade com versões anteriores, **`_alignof`** é um sinônimo para **`__alignof`** a menos que a opção do compilador [ `/Za` \( desabilite extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
