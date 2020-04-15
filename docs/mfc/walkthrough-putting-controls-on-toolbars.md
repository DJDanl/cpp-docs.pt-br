---
title: 'Instruções passo a passo: colocando controles em barras de ferramentas'
ms.date: 04/25/2019
helpviewer_keywords:
- Customize dialog box, adding controls
- toolbars [MFC], adding controls
ms.assetid: 8fc94bdf-0da7-45d9-8bc4-52b7b1edf205
ms.openlocfilehash: 2a801e61c49301d9b8780bbf7eb77025990337ad
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360263"
---
# <a name="walkthrough-putting-controls-on-toolbars"></a>Instruções passo a passo: colocando controles em barras de ferramentas

Este artigo descreve como adicionar um botão de barra de ferramentas que contém um controle do Windows em uma barra de ferramentas. No MFC, um botão de barra de ferramentas deve ser uma classe derivada da [classe CMFCToolBarButton,](../mfc/reference/cmfctoolbarbutton-class.md)por exemplo [CMFCToolBarComboBoxButton Class,](../mfc/reference/cmfctoolbarcomboboxbutton-class.md) [CMFCToolBarEditBoxButton Class,](../mfc/reference/cmfctoolbareditboxbutton-class.md) [CMFCDropDownToolbarButton Class](../mfc/reference/cmfcdropdowntoolbarbutton-class.md)ou [CMFCToolBarMenuButton Class](../mfc/reference/cmfctoolbarmenubutton-class.md).

## <a name="adding-controls-to-toolbars"></a>Adicionando controles às barras de ferramentas

Para adicionar um controle a uma barra de ferramentas, siga estas etapas:

1. Reserve um ID de recurso de boneco para o botão no recurso da barra de ferramentas pai. Para obter mais informações sobre como criar botões usando o **Editor de barras de ferramentas** no Visual Studio, consulte o artigo do Editor de barras de [ferramentas.](../windows/toolbar-editor.md)

1. Reserve uma imagem da barra de ferramentas (ícone de botão) para o botão em todos os bitmaps da barra de ferramentas pai.

