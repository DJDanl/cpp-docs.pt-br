---
title: "-/Wp64 (detectar problemas de portabilidade de 64 bits) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.Detect64BitPortabilityProblems"
  - "VC.Project.VCCLCompilerTool.Detect64BitPortabilityProblems"
  - "/wp64"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "detectando problemas de portabilidade de compilador de 64 bits [C++]"
  - "Opção de compilador /Wp64 (C++)"
  - "Opção de compilador -Wp64 (C++)"
  - "Opção de compilador Wp64 (C++)"
ms.assetid: 331ae5aa-e627-4d03-8f63-dd2c2d76dadd
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Wp64 (detectar problemas de portabilidade de 64 bits)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa opção de compilador é obsoleta. Em versões do Visual Studio antes do Visual Studio 2013, isso detecta problemas de portabilidade de 64 bits em tipos que também são marcados com o [w64](../../cpp/w64.md) palavra\-chave.  
  
## Sintaxe  
  
```  
/Wp64  
```  
  
## Comentários  
 Por padrão, em versões do Visual Studio antes do Visual Studio 2013, o **\/Wp64** opção de compilador está desativado no compilador do Visual C\+\+ 32 bits e, no compilador do Visual C\+\+ 64 bits.  
  
> [!IMPORTANT]
>  O [\/Wp64](../../build/reference/wp64-detect-64-bit-portability-issues.md) opção de compilador e [w64](../../cpp/w64.md) palavra\-chave são preteridos no Visual Studio 2010 e o Visual Studio 2012 e não tem suporte a partir do Visual Studio 2013. Se você converter um projeto que usa essa opção, o comutador não será migrado durante a conversão. Para usar essa opção no Visual Studio 2010 ou o Visual Studio 2012, você deve digitar o comutador de compilador em **Opções adicionais** no **linha de comando** seção de propriedades do projeto. Se você usar o **\/Wp64** opção de compilador na linha de comando, o compilador emite D9002 de aviso de linha de comando. Em vez de usar essa opção e a palavra\-chave para detectar problemas de portabilidade de 64 bits, use um compilador do Visual C\+\+ que se destina a uma plataforma de 64 bits e especifique o [\/W4](../../build/reference/compiler-option-warning-level.md) opção. Para obter mais informações, consulte [Configurando programas para 64 bits](../../build/configuring-programs-for-64-bit-visual-cpp.md).  
  
 Os seguintes tipos de variáveis são testadas em um sistema operacional de 32 bits como se eles estavam sendo usados em um sistema operacional de 64 bits:  
  
-   int  
  
-   long  
  
-   pointer  
  
 Se você compilar o seu aplicativo regularmente, usando um compilador de 64 bits, você pode desabilitar apenas **\/Wp64** em suas compilações de 32 bits porque o compilador de 64 bits detectará todos os problemas. Para obter mais informações sobre como sistema operacional de destino Windows de 64 bits, consulte [Configurando programas para 64 bits](../../build/configuring-programs-for-64-bit-visual-cpp.md).  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo.  
  
     Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique o **C\/C\+\+** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Modificar o **Opções adicionais** caixa para incluir **\/Wp64**.  
  
### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Detect64BitPortabilityProblems%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Configurando programas para 64 bits](../../build/configuring-programs-for-64-bit-visual-cpp.md)