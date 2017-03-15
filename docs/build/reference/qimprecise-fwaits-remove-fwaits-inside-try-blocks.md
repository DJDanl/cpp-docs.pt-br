---
title: "/Qimprecise_fwaits (remover fwaits dentro de blocos Try) | Microsoft Docs"
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
  - "/Qimprecise_fwaits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Qimprecise_fwaits (C++)"
  - "Opção de compilador -Qimprecise_fwaits (C++)"
ms.assetid: b1501f21-7e08-4fea-95e8-176ec03a635b
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Qimprecise_fwaits (remover fwaits dentro de blocos Try)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Remove os comandos de `fwait` internos aos blocos de `try` quando você usa a opção do compilador de [\/fp: exceto](../../build/reference/fp-specify-floating-point-behavior.md) .  
  
## Sintaxe  
  
```  
/Qimprecise_fwaits  
```  
  
## Comentários  
 Essa opção não terá efeito se **\/fp:except** não também for especificado.  Se você especificar a opção de **\/fp:except** , o compilador inserirá um comando de `fwait` ao redor de cada linha de código em um bloco de `try` .  Desse modo, o compilador pode identificar a linha de código específica que gerencia uma exceção.  **\/Qimprecise\_fwaits** remove as instruções internas de `fwait` , deixando apenas as esperas em torno do bloco de `try` .  Isso melhora o desempenho, mas o compilador somente poderá dizer que o bloco de `try` causa uma exceção, que não se alinham.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/Q Opções \(operações de nível baixo\)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)