---
title: "Adicionar uma caixa de diálogo do ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding dialog resources
- MFC dialog boxes, ATL dialogs
- dialog boxes, ATL
ms.assetid: 152a378f-7b24-4f66-aeba-c740973f03a6
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d8c9969f4747c6c3fa2a39b7b0452f6ac54c9d58
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-an-atl-dialog-box"></a>Adicionar uma caixa de diálogo do ATL
Para adicionar uma caixa de diálogo ATL ao seu projeto, o projeto deve ser um projeto de ATL ou um projeto MFC que inclui suporte ATL. Você pode usar o [Assistente de projeto de ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL, ou [adicionar um objeto ATL ao seu aplicativo do MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo do MFC.  
  
 Por padrão, o Assistente de caixa de diálogo do ATL implementa uma caixa de diálogo derivada [CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md). Essa classe inclui suporte para hospedagem de controles ActiveX e Windows. Se você não quiser que a sobrecarga de suporte de controle ActiveX, depois que o Assistente gerou seu código, substitua todas as instâncias de `CAxDialogImpl` com um [CSimpleDialog](../../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../../atl/reference/cdialogimpl-class.md) como sua classe base .  
  
> [!NOTE]
>  `CSimpleDialog`cria somente as caixas de diálogo modal que oferecem suporte a somente os controles comuns do Windows. `CDialogImpl`cria ou caixas de diálogo modal ou sem janela restrita.  
  
### <a name="to-add-an-atl-dialog-resource-to-your-project"></a>Para adicionar um recurso de caixa de diálogo ATL ao seu projeto  
  
1.  Crie um projeto ATL usando o [Assistente de projeto de ATL](../../atl/reference/atl-project-wizard.md).  
  
2.  De [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome do projeto e clique em **adicionar** no menu de atalho. Clique em **Adicionar classe**.  
  
3.  No painel modelos do [Adicionar classe](../../ide/add-class-dialog-box.md) caixa de diálogo, clique em **ATL diálogo**. Clique em **abrir** para exibir o [ATL caixa de diálogo Assistente](../../atl/reference/atl-dialog-wizard.md).  
  
 Para obter mais informações, consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md).  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Classes de janela](../../atl/atl-window-classes.md)   
 [Mapas de mensagem](../../atl/message-maps-atl.md)

