---
title: Atribuição de caractere
ms.date: 11/04/2016
helpviewer_keywords:
- characters [C++], assignments
- MBCS [C++], character assignments
ms.assetid: dcc329cd-92df-4e20-817d-364be62ff28f
ms.openlocfilehash: 9099382a212f9f7bd6c071f4e4d9a0c2bc8887de
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50435363"
---
# <a name="character-assignment"></a>Atribuição de caractere

Considere o exemplo a seguir, no qual o **enquanto** loop verifica uma cadeia de caracteres, copiando todos os caracteres, exceto 'X' em outra cadeia de caracteres:

```cpp
while( *sz2 )
{
    if( *sz2 != 'X' )
        *sz1++ = *sz2++;
    else
        sz2++;
}
```

O código copia o byte no `sz2` no local apontado por `sz1`, em seguida, incrementa `sz1` para receber o próximo byte. Porém, se o próximo caractere no `sz2` é um caractere de byte duplo, a atribuição ao `sz1` copia somente o primeiro byte. O código a seguir usa uma função portátil para copiar o caractere com segurança e outro para incrementar `sz1` e `sz2` corretamente:

```cpp
while( *sz2 )
{
    if( *sz2 != 'X' )
    {
        _mbscpy_s( sz1, 1, sz2 );
        sz1 = _mbsinc( sz1 );
        sz2 = _mbsinc( sz2 );
    }
    else
        sz2 = _mbsinc( sz2 );
}
```

## <a name="see-also"></a>Consulte também

[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)<br/>
[Comparação de caracteres](../text/character-comparison.md)