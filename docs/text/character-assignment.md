---
title: "Atribui&#231;&#227;o de caractere | Microsoft Docs"
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
  - "caracteres [C++], atribuições"
  - "MBCS [C++], atribuições de caractere"
ms.assetid: dcc329cd-92df-4e20-817d-364be62ff28f
caps.latest.revision: 9
caps.handback.revision: 9
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Atribui&#231;&#227;o de caractere
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Considere o exemplo a seguir, em que o loop de `while` examina uma cadeia de caracteres, copiando todos os caracteres exceto “X” em outra cadeia de caracteres:  
  
```  
while( *sz2 )  
{  
    if( *sz2 != 'X' )  
        *sz1++ = *sz2++;  
    else  
        sz2++;  
}  
```  
  
 O código copia bytes no `sz2` ao local apontado por `sz1`, a seguir incrementa `sz1` para receber o byte seguir.  Mas se o próximo caractere em `sz2` é um caractere de byte duplo, a atribuição a `sz1` copia só o primeiro byte.  O código a seguir usa uma função portátil para copiar segurança com o caractere e outro para incrementar corretamente `sz1` e `sz2` :  
  
```  
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
  
## Consulte também  
 [Dicas de programação MBCS](../Topic/MBCS%20Programming%20Tips.md)   
 [Comparação de caracteres](../text/character-comparison.md)