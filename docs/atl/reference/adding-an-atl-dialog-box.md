---
title: "Adicionando uma caixa de di&#225;logo de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Projetos de ATL, adicionando recursos da caixa de diálogo"
  - "caixas de diálogo, ATL"
  - "Caixas de diálogo MFC, Caixas de diálogo de ATL"
ms.assetid: 152a378f-7b24-4f66-aeba-c740973f03a6
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando uma caixa de di&#225;logo de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para adicionar uma caixa de diálogo de ATL ao seu projeto, seu projeto deve ser um projeto de ATL ou um projeto MFC que inclui suporte de ATL.  Você pode usar [Assistente de projeto de ATL](../Topic/ATL%20Project%20Wizard.md) para criar um aplicativo de ATL, ou [adicionar um objeto de ATL ao seu aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) implementar o suporte de ATL para um aplicativo MFC.  
  
 Por padrão, o assistente da caixa de diálogo de ATL implementa uma caixa de diálogo derivada de [CAxDialogImpl](../Topic/CAxDialogImpl%20Class.md).  Essa classe inclui suporte para hospedar controles ActiveX e do windows.  Se você não quiser a sobrecarga de suporte do controle ActiveX, uma vez que gerou o assistente seu código, substitua todas as instâncias de `CAxDialogImpl` com [CSimpleDialog](../../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../Topic/CDialogImpl%20Class.md) como sua classe base.  
  
> [!NOTE]
>  `CSimpleDialog` cria apenas caixas de diálogo modais que suportam apenas controles comuns.  `CDialogImpl` criar caixas de diálogo modais ou sem janela restrita.  
  
### Para adicionar um recurso da caixa de diálogo de ATL ao seu projeto  
  
1.  Crie um projeto de ATL usando [Assistente de projeto de ATL](../Topic/ATL%20Project%20Wizard.md).  
  
2.  De [Modo de Exibição de Classe](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique com o botão direito do mouse no nome do projeto e clique em **Adicionar** do menu de atalho.  Clique **Adicionar Classe**.  
  
3.  Em o painel de modelos da caixa de diálogo de [Adicionar Classe](../../ide/add-class-dialog-box.md) , clique **Caixa de Diálogo do ATL**.  Clique **Abrir** para exibir [Assistente da caixa de diálogo de ATL](../../atl/reference/atl-dialog-wizard.md).  
  
 Para obter mais informações, consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md).  
  
## Consulte também  
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Classes de janela](../Topic/ATL%20Window%20Classes.md)   
 [Mapas de mensagem](../../atl/message-maps-atl.md)