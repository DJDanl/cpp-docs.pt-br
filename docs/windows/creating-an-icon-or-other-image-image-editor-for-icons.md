---
title: Criando um ícone ou outra imagem (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.bitmap
dev_langs:
- C++
helpviewer_keywords:
- bitmaps [C++]
- images [C++], creating
- resource toolbars
- resources [Visual Studio], creating images
- bitmaps [C++], creating
- graphics [C++], creating
- Image editor [C++], creating images
ms.assetid: 66db3fb2-cfc1-48a2-9bdd-53f61eb7ee30
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2138e32b18f2e15de027e3cc04fb1bd7ee46ecd5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33874727"
---
# <a name="creating-an-icon-or-other-image-image-editor-for-icons"></a>Criando um ícone ou outra imagem (editor de imagens para ícones)
Você pode criar uma nova imagem (bitmap, ícone, cursor ou barra de ferramentas) e usar o editor de imagens para personalizar sua aparência. Você também pode criar um novo bitmap padronizado depois um [modelo](../windows/how-to-use-resource-templates.md).  
  
### <a name="to-add-a-new-image-resource-to-an-unmanaged-c-project"></a>Para adicionar um novo recurso de imagem a um projeto de C++ não gerenciado  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), clique com o arquivo. RC e escolha **inserir recursos** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode simplesmente clique o **Cursor** pasta e selecione **inserir Cursor** no menu de atalho.)  
  
    > [!NOTE]
    >  **Observação** se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione o tipo de recurso de imagem que você deseja criar (**Bitmap**, por exemplo), em seguida, clique em **novo**.  
  
     Se um sinal de adição (**+**) é exibido ao lado de tipo de recurso de imagem no **inserir recursos** caixa de diálogo, isso significa que os modelos de barra de ferramentas estão disponíveis. Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em **novo**.  
  
### <a name="to-add-a-new-image-resource-to-a-project-in-a-net-programming-language"></a>Para adicionar um novo recurso de imagem a um projeto em uma linguagem de programação do .NET  
  
1.  Em **Solution Explorer**, com o botão direito na pasta do projeto (por exemplo, **WindowsApplication1**).  
  
2.  No menu de atalho, clique em **adicionar**, em seguida, escolha **Adicionar Novo Item**.  
  
3.  No **categorias** painel, expanda o **itens de projeto Local** pasta, escolha **recursos**.  
  
4.  No **modelos** painel, escolha o tipo de recurso que você deseja adicionar ao seu projeto.  
  
     O recurso é adicionado ao seu projeto no Gerenciador de soluções e o recurso é aberto no [editor de imagem](../windows/image-editor-for-icons.md). Agora você pode usar todas as ferramentas disponíveis no editor de imagem para modificar sua imagem. Para obter mais informações sobre como adicionar imagens a um projeto gerenciado, consulte [carregar uma imagem em tempo de Design](/dotnet/framework/winforms/controls/how-to-load-a-picture-using-the-designer-windows-forms).  
  
    > [!NOTE]
    >  Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos. Para obter mais informações, consulte [criar arquivos de recurso](/dotnet/framework/resources/creating-resource-files-for-desktop-apps) no *guia do desenvolvedor do .NET Framework*.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)   
 [Convertendo Bitmaps em barras de ferramentas](../windows/converting-bitmaps-to-toolbars.md)   
 [Criando novas barras de ferramentas](../windows/creating-new-toolbars.md)   
 [Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)   
 [Editor de imagens para ícones](../windows/image-editor-for-icons.md)

