---
title: "/LIBPATH (Libpath adicional) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/libpath"
  - "VC.Project.VCLinkerTool.AdditionalLibraryDirectories"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /LIBPATH"
  - "opção de vinculador Libpath Adicional"
  - "substituição de caminho de biblioteca de ambiente"
  - "opção de vinculador LIBPATH"
  - "opção de vinculador -LIBPATH"
  - "opção de vinculador de caminho de biblioteca"
ms.assetid: 7240af0b-9a3d-4d53-8169-2a92cd6958ba
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /LIBPATH (Libpath adicional)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/LIBPATH:dir  
```  
  
## Comentários  
 onde:  
  
 `dir`  
 Especifica um caminho que o vinculador pesquisar antes que pesquise o caminho especificado na opção de ambiente de LIB.  
  
## Comentários  
 Use a opção \/LIBPATH substituir o caminho da biblioteca de ambiente.  O vinculador pesquisará primeiro no caminho especificado por essa opção, e pesquise no caminho especificado na variável de ambiente de LIB.  Você só pode especificar um diretório para cada opção do \/LIBPATH que você digita.  Se desejar especificar mais de um diretório, você deve especificar várias opções do \/LIBPATH.  O vinculador pesquisará nos diretórios especificados na ordem.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Geral** .  
  
4.  Modifique a propriedade de **Diretórios de Biblioteca Adicionais** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalLibraryDirectories%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)