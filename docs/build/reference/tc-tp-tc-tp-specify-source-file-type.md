---
title: "/Tc, /Tp, /TC, /TP (especificar tipo de arquivo de origem) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.CompileAs"
  - "VC.Project.VCCLCompilerTool.CompileAs"
  - "/Tp"
  - "/tc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Tc (C++)"
  - "Opção de compilador /Tp (C++)"
  - "arquivos de origem, especificando para compilador"
  - "Opção de compilador Tc [C++]"
  - "Opção de compilador -Tc [C++]"
  - "Opção de compilador Tp [C++]"
  - "Opção de compilador -Tp [C++]"
ms.assetid: 7d9d0a65-338b-427c-8b48-fff30e2f9d2b
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Tc, /Tp, /TC, /TP (especificar tipo de arquivo de origem)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A opção de **\/Tc** especifica que `filename` é arquivo de origem c, mesmo se não tiver a extensão de C.A.  A opção de **\/Tp** especifica que `filename` é arquivo de origem criando c, mesmo se não tiver uma extensão .cpp ou de .cxx.  Um espaço entre a opção e `filename` é opcional.  Cada opção especifica um arquivo; para especificar arquivos, repita a opção.  
  
 **\/TC** e **\/TP** variantes são globais de **\/Tc** e de **\/Tp**.  Especificam ao compilador para tratar todos os arquivos nomeados na linha de comando como arquivos de origem de C**\/TC**\(2.0\) ou arquivos de origem de**\/TP**\(C\+\+\), sem considerar o local na linha de comando com relação à opção.  Essas opções globais podem ser substituídas em um único arquivo por meio de **\/Tc** ou de **\/Tp**.  
  
## Sintaxe  
  
```  
/Tcfilename  
/Tpfilename  
/TC  
/TP  
```  
  
## Arguments  
 `filename`  
 C ou arquivo de origem C\+\+.  
  
## Comentários  
 Por padrão, o CL assume que os arquivos com a extensão de .c são arquivos de origem de C e os arquivos com o .cpp ou a extensão de .cxx são arquivos de origem C\+\+.  
  
 Quando **TC** ou a opção de **Tc** for especificado, qualquer especificação da opção de [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md) será ignorada.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Avançado** .  
  
4.  Modifique a propriedade de **Compile Como** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileAs%2A>.  
  
## Exemplos  
 A seguinte linha de comando de CL especifica que o MAIN.c, TEST.prg, e COLLATE.prg são todos os arquivos de origem de C.  O CL não reconhecerá PRINT.prg.  
  
```  
CL MAIN.C /TcTEST.PRG /TcCOLLATE.PRG PRINT.PRG  
```  
  
 A seguinte linha de comando de CL especifica que o TEST1.c, TEST2.cxx, TEST3.huh, e TEST4.o são compilados arquivos como C\+\+, e TEST5.z é compilado como o arquivo c.  
  
```  
CL TEST1.C TEST2.CXX TEST3.HUH TEST4.O /Tc TEST5.Z /TP  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)