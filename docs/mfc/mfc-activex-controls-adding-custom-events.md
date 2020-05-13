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
ms.openlocfilehash: 8d464e5d7c9731e158e44d66d569fd1555401e17
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364726"
---
# <a name="mfc-activex-controls-adding-custom-events"></a>Controles ActiveX MFC: adicionando eventos personalizados

Os eventos personalizados diferem dos eventos de ações, pois não são automaticamente disparados por classe `COleControl`. Um evento personalizado reconhece uma determinada ação, determinada pelo desenvolvedor de controle, como um evento. As entradas do mapa do evento para eventos personalizados são representadas pela macro EVENT_CUSTOM. A seção a seguir implementa um evento personalizado para um projeto de controle ActiveX que foi criado usando o ActiveX Control Wizard.

## <a name="adding-a-custom-event-with-the-add-event-wizard"></a><a name="_core_adding_a_custom_event_with_classwizard"></a>Adicionando um evento personalizado com o Assistente de Evento Adicionar

O procedimento a seguir adiciona um evento personalizado específico, ClickIn. Você pode usar este procedimento para adicionar outros eventos personalizados. Substitua o nome do evento personalizado e seus parâmetros para o nome e parâmetros do evento ClickIn.

#### <a name="to-add-the-clickin-custom-event-using-the-add-event-wizard"></a>Para adicionar o evento personalizado ClickIn usando o Assistente de Adicionar Eventos

1. Carregue o projeto do seu controle.

1. Em **Exibição de classe,** clique com o botão direito do mouse na classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar evento**.

   Isso abre o Assistente de Adicionar Eventos.

1. Na caixa **nome do evento,** primeiro selecione qualquer evento existente e clique no botão de rádio **Personalizado** e digite *ClickIn*.

1. Na **caixa Nome Interno,** digite o nome da função de disparo do evento. Para este exemplo, use o valor padrão fornecido`FireClickIn`pelo Assistente de Evento adicionar ( ).

1. Adicione um parâmetro, chamado *xCoord* (tipo *OLE_XPOS_PIXELS),* usando os controles Nome do **parâmetro** e **tipo de parâmetro.**

1. Adicione um segundo parâmetro, chamado *yCoord* (tipo *OLE_YPOS_PIXELS*).

1. Clique **em Concluir** para criar o evento.

## <a name="add-event-wizard-changes-for-custom-events"></a><a name="_core_classwizard_changes_for_custom_events"></a>Adicionar alterações do assistente de eventos para eventos personalizados

Quando você adiciona um evento personalizado, o Assistente de adicionar eventos faz alterações na classe de controle . H. CPP, e . Arquivos IDL. As seguintes amostras de código são específicas para o evento ClickIn.

As seguintes linhas são adicionadas ao cabeçalho (. H) arquivo da sua classe de controle:

