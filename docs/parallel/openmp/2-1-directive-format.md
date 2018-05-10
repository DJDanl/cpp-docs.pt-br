---
title: 2.1 formato de diretiva | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 918b6445-d35e-4176-9565-b045be941b4d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1eec5a2f0e91df6e8d71797199bd3a3911a3aab0
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="21-directive-format"></a>2.1 Formato de diretiva
A sintaxe de uma diretiva de OpenMP formalmente especificada pela gramática em [Apêndice C](../../parallel/openmp/c-openmp-c-and-cpp-grammar.md)e informalmente da seguinte maneira:  
  
```  
#pragma omp directive-name  [clause[ [,] clause]...] new-line  
```  
  
 Cada diretiva começa com **#pragma omp**, para reduzir o potencial de conflito com outras diretivas de pragma (não OpenMP ou fornecedor extensões OpenMP) com os mesmos nomes. O restante da diretiva segue as convenções dos padrões de diretivas de compilador C e C++. Em particular, o espaço em branco pode ser usado antes e depois o **#**, e às vezes, o espaço em branco devem ser usado para separar as palavras em uma diretiva. Pré-processamento de tokens após a **#pragma omp** estão sujeitos a substituição de macro.  
  
 Diretivas diferenciam maiusculas de minúsculas. A ordem na qual as cláusulas aparecerão em diretivas não é significativa. As cláusulas em diretivas podem ser repetidas, conforme necessário, sujeito as restrições listadas na descrição de cada cláusula. Se *lista variável* aparece em uma cláusula, ele deve especificar somente variáveis. Apenas uma *nome de diretiva* pode ser especificado por diretiva.  Por exemplo, não é permitida a seguinte diretiva:  
  
```  
/* ERROR - multiple directive names not allowed */  
#pragma omp parallel barrier  
```  
  
 Uma diretiva de OpenMP aplica-se a no máximo um sucessivo instrução, que deve ser um bloco estruturado.