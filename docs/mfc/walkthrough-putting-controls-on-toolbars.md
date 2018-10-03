---
title: 'Passo a passo: Colocando controles em barras de ferramentas | Microsoft Docs'
ms.custom: ''
ms.date: 09/20/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Customize dialog box, adding controls
- toolbars [MFC], adding controls
ms.assetid: 8fc94bdf-0da7-45d9-8bc4-52b7b1edf205
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1995d3472f175872e084e2654531a2e72a90f950
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48235499"
---
# <a name="walkthrough-putting-controls-on-toolbars"></a>Instruções passo a passo: colocando controles em barras de ferramentas

Este artigo descreve como adicionar um botão de barra de ferramentas que contém um controle do Windows para uma barra de ferramentas. No MFC, um botão de barra de ferramentas deve ser um [classe CMFCToolBarButton](../mfc/reference/cmfctoolbarbutton-class.md)-derivado de classe, por exemplo [classe CMFCToolBarComboBoxButton](../mfc/reference/cmfctoolbarcomboboxbutton-class.md), [classe CMFCToolBarEditBoxButton](../mfc/reference/cmfctoolbareditboxbutton-class.md), [Classe CMFCDropDownToolbarButton](../mfc/reference/cmfcdropdowntoolbarbutton-class.md), ou [classe CMFCToolBarMenuButton](../mfc/reference/cmfctoolbarmenubutton-class.md).

## <a name="adding-controls-to-toolbars"></a>Adicionando controles a barras de ferramentas

Para adicionar um controle a uma barra de ferramentas, siga estas etapas:

1. Reserve uma ID de recurso fictício para o botão no recurso da barra de ferramentas pai. Para obter mais informações sobre como criar botões usando o **barra de ferramentas do Editor** no Visual Studio, consulte o [Editor de barra de ferramentas](../windows/toolbar-editor.md) artigo.

1. Reserve uma imagem da barra de ferramentas (ícone do botão) para o botão em todos os bitmaps de barra de ferramentas pai.

