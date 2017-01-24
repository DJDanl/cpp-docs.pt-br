---
title: "Controles de edi&#231;&#227;o avan&#231;ada sem parte inferior | Microsoft Docs"
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
  - "controles de edição avançada sem parte inferior"
  - "Classe CRichEditCtrl, sem parte inferior"
  - "controles de edição avançada, sem parte inferior"
ms.assetid: 2877dd32-1e9a-4fd1-98c0-66dcbbeef1de
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles de edi&#231;&#227;o avan&#231;ada sem parte inferior
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Seu aplicativo pode redimensionar um controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\) quando necessário de modo que sempre é o mesmo tamanho que seu conteúdo.  Um controle de edição amplo suporte a essa funcionalidade “sem fundo” assim chamada enviando a janela pai uma notificação de [EN\_REQUESTRESIZE](http://msdn.microsoft.com/library/windows/desktop/bb787983) sempre que o tamanho do conteúdo é alterado.  
  
 Ao processar a notificação de **EN\_REQUESTRESIZE** , um aplicativo precisa redimensionar o controle a dimensões na estrutura especificada de [REQRESIZE](http://msdn.microsoft.com/library/windows/desktop/bb787950) .  Um aplicativo também pode mover todas as informações do controle para acomodar a alteração de controle no momento.  Para redimensionar o controle, você pode usar a função [SetWindowPos](../Topic/CWnd::SetWindowPos.md)de `CWnd` .  
  
 Você pode forçar um controle de edição rico sem fundo para enviar uma notificação de **EN\_REQUESTRESIZE** usando a função de membro de [RequestResize](../Topic/CRichEditCtrl::RequestResize.md) .  Essa mensagem pode ser útil no manipulador de [OnSize](../Topic/CWnd::OnSize.md) .  
  
 Para receber notificações de **EN\_REQUESTRESIZE** , você deve habilitar a notificação usando a função de membro de `SetEventMask` .  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)