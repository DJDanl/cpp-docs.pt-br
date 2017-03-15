---
title: "Designer da faixa de op&#231;&#245;es (MFC) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.ribbon.F1"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Designer da Faixa de Opções MFC"
  - "Designer da faixa de opções (MFC)"
ms.assetid: 0806dfd6-7d11-471a-99e1-4072852231f9
caps.latest.revision: 24
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Designer da faixa de op&#231;&#245;es (MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Designer de faixa de opções permite criar e personalizar as faixas de opções em aplicativos MFC.  Uma faixa de opções é um elemento de interface do usuário do usuário que organiza os comandos em grupos lógicos.  Esses grupos são exibidos em guias separadas em uma faixa na parte superior da janela.  A faixa de opções substitui a barra de menus e barras de ferramentas.  Uma faixa de opções pode melhorar significativamente a usabilidade do aplicativo.  Para obter mais informações, consulte [faixas de opções](http://go.microsoft.com/fwlink/?LinkId=129233).  A ilustração a seguir mostra uma faixa de opções.  
  
 ![Controle de recursos de faixa de opções do MFC](../mfc/media/ribbon_no_callouts.png "Ribbon\_No\_Callouts")  
  
 Nas versões anteriores do Visual Studio, faixas de opções precisava ser criado ao escrever código que usa as classes de faixa de opções do MFC como [Classe de CMFCRibbonBar](../mfc/reference/cmfcribbonbar-class.md).  Em [!INCLUDE[vs_dev10_long](../build/includes/vs_dev10_long_md.md)], o designer de faixa de opções fornece um método alternativo para a criação de faixas de opções. Primeiro, criar e personalizar uma faixa de opções como um recurso.  Em seguida, carregar o recurso de faixa de opções do código no aplicativo do MFC.  Você pode até usar recursos de faixa de opções e classes de faixa de opções do MFC juntos.  Por exemplo, você pode criar um recurso de faixa de opções e, em seguida, adicionar programaticamente elementos mais a ele em tempo de execução por meio de código.  
  
## Noções básicas sobre o Designer de faixa de opções  
 O designer de faixa de opções cria e armazena a faixa de opções como um recurso.  Quando você cria um recurso de faixa de opções, o designer de faixa de opções faz essas três coisas:  
  
-   Adiciona uma entrada no script de definição de recurso de projeto \(\*. rc\).  No exemplo a seguir, `IDR_RIBBON` é o nome exclusivo que identifica o recurso da faixa de opções, `RT_RIBBON_XML` é o tipo de recurso, e `ribbon.mfcribbon-ms` é o nome do arquivo de recurso.  
  
    ```  
    IDR_RIBBON             RT_RIBBON_XML                      "res\\ribbon.mfcribbon-ms"  
    ```  
  
-   Adiciona as definições de IDs de comando para resource.h.  
  
    ```  
    #define IDR_RIBBON            307  
    ```  
  
-   Cria um arquivo de recurso da faixa de opções \(\*.mfcribbon\-ms\) que contém o código XML que define os atributos, controles e botões da faixa de opções.  As alterações à faixa de opções no designer de faixa de opções são armazenadas no arquivo de recurso como XML.  O exemplo de código a seguir mostra parte do conteúdo de um arquivo ms \*.mfcribbon:  
  
    ```  
    <RIBBON_BAR>  
      <ELEMENT_NAME>RibbonBar</ELEMENT_NAME>  
      <IMAGE>  
        <ID>  
          <NAME>IDB_BUTTONS</NAME>  
          <VALUE>113</VALUE>  
        </ID> …  
    ```  
  
 Para usar o recurso de faixa de opções em seu aplicativo do MFC, carregar o recurso chamando [CMFCRibbonBar::LoadFromResource](../Topic/CMFCRibbonBar::LoadFromResource.md).  
  
## Criando uma faixa de opções usando o Designer de faixa de opções  
 Estas são as duas maneiras de adicionar um recurso da faixa de opções ao seu projeto MFC:  
  
-   Criar um aplicativo do MFC e configurar o Assistente de projeto do MFC para criar a faixa de opções.  Para obter mais informações, consulte [Instruções passo a passo: criando um aplicativo da faixa de opções usando MFC](../mfc/walkthrough-creating-a-ribbon-application-by-using-mfc.md).  
  
