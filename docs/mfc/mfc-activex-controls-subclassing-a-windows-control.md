---
title: 'Controles ActiveX MFC: subclasses de um controle do Windows'
ms.date: 09/12/2018
f1_keywords:
- precreatewindow
- IsSubclassed
helpviewer_keywords:
- OnDraw method, MFC ActiveX controls
- subclassing
- DoSuperclassPaint method [MFC]
- subclassing Windows controls
- subclassing, Windows controls
- reflected messages, in ActiveX controls
- PreCreateWindow method, overriding
- MFC ActiveX controls [MFC], subclassed controls
- MFC ActiveX controls [MFC], creating
- IsSubclassed method [MFC]
ms.assetid: 3236d4de-401f-49b7-918d-c84559ecc426
ms.openlocfilehash: 354cd1cac5db775ea56cb5215a8528bdfe9ac5ab
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225001"
---
# <a name="mfc-activex-controls-subclassing-a-windows-control"></a>Controles ActiveX MFC: subclasses de um controle do Windows

Este artigo descreve o processo de subclasse de um controle comum do Windows para criar um controle ActiveX. A criação de uma subclasse de um controle existente do Windows é uma maneira rápida de desenvolver um controle ActiveX. O novo controle terá as capacidades do controle de subclasse do Windows, como pintar e responder a cliques do mouse. O [botão](../overview/visual-cpp-samples.md) exemplo de controles ActiveX do MFC é um exemplo de subclasse de um controle do Windows.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Para subclasse de um controle do Windows, conclua as seguintes tarefas:

