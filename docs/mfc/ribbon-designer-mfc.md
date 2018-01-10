---
title: "Faixa de opções Designer (MFC) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.ribbon.F1
dev_langs: C++
helpviewer_keywords:
- Ribbon Designer (MFC)
- MFC Ribbon Designer
ms.assetid: 0806dfd6-7d11-471a-99e1-4072852231f9
caps.latest.revision: "24"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0dde2c26855e8d8acd51b8c607867d9b92b3987f
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="ribbon-designer-mfc"></a>Designer da faixa de opções (MFC)
O Designer de faixa de opções permite que você criar e personalizar as faixas de opções em aplicativos MFC. Uma faixa de opções é um elemento de interface do usuário do usuário que organiza os comandos em grupos lógicos. Esses grupos são exibidos em guias separadas em uma faixa na parte superior da janela. A faixa de opções substitui a barra de menus e barras de ferramentas. Uma faixa de opções pode melhorar significativamente a usabilidade do aplicativo. Para obter mais informações, consulte [faixas de opções](http://go.microsoft.com/fwlink/p/?linkid=129233). A ilustração a seguir mostra uma faixa de opções.  
  
 ![Controle de recurso de faixa de opções do MFC](../mfc/media/ribbon_no_callouts.png "ribbon_no_callouts")  
  
 Em versões anteriores do Visual Studio, faixas de opções precisava ser criado ao escrever código que usa as classes de faixa de opções do MFC como [classe CMFCRibbonBar](../mfc/reference/cmfcribbonbar-class.md). Em [!INCLUDE[vs_dev10_long](../build/includes/vs_dev10_long_md.md)], o designer de faixa de opções fornece um método alternativo para a criação de faixas de opções. Primeiro, criar e personalizar uma faixa de opções como um recurso. Em seguida, carregar o recurso de faixa de opções de código no aplicativo do MFC. Você pode até usar recursos de faixa de opções e classes de faixa de opções do MFC juntos. Por exemplo, você pode criar um recurso de faixa de opções e, em seguida, adicionar programaticamente elementos mais a ele em tempo de execução por meio de código.  
  
## <a name="understanding-the-ribbon-designer"></a>Noções básicas sobre o Designer de faixa de opções  
 O designer de faixa de opções cria e armazena a faixa de opções como um recurso. Quando você cria um recurso de faixa de opções, o designer de faixa de opções faz essas três coisas:  
  
-   Adiciona uma entrada para o script de definição de recurso do projeto (*. rc). No exemplo a seguir, `IDR_RIBBON` é o nome exclusivo que identifica o recurso de faixa de opções, `RT_RIBBON_XML` é o tipo de recurso, e `ribbon.mfcribbon-ms` é o nome do arquivo de recurso.  
  
 ```  
    IDR_RIBBON RT_RIBBON_XML      "res\\ribbon.mfcribbon-ms"  
 ```  
  
-   Adiciona as definições de IDs de comando para resource.h.  
  
 ```  
 #define IDR_RIBBON            307  
 ```  
  
-   Cria um arquivo de recurso de faixa de opções (*.mfcribbon ms) que contém o código XML que define os botões da faixa de opções, controles e atributos. Alterações para a faixa de opções no designer de faixa de opções são armazenadas no arquivo de recurso como XML. O exemplo de código a seguir mostra parte do conteúdo de um \*ms .mfcribbon arquivo:  
  
 ```  
 <RIBBON_BAR>  
 <ELEMENT_NAME>RibbonBar</ELEMENT_NAME>  
 <IMAGE>  
 <ID>  
 <NAME>IDB_BUTTONS</NAME>  
 <VALUE>113</VALUE>  
 </ID>   
 ```  
  
 Para usar o recurso de faixa de opções em seu aplicativo do MFC, carregar o recurso chamando [CMFCRibbonBar::LoadFromResource](../mfc/reference/cmfcribbonbar-class.md#loadfromresource).  
  
## <a name="creating-a-ribbon-by-using-the-ribbon-designer"></a>Criando uma faixa de opções usando o Designer de faixa de opções  
 Estes são os dois modos de adicionar um recurso de faixa de opções ao seu projeto MFC:  
  
-   Criar um aplicativo MFC e configurar o Assistente de projeto do MFC para criar a faixa de opções. Para obter mais informações, consulte [passo a passo: Criando uma faixa de opções aplicativos por usando MFC](../mfc/walkthrough-creating-a-ribbon-application-by-using-mfc.md).  
  
-   Em um projeto MFC existente, crie um recurso de faixa de opções e carregá-lo. Para obter mais informações, consulte [passo a passo: atualizando o aplicativo de rabisco MFC (parte 1)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md).  
  
 Se o projeto já tem uma faixa de opções manualmente codificada, MFC tem funções que você pode usar para converter a faixa de opções existente em um recurso de faixa de opções. Para obter mais informações, consulte [como: converter uma faixa de opções do MFC existente em um recurso de faixa de opções](../mfc/how-to-convert-an-existing-mfc-ribbon-to-a-ribbon-resource.md).  
  
> [!NOTE]
>  Faixas de opções não não possível criar aplicativos com base na caixa de diálogo. Para obter mais informações, consulte [tipo de aplicativo, Assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md).  
  
## <a name="customizing-ribbons"></a>Personalizando faixas de opções  
 Para abrir uma faixa de opções no designer de faixa de opções, clique duas vezes o recurso de faixa de opções no modo de exibição de recursos. No designer, você pode adicionar, remover e personalizar os elementos na faixa de opções, o botão do aplicativo ou a barra de ferramentas de acesso rápido. Também é possível vincular eventos, por exemplo, os eventos de clique do botão e eventos, para um método em seu aplicativo.  
  
 A ilustração a seguir mostra os vários componentes no designer de faixa de opções.  
  
 ![Designer de faixa de opções do MFC](../mfc/media/ribbon_designer.png "ribbon_designer")  
  
- **Caixa de ferramentas:** contém controles que podem ser arrastados para a superfície do designer.  
  
- **Superfície do Designer:** contém a representação visual do recurso da faixa de opções.  
  
- **Janela de propriedades:** lista os atributos do item selecionado na superfície do designer.  
  
- **Janela de exibição de recurso:** exibe os recursos que incluem recursos de faixa de opções, no seu projeto.  
  
- **Barra de ferramentas do Editor de faixa de opções:** contém comandos que lhe permitem visualizar a faixa de opções e alterar o tema do visual.  
  
 Os tópicos a seguir descrevem como usar os recursos do designer de faixa de opções:  
  
- [Como personalizar o botão Aplicativo](../mfc/how-to-customize-the-application-button.md)  
  
- [Como personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)  
  
- [Como adicionar controles de faixa de opções e manipuladores de evento](../mfc/how-to-add-ribbon-controls-and-event-handlers.md)  
  
- [Como carregar um recurso da faixa de opções de um aplicativo MFC](../mfc/how-to-load-a-ribbon-resource-from-an-mfc-application.md)  
  
## <a name="definitions-of-ribbon-elements"></a>Definições de elementos de faixa de opções  
 ![Faixa de opções do MFC](../mfc/media/ribbon.png "faixa de opções")  
  
- **Botão do aplicativo:** no botão que aparece no canto superior esquerdo de uma faixa de opções. O botão do aplicativo substitui o menu Arquivo e é visível mesmo quando a faixa de opções é minimizada. Quando o botão é clicado, é exibido um menu que tem uma lista de comandos.  
  
- **Ferramentas de acesso rápido:** comandos usados com uma barra de ferramentas pequena personalizável que exibe com frequência.  
  
- **Categoria de**: O agrupamento lógico que representa o conteúdo de uma guia de faixa de opções.  
  
- **Botão de padrão de categoria:** o botão que aparece na faixa de opções quando a faixa de opções é minimizada. Quando o botão é clicado, a categoria é exibida novamente como um menu.  
  
- **Painel:** uma área da barra de faixa de opções que exibe um grupo de controles relacionados. Cada categoria de faixa de opções contém um ou mais painéis de faixa de opções.  
  
- **Elementos de faixa de opções:** controla os painéis, por exemplo, botões e caixas de combinação. Para ver os vários controles que podem ser hospedados em uma faixa de opções, consulte [RibbonGadgets exemplo: aplicativo de Gadgets da faixa de opções](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)

