---
title: A.29   Uso de constructos de compartilhamento de trabalho em um construto crítico
ms.date: 11/04/2016
ms.assetid: d5c8a83f-2f51-4f23-8ddf-d267e347507f
ms.openlocfilehash: fac5576f859f63298d658b51c4307bb238e301c8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643580"
---
# <a name="a29---use-of-work-sharing-constructs-inside-a-critical-construct"></a>A.29   Uso de constructos de compartilhamento de trabalho em um construto crítico

O exemplo a seguir demonstra o uso de uma construção de compartilhamento de trabalho dentro de um `critical` construir. Este exemplo está em conformidade porque o compartilhamento de trabalho de construir e o `critical` constructo não serão associadas à mesma região paralela.

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