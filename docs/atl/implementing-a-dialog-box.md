---
title: Implementando uma caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- CSimpleDialog class, implementing dialog boxes in ATL
- dialog boxes, ATL
- CAxDialogImpl class, implementing dialog boxes in ATL
- ATL, dialog boxes
ms.assetid: 478525f2-aa6a-435a-b162-68fc8aa98a8e
ms.openlocfilehash: 435926b0a0affde03580ceb2b479cb08a17d0454
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319483"
---
# <a name="implementing-a-dialog-box"></a>Implementando uma caixa de diálogo

Existem duas maneiras de adicionar uma caixa de diálogo ao seu projeto ATL: use o Assistente de Diálogo ATL ou adicione-o manualmente.

## <a name="adding-a-dialog-box-with-the-atl-dialog-wizard"></a>Adicionando uma caixa de diálogo com o assistente de diálogo ATL

Na [caixa de diálogo Adicionar classe,](../ide/add-class-dialog-box.md)selecione o objeto diálogo ATL para adicionar uma caixa de diálogo ao projeto ATL. Preencha o assistente de diálogo ATL conforme apropriado e clique **em Concluir**. O assistente adiciona uma classe derivada de [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md) ao seu projeto. Abrir **recurso exibir** no menu **Exibir,** localizar sua caixa de diálogo e clicar duas vezes nele para abri-la no editor de recursos.

> [!NOTE]
> Se a caixa de `CAxDialogImpl`diálogo for derivada, ela poderá hospedar controles ActiveX e Windows. Se você não quiser a sobrecarga do suporte ao controle ActiveX na sua classe caixa de diálogo, use [CSimpleDialog](../atl/reference/csimpledialog-class.md) ou [CDialogImpl.](../atl/reference/cdialogimpl-class.md)

Os manipuladores de mensagens e eventos podem ser adicionados à sua classe de diálogo a partir do Class View. Para obter mais informações, consulte [Adicionando um manipulador de mensagens ATL](../atl/adding-an-atl-message-handler.md).

## <a name="adding-a-dialog-box-manually"></a>Adicionando uma caixa de diálogo manualmente

A implementação de uma caixa de diálogo é semelhante à implementação de uma janela. Você obtém uma classe de [CAxDialogImpl,](../atl/reference/caxdialogimpl-class.md) [CDialogImpl](../atl/reference/cdialogimpl-class.md)ou [CSimpleDialog](../atl/reference/csimpledialog-class.md) e declara um mapa de [mensagens](../atl/message-maps-atl.md) para lidar com mensagens. No entanto, você também deve especificar um ID de recurso de modelo de diálogo em sua classe derivada. Sua classe deve ter `IDD` um membro de dados chamado para manter esse valor.

> [!NOTE]
> Quando você cria uma caixa de diálogo usando o assistente `IDD` de diálogo ATL, o assistente adiciona automaticamente o membro como um tipo **de enum.**

`CDialogImpl`permite que você implemente um modal ou uma caixa de diálogo modelada que hospeda controles do Windows. `CAxDialogImpl`permite que você implemente um modal ou uma caixa de diálogo modelada que hospeda controles ActiveX e Windows.

Para criar uma caixa de diálogo modal, crie uma instância da sua `CDialogImpl`classe derivada (ou `CAxDialogImpl`derivada) e, em seguida, chame o método [DoModal.](../atl/reference/cdialogimpl-class.md#domodal) Para fechar uma caixa de diálogo modal, ligue para o método [EndDialog](../atl/reference/cdialogimpl-class.md#enddialog) de um manipulador de mensagens. Para criar uma caixa de diálogo modeless, chame o método [Criar](../atl/reference/cdialogimpl-class.md#create) em vez de `DoModal`. Para destruir uma caixa de diálogo modeless, chame [DestroyWindow](../atl/reference/cdialogimpl-class.md#destroywindow).

Eventos de naufrágio são feitos automaticamente em [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md). Implemente os manipuladores de mensagens da caixa `CWindowImpl`de diálogo como os manipuladores em uma classe derivada. Se houver um valor de retorno específico `LRESULT`da mensagem, devolva-o como um . Os valores retornados `LRESULT` são mapeados pela ATL para o manuseio adequado pelo gerenciador de diálogos do Windows. Para obter detalhes, consulte o código-fonte de [CDialogImplBaseT::DialogProc](../atl/reference/cdialogimpl-class.md#dialogproc) em atlwin.h.

## <a name="example"></a>Exemplo

A classe a seguir implementa uma caixa de diálogo:

[!code-cpp[NVC_ATL_Windowing#66](../atl/codesnippet/cpp/implementing-a-dialog-box_1.h)]

## <a name="see-also"></a>Confira também

[Aulas de janela](../atl/atl-window-classes.md)
