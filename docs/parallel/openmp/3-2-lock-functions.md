---
title: "3.2 bloquear funções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 0ec855c6-55a9-49d7-bee4-5edae6e86a1b
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 151c809a7bd28a2e4384371f5cec3bd192eed9d1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="32-lock-functions"></a>3.2 Funções Lock
As funções descritas nesta seção manipulam bloqueios usados para sincronização.  
  
 Para as funções a seguir, a variável de bloqueio deve ter tipo **omp_lock_t**. Essa variável só deve ser acessada por meio dessas funções. Todas as funções de bloqueio exigem um argumento que tem um ponteiro para **omp_lock_t** tipo.  
  
-   O `omp_init_lock` função inicializa um bloqueio simple.  
  
-   O `omp_destroy_lock` função remove um bloqueio simple.  
  
-   O `omp_set_lock` função aguarda até que um bloqueio simple está disponível.  
  
-   O `omp_unset_lock` função libera um bloqueio simple.  
  
-   O `omp_test_lock` função testa um bloqueio simple.  
  
 Para as funções a seguir, a variável de bloqueio deve ter tipo **omp_nest_lock_t**.  Essa variável só deve ser acessada por meio dessas funções. Todas as funções de bloqueio empilhável exigem um argumento que tem um ponteiro para **omp_nest_lock_t** tipo.  
  
-   O `omp_init_nest_lock` função inicializa um bloqueio empilhável.  
  
-   O `omp_destroy_nest_lock` função remove um bloqueio empilhável.  
  
-   O `omp_set_nest_lock` função aguarda até que um bloqueio empilhável está disponível.  
  
-   O `omp_unset_nest_lock` função libera um bloqueio empilhável.  
  
-   O `omp_test_nest_lock` função testa um bloqueio empilhável.  
  
 As funções de bloqueio OpenMP acessar a variável de bloqueio de forma que eles sempre leia e atualizam o valor mais recente da variável de bloqueio. Portanto, não é necessário para que um programa OpenMP incluem explícita **liberar** diretivas para garantir que o valor da variável de bloqueio é consistente entre os diferentes threads. (Pode haver a necessidade de **liberar** diretivas para tornar os valores de outras variáveis consistente.)