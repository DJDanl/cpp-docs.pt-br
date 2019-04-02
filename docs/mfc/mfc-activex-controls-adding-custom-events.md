---
title: 'Controles ActiveX MFC: Adicionando eventos personalizados'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], events [MFC]
- EVENT_CUSTOM prefix [MFC]
- custom events [MFC], adding to ActiveX controls
- EVENT_CUSTOM macro [MFC]
- InCircle method [MFC]
- ClickIn event
- FireClickIn event
- COleControl class [MFC], custom events [MFC]
- Click event, custom events [MFC]
- events [MFC], ActiveX controls
- custom events [MFC]
- FireEvent method, adding custom events
ms.assetid: c584d053-1e34-47aa-958e-37d3e9b85892
ms.openlocfilehash: 48c5ddbc8a3bcf6f74c251820e83cdebcef05bc9
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58780997"
---
# <a name="mfc-activex-controls-adding-custom-events"></a>Controles ActiveX MFC: Adicionando eventos personalizados

Eventos personalizados são diferentes de eventos de estoque não serão acionados automaticamente pela classe `COleControl`. Um evento personalizado reconhece uma determinada ação, determinada pelo desenvolvedor do controle, como um evento. As entradas de mapa de evento para eventos personalizados são representadas pela macro EVENT_CUSTOM. A seção a seguir implementa um evento personalizado para um projeto do controle ActiveX que foi criado usando o Assistente de controle ActiveX.

##  <a name="_core_adding_a_custom_event_with_classwizard"></a> Adicionando um evento personalizado com o Assistente de eventos para adicionar

O procedimento a seguir adiciona um evento personalizado específico, ClickIn. Você pode usar este procedimento para adicionar outros eventos personalizados. Substitua o nome do evento personalizado e seus parâmetros para os parâmetros e o nome do evento ClickIn.

#### <a name="to-add-the-clickin-custom-event-using-the-add-event-wizard"></a>Para adicionar o evento personalizado do ClickIn usando o Assistente para adicionar evento

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, clique com botão direito sua classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique em **Add** e, em seguida, clique em **Adicionar evento**.

   Isso abre o Assistente para adicionar eventos.

1. No **nome do evento** caixa, primeiro selecione qualquer evento existente, clique no **personalizado** radio botão e, em seguida, digite *ClickIn*.

1. No **nome interno** , digite o nome da função de acionamento do evento. Para este exemplo, use o valor padrão fornecido pelo Assistente de adição de eventos (`FireClickIn`).

1. Adicione um parâmetro chamado *xCoord* (tipo *OLE_XPOS_PIXELS*), usando o **nome do parâmetro** e **tipo de parâmetro** controles.

1. Adicionar um segundo parâmetro, chamado *yCoord* (tipo *OLE_YPOS_PIXELS*).

1. Clique em **concluir** para criar o evento.

##  <a name="_core_classwizard_changes_for_custom_events"></a> Adicionar Assistente altera o evento para eventos personalizados

Quando você adiciona um evento personalizado, o Assistente para adicionar evento faz alterações à classe do controle. H. CPP, e. Arquivos IDL. Os exemplos de código a seguir são específicos para o evento ClickIn.

As seguintes linhas são adicionadas ao cabeçalho (. H) o arquivo de sua classe de controle:

