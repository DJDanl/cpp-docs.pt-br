---
title: "Portabilidade do conjunto de benefícios de caractere | Microsoft Docs"
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
- character sets [C++], benefits
- portability [C++], character sets
ms.assetid: bd60b925-1498-4e4f-897b-4c8ce66edcf7
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7ce02fa834c39f629990d4f3c9785de94bd02196
ms.sourcegitcommit: a5916b48541f804a79891ff04e246628b5f9a24a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/09/2018
---
# <a name="benefits-of-character-set-portability"></a>Benefícios da portabilidade do conjunto de caracteres
Você pode se beneficiar do uso de recursos de portabilidade de tempo de execução MFC e C mesmo se você atualmente não pretende internacionalizar seu aplicativo:  
  
-   Codificação portably torna o código base flexível. Você posteriormente pode movê-la facilmente para Unicode ou MBCS.  
  
-   Usar Unicode torna mais eficiente seus aplicativos para Windows. Como o Windows usa o Unicode, cadeias de caracteres não Unicode passadas de e para o sistema operacional devem ser convertidas, que gera sobrecarga.  

  
## <a name="see-also"></a>Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Suporte para Unicode](../text/support-for-unicode.md)