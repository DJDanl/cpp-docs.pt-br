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
ms.openlocfilehash: c5efdaefdfd961a10d40c00855261eb547164f95
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42591395"
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