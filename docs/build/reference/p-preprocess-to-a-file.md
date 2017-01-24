---
title: "/P (pr&#233;-processar em um arquivo) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.GeneratePreprocessedFile"
  - "/p"
  - "VC.Project.VCCLWCECompilerTool.GeneratePreprocessedFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /P (C++)"
  - "arquivos de saída, pré-processador"
  - "Opção de compilador P [C++]"
  - "Opção de compilador -P [C++]"
  - "pré-processando arquivos de saída"
ms.assetid: 123ee54f-8219-4a6f-9876-4227023d83fc
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /P (pr&#233;-processar em um arquivo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Preprocesses arquivos de origem de 2.0 C e C\+\+ e grava a saída pré\-processados para um arquivo.  
  
## Sintaxe  
  
```  
/P  
```  
  
## Comentários  
 O arquivo tem o mesmo nome de base que o arquivo de origem e uma extensão de .i.  No processo, todas as políticas de pré\-processador são realizadas, as expansões macro são executadas, e os comentários são removidos.  Para preservar comentários na saída pré\-processados, use a opção de [\/C \(preservar comentários durante o pré\-processamento\)](../../build/reference/c-preserve-comments-during-preprocessing.md) junto com **\/P**.  
  
 adiciona**\/P** políticas de `#line` à saída, no início e o término de cada arquivo incluído e delimitando as linhas removidas por políticas de pré\-processador para a compilação condicional.  Essas políticas renumber as linhas do arquivo pré\-processados.  No resultado, os erros gerados durante estados avançadas de processamento se referem aos números de linhas do arquivo de origem original em vez de linhas no arquivo pré\-processados.  Para suprimir a geração de políticas de `#line` , use [\/EP \(pré\-processar para stdout sem diretivas \#line\)](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) bem como de **\/P**.  
  
 A opção de **\/P** suprime a compilação.  Não gerencia um arquivo de .obj, mesmo se você usar [\/Fo \(Nome do arquivo de objeto\)](../../build/reference/fo-object-file-name.md).  Você deve enviar novamente o arquivo pré\-processados para a compilação.  **\/P** também elimina os arquivos de saída de **\/FA**, de **\/Fa**, e as opções de **\/Fm** .  Para obter mais informações, consulte [\/FA, \/Fa \(listando arquivo\)](../../build/reference/fa-fa-listing-file.md) e [\/Fm \(mapfile de nome\)](../Topic/-Fm%20\(Name%20Mapfile\).md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Pré\-Processador** .  
  
4.  Modifique a propriedade de **Gerar Arquivo Pré\-Processado** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GeneratePreprocessedFile%2A>.  
  
## Exemplo  
 A linha de comando a seguir preprocesses `ADD.C`, preserva comentários, adiciona políticas de `#line` , e grava o resultado em um arquivo, `ADD.I`:  
  
```  
CL /P /C ADD.C  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [\/Fi \(pré\-processar nome do arquivo de saída\)](../../build/reference/fi-preprocess-output-file-name.md)