---
title: 2.6.4 constructo atomic | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: e4232ef1-4058-42ce-9de0-0ca788312aba
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 629fff5b0bef507b775fbe1b5bfabadd50b790be
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="264-atomic-construct"></a>2.6.4 Constructo atomic
O `atomic` diretiva garante que um local de memória específica é atualizado atomicamente, em vez de expô-lo para a possibilidade de várias simultâneas de gravação de threads. A sintaxe da `atomic` diretiva é da seguinte maneira:  
  
```  
#pragma omp atomic new-lineexpression-stmt  
```  
  
 A instrução de expressão deve ter uma das seguintes formas:  
  
 *x binop*= *expr*  
  
 x + +  
  
 + + x  
  
 x-  
  
 --x  
  
 As expressões anteriores:  
  
-   *x* é uma expressão de lvalue com tipo escalar.  
  
-   *Expr* é uma expressão com um tipo escalar, e ele não faz referência o objeto designado pelo *x*.  
  
-   `binop`não é um operador sobrecarregado e é um dos +, *, -, /, &, ^, &#124; <\<, ou >>.  
  
 Embora seja definido pela implementação se uma implementação substitui todos os `atomic` diretivas com **crítico** diretivas que têm o mesmo exclusivo *nome*, o `atomic` diretiva permite melhor otimização. Instruções de hardware geralmente estão disponíveis que pode executar a atualização atômica com a menor sobrecarga.  
  
 Somente o carregamento e o armazenamento do objeto designado pelo *x* são atômicas; a avaliação de *expr* não é atômica. Para evitar condições de corrida, todas as atualizações do local em paralelo devem ser protegidas com o `atomic` diretiva, exceto aqueles que são conhecidos como livre de condições de corrida.  
  
 Restrições para o `atomic` diretiva são da seguinte maneira:  
  
-   Todas as referências atômicas para o local de armazenamento x em todo o programa deve ter um tipo compatível.  
  
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