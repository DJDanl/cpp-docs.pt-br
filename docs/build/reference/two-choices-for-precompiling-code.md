---
title: "Duas escolhas para pr&#233;-compilar c&#243;digo | Microsoft Docs"
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
  - "Arquivos .pch"
  - "Arquivos .pch, opções de pré-compilação"
  - "pré-compilação automática"
  - "código, pré-compilando"
  - "compilando o código-fonte, pré-compilando"
  - "arquivos PCH"
  - "arquivos PCH, opções de pré-compilação"
  - "arquivos de cabeçalho pré-compilado"
  - "arquivos de cabeçalho pré-compilado, opções de pré-compilação"
  - "pré-compilando código"
ms.assetid: f50ac76f-e2a2-462d-bda5-0e2ab7cccdeb
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Duas escolhas para pr&#233;-compilar c&#243;digo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Com o Visual C\+\+, você pode precompile todo o código c ou C\+\+ 2.0; você não está limitado a precompiling somente arquivos de cabeçalho.  
  
 Precompiling requer planejamento, mas oferece uma compilações significativamente mais rápida se você precompile o código\-fonte diferente de arquivos de cabeçalho simples.  
  
 Precompile o código quando você souber que os conjuntos de uso comum dos arquivos de origem de arquivos de cabeçalho mas não estão na mesma ordem, ou quando quiser incluir o código\-fonte em seu precompilation.  
  
 As opções de pré\-compilado\- cabeçalho são [\/Yc \(criar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yc-create-precompiled-header-file.md) e [\/Yu \(usar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yu-use-precompiled-header-file.md).  Use **\/Yc** para criar um cabeçalho pré\-compilado.  Quando usado com o pragma opcional de `hdrstop` , **\/Yc** permite precompile arquivos e o código\-fonte de cabeçalho.  **\/Yu** selecione para usar um cabeçalho pré\-compilado existente na compilação existente.  Você também pode usar **\/Fp** com as opções de **\/Yc** e de **\/Yu** fornecer um nome alternativo para o cabeçalho pré\-compilado.  
  
 Os tópicos de referência da opção do compilador para **\/Yu** e **\/Yc** discutem como acessar essa funcionalidade no ambiente de desenvolvimento.  
  
## Mais informações  
  
-   [Quando Precompile o código\-fonte](../../build/reference/when-to-precompile-source-code.md)  
  
-   [Regras pré\-compilados de consistência de cabeçalho](../../build/reference/precompiled-header-consistency-rules.md)  
  
-   [Usando cabeçalhos pré\-compiladas em um projeto](../../build/reference/using-precompiled-headers-in-a-project.md)  
  
 Para obter exemplos mais adicionais usando cabeçalhos pré\-compilados, consulte os makefiles usados para criar os programas de exemplo fornecidos com a biblioteca de classes do Microsoft.  
  
## Consulte também  
 [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)