1. No manipulador de mensagens que processa a `AFX_WM_RESETTOOLBAR` mensagem, faça as seguintes etapas:

   1. Construa o controle `CMFCToolbarButton`do botão usando uma classe derivada.

   1. Substitua o botão de boneco pelo novo controle usando [CMFCToolBar::ReplaceButton](../mfc/reference/cmfctoolbar-class.md#replacebutton). Você pode construir o objeto de `ReplaceButton` botão na pilha, porque copia o objeto do botão e mantém a cópia.

> [!NOTE]
> Se você habilitou a personalização em seu aplicativo, você pode ter que redefinir a barra de ferramentas usando o botão **Redefinir** na guia Barras de **Ferramentas** da caixa de diálogo **Personalizar** para ver o controle atualizado em seu aplicativo após a recompilação. O estado da barra de ferramentas é salvo no registro do Windows, e as informações de registro são carregadas e aplicadas após a execução do método durante a inicialização do `ReplaceButton` aplicativo.

## <a name="toolbar-controls-and-customization"></a>Controles e Personalização da barra de ferramentas

A guia **Comandos** da caixa de diálogo **Personalizar** contém uma lista de comandos disponíveis no aplicativo. Por padrão, a caixa de diálogo **Personalizar processa** os menus do aplicativo e cria uma lista de botões padrão da barra de ferramentas em cada categoria de menu. Para manter a funcionalidade estendida que os controles da barra de ferramentas fornecem, você deve substituir o botão de barra de ferramentas padrão pelo controle personalizado na caixa de diálogo **Personalizar.**

Ao ativar a personalização, você cria a caixa `OnViewCustomize` de diálogo **Personalizar** no manipulador de personalização usando a classe [CMFCToolBarsPersonalizeSala.](../mfc/reference/cmfctoolbarscustomizedialog-class.md) Antes de exibir a caixa de diálogo **Personalizar** chamando [CMFCToolBarsPersonalize-seDiálogo::Criar,](../mfc/reference/cmfctoolbarscustomizedialog-class.md#create)chamar [CMFCBarsBarsPersonalize-seDiálogo::SubstituirBotão](../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) para substituir o botão padrão pelo novo controle.

## <a name="example-creating-a-find-combo-box"></a>Exemplo: Criando uma Caixa de Combinação de Achados

Esta seção descreve como criar um controle de caixa de combinação **Find** que aparece em uma barra de ferramentas e contém strings de pesquisa usadas recentemente. O usuário pode digitar uma seqüência de string no controle e, em seguida, pressionar a tecla enter para pesquisar um documento, ou pressionar a tecla de fuga para retornar o foco para o quadro principal. Este exemplo pressupõe que o documento seja exibido em uma exibição derivada do [CEditView Class.](../mfc/reference/ceditview-class.md)

### <a name="creating-the-find-control"></a>Criando o Controle de Encontrar

Primeiro, crie o controle de caixa de combinação **Find:**

1. Adicione o botão e seus comandos aos recursos do aplicativo:

   1. Nos recursos do aplicativo, adicione `ID_EDIT_FIND` um novo botão com um ID de comando a uma barra de ferramentas em seu aplicativo e a quaisquer bitmaps associados à barra de ferramentas.

   1. Crie um novo item `ID_EDIT_FIND` de menu com o iD de comando.

   1. Adicione uma nova string "Encontrar o texto\nFind" na `ID_EDIT_FIND_COMBO` tabela de strings e atribua-a um ID de comando. Este ID será usado como o iD de comando do botão **Find** combo box.

        > [!NOTE]
        > Como `ID_EDIT_FIND` é um comando padrão `CEditView`que é processado por , você não é obrigado a implementar um manipulador especial para este comando.  No entanto, você deve implementar `ID_EDIT_FIND_COMBO`um manipulador para o novo comando .

1. Crie uma nova `CFindComboBox`classe, derivada da [Classe CComboBox](../mfc/reference/ccombobox-class.md).

1. Na `CFindComboBox` aula, anular `PreTranslateMessage` o método virtual. Este método permitirá que a caixa de combinação processe a [mensagem WM_KEYDOWN.](/windows/win32/inputdev/wm-keydown) Se o usuário acertar`VK_ESCAPE`a tecla de escape (), retorne o foco para a janela principal do quadro. Se o usuário acertar`VK_ENTER`a tecla Enter (), poste na janela do quadro principal uma `WM_COMMAND` mensagem que contenha o ID do `ID_EDIT_FIND_COMBO` comando.

1. Crie uma classe para o botão **Find** combo box, derivado do [CMFCToolBarComboBoxButton Class](../mfc/reference/cmfctoolbarcomboboxbutton-class.md). Neste exemplo, o nome usado é `CFindComboButton`.

1. O construtor `CMFCToolbarComboBoxButton` de leva três parâmetros: o ID de comando do botão, o índice de imagem do botão e o estilo da caixa de combinação. Defina esses parâmetros da seguinte forma:

   1. Passe `ID_EDIT_FIND_COMBO` o como o id de comando.

   1. Use [CCommandManager::GetCmdImage](reference/internal-classes.md) para `ID_EDIT_FIND` obter o índice de imagem.

   1. Para obter uma lista de estilos de caixa combo disponíveis, consulte [Combo-Box Styles](../mfc/reference/styles-used-by-mfc.md#combo-box-styles).

1. Na `CFindComboButton` aula, anular `CMFCToolbarComboBoxButton::CreateCombo` o método. Aqui você deve `CFindComboButton` criar o objeto e retornar um ponteiro para ele.

1. Use a [macro IMPLEMENT_SERIAL](../mfc/reference/run-time-object-model-services.md#implement_serial) para tornar o botão combo persistente. O gerenciador de espaço de trabalho carrega e salva automaticamente o estado do botão no registro do Windows.

1. Implemente `ID_EDIT_FIND_COMBO` o manipulador na exibição do documento. Use [CMFCToolBar::GetCommandButtons](../mfc/reference/cmfctoolbar-class.md#getcommandbuttons) with `ID_EDIT_FIND_COMBO` para recuperar todos os botões de caixa de combinação **Find.** Pode haver várias cópias de um botão com o mesmo ID de comando por causa da personalização.

1. No `ID_EDIT_FIND` manipulador `OnFind`de mensagens, use [CMFCToolBar::IsLastCommandFromButton](../mfc/reference/cmfctoolbar-class.md#islastcommandfrombutton) para determinar se o comando find foi enviado a partir do botão **Find** combo box. Nesse caso, encontre o texto e adicione a seqüência de pesquisa à caixa de combinação.

### <a name="adding-the-find-control-to-the-main-toolbar"></a>Adicionando o Controle de Encontrar na barra de ferramentas principal

Para adicionar o botão de caixa de combinação à barra de ferramentas, siga estas etapas:

1. Implemente `AFX_WM_RESETTOOLBAR` o `OnToolbarReset` manipulador de mensagens na janela principal do quadro.

    > [!NOTE]
    > A estrutura envia essa mensagem para a janela principal do quadro quando uma barra de ferramentas é inicializada durante a inicialização do aplicativo ou quando uma barra de ferramentas é redefinida durante a personalização. Em ambos os casos, você deve substituir o botão de barra de ferramentas padrão pelo botão de caixa de combinação personalizado **Find.**

1. No `AFX_WM_RESETTOOLBAR` manipulador, examine o ID da barra de ferramentas, ou seja, o *WPARAM* da mensagem AFX_WM_RESETTOOLBAR. Se o ID da barra de ferramentas for igual ao da barra de ferramentas que contém o botão **Find** combo box, ligue para `ID_EDIT_FIND)` [CMFCToolBar::ReplaceButton](../mfc/reference/cmfctoolbar-class.md#replacebutton) para substituir o botão **Find** (ou seja, o botão com o iD de comando por um `CFindComboButton` objeto.

    > [!NOTE]
    > Você pode `CFindComboBox` construir um objeto `ReplaceButton` na pilha, porque copia o objeto do botão e mantém a cópia.

### <a name="adding-the-find-control-to-the-customize-dialog-box"></a>Adicionando o Controle de encontrar à caixa de diálogo personalizar

`OnViewCustomize`No manipulador de personalização, chame [CMFCToolBarsPersonalize-se::Substituirbotão](../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) para substituir o botão **Encontrar** (ou seja, o botão com o id `ID_EDIT_FIND`de comando ) por um `CFindComboButton` objeto.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../mfc/hierarchy-chart.md)<br/>
[Classes](../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarButton](../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[CMFCToolBarComboBoxClasse de botão](../mfc/reference/cmfctoolbarcomboboxbutton-class.md)<br/>
[Classe CMFCToolBarsCustomizeDialog](../mfc/reference/cmfctoolbarscustomizedialog-class.md)
