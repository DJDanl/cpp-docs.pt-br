---
title: Implementando uma caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- CSimpleDialog class, implementing dialog boxes in ATL
- dialog boxes, ATL
- CAxDialogImpl class, implementing dialog boxes in ATL
- ATL, dialog boxes
ms.assetid: 478525f2-aa6a-435a-b162-68fc8aa98a8e
ms.openlocfilehash: fa7b4122b513d48194dedeb39daecd1dfd7223eb
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499576"
---
# <a name="implementing-a-dialog-box"></a>Implementando uma caixa de diálogo

Há duas maneiras de adicionar uma caixa de diálogo ao seu projeto ATL: Use o assistente de caixa de diálogo ATL ou adicione-a manualmente.

## <a name="adding-a-dialog-box-with-the-atl-dialog-wizard"></a>Adicionando uma caixa de diálogo com o assistente de caixa de diálogo ATL

Na [caixa de diálogo Adicionar classe](../ide/adding-a-class-visual-cpp.md#add-class-dialog-box), selecione o objeto de diálogo ATL para adicionar uma caixa de diálogo ao seu projeto ATL. Preencha o assistente de caixa de diálogo do ATL conforme apropriado e clique em **concluir**. O assistente adiciona uma classe derivada de [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md) ao seu projeto. Abra **modo de exibição de recursos** no menu **Exibir** , localize a caixa de diálogo e clique duas vezes nela para abri-la no editor de recursos.

> [!NOTE]
> Se a caixa de diálogo for derivada de `CAxDialogImpl` , ela poderá hospedar controles ActiveX e do Windows. Se você não quiser a sobrecarga do suporte de controle ActiveX na sua classe de caixa de diálogo, use [CSimpleDialog](../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../atl/reference/cdialogimpl-class.md) em vez disso.

Os manipuladores de mensagens e eventos podem ser adicionados à sua classe de caixa de diálogo de Modo de Exibição de Classe. Para obter mais informações, consulte [adicionando um manipulador de mensagens ATL](../atl/adding-an-atl-message-handler.md).

## <a name="adding-a-dialog-box-manually"></a>Adicionar uma caixa de diálogo manualmente

A implementação de uma caixa de diálogo é semelhante à implementação de uma janela. Você deriva uma classe de [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md), [CDialogImpl](../atl/reference/cdialogimpl-class.md)ou [CSimpleDialog](../atl/reference/csimpledialog-class.md) e declara um mapa de [mensagens](../atl/message-maps-atl.md) para tratar mensagens. No entanto, você também deve especificar uma ID de recurso de modelo de caixa de diálogo em sua classe derivada. Sua classe deve ter um membro de dados chamado `IDD` para manter esse valor.

> [!NOTE]
> Quando você cria uma caixa de diálogo usando o assistente de caixa de diálogo ATL, o assistente adiciona automaticamente o `IDD` membro como um **`enum`** tipo.

`CDialogImpl` permite que você implemente uma caixa de diálogo modal ou sem janela restrita que hospeda controles do Windows. `CAxDialogImpl` permite que você implemente uma caixa de diálogo modal ou sem janela restrita que hospede controles ActiveX e do Windows.

Para criar uma caixa de diálogo modal, crie uma instância da `CDialogImpl` classe-derivada (ou `CAxDialogImpl` derivada) e, em seguida, chame o método [DoModal](../atl/reference/cdialogimpl-class.md#domodal) . Para fechar uma caixa de diálogo modal, chame o método [EndDialog](../atl/reference/cdialogimpl-class.md#enddialog) de um manipulador de mensagens. Para criar uma caixa de diálogo sem janela restrita, chame o método [Create](../atl/reference/cdialogimpl-class.md#create) em vez de `DoModal` . Para destruir uma caixa de diálogo sem janela restrita, chame [DestroyWindow](../atl/reference/cdialogimpl-class.md#destroywindow).

Eventos de coletor são feitos automaticamente no [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md). Implemente os manipuladores de mensagens da caixa de diálogo como você faria com os manipuladores em uma `CWindowImpl` classe derivada. Se houver um valor de retorno específico da mensagem, retorne-o como um `LRESULT` . Os `LRESULT` valores retornados são mapeados pela ATL para tratamento adequado pelo Gerenciador de caixas de diálogo do Windows. Para obter detalhes, consulte o código-fonte para [CDialogImplBaseT::D ialogproc](../atl/reference/cdialogimpl-class.md#dialogproc) em atlwin. h.

## <a name="example"></a>Exemplo

A seguinte classe implementa uma caixa de diálogo:

[!code-cpp[NVC_ATL_Windowing#66](../atl/codesnippet/cpp/implementing-a-dialog-box_1.h)]

## <a name="see-also"></a>Consulte também

[Classes de janela](../atl/atl-window-classes.md)
