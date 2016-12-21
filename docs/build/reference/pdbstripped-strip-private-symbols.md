---
title: "/PDBSTRIPPED (remover s&#237;mbolos privados) | Microsoft Docs"
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
  - "/pdbstripped"
  - "VC.Project.VCLinkerTool.StripPrivateSymbols"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos .pdb, retirando símbolos privados"
  - "Opção de vinculador /PDBSTRIPPED"
  - "arquivos PDB, retirando símbolos privados"
  - "opção de vinculador PDBSTRIPPED"
  - "opção de vinculador -PDBSTRIPPED"
ms.assetid: 9b9e0070-6a13-4142-8180-19c003fbbd55
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /PDBSTRIPPED (remover s&#237;mbolos privados)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/PDBSTRIPPED:pdb_file_name  
```  
  
## Comentários  
 onde:  
  
 *pdb\_file\_name*  
 Um nome especificado pelo usuário para o base de dados \(PDB\) retirado de programa que o vinculador cria.  
  
## Comentários  
 A opção \/PDBSTRIPPED cria um segundo arquivo \(PDB\) de base de dados do programa quando você cria a imagem de programa com qualquer uma das opções do compilador ou do vinculador que gerencia um arquivo PDB \([\/DEBUG](../../build/reference/debug-generate-debug-info.md), [\/Z7](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md), \/Zd, \/Zi ou\).  Este segundo arquivo PDB omite os símbolos que você não desejaria enviar aos seus clientes.  O segundo arquivo PDB conterá somente:  
  
-   Símbolos públicos  
  
-   A lista de arquivos de objeto e as partes do executável em que contribuem  
  
-   Registros de depuração de \(FPO\) de otimização do ponteiro do quadro usados para atravessar a pilha  
  
 O arquivo PDB eliminado não conterá:  
  
-   Informações de tipo  
  
-   Linha informações de número  
  
-   Símbolos de CodeView de arquivo do objeto como aqueles para funções, locais, e dados estáticos  
  
 O arquivo PDB completo será produzido ainda quando você usa o \/PDBSTRIPPED.  
  
 Se você não criar um arquivo PDB, \/PDBSTRIPPED será ignorado.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Depurar** .  
  
4.  Modifique a propriedade de **Segmentar Símbolos Privados** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.StripPrivateSymbols%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)