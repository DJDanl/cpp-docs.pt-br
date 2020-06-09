---
title: 'Controles ActiveX MFC: adicionando eventos personalizados'
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
ms.openlocfilehash: 70b0e08bc638b5f630d423ec0db8a169a0119175
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619945"
---
# <a name="mfc-activex-controls-adding-custom-events"></a>Controles ActiveX MFC: adicionando eventos personalizados

Eventos personalizados diferem dos eventos de estoque em que eles não são automaticamente acionados por classe `COleControl` . Um evento personalizado reconhece uma determinada ação, determinada pelo desenvolvedor de controle, como um evento. As entradas do mapa de eventos para eventos personalizados são representadas pela macro EVENT_CUSTOM. A seção a seguir implementa um evento personalizado para um projeto de controle ActiveX que foi criado usando o assistente de controle ActiveX.

## <a name="adding-a-custom-event-with-the-add-event-wizard"></a><a name="_core_adding_a_custom_event_with_classwizard"></a>Adicionando um evento personalizado com o assistente para adicionar eventos

O procedimento a seguir adiciona um evento personalizado específico, clique em. Você pode usar este procedimento para adicionar outros eventos personalizados. Substitua o nome do evento personalizado e seus parâmetros pelos parâmetros e pelo nome do evento Click.

#### <a name="to-add-the-clickin-custom-event-using-the-add-event-wizard"></a>Para adicionar o evento de clique personalizado usando o assistente para adicionar evento

1. Carregue o projeto do seu controle.

1. Em **modo de exibição de classe**, clique com o botão direito do mouse em sua classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar evento**.

   Isso abre o assistente para adicionar evento.

1. Na caixa **nome do evento** , primeiro selecione qualquer evento existente e, em seguida, clique no botão de opção **personalizado** e digite *Click*.

1. Na caixa **nome interno** , digite o nome da função de acionamento do evento. Para este exemplo, use o valor padrão fornecido pelo Assistente para adicionar evento ( `FireClickIn` ).

1. Adicione um parâmetro, chamado *xCoord* (tipo *OLE_XPOS_PIXELS*), usando os controles de **nome de parâmetro** e **tipo de parâmetro** .

1. Adicione um segundo parâmetro, chamado *yCoord* (tipo *OLE_YPOS_PIXELS*).

1. Clique em **concluir** para criar o evento.

## <a name="add-event-wizard-changes-for-custom-events"></a><a name="_core_classwizard_changes_for_custom_events"></a>Adicionar alterações do assistente de evento para eventos personalizados

Quando você adiciona um evento personalizado, o assistente para adicionar eventos faz alterações na classe de controle. H,. CPP e. Arquivos IDL. Os exemplos de código a seguir são específicos para o evento Click.

As linhas a seguir são adicionadas ao cabeçalho (. H) do arquivo de sua classe de controle:

