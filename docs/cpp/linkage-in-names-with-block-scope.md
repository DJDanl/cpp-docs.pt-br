---
title: "Liga&#231;&#227;o em nomes com escopo de bloco | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "escopo de bloco [C++]"
  - "vinculação externa, regras de vinculação de escopo"
  - "vinculação [C++], regras de vinculação de escopo"
  - "nomes [C++], regras de vinculação de escopo"
  - "escopo [C++], regras de vinculação"
ms.assetid: 73efa91a-f761-47f7-bbd9-9f9e3508e218
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Liga&#231;&#227;o em nomes com escopo de bloco
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As regras de vinculação a seguir se aplicam aos nomes com escopo de bloco \(nomes locais\):  
  
-   Os nomes declarados como `extern` terão vinculação externa, a menos que tenham sido declarados anteriormente como **static**.  
  
-   Todos os outros nomes com escopo de bloco não tem nenhuma vinculação.  
  
## Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)