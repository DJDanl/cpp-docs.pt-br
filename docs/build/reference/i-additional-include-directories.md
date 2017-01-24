---
title: "/I (diret&#243;rios de inclus&#227;o adicionais) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.AdditionalIncludeDirectories"
  - "VC.Project.VCCLCompilerTool.AdditionalIncludeDirectories"
  - "/I"
  - "VC.Project.VCNMakeTool.IncludeSearchPath"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /I (C++)"
  - "Opção de compilador Diretórios de Inclusão Adicionais"
  - "Opção de compilador I [C++]"
  - "Opção de compilador -I [C++]"
  - "incluir diretórios, Opção de compilador  (C++)"
  - "definir diretórios de inclusão"
ms.assetid: 3e9add2a-5ed8-4d15-ad79-5b411e313a49
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /I (diret&#243;rios de inclus&#227;o adicionais)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Adiciona um diretório à lista de diretórios pesquisados por incluem arquivos.  
  
## Sintaxe  
  
```  
/I[ ]directory  
```  
  
## Arguments  
 `directory`  
 O diretório a ser adicionado à lista de diretórios pesquisados por inclui arquivos.  
  
## Comentários  
 Para adicionar mais de um diretório, use essa opção para mais de uma vez.  Os diretórios são pesquisados apenas até que inclui o arquivo especificados forem localizados.  
  
 Você pode usar essa opção com o padrão ignorar inclui a opção dos caminhos[\/X \(ignorar caminhos de inclusão padrão\)](../../build/reference/x-ignore-standard-include-paths.md)\(\).  
  
 Pesquisas de compilador para diretórios na seguinte ordem:  
  
1.  Diretórios contendo o arquivo de origem.  
  
2.  Diretórios especificados com a opção de **\/I** , na ordem em que o CL os encontra.  
  
3.  Diretórios especificados na variável de ambiente de **INCLUDE** .  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Geral** .  
  
4.  Modifique a propriedade de **Diretórios de Inclusão Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalIncludeDirectories%2A>.  
  
## Exemplo  
 O comando a seguir procura arquivos incluir solicitados por MAIN.c na seguinte ordem: primeiro no diretório conter MAIN.c, no diretório \\INCLUDE, então no diretório \\MY\\INCLUDE e, finalmente nos diretórios atribuídos à variável de ambiente INCLUDE.  
  
```  
CL /I \INCLUDE /I\MY\INCLUDE MAIN.C  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)