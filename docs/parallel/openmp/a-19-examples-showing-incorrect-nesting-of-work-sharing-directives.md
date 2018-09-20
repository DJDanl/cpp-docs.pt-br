---
title: A.19 exemplos que mostram o aninhamento incorreto de diretivas de compartilhamento de trabalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 906e900d-9259-44d6-a095-c1ba9135d269
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3cf9502fd17fced7a4bc2a208634b825443f196a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46411515"
---
# <a name="a19---examples-showing-incorrect-nesting-of-work-sharing-directives"></a>A.19   Exemplos que mostram o aninhamento incorreto de diretivas de compartilhamento do trabalho

Os exemplos nesta seção ilustram as regras de aninhamento de diretiva. Para obter mais informações sobre o aninhamento de diretiva, consulte [seção 2.9](../../parallel/openmp/2-9-directive-nesting.md) na página 33.

O exemplo a seguir não está em conformidade porque internas e externas `for` diretivas que estão aninhadas e associar à mesma `parallel` diretiva:

```
void wrong1(int n)
{
  #pragma omp parallel default(shared)
  {
      int i, j;
      #pragma omp for
      for (i=0; i<n; i++) {
          #pragma omp for
              for (j=0; j<n; j++)
                 work(i, j);
     }
   }
}
```

A seguinte versão dinamicamente aninhada do exemplo anterior também está fora de conformidade:

```
void wrong2(int n)
{
  #pragma omp parallel default(shared)
  {
    int i;
    #pragma omp for
      for (i=0; i<n; i++)
        work1(i, n);
  }
}

void work1(int i, int n)
{
  int j;
  #pragma omp for
    for (j=0; j<n; j++)
      work2(i, j);
}
```

O exemplo a seguir não está em conformidade porque o `for` e `single` diretivas estão aninhadas e eles se ligam para a mesma região paralela:

```
void wrong3(int n)
{
  #pragma omp parallel default(shared)
  {
    int i;
    #pragma omp for
      for (i=0; i<n; i++) {
        #pragma omp single
          work(i);
      }
  }
}
```

O exemplo a seguir não está em conformidade porque uma `barrier` diretiva dentro de um `for` pode resultar em deadlock:

```
void wrong4(int n)
{
  #pragma omp parallel default(shared)
  {
    int i;
    #pragma omp for
      for (i=0; i<n; i++) {
        work1(i);
        #pragma omp barrier
        work2(i);
      }
  }
}
```

O exemplo a seguir não está em conformidade porque a `barrier` resulta em deadlock devido ao fato de que apenas um thread por vez pode inserir a seção crítica:

```
void wrong5()
{
  #pragma omp parallel
  {
    #pragma omp critical
    {
       work1();
       #pragma omp barrier
       work2();
    }
  }
}
```

O exemplo a seguir não está em conformidade porque o `barrier` resulta em deadlock devido ao fato de que apenas um thread executa o `single` seção:

```
void wrong6()
{
  #pragma omp parallel
  {
    setup();
    #pragma omp single
    {
      work1();
      #pragma omp barrier
      work2();
    }
    finish();
  }
}
```