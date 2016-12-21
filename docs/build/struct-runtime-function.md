---
title: "struct RUNTIME_FUNCTION | Microsoft Docs"
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
ms.assetid: 84386527-d3aa-41c5-871d-78e3e1913704
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# struct RUNTIME_FUNCTION
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Manipulação de exceção com base em tabela requer uma entrada de tabela para todas as funções que usa o espaço de pilha ou chamar outra função \(por exemplo, funções nonleaf\).  As entradas de tabela de função têm o formato:  
  
|||  
|-|-|  
|ULONG|Endereço de início de função|  
|ULONG|Endereço do final da função|  
|ULONG|Desenrole o endereço de informações|  
  
 A estrutura de RUNTIME\_FUNCTION deve ser DWORD alinhado na memória.  Todos os endereços são relativos de imagem, isto é, são deslocamentos de 32 bits do endereço inicial da imagem que contém a entrada de tabela de função.  Essas entradas são classificadas, e colocados na seção de .pdata de uma imagem PE32\+.  Para funções gerados dinamicamente \[compiladores JIT\], o tempo de execução para oferecer suporte a essas funções deve usar RtlInstallFunctionTableCallback ou RtlAddFunctionTable para fornecer essas informações para o sistema operacional.  A falha fazer isso resultará na manipulação de exceção não confiável e a depuração dos processos.  
  
## Consulte também  
 [Dados desenrolados para tratamento de exceções, suporte do depurador](../build/unwind-data-for-exception-handling-debugger-support.md)