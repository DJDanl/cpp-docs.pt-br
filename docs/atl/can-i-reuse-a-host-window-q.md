---
title: "Posso reutilizar uma janela hospedeira? | Microsoft Docs"
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
  - "o host"
ms.assetid: bcd08ab1-cfcf-49e3-b4e8-ac134d141005
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Posso reutilizar uma janela hospedeira?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Não é recomendável que você reutiliza o host.  Para garantir a robustez de seu código, você deve ao tempo de vida de sua janela hospedeira ao tempo de vida de um único controle.  
  
## Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)