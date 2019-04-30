---
title: Estouro de buffer
ms.date: 11/04/2016
helpviewer_keywords:
- buffers [C++], character sizes
- buffer overflows [C++]
- MBCS [C++], buffer overflow
ms.assetid: f2b7e40a-f02b-46d8-a449-51d26fc0c663
ms.openlocfilehash: 7f9864e6b49446ea68d82e76e877ce9c677b893d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410753"
---
# <a name="buffer-overflow"></a>Estouro de buffer

Variados tamanhos de caractere podem causar problemas quando você coloca caracteres em um buffer. Considere o código a seguir, que copia caracteres de uma cadeia de caracteres, `sz`, em um buffer, `rgch`:

```cpp
cb = 0;
while( cb < sizeof( rgch ) )
    rgch[ cb++ ] = *sz++;
```

A pergunta é: Foi o último byte copiado de um byte inicial? A seguir não resolve o problema porque ele pode potencialmente estourar o buffer:

```cpp
cb = 0;
while( cb < sizeof( rgch ) )
{
    _mbccpy( rgch + cb, sz );
    cb += _mbclen( sz );
    sz = _mbsinc( sz );
}
```

O `_mbccpy` chamada tenta fazer a coisa correta — copiar o caractere completo, se ele é 1 ou 2 bytes. Mas ela não leva em consideração que o último caractere copiado pode não caber no buffer se o caractere é 2 bytes de largura. A solução correta é:

```cpp
cb = 0;
while( (cb + _mbclen( sz )) <= sizeof( rgch ) )
{
    _mbccpy( rgch + cb, sz );
    cb += _mbclen( sz );
    sz = _mbsinc( sz );
}
```

Esse código testa estouro de buffer possível no loop de teste, usando `_mbclen` para testar o tamanho do caractere atual apontado pelo `sz`. Fazendo uma chamada para o `_mbsnbcpy` função, você pode substituir o código em de **enquanto** loop com uma única linha de código. Por exemplo:

```cpp
_mbsnbcpy( rgch, sz, sizeof( rgch ) );
```

## <a name="see-also"></a>Consulte também

[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)
