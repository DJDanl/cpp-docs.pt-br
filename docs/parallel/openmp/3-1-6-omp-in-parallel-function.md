---
title: "3.1.6 função omp_in_parallel | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: db6e3a63-2a0a-4b8e-8cc6-c6b49edca5fb
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2e5d05af81eb112894ca27a7599c271138893ee1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="316-ompinparallel-function"></a>3.1.6 função omp_in_parallel
O **omp_in_parallel** função retorna um valor diferente de zero se ele é chamado dentro de extensão dinâmica de uma região parallel em execução em paralelo; caso contrário, retornará 0. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_in_parallel(void);  
```  
  
 Essa função retorna um valor diferente de zero quando chamado de dentro de uma região de execução em paralelo, inclusive regiões aninhadas que são serializados.