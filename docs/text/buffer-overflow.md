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
ms.openlocfilehash: 11a3da883dae4d292a55eb2537fd98609404b5a9
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42609506"
---
# <a name="buffer-overflow"></a>Estouro de buffer
Variados tamanhos de caractere podem causar problemas quando você coloca caracteres em um buffer. Considere o código a seguir, que copia caracteres de uma cadeia de caracteres, `sz`, em um buffer, `rgch`:  
  
```  
cb = 0;  
while( cb < sizeof( rgch ) )  
    rgch[ cb++ ] = *sz++;  
```  
  
 A pergunta é: foi o último byte copiado de um byte inicial? A seguir não resolve o problema porque ele pode potencialmente estourar o buffer:  
  
```  
cb = 0;  
while( cb < sizeof( rgch ) )  
{  
    _mbccpy( rgch + cb, sz );  
    cb += _mbclen( sz );  
    sz = _mbsinc( sz );  
}  
```  
  
 O `_mbccpy` chamada tenta fazer a coisa correta — copiar o caractere completo, se ele é 1 ou 2 bytes. Mas ela não leva em consideração que o último caractere copiado pode não caber no buffer se o caractere é 2 bytes de largura. A solução correta é:  
  
```  
cb = 0;  
while( (cb + _mbclen( sz )) <= sizeof( rgch ) )  
{  
    _mbccpy( rgch + cb, sz );  
    cb += _mbclen( sz );  
    sz = _mbsinc( sz );  
}  
```  
  
 Esse código testa estouro de buffer possível no loop de teste, usando `_mbclen` para testar o tamanho do caractere atual apontado pelo `sz`. Fazendo uma chamada para o `_mbsnbcpy` função, você pode substituir o código em de **enquanto** loop com uma única linha de código. Por exemplo:  
  
```  
_mbsnbcpy( rgch, sz, sizeof( rgch ) );  
```  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação do MBCS](../text/mbcs-programming-tips.md)