---
title: Exemplos A.23 da diretiva ordenada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: f8fa761b-7fc5-4447-95f9-8571e9ca31bf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 37cc4ea9db8cbd1a7bf095e2bde0ae482053a584
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33692738"
---
# <a name="a23---examples-of-the-ordered-directive"></a>A.23   Exemplos da diretiva ordered
É possível ter várias seções ordenadas com uma `for` especificado com o `ordered` cláusula. O primeiro exemplo não for compatível, porque a API Especifica o seguinte:  
  
 "Uma iteração de um loop com um `for` construção não deve executar a mesma `ordered` diretiva mais de uma vez e ele não devem executar mais de um `ordered` diretiva." (Consulte [seção 2.6.6](../../parallel/openmp/2-6-6-ordered-construct.md) na página 22)  
  
 Neste exemplo não compatível, todas as iterações execute 2 seções ordenadas:  
  
```  
#pragma omp for ordered  
for (i=0; i<n; i++)   
{  
    ...  
    #pragma omp ordered  
    { ... }  
    ...  
    #pragma omp ordered  
    { ... }  
    ...  
}  
```  
  
 Mostra o seguinte exemplo compatíveis com um `for` com mais de uma seção de ordenados:  
  
```  
#pragma omp for ordered  
for (i=0; i<n; i++)   
{  
    ...  
    if (i <= 10)   
    {  
        ...  
        #pragma omp ordered  
        { ... }  
    }  
    ...  
    (i > 10)   
    {  
        ...  
        #pragma omp ordered  
        { ... }  
    }  
    ...  
}  
```