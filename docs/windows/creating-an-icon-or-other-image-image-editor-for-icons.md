---
title: Criando um ícone ou outra imagem (editor de imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.bitmap
helpviewer_keywords:
- bitmaps [C++]
- images [C++], creating
- resources [C++], creating images
- bitmaps [C++], creating
- graphics [C++], creating
- Image editor [C++], creating images
ms.assetid: 66db3fb2-cfc1-48a2-9bdd-53f61eb7ee30
ms.openlocfilehash: 45a119114c26513788b2cdc134e4258e42cf896d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50503263"
---
# <a name="creating-an-icon-or-other-image-image-editor-for-icons"></a>Criando um ícone ou outra imagem (editor de imagens para ícones)

Você pode criar uma nova imagem (bitmap, ícone, cursor ou barra de ferramentas) e usar o editor de imagens para personalizar sua aparência. Você também pode criar um novo bitmap em conformidade com um [modelo](../windows/how-to-use-resource-templates.md).

### <a name="to-add-a-new-image-resource-to-an-unmanaged-c-project"></a>Para adicionar um novo recurso de imagem a um projeto de C++ não gerenciado

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **inserir recurso** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode simplesmente com o botão direito do **Cursor** pasta e selecione **Cursor inserir** no menu de atalho.)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione o tipo de recurso de imagem que você deseja criar (**Bitmap**, por exemplo), em seguida, clique em **New**.

   Se um sinal de adição (**+**) é exibido ao lado do tipo de recurso de imagem no **inserir recurso** caixa de diálogo, isso significa que os modelos de barra de ferramentas estão disponíveis. Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em **New**.

### <a name="to-add-a-new-image-resource-to-a-project-in-a-net-programming-language"></a>Para adicionar um novo recurso de imagem a um projeto em uma linguagem de programação do .NET

1. Na **Gerenciador de soluções**, clique na pasta de projeto (por exemplo, `WindowsApplication1`).

2. No menu de atalho, clique em **Add**, em seguida, escolha **Adicionar Novo Item**.

3. No **categorias** painel, expanda o **itens de projeto locais** pasta, em seguida, escolha **recursos**.

4. No **modelos** painel, escolha o tipo de recurso que você deseja adicionar ao seu projeto.

   O recurso é adicionado ao seu projeto no **Gerenciador de soluções** e o recurso é aberto na [editor de imagens](../windows/image-editor-for-icons.md). Agora você pode usar todas as ferramentas disponíveis no editor de imagem para modificar sua imagem. Para obter mais informações sobre como adicionar imagens a um projeto gerenciado, consulte [carregando uma imagem em tempo de Design](/dotnet/framework/winforms/controls/how-to-load-a-picture-using-the-designer-windows-forms).

   > [!NOTE]
   > Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos. Para obter mais informações, consulte [criando arquivos de recurso](/dotnet/framework/resources/creating-resource-files-for-desktop-apps) na *guia do desenvolvedor do .NET Framework*.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)<br/>
[Convertendo bitmaps em barras de ferramentas](../windows/converting-bitmaps-to-toolbars.md)<br/>
[Criando novas barras de ferramentas](../windows/creating-new-toolbars.md)<br/>
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)