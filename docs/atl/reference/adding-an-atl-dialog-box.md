---
title: "Adicionando uma caixa de diálogo do ATL | Documentos do Microsoft"
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
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b89df346937ea93abdec4cefbfe7826cfeb9e2d7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="adding-an-atl-dialog-box"></a>Adicionando uma caixa de diálogo do ATL
Para adicionar uma caixa de diálogo do ATL ao seu projeto, o projeto deve ser um projeto ATL ou um projeto que inclui suporte ATL. Você pode usar o [ATL Project Wizard](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL, ou [adicionar um objeto ATL ao seu aplicativo do MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte do ATL para um aplicativo MFC.  
  
 Por padrão, o Assistente de caixa de diálogo do ATL implementa uma caixa de diálogo derivada de [CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md). Essa classe inclui suporte para hospedar controles ActiveX e Windows. Se você não quer a sobrecarga de suporte a controles ActiveX, depois que o Assistente gerou seu código, substitua todas as instâncias de `CAxDialogImpl` com um [CSimpleDialog](../../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../../atl/reference/cdialogimpl-class.md) como sua classe base.  
  
> [!NOTE]
>  `CSimpleDialog`cria apenas as caixas de diálogo modais que oferecem suporte a somente os controles comuns do Windows. `CDialogImpl`cria qualquer caixas de diálogo modal ou sem janela restrita.  
  
### <a name="to-add-an-atl-dialog-resource-to-your-project"></a>Para adicionar um recurso de caixa de diálogo do ATL ao seu projeto  
  
1.  Crie um projeto ATL usando o [ATL Project Wizard](../../atl/reference/atl-project-wizard.md).  
  
2.  De [Class View](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome do projeto e clique em **adicionar** no menu de atalho. Clique em **Adicionar classe**.  
  
3.  No painel de modelos do [Add Class](../../ide/add-class-dialog-box.md) caixa de diálogo, clique em **ATL diálogo**. Clique em **abrir** para exibir o [caixa de diálogo Assistente da ATL](../../atl/reference/atl-dialog-wizard.md).  
  
 Para obter mais informações, consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md).  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Classes de janela](../../atl/atl-window-classes.md)   
 [Mapas de mensagem](../../atl/message-maps-atl.md)


