---
title: 'Passo a passo: Colocando controles em barras de ferramentas'
ms.date: 04/25/2019
helpviewer_keywords:
- Customize dialog box, adding controls
- toolbars [MFC], adding controls
ms.assetid: 8fc94bdf-0da7-45d9-8bc4-52b7b1edf205
ms.openlocfilehash: 0c62a8b484cb666427f873244221afec5d4719da
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510734"
---
# <a name="walkthrough-putting-controls-on-toolbars"></a>Passo a passo: Colocando controles em barras de ferramentas

Este artigo descreve como adicionar um botão de barra de ferramentas que contém um controle do Windows a uma barra de ferramentas. No MFC, um botão de barra de ferramentas deve ser uma classe derivada de [classe CMFCToolBarButton](../mfc/reference/cmfctoolbarbutton-class.md), por exemplo, [Classe CMFCToolBarComboBoxButton](../mfc/reference/cmfctoolbarcomboboxbutton-class.md), classe [CMFCToolBarEditBoxButton](../mfc/reference/cmfctoolbareditboxbutton-class.md), [classe CMFCDropDownToolbarButton](../mfc/reference/cmfcdropdowntoolbarbutton-class.md)ou [ Classe CMFCToolBarMenuButton](../mfc/reference/cmfctoolbarmenubutton-class.md).

## <a name="adding-controls-to-toolbars"></a>Adicionando controles a barras de ferramentas

Para adicionar um controle a uma barra de ferramentas, siga estas etapas:

1. Reserve uma ID de recurso fictícia para o botão no recurso de barra de ferramentas pai. Para obter mais informações sobre como criar botões usando o **Editor de barra de ferramentas** no Visual Studio, consulte o artigo editor de barra de [ferramentas](../windows/toolbar-editor.md) .

1. Reserve uma imagem da barra de ferramentas (ícone de botão) para o botão em todos os bitmaps da barra de ferramentas pai.

