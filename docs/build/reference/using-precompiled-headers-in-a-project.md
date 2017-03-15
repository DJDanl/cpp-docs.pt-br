---
title: "Usando cabe&#231;alhos pr&#233;-compilados em um projeto | Microsoft Docs"
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
  - "cabeçalhos pré-compilados"
ms.assetid: 95010260-a035-4327-9d61-222016ac146c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando cabe&#231;alhos pr&#233;-compilados em um projeto
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As seções anteriores apresenta uma visão geral de cabeçalhos pré\-compilados: \/Yc e \/Yu, a opção \/Fp, e o pragma de [hdrstop](../../preprocessor/hdrstop.md) .  Esta seção descreve um método para usar as opções manual de pré\-compilado\- cabeçalho em um projeto; termina com um makefile de exemplo e o código que gerencia.  
  
 Para outra abordagem para as opções manual de pré\-compilado\- cabeçalho em um projeto, estude um dos makefiles localizados no diretório \\ SRC MFC que é criado durante a instalação padrão do Visual C\+\+.  Esses makefiles usam uma abordagem semelhante a aquela apresentada nesta seção mas fazem o maior uso de macros de manutenção de programas Microsoft \(NMAKE\) e, oferecem maior controle do processo de compilação.  
  
 Esta seção contém os seguintes tópicos:  
  
-   [Arquivos de PCH no processo de criação](../Topic/PCH%20Files%20in%20the%20Build%20Process.md)  
  
-   [Makefile de exemplo para PCH](../../build/reference/sample-makefile-for-pch.md)  
  
-   [Código de exemplo para PCH](../../build/reference/example-code-for-pch.md)  
  
## Consulte também  
 [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)