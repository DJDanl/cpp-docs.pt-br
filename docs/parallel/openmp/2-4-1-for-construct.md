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
ms.openlocfilehash: d5165c21f0bf6f2b9757550208d5e8e26a2bd3b1
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33693543"
---
# <a name="241-for-construct"></a>2.4.1 Constructo for
O **para** diretiva identifica uma construção de compartilhamento de trabalho iterativa que especifica que as iterações do loop associado serão executadas em paralelo. As iterações do **para** loop são distribuídas entre os threads que já existem na equipe executando a construção paralela à qual ela está associada. A sintaxe do **para** construção é o seguinte:  
  
```  
#pragma omp for [clause[[,] clause] ... ] new-linefor-loop  
```  
  
 A cláusula é um dos seguintes:  
  
 **private(** *variable-list* **)**  
  
 **firstprivate(** *variable-list* **)**  
  
 **lastprivate(** *variable-list* **)**  
  
 **redução (** *operador* **:** *variável-lista *)**  
  
 **ordenados**  
  
 **agenda (** *tipo*[, *chunk_size*]**)**  
  
 **nowait**  
  
 O **para** diretiva impõe restrições na estrutura do **para** loop. Especificamente, o correspondente **para** loop deve ter a forma canônica:  
  
 **para (** *expr init* **;** *var operações lógicas b*; *incr-expr *)**  
  
 *Init-expr*  
 Um dos seguintes:  
  
 *var* = *lb*  
  
 *tipo de inteiro var* = *lb*  
  
 *expr incrementais*  
 Um dos seguintes:  
  
 ++*Var*  
  
 *var* ++  
  
 -- *Var*  
  
 *var* --  
  
 *var* += *incr*  
  
 *var* -= *incr*  
  
 *var* = *var* + *incr*  
  
 *var* = *incr* + *var*  
  
 *var* = *var* - *incr*  
  
 *var*  
 Uma variável de inteiro com sinal. Se essa variável deve ser compartilhada, seja implicitamente tornado privado durante o **para**.   Essa variável não deve ser modificada dentro do corpo do **para** instrução. A menos que a variável for especificada **lastprivate**, seu valor depois que o loop é indeterminado.  
  
 *operações lógicas*  
 Um dos seguintes:  
  
 <  
  
 \<=  
  
 >  
  
 \>=  
  
 *balanceamento de carga*, *b*, e *incr*  
 Expressões de constante de inteiro de loop. Não há nenhuma sincronização durante a avaliação dessas expressões. Assim, efeitos colaterais avaliados produzir resultados indeterminados.  
  
 Observe que a forma canônica permite que o número de iterações de loop deve ser calculada na entrada para o loop. Esse cálculo é executado com valores no tipo de *var*, depois de promoções integrais. Em particular, se o valor de *b* - *lb* + *incr* não pode ser representado em que o tipo, o resultado é indeterminado. Além disso, se *operações lógicas* é < ou \<=, em seguida, *incr expr* devem causar *var* aumentar em cada iteração do loop.   Se *operações lógicas* é > ou > =, em seguida, *incr expr* devem causar *var* diminuir em cada iteração do loop.  
  
 O **agenda** cláusula Especifica como iterações do **para** loop são divididos entre threads da equipe. A correção de um programa não deve depender de segmento que executa uma iteração específica. O valor de *chunk_size*, se especificado, deve ser uma expressão de inteiro invariável de loop com um valor positivo. Não há nenhuma sincronização durante a avaliação desta expressão. Assim, efeitos colaterais avaliados produzir resultados indeterminados. A agenda *tipo* pode ser um dos seguintes:  
  
 Tabela 2-1 **agenda** cláusula *tipo* valores  
  
