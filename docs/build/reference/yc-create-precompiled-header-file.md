---
title: "/Yc (criar arquivo de cabe&#231;alho pr&#233;-compilado) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.UsePrecompiledHeader"
  - "/yc"
  - "VC.Project.VCCLWCECompilerTool.PrecompiledHeaderThrough"
  - "VC.Project.VCCLWCECompilerTool.UsePrecompiledHeader"
  - "VC.Project.VCCLCompilerTool.PrecompiledHeaderThrough"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .pch, criando"
  - "Opção de compilador /Yc (C++)"
  - "arquivos PCH, criando"
  - "arquivos de cabeçalho pré-compilado, criando"
  - "Opção de compilador Yc [C++]"
  - "Opção de compilador -Yc [C++]"
ms.assetid: 47c2e555-b4f5-46e6-906e-ab5cf21f0678
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Yc (criar arquivo de cabe&#231;alho pr&#233;-compilado)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Instrui o compilador para criar um arquivo de cabeçalho .pch pré\-compilado \(\) que representa o estado de compilação em algum ponto.  
  
## Sintaxe  
  
```  
/Yc[filename]  
```  
  
## Arguments  
 `filename`  
 Especifica um cabeçalho \(\) .h arquivo.  Quando esse argumento for usado, o compilador cria qualquer código até o arquivo de .h.  
  
## Comentários  
 Quando **\/Yc** é especificado sem um argumento, o compilador cria qualquer código até o fim do arquivo de origem de base, ou para o ponto no arquivo de base [hdrstop](../../preprocessor/hdrstop.md) onde ocorre.  O arquivo resultante de .pch tem o mesmo nome de base que o arquivo de origem de base a menos que você especifique um nome de arquivo diferente usando o pragma de **hdrstop** ou a opção de **\/Fp** .  
  
 O código pré\-compilado é salvo em um arquivo com um nome criado de nome de arquivo especificado com a opção de **\/Yc** e uma extensão de .pch.  Você também pode usar a opção de [\/Fp \(nomear arquivo .Pch\)](../Topic/-Fp%20\(Name%20.Pch%20File\).md) especifique um nome para o arquivo de cabeçalho pré\-compilado.  
  
 Se você usar **\/Yc**`filename`, o compilador cria qualquer código até o arquivo especificado para uso subsequente com a opção de **\/Yu** .  
  
 Se as opções **\/Yc**`filename` e [\/Yu \(usar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yu-use-precompiled-header-file.md)`filename` ocorrem na mesma linha de comando e em ambos referência, ou isso, o mesmo nome de arquivo, **\/Yc**`filename` terá precedência.  Esse recurso simplifica a gravação de makefiles.  
  
 Para obter mais informações sobre cabeçalhos pré\-compilados, consulte:  
  
-   [\/Y \(cabeçalhos pré\-compilados\)](../../build/reference/y-precompiled-headers.md)  
  
-   [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Selecione um arquivo .cpp.  O arquivo .cpp deve \#include o arquivo de .h que contém informações de cabeçalho pré\-compilado.  Defina de **\/Yc** de projeto pode ser substituído no nível de arquivo.  
  
2.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
3.  Clique na pasta **C\/C\+\+**.  
  
4.  Clique na página de propriedades de **Cabeçalhos Pré\-Compilados** .  
  
5.  Modifique a propriedade de **Criar\/uso com PCH Arquivo** ou a propriedade de **Cabeçalho pré\-compilado criar\/uso** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderThrough%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>.  
  
## Exemplo  
 Considere o código a seguir:  
  
```  
#include <afxwin.h>   // Include header for class library  
#include "resource.h" // Include resource definitions  
#include "myapp.h"    // Include information specific to this app  
...  
```  
  
 Quando esse código é criado com o comando `CL /YcMYAPP.H PROG.CPP`, o compilador salva qualquer pré\-processamento para AFXWIN.h, RESOURCE.h, e MYAPP.h em um arquivo de cabeçalho pré\-compilado chamado MYAPP.pch.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)