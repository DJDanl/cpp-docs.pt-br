---
title: "2.6.4 Constructo atomic | Microsoft Docs"
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
ms.assetid: e4232ef1-4058-42ce-9de0-0ca788312aba
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.6.4 Constructo atomic
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A `atomic` diretiva garante que um local específico da memória é atualizada atomicamente, em vez de expô-lo para a possibilidade de vários threads de gravação simultâneas. A sintaxe de `atomic` diretiva é o seguinte:  
  
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
  
-   *x* é uma expressão de l-value com tipo escalar.  
  
-   *Expr* é uma expressão com um tipo escalar e não faz referência a objeto designado pelo *x*.  
  
-   `binop` não é um operador sobrecarregado e é um dos +, *, -, /, &, ^, &#124; <\<, ou >>.  
  
 Embora seja definido pela implementação se uma implementação substitui todos `atomic` diretivas com **crítico** diretivas que têm o mesmo exclusivo *nome*, o `atomic` diretiva permite melhor otimização. Instruções de hardware geralmente estão disponíveis que pode executar a atualização atômica com menos sobrecarga.  
  
 Apenas a carga e o armazenamento de objeto designado pelo *x* são atômicas; a avaliação de *expr* não é atômica. Para evitar condições de corrida, todas as atualizações do local em paralelo devem ser protegidas com o `atomic` diretiva, exceto aqueles que são conhecidos como livre de condições de corrida.  
  
 Restrições para o `atomic` diretiva são os seguintes:  
  
-   Todas as referências atômicas para o local de armazenamento x em todo o programa devem ter um tipo compatível.  
  
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