---
title: 3. Funções da biblioteca em tempo de execução
ms.date: 11/04/2016
ms.assetid: b226e512-6822-4cbe-a2ca-74cc2bb7e880
ms.openlocfilehash: e1d8d498be7f58bcf510025c67c539127f450824
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484091"
---
# <a name="3-run-time-library-functions"></a>3. Funções da biblioteca em tempo de execução

Esta seção descreve as funções da biblioteca de tempo de execução OpenMP C e C++. O cabeçalho  **\<OMP >** declara dois tipos, várias funções que podem ser usadas para controlar e consultar o ambiente de execução paralela e funções que podem ser usadas para sincronizar o acesso aos dados de bloqueio.

O tipo **omp_lock_t** é um tipo de objeto capaz de representar a que um bloqueio está disponível ou que um thread possui um bloqueio. Esses bloqueios são denominados *bloqueios simples*.

O tipo **omp_nest_lock_t** é um tipo de objeto capaz de representar qualquer um dos que um bloqueio está disponível ou a identidade do thread que possui o bloqueio e um *aninhamento contagem* (descritos abaixo). Esses bloqueios são denominados *bloqueios aninháveis*.

As funções de biblioteca são funções externas com vínculo "C".

As descrições deste capítulo são divididas nos seguintes tópicos:

- Funções do ambiente de execução (consulte [seção 3.1](../../parallel/openmp/3-1-execution-environment-functions.md) na página 35).

- Funções de bloqueio (consulte [seção 3.2](../../parallel/openmp/3-2-lock-functions.md) na página 41).