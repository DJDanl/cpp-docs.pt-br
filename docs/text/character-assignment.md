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
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 084cfd69a3742db10e09e9d97974a0666fa31a47
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40010406"
---
# <a name="character-assignment"></a>Atribuição de caractere
Considere o exemplo a seguir, no qual o **enquanto** loop verifica uma cadeia de caracteres, copiando todos os caracteres, exceto 'X' em outra cadeia de caracteres:  
  
```  
while( *sz2 )  
{  
    if( *sz2 != 'X' )  
        *sz1++ = *sz2++;  
    else  
        sz2++;  
}  
```  
  
 O código copia o byte no `sz2` no local apontado por `sz1`, em seguida, incrementa `sz1` para receber o próximo byte. Porém, se o próximo caractere no `sz2` é um caractere de byte duplo, a atribuição ao `sz1` copia somente o primeiro byte. O código a seguir usa uma função portátil para copiar o caractere com segurança e outro para incrementar `sz1` e `sz2` corretamente:  
  
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