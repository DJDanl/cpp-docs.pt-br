---
title: "/MD, /MT, /LD (usar biblioteca em tempo de execu&#231;&#227;o) | Microsoft Docs"
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
  - "/ld"
  - "/mt"
  - "VC.Project.VCCLWCECompilerTool.RuntimeLibrary"
  - "VC.Project.VCCLCompilerTool.RuntimeLibrary"
  - "/md"
  - "/ml"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /LD (C++)"
  - "Opção de compilador /MD (C++)"
  - "Opção de compilador /MDd (C++)"
  - "Opção de compilador /MT (C++)"
  - "Opção de compilador /MTd (C++)"
  - "Símbolo _STATIC_CPPLIB"
  - "DLLs [C++], opções do compilador"
  - "Opção de compilador LD [C++]"
  - "Opção de compilador -LD [C++]"
  - "LIBC.lib"
  - "LIBCD.lib"
  - "LIBCMT.lib"
  - "LIBCMTD.lib"
  - "Opção de compilador MD [C++]"
  - "Opção de compilador -MD [C++]"
  - "Opção de compilador MDd [C++]"
  - "Opção de compilador -MDd [C++]"
  - "MSVCRT.lib"
  - "MSVCRTD.lib"
  - "Opção de compilador MT [C++]"
  - "Opção de compilador -MT [C++]"
  - "Opção de compilador MTd [C++]"
  - "Opção de compilador -MTd [C++]"
  - "Opção de compilador multithread"
  - "threading [C++], Opção de compilador multithread"
ms.assetid: cf7ed652-dc3a-49b3-aab9-ad60e5395579
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MD, /MT, /LD (usar biblioteca em tempo de execu&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Indica se um módulo com multithread é uma DLL e especifica versões comerciais ou de depuração da biblioteca em tempo de execução.  
  
## Sintaxe  
  
```  
/MD[d]  
/MT[d]  
/LD[d]  
```  
  
## Comentários  
  
|Opção|Descrição|  
|-----------|---------------|  
|**\/MD**|Faz com que o aplicativo use a versão específica de multithread e a versão específica de DLL da biblioteca em tempo de execução.  Define `_MT` e `_DLL` e faz com que o compilador coloque o nome da biblioteca MSVCRT.lib no arquivo .obj.<br /><br /> Os aplicativos criados com esta opção são vinculados a MSVCRT.lib estaticamente.  Essa biblioteca fornece uma camada de código que permite que o vinculador resolva referências externas.  O código de trabalho real está contido em MSVCR*versionnumber*.DLL, que deve estar disponível no tempo de execução para aplicativos vinculados a MSVCRT.lib.|  
|**\/MDd**|Define `_DEBUG`, `_MT` e `_DLL`, e faz com que o aplicativo use a versão específica de multithread de depuração e a versão específica de DLL da biblioteca em tempo de execução.  Também faz com que o compilador coloque o nome da biblioteca MSVCRTD.lib no arquivo .obj.|  
|**\/MT**|Faz com que o aplicativo use a versão estática de multithread da biblioteca em tempo de execução.  Define `_MT` e faz com que o compilador coloque o nome da biblioteca LIBCMT.lib no arquivo .obj para que o vinculador use LIBCMT.lib para resolver símbolos externos.|  
|**\/MTd**|Define `_DEBUG` e `_MT`.  Essa opção também faz com que o compilador coloque o nome da biblioteca LIBCMTD.lib no arquivo .obj para que o vinculador use LIBCMTD.lib para resolver símbolos externos.|  
|**\/LD**|Cria uma DLL.<br /><br /> Passa a opção **\/DLL** ao vinculador.  O vinculador procura, mas não requer, uma função `DllMain`.  Se você não grava uma função `DllMain`, o vinculador insere uma função `DllMain` que retorna TRUE.<br /><br /> Vincula o código de inicialização da DLL.<br /><br /> Cria uma biblioteca da importação \(.lib\), se um arquivo de exportação \(.exp\) não é especificado na linha de comando.  Você vinculará a biblioteca de importação aos aplicativos que chamam a DLL.<br /><br /> Interpreta [\/Fe \(nomear arquivo EXE\)](../../build/reference/fe-name-exe-file.md) como a nomeação de uma DLL em vez de um arquivo .exe.  Por padrão, o nome do programa se torna *basename*.dll em vez de *basename*.exe.<br /><br /> Indica **\/MT**, a menos que você especifique **\/MD** explicitamente.|  
|**\/LDd**|Cria uma DLL de depuração.  Define `_MT` e `_DEBUG`.|  
  
 Para obter mais informações sobre as bibliotecas CRT e quais bibliotecas são usadas quando você compila com [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md), consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).  
  
 Todos os módulos passados para determinada invocação do vinculador devem ter sido compilados com a mesma opção do compilador da biblioteca em tempo de execução \(**\/MD**, **\/MT**, **\/LD**\).  
  
 Para obter mais informações sobre como usar as versões de depuração das bibliotecas em tempo de execução, consulte [Referência da biblioteca em tempo de execução do C](../../c-runtime-library/c-run-time-library-reference.md).  
  
 O artigo Q140584 da Base de Dados de Conhecimento também discute como escolher a biblioteca CRT adequada.  
  
 Para saber mais sobre DLLs, consulte [DLLs no Visual C\+\+](../../build/dlls-in-visual-cpp.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Geração de Código**.  
  
4.  Modifique a propriedade de **Biblioteca em Tempo de Execução**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.RuntimeLibrary%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)