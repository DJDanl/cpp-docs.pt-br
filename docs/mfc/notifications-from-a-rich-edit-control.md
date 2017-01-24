---
title: "Notifica&#231;&#245;es de um controle de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
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
  - "Classe CRichEditCtrl, notificações"
  - "mensagens,  (notificação)"
  - "notificações, de CRichEditCtrl"
  - "controles de edição avançada, notificações"
ms.assetid: eb5304fe-f4f3-4557-9ebf-3095dea383c4
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Notifica&#231;&#245;es de um controle de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As notificações informam os eventos que afetem um controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\).  Podem ser processados pela janela pai ou, usando a reflexão de mensagem, o controle de edição rico próprio.  Os controles de edição avançada dão suporte a todas as notificações usadas com controles de edição bem como vários adicionais.  Você pode determinar quais notificações um controle de edição rico envia a janela pai definindo a máscara “evento”.  
  
 Para definir a máscara de evento para um controle de edição avançado, use a função de membro de [SetEventMask](../Topic/CRichEditCtrl::SetEventMask.md) .  Você pode recuperar a máscara de evento atual para um controle de edição rico usando a função de membro de [GetEventMask](../Topic/CRichEditCtrl::GetEventMask.md) .  
  
 Os parágrafos a seguir listam várias notificações específicas e seus usos:  
  
-   **EN\_MSGFILTER** que trata a notificação de **EN\_MSGFILTER** permite que uma classe, ou o controle de edição rico ou a janela pai, filtra toda a entrada de teclado e do mouse para o controle.  O manipulador pode impedir que a mensagem do teclado ou do mouse foi processada ou pode alterar a mensagem modificando a estrutura especificada de [MSGFILTER](http://msdn.microsoft.com/library/windows/desktop/bb787936) .  
  
-   Identificador de**EN\_PROTECTED**a notificação de **EN\_PROTECTED** para detectar quando o usuário tenta modificar o texto protegido.  Para marcar um intervalo de texto como protegido, você pode definir o efeito protegido de caractere.  Para obter mais informações, consulte [Formatação de caractere em controles de edição avançada](../mfc/character-formatting-in-rich-edit-controls.md).  
  
-   **EN\_DROPFILES** você pode habilitar o usuário para remover arquivos em um controle de edição rico processando a notificação de **EN\_DROPFILES** .  A estrutura especificada de [ENDROPFILES](http://msdn.microsoft.com/library/windows/desktop/bb787895) contém informações sobre os arquivos que estão sendo removidos.  
  
-   **EN\_SELCHANGE** um aplicativo pode detectar quando a seleção atual for alterada processando a notificação de **EN\_SELCHANGE** .  A notificação especifica uma estrutura de [SELCHANGE](http://msdn.microsoft.com/library/windows/desktop/bb787952) que contém informações sobre a nova seleção.  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)