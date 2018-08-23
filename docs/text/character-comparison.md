---
title: Comparação de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- comparing characters
- MBCS [C++], character comparison
- characters [C++], comparing
ms.assetid: 18846e44-3e6e-40c4-9b42-3153fb15db20
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 246801abcb04cc8d9c2fd1a005183501bde240d1
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42612320"
---
# <a name="character-comparison"></a>Comparação de caracteres
Use as dicas a seguir:  
  
-   Comparar um byte inicial conhecido com um caractere ASCII funciona corretamente:  
  
    ```  
    if( *sz1 == 'A' )  
    ```  
  
-   Comparação de dois caracteres desconhecidos requer o uso de uma das macros definidas em mbstring:  
  
    ```  
    if( !_mbccmp( sz1, sz2) )  
    ```  
  
     Isso garante que os dois bytes de um caractere de byte duplo são comparados quanto à igualdade.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação MBCS](../text/mbcs-programming-tips.md)   
 [Estouro de buffer](../text/buffer-overflow.md)