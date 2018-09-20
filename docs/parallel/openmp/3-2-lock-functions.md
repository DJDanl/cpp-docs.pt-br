---
title: 3.2 funções de bloqueio | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 0ec855c6-55a9-49d7-bee4-5edae6e86a1b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 97f125129d4b35586111f3d4092d457560aaebec
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412269"
---
# <a name="32-lock-functions"></a>3.2 Funções Lock

As funções descritas nesta seção manipulam bloqueios usados para sincronização.

Para as funções a seguir, a variável de bloqueio deve ter o tipo **omp_lock_t**. Essa variável deve ser acessada somente por meio dessas funções. Todas as funções de bloqueio exigem um argumento que tem um ponteiro para **omp_lock_t** tipo.

- O `omp_init_lock` função inicializa um bloqueio simples.

- O `omp_destroy_lock` função remove um bloqueio simples.

- O `omp_set_lock` função aguarda até que um bloqueio simple está disponível.

- O `omp_unset_lock` função libera um bloqueio simples.

- O `omp_test_lock` função testa um bloqueio simples.

Para as funções a seguir, a variável de bloqueio deve ter o tipo **omp_nest_lock_t**.  Essa variável deve ser acessada somente por meio dessas funções. Todas as funções de bloqueio empilhável exigem um argumento que tem um ponteiro para **omp_nest_lock_t** tipo.

- O `omp_init_nest_lock` função inicializa um bloqueio empilhável.

- O `omp_destroy_nest_lock` função remove um bloqueio empilhável.

- O `omp_set_nest_lock` função aguarda até que um bloqueio empilhável está disponível.

- O `omp_unset_nest_lock` função libera um bloqueio empilhável.

- O `omp_test_nest_lock` função testa um bloqueio empilhável.

As funções de bloqueio do OpenMP acessam a variável de bloqueio de tal forma que eles sempre leia e atualizam o valor mais atual da variável de bloqueio. Portanto, não é necessária para um programa OpenMP incluem explícito **liberar** diretivas para garantir que o valor da variável de bloqueio é consistente entre diferentes threads. (Pode haver uma necessidade **liberar** diretivas para tornar os valores de outras variáveis consistentes.)