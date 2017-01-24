---
title: "Criando caixas de di&#225;logo modais | Microsoft Docs"
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
  - "caixas de diálogo MFC, modal"
  - "caixas de diálogo modais, criando"
ms.assetid: 26c7a68c-79f6-4862-a5a8-6024984644d2
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando caixas de di&#225;logo modais
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para criar uma caixa de diálogo modal, chamar qualquer um dos dois construtores públicos declarados em [CDialog](../mfc/reference/cdialog-class.md).  Em seguida, chame a função de membro de [DoModal](../Topic/CDialog::DoModal.md) do objeto da caixa de diálogo para exibir a caixa de diálogo e para gerenciar a interação com ela até que o usuário escolha OK ou o cancelamento.  Este gerenciamento por `DoModal` é o que faz a caixa de diálogo modal.  Para caixas de diálogo modal, `DoModal` carrega o recurso da caixa de diálogo.  
  
## Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)