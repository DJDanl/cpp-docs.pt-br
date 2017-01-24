---
title: "Criando caixas de di&#225;logo sem janela restrita | Microsoft Docs"
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
  - "caixas de diálogo MFC, criando"
  - "caixas de diálogo MFC, sem modo"
  - "caixas de diálogo sem modo, criando"
ms.assetid: 70d78c7f-3d40-477b-9f78-0f33c359f88b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando caixas de di&#225;logo sem janela restrita
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para uma caixa de diálogo modeless, você deve fornecer seu próprio construtor público em sua classe da caixa de diálogo.  Para criar uma caixa de diálogo modeless, chame o construtor público e chame a função de membro de [Crie](../Topic/CDialog::Create.md) do objeto da caixa de diálogo para carregar o recurso da caixa de diálogo.  Você pode chamar **Criar** o durante ou depois da chamada de construtor.  Se o recurso de diálogo tem a propriedade **WS\_VISIBLE**, a caixa de diálogo aparecerá imediatamente.  Caso contrário, você deve chamar a função de membro de [ShowWindow](../Topic/CWnd::ShowWindow.md) .  
  
## Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)