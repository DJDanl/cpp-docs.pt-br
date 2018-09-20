---
title: 2.4.1 constructo for | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 27d2cbce-786b-4819-91d3-d55b2cc57a5e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb9a554d9141223be7a5f6bc741c86b8f03511e2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46428533"
---
# <a name="241-for-construct"></a>2.4.1 Constructo for

O **para** diretiva identifica uma construção de compartilhamento de trabalho iterativa que especifica que as iterações do loop associado serão executadas em paralelo. As iterações do **para** loop são distribuídas entre os threads que já existem na equipe que está executando o constructo paralelo ao qual ele se associa. A sintaxe do **para** construção é da seguinte maneira:

```
#pragma omp for [clause[[,] clause] ... ] new-line for-loop
```

A cláusula é um dos seguintes:

**private(** *variable-list* **)**

**firstprivate(** *variable-list* **)**

**lastprivate(** *variable-list* **)**

**redução de (** *operador* **:** *lista variável* **)**

**Ordenado**

**agenda (** *tipo* [**,** *chunk_size*] **)**

**nowait**

O **para** diretiva impõe restrições na estrutura da correspondente **para** loop. Especificamente, o correspondente **para** loop deve ter a forma canônica:

**para (** *expr init* **;** *var lógico op b*; *incr expr* **)**

*Init-expr*<br/>
Um dos seguintes:

*var* = *lb*

*tipo de inteiro var* = *lb*

*expr INCR*<br/>
Um dos seguintes:

++ *var*

*var* ++

-- *var*

*var* --

*var* += *incr*

*var* -= *incr*

*var* = *var* + *incr*

*var* = *incr* + *var*

*var* = *var* - *incr*

*var*<br/>
Uma variável de inteiro com sinal. Se essa variável deve ser compartilhada, ele será implicitamente feito privada para a duração da **para**.   Essa variável não deve ser modificada dentro do corpo do **para** instrução. A menos que a variável é especificada **lastprivate**, seu valor depois que o loop é indeterminado.

*lógica op*<br/>
Um dos seguintes:

<

\<=

>

\>=

*balanceamento de carga*, *b*, e *incr*<br>
Expressões de inteiro de invariável de loop. Não há nenhuma sincronização durante a avaliação dessas expressões. Portanto, os efeitos colaterais avaliados produzir resultados indeterminados.

Observe que a forma canônica permite que o número de iterações de loop para ser computada na entrada para o loop. Esse cálculo é realizado com os valores no tipo de *var*, após as promoções de integral. Em particular, se o valor de *b* - *lb* + *incr* não pode ser representado nesse tipo, o resultado é indeterminado. Além disso, se *lógico op* é < ou \<=, em seguida, *incr expr* deve causar *var* aumentar em cada iteração do loop.   Se *lógico op* é > ou > =, em seguida, *incr expr* deve causar *var* diminuir em cada iteração do loop.

O **agendamento** cláusula Especifica como iterações da **para** loop são divididas entre os threads da equipe. A correção de um programa não deve depender de qual thread executa uma iteração específica. O valor de *chunk_size*, se especificado, deve ser uma expressão de inteiro de invariável de loop com um valor positivo. Não há nenhuma sincronização durante a avaliação desta expressão. Portanto, os efeitos colaterais avaliados produzir resultados indeterminados. A agenda *tipo* pode ser uma das seguintes opções:

Tabela 2-1 **agendamento** cláusula *tipo* valores

