---
title: "Compila&#231;&#245;es de vers&#227;o | Microsoft Docs"
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
  - "depurar compilações, convertendo em compilação de lançamento"
  - "depurando [C++], compilações de lançamento"
  - "compilações de lançamento"
ms.assetid: fa9a78fa-f4b5-4722-baf4-aec655c4ff0f
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compila&#231;&#245;es de vers&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma construção da versão usa otimizações.  Quando você usa otimizações para criar uma compilação da versão, o compilador não gerará informações de depuração do token.  A ausência de informações de depuração do token, junto com o fato do código que não é gerado para o TRACE e NOT AFIRMA chamadas, significa que o tamanho do arquivo executável é reduzido e será mais rápido em virtude disso.  
  
 Esta seção apresenta informações em como e quando você pode desejar alterar de uma construção de depuração para uma construção da versão.  Também discute alguns dos problemas que você pode localizar quando se uma alteração de depuração para uma construção de versão:  
  
-   [Criando uma construção de versão](../../build/reference/how-to-create-a-release-build.md)  
  
-   [Problemas comuns ao criar uma construção de versão](../../build/reference/common-problems-when-creating-a-release-build.md)  
  
-   [Solucionando problemas de compilação da versão](../../build/reference/fixing-release-build-problems.md)  
  
    -   [Revise AFIRMA instruções](../../build/reference/using-verify-instead-of-assert.md)  
  
    -   [Usando a construção de depuração para verificar a memória substituir](../Topic/Using%20the%20Debug%20Build%20to%20Check%20for%20Memory%20Overwrite.md)  
  
    -   [Depurando uma construção de versão](../../build/reference/how-to-debug-a-release-build.md)  
  
    -   [Verifique se há substitui a memória](../../build/reference/checking-for-memory-overwrites.md)  
  
## Consulte também  
 [Compilando projetos do C\+\+ no Visual Studio](../../ide/building-cpp-projects-in-visual-studio.md)   
 [Referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md)