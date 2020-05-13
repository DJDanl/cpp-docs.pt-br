---
title: 'Contêineres de controle ActiveX: manipulando eventos a partir de um controle ActiveX'
ms.date: 09/12/2018
helpviewer_keywords:
- event handlers [MFC], ActiveX controls
- ActiveX control containers [MFC], event sinks
- event handling [MFC], ActiveX controls
- ON_EVENT macro [MFC]
- ActiveX controls [MFC], events [MFC]
- END_EVENTSINK_MAP macro, using
- events [MFC], ActiveX controls
- BEGIN_EVENTSINK_MAP macro
ms.assetid: f9c106db-052f-4e32-82ad-750646aa760b
ms.openlocfilehash: ae623ee0973e78db3b542646dd6bdec58cc2dfc8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367948"
---
# <a name="activex-control-containers-handling-events-from-an-activex-control"></a>Contêineres de controle ActiveX: manipulando eventos a partir de um controle ActiveX

Este artigo discute o uso da janela **Propriedades** (em **Class View)** para instalar manipuladores de eventos para controles ActiveX em um contêiner de controle ActiveX. Os manipuladores de eventos são usados para receber notificações (do controle) de determinados eventos e realizar alguma ação em resposta. Esta notificação é chamada de "disparo" do evento.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

> [!NOTE]
> Este artigo usa um projeto de contêiner de controle ActiveX baseado em diálogo chamado Container e um controle incorporado chamado Circ como exemplos nos procedimentos e código.

Usando o botão Eventos na janela **Propriedades** (em **Exibição de**classe), você pode criar um mapa de eventos que podem ocorrer no aplicativo de contêiner de controle ActiveX. Este mapa, chamado de "mapa do dissipador de eventos", é criado e mantido pelo Visual C++ quando você adiciona manipuladores de eventos à classe de contêiner de controle. Cada manipulador de eventos, implementado com uma entrada no mapa do evento, mapeia um evento específico para uma função de membro manipulador de eventos de contêiner. Essa função de manipulador de eventos é chamada quando o evento especificado é acionado pelo objeto de controle ActiveX.

Para obter mais informações sobre mapas de soantes de eventos, consulte [Mapas de dissipação de eventos](../mfc/reference/event-sink-maps.md) na referência da biblioteca de *classes*.

## <a name="event-handler-modifications-to-the-project"></a><a name="_core_event_handler_modifications_to_the_project"></a>Modificações do manipulador de eventos para o projeto

Quando você usa a janela **Propriedades** para adicionar manipuladores de eventos, um mapa do dissipador de eventos é declarado e definido em seu projeto. As seguintes instruções são adicionadas ao controle . Arquivo CPP na primeira vez que um manipulador de eventos é adicionado. Este código declara um mapa de sumidouro `CContainerDlg`de eventos para a classe caixa de diálogo (neste caso, ):

[!code-cpp[NVC_MFC_AxCont#8](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_1.cpp)]
[!code-cpp[NVC_MFC_AxCont#9](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_2.cpp)]

À medida **Properties** que você usa a janela Propriedades`ON_EVENT`para adicionar eventos, uma entrada de mapa de eventos ( ) é adicionada ao mapa do dissipador de eventos e uma função de manipulador de eventos é adicionada à implementação do contêiner (. CPP) arquivo.

O exemplo a seguir declara `OnClickInCircCtrl`um manipulador de eventos, `ClickIn` chamado , para o evento do controle Circ:

[!code-cpp[NVC_MFC_AxCont#10](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_3.cpp)]

Além disso, o modelo a `CContainerDlg` seguir é adicionado à implementação da classe (. Arquivo CPP) para a função de membro do manipulador de eventos:

[!code-cpp[NVC_MFC_AxCont#11](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_4.cpp)]

Para obter mais informações sobre macros de soantes de eventos, consulte [Mapas de sink de eventos](../mfc/reference/event-sink-maps.md) na referência da biblioteca de *classes*.

#### <a name="to-create-an-event-handler-function"></a>Para criar uma função de manipulador de eventos

1. Em Exibição de classe, selecione a classe de diálogo que contém o controle ActiveX. Para este exemplo, use `CContainerDlg`.

1. Na janela **Propriedades**, clique no botão **Eventos**.

1. Na janela **Propriedades,** selecione o ID de controle do controle ActiveX incorporado. Para este exemplo, use `IDC_CIRCCTRL1`.

   A janela **Propriedades** exibe uma lista de eventos que podem ser disparados pelo controle ActiveX incorporado. Qualquer função de membro mostrada em negrito já tem funções de manipulador atribuídas a ela.

1. Selecione o evento que deseja que a classe de diálogo seja tratada. Para este exemplo, selecione **Clique**.

1. Na caixa de lista baixa à direita, ** \<selecione Adicionar> ClickCirccl1**.

1. Clique duas vezes na nova função de manipulador do Class View para saltar para o código do manipulador de eventos na implementação (. CPP) arquivo `CContainerDlg`de .

## <a name="see-also"></a>Confira também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)
