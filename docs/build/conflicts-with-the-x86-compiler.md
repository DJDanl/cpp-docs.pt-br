---
title: "Está em conflito com x86 compilador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 8e47f0d3-afe0-42d9-9efa-de239ddd3a05
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2b2b9c4cf871e8436a8da34a862d205541e7dc5c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="conflicts-with-the-x86-compiler"></a>Conflitos com o compilador x86
Tipos de dados que são maiores do que 4 bytes não estão alinhados automaticamente na pilha quando você usa o x86 compilador para compilar um aplicativo. Como a arquitetura para x86 compilador é uma pilha de alinhamento 4 bytes, nada mais de 4 bytes, por exemplo, um inteiro de 64 bits, não pode ser alinhada automaticamente a um endereço de 8 bytes.  
  
 Trabalhando com dados não alinhados tem duas consequências.  
  
-   Pode levar mais tempo para acessar locais não alinhados que demora para acessar locais alinhados.  
  
-   Não alinhados locais não podem ser usados em operações integradas.  
  
 Se você precisar de mais de alinhamento estrito, use `__declspec(align(N)) on your variable declarations`. Isso faz com que o compilador alinhar dinamicamente a pilha para atender às suas especificações. No entanto, ajustar a pilha dinamicamente em tempo de execução pode causar a execução mais lenta do seu aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)   
 [align](../cpp/align-cpp.md)