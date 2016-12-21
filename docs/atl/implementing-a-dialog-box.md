---
title: "Implementando uma caixa de di&#225;logo | Microsoft Docs"
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
  - "ATL, caixas de diálogo"
  - "Classe de CAxDialogImpl, implementando caixas de diálogo em ATL"
  - "Classe de CSimpleDialog, implementando caixas de diálogo em ATL"
  - "caixas de diálogo, ATL"
ms.assetid: 478525f2-aa6a-435a-b162-68fc8aa98a8e
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando uma caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há duas maneiras de adicionar uma caixa de diálogo para seu projeto de ATL: use o assistente da caixa de diálogo de ATL ou adicioná\-la manualmente.  
  
## Adicionando uma caixa de diálogo com o assistente da caixa de diálogo de ATL  
 Em [Adicione a caixa de diálogo de classe](../ide/add-class-dialog-box.md), selecione o objeto da caixa de diálogo de ATL para adicionar uma caixa de diálogo para seu projeto de ATL.  Preencha o assistente da caixa de diálogo de ATL como apropriado e clique em **Concluir**.  O assistente adiciona uma classe derivada de [CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md) ao seu projeto.  Abra o modo de recurso do menu de **Modo de Visualização** , localize a caixa de diálogo, clique duas vezes em para abri\-lo no editor de recursos.  
  
> [!NOTE]
>  Se a caixa de diálogo é derivada de `CAxDialogImpl`, ele pode hospedar controles ActiveX e do windows.  Se você não quiser a sobrecarga de suporte do controle ActiveX em sua classe da caixa de diálogo, use [CSimpleDialog](../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../Topic/CDialogImpl%20Class.md) em vez de isso.  
  
 A mensagem e manipuladores de eventos podem ser adicionados à sua classe da caixa de diálogo do modo da classe.  Para obter mais informações, consulte [adicionando um manipulador de mensagem de ATL](../atl/adding-an-atl-message-handler.md).  
  
## Adicionando uma caixa de diálogo manualmente  
 Implementar uma caixa de diálogo é semelhante ao implementar uma janela.  Você deriva de uma classe, [CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md)de [CDialogImpl](../Topic/CDialogImpl%20Class.md), ou de [CSimpleDialog](../atl/reference/csimpledialog-class.md) e declara [mapa de mensagem](../atl/message-maps-atl.md) mensagens de manipular.  Em o entanto, você também deve especificar uma identificação de recurso do modelo da caixa de diálogo em sua classe derivada.  A classe deve ter um membro de dados chamado `IDD` para armazenar esse valor.  
  
> [!NOTE]
>  Quando você cria uma caixa de diálogo usando o assistente da caixa de diálogo de ATL, o assistente adiciona automaticamente o membro de `IDD` como um tipo de `enum` .  
  
 `CDialogImpl` permite que você implemente uma caixa de diálogo modal ou sem\-modo que hospeda controles do windows.  `CAxDialogImpl` permite que você implemente uma caixa de diálogo modal ou sem\-modo que hospeda controles ActiveX e do windows.  
  
 Para criar uma caixa de diálogo modal, crie uma instância do `CDialogImpl`\- derivado \(ou `CAxDialogImpl`\-derivada\) da classe então chame o método de [DoModal](../Topic/CDialogImpl::DoModal.md).  Para fechar a caixa de diálogo modal, chame o método de [EndDialog](../Topic/CDialogImpl::EndDialog.md) de um manipulador de mensagem.  Para criar uma caixa de diálogo sem\-modo, chame o método de [Criar](../Topic/CDialogImpl::Create.md) em vez de `DoModal`.  Para destruir uma caixa de diálogo sem\-modo, chame [DestroyWindow](../Topic/CDialogImpl::DestroyWindow.md).  
  
 Afundar eventos é feito automaticamente em [CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md).  Implementar manipuladores de mensagem da caixa de diálogo como você os manipuladores em `CWindowImpl`\- classe derivada.  Se houver um valor de retorno mensagem\- específico, retorna como `LRESULT`.  Os valores retornados de `LRESULT` são mapeados por ATL para manipulação apropriada pelo gerenciador da caixa de diálogo do windows.  Para obter detalhes, consulte o código\-fonte para [CDialogImplBaseT::DialogProc](../Topic/CDialogImpl::DialogProc.md) em atlwin.h.  
  
## Exemplo  
 a seguinte classe implementa uma caixa de diálogo:  
  
 [!code-cpp[NVC_ATL_Windowing#66](../atl/codesnippet/CPP/implementing-a-dialog-box_1.h)]  
  
## Consulte também  
 [Classes de janela](../Topic/ATL%20Window%20Classes.md)