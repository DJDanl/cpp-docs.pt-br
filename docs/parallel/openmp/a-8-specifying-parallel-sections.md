---
title: "A. 8 especificando seções paralelas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: cf399304-121e-4c07-9829-47e0dbc2ef10
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d369c2e3a0d326ab4c835a30681f3dbe50f789f0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="a8---specifying-parallel-sections"></a>A.8   Especificando seções em paralelo
No exemplo a seguir (para [seção 2.4.2](../../parallel/openmp/2-4-2-sections-construct.md) na página 14) funções *xaxis*, *yaxis*, e *zaxis* podem ser executados simultaneamente. A primeira `section` diretiva é opcional.  Observe que todos os `section` diretivas precisam aparecer na extensão de léxico o `parallel sections` construir.  
  
```  
#pragma omp parallel sections  
{  
    #pragma omp section  
        xaxis();  
    #pragma omp section  
        yaxis();  
    #pragma omp section  
        zaxis();  
}  
```