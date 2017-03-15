---
title: "Fechando a caixa de di&#225;logo | Microsoft Docs"
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
  - "caixas de diálogo, fechamento"
  - "caixas de diálogo MFC, fechamento"
ms.assetid: 946f5675-c482-46a4-a5dd-34fe138ffae5
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fechando a caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma caixa de diálogo modal é fechada quando o usuário escolhe um dos botões, normalmente o botão OK ou o botão cancelar.  Escolhendo OK ou janelas de transfere o botão cancelar para enviar a caixa de diálogo objeto uma mensagem de controle\- notificação de **BN\_CLICKED** com a ID do botão, **IDOK** ou **IDCANCEL**.  `CDialog` fornece funções padrão do manipulador dessas mensagens: `OnOK` e `OnCancel`.  Os manipuladores padrão chamam a função de membro de `EndDialog` para fechar a janela caixa de diálogo.  Você também pode chamar `EndDialog` de seu próprio código.  Para obter mais informações, veja a função de membro de [EndDialog](../Topic/CDialog::EndDialog.md) da classe `CDialog`*na referência de MFC*.  
  
 Para organizar para fechar e excluir uma caixa de diálogo, uma substituição modeless `PostNcDestroy` e invocar o operador de **delete** no ponteiro de **this** .  [Destruindo a caixa de diálogo](../Topic/Destroying%20the%20Dialog%20Box.md) explica o que acontece depois do.  
  
## Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)