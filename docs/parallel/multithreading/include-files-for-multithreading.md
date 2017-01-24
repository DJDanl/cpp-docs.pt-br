---
title: "Incluir arquivos para multithread | Microsoft Docs"
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
  - "incluir arquivos, multithreading"
  - "multithreading [C++], incluir arquivos"
  - "threading [C++], incluir arquivos"
ms.assetid: 98d764f9-71f4-4da5-8f3a-8d2d26e96799
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Incluir arquivos para multithread
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O inclui arquivos padrão declara funções da biblioteca de tempo de execução c como 2.0 são implementados em bibliotecas.  Se você usar a opção de [Otimização completa](../../build/reference/ox-full-optimization.md) \(\/Ox\) ou de [convenção de chamada de fastcall](../../build/reference/gd-gr-gv-gz-calling-convention.md) \(\/Gr\), o compilador pressupõe que todas as funções devem ser chamadas usando a convenção de chamada do registro.  Funções da biblioteca de tempo de execução foram compilados usando C que chama a convenção, as declarações no padrão incluem arquivos indicam o compilador para gerar referências externas corretas a essas funções.  
  
## Consulte também  
 [Multithread com C e Win32](../../parallel/multithreading-with-c-and-win32.md)