1. No manipulador de mensagens que processa a `AFX_WM_RESETTOOLBAR` mensagem, execute as seguintes etapas:

   1. Construa o controle de botão usando uma `CMFCToolbarButton`classe derivada.

   1. Substitua o botão fictício pelo novo controle usando [CMFCToolBar:: ReplaceButton](../mfc/reference/cmfctoolbar-class.md#replacebutton). Você pode construir o objeto Button na pilha, pois `ReplaceButton` o copia o objeto Button e mantém a cópia.

> [!NOTE]
>  Se você habilitou a personalização em seu aplicativo, talvez seja necessário redefinir a barra de ferramentas usando o botão **Redefinir** na guia **barras de ferramentas** da caixa de diálogo **Personalizar** para ver o controle atualizado em seu aplicativo após a recompilação. O estado da barra de ferramentas é salvo no registro do Windows e as informações do registro são carregadas `ReplaceButton` e aplicadas depois que o método é executado durante a inicialização do aplicativo.

## <a name="toolbar-controls-and-customization"></a>Controles e personalização da barra de ferramentas

A guia **comandos** da caixa de diálogo **Personalizar** contém uma lista de comandos que estão disponíveis no aplicativo. Por padrão, a caixa de diálogo **Personalizar** processa os menus do aplicativo e cria uma lista de botões da barra de ferramentas padrão em cada categoria de menu. Para manter a funcionalidade estendida que os controles da barra de ferramentas fornecem, você deve substituir o botão da barra de ferramentas padrão pelo controle personalizado na caixa de diálogo **Personalizar** .

Ao habilitar a personalização, você cria a caixa de diálogo **Personalizar** no manipulador `OnViewCustomize` de personalização usando a classe de [Classe CMFCToolBarsCustomizeDialog](../mfc/reference/cmfctoolbarscustomizedialog-class.md) . Antes de exibir a caixa de diálogo **Personalizar** chamando [CMFCToolBarsCustomizeDialog:: Create](../mfc/reference/cmfctoolbarscustomizedialog-class.md#create), chame [CMFCToolBarsCustomizeDialog:: ReplaceButton](../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) para substituir o botão padrão pelo novo controle.

## <a name="example-creating-a-find-combo-box"></a>Exemplo: Criando uma caixa de combinação localizar

Esta seção descreve como criar um controle **Localizar** caixa de combinação que aparece em uma barra de ferramentas e contém cadeias de caracteres de pesquisa usadas recentemente. O usuário pode digitar uma cadeia de caracteres no controle e pressionar a tecla Enter para pesquisar um documento ou pressionar a tecla escape para retornar o foco para o quadro principal. Este exemplo pressupõe que o documento é exibido em uma exibição derivada de [classe CEditView](../mfc/reference/ceditview-class.md).

### <a name="creating-the-find-control"></a>Criando o controle de localização

Primeiro, crie o controle **Localizar** caixa de combinação:

1. Adicione o botão e seus comandos aos recursos do aplicativo:

   1. Nos recursos do aplicativo, adicione um novo botão com uma `ID_EDIT_FIND` ID de comando a uma barra de ferramentas em seu aplicativo e a qualquer bitmap associado à barra de ferramentas.

   1. Crie um novo item de menu com `ID_EDIT_FIND` a ID de comando.

   1. Adicione uma nova cadeia de caracteres "Find The text\nFind" à tabela de cadeia de caracteres `ID_EDIT_FIND_COMBO` e atribua a ela uma ID de comando. Essa ID será usada como a ID de comando do botão **Localizar** caixa de combinação.

        > [!NOTE]
        > Como `ID_EDIT_FIND` é um comando padrão que é processado pelo `CEditView`, não é necessário implementar um manipulador especial para esse comando.  No entanto, você deve implementar um manipulador para o `ID_EDIT_FIND_COMBO`novo comando.

1. Crie uma nova classe, `CFindComboBox`, derivada da [classe CComboBox](../mfc/reference/ccombobox-class.md).

1. Na classe, substitua o `PreTranslateMessage` método virtual. `CFindComboBox` Esse método permitirá que a caixa de combinação processe a mensagem [WM_KEYDOWN](/windows/win32/inputdev/wm-keydown) . Se o usuário atingir a tecla escape (`VK_ESCAPE`), retorne o foco para a janela do quadro principal. Se o usuário pressionar a tecla Enter (`VK_ENTER`), poste na janela do quadro principal uma `WM_COMMAND` mensagem que contém a `ID_EDIT_FIND_COMBO` ID do comando.

1. Crie uma classe para o botão **Localizar** caixa de combinação, derivada da [Classe CMFCToolBarComboBoxButton](../mfc/reference/cmfctoolbarcomboboxbutton-class.md). Neste exemplo, o nome usado é `CFindComboButton`.

1. O construtor de `CMFCToolbarComboBoxButton` usa três parâmetros: a ID de comando do botão, o índice de imagem do botão e o estilo da caixa de combinação. Defina esses parâmetros da seguinte maneira:

   1. Passe o `ID_EDIT_FIND_COMBO` como a ID de comando.

   1. Use [CCommandManager:: GetCmdImage](reference/internal-classes.md) com `ID_EDIT_FIND` para obter o índice de imagem.

   1. Para obter uma lista de estilos de caixa de combinação disponíveis, consulte [estilos de caixa de combinação](../mfc/reference/styles-used-by-mfc.md#combo-box-styles).

1. Na classe, substitua o `CMFCToolbarComboBoxButton::CreateCombo` método. `CFindComboButton` Aqui você deve criar o `CFindComboButton` objeto e retornar um ponteiro para ele.

1. Use a macro [IMPLEMENT_SERIAL](../mfc/reference/run-time-object-model-services.md#implement_serial) para tornar o botão de combinação persistente. O Gerenciador de espaço de trabalho carrega e salva automaticamente o estado do botão no registro do Windows.

1. Implemente `ID_EDIT_FIND_COMBO` o manipulador no modo de exibição de documento. Use [CMFCToolBar:: GetCommandButtons](../mfc/reference/cmfctoolbar-class.md#getcommandbuttons) com `ID_EDIT_FIND_COMBO` para recuperar todos os botões da caixa de combinação **Localizar** . Pode haver várias cópias de um botão com a mesma ID de comando, devido à personalização.

1. No manipulador `ID_EDIT_FIND` `OnFind`de mensagens, use [CMFCToolBar:: IsLastCommandFromButton](../mfc/reference/cmfctoolbar-class.md#islastcommandfrombutton) para determinar se o comando find foi enviado do botão **Localizar** da caixa de combinação. Nesse caso, localize o texto e adicione a cadeia de caracteres de pesquisa à caixa de combinação.

### <a name="adding-the-find-control-to-the-main-toolbar"></a>Adicionando o controle localizar à barra de ferramentas principal

Para adicionar o botão da caixa de combinação à barra de ferramentas, siga estas etapas:

1. Implemente `AFX_WM_RESETTOOLBAR` o manipulador `OnToolbarReset` de mensagens na janela principal do quadro.

    > [!NOTE]
    > A estrutura envia essa mensagem à janela do quadro principal quando uma barra de ferramentas é inicializada durante a inicialização do aplicativo ou quando uma barra de ferramentas é redefinida durante a personalização. Em ambos os casos, você deve substituir o botão da barra de ferramentas padrão pelo botão da caixa de combinação **Localizar** personalizado.

1. No manipulador, examine a ID da barra de ferramentas, ou seja, o wParam da mensagem AFX_WM_RESETTOOLBAR. `AFX_WM_RESETTOOLBAR` Se a ID da barra de ferramentas for igual à da barra de ferramentas que contém o botão **Localizar** caixa de combinação, chame [CMFCToolBar:: ReplaceButton](../mfc/reference/cmfctoolbar-class.md#replacebutton) para substituir o botão **Localizar** (ou seja, o botão `ID_EDIT_FIND)` com a `CFindComboButton` ID de comando por um objeto.

    > [!NOTE]
    > Você pode construir um `CFindComboBox` objeto na pilha, pois `ReplaceButton` o copia o objeto Button e mantém a cópia.

### <a name="adding-the-find-control-to-the-customize-dialog-box"></a>Adicionando o controle Find à caixa de diálogo Personalizar

No `OnViewCustomize`manipulador de personalização, chame [CMFCToolBarsCustomizeDialog:: ReplaceButton](../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) para substituir o botão **Find** (ou seja, o botão com a ID `ID_EDIT_FIND`de comando) por um `CFindComboButton` objeto.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../mfc/hierarchy-chart.md)<br/>
[Classes](../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarButton](../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Classe CMFCToolBarComboBoxButton](../mfc/reference/cmfctoolbarcomboboxbutton-class.md)<br/>
[Classe CMFCToolBarsCustomizeDialog](../mfc/reference/cmfctoolbarscustomizedialog-class.md)
