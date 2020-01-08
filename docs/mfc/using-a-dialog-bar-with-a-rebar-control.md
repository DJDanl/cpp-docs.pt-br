---
title: Usando uma caixa de diálogo com um controle rebar
ms.date: 11/04/2016
helpviewer_keywords:
- WS_EX_TRANSPARENT style
- rebar controls [MFC], dialog bars
- dialog bars [MFC], using with rebar bands
ms.assetid: e528cea0-6b81-4bdf-9643-7c03b6176590
ms.openlocfilehash: e4e786d3670ec74b734739e29aa7e3e33b5af384
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302361"
---
# <a name="using-a-dialog-bar-with-a-rebar-control"></a>Usando uma caixa de diálogo com um controle rebar

Conforme mencionado em [controles e bandas de rebar](../mfc/rebar-controls-and-bands.md), cada banda pode conter apenas uma janela filho (ou controle). Isso pode ser uma limitação se você quiser ter mais de uma janela filho por banda. Uma solução alternativa conveniente é criar um recurso da barra de diálogo com vários controles e, em seguida, adicionar uma faixa Rebar (contendo a barra de diálogo) ao controle rebar.

Normalmente, se você quisesse que a faixa da barra de diálogo aparecesse transparente, definiria o WS_EX_TRANSPARENT estilo estendido para o objeto da barra de diálogo. No entanto, como WS_EX_TRANSPARENT tem alguns problemas com a pintura adequada do plano de fundo de uma barra de diálogo, você precisará fazer um pouco de trabalho extra para obter o efeito desejado.

O procedimento a seguir detalha as etapas necessárias para obter transparência sem usar o WS_EX_TRANSPARENT estilo estendido.

### <a name="to-implement-a-transparent-dialog-bar-in-a-rebar-band"></a>Para implementar uma barra de diálogo transparente em uma faixa Rebar

1. Usando a [caixa de diálogo Adicionar classe](../mfc/reference/adding-an-mfc-class.md), adicione uma nova classe (por exemplo, `CMyDlgBar`) que implementa o objeto da barra de diálogo.

1. Adicione um manipulador para a mensagem de WM_ERASEBKGND.

1. No novo manipulador, modifique o código existente para corresponder ao exemplo a seguir:

   [!code-cpp[NVC_MFCControlLadenDialog#29](../mfc/codesnippet/cpp/using-a-dialog-bar-with-a-rebar-control_1.cpp)]

1. Adicione um manipulador para a mensagem de WM_MOVE.

1. No novo manipulador, modifique o código existente para corresponder ao exemplo a seguir:

   [!code-cpp[NVC_MFCControlLadenDialog#30](../mfc/codesnippet/cpp/using-a-dialog-bar-with-a-rebar-control_2.cpp)]

Os novos manipuladores simulam a transparência da barra de diálogo encaminhando a mensagem de WM_ERASEBKGND para a janela pai e forçando um redesenho toda vez que o objeto da barra de diálogo for movido.

## <a name="see-also"></a>Veja também

[Usando CReBarCtrl](../mfc/using-crebarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
