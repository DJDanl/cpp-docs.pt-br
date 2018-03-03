---
title: "2.4.3 único construção | Microsoft Docs"
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
ms.assetid: 15c180cd-e462-4b41-bf8c-cb8b1afb1a9b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 72dc551986f149bda668c438ac5f51d01d530c51
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="243-single-construct"></a>2.4.3 Construto single
O **único** diretiva identifica uma construção que especifica que o bloco estruturado associado é executado por um thread na equipe (não necessariamente o thread principal). A sintaxe do **único** diretiva é da seguinte maneira:  
  
```  
#pragma omp single [clause[[,] clause] ...] new-linestructured-block  
```  
  
 A cláusula é um dos seguintes:  
  
 **privada (** *lista variável* **)**  
  
 **firstprivate (** *lista variável* **)**  
  
 **copyprivate (** *lista variável* **)**  
  
 **nowait**  
  
 Há uma barreira implícita após o **único** construir, a menos que um **nowait** cláusula for especificada.  
  
 Restrições para o **único** diretiva são da seguinte maneira:  
  
-   Um único **nowait** cláusula pode aparecer em uma **único** diretiva.  
  
-   O **copyprivate** cláusula não deve ser usada com a **nowait** cláusula.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **privada**, **firstprivate**, e **copyprivate** cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.