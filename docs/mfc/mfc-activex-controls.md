---
title: Controles ActiveX MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: MFC ActiveX Controls (MFC)
dev_langs: C++
helpviewer_keywords:
- COleControl class [MFC], MFC ActiveX controls
- ActiveX controls [MFC], MFC
- containers [MFC], MFC ActiveX controls
- MFC ActiveX controls [MFC], serializing
- MFC ActiveX controls [MFC], containers
- serialization [MFC], MFC ActiveX controls
- dispatch maps [MFC], for MFC ActiveX controls
- MFC ActiveX controls [MFC], active/inactive state
- events [MFC], ActiveX controls
- MFC ActiveX controls [MFC]
ms.assetid: c911fb74-3afc-4bf3-a0f5-7922b14d9a1b
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e5351e7dca3c78b9709f183b8e1f6f9e7b2dc883
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="mfc-activex-controls"></a>Controles ActiveX MFC
Um controle ActiveX é um componente de software reutilizáveis com base no modelo COM (Component Object) que oferece suporte a uma ampla variedade de funcionalidades OLE e podem ser personalizadas para atender às várias necessidades de software. Controles ActiveX são projetados para uso em contêineres de controle ActiveX comuns e na Internet, em páginas da Web. Você pode criar controles ActiveX com MFC, descrito aqui, ou com o [biblioteca ATL (Active Template)](../atl/active-template-library-atl-concepts.md).  
  
 Um controle ActiveX pode desenhar a próprio em sua própria janela, responder a eventos (como cliques do mouse) e gerenciadas por meio de uma interface que inclui propriedades e métodos semelhantes aos objetos de automação.  
  
 Esses controles podem ser desenvolvidos para muitas funções, como acesso de banco de dados, dados de monitoramento ou gráficos. Além de seu portabilidade, controles ActiveX oferecem suporte a recursos não disponíveis anteriormente aos controles ActiveX, como compatibilidade com contêineres OLE existentes e a capacidade de integrar seus menus os menus de contêiner OLE. Além disso, um controle ActiveX totalmente oferece suporte a automação, que permite que o controle exponha as propriedades de leitura \ gravação e um conjunto de métodos que podem ser chamados pelo usuário de controle.  
  
 Você pode criar controles ActiveX sem janelas e controles que criarem apenas uma janela quando eles se torne ativos. Controles sem janelas acelerar a exibição do seu aplicativo e possibilitam que tem controles transparentes e não retangulares. Você também pode carregar propriedades do controle ActiveX de forma assíncrona.  
  
 Um controle ActiveX é implementado como um servidor em processo (normalmente um pequeno objeto) que pode ser usado em qualquer contêiner OLE. Observe que a funcionalidade completa de um controle ActiveX está disponível apenas quando usado dentro de um contêiner OLE deve estar ciente dos controles ActiveX. Consulte [controles ActiveX de porta para outros aplicativos](../mfc/containers-for-activex-controls.md) para obter uma lista de contêineres que dão suporte a controles ActiveX. Esse tipo de contêiner, daqui em diante chamado "contêiner de controle", pode operar um controle ActiveX usando métodos e propriedades do controle e recebe notificações do controle ActiveX na forma de eventos. A figura a seguir demonstra essa interação.  
  
 ![Interação de contêiner do controle ActiveX e controle](../mfc/media/vc37221.gif "vc37221")  
Interação entre um contêiner de controle ActiveX e o controle ActiveX em janelas  
  
 Para obter algumas informações recentes sobre como otimizar seus controles ActiveX, consulte [controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md).  
  
 Para criar um controle ActiveX MFC, consulte [criar um projeto de controle ActiveX](../mfc/reference/mfc-activex-control-wizard.md).  
  
 Para obter mais informações, consulte:  
  
-   [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)  
  
-   [Documentos ativos](../mfc/active-documents.md)  
  