|||  
|-|-|  
|static|Quando **agenda (estático,** *chunk_size *)** for especificado, iterações são divididas em partes de um tamanho especificado por *chunk_size*. As partes são atribuídas estaticamente a threads da equipe em um modo round robin na ordem o número de threads. Quando nenhum *chunk_size* for especificado, o espaço de iteração é dividido em partes que são aproximadamente iguais em tamanho, com uma parte atribuída a cada thread.|  
|dinâmica|Quando **agenda (dinâmico,** *chunk_size *)** for especificado, as iterações são divididas em uma série de blocos, cada uma contendo *chunk_size* iterações. Cada bloco é atribuído a um thread que está esperando por uma atribuição. O thread executa o bloco de iterações e, em seguida, aguarda sua atribuição de Avançar, até que nenhum partes permanecem para serem atribuídos. Observe que a última parte a ser atribuído pode ter um número menor de iterações. Quando nenhum *chunk_size* for especificado, o padrão é 1.|  
|interativa|Quando **agenda (interativa,** *chunk_size *)** for especificado, as iterações são atribuídas a threads em partes com tamanhos de redução. Quando um thread conclui sua parte atribuído de iterações, ela é atribuída dinamicamente outra parte, até nenhuma permanece. Para uma *chunk_size* de 1, o tamanho de cada bloco é aproximadamente o número de iterações não atribuídos, dividido pelo número de threads. Esses tamanhos aproximadamente diminuem exponencialmente como 1. Para uma *chunk_size* com valor *k* maior que 1, os tamanhos de aproximadamente diminui exponencialmente a *k*, exceto que o último bloco pode ter menos de  *k* iterações. Quando nenhum *chunk_size* for especificado, o padrão é 1.|  
|tempo de execução|Quando **Schedule (Runtime)** for especificado, a decisão sobre planejamento é adiada até o tempo de execução. A agenda *tipo* e tamanho das partes pode ser escolhido em tempo de execução, definindo a variável de ambiente **OMP_SCHEDULE**. Se essa variável de ambiente não for definida, a agenda resultante é definido pela implementação. Quando **Schedule (Runtime)** for especificado, *chunk_size* não deve ser especificado.|  
  
 Na ausência de um definido explicitamente **agenda** cláusula, o padrão **agenda** é definido pela implementação.  
  
 Um programa OpenMP compatível não deve depender de uma agenda específica de execução correta. Um programa não deve confiar em um agendamento *tipo* em conformidade com precisão para a descrição fornecida acima, porque é possível ter variações em implementações de mesma agenda *tipo* em compiladores diferentes. As descrições de podem ser usadas para selecionar o agendamento apropriado para uma situação específica.  
  
 O **ordenados** cláusula deve estar presente quando **ordenados** diretivas de associar o **para** construir.  
  
 Há uma barreira implícita ao final de um **para** construir, a menos que um **nowait** cláusula for especificada.  
  
 Restrições para o **para** diretiva são da seguinte maneira:  
  
-   O **para** loop deve ser um bloco estruturado, e, além disso, sua execução não deve ser terminada por um **quebra** instrução.  
  
-   Os valores do loop controlam expressões do **para** loop associado com um **para** diretiva deve ser o mesmo para todos os threads na equipe.  
  
-   O **para** variável de iteração de loop deve ter um tipo inteiro com sinal.  
  
-   Um único **agenda** cláusula pode aparecer em uma **para** diretiva.  
  
-   Um único **ordenados** cláusula pode aparecer em uma **para** diretiva.  
  
-   Um único **nowait** cláusula pode aparecer em uma **para** diretiva.  
  
-   É se não especificado ou a frequência de efeitos de qualquer lado dentro de *chunk_size*, *lb*, *b*, ou *incr* ocorrem expressões.  
  
-   O valor de *chunk_size* expressão deve ser o mesmo para todos os threads na equipe.  
  
## <a name="cross-references"></a>Entre referências:  
  
-   **privada**, **firstprivate**, **lastprivate**, e **redução** cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.  
  
-   **OMP_SCHEDULE** consulte de variável de ambiente [seção 4.1](../../parallel/openmp/4-1-omp-schedule.md) na página 48.  
  
-   **ordenados** construir, consulte [seção 2.6.6](../../parallel/openmp/2-6-6-ordered-construct.md) na página 22.  
  
-   [Apêndice D](../../parallel/openmp/d-using-the-schedule-clause.md), página 93, fornece mais informações sobre como usar a cláusula de agenda.