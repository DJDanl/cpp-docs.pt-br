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
ms.openlocfilehash: 6d5aa6873966ecb4c845f1c503b24c07b6c0c7a3
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619614"
---
# <a name="creating-the-tab-control"></a>Criando o controle de tabulação

A forma como o controle de guia é criado depende se você está usando o controle em uma caixa de diálogo ou criando-o em uma janela que não seja de caixa de diálogo.

### <a name="to-use-ctabctrl-directly-in-a-dialog-box"></a>Para usar o CTabCtrl diretamente em uma caixa de diálogo

1. No editor de caixa de diálogo, adicione um controle guia ao recurso de modelo de caixa de diálogo. Especifique sua ID de controle.

1. Use o [Assistente para Adicionar variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro do tipo [CTabCtrl](reference/ctabctrl-class.md) com a propriedade Control. Você pode usar esse membro para chamar `CTabCtrl` funções de membro.

1. Funções de manipulador de mapa na classe de caixa de diálogo para qualquer mensagem de notificação de controle de guia que você precisa manipular. Para obter mais informações, consulte [mapeando mensagens para funções](reference/mapping-messages-to-functions.md).

1. Em [OnInitDialog](reference/cdialog-class.md#oninitdialog), defina os estilos para o `CTabCtrl` .

### <a name="to-use-ctabctrl-in-a-nondialog-window"></a>Para usar o CTabCtrl em uma janela sem caixa de diálogo

1. Defina o controle na classe View ou Window.

1. Chame a função de membro [Create](reference/ctabctrl-class.md#create) do controle, possivelmente em [OnInitialUpdate](reference/cview-class.md#oninitialupdate), possivelmente no início da função do manipulador [OnCreate](reference/cwnd-class.md#oncreate) da janela pai (se você estiver subclassendo o controle). Defina os estilos do controle.

Depois `CTabCtrl` que o objeto tiver sido criado, você poderá definir ou limpar os seguintes estilos estendidos:

- **TCS_EX_FLATSEPARATORS** O controle guia desenhará separadores entre os itens da guia. Esse estilo estendido só afeta os controles de guia que têm os estilos de **TCS_BUTTONS** e **TCS_FLATBUTTONS** . Por padrão, a criação do controle guia com o estilo **TCS_FLATBUTTONS** define esse estilo estendido.

- **TCS_EX_REGISTERDROP** O controle guia gera **TCN_GETOBJECT** mensagens de notificação para solicitar um objeto de destino drop quando um objeto é arrastado sobre os itens da guia no controle.

    > [!NOTE]
    >  Para receber a notificação de **TCN_GETOBJECT** , você deve inicializar as bibliotecas OLE com uma chamada para [AfxOleInit](reference/ole-initialization.md#afxoleinit).

Esses estilos podem ser recuperados e definidos, depois que o controle tiver sido criado, com as respectivas chamadas para as funções de membro [Extended](reference/ctabctrl-class.md#getextendedstyle) e [Extended](reference/ctabctrl-class.md#setextendedstyle) .

Por exemplo, defina o estilo de **TCS_EX_FLATSEPARATORS** com as seguintes linhas de código:

[!code-cpp[NVC_MFCControlLadenDialog#33](codesnippet/cpp/creating-the-tab-control_1.cpp)]

Limpe o estilo de **TCS_EX_FLATSEPARATORS** de um `CTabCtrl` objeto com as seguintes linhas de código:

[!code-cpp[NVC_MFCControlLadenDialog#34](codesnippet/cpp/creating-the-tab-control_2.cpp)]

Isso removerá os separadores que aparecem entre os botões do seu `CTabCtrl` objeto.

## <a name="see-also"></a>Consulte também

[Usando CTabCtrl](using-ctabctrl.md)<br/>
[Controles](controls-mfc.md)
