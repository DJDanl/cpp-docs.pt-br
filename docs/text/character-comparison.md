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
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b969783a19c0836a8ab81d75820fc688df3ef31e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33854945"
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