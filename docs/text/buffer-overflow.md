---
title: "Estouro de buffer | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "estouro de buffer [C++]"
  - "buffers [C++], tamanhos de caractere"
  - "MBCS [C++], estouro de buffer"
ms.assetid: f2b7e40a-f02b-46d8-a449-51d26fc0c663
caps.latest.revision: 8
caps.handback.revision: 8
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Estouro de buffer
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os tamanhos de caracteres de negócio podem causar problemas quando você coloca caracteres em um buffer.  Considere o seguinte código, que copia caracteres de uma cadeia de caracteres, `sz`, em um buffer, `rgch`:  
  
```  
cb = 0;  
while( cb < sizeof( rgch ) )  
    rgch[ cb++ ] = *sz++;  
```  
  
 A questão é: Era o byte o último copiado um byte inicial?  O a seguir não resolve o problema porque podem potencialmente transbordar o buffer:  
  
```  
cb = 0;  
while( cb < sizeof( rgch ) )  
{  
    _mbccpy( rgch + cb, sz );  
    cb += _mbclen( sz );  
    sz = _mbsinc( sz );  
}  
```  
  
 As tentativas de chamada de `_mbccpy` de uma maneira correta — copiar o caractere completo, se for 1 ou 2 bytes.  Mas não considerar que o último caractere copiado não pode ajustar o buffer se o caractere é de 2 bytes de comprimento.  A solução é correta:  
  
```  
cb = 0;  
while( (cb + _mbclen( sz )) <= sizeof( rgch ) )  
{  
    _mbccpy( rgch + cb, sz );  
    cb += _mbclen( sz );  
    sz = _mbsinc( sz );  
}  
```  
  
 Os testes deste código para o buffer possível estouro no teste de loop, usando `_mbclen` para testar o tamanho atual de caracteres apontada por `sz`.  Fazendo uma chamada à função de `_mbsnbcpy` , você pode substituir o código no loop de `while` com uma única linha de código.  Por exemplo:  
  
```  
_mbsnbcpy( rgch, sz, sizeof( rgch ) );  
```  
  
## Consulte também  
 [Dicas de programação MBCS](../Topic/MBCS%20Programming%20Tips.md)