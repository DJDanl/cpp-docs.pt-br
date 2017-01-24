---
title: "Refer&#234;ncia (C++ AMP) | Microsoft Docs"
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
  - "amp/Concurrency::Reference (C++ AMP)"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C++ Accelerated Massive Parallelism, referência"
ms.assetid: 372a8aed-8a53-48c9-996f-9c3cf09c9fa8
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Refer&#234;ncia (C++ AMP)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Esta seção contém informações de referência para o tempo de execução de C\+\+ Accelerated Massive Parallelism \(C\+\+ AMP\).  
  
> [!NOTE]
>  O padrão de linguagem C\+\+ permite o uso de identificadores que começam com um caractere de sublinhado \(`_`\) para implementações como bibliotecas.  Não use nomes que começam com um sublinhado em seu código.  O comportamento de elementos de código cujos nomes sigam esta convenção não é garantida e está sujeito a alterações nas versões futuras.  Por esses motivos, esses elementos de código são omitidos nesta documentação.  
  
## Nesta seção  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)  
 Fornece as classes e funções que habilitam a aceleração de código C\+\+ no hardware de dados paralelos.  
  
 [Namespace Concurrency::direct3d](../../../parallel/amp/reference/concurrency-direct3d-namespace.md)  
 Fornece funções que suportam a interoperabilidade D3D  Permite o uso direto de recursos de D3D para o cálculo no código de AMP e o uso de recursos criados no AMP no código de D3D, sem criar cópias intermediários redundantes.  Você pode usar o C\+\+ AMP acelerar de forma crescente as seções intensas de cálculo dos seus aplicativos DirectX, e usar o D3D API em dados gerados pelos cálculos AMP.  
  
 [Namespace Concurrency::fast\_math](../../../parallel/amp/reference/concurrency-fast-math-namespace.md)  
 As funções no namespace de `fast_math` não são compatíveis com C99.  São fornecidas apenas versões de precisão simples de cada função.  Essas funções usam as funções intrínsecas do DirectX, que são mais rápidas do que as funções correspondentes no namespace `precise_math` e não exigem suporte de precisão dupla estendido no acelerador, mas são menos exatas.  Há duas versões de cada função para compatibilidade no nível de fonte com o código C99; as duas versões adotam e retornam valores de precisão simples.  
  
 [Namespace Concurrency::graphics](../../../parallel/amp/reference/concurrency-graphics-namespace.md)  
 Fornece tipos e funções projetadas para a programação de elementos gráficos.  
  
 [Namespace Concurrency::precise\_math](../Topic/Concurrency::precise_math%20Namespace.md)  
 As funções no namespace de `precise_math` são compatíveis com C99.  As versões de precisão simples e de precisão dupla de cada função são incluídas.  Essas funções, incluindo as funções de precisão simples, exigem suporte de precisão dupla estendido no acelerador.  
  
## Seções relacionadas  
 [C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\)](../../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)  
 O C\+\+ AMP acelera a execução do seu código C\+\+, tirando proveito do hardware de dados paralelos comumente apresentado como uma unidade de processamento gráfico \(GPU, Graphics Processing Unit\) em uma placa gráfica discreta.