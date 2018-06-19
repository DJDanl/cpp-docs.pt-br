---
title: 3. Funções de biblioteca em tempo de execução | Microsoft Docs
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
ms.openlocfilehash: d747f775509c6b3b2b95be51d95ea937816d3cd1
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33688109"
---
# <a name="3-run-time-library-functions"></a>3. Funções de biblioteca em tempo de execução
Esta seção descreve as funções de biblioteca de tempo de execução OpenMP C e C++. O cabeçalho  **\<omp.h >** declara dois tipos, várias funções que podem ser usadas para controlar o ambiente de execução paralela da consulta e funções que podem ser usadas para sincronizar o acesso aos dados de bloqueio.  
  
 O tipo **omp_lock_t** é um tipo de objeto capaz de representar que um bloqueio está disponível ou que um thread possui um bloqueio. Esses bloqueios são chamados de *bloqueios simples*.  
  
 O tipo **omp_nest_lock_t** é um tipo de objeto capaz de representar que um bloqueio estiver disponível, ou seja, a identidade do thread que possui o bloqueio e um *aninhamento contagem* (descritas abaixo). Esses bloqueios são chamados de *bloqueios empilhável*.  
  
 As funções de biblioteca são funções externas com ligação "C".  
  
 As descrições neste capítulo são divididas nos seguintes tópicos:  
  
-   Funções do ambiente de execução (consulte [seção 3.1](../../parallel/openmp/3-1-execution-environment-functions.md) na página 35).  
  
-   Funções de bloqueio (consulte [seção 3.2](../../parallel/openmp/3-2-lock-functions.md) na página 41).