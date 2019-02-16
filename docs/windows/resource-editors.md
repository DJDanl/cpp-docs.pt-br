---
title: Editores de recursos (C++)
ms.date: 02/14/2019
f1_keywords:
- vs.editors.resource
- vc.resvw.resource.editors
- vs.resvw.resource.editors
- vs.resourceview
- vc.resvw.resource.previewing
- vs.resvw.resource.previewing
helpviewer_keywords:
- editors [C++], resource
- editors [C++]
- resource editors
- Windows [C++], application resource editing
- resources [C++], viewing
- layouts, previewing resource
- resource editors [C++], viewing resources
- .rc files [C++], viewing resources
- resources [C++], editing
- properties [C++], resources
- resources [C++], properties
ms.assetid: e20a29ec-d6fb-4ead-98f3-431a0e23aaaf
ms.openlocfilehash: aeeca87ceb5b2c5e54da7087b5020ccbc1c39039
ms.sourcegitcommit: 470de1337035dd33682d935b4b6c6d8b1bdb0bbb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/15/2019
ms.locfileid: "56320803"
---
# <a name="resource-editors-c"></a>Editores de recursos (C++)

Um **recurso** editor é um ambiente especializado para criar ou modificar os recursos que estão incluídos em um projeto do Visual Studio. Os editores de recursos do Visual Studio compartilham técnicas e interfaces para ajudá-lo a criar e modificar recursos do aplicativo de forma rápida e fácil. Editores de recursos permitem que você exiba e edite recursos nos recursos apropriados do editor e versão prévia.

O editor apropriado é aberto automaticamente quando você criar ou abrir um recurso.

> [!NOTE]
> Porque os projetos gerenciados não usam arquivos de script de recurso, você deve abrir seus recursos do **Gerenciador de soluções**. Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

|Use o...|Para editar...|
|----------------|----------------|
|[Editor de aceleradores](../windows/accelerator-editor.md)|Tabelas de aceleradores em projetos do Visual C++.|
|[Editor binário](binary-editor.md)|Informações de dados binários e recursos personalizados em projetos do Visual C++, Visual Basic ou Visual c#.|
|[Editor de caixa de diálogo](../windows/dialog-editor.md)|Caixas de diálogo em projetos do Visual C++.|
|[Editor de Imagens](../windows/image-editor-for-icons.md)|Bitmaps, ícones, cursores e outros arquivos de imagem em projetos do Visual C++, Visual Basic ou Visual c#.|
|[Editor de Menu](../windows/menu-editor.md)|Recursos de menu em projetos do Visual C++.|
|[Ribbon Editor](../mfc/ribbon-designer-mfc.md)|Recursos de faixa de opções em projetos MFC.|
|[Editor de cadeias de caracteres](../windows/string-editor.md)|Tabelas em projetos do Visual C++ de cadeia de caracteres.|
|[Editor de barra de ferramentas](../windows/toolbar-editor.md)|Recursos da barra de ferramentas em projetos do Visual C++. O editor de barra de ferramentas é parte do editor de imagens.|
|[Editor de informações de versão](../windows/version-information-editor.md)|Informações de versão em projetos do Visual C++.|

> [!NOTE]
> Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

## <a name="view-and-edit-resources"></a>Modo de exibição e edição de recursos

Cada tipo de recurso tem um **recurso** editor específico para esse tipo de recurso. Você pode reorganizar, redimensionar, adicionar controles e recursos ou caso contrário, modificar os aspectos de um recurso usando o editor associado. Você também pode editar um recurso no [formato de texto](../windows/how-to-open-a-resource-script-file-in-text-format.md) e [formato binário](../windows/opening-a-resource-for-binary-editing.md).

Alguns tipos de recurso são arquivos individuais que podem ser importados e usados de várias maneiras; Isso inclui bitmaps, ícones, cursores, barras de ferramentas e arquivos html. Esses recursos têm nomes de arquivo e [identificadores de recurso](../windows/symbols-resource-identifiers.md). Outros, como caixas de diálogo, menus e tabelas de cadeia de caracteres em projetos do Win32, existem apenas como parte de um arquivo de script (. rc) do recurso ou o arquivo de modelo (. rct) do recurso.

Recursos também podem ser editados fora do projeto, consulte [como: Abrir um arquivo de Script de recurso fora de um projeto (autônomo)](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).

> [!NOTE]
> Propriedades de um recurso [podem ser modificadas usando a janela propriedades](../windows/changing-the-properties-of-a-resource.md).

