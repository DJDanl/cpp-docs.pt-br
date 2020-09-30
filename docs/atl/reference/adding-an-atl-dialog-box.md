---
title: Adicionando uma caixa de diálogo da ATL
ms.date: 11/04/2016
helpviewer_keywords:
- ATL projects, adding dialog resources
- MFC dialog boxes, ATL dialogs
- dialog boxes, ATL
ms.assetid: 152a378f-7b24-4f66-aeba-c740973f03a6
ms.openlocfilehash: 71290cf0763ac6594985acc4cb11562efe7028e6
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499365"
---
# <a name="adding-an-atl-dialog-box"></a>Adicionando uma caixa de diálogo da ATL

Para adicionar uma caixa de diálogo ATL ao seu projeto, seu projeto deve ser um projeto ATL ou um projeto MFC que inclua suporte à ATL. Você pode usar o [Assistente de projeto do ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao seu aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo MFC.

Por padrão, o assistente de diálogo ATL implementa uma caixa de diálogo derivada de [CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md). Essa classe inclui suporte para hospedagem de controles ActiveX e do Windows. Se você não quiser a sobrecarga do suporte ao controle ActiveX, depois que o assistente gerar seu código, substitua todas as instâncias de `CAxDialogImpl` por [CSimpleDialog](../../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../../atl/reference/cdialogimpl-class.md) como sua classe base.

> [!NOTE]
> `CSimpleDialog` cria somente caixas de diálogo modais que dão suporte apenas a controles comuns do Windows. `CDialogImpl` cria caixas de diálogo modais ou sem janela restrita.

## <a name="to-add-an-atl-dialog-resource-to-your-project"></a>Para adicionar um recurso de caixa de diálogo ATL ao seu projeto

1. Crie um projeto ATL usando o [Assistente de projeto ATL](../../atl/reference/atl-project-wizard.md).

1. Em [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome do projeto e clique em **Adicionar** no menu de atalho. Clique em **Adicionar Classe**.

1. No painel **modelos** da caixa de diálogo [Adicionar classe](../../ide/adding-a-class-visual-cpp.md#add-class-dialog-box) , clique em **diálogo ATL**. Clique em **abrir** para exibir o [Assistente de caixa de diálogo ATL](../../atl/reference/atl-dialog-wizard.md).

Para obter mais informações, consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md).

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Classes de janela](../../atl/atl-window-classes.md)<br/>
[Mapas de mensagens](../../atl/message-maps-atl.md)
