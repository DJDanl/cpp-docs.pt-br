---
title: "/c (compilar sem vincula&#231;&#227;o) | Microsoft Docs"
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
  - "/c"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /c (C++)"
  - "Opção de compilador c [C++]"
  - "Opção de compilador -c [C++]"
  - "Compilador cl.exe, compilando sem vinculação"
  - "suprimir link"
ms.assetid: 8017fc3d-e5dd-4668-a1f7-3120daa95d20
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /c (compilar sem vincula&#231;&#227;o)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Impede a chamada automático COMO VINCULAR.  
  
## Sintaxe  
  
```  
/c  
```  
  
## Comentários  
 A compilação com **\/c** criar arquivos de .obj somente.  Você deve chamar explicitamente o LINK com os arquivos e as opções apropriadas para executar a fase de vinculação de compilação.  
  
 Qualquer projeto interno criado no ambiente de desenvolvimento usa a opção de **\/c** por padrão.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
-   Essa opção não está disponível dentro do ambiente de desenvolvimento.  
  
### Para definir essa opção do compilador via programação  
  
-   Para definir programaticamente essa opção do compilador, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CompileOnly%2A>.  
  
## Exemplo  
 A linha de comando a seguir cria os arquivos de objeto FIRST.obj e SECOND.obj.  THIRD.obj é ignorado.  
  
```  
CL /c FIRST.C SECOND.C THIRD.OBJ  
```  
  
 Para criar um arquivo executável, você deve chamar o LINK:  
  
```  
LINK firsti.obj second.obj third.obj /OUT:filename.exe  
```  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)