|||
|-|-|
|static|Quando **agendamento (estáticas** *chunk_size* **)** for especificado, as iterações são divididas em partes de um tamanho especificado pelo *chunk_size*. As partes são atribuídas estaticamente a threads da equipe em um estilo round-robin na ordem o número de threads. Quando nenhum *chunk_size* for especificado, o espaço de iteração é dividido em partes que são aproximadamente iguais em tamanho, com uma parte atribuída a cada thread.|
|dinâmica|Quando **agendamento (dinâmico,** *chunk_size* **)** for especificado, as iterações são divididas em uma série de blocos, cada uma contendo *chunk_size* iterações. Cada parte é atribuído a um thread que está aguardando uma atribuição. O thread executa o fragmento de iterações e, em seguida, aguarda sua atribuição de Avançar, até que nenhum partes permaneçam para ser atribuído. Observe que a última parte a ser atribuído pode ter um número menor de iterações. Quando nenhum *chunk_size* for especificado, o padrão será 1.|
|interativa|Quando **agendamento (interativa,** *chunk_size* **)** for especificado, as iterações são atribuídas aos threads em partes com tamanhos de diminuir. Quando um thread termina seu bloco atribuído de iterações, ela é atribuída dinamicamente outro bloco, até que nenhum permanecem. Para um *chunk_size* de 1, o tamanho de cada parte é aproximadamente igual ao número de iterações não atribuídos, dividido pelo número de threads. Esses tamanhos de aproximadamente diminuem exponencialmente como 1. Para um *chunk_size* com o valor *k* maior que 1, os tamanhos de aproximadamente diminuir exponencialmente à *k*, exceto que a última parte pode ter menos de  *k* iterações. Quando nenhum *chunk_size* for especificado, o padrão será 1.|
|tempo de execução|Quando **Schedule (Runtime)** for especificado, a decisão sobre agendamento é adiada até o tempo de execução. A agenda *tipo* e o tamanho das partes pode ser escolhido no tempo de execução, definindo a variável de ambiente **OMP_SCHEDULE**. Se essa variável de ambiente não for definido, o agendamento resultante é definido pela implementação. Quando **Schedule (Runtime)** for especificado, *chunk_size* não deve ser especificado.|

Na ausência de explicitamente definidas **agendamento** cláusula, o padrão **agenda** é definido pela implementação.

Um programa de conformidade de OpenMP não deve confiar em um agendamento específico para execução correta. Um programa não deve confiar em um agendamento *tipo* em conformidade com precisão a descrição fornecida acima, porque é possível ter variações nas implementações do mesmo agendamento *tipo* entre compiladores diferentes. As descrições de podem ser usadas para selecionar a agenda que é apropriada para uma determinada situação.

O **ordenados** cláusula deve estar presente quando **ordenados** diretivas ligar para o **para** construir.

Há uma barreira implícita no final de uma **para** construir, a menos que um **nowait** cláusula for especificada.

Restrições para o **para** diretiva são da seguinte maneira:

- O **para** loop deve ser um bloco estruturado e, além disso, sua execução não deve ser terminada por um **quebra** instrução.

- Os valores do loop de expressões de controlam a **para** loop associado com um **para** diretiva deve ser o mesmo para todos os threads da equipe.

- O **para** variável de iteração do loop deve ter um tipo de inteiro com sinal.

- Um único **agendamento** cláusula pode aparecer em uma **para** diretiva.

- Um único **ordenados** cláusula pode aparecer em uma **para** diretiva.

- Um único **nowait** cláusula pode aparecer em uma **para** diretiva.

- É se não especificado ou a frequência com que os efeitos de qualquer lado dentro de *chunk_size*, *lb*, *b*, ou *incr* expressões ocorrem.

- O valor de *chunk_size* expressão deve ser o mesmo para todos os threads da equipe.

## <a name="cross-references"></a>Entre as referências:

- **privado**, **firstprivate**, **lastprivate**, e **redução** cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.

- **OMP_SCHEDULE** consulte de variável de ambiente [seção 4.1](../../parallel/openmp/4-1-omp-schedule.md) na página 48.

- **ordenado** construir, consulte [seção 2.6.6](../../parallel/openmp/2-6-6-ordered-construct.md) na página 22.

- [Apêndice D](../../parallel/openmp/d-using-the-schedule-clause.md), página 93, fornece mais informações sobre como usar a cláusula de agendamento.