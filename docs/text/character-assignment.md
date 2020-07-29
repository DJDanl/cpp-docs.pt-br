---
title: Atribuição de caractere
ms.date: 11/04/2016
helpviewer_keywords:
- characters [C++], assignments
- MBCS [C++], character assignments
ms.assetid: dcc329cd-92df-4e20-817d-364be62ff28f
ms.openlocfilehash: 0f627f88ca2b1d3533d3690cd0316ee047a327ad
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217305"
---
# <a name="character-assignment"></a>Atribuição de caractere

Considere o exemplo a seguir, no qual o **`while`** loop examina uma cadeia de caracteres, copiando todos os caracteres, exceto ' X ', em outra cadeia de caracteres:

```cpp
while( *sz2 )
{
    if( *sz2 != 'X' )
        *sz1++ = *sz2++;
    else
        sz2++;
}
```

O código copia o byte `sz2` para o local apontado para by `sz1` e, em seguida, incrementa `sz1` para receber o próximo byte. Mas se o próximo caractere no `sz2` for um caractere de byte duplo, a atribuição para `sz1` copiar somente o primeiro byte. O código a seguir usa uma função portátil para copiar o caractere com segurança e outro para incrementar `sz1` e `sz2` corretamente:

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

## <a name="see-also"></a>Confira também

[Dicas de programação de MBCS](../text/mbcs-programming-tips.md)<br/>
[Comparação de caracteres](../text/character-comparison.md)
