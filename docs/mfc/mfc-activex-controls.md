---
title: Controles ActiveX do MFC | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- MFC ActiveX Controls (MFC)
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b94172d57bc21e7f747a5d0986ef28dbfb80e481
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46428636"
---
# <a name="mfc-activex-controls"></a>Controles ActiveX MFC

Um controle ActiveX é um componente de software reutilizável baseado no COM (Component Object Model) que dá suporte a uma ampla variedade de funcionalidades OLE e que pode ser personalizado para atender às várias necessidades de software.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](activex-controls.md).

Controles ActiveX são projetados para uso em contêineres de controle ActiveX comuns e na Internet e, em páginas da Web. Você pode criar controles ActiveX com o MFC, descrito aqui, ou com o [biblioteca ATL (Active Template)](../atl/active-template-library-atl-concepts.md).

Um controle ActiveX pode desenhar a próprio em sua própria janela, respondem a eventos (como cliques do mouse) e ser gerenciada por meio de uma interface que inclui propriedades e métodos semelhantes aos descritos em objetos de automação.

Esses controles podem ser desenvolvidos para muitos usos, como o acesso de banco de dados, dados de monitoramento ou representação gráfica. Além de sua portabilidade, os controles ActiveX dão suporte a recursos não disponíveis anteriormente aos controles ActiveX, como compatibilidade com os contêineres OLE existentes e a capacidade de integrar seus menus com os menus de contêiner OLE. Além disso, um controle ActiveX totalmente compatível com a automação, que permite que o controle para expor as propriedades de leitura \ gravação e um conjunto de métodos que podem ser chamados pelo usuário do controle.

Você pode criar controles ActiveX sem janelas e controles que só criar uma janela quando eles se tornar ativos. Controles sem janelas acelerar a exibição do seu aplicativo e torná-lo possível ter controles transparentes e não retangulares. Você também pode carregar propriedades do controle ActiveX de forma assíncrona.

Um controle ActiveX é implementado como um servidor em processo (geralmente um objeto pequeno) que pode ser usado em qualquer contêiner OLE. Observe que a funcionalidade completa de um controle ActiveX está disponível somente quando usado dentro de um contêiner OLE projetado para estar ciente dos controles ActiveX. Ver [controles ActiveX de porta para outros aplicativos](../mfc/containers-for-activex-controls.md) para obter uma lista de contêineres que dão suporte a controles ActiveX. Esse tipo de contêiner, daqui em diante chamado de "recipiente de controle", pode operar um controle ActiveX usando métodos e propriedades do controle e recebe notificações do controle ActiveX na forma de eventos. A figura a seguir demonstra essa interação.

![Interação de contêiner de controle ActiveX e o controle](../mfc/media/vc37221.gif "vc37221") interação entre um contêiner do controle ActiveX e o controle ActiveX em janelas

Para obter algumas informações recentes sobre como otimizar seus controles ActiveX, consulte [controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md).

Para criar um controle ActiveX do MFC, consulte [criar um projeto do controle ActiveX](../mfc/reference/mfc-activex-control-wizard.md).

Para obter mais informações, consulte:

