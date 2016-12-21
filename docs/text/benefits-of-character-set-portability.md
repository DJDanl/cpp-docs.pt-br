---
title: "Benef&#237;cios da portabilidade do conjunto de caracteres | Microsoft Docs"
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
  - "conjunto de caracteres [C++], benefícios"
  - "portabilidade [C++], conjuntos de caracteres"
ms.assetid: bd60b925-1498-4e4f-897b-4c8ce66edcf7
caps.latest.revision: 8
caps.handback.revision: 8
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Benef&#237;cios da portabilidade do conjunto de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode se beneficiar do uso de recursos a portabilidade de tempo de execução MFC e do C mesmo que você não pretende atualmente internacionalizar seu aplicativo:  
  
-   Codificar portably faz a sua base de código flexível.  Você pode facilmente posteriormente movê\-lo para Unicode ou a MBCS.  
  
-   Usar Unicode faz seus aplicativos para Windows 2000 mais eficientes.  Como o Windows 2000 usa Unicode, as cadeias de caracteres não Unicode transmitidas ao e do sistema operacional devem ser convertidas, que representem a sobrecarga.  
  
-   Usar MBCS permite dar suporte a mercados internacionais em plataformas do Win32 diferentes do Windows 2000, como o Windows 95 ou Windows 98.  
  
## Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Suporte para Unicode](../text/support-for-unicode.md)