[!code-cpp[NVC_MFC_AxUI#7](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_1.h)]

Esse código declara uma função embutida chamada `FireClickIn` que chama [COleControl::FireEvent](../mfc/reference/colecontrol-class.md#fireevent) com o evento ClickIn e os parâmetros definidos usando o Assistente para adicionar eventos.

Além disso, a seguinte linha é adicionada ao mapa de evento para o controle, localizado na implementação (. Arquivo CPP) de sua classe de controle:

[!code-cpp[NVC_MFC_AxUI#8](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_2.cpp)]

Esse código mapeia o evento ClickIn para a função embutida `FireClickIn`, passando os parâmetros que você definiu usando o Assistente de adição de eventos.

Por fim, a linha a seguir é adicionada ao seu controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#9](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_3.idl)]

Essa linha atribui o evento ClickIn um número específico de ID, obtido da posição do evento na lista de eventos Adicionar Assistente de eventos. A entrada na lista de eventos permite que um contêiner prever o evento. Por exemplo, ele pode fornecer o código do manipulador a ser executado quando o evento é acionado.

##  <a name="_core_calling_fireclickin"></a> Chamar FireClickIn

Agora que você adicionou o evento personalizado do ClickIn usando o Assistente para adicionar eventos, você deve decidir quando esse evento é acionado. Você pode fazer isso chamando `FireClickIn` quando ocorre a ação apropriada. Para esta discussão, o controle usa o `InCircle` função dentro de um manipulador de mensagens WM_LBUTTONDOWN acionar o evento ClickIn quando um usuário clica dentro de uma região circular ou elíptica. O procedimento a seguir adiciona o manipulador WM_LBUTTONDOWN.

#### <a name="to-add-a-message-handler-with-the-add-event-wizard"></a>Para adicionar um manipulador de mensagens com o Assistente para adicionar evento

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, selecione sua classe de controle ActiveX.

1. Na janela Propriedades, clique o **mensagens** botão.

   A janela Propriedades exibe uma lista de mensagens que podem ser manipulados pelo controle ActiveX. Qualquer mensagem mostrada em negrito já tem uma função de manipulador atribuída a ele.

1. Na janela Propriedades, selecione a mensagem que você deseja manipular. Neste exemplo, selecione WM_LBUTTONDOWN.

1. Na caixa de lista suspensa à direita, selecione  **\<Adicionar > OnLButtonDown**.

1. Clique duas vezes a nova função de manipulador no modo de exibição de classe para saltar para o código do manipulador de mensagem na implementação (. Arquivo CPP) do seu controle ActiveX.

O seguinte código de exemplo chama o `InCircle` toda vez que o botão esquerdo do mouse é clicado dentro da janela de controle de função. Este exemplo pode ser encontrado na função de manipulador WM_LBUTTONDOWN `OnLButtonDown`, no [exemplo c](../overview/visual-cpp-samples.md) abstrata.

[!code-cpp[NVC_MFC_AxUI#10](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_4.cpp)]

> [!NOTE]
>  Quando o Assistente para adicionar evento cria manipuladores de mensagens para ações de botão do mouse, uma chamada para o mesmo manipulador de mensagem da classe base é adicionada automaticamente. Não remova esta chamada. Se o controle usa nenhuma das mensagens de mouse de estoque, os manipuladores de mensagens na classe base devem ser chamados para garantir que a captura do mouse seja manipulada corretamente.

No exemplo a seguir, o evento é acionado somente quando o clique ocorrer dentro de uma região circular ou elíptica dentro do controle. Para obter esse comportamento, você pode colocar o `InCircle` função na implementação do seu controle (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#11](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_5.cpp)]

Você também precisará adicionar a seguinte declaração do `InCircle` função ao cabeçalho do controle (. H) arquivo:

[!code-cpp[NVC_MFC_AxUI#12](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_6.h)]

##  <a name="_core_custom_events_with_stock_names"></a> Eventos personalizados com nomes de estoque

Você pode criar eventos personalizados com o mesmo nome que os eventos de estoque, no entanto, você não pode implementar ambos no mesmo controle. Por exemplo, você talvez queira criar um evento personalizado chamado clique não é acionado quando o evento de ação clique ser normalmente acionado. Em seguida, você pode acionar o evento de clique a qualquer momento chamando a função de acionamento.

O procedimento a seguir adiciona um clique personalizado eventos.

#### <a name="to-add-a-custom-event-that-uses-a-stock-event-name"></a>Para adicionar um evento personalizado que usa um nome de evento de ação

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, clique com botão direito sua classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique em **Add** e, em seguida, clique em **Adicionar evento**.

   Isso abre o Assistente para adicionar eventos.

1. No **nome do evento** lista suspensa, selecione um nome de evento de ação. Neste exemplo, selecione **clique em**.

1. Para **tipo de evento**, selecione **personalizado**.

1. Clique em **concluir** para criar o evento.

1. Chamar `FireClick` em locais apropriados no seu código.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX MFC: Métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
