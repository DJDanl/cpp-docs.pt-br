---
title: "Comparação de caracteres | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- comparing characters
- MBCS [C++], character comparison
- characters [C++], comparing
ms.assetid: 18846e44-3e6e-40c4-9b42-3153fb15db20
caps.latest.revision: "8"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 28c2cd3a2e868a595d73d06b5cae8e71ec8cc313
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="character-comparison"></a>Comparação de caracteres
Use as dicas a seguir:  
  
-   Comparação de um byte conhecido com um caractere ASCII funciona corretamente:  
  
    ```  
    if( *sz1 == 'A' )  
    ```  
  
-   Comparação de dois caracteres desconhecidos requer o uso de uma das macros definidas em Mbstring.h:  
  
    ```  
    if( !_mbccmp( sz1, sz2) )  
    ```  
  
     Isso garante que ambos os bytes de um caractere de byte duplo são comparados para igualdade.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação MBCS](../text/mbcs-programming-tips.md)   
 [Estouro de buffer](../text/buffer-overflow.md)