---
title: 3.1.6 função omp_in_parallel | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: db6e3a63-2a0a-4b8e-8cc6-c6b49edca5fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 22b491695d2ae49336d7d8998af64e724f344d87
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="316-ompinparallel-function"></a>3.1.6 função omp_in_parallel
O **omp_in_parallel** função retorna um valor diferente de zero se ele é chamado dentro de extensão dinâmica de uma região parallel em execução em paralelo; caso contrário, retornará 0. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_in_parallel(void);  
```  
  
 Essa função retorna um valor diferente de zero quando chamado de dentro de uma região de execução em paralelo, inclusive regiões aninhadas que são serializados.