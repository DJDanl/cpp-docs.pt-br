---
title: "Arquivos de recurso (Visual Studio) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "recursos [Visual Studio]"
  - "Arquivos .rc"
  - "arquivos de recurso"
  - "arquivos de script de recurso"
  - "arquivos de script de recurso, aplicativos baseados no Win32"
  - "arquivos de script de recurso, os arquivos atualizados ao editar recursos"
  - "recursos [Visual Studio], tipos de arquivos de recurso"
  - "arquivos rct"
  - "recursos [C++]"
  - "arquivos rc"
  - "tipos de arquivos de recursos"
  - "Arquivos .rct"
  - "arquivos de script de recursos, tipos sem suporte"
ms.assetid: 4d2b6fcc-07cf-4289-be87-83a60f69533c
caps.latest.revision: 18
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos de recurso (Visual Studio)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Esse material se aplica a aplicativos de área de trabalho do Windows. Para obter informações sobre os recursos na [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos, consulte [definindo recursos do aplicativo](http://msdn.microsoft.com/pt-br/476ea844-632c-4467-9ce3-966be1350dd4).  
>   
>  Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Como os projetos em linguagens de programação .NET não usar arquivos de script de recurso, você deve abrir seus recursos de **Solution Explorer**. Você pode usar o [editor de imagem](../mfc/image-editor-for-icons.md) e [editor binário](../mfc/binary-editor.md) para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não dão suporte a edição de recursos inseridos. Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
 O termo "arquivo de recurso" pode fazer referência a um número de tipos de arquivo, incluindo:  
  
-   O arquivo de script \(. rc\) do recurso de um programa.  
  
-   Um arquivo de modelo \(. rct\) do recurso.  
  
-   Um recurso individual existente como um arquivo autônomo, como um arquivo de bitmap, ícone ou cursor que é chamado de um arquivo. rc.  
  
-   Um arquivo de cabeçalho gerado pelo ambiente de desenvolvimento, por exemplo Resource.h, que é chamado de um arquivo. rc.  
  
 Recursos também podem ser encontrados em [outros tipos de arquivo](../windows/editable-file-types-for-resources.md) como .exe, arquivos. dll e. res. Você pode trabalhar com recursos e arquivos de recurso do seu projeto e aqueles que não fazem parte do projeto atual. Você também pode trabalhar com arquivos de recursos que não foram criados no ambiente de desenvolvimento do Visual Studio. Por exemplo, você pode:  
  
-   Trabalhar com arquivos de recursos aninhados e incluídas condicionalmente.  
  
-   Atualizar recursos existentes ou convertê\-los para o formato do Visual C\+\+.  
  
-   Importar ou exportar recursos gráficos para ou do arquivo de recurso atual.  
  
-   Inclua compartilhados ou somente leitura identificadores \(símbolos\) que não podem ser modificados pelo ambiente de desenvolvimento.  
  
-   Inclua recursos em seu arquivo executável \(.exe\) que não exigem a edição \(ou que você não deseja que sejam editados\) durante o projeto atual, como os recursos são compartilhados entre vários projetos.  
  
-   Inclua os tipos de recurso não suportados pelo ambiente de desenvolvimento.  
  
 Esta seção aborda:  
  
-   [Criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md)  
  
-   [Criar um novo recurso](../windows/how-to-create-a-resource.md)  
  
-   [Exibindo recursos em um arquivo de Script de recurso](../windows/how-to-open-a-resource-script-file-outside-of-a-project-standalone.md)  
  
-   [Abrindo um arquivo de Script de recurso no formato de texto](../windows/how-to-open-a-resource-script-file-in-text-format.md)  
  
-   [Incluindo recursos em tempo de compilação](../Topic/How%20to:%20Include%20Resources%20at%20Compile%20Time.md)  
  
-   [Copiando recursos](../windows/how-to-copy-resources.md)  
  
-   [Usando modelos de recursos \(. rct\)](../Topic/How%20to:%20Use%20Resource%20Templates.md)  
  
-   [Importação e exportação de recursos](../windows/how-to-import-and-export-resources.md)  
  
-   [Tipos de arquivo editáveis para recursos](../windows/editable-file-types-for-resources.md)  
  
-   [Arquivos afetados pela edição de recurso](../Topic/Files%20Affected%20by%20Resource%20Editing.md)  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Editores de recursos](../mfc/resource-editors.md)   
 [Trabalhando com arquivos de recurso](../mfc/working-with-resource-files.md)   
 [Menus e outros recursos](http://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)