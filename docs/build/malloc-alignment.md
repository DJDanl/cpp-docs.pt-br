---
title: "Alinhamento de malloc | Microsoft Docs"
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
ms.assetid: a8d1d1b4-5122-456f-9a64-a50e105e55a5
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Alinhamento de malloc
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

É garantido que [malloc](../c-runtime-library/reference/malloc.md) retorna memória que esteja alinhada corretamente para o armazenamento de qualquer objeto que tenha um alinhamento fundamental e que poderia se ajustar à quantidade de memória alocada.  Um *alinhamento fundamental* é um alinhamento que é menor ou igual ao alinhamento o maior que é suportado pela implementação sem uma especificação de alinhamento. \(No Visual C\+\+, este é o alinhamento que é necessário para `double`, ou 8 bytes.  No código que se destina a plataformas de 64 bits, é de 16 bytes\). Por exemplo, uma alocação de quatro bytes seria alinhada em um limite com suporte a qualquer objeto de quatro bytes ou menor.  
  
 Visual C\+\+ permite tipos que *estenderam o alinhamento*, que são também conhecidos como tipos *sobrealinhados*.  Por exemplo, os tipos SSE [\_\_m128](../Topic/__m128.md) e `__m256`, e os tipos declarados usando `__declspec(align(``n``))` onde `n` é maior que 8, têm alinhamento estendido.  O alinhamento de memória em um limite adequado a um objeto que exija o alinhamento estendido não é garantido por `malloc`.  Para atribuir memória para tipos sobre\-alinhados, use [\_aligned\_malloc](../c-runtime-library/reference/aligned-malloc.md) e funções relacionadas.  
  
## Consulte também  
 [Uso da pilha](../build/stack-usage.md)   
 [align](../cpp/align-cpp.md)   
 [\_\_declspec](../cpp/declspec.md)