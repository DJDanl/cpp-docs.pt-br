---
title: "Componentes da caixa de di&#225;logo no Framework | Microsoft Docs"
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
  - "classes da caixa de diálogo, componentes da caixa de diálogo"
  - "modelos de caixa de diálogo, Estrutura MFC"
  - "caixas de diálogo MFC, sobre caixas de diálogo MFC"
  - "caixas de diálogo MFC, criando"
  - "caixas de diálogo MFC, recurso de caixa de diálogo"
ms.assetid: 592db160-0a8a-49be-ac72-ead278aca53f
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Componentes da caixa de di&#225;logo no Framework
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na estrutura de MFC, uma caixa de diálogo tem dois componentes:  
  
-   Um recurso de diálogo\- modelo que especifica da caixa de diálogo seu posicionamento da caixa controles e.  
  
     O recurso da caixa de diálogo armazena um modelo da caixa de diálogo da qual o windows cria a janela caixa de diálogo e a exibição.  O modelo especifica as características da caixa de diálogo, incluindo seu tamanho, local, estilo, e os tipos e as posições de controles da caixa de diálogo.  Você usará um modelo geral da caixa de diálogo armazenado como um recurso, mas você também pode criar seu próprio modelo na memória.  
  
-   Uma classe da caixa de diálogo, derivado de [CDialog](../mfc/reference/cdialog-class.md), para fornecer uma interface programática para gerenciar a caixa de diálogo.  
  
     Um diálogo é uma janela e será anexada a uma janela do windows quando visível.  Quando a janela caixa de diálogo é criada, o recurso de diálogo\- modelo é usado como modelo para criar controles da janela filho para a caixa de diálogo.  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)