---
title: "Implementa&#231;&#227;o da barra de status no MFC | Microsoft Docs"
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
  - "COldStatusBar"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe COldStatusBar"
  - "Classe CStatusBar, e classe CStatusBarCtrl"
  - "Classe CStatusBar, e barras de status de MFC"
  - "Classe CStatusBarCtrl, e classe CStatusBar"
  - "Classe CStatusBarCtrl, e barras de status de MFC"
  - "barras de status, e classe CStatusBarCtrl"
  - "barras de status, compatibilidade com versões anteriores"
  - "barras de status, implementando em MFC"
  - "barras de status, antigo com classe COldStatusBar"
  - "barras de status, implementação do Windows 95"
  - "indicadores de status"
ms.assetid: be5cd876-38e3-4d5c-b8cb-16d57a16a142
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementa&#231;&#227;o da barra de status no MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um objeto de [CStatusBar](../mfc/reference/cstatusbar-class.md) é uma barra de controle com uma linha de painéis de saída de texto.  Painéis de saída são usados como linhas de mensagem e como indicadores de status.  Os exemplos incluem as linhas de ajuda\- mensagem de menu que explicam brevemente o comando de menu selecionado e indicadores que mostram o status de SCROLL LOCK, NUMERIC de bloqueio, e outras chaves.  
  
 A partir da versão 4,0 do MFC, as barras de status são implementadas usando a classe [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md), que encapsula um controle comuns da barra de status.  Para compatibilidade com versões anteriores, o MFC retém a implementação mais antigo da barra de status da classe **COldStatusBar**.  A documentação para versões anteriores de MFC descreve **COldStatusBar** em `CStatusBar`.  
  
 [CStatusBar::GetStatusBarCtrl](../Topic/CStatusBar::GetStatusBarCtrl.md), uma função de membro novo MFC a 4,0, que possibilita o aproveitamento de suporte comuns de controle do windows para personalização e a funcionalidade adicional da barra de status.  as funções de membro de`CStatusBar` dão\-no mais a funcionalidade de controles comum do windows; no entanto, quando você chama `GetStatusBarCtrl`, você pode atribuir às barras de status ainda mais as características de uma barra de status.  Quando você chama `GetStatusBarCtrl`, retornará uma referência a um objeto de `CStatusBarCtrl` .  Você pode usar essa referência para manipular o controle da barra de status.  
  
 A seguinte figura mostra uma barra de status que exibe vários medidores.  
  
 ![Barra de status](../mfc/media/vc37dy1.png "vc37DY1")  
Uma barra de status  
  
 Como a barra de ferramentas, o objeto da barra de status será inserido na janela pai do quadro e construído automaticamente quando a janela do quadro é construída.  A barra de status, como todas as barras de controle, destruída também será automaticamente quando o quadro pai é destruído.  
  
## Que você deseja saber mais?  
  
-   [Atualizando o texto de um painel barra de status](../mfc/updating-the-text-of-a-status-bar-pane.md)  
  
-   O classifica [CStatusBar](../mfc/reference/cstatusbar-class.md) e [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)MFC  
  
-   [Barras de controle](../Topic/Control%20Bars.md)  
  
-   [Barras da caixa de diálogo](../mfc/dialog-bars.md)  
  
-   [Barras de ferramentas \(implementação da barra de ferramentas de MFC\)](../mfc/mfc-toolbar-implementation.md)  
  
## Consulte também  
 [Barras de status](../mfc/status-bars.md)