### <a name="to-edit-the-properties-of-a-resource"></a>Para editar as propriedades de um recurso

1. No [exibição de recurso](../windows/resource-view-window.md), clique com botão direito do recurso que deseja editar e escolha **propriedades** no menu de atalho.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), alterar as propriedades do recurso.

### <a name="to-undo-a-change-made-to-the-properties-of-a-resource"></a>Para desfazer uma alteração feita nas propriedades de um recurso

1. Verifique se o recurso tem o foco no **exibição de recurso**.

1. Escolher **desfazer** da **editar** menu.

### <a name="win32-resources"></a>Recursos do Win32

Você pode acessar os recursos do Win32 na [exibição de recurso](../windows/resource-view-window.md) painel.

#### <a name="to-view-a-win32-resource-in-a-resource-editor"></a>Para exibir um recurso do Win32 em um editor de recursos

1. Selecione **exibição de recurso** da **exibição** menu.

1. Se o **exibição de recurso** janela não é a janela principal, selecione o **exibição de recurso** guia para colocá-lo na parte superior.

1. Partir **exibição de recurso**, expanda a pasta do projeto que contém os recursos que você deseja exibir. Por exemplo, se você quiser exibir um recurso de caixa de diálogo, expanda o **caixa de diálogo** pasta.

1. Clique duas vezes no recurso, por exemplo, **IDD_ABOUTBOX**.

   O recurso é aberto no editor apropriado. Por exemplo, para recursos de caixa de diálogo, o recurso é aberto dentro do **caixa de diálogo** editor.

   Você também pode [exibir recursos em um arquivo. RC (script de recurso) sem a necessidade de abrir um projeto](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md).

#### <a name="to-delete-an-existing-win-32-resource"></a>Para excluir um recurso existente do Win 32

1. Na **exibição de recurso**, expanda o nó para um tipo de recurso.

1. Clique com botão direito no recurso que você deseja excluir e escolha **excluir** no menu de atalho.

   > [!NOTE]
   > Você pode excluir um recurso usando o mesmo comando de menu de atalho quando você tem o arquivo. rc abrir em uma janela de documento fora de um projeto.

### <a name="managed-project-resources"></a>Recursos de projeto gerenciado

Como os projetos gerenciados não usam arquivos de script de recurso, você deve abrir seus recursos do **Gerenciador de soluções**. Você pode usar o [editor de imagens](../windows/image-editor-for-icons.md) e o [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte a edição de recursos inseridos.

- Para exibir um recurso gerenciado em um editor de recursos, no **Gerenciador de soluções**, clique duas vezes no recurso, por exemplo, *Bitmap1.bmp*.

   O recurso é aberto no editor apropriado.

- Para excluir um recurso gerenciado existente no **Gerenciador de soluções**, com o recurso que deseja excluir e escolha o botão direito **excluir** no menu de atalho.

## <a name="preview-resources"></a>Recursos de visualização

Visualize seus recursos para que você possa exibir recursos gráficos sem abri-los. Visualização também é útil para executáveis depois que você tenha compilado-los porque os identificadores de recurso Alterar para números. Pois esses identificadores numéricos geralmente não fornecem informações suficientes, visualizando os recursos ajuda a identificar rapidamente-los.

Você pode visualizar o layout visual dos tipos de recursos a seguir: Bitmap, caixa de diálogo, ícone, Menu, Cursor, barra de ferramentas

A função de visualização do visual não se aplica a recursos: Acelerador, manifesto, tabela de cadeia de caracteres e informações de versão

> [!NOTE]
> Para visualizar recursos requer Win32.

### <a name="to-preview-resources"></a>Para visualizar os recursos

1. Na [exibição de recurso](../windows/resource-view-window.md) ou uma janela de documento, selecione o recurso, por exemplo, `IDD_ABOUTBOX`.

1. No [janela de propriedades](/visualstudio/ide/reference/properties-window), selecione o **páginas de propriedade** botão.

   > [!TIP]
   > Para um atalho, sobre o **exibição** menu, selecione **páginas de propriedades**.

   O **página de propriedades** para o recurso será aberta exibindo uma visualização desse recurso. Em seguida, você pode usar o **para cima** e **para baixo** teclas de direção para navegar na árvore de controle na **exibição de recurso** ou a janela do documento. O **página de propriedades** será permanecer aberta e mostrará a qualquer recurso que tem o foco e pode ser visualizado.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Identificadores de recurso (símbolos)](../windows/symbols-resource-identifiers.md)<br/>