---
title: Arquivos de recurso (Visual Studio) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- resources [Visual Studio]
- .rc files
- resource files
- resource script files
- resource script files, Win-32 based applications
- resource script files, files updated when editing resources
- resources [Visual Studio], types of resource files
- rct files
- resources [C++]
- rc files
- resource files, types of
- .rct files
- resource script files, unsupported types
ms.assetid: 4d2b6fcc-07cf-4289-be87-83a60f69533c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 117472c764dd6f13858881275b067600579a0fc8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-files-visual-studio"></a>Arquivos de recurso (Visual Studio)
> [!NOTE]
>  Este material se aplica a aplicativos de área de trabalho do Windows. Para obter informações sobre recursos em aplicativos de plataforma Universal do Windows, consulte [definindo recursos do aplicativo](http://msdn.microsoft.com/en-us/476ea844-632c-4467-9ce3-966be1350dd4).  
>   
> Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
>  
> Como projetos em linguagens de programação .NET não usa arquivos de script de recurso, você deve abrir os recursos de **Gerenciador de soluções**. Você pode usar o [editor de imagem](../windows/image-editor-for-icons.md) e [editor binário](binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que você deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não oferecem suporte à edição de recursos inseridos.  
  
 O termo "arquivo de recurso" pode se referir a um número de tipos de arquivo, incluindo:  
  
-   O arquivo de script (. rc) do recurso de um programa.  
  
-   Um arquivo de modelo (. rct) do recurso.  
  
-   Um recurso individual existente como um arquivo autônomo, como um arquivo de bitmap, ícone ou cursor que é chamado de um arquivo. rc.  
  
-   Um arquivo de cabeçalho gerado pelo ambiente de desenvolvimento, por exemplo Resource.h, que é chamado de um arquivo. rc.  
  
 Recursos também podem ser encontrados em [outros tipos de arquivo](../windows/editable-file-types-for-resources.md) como arquivos. res,. dll e .exe. Você pode trabalhar com recursos e arquivos de recurso de dentro de seu projeto e com aqueles que não fazem parte do projeto atual. Você também pode trabalhar com arquivos de recursos que não foram criados no ambiente de desenvolvimento do Visual Studio. Por exemplo, você pode:  
  
-   Trabalhar com arquivos de recursos aninhados e incluídas condicionalmente.  
  
-   Atualizar recursos existentes ou convertê-los para o formato do Visual C++.  
  
-   Importar ou exportar recursos gráficos para ou do arquivo de recurso atual.  
  
-   Inclua compartilhados ou somente leitura identificadores (símbolos) que não podem ser modificados pelo ambiente de desenvolvimento.  
  
-   Inclua recursos em seu arquivo executável (.exe) que não exigem a edição (ou que você não deseja ser editado) durante o projeto atual, como os recursos que são compartilhados entre vários projetos.  
  
-   Inclua tipos de recursos não suportados pelo ambiente de desenvolvimento.  
  
 Esta seção abrange:  
  
-   [Criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md)  
  
-   [Criando um novo recurso](../windows/how-to-create-a-resource.md)  
  
-   [Exibindo recursos em um arquivo de Script de recurso](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)  
  
-   [Abrir um arquivo de Script de recurso no formato de texto](../windows/how-to-open-a-resource-script-file-in-text-format.md)  
  
-   [Incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md)  
  
-   [Copiando recursos](../windows/how-to-copy-resources.md)  
  
-   [Usando modelos de recursos (. rct)](../windows/how-to-use-resource-templates.md)  
  
-   [Importar e exportar recursos](../windows/how-to-import-and-export-resources.md)  
  
-   [Tipos de arquivo editáveis para recursos](../windows/editable-file-types-for-resources.md)  
  
-   [Arquivos afetados pela edição de recurso](../windows/files-affected-by-resource-editing.md)  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editores de recursos](../windows/resource-editors.md)   
 [Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)   
 [Menus e outros recursos](http://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)

