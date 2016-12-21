---
title: "NotifyHandler | Microsoft Docs"
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
  - "NotifyHandler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função de NotifyHandler"
ms.assetid: 5ff953ec-de35-42bc-8b3c-d384d636c139
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# NotifyHandler
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O nome da função identificada pelo terceiro parâmetro de macro de `NOTIFY_HANDLER` no mapa de mensagem.  
  
## Sintaxe  
  
```  
  
      LRESULT   
      NotifyHandler  
      (  
   int idCtrl,  
   LPNMHDR pnmh,  
   BOOL& bHandled   
);  
```  
  
#### Parâmetros  
 `idCtrl`  
 O identificador do controle que envia a mensagem.  
  
 *pnmh*  
 Endereço de uma estrutura de [NMHDR](http://msdn.microsoft.com/library/windows/desktop/bb775514) que contém o código e informações adicionais de notificação.  Para algumas notificações, pontos de este parâmetro a estrutura maior que possui a estrutura de **NMHDR** como o primeiro membro.  
  
 `bHandled`  
 O mapa de mensagem `bHandled` define a **Verdadeiro** antes que *NotifyHandler* seja chamado.  Se *NotifyHandler* não trata totalmente a mensagem, deve definir `bHandled` a **Falso** para indicar a adicional das necessidades de mensagem.  
  
## Valor de retorno  
 O resultado de processamento de mensagem.  0 se com êxito.  
  
## Comentários  
 Para um exemplo de como usar este manipulador de mensagem em um mapa de mensagem, consulte [NOTIFY\_HANDLER](../Topic/NOTIFY_HANDLER.md).  
  
## Consulte também  
 [Implementando uma janela](../atl/implementing-a-window.md)   
 [Mapas de mensagem](../atl/message-maps-atl.md)   
 [WM\_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583)