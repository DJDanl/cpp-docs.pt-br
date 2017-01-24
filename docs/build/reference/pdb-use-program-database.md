---
title: "/PDB (usar banco de dados do programa) | Microsoft Docs"
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
  - "/pdb"
  - "VC.Project.VCLinkerTool.ProgramDatabaseFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos .pdb, criando"
  - "Opção de vinculador /PDB"
  - "arquivos PDB, criando"
  - "opção de vinculador PDB"
  - "opção de vinculador -PDB"
ms.assetid: d23db0ce-10cb-427a-bc60-d6b2a852723d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /PDB (usar banco de dados do programa)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/PDB:filename  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 Um nome especificado pelo usuário para o base de dados \(PDB\) de programa que o vinculador cria.  Substitui o nome padrão.  
  
## Comentários  
 Por padrão, quando [\/DEBUG](../../build/reference/debug-generate-debug-info.md) for especificado, o vinculador cria um base de dados \(PDB\) de programa que contém informações de depuração.  O nome de arquivo padrão para o PDB tem o nome de base de programa e a extensão .pdb.  
  
 Use \/PDB:*nome de arquivo* para especificar o nome do arquivo PDB.  \/DEBUG Se não for especificado, a opção \/PDB será ignorada.  
  
 Um arquivo PDB pode ser até GB.  
  
 Para obter mais informações, consulte [arquivos .pdb como a entrada do vinculador](../../build/reference/dot-pdb-files-as-linker-input.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Depurar** .  
  
4.  Modifique a propriedade de **Gerar Arquivo de Banco de Dados de Programa** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ProgramDatabaseFile%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)