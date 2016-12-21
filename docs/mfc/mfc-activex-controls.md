---
title: "Controles ActiveX MFC | Microsoft Docs"
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
  - "MFC ActiveX Controls (MFC)"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], MFC"
  - "Classe COleControl, Controles ActiveX MFC"
  - "contêineres [C++], Controles ActiveX MFC"
  - "mapas de envios, para controles ActiveX MFC"
  - "eventos [C++], Controles ActiveX"
  - "Controles ActiveX MFC [C++]"
  - "Controles ActiveX MFC [C++], estado ativo/inativo"
  - "Controles ActiveX MFC [C++], contêineres"
  - "Controles ActiveX MFC [C++], serializando"
  - "serialização [C++], Controles ActiveX MFC"
ms.assetid: c911fb74-3afc-4bf3-a0f5-7922b14d9a1b
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle ActiveX é um componente de software reutilizável baseado em COM \(Component Object Model \(COM\) que oferece suporte a uma ampla variedade de funcionalidade OLE e pode ser personalizado para atender às necessidades de software.  Os controles ActiveX são projetados para uso em contêineres comuns do controle ActiveX e na Internet, em páginas da World Wide Web.  Você pode criar controles ActiveX com o MFC, descrito aqui, ou com [Biblioteca ativa \(ATL\) do modelo](../atl/active-template-library-atl-concepts.md).  
  
 Um controle ActiveX pode desenhar\-se em sua própria janela, responde a eventos \(como cliques do mouse\), e é gerenciado por meio de uma interface que inclui as propriedades e os métodos semelhantes em objetos de automação.  
  
 Esses controles podem ser desenvolvidos para muitos usos, como o acesso a base de dados do sistema, monitoramento de dados, ou a representação gráfica.  Além da portabilidade, os controles ActiveX oferecem suporte aos recursos não disponíveis anteriormente nos controles ActiveX, como a compatibilidade com os contêineres com OLE DB existentes e a capacidade de integrar os menus com os menus DE o contêiner.  Além disso, um controle ActiveX oferece suporte completo à automação, o que permite o controle à exposição leitura \\ propriedades de gravação e um conjunto de métodos que podem ser chamados pelo usuário do controle.  
  
 Você pode criar os controles ActiveX sem o windows e os controles que criam apenas uma janela quando se tornam ativos.  Os controles sem o windows aceleram a exibição do aplicativo e tornam\-na possível ter controles transparentes e nonrectangular.  Você também pode carregar propriedades do controle ActiveX de forma assíncrona.  
  
 Um controle ActiveX é implementado como um servidor em processo \(geralmente um objeto pequeno\) que pode ser usado em qualquer contêiner OLE.  Observe que a funcionalidade completa de um controle ActiveX está disponível apenas quando usada em um contêiner OLE criado para estar ciente de controles ActiveX.  Consulte [Mova controles ActiveX a outros aplicativos](../Topic/Containers%20for%20ActiveX%20Controls.md) para obter uma lista de contêiner que dão suporte aos controles ActiveX.  Esse tipo de contêiner, assim por diante chamado de “um contêiner controle,” pode operar um controle ActiveX usando as propriedades e os métodos de controle, e recebe notificações do controle ActiveX na forma de eventos.  A figura a seguir demonstra essa interação.  
  
 ![Interações do controle ActiveX](../mfc/media/vc37221.png "vc37221")  
Interação entre um contêiner do controle ActiveX e um controle ActiveX de janela  
  
 Para algumas informações recentes sobre otimizar seus controles ActiveX, consulte [Controles ActiveX MFC: Otimização](../mfc/mfc-activex-controls-optimization.md).  
  
 Para criar um controle ActiveX de MFC, consulte [Crie um projeto do controle ActiveX](../mfc/reference/mfc-activex-control-wizard.md).  
  
 Para obter mais informações, consulte:  
  
-   [Contêiner do controle ActiveX](../mfc/activex-control-containers.md)  
  
-   [Documentos ativas](../Topic/Active%20Documents.md)  
  
-   [Usando controles ActiveX](../Topic/Using%20ActiveX%20Controls.md)  
  
-   [\<caps:sentence id\="tgt23" sentenceid\="e07c7a1ebdac21120a91f75018670c81" class\="tgtSentence"\>Controles ActiveX entendendo\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms693753)  
  
-   [Atualizando um controle ActiveX existente a ser usado na Internet](../Topic/Upgrading%20an%20Existing%20ActiveX%20Control.md)  
  
##  <a name="_core_basic_components_of_an_activex_control"></a> Componentes básicos de um controle ActiveX  
 Um controle ActiveX usa vários elementos de programação para interagir com eficiência com um contêiner do controle e ao usuário.  Essas são classe [COleControl](../mfc/reference/colecontrol-class.md), um conjunto de funções de evento acionado, e um mapa de distribuição.  
  
 Cada objeto de controle ActiveX que você desenvolve herda um conjunto avançado de recursos da sua classe base, MFC `COleControl`.  Esses recursos incluem o ativação no local, e a lógica de automação.  `COleControl` pode fornecer o objeto de controle com a mesma funcionalidade que um objeto da janela de MFC, além da capacidade de eventos acionados.  `COleControl` também pode fornecer [controles sem o windows](../mfc/providing-windowless-activation.md), que dependem de seu contêiner para obter ajuda com qualquer funcionalidade do que fornece uma janela \(captura do mouse em, foco de teclado, rolando\), mas em uma exibição muito mais rápida do oferecem.  
  
 Como a classe do controle é deriva de `COleControl`, herda o recurso enviar, ou “,” disparar eventos mensagens, chamado, ao contêiner do controle quando certas condições forem atendidas.  Esses eventos são usados para notificar o contêiner do controle quando algo importante ocorre no controle.  Você pode enviar informações adicionais sobre um evento no contêiner do controle anexando parâmetros para o evento.  Para obter mais informações sobre eventos do controle ActiveX, consulte o artigo [Controles ActiveX MFC: Eventos](../mfc/mfc-activex-controls-events.md).  
  
 O elemento final é um mapa de distribuição, que é usado para expor um conjunto de funções \(métodos chamados\) e propriedades chamados de atributos \(\) ao usuário do controle.  As propriedades permitem que o contêiner do controle ou o usuário de controle manipulem o controle de várias maneiras.  O usuário pode alterar a aparência de controle, altere determinados valores de controle, ou fazer solicitações de controle, como acessar uma parte específica de dados que mantém o controle.  Esta interface é determinada pelo desenvolvedor de controle e definida usando **Modo de Exibição de Classe**.  Para obter mais informações sobre os métodos e as propriedades do controle ActiveX, consulte os artigos [Controles ActiveX MFC: Métodos](../mfc/mfc-activex-controls-methods.md) e [Propriedades](../mfc/mfc-activex-controls-properties.md).  
  
##  <a name="_core_interaction_between_controls_with_windows_and_activex_control_containers"></a> Interação entre controles com o windows e contêiner do controle ActiveX  
 Quando um controle é usada dentro de um contêiner do controle, usa dois mecanismos para se comunicar: expondo propriedades e métodos, e aciona eventos.  A figura a seguir demonstra como esses dois mecanismos são implementados.  
  
 ![ActiveXCntrl de contêiner ActiveX CTRL comunicação](../Image/vc37222.gif "vc37222")  
Comunicação entre um contêiner do controle ActiveX e um controle ActiveX  
  
 A figura anterior também ilustra como outras interfaces OLE \(além de automação e dos eventos\) são tratadas por controles.  
  
 Toda a comunicação de um controle ao contêiner é executada por `COleControl`.  Para tratar as solicitações de contêiner, **COleControl** chama as funções de membro que são implementadas na classe do controle.  Todos os métodos e algumas propriedades são tratados dessa maneira.  A classe do controle também pode iniciar comunicação com o contêiner chamando funções de membro de `COleControl`.  Os eventos são disparados dessa forma.  
  
##  <a name="_core_active_and_inactive_states_of_an_activex_control"></a> Estados ativas e inativas de um controle ActiveX  
 Um controle tem dois estados básicos: ativa e inativo.  Tradicionalmente, esses estados foram distinguidos pelo se o controle tiver uma janela.  Um controle ativa tinha uma janela; um controle inativa não fez.  Com a introdução de ativação sem o windows, essa distinção não é mais universal, mas ainda se aplica a muitos controles.  
  
 Quando [controle sem o windows](../mfc/providing-windowless-activation.md) fica ativo, invocar a captura do mouse em, o foco de teclado, o deslocamento, e outros serviços da janela do respectivo contêiner.  Você também pode [fornecer a interação do mouse nos controles inativos](../Topic/Providing%20Mouse%20Interaction%20While%20Inactive.md), assim como para criar os controles que [espere até ativado para criar uma janela](../mfc/turning-off-the-activate-when-visible-option.md).  
  
 Quando um controle com uma janela fica ativo, pode interagir completamente com o contêiner do controle, o usuário, e o windows.  A figura a seguir demonstra os caminhos de comunicação entre o controle ActiveX, o contêiner do controle, e o sistema operacional.  
  
 ![Win Msg processamento janela ActiveX Windows &#40;ativo&#41;](../mfc/media/vc37223.png "vc37223")  
Processamento de mensagens do windows em um controle ActiveX da janela ativa \(quando\)  
  
##  <a name="_core_serializing_activex_elements"></a> Série  
 A capacidade de serializar os dados, às vezes chamado de como a persistência, permite que o controle gravar o valor de suas propriedades para o repositório persistente.  Os controles podem ser recriados lê o estado do objeto de armazenamento.  
  
 Observe que um controle não é responsável para obter acesso ao suporte de memória.  Em vez disso, o contêiner do controle é responsável para fornecer o controle um suporte de memória a ser usado nos momentos apropriados.  Para obter mais informações sobre a serialização, consulte o artigo [Controles ActiveX MFC: Serializar](../mfc/mfc-activex-controls-serializing.md).  Para obter informações sobre como otimizar a serialização, consulte [Otimizando a persistência e a inicialização](../mfc/optimizing-persistence-and-initialization.md) em controles ActiveX: Otimização.  
  
##  <a name="_core_installing_activex_control_classes_and_tools"></a> Instalando classes e ferramentas do controle ActiveX  
 Quando você instala o Visual C\+\+, as classes do controle ActiveX MFC e as dlls de tempo de execução do controle ActiveX de varejo e de depuração são instalados automaticamente se os controles ActiveX são selecionados na configuração \(são selecionados por padrão\).  
  
 Por padrão, as classes do controle ActiveX e as ferramentas forem instaladas nos subdiretórios em \\ arquivos de programas \\ Microsoft Visual Studio .NET:  
  
-   **\\Common7\\Tools**  
  
     Contém os arquivos do contêiner de teste \(TstCon32.exe, bem como seus arquivos de ajuda\).  
  
-   **\\Vc7\\atlmfc\\include**  
  
     Contém os arquivos necessários para desenvolver incluir controles ActiveX com MFC  
  
-   **\\Vc7\\atlmfc\\src\\mfc**  
  
     Contém a origem para classes específicas do controle ActiveX em MFC  
  
-   **\\Vc7\\atlmfc\\lib**  
  
     Contém as bibliotecas necessários para desenvolver controles ActiveX com MFC  
  
 Também há exemplos de MFC controles ActiveX.  Para obter mais informações sobre esses exemplos, consulte [Controles Exemplos: Controles ActiveX com base MFC\-](../top/visual-cpp-samples.md)  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)