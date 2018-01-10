---
title: "3.2.1 funções omp_init_lock e omp_init_nest_lock | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 098a2721-b16a-484f-bc83-4b8e281e382c
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3802822465d6527e4c98a0be6a8c274d767b0f52
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="321-ompinitlock-and-ompinitnestlock-functions"></a>3.2.1 funções omp_init_lock e omp_init_nest_lock
Essas funções fornecem a única forma de inicializar um bloqueio. Cada função inicializa o bloqueio associado ao parâmetro *bloqueio* para uso em chamadas subsequentes. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_init_lock(omp_lock_t *lock);  
void omp_init_nest_lock(omp_nest_lock_t *lock);  
```  
  
 O estado inicial seja desbloqueado (ou seja, nenhum thread possui o bloqueio). Para obter um bloqueio empilhável, a contagem inicial de aninhamento é zero. Ele está em conformidade para chamar um essas rotinas com uma variável de bloqueio que já foi inicializado.