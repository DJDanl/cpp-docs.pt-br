---
title: "/Fd (nome do arquivo de banco de dados do programa) | Microsoft Docs"
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
  - "/FD"
  - "VC.Project.VCCLWCECompilerTool.ProgramDataBaseFileName"
  - "VC.Project.VCCLCompilerTool.ProgramDataBaseFileName"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos .pdb, criando"
  - "Opção de compilador /FD (C++)"
  - "Opção de compilador FD [C++]"
  - "Opção de compilador -FD [C++]"
  - "arquivos PDB, criando"
  - "Opção de compilador de banco de dados de programa [C++]"
  - "nome de arquivo de banco de dados de programa [C++]"
ms.assetid: 3977a9ed-f0ac-45df-bf06-01cedd2ba85a
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Fd (nome do arquivo de banco de dados do programa)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica um nome para o arquivo \(PDB\) de base de dados do programa criado por [\/Z7, \/Zi, \/ZI \(depurar formato de informações\)](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md).  
  
## Sintaxe  
  
```  
/Fdpathname  
```  
  
## Comentários  
 Sem **\/Fd**, o nome de arquivo PDB assume como padrão VC a`x`0.pdb., onde `x` é a versão principal do Visual C\+\+ em uso.  
  
 Se você especificar um nome de caminho que não inclua um nome de arquivo \(o caminho termina na barra invertida\), o compilador cria um arquivo .pdb nomeada VC`x`0.pdb no diretório especificado.  
  
 Se você especificar um nome de arquivo que não inclui uma extensão, o compilador usa .pdb como a extensão.  
  
 Essa opção também nomear o arquivo de estado \(.idb\) usado para a recriação mínima e a compilação incremental.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **ARQUIVOS DE SAÍDA** .  
  
4.  Modifique a propriedade de **Nome de Arquivo de Banco de Dados de Programa** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ProgramDataBaseFileName%2A>.  
  
## Exemplo  
 Essa linha de comando cria um arquivo .pdb nomeada PROG.pdb e um arquivo de .idb nomeada PROG.idb:  
  
```  
CL /DDEBUG /Zi /FdPROG.PDB PROG.CPP  
```  
  
## Consulte também  
 [Opções do arquivo de saída \(\/F\)](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Especificando o nome de caminho](../Topic/Specifying%20the%20Pathname.md)