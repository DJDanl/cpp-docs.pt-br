---
title: 2.4.2 constructo sections | Microsoft Docs
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
ms.assetid: e9e6e3ea-7fc9-4925-8f68-92b8a5bb1e76
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6e5b755e95e9bbbb78d6ab13cd09732f9c9aee3d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="242-sections-construct"></a>2.4.2 Constructo sections
O **seções** diretiva identifica uma construção de compartilhamento em trabalho noniterative que especifica um conjunto de construções que devem ser divididos entre os threads em uma equipe. Cada seção é executada uma vez por um thread na equipe. A sintaxe do **seções** diretiva é da seguinte maneira:  
  
```  
#pragma omp sections [clause[[,] clause] ...] new-line  
   {  
   [#pragma omp section new-line]  
      structured-block  
   [#pragma omp section new-linestructured-block ]  
...  
}  
```  
  
 A cláusula é um dos seguintes:  
  
 **privada (** *lista variável* **)**  
  
 **firstprivate (** *lista variável* **)**  
  
 **lastprivate (** *lista variável* **)**  
  
 **redução (** *operador* **:***lista variável* **)**   
  
 **nowait**  
  
 Cada seção é precedida por um **seção** diretiva, embora o **seção** diretiva é opcional para a primeira seção. O **seção** diretivas devem aparecer dentro a extensão de léxica do **seções** diretiva. Há uma barreira implícita ao final de um **seções** construir, a menos que um **nowait** for especificado.  
  
 Restrições para o **seções** diretiva são da seguinte maneira:  
  
-   Um **seção** diretiva não pode aparecer fora a extensão de léxica do **seções** diretiva.  
  
-   Um único **nowait** cláusula pode aparecer em uma **seções** diretiva.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **privada**, **firstprivate**, **lastprivate**, e **redução** cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.