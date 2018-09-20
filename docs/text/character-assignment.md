---
title: Atribuição de caractere | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- characters [C++], assignments
- MBCS [C++], character assignments
ms.assetid: dcc329cd-92df-4e20-817d-364be62ff28f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8e17ace90abef63ce4af1dd56b5bbe8dfed9510c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46429546"
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