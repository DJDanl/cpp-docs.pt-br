---
title: "Atribuição de caractere | Microsoft Docs"
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
- characters [C++], assignments
- MBCS [C++], character assignments
ms.assetid: dcc329cd-92df-4e20-817d-364be62ff28f
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 266d3284716647fa073f76ef6ef871a3abd179bb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="character-assignment"></a>Atribuição de caractere
Considere o exemplo a seguir, no qual o `while` loop verifica uma cadeia de caracteres, copiando todos os caracteres, exceto 'X' em outra cadeia de caracteres:  
  
```  
while( *sz2 )  
{  
    if( *sz2 != 'X' )  
        *sz1++ = *sz2++;  
    else  
        sz2++;  
}  
```  
  
 O código copia o byte no `sz2` no local apontado pela `sz1`, em seguida, incrementa `sz1` para receber o próximo byte. Mas se o próximo caractere em `sz2` é um caractere de byte duplo, a atribuição ao `sz1` copia somente o primeiro byte. O código a seguir usa uma função portátil para copiar o caractere com segurança e outro para incrementar `sz1` e `sz2` corretamente:  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação MBCS](../text/mbcs-programming-tips.md)   
 [Comparação de caracteres](../text/character-comparison.md)