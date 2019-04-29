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
ms.openlocfilehash: 55c43c47b93cd21d86293706fc7c3eb5145c39fd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62238553"
---
# <a name="mfc-toolbar-implementation"></a>Implementação da barra de ferramentas MFC

Uma barra de ferramentas é uma [barra de controle](../mfc/control-bars.md) que contém as imagens de bitmap de controles. Essas imagens podem se comportar como botões de opção, caixas de seleção ou comportarem. MFC fornece a classe [CToolbar](../mfc/reference/ctoolbar-class.md) para gerenciar as barras de ferramentas.

Se você habilitá-la, os usuários das barras de ferramentas MFC podem encaixá-las para a borda de uma janela ou "flutuar"-los em qualquer lugar dentro da janela do aplicativo. MFC não dá suporte a barras de ferramentas personalizáveis, como aqueles no ambiente de desenvolvimento.

MFC também oferece suporte a dicas de ferramenta: janelas pop-up pequeno que descrevem a finalidade de um botão barra de ferramentas quando você posiciona o mouse sobre o botão. Por padrão, quando o usuário pressiona um botão de barra de ferramentas, uma cadeia de caracteres de status aparece na barra de status (se houver). Você pode ativar a barra de atualização para exibir a cadeia de caracteres de status quando o mouse está posicionado sobre o botão sem pressioná-lo de "tempo real por" status.

> [!NOTE]
>  A partir do MFC versão 4.0, barras de ferramentas e dicas de ferramenta são implementadas usando o Windows 95 e a funcionalidade mais recente em vez da implementação anterior específica ao MFC.

Para compatibilidade com versões anteriores, o MFC retém a implementação da barra de ferramentas mais antiga na classe `COldToolBar`. A documentação de versões anteriores do MFC descrevem `COldToolBar` sob `CToolBar`.

Crie a primeira barra de ferramentas em seu programa, selecionando a opção de barra de ferramentas no Assistente do aplicativo. Você também pode criar barras de ferramentas adicionais.

A seguir é apresentadas neste artigo:

- [Botões da barra de ferramentas](#_core_toolbar_buttons)

- [Encaixando e flutuando barras de ferramentas](#_core_docking_and_floating_toolbars)

- [Barras de ferramentas e dicas de ferramenta](#_core_toolbars_and_tool_tips)

- [As classes CToolBar e CToolBarCtrl](#_core_the_ctoolbar_and_ctoolbarctrl_classes)

- [O bitmap de barra de ferramentas](#_core_the_toolbar_bitmap)

##  <a name="_core_toolbar_buttons"></a> Botões da barra de ferramentas

Os botões na barra de ferramentas são análogos aos itens em um menu. Os dois tipos de objetos de interface do usuário geram comandos, que lida com seu programa, fornecendo funções de manipulador. Botões de barra de ferramentas com frequência duplicam a funcionalidade dos comandos de menu, fornecendo uma interface do usuário alternativa para a mesma funcionalidade. Essa duplicação é organizada simplesmente fornecendo o botão e o item de menu a mesma ID.

Você pode tornar os botões em uma barra de ferramentas são exibidos e se comportar como botões de opção, caixas de seleção ou comportarem. Para obter mais informações, consulte a classe [CToolBar](../mfc/reference/ctoolbar-class.md).

##  <a name="_core_docking_and_floating_toolbars"></a> Encaixando e flutuando barras de ferramentas

Uma barra de ferramentas MFC pode:

- Permanece parado ao longo de um lado da sua janela pai.

- Ser arrastado e "encaixado" ou anexado, pelo usuário para qualquer lado ou lados da janela pai que você especificar.

- Ser "flutuar" ou desanexado da janela do quadro, em sua própria janela com minimoldura para que o usuário pode movê-lo em torno de qualquer posição conveniente.

- Ser redimensionados enquanto flutuante.

Para obter mais informações, consulte o artigo [encaixe e barras de ferramentas flutuante](../mfc/docking-and-floating-toolbars.md).

##  <a name="_core_toolbars_and_tool_tips"></a> Barras de ferramentas e dicas de ferramenta

Barras de ferramentas MFC também podem ser feitas para exibir "dicas de ferramentas" — windows pequena janela pop-up que contém uma descrição de texto curto da finalidade de um botão barra de ferramentas. Quando o usuário move o mouse sobre um botão de barra de ferramentas, a janela de dica de ferramenta é exibida para oferecer uma dica. Para obter mais informações, consulte o artigo [dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md).

##  <a name="_core_the_ctoolbar_and_ctoolbarctrl_classes"></a> As Classes de CToolBarCtrl e CToolBar

Você gerencia as barras de ferramentas do seu aplicativo por meio da classe [CToolBar](../mfc/reference/ctoolbar-class.md). A partir do MFC versão 4.0, `CToolBar` foi reimplementado para usar o controle de barra de ferramentas comuns disponível no Windows 95 ou posterior e Windows NT 3.51 ou posterior.

Essa reimplementação resulta em menos código do MFC para barras de ferramentas, como o MFC faz uso de suporte do sistema operacional. A reimplementação também melhora a capacidade. Você pode usar `CToolBar` funções de membro para manipular as barras de ferramentas, ou você podem obter uma referência ao subjacente [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) de objeto e chamar funções de seu membro para personalização da barra de ferramentas e funcionalidades adicionais.

> [!TIP]
>  Se você tiver investido muito na implementação do MFC mais antiga do `CToolBar`, que suporte ainda está disponível. Consulte o artigo [usando sua barras de ferramentas](../mfc/using-your-old-toolbars.md).

Consulte também o exemplo de MFC geral [DOCKTOOL](../overview/visual-cpp-samples.md).

##  <a name="_core_the_toolbar_bitmap"></a> O Bitmap de barra de ferramentas

Após a construção, um `CToolBar` objeto cria a imagem da barra de ferramentas com o carregamento de um único bitmap que contém uma imagem para cada botão. O Assistente de aplicativo cria um bitmap de barra de ferramentas padrão que você pode personalizar com o Visual C++ [editor de barra de ferramentas](../windows/toolbar-editor.md).

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Conceitos básicos da barra de ferramentas](../mfc/toolbar-fundamentals.md)

- [Encaixando e flutuando barras de ferramentas](../mfc/docking-and-floating-toolbars.md)

- [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)

- [Trabalhando com o controle de barra de ferramentas](../mfc/working-with-the-toolbar-control.md)

- [Usando as barras de ferramentas anteriores](../mfc/using-your-old-toolbars.md)

- O [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) classes

## <a name="see-also"></a>Consulte também

[Barras de ferramentas](../mfc/toolbars.md)<br/>
[Editor de barra de ferramentas](../windows/toolbar-editor.md)
