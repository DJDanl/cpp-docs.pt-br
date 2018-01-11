---
title: "Implementação da barra de ferramentas MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- toolbars [MFC], creating
- buttons [MFC], MFC toolbars
- toolbars [MFC], docking
- CToolBar class [MFC], creating toolbars
- MFC toolbars
- floating toolbars [MFC]
- toolbars [MFC], floating
- docking toolbars [MFC]
- bitmaps [MFC], toolbar
- toolbar controls [MFC]
- CToolBarCtrl class [MFC], implementing toolbars
- tool tips [MFC], enabling
- toolbars [MFC]
- toolbars [MFC], implementing MFC toolbars
ms.assetid: af3319ad-c430-4f90-8361-e6a2c06fd084
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 540f3240588b8e6fde119a167eace8103ef58c5a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-toolbar-implementation"></a>Implementação da barra de ferramentas MFC
Uma barra de ferramentas é um [barra de controle](../mfc/control-bars.md) que contém as imagens de bitmap de controles. Essas imagens podem se comportar como pushbuttons, caixas de seleção ou botões de opção. MFC fornece a classe [CToolbar](../mfc/reference/ctoolbar-class.md) para gerenciar as barras de ferramentas.  
  
 Se você habilitá-la, os usuários das barras de ferramentas MFC podem encaixe-os para a borda de uma janela ou "flutuar"-los em qualquer lugar na janela do aplicativo. MFC não dá suporte a barras de ferramentas personalizáveis, como aqueles no ambiente de desenvolvimento.  
  
 MFC também oferece suporte a dicas de ferramenta: pequenas janelas pop-up que descrevam a finalidade de um botão barra de ferramentas quando você posiciona o mouse sobre o botão. Por padrão, quando o usuário pressiona um botão de barra de ferramentas, uma cadeia de caracteres de status aparece na barra de status (se houver). Você pode ativar o status "Deslizar por" barra atualizar para exibir a cadeia de caracteres de status quando o mouse é posicionado sobre o botão sem pressioná-lo.  
  
> [!NOTE]
>  A partir da versão 4.0 do MFC, barras de ferramentas e dicas de ferramenta são implementadas usando o Windows 95 e posterior funcionalidade em vez da implementação anterior específica a MFC.  
  
 Para compatibilidade com versões anteriores, MFC retém a implementação da barra de ferramentas mais antiga na classe **COldToolBar**. A documentação de versões anteriores do MFC descrevem **COldToolBar** em `CToolBar`.  
  
 Crie a barra de ferramentas primeiro em seu programa, selecionando a opção de barra de ferramentas no Assistente do aplicativo. Você também pode criar outras barras de ferramentas.  
  
 A seguir é apresentados neste artigo:  
  
-   [Botões da barra de ferramentas](#_core_toolbar_buttons)  
  
-   [Encaixando e flutuando barras de ferramentas](#_core_docking_and_floating_toolbars)  
  
-   [Barras de ferramentas e dicas de ferramenta](#_core_toolbars_and_tool_tips)  
  
-   [As classes CToolBar e CToolBarCtrl](#_core_the_ctoolbar_and_ctoolbarctrl_classes)  
  
-   [O bitmap de barra de ferramentas](#_core_the_toolbar_bitmap)  
  
##  <a name="_core_toolbar_buttons"></a>Botões da barra de ferramentas  
 Os botões na barra de ferramentas são análogos aos itens em um menu. Os dois tipos de objetos de interface do usuário geram comandos, que trata de seu programa, fornecer funções de manipulador. Botões de barra de ferramentas geralmente duplicam a funcionalidade de comandos de menu, fornecendo uma interface de usuário alternativa para a mesma funcionalidade. Tal eliminação de duplicação é organizada simplesmente, fornecendo o botão e o item de menu a mesma ID.  
  
 Você pode tornar os botões na barra de ferramentas aparecem e se comportam como pushbuttons, caixas de seleção ou botões de opção. Para obter mais informações, consulte a classe [CToolBar](../mfc/reference/ctoolbar-class.md).  
  
##  <a name="_core_docking_and_floating_toolbars"></a>Encaixando e flutuando barras de ferramentas  
 Uma barra de ferramentas MFC pode:  
  
-   Permanece parado ao longo de um lado da janela pai.  
  
-   Ser arrastado e "encaixado" ou anexado, pelo usuário em qualquer lado ou lados da janela pai especificado.  
  
-   Ser "flutuante" ou desanexado da janela do quadro, em sua própria janela do minipara quadro que o usuário pode movê-lo para qualquer posição conveniente.  
  
-   Ser redimensionado ao flutuante.  
  
 Para obter mais informações, consulte o artigo [encaixe e barras de ferramentas flutuantes](../mfc/docking-and-floating-toolbars.md).  
  
##  <a name="_core_toolbars_and_tool_tips"></a>Barras de ferramentas e dicas de ferramenta  
 Barras de ferramentas MFC também podem ser feitas para exibir "dicas de ferramentas" — windows pequena pop-up que contém uma descrição de texto curto de uso de um botão barra de ferramentas. Como o usuário move o mouse sobre um botão de barra de ferramentas, a janela de dica de ferramenta surge ofereça uma dica. Para obter mais informações, consulte o artigo [dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md).  
  
##  <a name="_core_the_ctoolbar_and_ctoolbarctrl_classes"></a>As Classes de CToolBarCtrl e CToolBar  
 Gerenciar barras de ferramentas do aplicativo por meio da classe [CToolBar](../mfc/reference/ctoolbar-class.md). A partir de MFC versão 4.0, `CToolBar` foi reimplementado para usar o controle de barra de ferramentas comuns disponível no Windows 95 ou posterior e Windows NT 3.51 ou posterior.  
  
 Este reimplementação resulta em menos código MFC para barras de ferramentas, como o MFC faz uso de suporte do sistema operacional. A reimplementação também melhora a capacidade. Você pode usar `CToolBar` funções de membro para manipular as barras de ferramentas, ou você podem obter uma referência para o subjacente [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) de objeto e chamar funções de membro para personalização da barra de ferramentas e recursos adicionais.  
  
> [!TIP]
>  Se você tiver feito grande investimento na implementação do MFC mais antiga do `CToolBar`, que suporte ainda está disponível. Consulte o artigo [usando seu antigo barras de ferramentas](../mfc/using-your-old-toolbars.md).  
  
 Também consulte a amostra de MFC geral [DOCKTOOL](../visual-cpp-samples.md).  
  
##  <a name="_core_the_toolbar_bitmap"></a>O Bitmap de barra de ferramentas  
 Uma vez criada, uma `CToolBar` objeto cria a imagem da barra de ferramentas ao carregar um único bitmap que contém uma imagem para cada botão. O Assistente de aplicativo cria um bitmap de barra de ferramentas padrão que você pode personalizar o Visual c++ [editor de barra de ferramentas](../windows/toolbar-editor.md).  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Fundamentos da barra de ferramentas](../mfc/toolbar-fundamentals.md)  
  
-   [Encaixando e flutuando barras de ferramentas](../mfc/docking-and-floating-toolbars.md)  
  
-   [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)  
  
-   [Trabalhando com o controle de barra de ferramentas](../mfc/working-with-the-toolbar-control.md)  
  
-   [Usando as barras de ferramentas anteriores](../mfc/using-your-old-toolbars.md)  
  
-   O [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) classes  
  
## <a name="see-also"></a>Consulte também  
 [Barras de ferramentas](../mfc/toolbars.md)   
 [Editor de barra de ferramentas](../windows/toolbar-editor.md)

