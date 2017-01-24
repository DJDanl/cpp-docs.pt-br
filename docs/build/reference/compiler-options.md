---
title: "Op&#231;&#245;es do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "Compilador cl.exe"
  - "opções do compilador, C++"
  - "compilador IPF Visual C++"
  - "compilador Itanium Visual C++"
  - "compilador x64 Visual C++"
ms.assetid: ed3376c8-bef4-4c9a-80e9-3b5da232644c
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Op&#231;&#245;es do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

cl.exe é uma ferramenta que controla os compiladores Microsoft C e C\+\+ e o vinculador. cl.exe pode ser executado somente nos sistemas operacionais que suportam Microsoft Visual Studio.  
  
> [!NOTE]
>  É possível iniciar esta ferramenta somente usando o prompt de comando [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)].  Não é possível iniciá\-lo a partir de um prompt de comando do sistema ou do gerenciador de arquivos.  
  
 Os compiladores produzem arquivos de objeto \(.obj\) de COFF \(Common Object File Format\).  O vinculador gera arquivos executáveis \(.exe\) ou DLLs.  
  
 Observe que todas as opções de compilador diferenciam maiúsculas de minúsculas.  
  
 Para compilar sem vincular, use [\/c](../../build/reference/c-compile-without-linking.md).  
  
## Localizando uma opção  
 Para localizar uma opção específica do compilador, consulte uma das listas:  
  
-   [Opções de compilador listadas em ordem alfabética](../../build/reference/compiler-options-listed-alphabetically.md)  
  
-   [Opções de compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md)  
  
## Opções de Especificação  
 O tópico para cada opção de compilador discute como ele pode ser definido no ambiente de desenvolvimento.  Para obter informações sobre como especificar opções fora do ambiente de desenvolvimento, consulte:  
  
-   [Sintaxe da linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)  
  
-   [Arquivos de comando CL](../../build/reference/cl-command-files.md)  
  
-   [Variáveis de ambiente CL](../../build/reference/cl-environment-variables.md)  
  
## Ferramentas de compilação relacionadas  
 Use [NMAKE](../../build/nmake-reference.md) para criar o arquivo de saída.  
  
 Use [BSCMAKE](../../build/reference/bscmake-reference.md) para oferecer suporte à navegação de classe.  
  
 [Opções de vinculador](../../build/reference/linker-options.md) também afetam como o programa é criado.  
  
## Consulte também  
 [Referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Compilação rápida](../Topic/Fast%20Compilation.md)   
 [CL invoca o vinculador](../../build/reference/cl-invokes-the-linker.md)