---
title: 'Controles ActiveX MFC: Subclasses de um controle do Windows'
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
ms.openlocfilehash: 7042df6e7b7dc2c9a608470ba7cfc5a9e9f6127a
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58773249"
---
# <a name="mfc-activex-controls-subclassing-a-windows-control"></a>Controles ActiveX MFC: Subclasses de um controle do Windows

Este artigo descreve o processo para subclasses de um controle comum do Windows para criar um controle ActiveX. Controle subclasses de um Windows existentes é uma maneira rápida de desenvolver um controle ActiveX. O novo controle terá a capacidade de controle subclasse do Windows, como pintura e responder a cliques do mouse. Exemplo de controles ActiveX MFC [botão](../overview/visual-cpp-samples.md) é um exemplo de subclasses de um controle do Windows.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

A subclasse um controle do Windows, conclua as seguintes tarefas:

- [Substituir as funções de membro IsSubclassedControl e PreCreateWindow da COleControl](#_core_overriding_issubclassedcontrol_and_precreatewindow)

- [Modifique a função de membro OnDraw](#_core_modifying_the_ondraw_member_function)

- [Lidar com quaisquer mensagens de controle ActiveX (OCM) refletidas ao controle](#_core_handling_reflected_window_messages)

   > [!NOTE]
   > Grande parte desse trabalho é feito para você pelo Assistente de controle ActiveX se você selecionar o controle para ser uma subclasse usando o **Selecionar classe de janela pai** lista suspensa na **configurações de controle** página.

##  <a name="_core_overriding_issubclassedcontrol_and_precreatewindow"></a> Substituindo IsSubclassedControl e PreCreateWindow

Para substituir `PreCreateWindow` e `IsSubclassedControl`, adicione as seguintes linhas de código para o **protegido** seção da declaração de classe de controle:

[!code-cpp[NVC_MFC_AxSub#1](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_1.h)]

No arquivo de implementação de controle (. CPP), adicione as seguintes linhas de código para implementar as duas funções substituídas:

[!code-cpp[NVC_MFC_AxSub#2](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_2.cpp)]

Observe que, neste exemplo, os Windows controle de botão é especificado em `PreCreateWindow`. No entanto, quaisquer controles padrão do Windows pode ser uma subclasse. Para obter mais informações sobre os controles padrão do Windows, consulte [controles](../mfc/controls-mfc.md).

Quando subclasses de um controle do Windows, você talvez queira especificar o estilo de janela específica (WS _) ou de janela estendidos sinalizadores de estilo (WS_EX_) a ser usado na criação de janela do controle. Você pode definir valores para esses parâmetros na `PreCreateWindow` função de membro, modificando o `cs.style` e o `cs.dwExStyle` campos de estrutura. As modificações a esses campos devem ser feitas usando um **ou** operação, para preservar os sinalizadores padrão que são definidos pela classe `COleControl`. Por exemplo, se o controle é subclasses de controle de botão e você deseja que o controle seja exibido como uma caixa de seleção, insira a seguinte linha de código na implementação de `CSampleCtrl::PreCreateWindow`, antes da instrução return:

[!code-cpp[NVC_MFC_AxSub#3](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_3.cpp)]

Essa operação adiciona o sinalizador de estilo BS_CHECKBOX, deixando o sinalizador de estilo padrão (WS_CHILD) da classe `COleControl` intactos.

##  <a name="_core_modifying_the_ondraw_member_function"></a> Modificando a função de membro OnDraw

Se você quiser que o controle de subclasse para manter a mesma aparência que o controle correspondente do Windows, o `OnDraw` função de membro para o controle deve conter apenas uma chamada para o `DoSuperclassPaint` função de membro, como no exemplo a seguir:

[!code-cpp[NVC_MFC_AxSub#4](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_4.cpp)]

O `DoSuperclassPaint` função de membro, implementada pelo `COleControl`, usa o procedimento de janela do controle do Windows para desenhar o controle no contexto de dispositivo especificado, dentro do retângulo delimitador. Isso torna o controle visível mesmo quando não está ativo.

> [!NOTE]
>  O `DoSuperclassPaint` função de membro só funcionará com esses tipos de controle que permitem que um contexto de dispositivo a ser passado como o *wParam* de uma mensagem WM_PAINT. Isso inclui alguns dos controles padrão do Windows, como a barra de ROLAGEM e botão e todos os controles comuns. Para controles que não dão suporte a esse comportamento, você precisará fornecer seu próprio código para exibir corretamente um controle inativo.

##  <a name="_core_handling_reflected_window_messages"></a> Manipulando janela mensagens refletidas

Controles do Windows normalmente enviam determinadas mensagens de janela para sua janela pai. Algumas dessas mensagens, como o WM_COMMAND, fornecem notificação de uma ação do usuário. Outros, como WM_CTLCOLOR, são usados para obter informações da janela pai. Um controle ActiveX geralmente se comunica com a janela pai por outros meios. As notificações são comunicadas por acionar eventos (enviando notificações de eventos) e informações sobre o contêiner de controle são obtidas, acessando propriedades de ambiente do contêiner. Como essas técnicas de comunicação existem, contêineres de controle ActiveX não devem processar as mensagens de janela enviadas pelo controle.

Para impedir que o contêiner receba as mensagens de janela enviadas por um controle de Windows subclasse, `COleControl` cria uma janela extra para servir como o pai do controle. Essa janela extra, chamada "reflector", é criada apenas para um controle ActiveX que as subclasses de um Windows controlam e tem o mesmo tamanho e posição como a janela de controle. A janela do reflector intercepta determinadas mensagens de janela e envia-os de volta para o controle. O controle, em seu procedimento de janela pode processar essas mensagens refletidas executando ações apropriadas para um controle ActiveX (por exemplo, acionar um evento). Ver [IDs de mensagem da janela refletida](../mfc/reflected-window-message-ids.md) para uma lista de janelas interceptadas mensagens e suas respectivas refletem mensagens.

Um contêiner de controle ActiveX pode ser projetado para executar a reflexão de mensagem em si, eliminando a necessidade de `COleControl` para criar a janela do reflector e reduzindo o tempo de execução sobrecarga de um controle de Windows subclasse. `COleControl` detecta se o contêiner dá suporte a esse recurso através da verificação de uma propriedade de ambiente MessageReflect com um valor de **verdadeira**.

Para lidar com uma mensagem da janela refletida, adicione uma entrada para mapa de mensagens de controle e implementar uma função de manipulador. Como mensagens refletidas não fazem parte do conjunto padrão de mensagens definidas pelo Windows, o modo de exibição de classe não oferece suporte adicionando esses manipuladores de mensagens. No entanto, não é difícil adicionar um manipulador manualmente.

Para adicionar um manipulador de mensagens para uma mensagem da janela refletida manualmente faça o seguinte:

- Na classe de controle. Arquivo do H, declarar uma função de manipulador. A função deve ter um tipo de retorno **LRESULT** e dois parâmetros com tipos **WPARAM** e **LPARAM**, respectivamente. Por exemplo:

   [!code-cpp[NVC_MFC_AxSub#5](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_5.h)]
    [!code-cpp[NVC_MFC_AxSub#6](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_6.h)]

- Na classe de controle. CPP do arquivo, adicione uma entrada ON_MESSAGE ao mapa de mensagens. Os parâmetros desta entrada devem ser o identificador da mensagem e o nome da função de manipulador. Por exemplo:

   [!code-cpp[NVC_MFC_AxSub#7](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_7.cpp)]

- Além disso, na. Arquivo CPP, implemente o `OnOcmCommand` a função de membro para processar a mensagem refletida. O *wParam* e *lParam* parâmetros são iguais da mensagem em janela original.

Para um exemplo de como refletido as mensagens são processadas, consulte o exemplo de controles ActiveX MFC [botão](../overview/visual-cpp-samples.md). Ele demonstra uma `OnOcmCommand` manipulador que detecta o código de notificação BN_CLICKED e responde disparando (Enviar) um `Click` eventos.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
