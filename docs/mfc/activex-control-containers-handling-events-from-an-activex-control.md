---
title: "Cont&#234;ineres de controle ActiveX: manipulando eventos a partir de um controle ActiveX | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Contêineres de controle ActiveX [C++], coletores de eventos"
  - "Controles ActiveX [C++], eventos"
  - "Macro BEGIN_EVENTSINK_MAP"
  - "Macro END_EVENTSINK_MAP, usando"
  - "manipuladores de eventos [C++], Controles ActiveX"
  - "tratamento de evento [C++], Controles ActiveX"
  - "eventos [C++], Controles ActiveX"
  - "Macro ON_EVENT"
ms.assetid: f9c106db-052f-4e32-82ad-750646aa760b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres de controle ActiveX: manipulando eventos a partir de um controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve usando a janela Propriedades para instalar manipuladores de eventos para controles ActiveX em um contêiner do controle ActiveX.  Os manipuladores de eventos são usados para receber notificações \(\) do controle de certos eventos e executar qualquer ação na resposta.  Essa notificação é chamada “” acionamento do evento.  
  
> [!NOTE]
>  Este artigo usa um contêiner diálogo\- baseado Contêiner denominado projeto do controle ActiveX e um controle inserido denominado Circ como exemplos nos procedimentos e em código.  
  
 Usando os eventos botão na janela Propriedades, você pode criar um mapa dos eventos que podem ocorrer em seu aplicativo de contêiner do controle ActiveX.  Esse mapa, chamado de “um mapa coletor de eventos,” é criado e mantido pelo Visual C\+\+ quando você adicionar manipuladores de eventos à classe do contêiner do controle.  Cada manipulador de eventos, implementado com uma entrada do mapa de evento, mapeia um evento específico a uma função de membro do manipulador de eventos do contêiner.  Essa função do manipulador de eventos é chamada quando o evento especificado é acionado pelo objeto do controle ActiveX.  
  
 Para obter mais informações sobre mapas de coletor de eventos, consulte [Mapas de coletor de eventos](../mfc/reference/event-sink-maps.md)*na referência da biblioteca da classe*.  
  
##  <a name="_core_event_handler_modifications_to_the_project"></a> Alterações de manipulador de eventos ao projeto  
 Quando você usa a janela Propriedades para adicionar manipuladores de eventos, um mapa de coletor de eventos é declarado e definido em seu projeto.  As instruções a seguir são adicionadas ao arquivo de controle .CPP a primeira vez que um manipulador de eventos é adicionado.  Esse código a seguir declara um mapa de coletor de eventos para a classe da caixa de diálogo \(nesse caso, `CContainerDlg`\):  
  
 [!code-cpp[NVC_MFC_AxCont#8](../mfc/codesnippet/CPP/activex-control-containers-handling-events-from-an-activex-control_1.cpp)]  
[!code-cpp[NVC_MFC_AxCont#9](../mfc/codesnippet/CPP/activex-control-containers-handling-events-from-an-activex-control_2.cpp)]  
  
 Como você usa a janela Propriedades para adicionar eventos, uma entrada de mapa do evento \(`ON_EVENT`\) é adicionada ao mapa do coletor de eventos e um manipulador de eventos que a função é adicionada ao arquivo de implementação do contêiner \(.CPP\).  
  
 O exemplo a seguir declara um manipulador de eventos, `OnClickInCircCtrl`chamado, para o evento de **ClickIn** de controle de Circ:  
  
 [!code-cpp[NVC_MFC_AxCont#10](../mfc/codesnippet/CPP/activex-control-containers-handling-events-from-an-activex-control_3.cpp)]  
  
 Além disso, o seguinte modelo é adicionado ao arquivo de implementação da classe de `CContainerDlg` \(.CPP\) para a função de membro do manipulador de eventos:  
  
 [!code-cpp[NVC_MFC_AxCont#11](../mfc/codesnippet/CPP/activex-control-containers-handling-events-from-an-activex-control_4.cpp)]  
  
 Para obter mais informações sobre macros de coletor de eventos, consulte [Mapas de coletor de eventos](../mfc/reference/event-sink-maps.md)*na referência da biblioteca da classe*.  
  
#### Para criar uma função de manipulador de eventos  
  
1.  Em vez da classe, selecione a classe da caixa de diálogo que contém o controle ActiveX.  Para esse exemplo, use `CContainerDlg`.  
  
2.  Na janela Propriedades, clique no botão **Eventos**.  
  
3.  Na janela Propriedades, selecione a ID do controle ActiveX inserido.  Para esse exemplo, use `IDC_CIRCCTRL1`.  
  
     A janela Propriedades exibe uma lista de eventos que podem ser acionados pelo controle ActiveX inserido.  Qualquer função de membro mostrada em negrito já tem as funções do manipulador atribuídas a eles.  
  
4.  Selecione o evento que você deseja a classe da caixa de diálogo para tratar.  Para este exemplo, **Clicar**selecione.  
  
5.  Na caixa de listagem suspensa à direita, selecione **\<Add\> ClickCircctrl1**.  
  
6.  Clique duas vezes na nova função do manipulador de exibição da classe para saltar para o código do manipulador de eventos no arquivo de implementação\) \(.CPP de `CContainerDlg`.  
  
## Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)