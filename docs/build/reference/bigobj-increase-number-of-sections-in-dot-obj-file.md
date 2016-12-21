---
title: "/bigobj (aumentar n&#250;mero de se&#231;&#245;es no arquivo .Obj) | Microsoft Docs"
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
  - "/bigobj"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /bigobj (C++)"
  - "Opção de compilador bigobj [C++]"
  - "Opção de compilador -bigobj [C++]"
ms.assetid: ba94d602-4015-4a8d-86ec-49241ab74c12
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /bigobj (aumentar n&#250;mero de se&#231;&#245;es no arquivo .Obj)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**\/bigobj** aumenta o número de seções que um arquivo de objeto pode conter.  
  
## Sintaxe  
  
```  
/bigobj  
```  
  
## Comentários  
 Por padrão, um arquivo de objeto pode conter até 65.536 \(2^16\) seções endereçáveis.  Esse é o caso, não importa qual plataforma de destino é especificada.  **\/bigobj** aumenta a capacidade de endereço para 4.294.967.296 \(2^32\).  
  
 A maioria de módulos nunca irá gerar um arquivo .obj que contém mais de 65.536 seções.  No entanto, o código gerado pelo computador, ou código que fizer uso intenso das bibliotecas de modelo poderá exigir os arquivos .obj que podem conter mais seções.  **\/bigobj** é habilitado por padrão em projetos do Windows Store, pois o código XAML gerado pela máquina inclui um grande número cabeçalhos.  Se você desativar essa opção em um projeto de aplicativo da Windows Store, você provavelmente encontrará o erro C1128 de compilador.  
  
 Os vinculadores fornecidos antes do Visual C\+\+ 2005 não podem ler arquivos .obj que foram gerados com **\/bigobj**.  
  
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