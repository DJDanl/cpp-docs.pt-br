---
title: 'Controles ActiveX MFC: Subclasses de um controle de Windows | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- precreatewindow
- IsSubclassed
dev_langs: C++
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
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3e41eefdf1c1be2d0e91061e0efce5f5408c1848
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-subclassing-a-windows-control"></a>Controles ActiveX MFC: subclasses de um controle do Windows
Este artigo descreve o processo de subclasses de um controle comum do Windows para criar um controle ActiveX. Controle subclasses existentes do Windows é uma maneira rápida de desenvolver um controle ActiveX. O novo controle terá a capacidade do controle subclasse do Windows, como pintura e responder a cliques do mouse. Exemplo de controles do ActiveX MFC [botão](../visual-cpp-samples.md) é um exemplo de subclasses de um controle do Windows.  
  
 A subclasse um controle do Windows, conclua as seguintes tarefas:  
  
-   [Substituem as funções de membro IsSubclassedControl e PreCreateWindow de COleControl](#_core_overriding_issubclassedcontrol_and_precreatewindow)  
  
-   [Modificar a função de membro OnDraw](#_core_modifying_the_ondraw_member_function)  
  
-   [Lidar com as mensagens de controle ActiveX (OCM) refletidas para o controle](#_core_handling_reflected_window_messages)  
  
    > [!NOTE]
    >  Muito desse trabalho é feito para você pelo Assistente de controle ActiveX se você selecionar o controle a ser uma subclasse usando a **Selecionar classe de janela pai** lista suspensa de **configurações de controle** página.  
  
 Consulte o artigo da Base de dados de Conhecimento Q243454 para obter mais informações sobre subclasses de um controle.  
  
##  <a name="_core_overriding_issubclassedcontrol_and_precreatewindow"></a>Substituindo IsSubclassedControl e PreCreateWindow  
 Para substituir `PreCreateWindow` e `IsSubclassedControl`, adicione as seguintes linhas de código para o `protected` seção da declaração de classe do controle:  
  
 [!code-cpp[NVC_MFC_AxSub#1](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_1.h)]  
  
 No arquivo de implementação de controle (. CPP), adicione as seguintes linhas de código para implementar as duas funções substituídas:  
  
 [!code-cpp[NVC_MFC_AxSub#2](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_2.cpp)]  
  
 Observe que, neste exemplo, os Windows controle de botão é especificado em `PreCreateWindow`. No entanto, os controles de Windows padrão podem ser uma subclasse. Para obter mais informações sobre controles padrão do Windows, consulte [controles](../mfc/controls-mfc.md).  
  
 Quando subclasses de um controle do Windows, você talvez queira especificar o estilo de janela específico (**WS_**) ou o estilo de janela estendido (**WS_EX_**) sinalizadores a ser usado na criação de janela do controle. Você pode definir valores para esses parâmetros no `PreCreateWindow` função de membro, modificando o **cs.style** e **cs.dwExStyle** campos de estrutura. Modificações para esses campos devem ser feitas usando um `OR` operação, para preservar os sinalizadores padrão que são definidos pela classe `COleControl`. Por exemplo, se o controle é Subclassificação do controle de botão e você deseja que o controle seja exibido como uma caixa de seleção, insira a seguinte linha de código na implementação de `CSampleCtrl::PreCreateWindow`, antes da instrução de retorno:  
  
 [!code-cpp[NVC_MFC_AxSub#3](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_3.cpp)]  
  
 Essa operação adiciona o **BS_CHECKBOX** estilo sinalizador, deixando o sinalizador de estilo padrão (**WS_CHILD**) da classe `COleControl` intactos.  
  
##  <a name="_core_modifying_the_ondraw_member_function"></a>Modificando a função de membro OnDraw  
 Se você desejar que o controle de subclasse para manter a mesma aparência que o controle do Windows correspondente, o `OnDraw` a função de membro para o controle deve conter apenas uma chamada para o `DoSuperclassPaint` a função de membro, como no exemplo a seguir:  
  
 [!code-cpp[NVC_MFC_AxSub#4](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_4.cpp)]  
  
 O `DoSuperclassPaint` implementada pela função de membro, `COleControl`, usa o procedimento de janela de controle do Windows para desenhar o controle no contexto de dispositivo especificado, dentro do retângulo delimitador. Isso torna o controle visível mesmo quando não está ativa.  
  
> [!NOTE]
>  O `DoSuperclassPaint` função membro só funcionará com esses tipos de controle que permitem a um contexto de dispositivo a ser passado como o **wParam** de um `WM_PAINT` mensagem. Isso inclui alguns dos controles padrão do Windows, como **SCROLLBAR** e **botão**e todos os controles comuns. Para controles que não oferecem suporte a esse comportamento, você precisará fornecer seu próprio código para exibir corretamente um controle inativo.  
  
##  <a name="_core_handling_reflected_window_messages"></a>Manipulando janela mensagens refletidas  
 Controles do Windows geralmente enviam determinadas mensagens de janela para a janela pai. Algumas dessas mensagens, como **WM_COMMAND**, fornecer notificação de uma ação do usuário. Outras, como `WM_CTLCOLOR`, são usadas para obter informações da janela pai. Um controle ActiveX geralmente se comunica com a janela pai por outros meios. As notificações são comunicadas por acionando eventos (enviar notificações de eventos) e informações sobre o contêiner de controle são obtidas acessando propriedades ambiente do contêiner. Como essas técnicas de comunicação existem, contêineres de controle ActiveX não são esperados para processar as mensagens de janela enviadas pelo controle.  
  
 Para impedir que o contêiner receba as mensagens de janela enviadas por um controle de Windows subclasse, `COleControl` cria uma janela extra para servir como o pai do controle. Essa janela extra, chamada "reflector", é criada apenas para um controle ActiveX que subclasses de uma janela de controlam e tem o mesmo tamanho e a posição da janela de controle. A janela reflector intercepta determinadas mensagens de janela e envia-os de volta para o controle. O controle, em seu procedimento de janela pode processar essas mensagens refletidas executando ações apropriadas para um controle ActiveX (por exemplo, disparar um evento). Consulte [IDs de mensagem da janela refletida](../mfc/reflected-window-message-ids.md) para uma lista de janelas interceptadas mensagens e seus correspondente refletidas mensagens.  
  
 Um contêiner de controle ActiveX pode ser criado para executar a reflexão de mensagem em si, eliminando a necessidade de `COleControl` para criar a janela reflector e reduzindo o tempo de execução do controle do Windows subclasse. `COleControl`detecta se o contêiner dá suporte a esse recurso através da verificação de uma propriedade de ambiente MessageReflect com um valor de **TRUE**.  
  
 Para lidar com uma mensagem da janela refletida, adicione uma entrada para o mapa de mensagens de controle e implementar uma função de manipulador. Como mensagens refletidas não fazem parte do conjunto padrão de mensagens definidas pelo Windows, o modo de exibição de classe não dá suporte adicionando esses manipuladores de mensagens. No entanto, não é difícil adicionar um manipulador manualmente.  
  
 Para adicionar um manipulador de mensagens para uma mensagem da janela refletida manualmente faça o seguinte:  
  
-   Na classe de controle. Arquivo H, declarar uma função de manipulador. A função deve ter um tipo de retorno **LRESULT** e dois parâmetros com tipos **WPARAM** e **LPARAM**, respectivamente. Por exemplo:  
  
     [!code-cpp[NVC_MFC_AxSub#5](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_5.h)]  
    [!code-cpp[NVC_MFC_AxSub#6](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_6.h)]  
  
-   Na classe de controle. CPP de arquivo, adicione um `ON_MESSAGE` entrada para o mapa de mensagens. Os parâmetros desta entrada devem ser o identificador da mensagem e o nome da função de manipulador. Por exemplo:  
  
     [!code-cpp[NVC_MFC_AxSub#7](../mfc/codesnippet/cpp/mfc-activex-controls-subclassing-a-windows-control_7.cpp)]  
  
-   Também no. O arquivo CPP, implementar a **OnOcmCommand** a função de membro para processar a mensagem refletida. O **wParam** e **lParam** parâmetros são os mesmos da mensagem original da janela.  
  
 Para um exemplo de como refletido as mensagens são processadas, consulte o exemplo de controles ActiveX MFC [botão](../visual-cpp-samples.md). Ele demonstra uma **OnOcmCommand** manipulador que detecta o **BN_CLICKED** código de notificação e um evento de clique responde acionando (envio).  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

