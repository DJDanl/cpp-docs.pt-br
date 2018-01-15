---
title: Uso A.30 de Reprivatization | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 26529090-6c39-40f2-b806-e12374d6b5f8
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1b8a6bedad37e9edd70edd014a9dd8f70143bbe5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="a30---use-of-reprivatization"></a>A.30   Uso de reprivatização
O exemplo a seguir demonstra o reprivatization de variáveis. Variáveis privadas podem ser marcados `private` novamente em uma diretiva aninhada. Eles não precisam ser compartilhado na região parallel delimitador.  
  
```  
int i, a;  
...  
#pragma omp parallel private(a)  
{  
  ...  
  #pragma omp parallel for private(a)  
  for (i=0; i<10; i++)  
     {  
       ...  
     }  
}  
```