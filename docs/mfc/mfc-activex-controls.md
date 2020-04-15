---
title: Controles ActiveX MFC
ms.date: 11/19/2018
f1_keywords:
- MFC ActiveX Controls (MFC)
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
ms.openlocfilehash: e9cc38eebed0b1f8e0932e89ef1452261aefd7dd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365435"
---
# <a name="mfc-activex-controls"></a>Controles ActiveX MFC

Um controle ActiveX é um componente de software reutilizável baseado no COM (Component Object Model) que dá suporte a uma ampla variedade de funcionalidades OLE e que pode ser personalizado para atender às várias necessidades de software.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [ActiveX Controls](activex-controls.md).

Os controles ActiveX são projetados para uso tanto em contêineres de controle ActiveX comuns quanto na Internet, em páginas da World Wide Web. Você pode criar controles ActiveX com MFC, descrito aqui, ou com a [Active Template Library (ATL)](../atl/active-template-library-atl-concepts.md).

Um controle ActiveX pode desenhar-se em sua própria janela, responder a eventos (como cliques do mouse) e ser gerenciado através de uma interface que inclui propriedades e métodos semelhantes aos de objetos de Automação.

Esses controles podem ser desenvolvidos para muitos usos, como acesso a banco de dados, monitoramento de dados ou gráficos. Além de sua portabilidade, o ActiveX controla recursos que antes não estavam disponíveis nos controles do ActiveX, como compatibilidade com contêineres OLE existentes e a capacidade de integrar seus menus com os menus de contêineres OLE. Além disso, um controle ActiveX suporta totalmente a Automação, que permite que o controle exponha propriedades de leitura\gravação e um conjunto de métodos que podem ser chamados pelo usuário de controle.

Você pode criar controles e controles ActiveX sem janelas que só criam uma janela quando eles se tornam ativos. Controles sem janelas aceleram a exibição do seu aplicativo e tornam possível ter controles transparentes e não retangulares. Você também pode carregar as propriedades de controle ActiveX de forma assíncrona.

Um controle ActiveX é implementado como um servidor em processo (tipicamente um objeto pequeno) que pode ser usado em qualquer contêiner OLE. Observe que a funcionalidade completa de um controle ActiveX só está disponível quando usada dentro de um contêiner OLE projetado para estar ciente dos controles ActiveX. Consulte [Os controles Port ActiveX para outros aplicativos](../mfc/containers-for-activex-controls.md) para obter uma lista de contêineres que suportam controles ActiveX. Este tipo de contêiner, doravante chamado de "contêiner de controle", pode operar um controle ActiveX usando as propriedades e métodos do controle, e recebe notificações do controle ActiveX na forma de eventos. A figura a seguir demonstra essa interação.

![Interplay do contêiner de controle ActiveX e controle](../mfc/media/vc37221.gif "Interplay do contêiner de controle ActiveX e controle") <br/>
Interação entre um contêiner de controle ActiveX e um controle ActiveX com janelas

Para obter algumas informações recentes sobre como otimizar seus controles ActiveX, consulte [Controles MFC ActiveX: Otimização](../mfc/mfc-activex-controls-optimization.md).

Para criar um controle MFC ActiveX, consulte [Criar um projeto de controle ActiveX](../mfc/reference/mfc-activex-control-wizard.md).

Para obter mais informações, consulte:

