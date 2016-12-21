---
title: "Editor bin&#225;rio | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.binary.F1"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "editores, binário"
  - "edição de recursos [Visual Studio]"
  - "editores de recursos, o editor binário"
  - "Editor Binário"
ms.assetid: 2483c48b-1252-4dbc-826b-82e6c1a0e9cb
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Editor bin&#225;rio
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!WARNING]
>  O Editor binário não está disponível nas edições Express.  
  
 Editor binário permite que você edite qualquer recurso no nível binário em formato hexadecimal ou ASCII. Você também pode usar o [comando localizar](../Topic/Find%20Command.md) para pesquisar cadeias de caracteres ASCII ou bytes hexadecimais. Você deve usar o editor binário somente quando você precisa exibir ou fazer pequenas alterações em recursos personalizados ou tipos de recurso não suportados pelo ambiente do Visual Studio.  
  
 Para abrir o Editor binário, primeiro escolha **arquivo &#124; Novo &#124; Arquivo** no menu principal, selecione o arquivo que você deseja editar, clique na seta suspensa ao lado de **Abrir** botão e escolha **Abrir com &#124; Editor binário**.  
  
> [!CAUTION]
>  Edição de recursos, como caixas de diálogo, imagens ou menus no editor binário é perigoso. A edição incorreta pode corromper o recurso, tornando\-as ilegíveis em seu editor nativo.  
  
> [!TIP]
>  Ao usar o editor binário, em muitos casos, clique para exibir um menu de atalho de comandos específicos do recurso. Os comandos disponíveis dependem do que o cursor está apontando. Por exemplo, se você clicar em enquanto estiver apontando para o editor binário com valores hexadecimais selecionados, o menu de atalho mostra o **Recortar**, **cópia**, e **Colar** comandos.  
  
 Com o editor binário, você pode:  
  
-   [Abrir um recurso para edição binária](../mfc/opening-a-resource-for-binary-editing.md)  
  
-   [Editar dados binários](../mfc/editing-binary-data.md)  
  
-   [Localizar dados binários](../mfc/finding-binary-data.md)  
  
-   [Criar um novo recurso personalizado ou dados](../mfc/creating-a-new-custom-or-data-resource.md)  
  
## Recursos gerenciados  
 Você pode usar o [editor de imagem](../mfc/image-editor-for-icons.md) e o editor binário para trabalhar com arquivos de recursos em projetos gerenciados. Todos os recursos gerenciados que deseja editar devem ser recursos vinculados. Os editores de recursos do Visual Studio não dão suporte a edição de recursos inseridos.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
### Requisitos  
 Nenhum  
  
## Consulte também  
 [Editores de recursos](../mfc/resource-editors.md)