[!code-cpp[NVC_MFC_AxUI#7](codesnippet/cpp/mfc-activex-controls-adding-custom-events_1.h)]

Esse código declara uma função embutida chamada `FireClickIn` que chama [COleControl:: FireEvent](reference/colecontrol-class.md#fireevent) com o evento Click e os parâmetros que você definiu usando o assistente para adicionar evento.

Além disso, a linha a seguir é adicionada ao mapa de eventos para o controle, localizado na implementação (. CPP) do arquivo de sua classe de controle:

[!code-cpp[NVC_MFC_AxUI#8](codesnippet/cpp/mfc-activex-controls-adding-custom-events_2.cpp)]

Esse código mapeia o evento Click para a função inline `FireClickIn` , passando os parâmetros que você definiu usando o assistente para adicionar evento.

Por fim, a linha a seguir é adicionada ao seu controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#9](codesnippet/cpp/mfc-activex-controls-adding-custom-events_3.idl)]

Essa linha atribui o evento Click a um número de ID específico, extraído da posição do evento na lista de eventos do assistente de adição de eventos. A entrada na lista de eventos permite que um contêiner antecipe o evento. Por exemplo, ele pode fornecer código de manipulador a ser executado quando o evento for acionado.

## <a name="calling-fireclickin"></a><a name="_core_calling_fireclickin"></a>Chamando FireClickIn

Agora que você adicionou o clique em evento personalizado usando o assistente para adicionar evento, deverá decidir quando esse evento deve ser acionado. Faça isso chamando `FireClickIn` quando a ação apropriada ocorrer. Para essa discussão, o controle usa a `InCircle` função dentro de um `WM_LBUTTONDOWN` manipulador de mensagens para acionar o evento Click quando um usuário clica dentro de uma região circular ou elíptica. O procedimento a seguir adiciona o `WM_LBUTTONDOWN` manipulador.

#### <a name="to-add-a-message-handler-with-the-add-event-wizard"></a>Para adicionar um manipulador de mensagens com o assistente para adicionar eventos

1. Carregue o projeto do seu controle.

1. Em **modo de exibição de classe**, selecione sua classe de controle ActiveX.

1. Na janela **Propriedades** , você vê uma lista de mensagens que podem ser manipuladas pelo controle ActiveX. Qualquer mensagem mostrada em negrito já tem uma função de manipulador atribuída a ela.

1. Selecione a mensagem que você deseja manipular. Para este exemplo, selecione `WM_LBUTTONDOWN` .

1. Na caixa de listagem suspensa à direita, selecione ** \<Add> OnLButtonDown**.

1. Clique duas vezes na nova função de manipulador em **modo de exibição de classe** para saltar para o código do manipulador de mensagens na implementação (. CPP) do seu controle ActiveX.

O exemplo de código a seguir chama a `InCircle` função toda vez que o botão esquerdo do mouse é clicado dentro da janela de controle. Esse exemplo pode ser encontrado na `WM_LBUTTONDOWN` função de manipulador, `OnLButtonDown` , no Resumo de [exemplo de Circ](../overview/visual-cpp-samples.md) .

[!code-cpp[NVC_MFC_AxUI#10](codesnippet/cpp/mfc-activex-controls-adding-custom-events_4.cpp)]

> [!NOTE]
> Quando o assistente para adicionar evento cria manipuladores de mensagens para ações de botão do mouse, uma chamada para o mesmo manipulador de mensagens da classe base é adicionada automaticamente. Não remova esta chamada. Se o seu controle usa qualquer uma das mensagens do mouse de ações, os manipuladores de mensagens na classe base devem ser chamados para garantir que a captura do mouse seja manipulada corretamente.

No exemplo a seguir, o evento é acionado somente quando o clique ocorre dentro de uma região circular ou elíptica dentro do controle. Para obter esse comportamento, você pode posicionar a `InCircle` função na implementação do seu controle (. CPP) arquivo:

[!code-cpp[NVC_MFC_AxUI#11](codesnippet/cpp/mfc-activex-controls-adding-custom-events_5.cpp)]

Você também precisará adicionar a seguinte declaração da `InCircle` função ao cabeçalho do controle (. H) arquivo:

[!code-cpp[NVC_MFC_AxUI#12](codesnippet/cpp/mfc-activex-controls-adding-custom-events_6.h)]

## <a name="custom-events-with-stock-names"></a><a name="_core_custom_events_with_stock_names"></a>Eventos personalizados com nomes de ações

Você pode criar eventos personalizados com o mesmo nome que os eventos de estoque, no entanto, não é possível implementar ambos no mesmo controle. Por exemplo, talvez você queira criar um evento personalizado chamado Click que não é acionado quando o clique do evento de ação normalmente é acionado. Em seguida, você pode acionar o evento de clique a qualquer momento chamando a função de acionamento.

O procedimento a seguir adiciona um evento de clique personalizado.

#### <a name="to-add-a-custom-event-that-uses-a-stock-event-name"></a>Para adicionar um evento personalizado que usa um nome de evento de ações

1. Carregue o projeto do seu controle.

1. Em **modo de exibição de classe**, clique com o botão direito do mouse em sua classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar evento**.

   Isso abre o assistente para adicionar evento.

1. Na lista suspensa **nome do evento** , selecione um nome de evento de estoque. Para este exemplo, selecione **clique**.

1. Para **tipo de evento**, selecione **personalizado**.

1. Clique em **concluir** para criar o evento.

1. Chame `FireClick` em locais apropriados em seu código.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: métodos](mfc-activex-controls-methods.md)<br/>
[Classe COleControl](reference/colecontrol-class.md)
