---
title: "Quando eu preciso de chamar AtlAxWinInit? | Microsoft Docs"
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
  - "AtlAxWinInit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de AtlAxWinInit"
ms.assetid: 080b9cfe-d85a-4439-a9e9-ab3966ebaa8e
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Quando eu preciso de chamar AtlAxWinInit?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[AtlAxWinInit](../Topic/AtlAxWinInit.md) registra a classe de janela de **"AtlAxWin80"** \(mais um par mensagens personalizadas da janela\) para que essa função deve ser chamada antes de tentar criar uma janela hospedeira.  Em o entanto, você nem sempre precisará chamar explicitamente essa função, desde que as APIs de hospedagem \(e as classes que usam os chamam\) geralmente essa função para você.  Não há nenhum danos em chamar essa função mais de uma vez.  Para obter mais informações, consulte [O que é ATL API de Hospedagem?](../atl/what-is-the-atl-control-hosting-api-q.md).  
  
## Consulte também  
 [Quando eu preciso de chamar AtlAxWinTerm?](../atl/when-do-i-need-to-call-atlaxwinterm-q.md)   
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)