---
title: 2.3 construto parallel | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 190eacdf-2c16-4c06-8cb7-ac60eb211425
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4be5bdc40f69cfa0a326ffa6a7f8465e401cfd33
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46448227"
---
# <a name="23-parallel-construct"></a>2.3 Construto parallel

A diretiva a seguir define uma região paralela, o que é uma região do programa que deve ser executado por vários threads em paralelo. Isso é a construção fundamental que inicia a execução paralela.

```
#pragma omp parallel [clause[ [, ]clause] ...] new-line   structured-block
```

O *cláusula* é um dos seguintes:

**if(** *scalar-expression* **)**

**private(** *variable-list* **)**

**firstprivate(** *variable-list* **)**

**padrão (compartilhado &#124; none)**

**shared(** *variable-list* **)**

**copyin(** *variable-list* **)**

**reduction(** *operator* **:**  *variable-list* **)**

**num_threads(** *integer-expression* **)**

Quando um thread encontra um constructo paralelo, uma equipe de threads é criada, se um dos casos a seguir for verdadeiro:

- Não **se** cláusula estiver presente.

- O **se** expressão é avaliada como um valor diferente de zero.

Esse thread torna-se o thread mestre da equipe, com um número de threads de 0, e todos os threads da equipe, incluindo o thread mestre, executem a região em paralelo. Se o valor de **se** expressão for zero, a região é serializada.

Para determinar o número de threads que são solicitados, as regras a seguir serão consideradas na ordem. A primeira regra cuja condição é atendida será aplicada:

1. Se o **num_threads** cláusula estiver presente, então o valor da expressão de inteiro é o número de threads solicitado.

1. Se o **omp_set_num_threads** biblioteca a função foi chamada e, em seguida, o valor do argumento na chamada executada mais recentemente é o número de threads solicitado.

1. Se a variável de ambiente **OMP_NUM_THREADS** for definida, o valor dessa variável de ambiente é o número de threads solicitado.

1. Se nenhum dos métodos acima foram usadas, o número de threads solicitado é definido pela implementação.

Se o **num_threads** cláusula estiver presente e em seguida, ele substitui o número de threads solicitado pelo **omp_set_num_threads** função de biblioteca ou o **OMP_NUM_THREADS** variável de ambiente somente para a região paralela é aplicada a. Regiões em paralelo subsequente não é afetado por ela.

O número de threads que executam a região paralela também depende ou não o ajuste dinâmico do número de threads está habilitado. Se o ajuste dinâmico for desabilitado, o número solicitado de threads executará a região paralela. Se o ajuste dinâmico estiver habilitado, em seguida, o número solicitado de threads é o número máximo de threads que podem ser executadas a região paralela.

Se uma região parallel for encontrada enquanto o ajuste dinâmico do número de threads está desabilitado e o número de threads solicitada para a região paralela excede o número que o sistema de tempo de execução pode fornecer, o comportamento do programa é definido pela implementação. Uma implementação pode, por exemplo, interromper a execução do programa, ou ele pode serializar a região paralela.

O **omp_set_dynamic** função de biblioteca e o **OMP_DYNAMIC** variável de ambiente pode ser usada para ativar e desativar o ajuste dinâmico do número de threads.

O número de processadores físicos, hospedagem, na verdade, os threads em um determinado momento é definido pela implementação. Depois de criado, o número de threads na equipe permanece constante durante essa região paralela. Ele pode ser alterado explicitamente pelo usuário ou automaticamente pelo sistema de tempo de execução de uma região paralela para outro.

As instruções contidas em extensão dinâmico da região paralela são executadas por cada thread, e cada thread pode executar um caminho de instruções que é diferente de outros threads. Diretivas encontradas fora a extensão de léxica de uma região paralela são chamadas de diretivas de órfãos.

Há uma barreira implícita no final de uma região paralela. Somente o thread mestre da equipe continua a execução no final de uma região paralela.

Se um thread em uma equipe de execução de uma região parallel encontrar outro constructo parallel, ele cria uma nova equipe, e ele se torna o mestre da nova equipe. Regiões em paralelo aninhadas são serializadas por padrão. Como resultado, por padrão, uma região paralela aninhada é executada por uma equipe composta de um thread. O comportamento padrão pode ser alterado usando a função de biblioteca de tempo de execução **omp_set_nested** ou a variável de ambiente **OMP_NESTED**. No entanto, o número de threads que executam uma região paralela aninhada em uma equipe é definido pela implementação.

Restrições para o **paralela** diretiva são da seguinte maneira:

- No máximo uma **se** cláusula pode aparecer na diretiva.

- É especificado se qualquer lado efeitos dentro do if expressão ou **num_threads** expressão ocorrer.

- Um **lançar** executado dentro de uma região parallel deve causar a execução de retomar dentro a extensão dinâmica do mesmo bloco estruturado, e ela deve ser capturada pelo mesmo thread que gerou a exceção.

- Um único **num_threads** cláusula pode aparecer na diretiva. O **num_threads** expressão é avaliada fora do contexto da região paralela e deve ser avaliada como um valor inteiro positivo.

- A ordem de avaliação do **se** e **num_threads** cláusulas não está especificado.

## <a name="cross-references"></a>Entre as referências:

- **privado**, **firstprivate**, **padrão**, **compartilhado**, **copyin**, e **redução**cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.

- **OMP_NUM_THREADS** variável de ambiente [seção 4.2](../../parallel/openmp/4-2-omp-num-threads.md) na página 48.

- **omp_set_dynamic** função de biblioteca, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.

- **OMP_DYNAMIC** consulte de variável de ambiente [seção 4.3](../../parallel/openmp/4-3-omp-dynamic.md) na página 49.

- **omp_set_nested** , consulte [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página de 40.

- **OMP_NESTED** consulte de variável de ambiente [seção 4.4](../../parallel/openmp/4-4-omp-nested.md) na página 49.

- **omp_set_num_threads** função de biblioteca, consulte [seção 3.1.1](../../parallel/openmp/3-1-1-omp-set-num-threads-function.md) na página de 36.