- [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

- [Documentos ativos](../mfc/active-documents.md)

- [Noções básicas sobre os controles ActiveX](/windows/desktop/com/activex-controls)

- [Atualizando um controle ActiveX existente a ser usado na Internet](../mfc/upgrading-an-existing-activex-control.md)

##  <a name="_core_basic_components_of_an_activex_control"></a> Componentes básicos de um controle ActiveX

Um controle ActiveX usa vários elementos de programação para interagir com eficiência com um contêiner de controle e com o usuário. Esses são a classe [COleControl](../mfc/reference/colecontrol-class.md), um conjunto de funções de acionamento do evento e um despacho de mapa.

Cada objeto de controle ActiveX que desenvolve herda um poderoso conjunto de recursos de sua classe base do MFC, `COleControl`. Esses recursos incluem ativação in-loco e a lógica de automação. `COleControl` pode fornecer o objeto de controle com a mesma funcionalidade que um objeto de janela MFC, além da capacidade para disparar eventos. `COleControl` também pode fornecer [controles sem janelas](../mfc/providing-windowless-activation.md), que dependem de seu contêiner para obter ajuda com algumas das funcionalidades de uma janela fornece (captura do mouse, o foco do teclado, rolagem), mas oferecem muito mais rápido do vídeo.

Porque a classe control deriva `COleControl`, ele herda o recurso para enviar ou "fire", mensagens, chamadas de eventos, para o contêiner de controle quando determinadas condições forem atendidas. Esses eventos são usados para notificar o contêiner de controle quando algo importante acontece no controle. Você pode enviar informações adicionais sobre um evento para o contêiner de controle anexando parâmetros para o evento. Para obter mais informações sobre eventos de controle ActiveX, consulte o artigo [controles ActiveX MFC: eventos](../mfc/mfc-activex-controls-events.md).

O elemento final é um mapa de expedição, o que é usado para expor um conjunto de funções (chamadas de métodos) e atributos (chamados propriedades) para o usuário do controle. Propriedades permitem que o contêiner de controle ou o usuário do controle para manipular o controle de várias maneiras. O usuário pode alterar a aparência do controle, alterar certos valores de controle ou fazer solicitações do controle, como acessar uma parte específica de dados que mantém o controle. Essa interface é determinada pelo desenvolvedor do controle e é definida usando **modo de exibição de classe**. Para obter mais informações sobre propriedades e métodos do controle ActiveX, consulte os artigos [controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md) e [propriedades](../mfc/mfc-activex-controls-properties.md).

##  <a name="_core_interaction_between_controls_with_windows_and_activex_control_containers"></a> Interação entre os controles com o Windows e contêineres de controle ActiveX

Quando um controle é usado dentro de um contêiner de controle, ele usa dois mecanismos para se comunicar: ele expõe métodos e propriedades, e ele aciona eventos. A figura a seguir demonstra como esses dois mecanismos são implementados.

![Controle ActiveX se comunica com seu contêiner](../mfc/media/vc37222.gif "vc37222") comunicação entre um contêiner do controle ActiveX e um controle ActiveX

A figura anterior também ilustra como as outras interfaces OLE (além de automação e eventos) são tratados por controles.

Todos os de comunicação de um controle com o contêiner é executada por `COleControl`. Para lidar com algumas das solicitações do contêiner, `COleControl` irá chamar funções que são implementadas na classe de controle de membro. Todos os métodos e algumas propriedades são tratadas dessa forma. Sua classe do controle também pode iniciar a comunicação com o contêiner chamando funções de membro de `COleControl`. Os eventos são disparados dessa maneira.

##  <a name="_core_active_and_inactive_states_of_an_activex_control"></a> Estados ativo e inativo de um controle ActiveX

Um controle tem dois estados básicos: ativas e inativas. Tradicionalmente, esses estados foram diferenciados por se o controle tinha uma janela. Um controle ativo tinha uma janela; um controle inativo não faziam isso. Com a introdução da ativação sem janelas, essa distinção não é universal, mas ainda se aplica a muitos controles.

Quando um [controle sem janelas](../mfc/providing-windowless-activation.md) vai ativo, ele invoca a captura do mouse, o foco do teclado, rolagem e outros serviços da janela de seu contêiner. Você também pode [fornecem a interação do mouse para controles inativos](../mfc/providing-mouse-interaction-while-inactive.md), bem como criar controles que [Aguarde até ser ativado para criar uma janela](../mfc/turning-off-the-activate-when-visible-option.md).

Quando um controle com uma janela fica ativo, é capaz de interagir completamente com o contêiner de controle, o usuário e o Windows. A figura a seguir demonstra os caminhos de comunicação entre o controle ActiveX, o contêiner de controle e o sistema operacional.

![Msg no Active Directory controle ActiveX em janelas de processamento](../mfc/media/vc37223.gif "vc37223") processamento de mensagens do Windows em um controle ActiveX em janelas (ao Active Directory)

##  <a name="_core_serializing_activex_elements"></a> Serialização

A capacidade de serializar os dados, às vezes chamados de persistência, permite que o controle gravar o valor de suas propriedades para o armazenamento persistente. Controles podem ser recriados, em seguida, lendo o estado do objeto do armazenamento.

Observe que um controle não é responsável por obter acesso à mídia de armazenamento. Em vez disso, o contêiner do controle é responsável por fornecer o controle com uma mídia de armazenamento para usar nos momentos apropriados. Para obter mais informações sobre serialização, consulte o artigo [controles ActiveX MFC: serializando](../mfc/mfc-activex-controls-serializing.md). Para obter informações sobre como otimizar a serialização, consulte [otimizando persistência e inicialização](../mfc/optimizing-persistence-and-initialization.md) em controles ActiveX: otimização.

##  <a name="_core_installing_activex_control_classes_and_tools"></a> Instalando ferramentas e Classes de controle ActiveX

Quando você instala o Visual C++, o ActiveX do MFC controlam as classes e varejo e depurar o controle ActiveX DLLs de tempo de execução são instalados automaticamente se os controles ActiveX são selecionados na instalação (eles são selecionados por padrão).

Por padrão, as ferramentas e classes de controle ActiveX são instaladas nos seguintes subdiretórios \Program Files\Microsoft Visual Studio .NET:

- **\Common7\Tools**

     Contém os arquivos do contêiner de teste (TstCon32.exe, bem como seus arquivos de Ajuda).

- **\Vc7\atlmfc\include**

     Contém os arquivos de inclusão necessários para o desenvolvimento de controles ActiveX com o MFC

- **\Vc7\atlmfc\src\mfc**

     Contém o código-fonte para classes específicas de controle ActiveX no MFC

- **\Vc7\atlmfc\lib**

     Contém as bibliotecas necessárias para desenvolver controles ActiveX com o MFC

Também há exemplos para controles ActiveX do MFC. Para obter mais informações sobre esses exemplos, consulte [exemplos de controles: MFC-Based os controles ActiveX](../visual-cpp-samples.md)

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
