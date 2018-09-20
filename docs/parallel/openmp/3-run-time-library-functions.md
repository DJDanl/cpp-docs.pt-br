---
title: 3. Funções da biblioteca em tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: b226e512-6822-4cbe-a2ca-74cc2bb7e880
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5c1a05df3b47c2bbf345bc0101f30ffb83b84967
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46401833"
---
# <a name="3-run-time-library-functions"></a>3. Funções da biblioteca em tempo de execução

Esta seção descreve as funções da biblioteca de tempo de execução OpenMP C e C++. O cabeçalho  **\<OMP >** declara dois tipos, várias funções que podem ser usadas para controlar e consultar o ambiente de execução paralela e funções que podem ser usadas para sincronizar o acesso aos dados de bloqueio.

O tipo **omp_lock_t** é um tipo de objeto capaz de representar a que um bloqueio está disponível ou que um thread possui um bloqueio. Esses bloqueios são denominados *bloqueios simples*.

O tipo **omp_nest_lock_t** é um tipo de objeto capaz de representar qualquer um dos que um bloqueio está disponível ou a identidade do thread que possui o bloqueio e um *aninhamento contagem* (descritos abaixo). Esses bloqueios são denominados *bloqueios aninháveis*.

As funções de biblioteca são funções externas com vínculo "C".

As descrições deste capítulo são divididas nos seguintes tópicos:

- Funções do ambiente de execução (consulte [seção 3.1](../../parallel/openmp/3-1-execution-environment-functions.md) na página 35).

- Funções de bloqueio (consulte [seção 3.2](../../parallel/openmp/3-2-lock-functions.md) na página 41).