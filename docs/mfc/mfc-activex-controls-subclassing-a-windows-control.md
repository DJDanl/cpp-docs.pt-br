---
title: "Controles ActiveX MFC: subclasses de um controle do Windows | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "precreatewindow"
  - "IsSubclassed"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método DoSuperclassPaint"
  - "Método IsSubclassed"
  - "Controles ActiveX MFC, criando"
  - "Controles ActiveX MFC, controles de subclasse"
  - "Método OnDraw, Controles ActiveX MFC"
  - "Método PreCreateWindow, substituição"
  - "mensagens refletidas, em controles ActiveX"
  - "subclasses"
  - "controles Windows de subclasses"
  - "subclasses, Controles do Windows"
ms.assetid: 3236d4de-401f-49b7-918d-c84559ecc426
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: subclasses de um controle do Windows
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve o processo para subclassing um controle comum do windows para criar um controle ActiveX.  Subclassing um controle existente do windows é um modo rápido de desenvolver um controle ActiveX.  O novo controle terá os recursos de controle subclassed do windows, como paint e resposta a cliques do mouse.  O exemplo de [BOTÃO](../top/visual-cpp-samples.md) MFC controles ActiveX é um exemplo de subclassing um controle do windows.  
  
 A subclasse controlam as janelas, execute as seguintes tarefas:  
  
