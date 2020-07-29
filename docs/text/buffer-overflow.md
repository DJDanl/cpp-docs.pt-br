---
title: Estouro de buffer
ms.date: 11/04/2016
helpviewer_keywords:
- buffers [C++], character sizes
- buffer overflows [C++]
- MBCS [C++], buffer overflow
ms.assetid: f2b7e40a-f02b-46d8-a449-51d26fc0c663
ms.openlocfilehash: 71877ed770384190cb7f856567d9e7e845e3da19
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217318"
---
# <a name="buffer-overflow"></a>Estouro de buffer

Tamanhos de caracteres variáveis podem causar problemas quando você coloca caracteres em um buffer. Considere o código a seguir, que copia os caracteres de uma cadeia de caracteres, `sz` , em um buffer, `rgch` :

```cpp
cb = 0;
while( cb < sizeof( rgch ) )
    rgch[ cb++ ] = *sz++;
```

A pergunta é: o último byte copiou um byte de Lead? O seguinte não resolve o problema, pois ele pode potencialmente exceder o buffer:

```cpp
cb = 0;
while( cb < sizeof( rgch ) )
{
    _mbccpy( rgch + cb, sz );
    cb += _mbclen( sz );
    sz = _mbsinc( sz );
}
```

A `_mbccpy` chamada tenta fazer a coisa correta — Copie o caractere completo, seja 1 ou 2 bytes. Mas não leva em conta que o último caractere copiado pode não se ajustar ao buffer se o caractere tiver 2 bytes de largura. A solução correta é:

```cpp
cb = 0;
while( (cb + _mbclen( sz )) <= sizeof( rgch ) )
{
    _mbccpy( rgch + cb, sz );
    cb += _mbclen( sz );
    sz = _mbsinc( sz );
}
```

Esse código testa o possível estouro de buffer no teste de loop, usando `_mbclen` para testar o tamanho do caractere atual apontado por `sz` . Fazendo uma chamada para a `_mbsnbcpy` função, você pode substituir o código no **`while`** loop por uma única linha de código. Por exemplo:

```cpp
_mbsnbcpy( rgch, sz, sizeof( rgch ) );
```

## <a name="see-also"></a>Confira também

[Dicas de programação de MBCS](../text/mbcs-programming-tips.md)
