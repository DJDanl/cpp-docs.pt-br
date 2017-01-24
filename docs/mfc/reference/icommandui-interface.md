---
title: "Interface de ICommandUI | Microsoft Docs"
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
  - "ICommandUI"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface de ICommandUI"
ms.assetid: 134afe8d-dcdf-47ca-857a-a166a6b665dd
caps.latest.revision: 24
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface de ICommandUI
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia comandos de interface do usuário.  
  
## Sintaxe  
  
```  
interface class ICommandUI  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ICommandUI::Check](../Topic/ICommandUI::Check.md)|Define o item de interface de usuário para esse comando apropriado ao estado de verificação.|  
|[ICommandUI::ContinueRouting](../Topic/ICommandUI::ContinueRouting.md)|Com o mecanismo de comando para roteamento continuar a rotear mensagens na atual de cadeia manipuladores.|  
|[ICommandUI::Enabled](../Topic/ICommandUI::Enabled.md)|Habilita ou desabilita o item de interface de usuário para este comando.|  
|[ICommandUI::ID](../Topic/ICommandUI::ID.md)|Obtém a identificação do objeto de interface do usuário representado pelo objeto de `ICommandUI` .|  
|[ICommandUI::Index](../Topic/ICommandUI::Index.md)|Obtém o índice do objeto de interface do usuário representado pelo objeto de `ICommandUI` .|  
|[ICommandUI::Radio](../Topic/ICommandUI::Radio.md)|Define o item de interface de usuário para esse comando apropriado ao estado de verificação.|  
|[ICommandUI::Text](../Topic/ICommandUI::Text.md)|Define o texto do item de interface de usuário para este comando.|  
  
## Comentários  
 Essa interface fornece métodos e propriedades que gerenciam os comandos de interface do usuário.  `ICommandUI` é semelhante a [Classe de CCmdUI](../Topic/CCmdUI%20Class.md), exceto que `ICommandUI` é usado para aplicativos MFC que interoperam com componentes .NET.  
  
 `ICommandUI` é usado dentro de um manipulador em [ICommandTarget](../../mfc/reference/icommandtarget-interface.md)\- classe derivada de `ON_UPDATE_COMMAND_UI` .  Quando um usuário de um aplicativo ativa \(selecionar\) ou clica em um menu, cada item de menu é exibido como ativado ou desativado.  O destino de cada comando de menu fornece essa informação implementando um manipulador de `ON_UPDATE_COMMAND_UI` .  Para cada um dos objetos de interface de usuário de comando em seu aplicativo, use a janela propriedades para criar um protótipo de entrada e a função de mapa mensagem\- para cada manipulador.  
  
 Para obter mais informações sobre como a interface de `ICommandUI` é usada no roteamento de comando, consulte [Como adicionar roteamento de comando ao controle dos Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).  
  
 Para obter mais informações sobre como usar formulários do windows, consulte [Usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
 Para obter mais informações sobre como os comandos de interface do usuário são gerenciados no MFC, consulte [Classe de CCmdUI](../Topic/CCmdUI%20Class.md).  
  
## Requisitos  
 **Cabeçalho:** afxwinforms.h \(definido no assembly atlmfc\\lib\\mfcmifc80.dll\)  
  
## Consulte também  
 [Classe de CCmdUI](../Topic/CCmdUI%20Class.md)