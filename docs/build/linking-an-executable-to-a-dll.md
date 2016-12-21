---
title: "Vinculando um execut&#225;vel a uma DLL | Microsoft Docs"
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
  - "DLLs [C++], vinculando"
  - "vinculação de carga dinâmica [C++]"
  - "arquivos executáveis [C++], vinculando a DLLs"
  - "vinculando explicitamente [C++]"
  - "vinculação implícita [C++]"
  - "vinculando [C++], DLLs"
  - "carregando DLLs [C++]"
  - "tempo de execução [C++], vinculando"
ms.assetid: 7592e276-dd6e-4a74-90c8-e1ee35598ea3
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vinculando um execut&#225;vel a uma DLL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um arquivo executável vincula \(ou carrega\) a uma DLL de uma das duas maneiras:  
  
-   [Vinculação implícita](../Topic/Linking%20Implicitly.md)  
  
-   [Vinculação explícita](../build/linking-explicitly.md)  
  
 A vinculação implícita às vezes é chamada de carregamento estático ou vinculação dinâmica em tempo de carregamento.  A vinculação explícita às vezes é chamada de carregamento dinâmico ou vinculação dinâmica em tempo de execução.  
  
 Com a vinculação implícita, o executável que usa a DLL é vinculado a uma biblioteca de importação de arquivo \(.lib\) fornecida pelo fabricante da DLL.  O sistema operacional carregará a DLL quando o executável que a estiver usando for carregado.  O executável do cliente chama funções exportadas da DLL exatamente como se as funções estivessem contidas no executável.  
  
 Com a vinculação explícita, o arquivo executável que usa a DLL deve fazer chamadas de função para carregar e descarregar a DLL e para acessar explicitamente as funções exportadas da DLL.  O executável cliente deve chamar as funções exportadas por meio de um ponteiro de função.  
  
 Um executável pode usar a mesma DLL com qualquer método de vinculação.  Além disso, esses mecanismos não são mutuamente exclusivos, porque um executável pode implicitamente vincular\-se a um DLL e outro pode anexar\-se a ele explicitamente.  
  
## Que você deseja saber mais?  
  
-   [Trabalhando com bibliotecas de importação e arquivos de exportação](../build/reference/working-with-import-libraries-and-export-files.md)  
  
-   [Determinando o método de vinculação a ser usado](../build/determining-which-linking-method-to-use.md)  
  
-   [O caminho de pesquisa usado pelo Windows para localizar uma DLL](../build/search-path-used-by-windows-to-locate-a-dll.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)