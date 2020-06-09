---
title: Implementação da barra de ferramentas MFC
ms.date: 11/04/2016
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
ms.openlocfilehash: 7876e9403389c19a24e5a482534d0f223eaa4bf5
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626121"
---
# <a name="mfc-toolbar-implementation"></a>Implementação da barra de ferramentas MFC

Uma barra de ferramentas é uma [barra de controle](control-bars.md) que contém as imagens de bitmap dos controles. Essas imagens podem se comportar como botões de opção, caixas de seleção ou interligamentos. O MFC fornece a classe [CToolBar](reference/ctoolbar-class.md) para gerenciar barras de ferramentas.

Se você habilitá-lo, os usuários das barras de ferramentas do MFC poderão encaixá-los na borda de uma janela ou "flutuar" em qualquer lugar dentro da janela do aplicativo. O MFC não dá suporte a barras de ferramentas personalizáveis como as do ambiente de desenvolvimento.

O MFC também dá suporte a dicas de ferramentas: pequenas janelas pop-up que descrevem a finalidade de um botão da barra de ferramentas quando você posiciona o mouse sobre o botão. Por padrão, quando o usuário pressiona um botão da barra de ferramentas, uma cadeia de caracteres de status é exibida na barra de status (se houver). Você pode ativar a atualização da barra de status "com interrupções" para exibir a cadeia de caracteres de status quando o mouse estiver posicionado sobre o botão sem pressioná-lo.

> [!NOTE]
> A partir da versão 4,0 do MFC, barras de ferramentas e dicas de ferramenta são implementadas usando o Windows 95 e a funcionalidade posterior, em vez da implementação anterior específica do MFC.

Para compatibilidade com versões anteriores, o MFC retém a implementação mais antiga da barra de ferramentas na classe `COldToolBar` . A documentação para versões anteriores do MFC descreve `COldToolBar` em `CToolBar` .

Crie a primeira barra de ferramentas em seu programa selecionando a opção da barra de ferramentas no assistente do aplicativo. Você também pode criar barras de ferramentas adicionais.

Os itens a seguir são apresentados neste artigo:

- [Botões da barra de ferramentas](#_core_toolbar_buttons)

- [Barras de ferramentas flutuantes e de encaixe](#_core_docking_and_floating_toolbars)

- [Barras de ferramentas e dicas de ferramenta](#_core_toolbars_and_tool_tips)

- [As classes CToolBar e CToolBarCtrl](#_core_the_ctoolbar_and_ctoolbarctrl_classes)

- [O bitmap da barra de ferramentas](#_core_the_toolbar_bitmap)

## <a name="toolbar-buttons"></a><a name="_core_toolbar_buttons"></a>Botões da barra de ferramentas

Os botões em uma barra de ferramentas são análogos aos itens em um menu. Os dois tipos de objetos de interface do usuário geram comandos, que o programa manipula fornecendo funções de manipulador. Frequentemente, os botões da barra de ferramentas duplicam a funcionalidade dos comandos de menu, fornecendo uma interface do usuário alternativa para a mesma funcionalidade. Essa duplicação é organizada simplesmente fornecendo ao botão e ao item de menu a mesma ID.

Você pode fazer com que os botões de uma barra de ferramentas sejam exibidos e se comportam como botões de opção, caixas de seleção ou botão. Para obter mais informações, consulte Class [CToolBar](reference/ctoolbar-class.md).

## <a name="docking-and-floating-toolbars"></a><a name="_core_docking_and_floating_toolbars"></a>Barras de ferramentas flutuantes e de encaixe

Uma barra de ferramentas do MFC pode:

- Permaneça estacionário ao longo de um lado de sua janela pai.

- Ser arrastado e "encaixado", ou anexado, pelo usuário a qualquer lado ou lados da janela pai que você especificar.

- Ser "flutuante" ou desanexado da janela do quadro, em sua própria janela de mini-quadro, para que o usuário possa movê-lo para qualquer posição conveniente.

- Ser redimensionado enquanto estiver flutuante.

Para obter mais informações, consulte o artigo [encaixe e barras de ferramentas flutuantes](docking-and-floating-toolbars.md).

## <a name="toolbars-and-tool-tips"></a><a name="_core_toolbars_and_tool_tips"></a>Barras de ferramentas e dicas de ferramenta

As barras de ferramentas do MFC também podem ser feitas para exibir "dicas de ferramentas" – janelas pop-up pequenas que contêm uma descrição de texto curto da finalidade de um botão da barra de ferramentas. À medida que o usuário move o mouse sobre um botão da barra de ferramentas, a janela da dica de ferramenta é exibida para oferecer uma dica. Para obter mais informações, consulte o artigo [dicas de ferramenta da barra de ferramentas](toolbar-tool-tips.md).

## <a name="the-ctoolbar-and-ctoolbarctrl-classes"></a><a name="_core_the_ctoolbar_and_ctoolbarctrl_classes"></a>As classes CToolBar e CToolBarCtrl

Você gerencia as barras de ferramentas do seu aplicativo por meio da classe [CToolBar](reference/ctoolbar-class.md). A partir da versão 4,0 do MFC, foi `CToolBar` reimplementada para usar o controle comum da barra de ferramentas disponível no windows 95 ou posterior e no Windows NT versão 3,51 ou posterior.

Essa reimplementação resulta em menos código MFC para barras de ferramentas, porque o MFC usa o suporte do sistema operacional. A reimplementação também melhora o recurso. Você pode usar `CToolBar` funções de membro para manipular barras de ferramentas ou pode obter uma referência para o objeto [CToolBarCtrl](reference/ctoolbarctrl-class.md) subjacente e chamar suas funções de membro para personalização da barra de ferramentas e funcionalidade adicional.

> [!TIP]
> Se você investiu muito na implementação mais antiga do MFC do `CToolBar` , esse suporte ainda estará disponível. Consulte o artigo [usando suas barras de ferramentas antigas](using-your-old-toolbars.md).

Consulte também o exemplo de [DOCKTOOL](../overview/visual-cpp-samples.md)geral do MFC.

## <a name="the-toolbar-bitmap"></a><a name="_core_the_toolbar_bitmap"></a>O bitmap da barra de ferramentas

Uma vez construída, um `CToolBar` objeto cria a imagem da barra de ferramentas carregando um único bitmap que contém uma imagem para cada botão. O assistente de aplicativo cria um bitmap de barra de ferramentas padrão que você pode personalizar com o [Editor de barra de ferramentas](../windows/toolbar-editor.md)Visual C++.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Conceitos básicos da barra de ferramentas](toolbar-fundamentals.md)

- [Barras de ferramentas flutuantes e de encaixe](docking-and-floating-toolbars.md)

- [Dicas de ferramenta da barra de ferramentas](toolbar-tool-tips.md)

- [Trabalhando com o controle da barra de ferramentas](working-with-the-toolbar-control.md)

- [Usando as barras de ferramentas anteriores](using-your-old-toolbars.md)

- As classes [CToolBar](reference/ctoolbar-class.md) e [CToolBarCtrl](reference/ctoolbarctrl-class.md)

## <a name="see-also"></a>Consulte também

[Barras de Ferramentas](toolbars.md)<br/>
[Editor de barra de ferramentas](../windows/toolbar-editor.md)