- [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

- [Documentos ativos](../mfc/active-documents.md)

- [Entendendo controles ActiveX](/windows/win32/com/activex-controls)

- [Atualizando um controle ActiveX existente para ser usado na Internet](../mfc/upgrading-an-existing-activex-control.md)

## <a name="basic-components-of-an-activex-control"></a><a name="_core_basic_components_of_an_activex_control"></a>Componentes básicos de um controle ActiveX

Um controle ActiveX usa vários elementos programáticos para interagir eficientemente com um recipiente de controle e com o usuário. Estes são [coleControl](../mfc/reference/colecontrol-class.md)de classe, um conjunto de funções de disparo de eventos e um mapa de despacho.

Cada objeto de controle ActiveX que você desenvolve herda um `COleControl`poderoso conjunto de recursos de sua classe base MFC, . Esses recursos incluem ativação no local e lógica de automação. `COleControl`pode fornecer ao objeto de controle a mesma funcionalidade que um objeto de janela MFC, além da capacidade de disparar eventos. `COleControl`também pode fornecer [controles sem janelas,](../mfc/providing-windowless-activation.md)que dependem de seu contêiner para ajudar com algumas das funcionalidades que uma janela oferece (captura do mouse, foco do teclado, rolagem), mas oferecem uma exibição muito mais rápida.

Como a classe de `COleControl`controle deriva, herda a capacidade de enviar, ou "fogo", mensagens, chamadas de eventos, para o recipiente de controle quando determinadas condições são atendidas. Esses eventos são usados para notificar o recipiente de controle quando algo importante acontece no controle. Você pode enviar informações adicionais sobre um evento para o contêiner de controle anexando parâmetros ao evento. Para obter mais informações sobre eventos de controle ActiveX, consulte o artigo [MFC ActiveX Controls: Events](../mfc/mfc-activex-controls-events.md).

O elemento final é um mapa de despacho, que é usado para expor um conjunto de funções (chamados métodos) e atributos (chamados propriedades) ao usuário de controle. As propriedades permitem que o recipiente de controle ou o usuário de controle manipulem o controle de várias maneiras. O usuário pode alterar a aparência do controle, alterar certos valores do controle ou fazer solicitações do controle, como acessar um determinado pedaço de dados que o controle mantém. Esta interface é determinada pelo desenvolvedor de controle e é definida usando **o Class View**. Para obter mais informações sobre métodos e propriedades de controle ActiveX, consulte os artigos [MFC ActiveX Controls: Methods](../mfc/mfc-activex-controls-methods.md) and [Properties](../mfc/mfc-activex-controls-properties.md).

## <a name="interaction-between-controls-with-windows-and-activex-control-containers"></a><a name="_core_interaction_between_controls_with_windows_and_activex_control_containers"></a>Interação entre controles com windows e recipientes de controle ActiveX

Quando um controle é usado dentro de um recipiente de controle, ele usa dois mecanismos para se comunicar: expõe propriedades e métodos, e dispara eventos. A figura a seguir demonstra como esses dois mecanismos são implementados.

![O controle ActiveX se comunica com seu contêiner](../mfc/media/vc37222.gif "O controle ActiveX se comunica com seu contêiner") <br/>
Comunicação entre um contêiner de controle ActiveX e um controle ActiveX

A figura anterior também ilustra como outras interfaces OLE (além de automação e eventos) são tratadas por controles.

Toda a comunicação de um controle `COleControl`com o recipiente é realizada por . Para atender algumas das solicitações `COleControl` do contêiner, chamará as funções dos membros que são implementadas na classe de controle. Todos os métodos e algumas propriedades são tratados dessa forma. A classe do seu controle também pode iniciar a `COleControl`comunicação com o contêiner chamando as funções de membro de . Os eventos são disparados desta maneira.

## <a name="active-and-inactive-states-of-an-activex-control"></a><a name="_core_active_and_inactive_states_of_an_activex_control"></a>Estados ativos e inativos de um controle ActiveX

Um controle tem dois estados básicos: ativo e inativo. Tradicionalmente, esses estados se distinguiam por se o controle tinha uma janela. Um controle ativo tinha uma janela; um controle inativo não. Com a introdução da ativação sem janelas, essa distinção não é mais universal, mas ainda se aplica a muitos controles.

Quando um [controle sem janelas](../mfc/providing-windowless-activation.md) fica ativo, ele invoca a captura do mouse, o foco do teclado, a rolagem e outros serviços de janela de seu contêiner. Você também pode [fornecer interação do mouse com controles inativos,](../mfc/providing-mouse-interaction-while-inactive.md)bem como criar controles que esperam até serem [ativados para criar uma janela](../mfc/turning-off-the-activate-when-visible-option.md).

Quando um controle com uma janela se torna ativo, ele é capaz de interagir totalmente com o contêiner de controle, o usuário e o Windows. A figura abaixo demonstra os caminhos de comunicação entre o controle ActiveX, o contêiner de controle e o sistema operacional.

![Processamento de Msg no controle Active Windowsed Active ActiveX](../mfc/media/vc37223.gif "Processamento de Msg no controle Active Windowsed Active ActiveX") <br/>
Processamento de mensagens do Windows em um controle ActiveX com janelas (quando ativo)

## <a name="serialization"></a><a name="_core_serializing_activex_elements"></a>Serialização

A capacidade de serializar dados, às vezes referido como persistência, permite que o controle escreva o valor de suas propriedades para armazenamento persistente. Os controles podem então ser recriados lendo o estado do objeto a partir do armazenamento.

Observe que um controle não é responsável por obter acesso ao meio de armazenamento. Em vez disso, o recipiente do controle é responsável por fornecer ao controle um meio de armazenamento para usar nos momentos apropriados. Para obter mais informações sobre serialização, consulte o artigo [MFC ActiveX Controls: Serializing](../mfc/mfc-activex-controls-serializing.md). Para obter informações sobre como otimizar a serialização, consulte [Otimizando a persistência e a inicialização](../mfc/optimizing-persistence-and-initialization.md) em Controles ActiveX: Otimização.

## <a name="installing-activex-control-classes-and-tools"></a><a name="_core_installing_activex_control_classes_and_tools"></a>Instalando classes e ferramentas de controle ActiveX

Quando você instala o Visual C++, as classes de controle MFC ActiveX e as DLLs de controle de varejo e depuração do ActiveX são instaladas automaticamente se os controles ActiveX forem selecionados na configuração (eles são selecionados por padrão).

Por padrão, as classes e ferramentas de controle ActiveX são instaladas nos seguintes subdiretórios em \Arquivos do programa\Microsoft Visual Studio .NET:

- **\Common7\Ferramentas**

   Contém os arquivos do Contêiner de Teste (TstCon32.exe, bem como seus arquivos de Ajuda).

- **\Vc7\atlmfc\include**

   Contém os arquivos necessários para desenvolver controles ActiveX com MFC

- **\Vc7\atlmfc\src\mfc**

   Contém o código-fonte para classes de controle ActiveX específicas no MFC

- **\Vc7\atlmfc\lib**

   Contém as bibliotecas necessárias para desenvolver controles ActiveX com MFC

Há também amostras para controles MFC ActiveX. Para obter mais informações sobre essas amostras, consulte [Controls Samples: MFC-Based ActiveX Controls](../overview/visual-cpp-samples.md)

## <a name="see-also"></a>Confira também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)
