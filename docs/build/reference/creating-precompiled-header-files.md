---
title: "Criando arquivos de cabe&#231;alho pr&#233;-compilados | Microsoft Docs"
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
  - "pch"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .pch, criando"
  - "Compilador cl.exe, pré-compilando código"
  - "arquivos PCH, criando"
  - "arquivos de cabeçalho pré-compilado, criando"
ms.assetid: e2cdb404-a517-4189-9771-c869c660cb1b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Criando arquivos de cabe&#231;alho pr&#233;-compilados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os compiladores do Microsoft C e C\+\+ 2.0 fornecem as opções para precompiling todo o código c ou C\+\+ 2.0, incluindo o código de tabela embutida.  Usando esse recurso de desempenho, você pode criar um corpo estável de código, armazena o estado criado a partir do código em um arquivo e, em seguida, durante compilações subsequentes, o combina o código pré\-compilado pelo código que ainda está em desenvolvimento.  Cada compilação subsequente é mais rápida porque o código estável não precisa ser recompilado.  
  
 Essa seção abrange os seguintes problemas pré\-compilados de cabeçalho:  
  
-   [Quando Precompile o código\-fonte](../../build/reference/when-to-precompile-source-code.md)  
  
-   [Duas opções para o código Precompiling](../../build/reference/two-choices-for-precompiling-code.md)  
  
-   [Regras pré\-compilados de consistência de cabeçalho](../../build/reference/precompiled-header-consistency-rules.md)  
  
-   [Usando cabeçalhos pré\-compiladas em um projeto](../../build/reference/using-precompiled-headers-in-a-project.md)  
  
 Para obter informações de referência nas opções do compilador relacionadas aos cabeçalhos pré\-compilados, consulte [\/Y \(Cabeçalhos pré\-compilados\)](../../build/reference/y-precompiled-headers.md).  
  
## Consulte também  
 [Referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)