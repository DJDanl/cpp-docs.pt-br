---
title: Estouro de buffer | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- buffers [C++], character sizes
- buffer overflows [C++]
- MBCS [C++], buffer overflow
ms.assetid: f2b7e40a-f02b-46d8-a449-51d26fc0c663
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4bfad181ee7c6b702af87bc8ff0a49ccfb42cb65
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="buffer-overflow"></a>Estouro de buffer
Diversos tamanhos de caractere podem causar problemas quando caracteres são colocados em um buffer. Considere o código a seguir, que copia caracteres de uma cadeia de caracteres, `sz`, em um buffer, `rgch`:  
  
```  
cb = 0;  
while( cb < sizeof( rgch ) )  
    rgch[ cb++ ] = *sz++;  
```  
  
 A pergunta é: foi o último byte copiado de um byte inicial? O exemplo a seguir não resolve o problema porque ele pode potencialmente estourar o buffer:  
  
```  
cb = 0;  
while( cb < sizeof( rgch ) )  
{  
    _mbccpy( rgch + cb, sz );  
    cb += _mbclen( sz );  
    sz = _mbsinc( sz );  
}  
```  
  
 O `_mbccpy` chamada tenta realizar a ação correta — copie o caractere completo, se ele é de 1 ou 2 bytes. Mas ela não leva em consideração que o último caractere copiado pode não caber no buffer se o caractere for 2 bytes de largura. A solução correta é:  
  
```  
cb = 0;  
while( (cb + _mbclen( sz )) <= sizeof( rgch ) )  
{  
    _mbccpy( rgch + cb, sz );  
    cb += _mbclen( sz );  
    sz = _mbsinc( sz );  
}  
```  
  
 Esse código de testes de estouro de buffer possíveis no loop de teste, usando `_mbclen` para testar o tamanho do caractere atual apontado pelo `sz`. Fazendo uma chamada para o `_mbsnbcpy` função, você pode substituir o código de `while` loop com uma única linha de código. Por exemplo:  
  
```  
_mbsnbcpy( rgch, sz, sizeof( rgch ) );  
```  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação do MBCS](../text/mbcs-programming-tips.md)