-   Em um projeto existente do MFC, crie um recurso de faixa de opções e carregá\-lo.  Para obter mais informações, consulte [Instruções passo a passo: atualizando o aplicativo de rabisco MFC \(parte 1\)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md).  
  
 Se o projeto já tiver uma faixa de opções codificada manualmente, MFC tem funções que você pode usar para converter a faixa de opções existente em um recurso de faixa de opções.  Para obter mais informações, consulte [Como converter uma faixa de opções MFC existente em um recurso da faixa de opções](../mfc/how-to-convert-an-existing-mfc-ribbon-to-a-ribbon-resource.md).  
  
> [!NOTE]
>  Faixas de opções podem ser criadas em aplicativos com base na caixa de diálogo.  Para obter mais informações, consulte [Tipo de aplicativo, Assistente de Aplicativo MFC](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md).  
  
## Personalizando as faixas de opções  
 Para abrir uma faixa de opções no designer de faixa de opções, clique duas vezes o recurso de faixa de opções no modo de exibição de recurso.  No designer, você pode adicionar, remover e personalizar elementos na faixa de opções, o botão do aplicativo ou a barra de ferramentas de acesso rápido.  Também é possível vincular eventos, por exemplo, eventos de clique de botão e eventos, para um método em seu aplicativo.  
  
 A ilustração a seguir mostra os vários componentes no designer de faixa de opções.  
  
 ![Designer de faixa de opções do MFC](../mfc/media/ribbon_designer.png "Ribbon\_Designer")  
  
-   **Caixa de ferramentas:** contém controles que podem ser arrastados para a superfície de designer.  
  
-   **a superfície de designer:** contém a representação visual do recurso da faixa de opções.  
  
-   **Janela Propriedades:** lista os atributos do item selecionado na superfície de design.  
  
-   **Janela de exibição de recurso:** exibe os recursos que incluem recursos de faixa de opções, no seu projeto.  
  
-   **De ferramentas do Editor de faixa de opções:** contém comandos que lhe permitem visualizar a faixa de opções e altere seu tema visual.  
  
 Os tópicos a seguir descrevem como usar os recursos do designer de faixa de opções:  
  
-   [Como personalizar o botão do aplicativo](../mfc/how-to-customize-the-application-button.md)  
  
-   [Como personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)  
  
-   [Como adicionar controles de faixa de opções e manipuladores de evento](../mfc/how-to-add-ribbon-controls-and-event-handlers.md)  
  
-   [Como carregar um recurso da faixa de opções de um aplicativo MFC](../mfc/how-to-load-a-ribbon-resource-from-an-mfc-application.md)  
  
## Definições de elementos da faixa de opções  
 ![Faixa de opções do MFC](../mfc/media/ribbon.png "Ribbon")  
  
-   **Botão do aplicativo:** o botão é exibido no canto superior esquerdo de uma faixa de opções.  O botão do aplicativo substitui o menu Arquivo e é visível mesmo quando a faixa de opções é minimizada.  Quando o botão é clicado, é exibido um menu que possui uma lista de comandos.  
  
-   **Barra de ferramentas de acesso rápido:** comandos usados com uma barra de ferramentas pequena e personalizável que exibe com frequência.  
  
-   **Categoria**: O agrupamento lógico que representa o conteúdo de uma guia faixa de opções.  
  
-   **Botão categoria padrão:** o botão que aparece na faixa de opções quando a faixa de opções é minimizada.  Quando o botão é clicado, a categoria reaparece como um menu.  
  
-   **Painel:** uma área da barra de faixa de opções que exibe um grupo de controles relacionados.  Cada categoria de faixa de opções contém um ou mais painéis de faixa de opções.  
  
-   **Elementos da faixa de opções:** controla os painéis, por exemplo, botões e caixas de combinação.  Para ver os vários controles que podem ser hospedados em uma faixa de opções, consulte [RibbonGadgets exemplo: aplicativo de Gadgets de faixa de opções](../top/visual-cpp-samples.md).  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Trabalhando com arquivos de recurso](../mfc/working-with-resource-files.md)