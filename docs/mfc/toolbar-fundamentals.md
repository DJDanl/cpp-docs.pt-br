---
title: Fundamentos da barra de ferramentas
ms.date: 11/04/2016
f1_keywords:
- RT_TOOLBAR
helpviewer_keywords:
- embedding toolbar in frame window class [MFC]
- application wizards [MFC], installing default application toolbars
- toolbars [MFC], creating
- resources [MFC], toolbar
- toolbar controls [MFC], toolbars created using Application Wizard
- toolbar controls [MFC], command ID
- RT_TOOLBAR resource [MFC]
- toolbars [MFC], adding default using Application Wizard
- LoadBitmap method [MFC], toolbars
- Toolbar editor [MFC], Application Wizard
- command IDs [MFC], toolbar buttons
- SetButtons method [MFC]
- CToolBar class [MFC], default toolbars in Application Wizard
- frame window classes [MFC], toolbar embedded in
- LoadToolBar method [MFC]
ms.assetid: cc00aaff-8a56-433b-b0c0-b857d76b4ffd
ms.openlocfilehash: d4e8793337beb2eed533fe04daf549ec21efc61d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373474"
---
# <a name="toolbar-fundamentals"></a>Fundamentos da barra de ferramentas

Este artigo descreve a implementação fundamental do MFC que permite adicionar uma barra de ferramentas padrão ao seu aplicativo, selecionando uma opção no Assistente de Aplicativos. Os tópicos abordados incluem:

