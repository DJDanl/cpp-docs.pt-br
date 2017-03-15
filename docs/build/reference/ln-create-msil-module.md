---
title: "/LN (criar m&#243;dulo MSIL) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/LN"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /LN (C++)"
  - "Opção de compilador -LN [C++]"
ms.assetid: 4f38f4f4-3176-4caf-8200-5c7585dc1ed3
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /LN (criar m&#243;dulo MSIL)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica que um manifesto do assembly não deve ser inserido no arquivo de saída.  
  
## Sintaxe  
  
```  
/LN  
```  
  
## Comentários  
 Por padrão, **\/LN** não é aplicado \(um manifesto do assembly é inserido no arquivo de saída\).  
  
 Quando **\/LN** é usado, uma das opções de [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) também deve ser usado.  
  
 Um programa gerenciado que não tem metadados de um assembly no manifesto é chamado em um módulo.  Se você compila com [\/c \(compilar sem vinculação\)](../../build/reference/c-compile-without-linking.md) e **\/LN**, especifique [\/NOASSEMBLY \(criar um módulo MSIL\)](../../build/reference/noassembly-create-a-msil-module.md) na fase do vinculador para criar o arquivo de saída.  
  
 Talvez você queira criar os módulos se você deseja utilizar uma abordagem à base de componentes a criar assemblies.  Ou seja, você pode criar tipos e criá\-las os módulos.  Em seguida, você pode gerar um assembly de um ou vários módulos.  Para obter mais informações sobre como criar assemblies os módulos, consulte [Arquivos .netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md) ou [Al.exe \(Assembly Linker\)](../Topic/Al.exe%20\(Assembly%20Linker\).md).  
  
 A extensão de arquivo padrão para um módulo é .netmodule.  
  
 Em versões de [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] antes do Visual C\+\+ 2005, um módulo foi criado com **\/clr:noAssembly**.  
  
 O vinculador Visual C\+\+ aceita arquivos de .netmodule como a entrada e o arquivo de saída gerada pelo vinculador será um assembly ou em um .netmodule sem dependência de tempo de execução em qualquer um dos .netmodules que foram registrados no vinculador.  Para obter mais informações, consulte [Arquivos .netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
-   Especifique [\/NOASSEMBLY \(criar um módulo MSIL\)](../../build/reference/noassembly-create-a-msil-module.md) na fase do vinculador para criar o arquivo de saída.  
  
### Para definir essa opção do compilador via programação  
  
-   Essa opção de compilador não pode ser modificada programaticamente.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)