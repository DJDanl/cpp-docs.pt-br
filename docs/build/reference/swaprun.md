---
title: "/SWAPRUN | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/swaprun"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /SWAPRUN (editbin)"
  - "opção editbin SWAPRUN"
  - "opção editbin -SWAPRUN"
ms.assetid: 6eefd7f3-ca47-48e3-8509-323d27cf4ae7
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /SWAPRUN
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/SWAPRUN:{[!]NET|[!]CD}  
```  
  
## Comentários  
 Essa opção edita a imagem para informar o sistema operacional para copiar imagem em um arquivo de permuta e para executá\-lo de lá.  Use esta opção para as imagens que residem em redes ou uma mídia removível.  
  
 Você pode adicionar ou remover os qualificadores de O ou do CD:  
  
-   A O indica que a imagem reside em uma rede.  
  
-   O CD indica que a imagem reside em um CD\-ROM ou em uma mídia removível semelhante.  
  
-   Use\! NETWORK e\! CD para reverter os efeitos de O e do CD.  
  
## Consulte também  
 [Opções EDITBIN](../../build/reference/editbin-options.md)