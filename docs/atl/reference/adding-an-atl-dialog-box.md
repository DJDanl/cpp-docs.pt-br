---
title: Adicionando uma caixa de diálogo do ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding dialog resources
- MFC dialog boxes, ATL dialogs
- dialog boxes, ATL
ms.assetid: 152a378f-7b24-4f66-aeba-c740973f03a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bd34cbcecdcf8943f8a02a2bb82c5c712f2cb16f
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43754716"
---
# <a name="adding-an-atl-dialog-box"></a>Adicionando uma caixa de diálogo do ATL

Para adicionar uma caixa de diálogo do ATL ao seu projeto, o projeto deve ser um projeto ATL ou um projeto MFC que inclui suporte ATL. Use o [Assistente de Projeto ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte à ATL para um aplicativo MFC.

Por padrão, o Assistente de caixa de diálogo do ATL implementa uma caixa de diálogo derivada [CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md). Essa classe inclui suporte para hospedagem de controles ActiveX e Windows. Se você não quiser que a sobrecarga de suporte a controles ActiveX, depois que o Assistente gerou seu código, substitua todas as instâncias do `CAxDialogImpl` com um [CSimpleDialog](../../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../../atl/reference/cdialogimpl-class.md) como sua classe base .

> [!NOTE]
>  `CSimpleDialog` cria apenas as caixas de diálogo modal que dão suporte a apenas os controles comuns do Windows. `CDialogImpl` cria qualquer caixas de diálogo modal ou sem janela restrita.

### <a name="to-add-an-atl-dialog-resource-to-your-project"></a>Para adicionar um recurso de caixa de diálogo do ATL ao seu projeto

1. Crie um projeto ATL usando o [ATL Project Wizard](../../atl/reference/atl-project-wizard.md).

2. Partir [Class View](/visualstudio/ide/viewing-the-structure-of-code), clique com botão direito no nome do projeto e clique em **Add** no menu de atalho. Clique em **Adicionar classe**.

3. No painel de modelos do [Add Class](../../ide/add-class-dialog-box.md) caixa de diálogo, clique em **caixa de diálogo do ATL**. Clique em **aberto** para exibir o [Assistente de caixa de diálogo do ATL](../../atl/reference/atl-dialog-wizard.md).

Para obter mais informações, consulte [implementar uma caixa de diálogo](../../atl/implementing-a-dialog-box.md).

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
[Classes de janela](../../atl/atl-window-classes.md)   
[Mapas de mensagem](../../atl/message-maps-atl.md)

