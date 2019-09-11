---
title: 'Contêineres de controle ActiveX: Manipulando eventos de um controle ActiveX'
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
ms.openlocfilehash: 7487792fbc9fe6775640f40755a7f725543fb9f3
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907766"
---
# <a name="activex-control-containers-handling-events-from-an-activex-control"></a>Contêineres de controle ActiveX: Manipulando eventos de um controle ActiveX

Este artigo aborda o uso da janela **Propriedades** (em **modo de exibição de classe**) para instalar manipuladores de eventos para controles ActiveX em um contêiner de controle ActiveX. Os manipuladores de eventos são usados para receber notificações (do controle) de determinados eventos e executar alguma ação em resposta. Essa notificação é chamada de "acionamento" do evento.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

> [!NOTE]
>  Este artigo usa um projeto de contêiner de controle ActiveX baseado em caixa de diálogo chamado contêiner e um controle inserido chamado CIRC como exemplos nos procedimentos e no código.

Usando o botão eventos na janela **Propriedades** (em **modo de exibição de classe**), você pode criar um mapa de eventos que podem ocorrer em seu aplicativo de contêiner de controle ActiveX. Esse mapa, chamado de "mapa do coletor de eventos," "é criado e mantido C++ pelo Visual quando você adiciona manipuladores de eventos à classe de contêiner de controle. Cada manipulador de eventos, implementado com uma entrada de mapa de eventos, mapeia um evento específico para uma função de membro de manipulador de eventos de contêiner. Essa função do manipulador de eventos é chamada quando o evento especificado é acionado pelo objeto de controle ActiveX.

Para obter mais informações sobre mapas do coletor de eventos, consulte [mapas do coletor de eventos](../mfc/reference/event-sink-maps.md) na referência da biblioteca de *classes*.

##  <a name="_core_event_handler_modifications_to_the_project"></a>Modificações no manipulador de eventos para o projeto

Quando você usa a janela **Propriedades** para adicionar manipuladores de eventos, um mapa de coletor de eventos é declarado e definido em seu projeto. As instruções a seguir são adicionadas ao controle. Arquivo CPP na primeira vez que um manipulador de eventos é adicionado. Esse código declara um mapa de coletor de eventos para a classe da caixa de diálogo (neste `CContainerDlg`caso,):

[!code-cpp[NVC_MFC_AxCont#8](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_1.cpp)]
[!code-cpp[NVC_MFC_AxCont#9](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_2.cpp)]

Conforme você usa a janela **Propriedades** para adicionar eventos, uma entrada de mapa de`ON_EVENT`eventos () é adicionada ao mapa do coletor de eventos e uma função de manipulador de eventos é adicionada à implementação do contêiner (. CPP).

O exemplo a seguir declara um manipulador de eventos, `OnClickInCircCtrl`chamado, para o evento do `ClickIn` controle Circ:

[!code-cpp[NVC_MFC_AxCont#10](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_3.cpp)]

Além disso, o modelo a seguir é adicionado à `CContainerDlg` implementação da classe (. CPP) para a função de membro do manipulador de eventos:

[!code-cpp[NVC_MFC_AxCont#11](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_4.cpp)]

Para obter mais informações sobre macros do coletor de eventos, consulte [mapas do coletor de eventos](../mfc/reference/event-sink-maps.md) na referência da biblioteca de *classes*.

#### <a name="to-create-an-event-handler-function"></a>Para criar uma função de manipulador de eventos

1. Em Modo de Exibição de Classe, selecione a classe de caixa de diálogo que contém o controle ActiveX. Para este exemplo, use `CContainerDlg`.

1. Na janela **Propriedades**, clique no botão **Eventos**.

1. Na janela **Propriedades** , selecione a ID de controle do controle ActiveX inserido. Para este exemplo, use `IDC_CIRCCTRL1`.

   A janela **Propriedades** exibe uma lista de eventos que podem ser acionados pelo controle ActiveX incorporado. Qualquer função de membro mostrada em negrito já tem funções de manipulador atribuídas a ele.

1. Selecione o evento que você deseja que a classe de caixa de diálogo manipule. Para este exemplo, selecione **clique**.

1. Na caixa de listagem suspensa à direita, selecione  **\<Adicionar > ClickCircctrl1**.

1. Clique duas vezes na nova função de manipulador de Modo de Exibição de Classe para saltar para o código do manipulador de eventos na implementação (. CPP) de `CContainerDlg`.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)
