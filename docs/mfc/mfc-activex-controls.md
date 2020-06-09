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
ms.openlocfilehash: 58af2dc59aa6287ad01ace41cca54e615c48c0b6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618088"
---
# <a name="mfc-activex-controls"></a>Controles ActiveX MFC

Um controle ActiveX é um componente de software reutilizável baseado no COM (Component Object Model) que dá suporte a uma ampla variedade de funcionalidades OLE e que pode ser personalizado para atender às várias necessidades de software.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](activex-controls.md).

Os controles ActiveX são projetados para uso em contêineres de controle ActiveX comuns e na Internet, em World Wide Web páginas. Você pode criar controles ActiveX com o MFC, descrito aqui ou com o [Active Template Library (ATL)](../atl/active-template-library-atl-concepts.md).

Um controle ActiveX pode se desenhar em sua própria janela, responder a eventos (como cliques do mouse) e ser gerenciado por meio de uma interface que inclui propriedades e métodos semelhantes aos em objetos de automação.

Esses controles podem ser desenvolvidos para muitos usos, como o acesso ao banco de dados, o data Monitoring ou o gráfico. Além de sua portabilidade, os controles ActiveX dão suporte a recursos que anteriormente não estavam disponíveis para controles ActiveX, como compatibilidade com contêineres OLE existentes e a capacidade de integrar seus menus com os menus de contêiner OLE. Além disso, um controle ActiveX dá suporte total à automação, que permite ao controle expor propriedades read\write e um conjunto de métodos que podem ser chamados pelo usuário de controle.

Você pode criar controles ActiveX sem janela e controles que só criam uma janela quando se tornam ativas. Controles sem janela aceleram a exibição do seu aplicativo e possibilitam que controles transparentes e não retangulares. Você também pode carregar as propriedades do controle ActiveX de forma assíncrona.

Um controle ActiveX é implementado como um servidor em processo (normalmente um pequeno objeto) que pode ser usado em qualquer contêiner OLE. Observe que a funcionalidade completa de um controle ActiveX está disponível somente quando usada em um contêiner OLE projetado para estar ciente dos controles ActiveX. Consulte [controles ActiveX de porta para outros aplicativos](containers-for-activex-controls.md) para obter uma lista de contêineres que dão suporte a controles ActiveX. Esse tipo de contêiner, em seguida chamado de "contêiner de controle", pode operar um controle ActiveX usando as propriedades e os métodos do controle e recebe notificações do controle ActiveX na forma de eventos. A figura a seguir demonstra essa interação.

![Interação do contêiner e controle do controle ActiveX](../mfc/media/vc37221.gif "Interação do contêiner e controle do controle ActiveX") <br/>
Interação entre um contêiner de controle ActiveX e um controle ActiveX em janelas

Para obter algumas informações recentes sobre como otimizar seus controles ActiveX, consulte [controles ActiveX do MFC: otimização](mfc-activex-controls-optimization.md).

Para criar um controle ActiveX do MFC, consulte [criar um projeto de controle ActiveX](reference/mfc-activex-control-wizard.md).

Para obter mais informações, consulte:

- [Contêineres de controle ActiveX](activex-control-containers.md)

- [Documentos ativos](active-documents.md)

- [Noções básicas sobre controles ActiveX](/windows/win32/com/activex-controls)

- [Atualizando um controle ActiveX existente para ser usado na Internet](upgrading-an-existing-activex-control.md)

## <a name="basic-components-of-an-activex-control"></a><a name="_core_basic_components_of_an_activex_control"></a>Componentes básicos de um controle ActiveX

Um controle ActiveX usa vários elementos programáticos para interagir com eficiência com um contêiner de controle e com o usuário. Esses são [COleControl](reference/colecontrol-class.md)de classe, um conjunto de funções de acionamento de eventos e um mapa de expedição.

Todo objeto de controle ActiveX que você desenvolve herda um poderoso conjunto de recursos de sua classe base MFC `COleControl` . Esses recursos incluem ativação in-loco e lógica de automação. `COleControl`pode fornecer o objeto de controle com a mesma funcionalidade de um objeto de janela do MFC, além da capacidade de acionar eventos. `COleControl`também pode fornecer [controles sem janela](providing-windowless-activation.md), que dependem de seu contêiner para obter ajuda com algumas das funcionalidades que uma janela fornece (captura do mouse, foco do teclado, rolagem), mas oferece uma exibição muito mais rápida.

Como a classe Control é derivada de `COleControl` , ela herda a capacidade de enviar, ou "acionar", mensagens, chamadas eventos, para o contêiner de controle quando determinadas condições são atendidas. Esses eventos são usados para notificar o contêiner de controle quando algo importante acontece no controle. Você pode enviar informações adicionais sobre um evento para o contêiner de controle anexando parâmetros ao evento. Para obter mais informações sobre eventos de controle ActiveX, consulte o artigo [controles ActiveX do MFC: eventos](mfc-activex-controls-events.md).

