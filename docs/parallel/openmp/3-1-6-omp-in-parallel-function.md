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
ms.openlocfilehash: b72351095fd56ae6543c2ca742983eef315f2158
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="316-ompinparallel-function"></a>3.1.6 função omp_in_parallel
O **omp_in_parallel** função retorna um valor diferente de zero se ele é chamado dentro de extensão dinâmica de uma região parallel em execução em paralelo; caso contrário, retornará 0. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_in_parallel(void);  
```  
  
 Essa função retorna um valor diferente de zero quando chamado de dentro de uma região de execução em paralelo, inclusive regiões aninhadas que são serializados.