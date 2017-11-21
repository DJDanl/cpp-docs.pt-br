---
title: "3.1.7 função omp_set_dynamic | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 1fba961b-b82c-4a1e-ab0f-e4be826e50ab
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1569235e807fb8e6981c45d7547cae7bd6f70c56
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="317-ompsetdynamic-function"></a>3.1.7 função omp_set_dynamic
O **omp_set_dynamic** função ativa ou desativa o ajuste dinâmico do número de threads disponíveis para execução de regiões paralelas. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_set_dynamic(int dynamic_threads);  
```  
  
 Se *dynamic_threads* é avaliada como um valor diferente de zero, o número de threads que são usados para a execução de regiões paralelas subsequentes pode ajustado automaticamente pelo ambiente de tempo de execução para utilizar melhor os recursos do sistema. Como consequência, o número de threads especificado pelo usuário é a contagem máxima de threads. O número de threads da equipe de execução de uma região parallel permanece fixo para a duração da região paralela e é reportado pelo **omp_get_num_threads** função.  
  
 Se *dynamic_threads* é avaliada como 0, o ajuste dinâmico está desabilitado.  
  
 Essa função tem os efeitos descritos acima, quando chamado a partir de uma parte do programa de onde o **omp_in_parallel** função retornará zero. Se ele é chamado de uma parte do programa de onde o **omp_in_parallel** função retorna um valor diferente de zero, o comportamento dessa função é indefinido.  
  
 Uma chamada para **omp_set_dynamic** tem precedência sobre o **OMP_DYNAMIC** variável de ambiente.  
  
 O padrão para o ajuste dinâmico de threads é definido pela implementação. Como resultado, os códigos de usuário que dependem de um número específico de segmentos de execução correta desabilite explicitamente threads dinâmicos. Implementações não são necessárias para fornecer a capacidade de ajustar dinamicamente o número de threads, mas eles são necessários para fornecer a interface para oferecer suporte a portabilidade em todas as plataformas.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **omp_get_num_threads** funcionam, consulte [seção 3.1.2](../../parallel/openmp/3-1-2-omp-get-num-threads-function.md) na página 37.  
  
-   **OMP_DYNAMIC** consulte de variável de ambiente [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49.  
  
-   **omp_in_parallel** funcionam, consulte [seção 3.1.6](../../parallel/openmp/3-1-6-omp-in-parallel-function.md) na página 38.