- [A opção Barra de ferramentas do Assistente de Aplicativo](#_core_the_appwizard_toolbar_option)

- [A barra de ferramentas em código](#_core_the_toolbar_in_code)

- [Edição do recurso da barra de ferramentas](#_core_editing_the_toolbar_resource)

- [Barras de ferramentas múltiplas](#_core_multiple_toolbars)

## <a name="the-application-wizard-toolbar-option"></a><a name="_core_the_appwizard_toolbar_option"></a>A opção barra de ferramentas do assistente de aplicativo

Para obter uma única barra de ferramentas com botões padrão, selecione a opção Barra de ferramentas de encaixe padrão na página denominada Recursos de Interface do Usuário. Isso adiciona código ao seu aplicativo que:

- Cria o objeto da barra de ferramentas.

- Gerencia a barra de ferramentas, incluindo sua capacidade de atracar ou flutuar.

## <a name="the-toolbar-in-code"></a><a name="_core_the_toolbar_in_code"></a>A barra de ferramentas em código

A barra de ferramentas é um objeto [CToolBar](../mfc/reference/ctoolbar-class.md) declarado `CMainFrame` como um membro de dados da classe do seu aplicativo. Em outras palavras, o objeto da barra de ferramentas está incorporado no objeto da janela da janela do quadro principal. Isso significa que o MFC cria a barra de ferramentas quando cria a janela do quadro e destrói a barra de ferramentas quando destrói a janela do quadro. A seguinte declaração parcial de classe, para um aplicativo de interface de documento múltiplo (MDI), mostra membros de dados para uma barra de ferramentas incorporada e uma barra de status incorporada. Ele também mostra a `OnCreate` substituição da função do membro.

[!code-cpp[NVC_MFCListView#6](../atl/reference/codesnippet/cpp/toolbar-fundamentals_1.h)]

A criação da `CMainFrame::OnCreate`barra de ferramentas ocorre em . O MFC chama [onCreate](../mfc/reference/cwnd-class.md#oncreate) depois de criar a janela para o quadro, mas antes que ele se torne visível. O `OnCreate` padrão que o Assistente de Aplicativo gera faz as seguintes tarefas da barra de ferramentas:

1. Chama `CToolBar` a função [Criar](../mfc/reference/ctoolbar-class.md#create) membro do objeto para criar o objeto [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) subjacente.

1. Chama [loadToolBar](../mfc/reference/ctoolbar-class.md#loadtoolbar) para carregar as informações de recursos da barra de ferramentas.

1. Chamadas funciona para habilitar encaixe, flutuante e dicas de ferramentas. Para obter detalhes sobre essas chamadas, consulte o artigo [Docking and Floating Toolbars](../mfc/docking-and-floating-toolbars.md).

> [!NOTE]
> A amostra MFC General [DOCKTOOL](../overview/visual-cpp-samples.md) inclui ilustrações de barras de ferramentas antigas e novas mfc. As barras de `COldToolbar` ferramentas que usam `LoadBitmap` exigem `LoadToolBar`chamadas na `SetButtons`etapa 2 para (em vez de ) e para . As novas barras de `LoadToolBar`ferramentas exigem chamadas para .

As chamadas de encaixe, flutuante e dicas de ferramentas são opcionais. Você pode remover `OnCreate` essas linhas se preferir. O resultado é uma barra de ferramentas que permanece fixa, incapaz de flutuar ou reencaixar e incapaz de exibir as pontas da ferramenta.

## <a name="editing-the-toolbar-resource"></a><a name="_core_editing_the_toolbar_resource"></a>Edição do recurso barra de ferramentas

A barra de ferramentas padrão que você recebe com o Assistente de Aplicativos é baseada em um recurso personalizado **RT_TOOLBAR,** introduzido na versão 4.0 do MFC. Você pode editar este recurso com o [editor da barra de ferramentas](../windows/toolbar-editor.md). O editor permite adicionar, excluir e reorganizar botões facilmente. Ele contém um editor gráfico para os botões que é muito semelhante ao editor geral de gráficos no Visual C++. Se você editou barras de ferramentas em versões anteriores do Visual C++, você encontrará a tarefa muito mais fácil agora.

Para conectar um botão de barra de ferramentas a um comando, você dá ao botão um ID de comando, como `ID_MYCOMMAND`. Especifique o ID de comando na página de propriedade do botão no editor da barra de ferramentas. Em seguida, crie uma função de manipulador para o comando (consulte [Mapping Messages to Functions](../mfc/reference/mapping-messages-to-functions.md) para obter mais informações).

As funções do novo membro [CToolBar](../mfc/reference/ctoolbar-class.md) funcionam com o recurso **RT_TOOLBAR.** [LoadToolBar](../mfc/reference/ctoolbar-class.md#loadtoolbar) agora toma o lugar do [LoadBitmap](../mfc/reference/ctoolbar-class.md#loadbitmap) para carregar o bitmap das imagens do botão da barra de ferramentas e [SetButtons](../mfc/reference/ctoolbar-class.md#setbuttons) para definir os estilos de botão e conectar botões com imagens de bitmap.

Para obter detalhes sobre o uso do editor da barra de ferramentas, consulte [Toolbar Editor](../windows/toolbar-editor.md).

## <a name="multiple-toolbars"></a><a name="_core_multiple_toolbars"></a>Barras de ferramentas múltiplas

O Assistente de Aplicativo fornece uma barra de ferramentas padrão. Se você precisar de mais de uma barra de ferramentas em seu aplicativo, você pode modelar seu código para barras de ferramentas adicionais com base no código gerado pelo assistente para a barra de ferramentas padrão.

Se você quiser exibir uma barra de ferramentas como resultado de um comando, você precisará:

- Crie um novo recurso de barra de ferramentas `OnCreate` com o editor da barra de ferramentas e carregue-o com a função de membro [loadToolbar.](../mfc/reference/ctoolbar-class.md#loadtoolbar)

- Incorpore um novo objeto [CToolBar](../mfc/reference/ctoolbar-class.md) na classe da janela do quadro principal.

- Faça as chamadas `OnCreate` de função apropriadas para acoplar ou flutuar a barra de ferramentas, definir seus estilos e assim por diante.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Implementação da barra de ferramentas do MFC (informações de visão geral sobre barras de ferramentas)](../mfc/mfc-toolbar-implementation.md)

- [Barras de ferramentas flutuantes e de acoplamento](../mfc/docking-and-floating-toolbars.md)

- [Dicas de ferramenta da barra de ferramentas](../mfc/toolbar-tool-tips.md)

- As classes [CToolBarCtrl](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)

- [Trabalhando com o controle da barra de ferramentas](../mfc/working-with-the-toolbar-control.md)

- [Usando suas barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)

## <a name="see-also"></a>Confira também

[Implementação da barra de ferramentas MFC](../mfc/mfc-toolbar-implementation.md)
