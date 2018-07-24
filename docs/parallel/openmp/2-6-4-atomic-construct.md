---
title: 2.6.4 constructo atomic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: e4232ef1-4058-42ce-9de0-0ca788312aba
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3c906a9a9b781f742f525688b77d5f58da16bb10
ms.sourcegitcommit: 7eadb968405bcb92ffa505e3ad8ac73483e59685
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/23/2018
ms.locfileid: "39208127"
---
# <a name="264-atomic-construct"></a>2.6.4 Constructo atomic
O `atomic` diretiva garante que um local específico da memória é atualizado atomicamente, em vez de expô-lo para a possibilidade de várias simultâneas gravando segmentos. A sintaxe do `atomic` diretiva é da seguinte maneira:  
  
```  
#pragma omp atomic new-lineexpression-stmt  
```  
  
 A instrução da expressão deve ter uma das seguintes formas:  
  
 *x binop*= *expr*  
  
 x + +  
  
 + + x  
  
 x-  
  
 --x  
  
 Nas expressões anteriores:  
  
-   *x* é uma expressão de lvalue com tipo escalar.  
  
-   *Expr* é uma expressão com um tipo escalar, e ele não faz referência a objeto designado pelo *x*.  
  
-   `binop` não é um operador sobrecarregado e é um dos +, \*, -, /, &, ^, &#124;, <\<, ou >>.  
  
 Embora seja definido pela implementação se uma implementação substitui todos os `atomic` diretivas com **críticas** diretivas que têm o mesmo exclusivo *nome*, o `atomic` diretiva permite melhor otimização. Instruções de hardware geralmente estão disponíveis que podem executar a atualização atômica com menos sobrecarga.  
  
 Somente o carregamento e o armazenamento de objeto designado pelo *x* são atômicas; avaliação de *expr* não é atômica. Para evitar condições de corrida, todas as atualizações do local em paralelo devem ser protegidas com o `atomic` diretiva, exceto aqueles que são conhecidos por estar livres de condições de corrida.  
  
 Restrições para o `atomic` diretiva são da seguinte maneira:  
  
-   Todas as referências atômicas para o local de armazenamento em todo o programa x devem ter um tipo compatível.  
  
## <a name="examples"></a>Exemplos:  
  
```  
extern float a[], *p = a, b;  
/* Protect against races among multiple updates. */  
#pragma omp atomic  
a[index[i]] += b;  
/* Protect against races with updates through a. */  
#pragma omp atomic  
p[i] -= 1.0f;  
  
extern union {int n; float x;} u;  
/* ERROR - References through incompatible types. */  
#pragma omp atomic  
u.n++;  
#pragma omp atomic  
u.x -= 1.0f;  
```