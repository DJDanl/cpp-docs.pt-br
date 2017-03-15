---
title: "Gerenciando janelas filhos MDI | Microsoft Docs"
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
  - "MDICLIENT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "janelas filho"
  - "janelas filho, e janela MDICLIENT"
  - "janelas com moldura [C++], Janelas filho MDI"
  - "MDI [C++], janelas filho"
  - "MDI [C++], janelas com moldura"
  - "Janela MDICLIENT"
  - "janelas [C++], MDI"
ms.assetid: 1828d96e-a561-48ae-a661-ba9701de6bee
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciando janelas filhos MDI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As janelas do quadro principal \(MDI uma pelo aplicativo\) contêm uma janela filho especial chamada a janela de **MDICLIENT** .  A janela de **MDICLIENT** gerencia a área da janela do quadro principal, e própria cliente tem janelas filho: as janelas de documentos, derivadas de `CMDIChildWnd`.  Como as janelas de documentos são as janelas próprias do quadro \(janelas filho MDI\), também podem ter seus próprios filhos.  Em todos esses casos, a janela pai gerencia as janelas filho e encaminha\-lhes alguns comandos.  
  
 Em uma janela do quadro MDI, a janela do quadro gerencia a janela de **MDICLIENT** , reposicionando a junto com barras de controle.  A janela de **MDICLIENT** , por sua vez, gerencia todas as janelas filho MDI do quadro.  A figura a seguir mostra a relação entre uma janela do quadro MDI, a janela de **MDICLIENT** , e as janelas filho do quadro do documento.  
  
 ![Janelas de quadro MDI filho](../mfc/media/vc37gb1.png "vc37GB1")  
O windows e filho MDI do quadro  
  
 Uma janela do quadro MDI também funciona em conjunto com a janela filho MDI atual, se houver.  As mensagens do comando de representantes da janela do quadro MDI ao filho MDI antes de tentar os tratar própria.  
  
## Que você deseja saber mais?  
  
-   [Criando o windows do quadro do documento](../Topic/Creating%20Document%20Frame%20Windows.md)  
  
-   [Estilos de Quadro\- janela](../Topic/Frame-Window%20Styles%20\(C++\).md)  
  
## Consulte também  
 [Usando janelas com moldura](../Topic/Using%20Frame%20Windows.md)