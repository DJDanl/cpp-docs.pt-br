---
title: Palavra-chave _Noreturn e macro noreturn (C11)
description: Descreve a `_Noreturn` palavra-chave e a `noreturn` macro.
ms.date: 10/19/2020
f1_keywords:
- _Noreturn_c
- noreturn
helpviewer_keywords:
- keywords [C]
ms.openlocfilehash: 68448d8b8c999c92fb240100c25048fa94a559b9
ms.sourcegitcommit: 19016630f9d35f365e9ba249e0f3617515d7ca33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/20/2020
ms.locfileid: "92274687"
---
# <a name="_noreturn-keyword-and-noreturn-macro-c11"></a>`_Noreturn` palavra-chave e `noreturn` macro (C11)

A `_Noreturn` palavra-chave foi introduzida em C11. Ele informa ao compilador que a função a que ela é aplicada não retorna ao chamador. O compilador sabe que o código após uma chamada para uma `_Noreturn` função está inacessível. Um exemplo de uma função que não retorna é [abortar](../c-runtime-library/reference/abort.md). Se houver uma possibilidade para o fluxo de controle retornar ao chamador, a função não deverá ter o `_Noreturn` atributo.

A palavra-chave normalmente é usada por meio da macro de conveniência, `noreturn` fornecida em <stdnoreturn. h>, que é mapeada para a `_Noreturn` palavra-chave.

Os principais benefícios de usar `_Noreturn` (ou o equivalente `noreturn` ) estão tornando a intenção da função clara no código para futuros leitores e detectando código inacessível involuntariamente.

Uma função marcada `noreturn` não deve incluir um tipo de retorno porque não retorna um valor para o chamador. Ela deverá ser `void`.

## <a name="example-using-noreturn-macro-and-_noreturn-keyword"></a>Exemplo usando `noreturn` macro e `_Noreturn ` palavra-chave

O exemplo a seguir demonstra a `_Noreturn` palavra-chave e a `noreturn` macro equivalente.

O IntelliSense pode gerar um erro falso, `E0065` se você usar a macro `noreturn` que você pode ignorar. Ele não impede que você execute o exemplo.

```C
// Compile with Warning Level4 (/W4) and /std:c11
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void fatal_error(void)
{
    exit(3);
}

_Noreturn void not_coming_back(void)
{
    puts("There's no coming back");
    fatal_error();
    return; // warning C4645 - function declared with noreturn has a return statement
}

void done(void)
{
    puts("We'll never get here");
}

int main(void)
{
    not_coming_back();
    done(); // warning c4702 - unreachable code

    return 0;
}
```

## <a name="requirements"></a>Requisitos

|Macro|Cabeçalho necessário|
|-------------|---------------------|
|**`noreturn`**|\<stdnoreturn.h>|

## <a name="see-also"></a>Confira também

[/STD (especifique a versão padrão do idioma)](../build/reference/std-specify-language-standard-version.md)\
[/W4 (especificar nível de aviso)](../build/reference/compiler-option-warning-level.md)\
[Aviso de C4702](../error-messages\compiler-warnings\compiler-warning-level-4-c4702.md)\
[__declspec (noreturn)](../cpp/noreturn.md)
