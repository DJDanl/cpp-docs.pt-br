---
title: "/doc (Processar coment&#225;rios de documenta&#231;&#227;o) (C/C++) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.GenerateXMLDocumentationFiles"
  - "/doc"
  - "VC.Project.VCCLCompilerTool.XMLDocumentationFileName"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /doc (C++)"
  - "comentários, código C++"
  - "Opção de compilador -doc [C++]"
  - "documentação XML, comentários em arquivos de origem"
ms.assetid: b54f7e2c-f28f-4f46-9ed6-0db09be2cc63
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /doc (Processar coment&#225;rios de documenta&#231;&#227;o) (C/C++)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Faz com que o compilador aos comentários sobre a documentação do processo em arquivos de origem e criar um arquivo de .xdc para cada arquivo de origem que tem comentários sobre a documentação.  
  
## Sintaxe  
  
```  
/doc[name]  
```  
  
## Arguments  
 `name`  
 O nome do arquivo de .xdc que o compilador criará.  Válido apenas quando um arquivo .cpp é transmitido na compilação.  
  
## Comentários  
 Os arquivos de .xdc são processados em um arquivo.xml com xdcmake.exe.  Para obter mais informações, consulte [Referência XDCMake](../../ide/xdcmake-reference.md).  
  
 Você pode adicionar comentários sobre a documentação ao seu arquivo de código\-fonte.  Para obter mais informações, consulte [Marcas recomendadas para comentários da documentação](../Topic/Recommended%20Tags%20for%20Documentation%20Comments%20\(Visual%20C++\).md).  
  
 **\/doc** não é compatível com **\/clr:oldSyntax**.  Consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) para maiores informações.  
  
 Para usar o arquivo .xml gerado com IntelliSense, faça o nome do arquivo .xml o mesmo que o assembly que você deseja dar suporte a e colocar o arquivo .xml estiver no mesmo diretório que o assembly.  Quando o assembly for referenciado no projeto do Visual Studio, o arquivo .xml também está localizado.  Para obter mais informações, consulte [Usando IntelliSense](../Topic/Using%20IntelliSense.md) e [Fornecendo comentários de código XML](../Topic/Supplying%20XML%20Code%20Comments.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó de **C\/C\+\+** .  
  
4.  Selecione a página de propriedades de **ARQUIVOS DE SAÍDA** .  
  
5.  Modifique a propriedade de **Gera Arquivos XML de Documentação** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.GenerateXMLDocumentationFiles%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)