1. No manipulador de mensagens que processa o `AFX_WM_RESETTOOLBAR` a mensagem, execute as seguintes etapas:

   1. Construir o controle de botão, usando um `CMFCToolbarButton`-classe derivada.

   1. Substitua o botão fictício com o novo controle usando [CMFCToolBar::ReplaceButton](../mfc/reference/cmfctoolbar-class.md#replacebutton). Você pode construir o objeto de botão na pilha, pois `ReplaceButton` copia o objeto de botão e mantém a cópia.

> [!NOTE]
>  Se você habilitou a personalização em seu aplicativo, talvez você precise redefinir barra de ferramentas usando o **redefinição** botão a **barras de ferramentas** guia da **personalizar** caixa de diálogo para ver o atualizado o controle em seu aplicativo depois de recompilar. O estado da barra de ferramentas é salvo no registro do Windows, e as informações de registro são carregadas e aplicadas após o `ReplaceButton` método é executado durante a inicialização do aplicativo.

## <a name="toolbar-controls-and-customization"></a>Personalização e controles de barra de ferramentas

O **comandos** guia o **personalizar** caixa de diálogo contém uma lista de comandos que estão disponíveis no aplicativo. Por padrão, o **personalizar** caixa de diálogo processa os menus do aplicativo e cria uma lista de botões de barra de ferramentas padrão em cada categoria de menu. Para manter a funcionalidade estendida que fornecem os controles de barra de ferramentas, você deve substituir o botão de barra de ferramentas padrão com o controle personalizado na **personalizar** caixa de diálogo.

Ao habilitar a personalização, você cria o **personalizar** caixa de diálogo no manipulador de personalização `OnViewCustomize` usando o [classe CMFCToolBarsCustomizeDialog](../mfc/reference/cmfctoolbarscustomizedialog-class.md) classe. Antes de exibir o **personalizar** caixa de diálogo chamando [CMFCToolBarsCustomizeDialog::Create](../mfc/reference/cmfctoolbarscustomizedialog-class.md#create), chame [CMFCToolBarsCustomizeDialog::ReplaceButton](../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) para substituir o botão padrão com o novo controle.

## <a name="example-creating-a-find-combo-box"></a>Exemplo: Criando uma caixa de combinação localizar

Esta seção descreve como criar uma **localizar** controle de caixa de combinação que aparece em uma barra de ferramentas e contém cadeias de caracteres de pesquisa recentes usado. O usuário pode digitar uma cadeia de caracteres no controle e, em seguida, pressione a tecla enter para pesquisar um documento ou pressione a tecla ESC para retornar o foco para o quadro principal. Este exemplo supõe que o documento é exibido em uma [classe CEditView](../mfc/reference/ceditview-class.md)-derivado do modo de exibição.

### <a name="creating-the-find-control"></a>Criando o controle Find

Primeiro, crie o **localizar** controle caixa de combinação:

1. Adicione o botão e seus comandos aos recursos do aplicativo:

   1. Nos recursos do aplicativo, adicione um novo botão com um `ID_EDIT_FIND` ID do comando para uma barra de ferramentas em seu aplicativo e qualquer bitmaps associado com a barra de ferramentas.

   1. Criar um novo item de menu com o `ID_EDIT_FIND` comando ID.

   1. Adicionar uma nova cadeia de caracteres "Localizar o text\nFind" à tabela de cadeia de caracteres e atribuí-lo um `ID_EDIT_FIND_COMBO` comando ID. Essa ID será usada como a ID de comando do **localizar** botão da caixa de combinação.

        > [!NOTE]
        > Porque `ID_EDIT_FIND` é um comando padrão que é processado pelo `CEditView`, não é necessário implementar um manipulador especial para esse comando.  No entanto, você deve implementar um manipulador para o novo comando `ID_EDIT_FIND_COMBO`.

1. Crie uma nova classe, `CFindComboBox`, derivado do [classe CComboBox](../mfc/reference/ccombobox-class.md).

1. No `CFindComboBox` classe, substitua o `PreTranslateMessage` método virtual. Esse método permitirá que a caixa de combinação processar o [WM_KEYDOWN](/windows/desktop/inputdev/wm-keydown) mensagem. Se o usuário pressiona a tecla ESC (`VK_ESCAPE`), retornar o foco para a janela de quadro principal. Se o usuário pressiona a tecla Enter (`VK_ENTER`), postar para a janela de quadro principal um `WM_COMMAND` mensagem que contém o `ID_EDIT_FIND_COMBO` comando ID.

1. Criar uma classe para o **encontrar** botão da caixa de combinação, derivado de [classe CMFCToolBarComboBoxButton](../mfc/reference/cmfctoolbarcomboboxbutton-class.md). Neste exemplo, ela é nomeada `CFindComboButton`.

1. O construtor de `CMFCToolbarComboBoxButton` usa três parâmetros: a ID de comando do botão, o índice de imagem do botão e o estilo da caixa de combinação. Defina esses parâmetros da seguinte maneira:

   1. Passar o `ID_EDIT_FIND_COMBO` como a ID de comando.

   1. Use [CCommandManager::GetCmdImage](reference/internal-classes.md) com `ID_EDIT_FIND` para obter o índice de imagem.

   1. Para obter uma lista de estilos de caixa de combinação disponíveis, consulte [estilos de caixa de combinação](../mfc/reference/styles-used-by-mfc.md#combo-box-styles).

1. No `CFindComboButton` classe, substitua o `CMFCToolbarComboBoxButton::CreateCombo` método. Aqui, você deve criar o `CFindComboButton` do objeto e retornar um ponteiro para ele.

1. Use o [IMPLEMENT_SERIAL](../mfc/reference/run-time-object-model-services.md#implement_serial) macro para tornar o botão de combinação persistente. O Gerenciador de espaço de trabalho automaticamente carrega e salva o estado do botão no registro do Windows.

1. Implementar o `ID_EDIT_FIND_COMBO` manipulador no modo de exibição de documento. Use [CMFCToolBar::GetCommandButtons](../mfc/reference/cmfctoolbar-class.md#getcommandbuttons) com `ID_EDIT_FIND_COMBO` para recuperar todas as **localizar** botões da caixa de combinação. Pode haver várias cópias de um botão com a mesma ID de comando devido à personalização.

1. No `ID_EDIT_FIND` manipulador de mensagens `OnFind`, use [CMFCToolBar::IsLastCommandFromButton](../mfc/reference/cmfctoolbar-class.md#islastcommandfrombutton) para determinar se o comando Localizar foi enviado do **localizar** botão da caixa de combinação. Nesse caso, localize o texto e adicione a cadeia de caracteres de pesquisa à caixa de combinação.

### <a name="adding-the-find-control-to-the-main-toolbar"></a>Adicionando o controle localizar na barra de ferramentas principal

Para adicionar o botão da caixa de combinação na barra de ferramentas, siga estas etapas:

1. Implemente a `AFX_WM_RESETTOOLBAR` manipulador de mensagens `OnToolbarReset` na janela do quadro principal.

    > [!NOTE]
    > O framework envia essa mensagem para a janela do quadro principal quando uma barra de ferramentas é inicializada durante a inicialização do aplicativo, ou quando uma barra de ferramentas é redefinida durante a personalização. Em ambos os casos, você deve substituir o botão de barra de ferramentas padrão com personalizado **localizar** botão da caixa de combinação.

1. No `AFX_WM_RESETTOOLBAR` manipulador, examine a ID de barra de ferramentas, ou seja, o *WPARAM* da mensagem AFX_WM_RESETTOOLBAR. Se a ID da barra de ferramentas é igual da barra de ferramentas que contém o **encontrar** botão da caixa de combinação, chame [CMFCToolBar::ReplaceButton](../mfc/reference/cmfctoolbar-class.md#replacebutton) para substituir o **localizar** botão (ou seja, o botão com a ID de comando `ID_EDIT_FIND)` com um `CFindComboButton` objeto.

    > [!NOTE]
    > Você pode construir uma `CFindComboBox` do objeto na pilha, pois `ReplaceButton` copia o objeto de botão e mantém a cópia.

### <a name="adding-the-find-control-to-the-customize-dialog-box"></a>Adicionando o controle localizar a caixa de diálogo Personalizar

No manipulador de personalização `OnViewCustomize`, chame [CMFCToolBarsCustomizeDialog::ReplaceButton](../mfc/reference/cmfctoolbarscustomizedialog-class.md#replacebutton) para substituir o **localizar** botão (ou seja, o botão com a ID de comando `ID_EDIT_FIND`) com um `CFindComboButton` objeto.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../mfc/hierarchy-chart.md)<br/>
[Classes](../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarButton](../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Classe CMFCToolBarComboBoxButton](../mfc/reference/cmfctoolbarcomboboxbutton-class.md)<br/>
[Classe CMFCToolBarsCustomizeDialog](../mfc/reference/cmfctoolbarscustomizedialog-class.md)
