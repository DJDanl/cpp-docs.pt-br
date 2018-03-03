---
title: "3.2.5 funções omp_test_lock e omp_test_nest_lock | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 36818945-c22c-4c24-b754-4e73eba6f3f8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8fcdacdbb38a9bb27e35ada74aa2139be10c6797
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="325-omptestlock-and-omptestnestlock-functions"></a>3.2.5 funções omp_test_lock e omp_test_nest_lock
Essas funções tentam de definir um bloqueio, mas não bloquear a execução do thread. O formato é o seguinte:  
  
```  
#include <omp.h>  
int omp_test_lock(omp_lock_t *lock);  
int omp_test_nest_lock(omp_nest_lock_t *lock);  
```  
  
 O argumento deve apontar para uma variável de bloqueio foi inicializado. Essas funções tentam de definir um bloqueio da mesma maneira como `omp_set_lock` e `omp_set_nest_lock`, exceto que eles não bloqueiam a execução do thread.  
  
 Um bloqueio simples, o `omp_test_lock` função retorna um valor diferente de zero se o bloqueio é definido com êxito; caso contrário, retorna zero.  
  
 Um bloqueio empilhável, o `omp_test_nest_lock` função retorna a nova contagem de aninhamento se o bloqueio é definido com êxito; caso contrário, retorna zero.