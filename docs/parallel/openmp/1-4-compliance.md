---
title: 1.4 conformidade | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 662ad260-b9a1-43b7-b269-ef6ff0714e05
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d3fca67cb50cf91195d7edfb1e5e2fccfc9f8c5d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="14-compliance"></a>1.4 Conformidade
É uma implementação da API do C/C++ OpenMP *OpenMP compatíveis* se ele reconhece e preserva a semântica de todos os elementos desta especificação, de acordo com capítulos 1, 2, 3, 4, e são apêndice C. apêndices A, B, D, E e F para informações fins apenas e não fazem parte da especificação. Implementações que incluem apenas um subconjunto da API não são compatíveis com o OpenMP.  
  
 O OpenMP C e C++ API é uma extensão para o idioma base que é suportada por uma implementação. Se o idioma base não dá suporte a uma construção de linguagem ou a extensão que aparece neste documento, a implementação de OpenMP não é necessário para dar suporte a ele.  
  
 Todas as funções de biblioteca C e C++ padrão e funções internas (ou seja, funções das quais o compilador não tem conhecimento específico) deve ser thread-safe. Não sincronizado uso de funções de thread-safe por threads diferentes dentro de uma região parallel não produzir um comportamento indefinido. No entanto, o comportamento não pode ser igual de uma região de série. (É um exemplo de uma função de geração de número aleatório.)  
  
 A API do C/C++ OpenMP Especifica que certos comportamento *definido pela implementação.* Uma implementação OpenMP com conformidade é necessária para definir e documentar seu comportamento nesses casos. Consulte [Apêndice E](../../parallel/openmp/e-implementation-defined-behaviors-in-openmp-c-cpp.md), página 97, para obter uma lista de comportamentos definidos na implementação.