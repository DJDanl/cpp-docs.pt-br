---
title: "Exportando fun&#231;&#245;es do C++ a serem usadas em execut&#225;veis da linguagem C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "exportando DLLs [C++], funções C++ em executáveis C"
  - "exportando funções [C++], funções C++ em executáveis C"
  - "funções [C++], funções C++ em executáveis C"
  - "funções [C++], exportando"
ms.assetid: 80b9e982-f52d-4312-a891-f73cc69f3c2b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exportando fun&#231;&#245;es do C++ a serem usadas em execut&#225;veis da linguagem C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você tiver funções em uma DLL gravado em C\+\+ que você deseja acessar c \- módulo de idioma, você deve declarar essas funções com esse tipo de C em vez de vinculação C\+\+.  Salvo indicação em contrário, o compilador do C\+\+ usa as convenções de nomenclatura de tipo seguras C\+\+ \(também conhecida como decoração o nome\) e de chamada C\+\+, que podem ser difíceis de chamar C.  
  
 Para especificar o vínculo de C, especifique **extern** "**C**” para suas declarações de função.  Por exemplo:  
  
```  
extern "C" __declspec( dllexport ) int MyFunc(long parm1);  
```  
  
## O que você deseja fazer?  
  
-   [Exportação de uma DLL usando arquivos .def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando \_\_declspec\(dllexport\)](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX\_EXT\_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções de C para uso em executáveis de linguagem C ou C\+\+](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Determine o método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar em um aplicativo usando \_\_declspec \(dllimport\)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Que você deseja saber mais?  
  
-   [Nomes decorados](../Topic/Decorated%20Names.md)  
  
-   [Especificações de vinculação](http://msdn.microsoft.com/pt-br/d2b0cff1-7798-4c38-9ac8-61c3bfe2bfb9)  
  
## Consulte também  
 [Exportando a partir de uma DLL](../build/exporting-from-a-dll.md)