[!code-cpp[NVC_MFC_AxUI#7](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_1.h)]

Este código declara uma função `FireClickIn` inline chamada [COleControl::FireEvent](../mfc/reference/colecontrol-class.md#fireevent) com o evento ClickIn e parâmetros definidos usando o Assistente de Adicionar Eventos.

Além disso, a linha a seguir é adicionada ao mapa de eventos para o controle, localizado na implementação (. CPP) arquivo da sua classe de controle:

[!code-cpp[NVC_MFC_AxUI#8](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_2.cpp)]

Este código mapeia o evento `FireClickIn`ClickIn para a função inline , passando os parâmetros definidos usando o Assistente de Adicionar eventos.

Finalmente, a seguinte linha é adicionada ao seu controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#9](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_3.idl)]

Esta linha atribui ao evento ClickIn um número de ID específico, retirado da posição do evento na lista de eventos Add Event Wizard. A entrada na lista de eventos permite que um contêiner antecipe o evento. Por exemplo, ele pode fornecer código de manipulador a ser executado quando o evento é acionado.

## <a name="calling-fireclickin"></a><a name="_core_calling_fireclickin"></a>Chamando FireClickIn

Agora que você adicionou o evento personalizado ClickIn usando o Assistente de Evento Adicionar, você deve decidir quando este evento será acionado. Você faz isso `FireClickIn` ligando quando a ação apropriada ocorre. Para esta discussão, o `InCircle` controle `WM_LBUTTONDOWN` usa a função dentro de um manipulador de mensagens para disparar o evento ClickIn quando um usuário clica dentro de uma região circular ou elíptica. O procedimento a `WM_LBUTTONDOWN` seguir adiciona o manipulador.

#### <a name="to-add-a-message-handler-with-the-add-event-wizard"></a>Para adicionar um manipulador de mensagens com o Assistente de Evento adicionar

1. Carregue o projeto do seu controle.

1. Em **Exibição de classe,** selecione sua classe de controle ActiveX.

1. Na janela **Propriedades,** você vê uma lista de mensagens que podem ser manuseadas pelo controle ActiveX. Qualquer mensagem mostrada em negrito já tem uma função de manipulador atribuída a ela.

1. Selecione a mensagem que deseja manusear. Para este exemplo, selecione `WM_LBUTTONDOWN`.

1. Na caixa de lista baixa à direita, ** \<selecione Adicionar> OnLButtonDown**.

1. Clique duas vezes na nova função de manipulador na **Exibição de classe** para saltar para o código do manipulador de mensagens na implementação (. CPP) arquivo do seu controle ActiveX.

A amostra de `InCircle` código a seguir chama a função toda vez que o botão esquerdo do mouse é clicado dentro da janela de controle. Esta amostra pode ser `WM_LBUTTONDOWN` encontrada `OnLButtonDown`na função do manipulador, no resumo da [amostra de Circ.](../overview/visual-cpp-samples.md)

[!code-cpp[NVC_MFC_AxUI#10](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_4.cpp)]

> [!NOTE]
> Quando o Assistente de adicionar evento cria manipuladores de mensagens para ações do botão do mouse, uma chamada para o mesmo manipulador de mensagens da classe base é adicionada automaticamente. Não remova esta chamada. Se o seu controle usar qualquer uma das mensagens do mouse de estoque, os manipuladores de mensagens na classe base devem ser chamados para garantir que a captura do mouse seja tratada corretamente.

No exemplo a seguir, o evento é acionado somente quando o clique ocorre dentro de uma região circular ou elíptica dentro do controle. Para alcançar esse comportamento, `InCircle` você pode colocar a função na implementação do seu controle (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#11](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_5.cpp)]

Você também precisará adicionar a seguinte `InCircle` declaração da função ao cabeçalho do seu controle (. Arquivo H:

[!code-cpp[NVC_MFC_AxUI#12](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-events_6.h)]

## <a name="custom-events-with-stock-names"></a><a name="_core_custom_events_with_stock_names"></a>Eventos personalizados com nomes de ações

Você pode criar eventos personalizados com o mesmo nome de eventos de ações, no entanto, você não pode implementar ambos no mesmo controle. Por exemplo, você pode querer criar um evento personalizado chamado Clique que não seja acionado quando o evento de estoque Clique normalmente seria acionado. Em seguida, você pode disparar o evento Clique a qualquer momento, chamando sua função de disparo.

O procedimento a seguir adiciona um evento de clique personalizado.

#### <a name="to-add-a-custom-event-that-uses-a-stock-event-name"></a>Para adicionar um evento personalizado que usa um nome de evento de ações

1. Carregue o projeto do seu controle.

1. Em **Exibição de classe,** clique com o botão direito do mouse na classe de controle ActiveX para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar evento**.

   Isso abre o Assistente de Adicionar Eventos.

1. Na lista de paradas **nomeação nome** de evento, selecione um nome de evento de ações. Para este exemplo, selecione **Clique**.

1. Para **tipo de evento,** selecione **Personalizado**.

1. Clique **em Concluir** para criar o evento.

1. Ligue `FireClick` em lugares apropriados em seu código.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
