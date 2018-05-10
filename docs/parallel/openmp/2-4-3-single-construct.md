---
title: 2.4.3 único construção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 15c180cd-e462-4b41-bf8c-cb8b1afb1a9b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: db3f9ca834fb3f35c95732698fd02e16f31b4225
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="243-single-construct"></a>2.4.3 Construto single
O **único** diretiva identifica uma construção que especifica que o bloco estruturado associado é executado por um thread na equipe (não necessariamente o thread principal). A sintaxe do **único** diretiva é da seguinte maneira:  
  
```  
#pragma omp single [clause[[,] clause] ...] new-linestructured-block  
```  
  
 A cláusula é um dos seguintes:  
  
 **private(** *variable-list* **)**  
  
 **firstprivate(** *variable-list* **)**  
  
 **copyprivate (** *lista variável* **)**  
  
 **nowait**  
  
 Há uma barreira implícita após o **único** construir, a menos que um **nowait** cláusula for especificada.  
  
 Restrições para o **único** diretiva são da seguinte maneira:  
  
-   Um único **nowait** cláusula pode aparecer em uma **único** diretiva.  
  
-   O **copyprivate** cláusula não deve ser usada com a **nowait** cláusula.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **privada**, **firstprivate**, e **copyprivate** cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.