-   [Noções básicas sobre controles ActiveX](http://msdn.microsoft.com/library/windows/desktop/ms693753)  
  
-   [Atualizando um controle ActiveX existente a ser usado na Internet](../mfc/upgrading-an-existing-activex-control.md)  
  
##  <a name="_core_basic_components_of_an_activex_control"></a>Componentes básicos de um controle ActiveX  
 Um controle ActiveX usa vários elementos de programação para interagir com eficiência com um contêiner de controle e o usuário. Esses são classe [COleControl](../mfc/reference/colecontrol-class.md), um conjunto de funções de acionamento do evento e a expedição de mapa.  
  
 Cada objeto de controle ActiveX desenvolver herda um conjunto avançado de recursos de sua classe base MFC, `COleControl`. Esses recursos incluem a ativação no local e a lógica de automação. `COleControl`pode fornecer o objeto de controle com a mesma funcionalidade de um objeto de janela MFC, além da capacidade para disparar eventos. `COleControl`também pode fornecer [controles sem janelas](../mfc/providing-windowless-activation.md), que dependem de seus contêineres para obter ajuda com algumas das funcionalidades de uma janela fornece (captura do mouse, o foco do teclado, rolando), mas oferece exibição muito mais rápida.  
  
 Porque a classe de controle deriva `COleControl`, ele herda a capacidade de enviar ou "incêndio," mensagens, chamado de eventos para o contêiner de controle quando determinadas condições forem atendidas. Esses eventos são usados para notificar o contêiner de controle quando algo importante acontece no controle. Você pode enviar informações adicionais sobre um evento para o contêiner de controle, anexando parâmetros para o evento. Para obter mais informações sobre eventos de controle ActiveX, consulte o artigo [controles ActiveX MFC: eventos](../mfc/mfc-activex-controls-events.md).  
  
 O elemento final é um mapa de expedição, que é usado para expor um conjunto de funções (chamadas de métodos) e atributos (chamados de propriedades) para o usuário do controle. Propriedades permitem que o contêiner de controle ou o usuário de controle para manipular o controle de várias maneiras. O usuário pode alterar a aparência do controle, alterar certos valores de controle ou fazer solicitações de controle, como acessar um segmento específico de dados que mantém o controle. Essa interface é determinado pelo desenvolvedor do controle e é definida usando **exibição de classe**. Para obter mais informações sobre propriedades e métodos do controle ActiveX, consulte os artigos [controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md) e [propriedades](../mfc/mfc-activex-controls-properties.md).  
  
##  <a name="_core_interaction_between_controls_with_windows_and_activex_control_containers"></a>Interação entre contêineres de controle ActiveX e controles com o Windows  
 Quando um controle é usado dentro de um contêiner de controle, ele usa dois mecanismos para se comunicar: expõe métodos e propriedades e dispara eventos. A figura a seguir demonstra como esses dois mecanismos são implementados.  
  
 ![Controle ActiveX se comunica com seu contêiner](../mfc/media/vc37222.gif "vc37222")  
Comunicação entre um contêiner de controle ActiveX e um controle ActiveX  
  
 A figura anterior também ilustra como as outras interfaces OLE (além de automação e eventos) são tratados por controles.  
  
 Todas a comunicação com o contêiner do controle é executada por `COleControl`. Para lidar com algumas das solicitações do contêiner, **COleControl** chamará membro funções que são implementadas na classe de controle. Todos os métodos e algumas propriedades são tratadas dessa maneira. Classe do controle também pode iniciar a comunicação com o contêiner chamando funções membro de `COleControl`. Os eventos são disparados dessa maneira.  
  
##  <a name="_core_active_and_inactive_states_of_an_activex_control"></a>Estados ativo e inativo de um controle ActiveX  
 Um controle tem dois estados básico: ativas e inativas. Tradicionalmente, esses estados foram diferenciados por se o controle tiver uma janela. Um controle ativo tinha uma janela. um controle inativo não faziam isso. Com a introdução da ativação sem janelas, essa diferença não é mais universal, mas ainda se aplica a vários controles.  
  
 Quando um [controle sem janelas](../mfc/providing-windowless-activation.md) fica ativo, ele chama a captura do mouse, o foco do teclado, rolar e outros serviços de janela de seu contêiner. Você também pode [fornecer interação de mouse para controles inativos](../mfc/providing-mouse-interaction-while-inactive.md), bem como criar controles que [Aguarde ativado para criar uma janela](../mfc/turning-off-the-activate-when-visible-option.md).  
  
 Quando um controle com uma janela se torna ativo, é capaz de interagir totalmente com o contêiner de controle, o usuário e o Windows. A figura a seguir demonstra os caminhos de comunicação entre o controle ActiveX, o contêiner de controle e o sistema operacional.  
  
 ![Msg active controle ActiveX em janelas de processamento](../mfc/media/vc37223.gif "vc37223")  
Processamento em um controle ActiveX em janelas (quando ativo) de mensagens do Windows  
  
##  <a name="_core_serializing_activex_elements"></a>Serialização  
 A capacidade de serializar dados, às vezes chamados de persistência, permite que o controle gravar o valor de suas propriedades para o armazenamento persistente. Em seguida, podem ser recriados controles lendo o estado do objeto do armazenamento.  
  
 Observe que um controle não é responsável por obter acesso à mídia de armazenamento. Em vez disso, o contêiner do controle é responsável por fornecer o controle com uma mídia de armazenamento para usar nos momentos apropriados. Para obter mais informações sobre serialização, consulte o artigo [controles ActiveX MFC: serializando](../mfc/mfc-activex-controls-serializing.md). Para obter informações sobre como otimizar a serialização, consulte [otimizando persistência e inicialização](../mfc/optimizing-persistence-and-initialization.md) em controles ActiveX: otimização.  
  
##  <a name="_core_installing_activex_control_classes_and_tools"></a>Instalando ferramentas e Classes de controle ActiveX  
 Quando você instala o Visual C++, o ActiveX MFC controlar classes e varejo e depurar um controle ActiveX DLLs de tempo de execução são instalados automaticamente se os controles ActiveX são selecionados na configuração (eles são selecionados por padrão).  
  
 Por padrão, as ferramentas e classes de controle ActiveX são instaladas nos seguintes subdiretórios em \Program Files\Microsoft Visual Studio .NET:  
  
-   **\Common7\Tools**  
  
     Contém os arquivos de contêiner de teste (TstCon32.exe, bem como seus arquivos de Ajuda).  
  
-   **\Vc7\atlmfc\include**  
  
     Contém os arquivos necessários para desenvolver controles ActiveX MFC  
  
-   **\Vc7\atlmfc\src\mfc**  
  
     Contém o código-fonte para classes específicas de controle ActiveX em MFC  
  
-   **\Vc7\atlmfc\lib**  
  
     Contém as bibliotecas necessárias para desenvolver controles ActiveX MFC  
  
 Também há exemplos para controles ActiveX MFC. Para obter mais informações sobre esses exemplos, consulte [controles exemplos: MFC-Based os controles ActiveX](../visual-cpp-samples.md)  
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
