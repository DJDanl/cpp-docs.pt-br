---
title: "Exportando a partir de uma DLL | Microsoft Docs"
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
  - "Exportações de DLL [C++]"
  - "DLLs [C++], exportando a partir de"
  - "exportando DLLs [C++]"
  - "exportando DLLs [C++], sobre exportação de DLLs"
  - "exportando funções [C++], DLLs (exportando de)"
  - "tabela de exportações [C++]"
  - "funções [C++], exportando"
ms.assetid: a08f86c4-5996-460b-ae54-da2b764045f0
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exportando a partir de uma DLL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um arquivo de DLL tem um layout muito semelhante a um arquivo .exe, com uma diferença importante — um arquivo de DLL contém uma tabela de exportações.  A tabela de exportações contém o nome de cada função que o DLL exporta a outros executáveis.  Essas funções são os pontos de entrada na DLL; apenas funções na tabela de exportações podem ser acessadas por outros executáveis.  Todas as outras funções na DLL são privadas para a DLL.  A tabela de exportações de uma DLL podem ser exibidas usando a ferramenta de [DUMPBIN](../build/reference/dumpbin-reference.md) com a opção do \/EXPORTS.  
  
 Você pode exportar funções de uma DLL usando dois métodos:  
  
-   Crie um arquivo de definição de módulo \(.def\) e o arquivo .def durante a criação da DLL.  Use esta abordagem se desejar que a [exportar funções do DLL por ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).  
  
-   Use a palavra\-chave **\_\_declspec\(dllexport\)** na definição de função.  
  
 Ao exportar funções com um ou outro método, use [\_\_stdcall](../cpp/stdcall.md) que chama a convenção.  
  
## O que você deseja fazer?  
  
-   [Exportação de uma DLL usando arquivos .def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando \_\_declspec\(dllexport\)](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX\_EXT\_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções de C\+\+ para uso em executáveis de linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções de C para uso em executáveis de linguagem C ou C\+\+](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Exportar funções de uma DLL por ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md)  
  
-   [Determine o método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Determine o método de vinculação a ser usado](../build/determining-which-linking-method-to-use.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Que você deseja saber mais?  
  
-   [Importar em um aplicativo](../build/importing-into-an-application.md)  
  
-   [Importando e exportando funções embutidas](../Topic/Importing%20and%20Exporting%20Inline%20Functions.md)  
  
-   [Importações Mútuas](../Topic/Mutual%20Imports.md)  
  
## Consulte também  
 [Importando e exportando](../build/importing-and-exporting.md)