-   [Substituir as funções de membro de IsSubclassedControl e de PreCreateWindow de COleControl](#_core_overriding_issubclassedcontrol_and_precreatewindow)  
  
-   [Modifique a função de membro de OnDraw](#_core_modifying_the_ondraw_member_function)  
  
-   [Manipular todas as mensagens do controle ActiveX \(\) OCM refletidas no controle](#_core_handling_reflected_window_messages)  
  
    > [!NOTE]
    >  Muito esse trabalho é feito para você pelo assistente de controle ActiveX se você selecionar o controle a ser subclassed usando a lista suspensa de **Select Parent Window Class** na página de **Control Settings** .  
  
 Consulte o artigo da Base de Dados de Conhecimento Q243454 para obter mais informações sobre como subclassing um controle.  
  
##  <a name="_core_overriding_issubclassedcontrol_and_precreatewindow"></a> Substituindo IsSubclassedControl e PreCreateWindow  
 Para substituir `PreCreateWindow` e `IsSubclassedControl`, adicione as seguintes linhas de código na seção de `protected` de declaração da classe de controle:  
  
 [!code-cpp[NVC_MFC_AxSub#1](../mfc/codesnippet/CPP/mfc-activex-controls-subclassing-a-windows-control_1.h)]  
  
 No arquivo de implementação de controle \(.CPP\), adicione as seguintes linhas de código para implementar as duas funções substituídas:  
  
 [!code-cpp[NVC_MFC_AxSub#2](../mfc/codesnippet/CPP/mfc-activex-controls-subclassing-a-windows-control_2.cpp)]  
  
 Observe que, neste exemplo, o windows alterações o controle são especificadas em `PreCreateWindow`.  No entanto, todos os controles padrão do windows podem ser subclassed.  Para obter mais informações sobre os controles padrão do windows, consulte [Controles](../mfc/controls-mfc.md).  
  
 Ao subclassing o windows controle, talvez você queira especificar o estilo específico da janela**WS\_**\(\) ou os sinalizadores estendidos de estilo da janela**WS\_EX\_**\(\) a serem usados na criação da janela de controle.  Você pode definir valores para esses parâmetros da função de membro de `PreCreateWindow` alterando **cs.style** e os campos de estrutura de **cs.dwExStyle** .  As alterações nesses campos devem ser feitas com uma operação de `OR` , para preservar os sinalizadores de opção que são definidos pela classe `COleControl`.  Por exemplo, se o controle subclassing o controle de BOTÃO e você desejar controle a ser exibido como uma caixa de seleção, insira a seguinte linha de código na implementação de `CSampleCtrl::PreCreateWindow`, antes de retorno:  
  
 [!code-cpp[NVC_MFC_AxSub#3](../mfc/codesnippet/CPP/mfc-activex-controls-subclassing-a-windows-control_3.cpp)]  
  
 Essa operação adiciona o sinalizador de estilo de **BS\_CHECKBOX** , deixando o sinalizador de estilo padrão \(**WS\_CHILD**\) da classe `COleControl` intacta.  
  
##  <a name="_core_modifying_the_ondraw_member_function"></a> Alterando a função de membro de OnDraw  
 Se você deseja que o controle subclassed para manter a mesma aparência que o controle do windows correspondente, a função de membro de `OnDraw` para o controle deve conter apenas uma chamada à função de membro de `DoSuperclassPaint` , como no exemplo a seguir:  
  
 [!code-cpp[NVC_MFC_AxSub#4](../mfc/codesnippet/CPP/mfc-activex-controls-subclassing-a-windows-control_4.cpp)]  
  
 A função de membro de `DoSuperclassPaint` , implementada por `COleControl`, use o procedimento da janela de controle do windows para desenhar o controle no contexto especificado de dispositivo, dentro do retângulo delimitador.  Isso torna o controle visível mesmo quando não está ativa.  
  
> [!NOTE]
>  A função de membro de `DoSuperclassPaint` funcionará apenas a esses tipos de controle que permitem que um contexto de dispositivo é passado como **wParam** de uma mensagem de `WM_PAINT` .  Isso inclui alguns dos controles padrão do windows, como **SCROLLBAR** e **BOTÃO**, e todos os controles comuns.  Para os controles que não dão suporte a esse comportamento, forneça seu próprio código para exibir corretamente um controle inativo.  
  
##  <a name="_core_handling_reflected_window_messages"></a> Tratando mensagens refletidas na janela  
 Os controles do windows geralmente determinadas enviam mensagens da janela para a janela pai.  Algumas dessas mensagens, como **WM\_COMMAND**, fornecem a notificação de uma ação pelo usuário.  Outro, como `WM_CTLCOLOR`, e são usadas para obter as informações da janela pai.  Um controle ActiveX geralmente se comunica com a janela pai por outros meios.  As notificações são comunicadas acionando os eventos \(que enviam notificações de eventos\), e as informações sobre o contêiner do controle é obtida acessando as propriedades ou do contêiner.  Como essas técnicas de comunicação existirem, os contêineres do controle ActiveX não são esperadas para processar nenhuma mensagem da janela enviada pelo controle.  
  
 Para impedir que o contêiner recebe as mensagens da janela enviadas por um controle subclassed do windows, `COleControl` cria uma janela adicional para servir como o pai do controle.  Essa janela adicional, chamada “refletora”, é criada apenas para um controle ActiveX que as subclasses o windows para controlar e tem o mesmo tamanho e posição como a janela de controle.  Mensagens na janela das interseções de janela refletora determinas e os envia de volta ao controle.  O controle, no procedimento de janela, poderá processar essas mensagens refletidas tomando as ações apropriadas para um controle ActiveX \(por exemplo, acionando um evento\).  Consulte [IDs refletidas de mensagem da janela](../mfc/reflected-window-message-ids.md) para obter uma lista de mensagens interceptadas do windows e suas mensagens refletidas correspondentes.  
  
 Um contêiner do controle ActiveX pode ser criado para executar a reflexão de mensagem própria, eliminando a necessidade de `COleControl` crie a janela refletora e reduzindo a sobrecarga de tempo de execução para um controle subclassed do windows.  `COleControl` detecta se o contêiner da suporte a esse recurso verificando se há uma propriedade de ambiente de MessageReflect com um valor de **Verdadeiro**.  
  
 Para tratar uma mensagem refletida na janela, adicione uma entrada para mapa da mensagem de controle e implementar uma função de manipulador.  Como as mensagens não são refletidas parte do conjunto padrão de mensagens definidas pelo windows, a exibição da classe não oferece suporte para adicionar esses manipuladores de mensagem.  No entanto, não é difícil adicionar manualmente um manipulador.  
  
 Para adicionar um manipulador de mensagem para uma mensagem refletida da janela manualmente faça o seguinte:  
  
-   Na classe do controle. O arquivo de H, declara uma função de manipulador.  A função deve ter um tipo de retorno de **LRESULT** e dois parâmetros, com tipos **WPARAM** e **LPARAM**, respectivamente.  Por exemplo:  
  
     [!code-cpp[NVC_MFC_AxSub#5](../mfc/codesnippet/CPP/mfc-activex-controls-subclassing-a-windows-control_5.h)]  
    [!code-cpp[NVC_MFC_AxSub#6](../mfc/codesnippet/CPP/mfc-activex-controls-subclassing-a-windows-control_6.h)]  
  
-   No arquivo da classe .CPP de controle, adicione uma entrada de `ON_MESSAGE` no mapa da mensagem.  Os parâmetros desta entrada devem ser o identificador de mensagem e o nome da função do manipulador.  Por exemplo:  
  
     [!code-cpp[NVC_MFC_AxSub#7](../mfc/codesnippet/CPP/mfc-activex-controls-subclassing-a-windows-control_7.cpp)]  
  
-   Também no arquivo de .CPP, implemente a função de membro de **OnOcmCommand** para processar a mensagem refletida.  Os parâmetros de **wParam** e de **lParam** são iguais aos da mensagem original da janela.  
  
 Para obter um exemplo de como as mensagens são refletidas processadas, consulte o exemplo de [BOTÃO](../top/visual-cpp-samples.md)MFC controles ActiveX.  Demonstra um manipulador de **OnOcmCommand** que detecta o código de notificação de **BN\_CLICKED** e responder acionando \(\) enviar um evento clique em.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)