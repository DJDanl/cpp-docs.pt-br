---
title: "Alternativas de Entrada/Sa&#237;da | Microsoft Docs"
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
  - "E/S [C++], alternativas"
ms.assetid: 9f8401c7-d90d-4285-8918-63573df74a80
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Alternativas de Entrada/Sa&#237;da
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ o fornece várias alternativas para a programação de E\/S:  
  
-   Biblioteca de tempo de execução direta, E\/S não armazenado C.  
  
-   Fluxo de E\/S a biblioteca de tempo de execução ANSI C.  
  
-   Console e porta E\/S direto.  
  
-   Biblioteca de classes do Microsoft.  
  
-   Biblioteca padrão do Microsoft C\+\+.  
  
 As classes iostream são úteis para armazenado no buffer, texto formatado E\/S.  Também são úteis para E\/S não armazenado ou binário se você precisar da interface de programação c criando e decidiu usar a biblioteca de \(MFC\) da classe do Microsoft.  As classes iostream são uma alternativa orientado a objeto de E\/S às funções de tempo de execução C.  
  
 Você pode usar classes iostream com o sistema operacional Microsoft Windows.  Os fluxos de cadeia de caracteres e do arquivo funcionam sem restrições, mas os objetos `cin`, `cout`, `cerr`, e `clog` de fluxo em modo de caractere forem inconsistentes com a interface gráfica do usuário do windows.  Você também pode derivar as classes personalizadas de fluxo que interagem diretamente com o ambiente do windows.  
  
## Consulte também  
 [O que é um fluxo](../standard-library/what-a-stream-is.md)