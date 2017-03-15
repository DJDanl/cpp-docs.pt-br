---
title: "/DEF (especificar arquivo de defini&#231;&#227;o do m&#243;dulo) | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.ModuleDefinitionFile"
  - "/def"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /DEF"
  - "opção de vinculador DEF"
  - "opção de vinculador -DEF"
  - "arquivos de definição de módulo"
  - "arquivos de definição de módulo, especificando"
ms.assetid: 6497fa68-65f0-48ca-8f66-b87166fc631a
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /DEF (especificar arquivo de defini&#231;&#227;o do m&#243;dulo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/DEF:filename  
```  
  
## Comentários  
 onde:  
  
 *filename*  
 O nome de um arquivo do definição \(.def\) a ser passado para o vinculador.  
  
## Comentários  
 A opção \/DEF passa um arquivo do definição \(.def\) ao vinculador.  Apenas um arquivo .def pode ser especificado COMO VINCULAR.  Para obter detalhes sobre arquivos de [Arquivos de definição o](../Topic/Module-Definition%20\(.Def\)%20Files.md).def, consulte.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Entrada** .  
  
4.  Modifique a propriedade de **Arquivo de Definição de Módulo** .  
  
 Para especificar um arquivo .def de dentro do ambiente de desenvolvimento, você deverá adicioná\-la ao projeto com outros arquivos e especificar o arquivo para a opção do \/DEF.  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ModuleDefinitionFile%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)