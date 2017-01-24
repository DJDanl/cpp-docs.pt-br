---
title: "Interface de ICommandSource | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ICommandSource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface de ICommandSource"
ms.assetid: a4b1f698-c09f-4ba8-9b13-0e74a0a4967e
caps.latest.revision: 24
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface de ICommandSource
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia os comandos enviados de um objeto de fonte de comando para um controle de usuário.  
  
## Sintaxe  
  
```  
interface class ICommandSource  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ICommandSource::AddCommandHandler](../Topic/ICommandSource::AddCommandHandler.md)|Adiciona um manipulador de comando para um objeto de fonte de comando.|  
|[ICommandSource::AddCommandRangeHandler](../Topic/ICommandSource::AddCommandRangeHandler.md)|Adiciona um grupo de manipuladores de comando para um objeto de fonte de comando.|  
|[ICommandSource::AddCommandRangeUIHandler](../Topic/ICommandSource::AddCommandRangeUIHandler.md)|Adiciona um grupo de manipuladores de mensagem de comando de interface de usuário para um objeto de fonte de comando.|  
|[ICommandSource::AddCommandUIHandler](../Topic/ICommandSource::AddCommandUIHandler.md)|Adiciona um manipulador de mensagem de comando de interface de usuário para um objeto de fonte de comando.|  
|[ICommandSource::PostCommand](../Topic/ICommandSource::PostCommand.md)|Enviar uma mensagem sem esperá\-la a ser processada.|  
|[ICommandSource::RemoveCommandHandler](../Topic/ICommandSource::RemoveCommandHandler.md)|Remove um manipulador de comando de um objeto de fonte de comando.|  
|[ICommandSource::RemoveCommandRangeHandler](../Topic/ICommandSource::RemoveCommandRangeHandler.md)|Remove um grupo de manipuladores de comando de um objeto de fonte de comando.|  
|[ICommandSource::RemoveCommandRangeUIHandler](../Topic/ICommandSource::RemoveCommandRangeUIHandler.md)|Remove um grupo de manipuladores de mensagem de comando de interface do usuário de um objeto de fonte de comando.|  
|[ICommandSource::RemoveCommandUIHandler](../Topic/ICommandSource::RemoveCommandUIHandler.md)|Remove um manipulador de mensagem de comando de interface do usuário de um objeto de fonte de comando.|  
|[ICommandSource::SendCommand](../Topic/ICommandSource::SendCommand.md)|Enviar uma mensagem e espera\-à ser processada antes de retornar.|  
  
## Comentários  
 Quando você hospeda um controle de usuário em uma visualização MFC, [Classe de CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos e rotear mensagens de interface de usuário de comando de atualização para o controle de usuário permitir que manipula comandos MFC \(por exemplo, itens de menu do quadro e botões da barra de ferramentas\).  Implementando [Interface de ICommandTarget](../../mfc/reference/icommandtarget-interface.md), você o controle permite ao usuário uma referência ao objeto de `ICommandSource` .  
  
 [Como adicionar roteamento de comando ao controle dos Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) consulte para um exemplo de como usar `ICommandTarget`.  
  
 Para obter mais informações sobre como usar formulários do windows, consulte [Usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
## Requisitos  
 **Cabeçalho:** afxwinforms.h \(definido no assembly atlmfc\\lib\\mfcmifc80.dll\)  
  
## Consulte também  
 [Como adicionar roteamento de comando ao controle dos Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)   
 [Interface de ICommandTarget](../../mfc/reference/icommandtarget-interface.md)