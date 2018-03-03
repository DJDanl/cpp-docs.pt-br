---
title: "Contêineres de controle ActiveX: Manipulando eventos a partir de um controle ActiveX | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 84e1571f400297584e12a40dfd2bfcc3c0b525d2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="activex-control-containers-handling-events-from-an-activex-control"></a>Contêineres de controle ActiveX: manipulando eventos a partir de um controle ActiveX
Este artigo aborda usando a janela Propriedades para instalar os manipuladores de eventos para controles ActiveX em um contêiner de controle ActiveX. Os manipuladores de eventos são usados para receber notificações (de controle) de determinados eventos e executam alguma ação em resposta. Essa notificação é chamada de "disparo" do evento.  
  
> [!NOTE]
>  Este artigo usa um baseado na caixa de diálogo ActiveX controle recipiente projeto chamado recipiente e um controle inserido chamado c como exemplos de procedimentos e código.  
  
 Usando o botão de eventos na janela Propriedades, você pode criar um mapa de eventos que podem ocorrer no seu aplicativo de contêiner de controle ActiveX. Este mapa, chamado de um "mapa de coletor de eventos', é criado e mantido pelo Visual C++, quando você adicionar manipuladores de eventos para a classe de contêiner de controle. Cada manipulador de eventos, implementado com uma entrada de mapa de evento, um evento específico é mapeado para uma função de membro de manipulador de eventos do contêiner. Essa função de manipulador de eventos é chamada quando o evento especificado é acionado por objeto de controle ActiveX.  
  
 Para obter mais informações sobre mapas de coleta de eventos, consulte [mapas de coleta de eventos](../mfc/reference/event-sink-maps.md) no *referência da biblioteca de classe*.  
  
##  <a name="_core_event_handler_modifications_to_the_project"></a>Modificações de manipulador de eventos para o projeto  
 Quando você usar a janela Propriedades para adicionar manipuladores de eventos, um mapa de coletor de eventos é declarado e definido no seu projeto. As instruções a seguir são adicionadas ao controle. Arquivo CPP na primeira vez que um manipulador de eventos é adicionado. Esse código declara um mapa de coletor de evento para a classe de caixa de diálogo (nesse caso, `CContainerDlg`):  
  
 [!code-cpp[NVC_MFC_AxCont#8](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_1.cpp)]  
[!code-cpp[NVC_MFC_AxCont#9](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_2.cpp)]  
  
 Como usar a janela Propriedades para adicionar eventos, um evento de entrada do mapa (`ON_EVENT`) é adicionado para o mapa de coletor de evento e um manipulador de eventos função é adicionada a implementação do contêiner (. Arquivo CPP).  
  
 O exemplo a seguir declara um manipulador de eventos, chamado `OnClickInCircCtrl`, para o controle de c **ClickIn** evento:  
  
 [!code-cpp[NVC_MFC_AxCont#10](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_3.cpp)]  
  
 Além disso, o modelo a seguir é adicionado para o `CContainerDlg` implementação da classe (. Arquivo CPP) para a função de membro de manipulador de eventos:  
  
 [!code-cpp[NVC_MFC_AxCont#11](../mfc/codesnippet/cpp/activex-control-containers-handling-events-from-an-activex-control_4.cpp)]  
  
 Para obter mais informações sobre as macros de coletor de eventos, consulte [mapas de coleta de eventos](../mfc/reference/event-sink-maps.md) no *referência da biblioteca de classe*.  
  
#### <a name="to-create-an-event-handler-function"></a>Para criar uma função de manipulador de eventos  
  
1.  Exibição de classe, selecione a classe de caixa de diálogo que contém o controle ActiveX. Para este exemplo, use `CContainerDlg`.  
  
2.  Na janela Propriedades, clique o **eventos** botão.  
  
3.  Na janela Propriedades, selecione a ID do controle do controle ActiveX incorporado. Para este exemplo, use `IDC_CIRCCTRL1`.  
  
     A janela Propriedades exibe uma lista de eventos que podem ser acionados pelo controle ActiveX incorporado. Nenhuma função de membro mostrada em negrito já tem funções de manipulador atribuídas a ele.  
  
4.  Selecione o evento que você deseja que a classe de caixa de diálogo para tratar. Neste exemplo, selecione **clique**.  
  
5.  Na caixa de listagem suspensa à direita, selecione  **\<Adicionar > ClickCircctrl1**.  
  
6.  Clique duas vezes a nova função de manipulador de exibição de classe para saltar para o código de manipulador de eventos na implementação (. Arquivo CPP) de `CContainerDlg`.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

