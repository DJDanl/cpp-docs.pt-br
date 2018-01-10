---
title: "3. Funções de biblioteca em tempo de execução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: b226e512-6822-4cbe-a2ca-74cc2bb7e880
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f1cbedf8782c9c5ccb25bda3f8b43df8a526f268
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="3-run-time-library-functions"></a>3. Funções de biblioteca em tempo de execução
Esta seção descreve as funções de biblioteca de tempo de execução OpenMP C e C++. O cabeçalho  **\<omp.h >** declara dois tipos, várias funções que podem ser usadas para controlar o ambiente de execução paralela da consulta e funções que podem ser usadas para sincronizar o acesso aos dados de bloqueio.  
  
 O tipo **omp_lock_t** é um tipo de objeto capaz de representar que um bloqueio está disponível ou que um thread possui um bloqueio. Esses bloqueios são chamados de *bloqueios simples*.  
  
 O tipo **omp_nest_lock_t** é um tipo de objeto capaz de representar que um bloqueio estiver disponível, ou seja, a identidade do thread que possui o bloqueio e um *aninhamento contagem* (descritas abaixo). Esses bloqueios são chamados de *bloqueios empilhável*.  
  
 As funções de biblioteca são funções externas com ligação "C".  
  
 As descrições neste capítulo são divididas nos seguintes tópicos:  
  
-   Funções do ambiente de execução (consulte [seção 3.1](../../parallel/openmp/3-1-execution-environment-functions.md) na página 35).  
  
-   Funções de bloqueio (consulte [seção 3.2](../../parallel/openmp/3-2-lock-functions.md) na página 41).