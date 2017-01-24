---
title: "/Yl (injetar refer&#234;ncia PCH para biblioteca de depura&#231;&#227;o) | Microsoft Docs"
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
  - "/yi"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Yl (C++)"
  - "Opção de compilador Yl [C++]"
  - "Opção de compilador -Yl [C++]"
ms.assetid: 8e4a396a-6790-4a9f-8387-df015a3220e7
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Yl (injetar refer&#234;ncia PCH para biblioteca de depura&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para criar uma biblioteca de depuração que usa cabeçalhos pré\-compilados e a compilação falhará.  
  
## Sintaxe  
  
```  
/Ylsymbol  
```  
  
```  
/Yl-  
```  
  
## Arguments  
 `symbol`  
 Um símbolo arbitrário a ser armazenado no módulo de objeto.  
  
 \-  
 Um sinal de menos \(\-\) que desabilita explicitamente a opção do compilador de **\/Yl** .  
  
## Comentários  
 Por padrão, o compilador usa a opção de **\/Yl** \(sem especificar *symbol*\).  A opção de **\/Yl** habilita o depurador para obter informações completas sobre tipos.  **\/Yl\-** desabilita comportamento padrão.  
  
 Quando você cria um módulo com **\/Yc** e **\/Yl**`symbol`, o compilador cria um símbolo semelhante ao \_\_@@\_PchSym\_@00… @ @`symbol`, onde as reticências \(...\) representam uma cadeia de caracteres vinculador\- gerado, e o coloca no módulo de objeto.  Qualquer arquivo de origem que você compile com este cabeçalho pré\-compilado se refere ao símbolo especificado, que faz com que o vinculador inclui o módulo de objeto e suas informações de depuração da biblioteca.  
  
 Usando esta opção, você pode gerar LNK1211.  Quando você especifica as opções de [\/Yc \(criar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yc-create-precompiled-header-file.md) e de [\/Z7, \/Zi, \/ZI \(depurar formato de informações\)](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) , o compilador cria um arquivo de cabeçalho pré\-compilado que contém informações de depuração.  Um erro pode ocorrer quando você armazena o cabeçalho pré\-compilado em uma biblioteca, usa a biblioteca para criar um módulo de objeto, e o código\-fonte não se refere a nenhuma das funções que o arquivo de cabeçalho pré\-compilado define o.  
  
 Para resolver o problema, especifique **\/Yl**`symbol`, onde `symbol` é o nome de um símbolo arbitrário na biblioteca, quando você cria um arquivo de cabeçalho pré\-compilado que não contém nenhuma definições de função.  Essa opção direciona o compilador para armazenar informações de depuração no arquivo de cabeçalho pré\-compilado.  
  
 Para obter mais informações sobre cabeçalhos pré\-compilados, consulte:  
  
-   [\/Y \(cabeçalhos pré\-compilados\)](../../build/reference/y-precompiled-headers.md)  
  
-   [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)