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
ms.openlocfilehash: 5deff0a50de813cc5faa43a86e591d3003a3c03e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50659622"
---
# <a name="activex-control-containers-handling-events-from-an-activex-control"></a>Contêineres de controle ActiveX: manipulando eventos a partir de um controle ActiveX

Este artigo aborda usando a janela Propriedades para instalar os manipuladores de eventos para controles ActiveX em um contêiner de controle ActiveX. Os manipuladores de eventos são usados para receber notificações (de controle) de determinados eventos e realizar alguma ação em resposta. Essa notificação é chamada de "disparo" do evento.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

> [!NOTE]
>  Este artigo usa um baseado em diálogo ActiveX contêiner projeto de controle de contêiner e um controle inserido chamado c como exemplos nos procedimentos e código de chamada.

Usando o botão de eventos na janela Propriedades, você pode criar um mapa de eventos que podem ocorrer em seu aplicativo de contêiner do controle ActiveX. Neste mapa, chamado de um "mapa de coletor de evento ', é criado e mantido pelo Visual C++ quando você adiciona manipuladores de eventos à classe de contêiner do controle. Cada manipulador de eventos, implementado com uma entrada de mapa de evento, mapeia um evento específico para uma função de membro de manipulador de eventos de contêiner. Essa função de manipulador de eventos é chamada quando o evento especificado é disparado pelo objeto de controle ActiveX.

Para obter mais informações sobre mapas de coleta de eventos, consulte [mapas de coleta de eventos](../mfc/reference/event-sink-maps.md) na *referência da biblioteca de classe*.

##  <a name="_core_event_handler_modifications_to_the_project"></a> Modificações de manipulador de eventos para o projeto

Quando você usa a janela Propriedades para adicionar manipuladores de eventos, um mapa coletor de evento é declarado e definido em seu projeto. As instruções a seguir são adicionadas ao controle. Arquivo CPP na primeira vez que um manipulador de eventos é adicionado. Esse código declara um mapa coletor de evento para a classe de caixa de diálogo (nesse caso, `CContainerDlg`):

[!code-cpp[NVC_MFC_AxCont#8](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_1.cpp)]
[!code-cpp[NVC_MFC_AxCont#9](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_2.cpp)]

Como você pode usar a janela Propriedades para adicionar eventos, um evento de entrada do mapa (`ON_EVENT`) é adicionado ao mapa de coletor de evento e um manipulador de eventos função será adicionada à implementação do contêiner (. Arquivo CPP).

O exemplo a seguir declara um manipulador de eventos, chamado `OnClickInCircCtrl`, para o controle de c `ClickIn` eventos:

[!code-cpp[NVC_MFC_AxCont#10](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_3.cpp)]

Além disso, o modelo a seguir é adicionado para o `CContainerDlg` implementação da classe (. Arquivo CPP) para a função de membro de manipulador de eventos:

[!code-cpp[NVC_MFC_AxCont#11](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_4.cpp)]

Para obter mais informações sobre as macros de coletor de eventos, consulte [mapas de coleta de eventos](../mfc/reference/event-sink-maps.md) na *referência da biblioteca de classe*.

#### <a name="to-create-an-event-handler-function"></a>Para criar uma função de manipulador de eventos

1. Na exibição de classe, selecione a classe de caixa de diálogo que contém o controle ActiveX. Para este exemplo, use `CContainerDlg`.

1. Na janela Propriedades, clique o **eventos** botão.

1. Na janela Propriedades, selecione a ID do controle do controle ActiveX incorporado. Para este exemplo, use `IDC_CIRCCTRL1`.

   A janela Propriedades exibe uma lista de eventos que podem ser acionados pelo controle ActiveX incorporado. Nenhuma função de membro mostrada em negrito já tem funções de manipulador atribuídas a ele.

1. Selecione o evento que você deseja que a classe de caixa de diálogo para manipular. Neste exemplo, selecione **clique em**.

1. Na caixa de lista suspensa à direita, selecione  **\<Adicionar > ClickCircctrl1**.

1. Clique duas vezes a nova função do manipulador da exibição de classe para saltar para o código de manipulador de eventos na implementação (. Arquivo CPP) de `CContainerDlg`.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

