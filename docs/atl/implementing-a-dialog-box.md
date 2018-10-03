---
title: Implementando uma caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CSimpleDialog class, implementing dialog boxes in ATL
- dialog boxes, ATL
- CAxDialogImpl class, implementing dialog boxes in ATL
- ATL, dialog boxes
ms.assetid: 478525f2-aa6a-435a-b162-68fc8aa98a8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 30e843c6df70548257de1bf1af8c5f0e83555652
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48234051"
---
# <a name="implementing-a-dialog-box"></a>Implementando uma caixa de diálogo

Há duas maneiras de adicionar uma caixa de diálogo ao seu projeto ATL: usar o Assistente de caixa de diálogo do ATL ou adicioná-lo manualmente.

## <a name="adding-a-dialog-box-with-the-atl-dialog-wizard"></a>Adicionando uma caixa de diálogo com o Assistente de caixa de diálogo do ATL

No [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md), selecione o objeto de caixa de diálogo do ATL para adicionar uma caixa de diálogo ao seu projeto ATL. Preencha o Assistente de caixa de diálogo do ATL conforme apropriado e clique em **concluir**. O assistente adiciona uma classe derivada de [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md) ao seu projeto. Abra **exibição de recurso** da **exibição** menu, localize a caixa de diálogo e clique duas vezes nele para abri-lo no editor de recursos.

> [!NOTE]
>  Se a caixa de diálogo é derivada de `CAxDialogImpl`, ele pode hospedar os dois ActiveX e controles do Windows. Se você não quiser a sobrecarga de suporte a controles ActiveX em sua classe de caixa de diálogo, use [CSimpleDialog](../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../atl/reference/cdialogimpl-class.md) em vez disso.

Manipuladores de eventos e de mensagem podem ser adicionados à sua classe de caixa de diálogo de exibição de classe. Para obter mais informações, consulte [adicionando um manipulador de mensagens do ATL](../atl/adding-an-atl-message-handler.md).

## <a name="adding-a-dialog-box-manually"></a>Adicionando uma caixa de diálogo manualmente

Implementar uma caixa de diálogo é semelhante à implementação de uma janela. Derive uma classe do [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md), [CDialogImpl](../atl/reference/cdialogimpl-class.md), ou [CSimpleDialog](../atl/reference/csimpledialog-class.md) e declarar um [mapa de mensagem](../atl/message-maps-atl.md) para lidar com mensagens. No entanto, você também deve especificar uma ID de recurso de modelo de caixa de diálogo em sua classe derivada. Sua classe deve ter um membro de dados chamado `IDD` para manter esse valor.

> [!NOTE]
>  Quando você cria uma caixa de diálogo usando o Assistente de caixa de diálogo do ATL, o assistente adicionará automaticamente o `IDD` membro como um **enum** tipo.

`CDialogImpl` permite que você implemente uma modal ou uma caixa de diálogo sem janela restrita que hospeda controles do Windows. `CAxDialogImpl` permite que você implemente uma modal ou uma caixa de diálogo sem janela restrita que hospeda controles ActiveX e Windows.

Para criar uma caixa de diálogo modal, crie uma instância do seu `CDialogImpl`-derivadas (ou `CAxDialogImpl`-derivado) de classe e, em seguida, chame o [DoModal](../atl/reference/cdialogimpl-class.md#domodal) método. Para fechar a caixa de diálogo modal, chame o [EndDialog](../atl/reference/cdialogimpl-class.md#enddialog) método de um manipulador de mensagens. Para criar uma caixa de diálogo sem janela restrita, chame o [Create](../atl/reference/cdialogimpl-class.md#create) método em vez de `DoModal`. Para destruir uma caixa de diálogo sem janela restrita, chame [DestroyWindow](../atl/reference/cdialogimpl-class.md#destroywindow).

Eventos de coletor é feito automaticamente no [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md). Implementar manipuladores de mensagens da caixa de diálogo, como você faria com os manipuladores em um `CWindowImpl`-classe derivada. Se houver um valor de retorno específicos à mensagem, retorná-la como um `LRESULT`. Retornado `LRESULT` valores são mapeados pelo ATL para manipulação adequada pelo Gerenciador de caixa de diálogo do Windows. Para obter detalhes, consulte o código-fonte [CDialogImplBaseT::DialogProc](../atl/reference/cdialogimpl-class.md#dialogproc) no atlwin.

## <a name="example"></a>Exemplo

A classe a seguir implementa uma caixa de diálogo:

[!code-cpp[NVC_ATL_Windowing#66](../atl/codesnippet/cpp/implementing-a-dialog-box_1.h)]

## <a name="see-also"></a>Consulte também

[Classes de janela](../atl/atl-window-classes.md)

