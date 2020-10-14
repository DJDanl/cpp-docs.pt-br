---
title: _Static_assert palavra-chave e static_assert macro (C11)
description: Descreve a palavra-chave C11 _Static_assert e a macro static_assert C11.
ms.date: 10/13/2020
f1_keywords:
- static_assert_c
- _Static_assert
helpviewer_keywords:
- assertions [C], _Static_assert, static_assert
ms.openlocfilehash: dbe49b1dcbb8dd4e0d9df678f4456bc605e01c3f
ms.sourcegitcommit: 651348f8cd92ab0d52f09e9225a7eb41562559db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/14/2020
ms.locfileid: "92061012"
---
# <a name="_static_assert-keyword-and-static_assert-macro-c11"></a>_Static_assert palavra-chave e static_assert macro (C11)

Testa uma asserção no momento da compilação. Se a expressão constante especificada for **`false`** , o compilador exibirá a mensagem especificada e a compilação falhará com o erro C2338; caso contrário, não haverá efeito. Novo no C11.

**`_Static_assert`** é uma palavra-chave introduzida no C11.
**`static_assert`** é uma macro, introduzida no C11, que é mapeada para a **`_Static_assert`** palavra-chave.

## <a name="syntax"></a>Sintaxe

```C
_Static_assert(constant-expression, string-literal);
static_assert(constant-expression, string-literal);
```

### <a name="parameters"></a>Parâmetros

*expressão de constante*\
Uma expressão constante integral que pode ser avaliada no momento da compilação. Se a expressão for zero (false), o exibirá o parâmetro *String-literal* e a compilação falhará com um erro. Se a expressão for diferente de zero (true), não haverá nenhum efeito.

*literal de cadeia de caracteres*\
A mensagem exibida se a *expressão constante* for avaliada como zero (false). A mensagem deve ser feita usando o [conjunto de caracteres base](../c-language/ascii-character-set.md) do compilador. Os caracteres não podem ser [caracteres multibyte ou largos](../c-language/multibyte-and-wide-characters.md).

## <a name="remarks"></a>Comentários

A **`_Static_assert`** palavra-chave e a **`static_assert`** macro testam uma asserção de software no momento da compilação. Eles podem ser usados em escopo global ou de função.

Em contraste, a [macro Assert e as funções _assert e _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) testam uma declaração de software em tempo de execução e incorrem em um custo de tempo de execução.

**Comportamento específico da Microsoft**

Em C, quando você não inclui `<assert.h>` , o compilador do Microsoft Visual C/C++ trata **`static_assert`** como uma palavra-chave que mapeia para **`_Static_assert`** . Usar **`static_assert`** é preferencial, pois o mesmo código funcionará em C e C++.

## <a name="example-of-a-compile-time-assert"></a>Exemplo de uma declaração de tempo de compilação

No exemplo a seguir, **`static_assert`** e **`_Static_assert`** são usadas para verificar quantos elementos estão em um enum e se os inteiros têm 32 bits de largura.

```C
// requires /std:c11 or higher
#include <assert.h>

enum Items
{
    A,
    B,
    C,
    LENGTH
};

int main()
{
    // _Static_assert is a C11 keyword
    _Static_assert(LENGTH == 3, "Expected Items enum to have three elements");

    // Preferred: static_assert maps to _Static_Assert and is compatible with C++
    static_assert(sizeof(int) == 4, "Expecting 32 bit integers"); 

    return 0;
}
```

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-------------|---------------------|
|**`static_assert`**|\<assert.h>|

## <a name="see-also"></a>Veja também

[_STATIC_ASSERT macro](../c-runtime-library/reference/static-assert-macro.md)\
[macro Assert e funções](../c-runtime-library/reference/assert-macro-assert-wassert.md) 
 de _assert e _wassert [/STD (especifique a versão padrão do idioma)](../build/reference/std-specify-language-standard-version.md)