---
title: "Portabilidade do conjunto de benefícios de caractere | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- character sets [C++], benefits
- portability [C++], character sets
ms.assetid: bd60b925-1498-4e4f-897b-4c8ce66edcf7
caps.latest.revision: "8"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 554137352c0a8f7275a051e4026020fce25edbb8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="benefits-of-character-set-portability"></a>Benefícios da portabilidade do conjunto de caracteres
Você pode se beneficiar do uso de recursos de portabilidade de tempo de execução MFC e C mesmo se você atualmente não pretende internacionalizar seu aplicativo:  
  
-   Codificação portably torna o código base flexível. Você posteriormente pode movê-la facilmente para Unicode ou MBCS.  
  
-   Usar Unicode torna mais eficiente seus aplicativos para o Windows 2000. Como o Windows 2000 usa Unicode, cadeias de caracteres não Unicode passadas de e para o sistema operacional devem ser convertidas, que gera sobrecarga.  
  
-   Usar MBCS permite oferecer suporte mercados internacionais em plataformas Win32 que não sejam Windows 2000, como o Windows 95 ou Windows 98.  
  
## <a name="see-also"></a>Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Suporte para Unicode](../text/support-for-unicode.md)