- [Substituir as funções de membro IsSubclassedControl e PreCreateWindow de COleControl](#_core_overriding_issubclassedcontrol_and_precreatewindow)

- [Modificar a função de membro OnDraw](#_core_modifying_the_ondraw_member_function)

- [Manipular quaisquer OCM (mensagens de controle ActiveX) refletidas no controle](#_core_handling_reflected_window_messages)

   > [!NOTE]
   > Grande parte desse trabalho é feita para você pelo assistente de controle ActiveX se você selecionar o controle a ser subclassedo usando a lista suspensa **Selecionar classe de janela pai** na página **configurações de controle** .

## <a name="overriding-issubclassedcontrol-and-precreatewindow"></a><a name="_core_overriding_issubclassedcontrol_and_precreatewindow"></a>Substituindo IsSubclassedControl e PreCreateWindow

Para substituir `PreCreateWindow` e `IsSubclassedControl` Adicionar as seguintes linhas de código à **`protected`** seção da declaração de classe de controle:

[!code-cpp[NVC_MFC_AxSub#1](codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_1.h)]

No arquivo de implementação de controle (. CPP), adicione as seguintes linhas de código para implementar as duas funções substituídas:

[!code-cpp[NVC_MFC_AxSub#2](codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_2.cpp)]

Observe que, neste exemplo, o controle de botão do Windows é especificado em `PreCreateWindow` . No entanto, todos os controles padrão do Windows podem ser subclasses. Para obter mais informações sobre controles padrão do Windows, consulte [controles](controls-mfc.md).

Ao criar uma subclasse de um controle do Windows, talvez você queira especificar os sinalizadores de estilo de janela (WS_) ou de estilo de janela estendidos (WS_EX_) para que sejam usados na criação da janela do controle. Você pode definir valores para esses parâmetros na `PreCreateWindow` função de membro modificando os `cs.style` campos de `cs.dwExStyle` estrutura e. As modificações nesses campos devem ser feitas usando uma operação **ou** , para preservar os sinalizadores padrão definidos por classe `COleControl` . Por exemplo, se o controle estiver subclassendo o controle de botão e você quiser que o controle apareça como uma caixa de seleção, insira a seguinte linha de código na implementação de `CSampleCtrl::PreCreateWindow` , antes da instrução de retorno:

[!code-cpp[NVC_MFC_AxSub#3](codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_3.cpp)]

Esta operação adiciona o sinalizador de estilo BS_CHECKBOX, deixando o sinalizador de estilo padrão (WS_CHILD) de classe `COleControl` intacto.

## <a name="modifying-the-ondraw-member-function"></a><a name="_core_modifying_the_ondraw_member_function"></a>Modificando a função de membro OnDraw

Se você quiser que seu controle de subclasse mantenha a mesma aparência que o controle do Windows correspondente, a `OnDraw` função de membro para o controle deve conter apenas uma chamada para a `DoSuperclassPaint` função de membro, como no exemplo a seguir:

[!code-cpp[NVC_MFC_AxSub#4](codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_4.cpp)]

A `DoSuperclassPaint` função de membro, implementada pelo `COleControl` , usa o procedimento de janela do controle do Windows para desenhar o controle no contexto de dispositivo especificado, dentro do retângulo delimitador. Isso torna o controle visível mesmo quando não está ativo.

> [!NOTE]
> A `DoSuperclassPaint` função membro só funcionará com os tipos de controle que permitem que um contexto de dispositivo seja passado como o *wParam* de uma mensagem de WM_PAINT. Isso inclui alguns dos controles padrão do Windows, como SCROLLBAR e BUTTON, e todos os controles comuns. Para controles que não dão suporte a esse comportamento, você precisará fornecer seu próprio código para exibir corretamente um controle inativo.

## <a name="handling-reflected-window-messages"></a><a name="_core_handling_reflected_window_messages"></a>Manipulando mensagens de janela refletidas

Os controles do Windows normalmente enviam certas mensagens de janela para sua janela pai. Algumas dessas mensagens, como WM_COMMAND, fornecem notificação de uma ação pelo usuário. Outros, como WM_CTLCOLOR, são usados para obter informações da janela pai. Um controle ActiveX geralmente se comunica com a janela pai por outros meios. As notificações são comunicadas por eventos de acionamento (envio de notificações de eventos) e as informações sobre o contêiner de controle são obtidas acessando as propriedades de ambiente do contêiner. Como existem essas técnicas de comunicação, os contêineres de controle ActiveX não devem processar nenhuma mensagem de janela enviada pelo controle.

Para impedir que o contêiner receba as mensagens de janela enviadas por um controle de subclasse do Windows, `COleControl` o cria uma janela extra para servir como o pai do controle. Essa janela extra, chamada de "refletor", é criada somente para um controle ActiveX que subcria um controle do Windows e tem o mesmo tamanho e posição que a janela de controle. A janela refletor intercepta certas mensagens da janela e as envia de volta para o controle. O controle, em seu procedimento de janela, pode processar essas mensagens refletidas executando ações apropriadas para um controle ActiveX (por exemplo, acionando um evento). Consulte [IDs de mensagem da janela refletida](reflected-window-message-ids.md) para obter uma lista de mensagens interceptadas do Windows e suas mensagens refletidas correspondentes.

Um contêiner de controle ActiveX pode ser criado para executar a reflexão da mensagem em si, eliminando a necessidade de `COleControl` criar a janela do reflector e reduzir a sobrecarga de tempo de execução para um controle de uma subclasse do Windows. `COleControl`detecta se o contêiner dá suporte a essa capacidade verificando se há uma propriedade de ambiente MessageReflect com um valor de **true**.

Para manipular uma mensagem de janela refletida, adicione uma entrada ao mapa de mensagens de controle e implemente uma função de manipulador. Como as mensagens refletidas não fazem parte do conjunto padrão de mensagens definidas pelo Windows, Modo de Exibição de Classe não dá suporte à adição desses manipuladores de mensagens. No entanto, não é difícil adicionar um manipulador manualmente.

Para adicionar um manipulador de mensagens para uma mensagem de janela refletida manualmente, faça o seguinte:

- Na classe de controle. Arquivo H, declare uma função de manipulador. A função deve ter um tipo de retorno de **LRESULT** e dois parâmetros, com tipos **wParam** e **lParam**, respectivamente. Por exemplo:

   [!code-cpp[NVC_MFC_AxSub#5](codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_5.h)]
    [!code-cpp[NVC_MFC_AxSub#6](codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_6.h)]

- Na classe de controle. Arquivo CPP, adicione uma entrada de ON_MESSAGE ao mapa de mensagens. Os parâmetros dessa entrada devem ser o identificador da mensagem e o nome da função do manipulador. Por exemplo:

   [!code-cpp[NVC_MFC_AxSub#7](codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_7.cpp)]

- Também no. Arquivo CPP, implemente a `OnOcmCommand` função membro para processar a mensagem refletida. Os parâmetros *wParam* e *lParam* são os mesmos que os da mensagem de janela original.

Para obter um exemplo de como as mensagens refletidas são processadas, consulte o [botão](../overview/visual-cpp-samples.md)de exemplo de controles ActiveX do MFC. Ele demonstra um `OnOcmCommand` manipulador que detecta o BN_CLICKED código de notificação e responde acionando (enviando) um `Click` evento.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](mfc-activex-controls.md)
