---
title: "Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl | Microsoft Docs"
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
  - "CToolTipCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CToolTipCtrl, usando"
  - "dicas de ferramenta [C++], criando"
ms.assetid: 0a34583f-f66d-46a1-a239-31b80ea395ad
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando CToolTipCtrl para criar e manipular um objeto CToolTipCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Aqui está um exemplo de uso de [CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md) :  
  
### Para criar e manipular um CToolTipCtrl  
  
1.  Construir o objeto de `CToolTipCtrl` .  
  
2.  Chame [Crie](../Topic/CToolTipCtrl::Create.md) para criar o controle de comum de dica de ferramenta do windows e anexá\-lo ao objeto de `CToolTipCtrl` .  
  
3.  Chame [AddTool](../Topic/CToolTipCtrl::AddTool.md) para registrar uma ferramenta com o controle da dica de ferramenta, de modo que as informações armazenadas na dica de ferramenta é exibida quando o cursor é a ferramenta.  
  
4.  Chame [SetToolInfo](../Topic/CToolTipCtrl::SetToolInfo.md) para definir as informações que uma dica de ferramenta mantém para uma ferramenta.  
  
5.  Chame [SetToolRect](../Topic/CToolTipCtrl::SetToolRect.md) para definir um novo retângulo delimitador para uma ferramenta.  
  
6.  Chame [HitTest](../Topic/CToolTipCtrl::HitTest.md) para testar um ponto para determinar se estiver dentro do retângulo delimitador da ferramenta fornecida e, nesse caso, recuperar informações sobre a ferramenta.  
  
7.  Chame [GetToolCount](../Topic/CToolTipCtrl::GetToolCount.md) para recuperar uma contagem das ferramentas registradas com o controle da dica de ferramenta.  
  
## Consulte também  
 [Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)   
 [Controles](../mfc/controls-mfc.md)