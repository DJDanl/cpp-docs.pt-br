---
title: A.29 compartilhamento de uso de trabalho constrói dentro de uma construção crítica | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: d5c8a83f-2f51-4f23-8ddf-d267e347507f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ccbb39a9067adf545339d02fe0c05e24fbcdb0a4
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691346"
---
# <a name="a29---use-of-work-sharing-constructs-inside-a-critical-construct"></a>A.29   Uso de constructos de compartilhamento de trabalho em um construto crítico
O exemplo a seguir demonstra o uso de uma construção de compartilhamento de trabalho dentro de um `critical` construir. Este exemplo é compatível porque o compartilhamento de trabalho construir e `critical` construção não associar à mesma região paralela.  
  
```  
void f()  
{  
  int i = 1;  
  #pragma omp parallel sections  
  {  
    #pragma omp section  
    {  
      #pragma omp critical (name)  
      {  
        #pragma omp parallel  
        {  
          #pragma omp single  
          {  
            i++;  
          }  
        }  
      }  
    }  
  }  
}  
```