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
ms.openlocfilehash: 38811be765d4427c4083b8f142b54fb67b9076a0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359313"
---
# <a name="mfc-toolbar-implementation"></a>Implementação da barra de ferramentas MFC

Uma barra de ferramentas é uma [barra de controle](../mfc/control-bars.md) que contém as imagens bitmap dos controles. Essas imagens podem se comportar como botões, caixas de seleção ou botões de rádio. O MFC fornece a classe [CToolbar](../mfc/reference/ctoolbar-class.md) para gerenciar barras de ferramentas.

Se você habilitá-lo, os usuários das barras de ferramentas do MFC podem ancorá-los na borda de uma janela ou "flutuar" em qualquer lugar dentro da janela do aplicativo. O MFC não suporta barras de ferramentas personalizáveis como as do ambiente de desenvolvimento.

O MFC também suporta dicas de ferramentas: pequenas janelas pop-up que descrevem o propósito de um botão de barra de ferramentas quando você posiciona o mouse sobre o botão. Por padrão, quando o usuário pressiona um botão de barra de ferramentas, uma seqüência de status aparece na barra de status (se houver uma). Você pode ativar a atualização da barra de status "fly by" para exibir a seqüência de status quando o mouse estiver posicionado sobre o botão sem pressioná-lo.

> [!NOTE]
> A partir da versão 4.0 do MFC, barras de ferramentas e dicas de ferramentas são implementadas usando o Windows 95 e funcionalidade posterior em vez da implementação anterior específica para MFC.

Para compatibilidade retrógrada, o MFC `COldToolBar`mantém a implementação da barra de ferramentas mais antiga em classe . A documentação para versões anteriores do MFC descreve `COldToolBar` em `CToolBar`.

Crie a primeira barra de ferramentas do seu programa selecionando a opção Barra de ferramentas no Assistente de aplicativos. Você também pode criar barras de ferramentas adicionais.

Os seguintes são introduzidos neste artigo:

- [Botões da barra de ferramentas](#_core_toolbar_buttons)

- [Barras de ferramentas flutuantes e de acoplamento](#_core_docking_and_floating_toolbars)

- [Barras de ferramentas e dicas de ferramentas](#_core_toolbars_and_tool_tips)

- [As classes CToolBarCtrl e CToolBarCtrl](#_core_the_ctoolbar_and_ctoolbarctrl_classes)

- [O bitmap da barra de ferramentas](#_core_the_toolbar_bitmap)

## <a name="toolbar-buttons"></a><a name="_core_toolbar_buttons"></a>Botões da barra de ferramentas

Os botões em uma barra de ferramentas são análogos aos itens em um menu. Ambos os tipos de objetos de interface de usuário geram comandos, que o programa lida fornecendo funções de manipulador. Muitas vezes, os botões da barra de ferramentas duplicam a funcionalidade dos comandos do menu, fornecendo uma interface de usuário alternativa para a mesma funcionalidade. Essa duplicação é organizada simplesmente dando ao botão e ao item do menu o mesmo ID.

Você pode fazer com que os botões em uma barra de ferramentas apareçam e se comportem como botões, caixas de seleção ou botões de rádio. Para obter mais informações, consulte [classe CToolBar](../mfc/reference/ctoolbar-class.md).

## <a name="docking-and-floating-toolbars"></a><a name="_core_docking_and_floating_toolbars"></a>Barras de ferramentas flutuantes e de encaixe

Uma barra de ferramentas do MFC pode:

- Permanecer parado ao longo de um lado de sua janela pai.

- Ser arrastado e "ancorado", ou anexado, pelo usuário a qualquer lado ou lado da janela pai especificado.

- Seja "flutuado", ou separado da janela do quadro, em sua própria janela de mini-quadro para que o usuário possa movê-lo para qualquer posição conveniente.

- Ser redimensionado enquanto flutua.

Para obter mais informações, consulte o artigo [Docking and Floating Toolbars](../mfc/docking-and-floating-toolbars.md).

## <a name="toolbars-and-tool-tips"></a><a name="_core_toolbars_and_tool_tips"></a>Barras de ferramentas e dicas de ferramentas

As barras de ferramentas do MFC também podem ser feitas para exibir "dicas de ferramentas" — pequenas janelas pop-up contendo uma pequena descrição de texto do propósito de um botão de barra de ferramentas. À medida que o usuário move o mouse sobre um botão de barra de ferramentas, a janela da dica da ferramenta aparece para oferecer uma dica. Para obter mais informações, consulte o artigo Dicas de [ferramentas da barra de ferramentas](../mfc/toolbar-tool-tips.md).

## <a name="the-ctoolbar-and-ctoolbarctrl-classes"></a><a name="_core_the_ctoolbar_and_ctoolbarctrl_classes"></a>As classes CToolBarCtrl

Você gerencia as barras de ferramentas do seu aplicativo através da classe [CToolBar](../mfc/reference/ctoolbar-class.md). A partir da versão 4.0 do MFC, `CToolBar` foi reimplementado para usar a barra de ferramentas comum de controle disponível no Windows 95 ou posterior e windows NT versão 3.51 ou posterior.

Essa reimplementação resulta em menos código MFC para barras de ferramentas, porque o MFC faz uso do suporte do sistema operacional. A reimplementação também melhora a capacidade. Você pode `CToolBar` usar funções de membro para manipular barras de ferramentas, ou você pode obter uma referência ao objeto [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) subjacente e chamar suas funções de membro para personalização da barra de ferramentas e funcionalidade adicional.

> [!TIP]
> Se você investiu pesado na implementação `CToolBar`mais antiga do MFC, esse suporte ainda está disponível. Veja o artigo [Usando suas barras de ferramentas antigas](../mfc/using-your-old-toolbars.md).

Consulte também a amostra geral do MFC [DOCKTOOL](../overview/visual-cpp-samples.md).

## <a name="the-toolbar-bitmap"></a><a name="_core_the_toolbar_bitmap"></a>O Bitmap da barra de ferramentas

Uma vez construído, um `CToolBar` objeto cria a imagem da barra de ferramentas carregando um único bitmap que contém uma imagem para cada botão. O Assistente de Aplicativos cria um bitmap de barra de ferramentas padrão que você pode personalizar com o editor da barra de ferramentas Visual [C++.](../windows/toolbar-editor.md)

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Fundamentos da barra de ferramentas](../mfc/toolbar-fundamentals.md)

- [Barras de ferramentas flutuantes e de acoplamento](../mfc/docking-and-floating-toolbars.md)

- [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)

- [Trabalhando com o controle da barra de ferramentas](../mfc/working-with-the-toolbar-control.md)

- [Usando as barras de ferramentas anteriores](../mfc/using-your-old-toolbars.md)

- As classes [CToolBarCtrl](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)

## <a name="see-also"></a>Confira também

[Barras de Ferramentas](../mfc/toolbars.md)<br/>
[Editor de barra de ferramentas](../windows/toolbar-editor.md)
