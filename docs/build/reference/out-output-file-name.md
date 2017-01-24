---
title: "/OUT (nome do arquivo de sa&#237;da) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.OutputFile"
  - "/out"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "opção de vinculador /OUT C++"
  - "vinculador [C++], arquivos de saída"
  - "opção de vinculador OUT"
  - "opção de vinculador -OUT"
  - "arquivos de saída, opção de vinculador de nome"
ms.assetid: 976210a4-e51f-4cfb-af5e-c16344455834
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /OUT (nome do arquivo de sa&#237;da)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/OUT:filename  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 Um nome especificado pelo usuário para o arquivo de saída.  Substitui o nome padrão.  
  
## Comentários  
 A opção \/OUT substitui o nome padrão e o local do programa que o vinculador cria.  
  
 Por padrão, o vinculador forma o nome de arquivo usando o nome de base do primeiro arquivo de .obj especificado e a extensão apropriada \(.exe ou .dll\).  
  
 Essa opção de base o nome padrão para uma biblioteca de .mapfile ou de importação.  Para obter detalhes, consulte [Gerencia Mapfile](../../build/reference/map-generate-mapfile.md) \(\/MAP\) e [\/IMPLIB](../Topic/-IMPLIB%20\(Name%20Import%20Library\).md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Geral** .  
  
4.  Modifique a propriedade de **Arquivo de Saída** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OutputFile%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)