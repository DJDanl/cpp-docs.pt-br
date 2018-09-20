---
title: Estouro de buffer | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- buffers [C++], character sizes
- buffer overflows [C++]
- MBCS [C++], buffer overflow
ms.assetid: f2b7e40a-f02b-46d8-a449-51d26fc0c663
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 109719b437716e31fc5ebdcd43c02c55bfea997d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46413478"
---
# <a name="buffer-overflow"></a>Estouro de buffer

Variados tamanhos de caractere podem causar problemas quando você coloca caracteres em um buffer. Considere o código a seguir, que copia caracteres de uma cadeia de caracteres, `sz`, em um buffer, `rgch`:

```cpp
cb = 0;
while( cb < sizeof( rgch ) )
    rgch[ cb++ ] = *sz++;
```

A pergunta é: foi o último byte copiado de um byte inicial? A seguir não resolve o problema porque ele pode potencialmente estourar o buffer:

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