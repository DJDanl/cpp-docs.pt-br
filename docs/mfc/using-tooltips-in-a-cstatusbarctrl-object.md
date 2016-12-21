---
title: "Usando dicas de ferramenta em um objeto CStatusBarCtrl | Microsoft Docs"
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
  - "CStatusBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CStatusBarCtrl, dicas de ferramenta"
  - "barras de status, dicas de ferramenta"
  - "dicas de ferramenta [C++], usando em barras de status"
ms.assetid: a77597a7-43ef-4b8f-87bc-a8ea1dc63dc3
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando dicas de ferramenta em um objeto CStatusBarCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para habilitar dicas de ferramenta para uma barra de status controle, crie o objeto de `CStatusBarCtrl` com o estilo de **SBT\_TOOLTIPS** .  
  
> [!NOTE]
>  Se você estiver usando um objeto de `CStatusBar` para implementar a barra de status, use a função de `CStatusBar::CreateEx` .  Permite que você especifique estilo adicionais para o objeto de **CStatusBarCtrl** inserido.  
  
 Uma vez que o objeto de `CStatusBarCtrl` foi criado com êxito, use [CStatusBarCtrl::SetTipText](../Topic/CStatusBarCtrl::SetTipText.md) e [CStatusBarCtrl::GetTipText](../Topic/CStatusBarCtrl::GetTipText.md) definir e recuperar o texto de dica para um painel específico.  
  
 Uma vez que a dica de ferramenta tiver sido definida, será exibida apenas se a parte não tem um ícone e nenhum texto, ou se todo o texto não pode ser exibido na parte.  As dicas de ferramenta não têm suporte no modo simples.  
  
## Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)