---
title: Criando o controle de tabulação
ms.date: 11/04/2016
f1_keywords:
- TCS_EX_REGISTERDROP
- TCS_EX_FLATSEPARATORS
helpviewer_keywords:
- TCS_EX_REGISTERDROP extended style [MFC]
- tab controls [MFC], creating
- CTabCtrl class [MFC], creating
- TCS_EX_FLATSEPARATORS extended style
ms.assetid: 3a9c2d64-f5f4-41ea-84ab-fceb73c3dbdc
ms.openlocfilehash: c444c938c88c2e8bf079f0f3eba80776c54af5ca
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50573401"
---
# <a name="creating-the-tab-control"></a>Criando o controle de tabulação

Como o controle de guia é criado depende se você estiver usando o controle em uma caixa de diálogo ou criá-lo em uma janela nondialog.

### <a name="to-use-ctabctrl-directly-in-a-dialog-box"></a>Usar CTabCtrl diretamente em uma caixa de diálogo

1. No editor de caixa de diálogo, adicione um controle guia até o recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Use o [Assistente para adição de variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CTabCtrl](../mfc/reference/ctabctrl-class.md) com a propriedade de controle. Você pode usar esse membro para chamar `CTabCtrl` funções de membro.

1. Mapear as funções de manipulador na classe de caixa de diálogo de quaisquer mensagens de notificação do controle guia que você precisa manipular. Para obter mais informações, consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).

1. Na [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), definir os estilos para o `CTabCtrl`.

### <a name="to-use-ctabctrl-in-a-nondialog-window"></a>Para usar CTabCtrl em uma janela de nondialog

1. Defina o controle na classe de janela ou exibição.

1. Chame o controle [Create](../mfc/reference/ctabctrl-class.md#create) função de membro, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente como antecipada como da janela pai [OnCreate](../mfc/reference/cwnd-class.md#oncreate) função do manipulador (se você estiver Criando subclasses de controle). Defina os estilos para o controle.

Após o `CTabCtrl` objeto tiver sido criado, você pode definir ou limpar os seguintes estilos estendidos:

- **TCS_EX_FLATSEPARATORS** o controle de guia desenhará separadores entre itens de guia. Esse estilo estendido somente afeta guia controles que têm o **TCS_BUTTONS** e **TCS_FLATBUTTONS** estilos. Por padrão, criando o controle de guia com o **TCS_FLATBUTTONS** estilo define esse estilo estendido.

- **TCS_EX_REGISTERDROP** o controle de guia gera **TCN_GETOBJECT** mensagens de notificação para solicitar um destino de soltar quando um objeto é arrastado sobre os itens de guia no controle do objeto.

    > [!NOTE]
    >  Para receber os **TCN_GETOBJECT** notificação, você deve inicializar as bibliotecas OLE com uma chamada para [AfxOleInit](../mfc/reference/ole-initialization.md#afxoleinit).

Esses estilos podem ser recuperados e definir, depois que o controle tiver sido criado, com as respectivas chamadas para o [GetExtendedStyle](../mfc/reference/ctabctrl-class.md#getextendedstyle) e [SetExtendedStyle](../mfc/reference/ctabctrl-class.md#setextendedstyle) funções de membro.

Por exemplo, defina as **TCS_EX_FLATSEPARATORS** estilo com as seguintes linhas de código:

[!code-cpp[NVC_MFCControlLadenDialog#33](../mfc/codesnippet/cpp/creating-the-tab-control_1.cpp)]

Desmarque a **TCS_EX_FLATSEPARATORS** de estilo de um `CTabCtrl` objeto com as seguintes linhas de código:

[!code-cpp[NVC_MFCControlLadenDialog#34](../mfc/codesnippet/cpp/creating-the-tab-control_2.cpp)]

Isso removerá os separadores que aparecem entre os botões de seu `CTabCtrl` objeto.

## <a name="see-also"></a>Consulte também

[Usando CTabCtrl](../mfc/using-ctabctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

