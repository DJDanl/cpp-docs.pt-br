---
title: "Caixas de di&#225;logo modais e sem janela restrita | Microsoft Docs"
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
  - "caixas de diálogo MFC, modal"
  - "caixas de diálogo MFC, sem modo"
  - "caixas de diálogo modais"
  - "caixas de diálogo sem modo"
ms.assetid: e83df336-5994-4b8f-8233-7942f997315b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caixas de di&#225;logo modais e sem janela restrita
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar a classe [CDialog](../mfc/reference/cdialog-class.md) para gerenciar dois tipos de caixas de diálogo:  
  
-   *Caixas de diálogo modal*, que exigem que o usuário responder antes de continuar o programa  
  
-   *As caixas de diálogo Modeless*, que permanecem na tela e estão disponíveis para uso a qualquer momento mas permitem outras atividades de usuário  
  
 A edição e os procedimentos de recursos para criar um modelo da caixa de diálogo é a mesma para caixas de diálogo modais e modeless.  
  
 Criar uma caixa de diálogo para seu programa exige as seguintes etapas:  
  
1.  Use [editor da caixa de diálogo](../mfc/dialog-editor.md) para criar a caixa de diálogo e crie seu recurso de diálogo\- modelo.  
  
2.  Crie uma classe da caixa de diálogo.  
  
3.  Se conectar [os controles de recurso da caixa de diálogo manipuladores de mensagem](../mfc/adding-event-handlers-for-dialog-box-controls.md) na classe da caixa de diálogo.  
  
4.  Adicionar os membros de dados associados com os controles na caixa de diálogo e especifique [caixa de diálogo de troca de dados](../mfc/dialog-data-exchange.md) e [validações de dados na caixa de diálogo](../mfc/dialog-data-validation.md) dos controles.  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)