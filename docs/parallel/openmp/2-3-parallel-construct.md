---
title: 2.3 construto parallel | Microsoft Docs
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
ms.assetid: 190eacdf-2c16-4c06-8cb7-ac60eb211425
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 89167547085682a81cc1d281f4f32ab55022d27c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="23-parallel-construct"></a>2.3 Construto parallel
A seguinte diretiva define uma região parallel, que é uma região do programa a ser executado por vários threads em paralelo. Isso é a construção fundamental que inicia a execução paralela.  
  
```  
#pragma omp parallel [clause[ [, ]clause] ...] new-line   structured-block  
```  
  
 O *cláusula* é um dos seguintes:  
  
 **Se (** *expressão escalar* **)**  
  
 **privada (** *lista variável* **)**  
  
 **firstprivate (** *lista variável* **)**  
  
 **padrão (compartilhado &#124; nenhum)**  
  
 **compartilhado (** *lista variável* **)**  
  
 **copyin (** *lista variável* **)**  
  
 **redução (** *operador* **:***lista variável* **)**   
  
 **num_threads (** *expressão de inteiro* **)**  
  
 Quando um thread encontra uma construção paralela, uma equipe de threads é criada se uma das seguintes situações for verdadeira:  
  
-   Não **se** cláusula estiver presente.  
  
-   O **se** expressão é avaliada como um valor diferente de zero.  
  
 Esse thread torna-se o thread principal da equipe, com um número de threads de 0, e todos os threads da equipe, incluindo o thread mestre, executem a região em paralelo. Se o valor de **se** expressão for zero, a região é serializada.  
  
 Para determinar o número de threads que são solicitadas, as regras a seguir serão consideradas em ordem. A primeira regra cuja condição será aplicada:  
  
1.  Se o **num_threads** cláusula estiver presente, então o valor da expressão de inteiro é o número de threads solicitado.  
  
2.  Se o **omp_set_num_threads** chamada de função de biblioteca, em seguida, o valor do argumento na chamada executada mais recentemente é o número de threads solicitado.  
  
3.  Se a variável de ambiente **OMP_NUM_THREADS** for definida, o valor dessa variável de ambiente é o número de threads solicitado.  
  
4.  Se nenhum dos métodos acima foram usadas, o número de threads solicitado é definido pela implementação.  
  
 Se o **num_threads** cláusula estiver presente, em seguida, ele substitui o número de threads solicitado pelo **omp_set_num_threads** função de biblioteca ou o **OMP_NUM_THREADS** variável de ambiente somente para a região paralela a que será aplicada. Regiões paralelas subsequentes não são afetados por ela.  
  
 O número de threads que executam a região parallel também depende se o ajuste dinâmico do número de threads está habilitado. Se ajuste dinâmico estiver desabilitado, o número de threads solicitado executará a região paralela. Se o ajuste dinâmico é habilitado o número solicitado de threads é o número máximo de threads que podem ser executadas a região paralela.  
  
 Se uma região parallel for encontrada durante o ajuste dinâmico do número de threads está desabilitado e o número de threads solicitado para a região parallel excede o número que pode fornecer o sistema de tempo de execução, o comportamento do programa é definido pela implementação. Uma implementação pode, por exemplo, interromper a execução do programa, ou ele pode serializar a região paralela.  
  
 O **omp_set_dynamic** função de biblioteca e o **OMP_DYNAMIC** variável de ambiente pode ser usada para ativar e desativar o ajuste dinâmico do número de threads.  
  
 O número de processadores físicos de hospedagem, na verdade, os threads a qualquer momento determinado é definido pela implementação. Depois de criado, o número de threads na equipe permanece constante durante essa região paralela. Ele pode ser alterado explicitamente pelo usuário ou automaticamente pelo sistema de tempo de execução de uma região parallel para outro.  
  
 As instruções contidas na extensão dinâmica da região de dados paralela são executadas por cada thread, e cada thread pode executar um caminho de instruções que é diferente dos outros threads. Diretivas encontradas fora a extensão de léxica de uma região parallel são chamadas de diretivas de órfãos.  
  
 Há uma barreira implícita ao final de uma região parallel. Somente o thread principal da equipe continua a execução do final de uma região parallel.  
  
 Se um thread em uma equipe de execução de uma região parallel encontrar outra construção paralela, ele cria uma nova equipe e torna-se o mestre da nova equipe. Regiões paralelas aninhados são serializados por padrão. Como resultado, por padrão, uma região parallel aninhada é executada por uma equipe composta de um thread. O comportamento padrão pode ser alterado usando a função de biblioteca de tempo de execução **omp_set_nested** ou a variável de ambiente **OMP_NESTED**. No entanto, o número de segmentos em uma equipe que execute uma região parallel aninhada é definido pela implementação.  
  
 Restrições para o **paralela** diretiva são da seguinte maneira:  
  
-   No máximo uma **se** cláusula pode aparecer na diretiva.  
  
-   É não especificado se qualquer lado efeitos dentro de se expressão ou **num_threads** expressão ocorrer.  
  
-   Um **gerar** executado dentro de uma região parallel deve causar a execução de retomar dentro a extensão dinâmica do mesmo bloco estruturado, e ele deve ser capturado pelo mesmo thread que lançou a exceção.  
  
-   Um único **num_threads** cláusula pode aparecer na diretiva. O **num_threads** expressão é avaliada fora do contexto da região de dados paralela e deve ser avaliada como um valor inteiro positivo.  
  
-   A ordem de avaliação do **se** e **num_threads** cláusulas for especificado.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **privada**, **firstprivate**, **padrão**, **compartilhado**, **copyin**, e **redução**cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.  
  
-   **OMP_NUM_THREADS** variável de ambiente, [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48.  
  
-   **omp_set_dynamic** função de biblioteca, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.  
  
-   **OMP_DYNAMIC** consulte de variável de ambiente [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49.  
  
-   **omp_set_nested** funcionam, consulte [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página 40.  
  
-   **OMP_NESTED** consulte de variável de ambiente [seção 4.4](../../parallel/openmp/4-4-omp-nested.md) na página 49.  
  
-   **omp_set_num_threads** função de biblioteca, consulte [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página 36.