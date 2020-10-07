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
ms.openlocfilehash: f854f3cc6e61e3022e784befc738bf28c1adeb6c
ms.sourcegitcommit: 30792632548d1c71894f9fecbe2f554294b86020
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/06/2020
ms.locfileid: "91765244"
---
# <a name="resource-editors-c"></a>Editores de recursos (C++)

Um editor de recursos é um ambiente especializado para criar ou modificar recursos que são incluídos em um projeto do Visual Studio. Os editores de recursos do Visual Studio compartilham técnicas e interfaces para ajudá-lo a criar e modificar recursos de aplicativos de forma rápida e fácil. Os editores de recursos permitem exibir e editar recursos no editor apropriado e recursos de visualização.

O editor apropriado é aberto automaticamente quando você cria ou abre um recurso.

> [!NOTE]
> Como os projetos gerenciados não usam arquivos de script de recurso, você deve abrir seus recursos de **Gerenciador de soluções**. Você pode usar o [Editor de imagem](../windows/image-editor-for-icons.md) e o [Editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.

|Use o...|Para editar...|
|----------------|----------------|
|[Editor de acelerador](../windows/accelerator-editor.md)|Tabelas de aceleração em projetos do Visual Studio C++.|
|[Editor de binários](binary-editor.md)|Informações de dados binários e recursos personalizados em projetos Visual C++, Visual Basic ou Visual C#.|
|[Editor de diálogo](../windows/dialog-editor.md)|Caixas de diálogo em projetos do Visual Studio C++.|
|[Editor de imagem](../windows/image-editor-for-icons.md)|Bitmaps, ícones, cursores e outros arquivos de imagem em projetos Visual C++, Visual Basic ou Visual C#.|
|[Editor de menu](../windows/menu-editor.md)|Recursos de menu em projetos do Visual Studio C++.|
|[Editor de faixa de Ribbon](../mfc/ribbon-designer-mfc.md)|Recursos da faixa de das de MFC.|
|[Editor de cadeia de caracteres](../windows/string-editor.md)|Tabelas de cadeia de caracteres em projetos do Visual Studio C++.|
|[Editor de barra de ferramentas](../windows/toolbar-editor.md)|Recursos da barra de ferramentas em projetos do Visual Studio C++. O **Editor de barra de ferramentas** faz parte do **Editor de imagem**.|
|[Editor de informações de versão](../windows/version-information-editor.md)|Informações de versão em projetos do Visual Studio C++.|

> [!NOTE]
> Se o seu projeto ainda não contiver um arquivo. rc, consulte [como: criar recursos](../windows/how-to-create-a-resource-script-file.md).

## <a name="view-and-edit-resources"></a>Exibir e editar recursos

Cada tipo de recurso tem um editor de recursos específico para esse tipo de recurso. Você pode reorganizar, redimensionar, adicionar controles e recursos ou, de outra forma, modificar aspectos de um recurso usando o editor associado. Você também pode editar um recurso em formato de texto e formato binário. Para obter mais informações, consulte [como: criar recursos](../windows/how-to-create-a-resource-script-file.md).

Alguns tipos de recursos são arquivos individuais que podem ser importados e usados de várias maneiras; Eles incluem bitmaps, ícones, cursores, barras de ferramentas e arquivos HTML. Esses recursos têm nomes de arquivo e [identificadores de recurso](../windows/symbols-resource-identifiers.md). Outros, como caixas de diálogo, menus e tabelas de cadeia de caracteres em projetos Win32, existem somente como parte de um arquivo de script de recurso (. rc) ou de um arquivo de modelo de recurso (. rct).

Os recursos também podem ser editados fora do projeto sem que o projeto seja aberto. Para obter mais informações, consulte [como: criar recursos](./how-to-create-a-resource-script-file.md).

> [!NOTE]
> As propriedades de um recurso podem ser modificadas usando a janela **Propriedades** .

- Para editar as propriedades de um recurso, em [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources), clique com o botão direito do mouse no recurso que você deseja editar e escolha **Propriedades**.  Em seguida, no [janela Propriedades](/visualstudio/ide/reference/properties-window), altere as propriedades do recurso.

- Para desfazer uma alteração feita nas propriedades de um recurso, verifique se o recurso tem foco em **modo de exibição de recursos** e escolha **desfazer** no menu **Editar** .

### <a name="win32-resources"></a>Recursos do Win32

Você pode acessar recursos do Win32 no painel de [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources) .

#### <a name="to-view-a-win32-resource-in-a-resource-editor"></a>Para exibir um recurso do Win32 em um editor de recursos

1. Vá para o menu **Exibir**  >  **outras**  >  **modo de exibição de recursos**do Windows.

1. Se a janela de **modo de exibição de recursos** não for a janela superior, selecione a guia **modo de exibição de recursos** para trazê-la para a parte superior.

1. Em **modo de exibição de recursos**, expanda a pasta do projeto que contém os recursos que você deseja exibir. Por exemplo, se você quiser exibir um recurso de caixa de diálogo, expanda a pasta **caixa de diálogo** .

1. Clique duas vezes no recurso, por exemplo, **IDD_ABOUTBOX**.

   O recurso é aberto no editor apropriado. Por exemplo, para recursos de caixa de diálogo, o recurso é aberto dentro do **Editor de caixa de diálogo**.

#### <a name="to-delete-an-existing-win32-resource"></a>Para excluir um recurso Win32 existente

1. Em **modo de exibição de recursos**, expanda o nó para um tipo de recurso.

1. Clique com o botão direito do mouse no recurso que você deseja excluir e escolha **excluir**.

> [!TIP]
> Você também pode usar esse método quando tiver o arquivo. rc aberto em uma janela de documento fora de um projeto.

### <a name="managed-project-resources"></a>Recursos de projeto gerenciado

Como os projetos gerenciados não usam arquivos de script de recurso, você deve abrir seus recursos de **Gerenciador de soluções**. Use o [Editor de imagem](../windows/image-editor-for-icons.md) e o [Editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Os recursos gerenciados que você deseja editar devem ser recursos vinculados e os editores de recursos do Visual Studio não dão suporte à edição de recursos incorporados.

- Para exibir um recurso gerenciado em um editor de recursos, em **Gerenciador de soluções**, clique duas vezes no recurso, por exemplo, *Bitmap1.bmp*, e o recurso será aberto no editor apropriado.

- Para excluir um recurso gerenciado existente, em **Gerenciador de soluções**, clique com o botão direito do mouse no recurso que você deseja excluir e escolha **excluir**.

## <a name="preview-resources"></a>Recursos de visualização

Visualize seus recursos para permitir que você exiba recursos gráficos sem abri-los. A visualização também é útil para executáveis depois de você tê-los compilados, pois os identificadores de recurso são alterados para números. Como esses identificadores numéricos geralmente não fornecem informações suficientes, a visualização dos recursos ajuda você a identificá-los rapidamente.

Os seguintes tipos de recursos fornecem uma visualização de layout visual: bitmap, caixa de diálogo, ícone, menu, cursor, barra de ferramentas

Os recursos a seguir não fornecem uma visualização Visual: acelerador, manifesto, tabela de cadeia de caracteres, informações de versão

> [!NOTE]
> Para visualizar os recursos, é necessário o Win32.

### <a name="to-preview-resources"></a>Para Visualizar recursos

1. No [modo de exibição de recursos](how-to-create-a-resource-script-file.md#create-resources) ou em uma janela de documento, selecione seu recurso, por exemplo, **IDD_ABOUTBOX**.

1. No [janela Propriedades](/visualstudio/ide/reference/properties-window), selecione o botão **páginas de propriedades** .

   > [!TIP]
   > Use um atalho, vá para o menu **Exibir**  >  **páginas de propriedades**.

   A página de **Propriedades** do recurso é aberta exibindo uma visualização desse recurso. Você pode usar as teclas de seta para **cima** e para **baixo** para navegar pelo controle de árvore em **modo de exibição de recursos** ou na janela do documento. A página de **Propriedades** permanecerá aberta e mostrará qualquer recurso que tenha foco e possa ser visualizado.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Confira também

[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Identificadores de recurso (símbolos)](../windows/symbols-resource-identifiers.md)<br/>