O elemento final é um mapa de expedição, que é usado para expor um conjunto de funções (chamadas de métodos) e atributos (chamados Propriedades) para o usuário de controle. As propriedades permitem que o contêiner de controle ou o usuário de controle manipule o controle de várias maneiras. O usuário pode alterar a aparência do controle, alterar determinados valores do controle ou fazer solicitações do controle, como acessar uma parte específica dos dados que o controle mantém. Essa interface é determinada pelo desenvolvedor de controle e é definida usando **modo de exibição de classe**. Para obter mais informações sobre métodos e propriedades do controle ActiveX, consulte os artigos [controles ActiveX do MFC: métodos](mfc-activex-controls-methods.md) e [Propriedades](mfc-activex-controls-properties.md).

## <a name="interaction-between-controls-with-windows-and-activex-control-containers"></a><a name="_core_interaction_between_controls_with_windows_and_activex_control_containers"></a>Interação entre controles com contêineres de controle do Windows e ActiveX

Quando um controle é usado dentro de um contêiner de controle, ele usa dois mecanismos para se comunicar: ele expõe propriedades e métodos e dispara eventos. A figura a seguir demonstra como esses dois mecanismos são implementados.

![O controle ActiveX se comunica com seu contêiner](../mfc/media/vc37222.gif "O controle ActiveX se comunica com seu contêiner") <br/>
Comunicação entre um contêiner de controle ActiveX e um controle ActiveX

A figura anterior também ilustra como outras interfaces OLE (além da automação e dos eventos) são manipuladas pelos controles.

Toda a comunicação de um controle com o contêiner é executada pelo `COleControl` . Para lidar com algumas das solicitações do contêiner, o `COleControl` chamará as funções de membro que são implementadas na classe de controle. Todos os métodos e algumas propriedades são tratados dessa maneira. A classe do controle também pode iniciar a comunicação com o contêiner chamando funções de membro de `COleControl` . Os eventos são acionados dessa maneira.

## <a name="active-and-inactive-states-of-an-activex-control"></a><a name="_core_active_and_inactive_states_of_an_activex_control"></a>Estados ativos e inativos de um controle ActiveX

Um controle tem dois Estados básicos: ativo e inativo. Tradicionalmente, esses Estados foram diferenciados pelo fato de o controle tivesse uma janela. Um controle ativo tinha uma janela; um controle inativo não. Com a introdução da ativação sem janela, essa distinção não é mais universal, mas ainda se aplica a muitos controles.

Quando um [controle sem janela](providing-windowless-activation.md) fica ativo, ele invoca a captura do mouse, o foco do teclado, a rolagem e outros serviços do Windows a partir de seu contêiner. Você também pode [fornecer a interação com o mouse para controles inativos](providing-mouse-interaction-while-inactive.md), bem como criar controles que [aguardem até que sejam ativados para criar uma janela](turning-off-the-activate-when-visible-option.md).

Quando um controle com uma janela se torna ativo, ele é capaz de interagir totalmente com o contêiner de controle, o usuário e o Windows. A figura a seguir demonstra os caminhos de comunicação entre o controle ActiveX, o contêiner de controle e o sistema operacional.

![Processamento de MSG no controle ActiveX com janela ativa](../mfc/media/vc37223.gif "Processamento de MSG no controle ActiveX com janela ativa") <br/>
Processamento de mensagens do Windows em um controle ActiveX em janelas (quando ativo)

## <a name="serialization"></a><a name="_core_serializing_activex_elements"></a>Série

A capacidade de serializar dados, às vezes conhecida como persistência, permite que o controle grave o valor de suas propriedades no armazenamento persistente. Os controles podem ser recriados lendo o estado do objeto do armazenamento.

Observe que um controle não é responsável por obter acesso ao meio de armazenamento. Em vez disso, o contêiner do controle é responsável por fornecer o controle com um meio de armazenamento a ser usado nos horários apropriados. Para obter mais informações sobre serialização, consulte o artigo [controles ActiveX do MFC: Serializando](mfc-activex-controls-serializing.md). Para obter informações sobre como otimizar a serialização, consulte [otimizando a persistência e a inicialização](optimizing-persistence-and-initialization.md) em controles ActiveX: otimização.

## <a name="installing-activex-control-classes-and-tools"></a><a name="_core_installing_activex_control_classes_and_tools"></a>Instalando classes e ferramentas de controle ActiveX

Quando você instala o Visual C++, as classes de controle ActiveX do MFC e as DLLs de tempo de execução do controle ActiveX de varejo e depuração são instaladas automaticamente se os controles ActiveX estiverem selecionados na instalação (eles são selecionados por padrão).

Por padrão, as classes e as ferramentas de controle ActiveX são instaladas nos seguintes subdiretórios em \Program Files\Microsoft Visual Studio .NET:

- **\Common7\Tools**

   Contém os arquivos de contêiner de teste (TstCon32. exe, bem como seus arquivos de ajuda).

- **\Vc7\atlmfc\include**

   Contém os arquivos de inclusão necessários para o desenvolvimento de controles ActiveX com o MFC

- **\Vc7\atlmfc\src\mfc**

   Contém o código-fonte para classes de controle ActiveX específicas no MFC

- **\Vc7\atlmfc\lib**

   Contém as bibliotecas necessárias para o desenvolvimento de controles ActiveX com MFC

Também há exemplos para controles ActiveX do MFC. Para obter mais informações sobre esses exemplos, consulte [exemplos de controles: controles ActiveX baseados em MFC](../overview/visual-cpp-samples.md)

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](user-interface-elements-mfc.md)
