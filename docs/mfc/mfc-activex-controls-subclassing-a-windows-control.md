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
ms.openlocfilehash: ccebbad22be92b84fa2fd84434f788484d332cce
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375991"
---
# <a name="mfc-activex-controls-subclassing-a-windows-control"></a>Controles ActiveX MFC: subclasses de um controle do Windows

Este artigo descreve o processo de subclassificação de um controle comum do Windows para criar um controle ActiveX. A subclassificação de um controle windows existente é uma maneira rápida de desenvolver um controle ActiveX. O novo controle terá as habilidades do controle do Windows subclassificado, como pintar e responder a cliques do mouse. O Botão de [amostra](../overview/visual-cpp-samples.md) de controles MFC ActiveX é um exemplo de subclassificação de um controle do Windows.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Para subclassificar um controle do Windows, complete as seguintes tarefas:

- [Substituir as funções de membro IsSubclassedControl e PreCreateWindow do COleControl](#_core_overriding_issubclassedcontrol_and_precreatewindow)

- [Modificar a função de membro OnDraw](#_core_modifying_the_ondraw_member_function)

- [Manuseie quaisquer mensagens de controle ActiveX (OCM) refletidas no controle](#_core_handling_reflected_window_messages)

   > [!NOTE]
   > Grande parte deste trabalho é feito para você pelo Assistente de Controle ActiveX se você selecionar o controle a ser subclassificado usando a lista suspensa **Select Parent Window Class** na página Configurações de **controle.**

## <a name="overriding-issubclassedcontrol-and-precreatewindow"></a><a name="_core_overriding_issubclassedcontrol_and_precreatewindow"></a>Sobrepondo issubclassedControl e PreCreateWindow

Para substituir `PreCreateWindow` `IsSubclassedControl`e adicionar as seguintes linhas de código à seção **protegida** da declaração da classe de controle:

[!code-cpp[NVC_MFC_AxSub#1](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_1.h)]

No arquivo de implementação de controle (. CPP), adicione as seguintes linhas de código para implementar as duas funções substituídas:

[!code-cpp[NVC_MFC_AxSub#2](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_2.cpp)]

Observe que, neste exemplo, o controle do `PreCreateWindow`botão do Windows está especificado em . No entanto, qualquer controle padrão do Windows pode ser subclassificado. Para obter mais informações sobre os controles padrão do Windows, consulte [Controles](../mfc/controls-mfc.md).

Ao subclassificar um controle do Windows, você pode querer especificar sinalizadores de estilo de janela (WS_) ou estilo de janela estendido (WS_EX_) para serem usados na criação da janela do controle. Você pode definir valores `PreCreateWindow` para esses parâmetros `cs.style` na `cs.dwExStyle` função membro modificando os campos e a estrutura. As modificações nesses campos devem ser feitas usando uma operação **OR,** para preservar as bandeiras padrão definidas por classe `COleControl`. Por exemplo, se o controle estiver subclassizando o controle BUTTON e quiser que o controle apareça `CSampleCtrl::PreCreateWindow`como uma caixa de seleção, insira a seguinte linha de código na implementação de , antes da instrução de retorno:

[!code-cpp[NVC_MFC_AxSub#3](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_3.cpp)]

Esta operação adiciona o sinalizador de estilo BS_CHECKBOX, deixando `COleControl` intacta a bandeira de estilo padrão (WS_CHILD) da classe.

## <a name="modifying-the-ondraw-member-function"></a><a name="_core_modifying_the_ondraw_member_function"></a>Modificando a função do membro ondraw

Se você quiser que seu controle subclassificado mantenha a mesma `OnDraw` aparência do controle do Windows correspondente, a função de membro para o controle deve conter apenas uma chamada para a `DoSuperclassPaint` função de membro, como no exemplo a seguir:

[!code-cpp[NVC_MFC_AxSub#4](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_4.cpp)]

A `DoSuperclassPaint` função membro, `COleControl`implementada por , usa o procedimento de janela do controle do Windows para desenhar o controle no contexto do dispositivo especificado, dentro do retângulo delimitador. Isso torna o controle visível mesmo quando não está ativo.

> [!NOTE]
> A `DoSuperclassPaint` função membro funcionará apenas com os tipos de controle que permitem que um contexto do dispositivo seja passado como o *wParam* de uma mensagem WM_PAINT. Isso inclui alguns dos controles padrão do Windows, como SCROLLBAR e BUTTON, e todos os controles comuns. Para controles que não suportam esse comportamento, você terá que fornecer seu próprio código para exibir adequadamente um controle inativo.

## <a name="handling-reflected-window-messages"></a><a name="_core_handling_reflected_window_messages"></a>Manipulação de mensagens de janela refletidas

Os controles do Windows normalmente enviam certas mensagens de janela para a janela dos pais. Algumas dessas mensagens, como WM_COMMAND, fornecem notificação de uma ação pelo usuário. Outros, como WM_CTLCOLOR, são usados para obter informações da janela dos pais. Um controle ActiveX geralmente se comunica com a janela pai por outros meios. As notificações são comunicadas por eventos de disparo (envio de notificações de eventos), e informações sobre o contêiner de controle são obtidas acessando as propriedades ambientais do contêiner. Como essas técnicas de comunicação existem, não se espera que os contêineres de controle ActiveX processem nenhuma mensagem de janela enviada pelo controle.

Para evitar que o contêiner receba as mensagens de `COleControl` janela enviadas por um controle windows subclassificado, crie uma janela extra para servir como pai do controle. Esta janela extra, chamada de "refletor", é criada apenas para um controle ActiveX que subclasses um controle do Windows e tem o mesmo tamanho e posição que a janela de controle. A janela do refletor intercepta certas mensagens de janela e as envia de volta ao controle. O controle, em seu procedimento de janela, pode então processar essas mensagens refletidas, tomando ações apropriadas para um controle ActiveX (por exemplo, disparar um evento). Consulte [IDs de mensagens de janela refletidas](../mfc/reflected-window-message-ids.md) para obter uma lista de mensagens interceptadas do Windows e suas mensagens refletidas correspondentes.

Um contêiner de controle ActiveX pode ser projetado para `COleControl` executar a reflexão da mensagem em si, eliminando a necessidade de criar a janela do refletor e reduzindo a sobrecarga de tempo de execução para um controle windows subclassificado. `COleControl`detecta se o contêiner suporta esse recurso verificando se há uma propriedade ambiente MessageReflect com um valor de **TRUE**.

Para lidar com uma mensagem de janela refletida, adicione uma entrada no mapa da mensagem de controle e implemente uma função de manipulador. Como as mensagens refletidas não fazem parte do conjunto padrão de mensagens definidas pelo Windows, o Class View não suporta a adição desses manipuladores de mensagens. No entanto, não é difícil adicionar um manipulador manualmente.

Para adicionar um manipulador de mensagens para uma mensagem de janela refletida, faça manualmente o seguinte:

- Na classe de controle. Arquivo H, declare uma função de manipulador. A função deve ter um tipo de retorno de **LRESULT** e dois parâmetros, com os tipos **WPARAM** e **LPARAM,** respectivamente. Por exemplo:

   [!code-cpp[NVC_MFC_AxSub#5](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_5.h)]
    [!code-cpp[NVC_MFC_AxSub#6](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_6.h)]

- Na classe de controle. Arquivo CPP, adicione uma entrada ON_MESSAGE ao mapa da mensagem. Os parâmetros desta entrada devem ser o identificador de mensagem e o nome da função do manipulador. Por exemplo:

   [!code-cpp[NVC_MFC_AxSub#7](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_7.cpp)]

- Também no . Arquivo CPP, `OnOcmCommand` implementar a função de membro para processar a mensagem refletida. Os *parâmetros wParam* e *iParam* são os mesmos da mensagem de janela original.

Para obter um exemplo de como as mensagens refletidas são processadas, consulte o [botão](../overview/visual-cpp-samples.md)de amostra de controles MFC ActiveX . Ele demonstra `OnOcmCommand` um manipulador que detecta o código de notificação `Click` BN_CLICKED e responde disparando (enviando) um evento.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
