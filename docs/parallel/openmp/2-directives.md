---
title: 2. Diretivas
ms.date: 01/18/2019
ms.assetid: d1a69374-6c03-45fb-8c86-e91cea8adae8
ms.openlocfilehash: 5b2649a65efd3368cf8a4d2649a424b1a539f1ef
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841968"
---
# <a name="2-directives"></a>2. Diretivas

As diretivas são baseadas em `#pragma` diretivas definidas nos padrões C e C++.  Os compiladores que dão suporte à API de OpenMP C e C++ incluirão uma opção de linha de comando que ativa e permite a interpretação de todas as diretivas de compilação de OpenMP.

## <a name="21-directive-format"></a>formato de diretiva 2,1

A sintaxe de uma diretiva de OpenMP é formalmente especificada pela gramática no [Apêndice C](c-openmp-c-and-cpp-grammar.md)e informalmente da seguinte maneira:

```cpp
#pragma omp directive-name  [clause[ [,] clause]...] new-line
```

Cada diretiva começa com  `#pragma omp` , para reduzir o potencial de conflito com outras diretivas de pragma (extensões não OpenMP ou de fornecedor para OpenMP) com os mesmos nomes. O restante da diretiva segue as convenções dos padrões C e C++ para diretivas de compilador. Em particular, o espaço em branco pode ser usado antes e depois do e `#` , às vezes, o espaço em branco deve ser usado para separar as palavras em uma diretiva. Os tokens de pré-processamento após o `#pragma omp` estão sujeitos à substituição de macro.

As diretivas diferenciam maiúsculas de minúsculas. A ordem na qual as cláusulas aparecem nas diretivas não é significativa. As cláusulas nas diretivas podem ser repetidas conforme necessário, sujeitas às restrições listadas na descrição de cada cláusula. Se *a lista de variáveis* for exibida em uma cláusula, ela deverá especificar apenas variáveis. Somente um *nome de diretiva* pode ser especificado por diretiva.  Por exemplo, a diretiva a seguir não é permitida:

```cpp
/* ERROR - multiple directive names not allowed */
#pragma omp parallel barrier
```

Uma diretiva de OpenMP aplica-se a, no máximo, uma instrução com sucesso, que deve ser um bloco estruturado.

## <a name="22-conditional-compilation"></a>compilação condicional 2,2

O `_OPENMP` nome da macro é definido por implementações compatíveis com OpenMP como a constante *yyyymm*decimal, que será o ano e o mês da especificação aprovada. Essa macro não deve ser o assunto de uma `#define` diretiva do ou de `#undef` pré-processamento.

```cpp
#ifdef _OPENMP
iam = omp_get_thread_num() + index;
#endif
```

Se os fornecedores definirem extensões para OpenMP, eles poderão especificar macros predefinidas adicionais.

## <a name="23-parallel-construct"></a>construção paralela 2,3

A diretiva a seguir define uma região paralela, que é uma região do programa que deve ser executada por vários threads em paralelo. Essa diretiva é a construção fundamental que inicia a execução paralela.

```cpp
#pragma omp parallel [clause[ [, ]clause] ...] new-line   structured-block
```

A *cláusula* é uma das seguintes:

- `if(`*expressão escalar*`)`
- `private(`*lista de variáveis*`)`
- `firstprivate(`*lista de variáveis*`)`
- `default(shared | none)`
- `shared(`*lista de variáveis*`)`
- `copyin(`*lista de variáveis*`)`
- `reduction(`*operador* `:` *lista de variáveis*  `)`
- `num_threads(`*expressão de número inteiro*`)`

Quando um thread chegar a uma construção paralela, uma equipe de threads será criada se um dos seguintes casos for verdadeiro:

- Nenhuma `if` cláusula está presente.
- A `if` expressão é avaliada como um valor diferente de zero.

Esse thread se torna o thread mestre da equipe, com um número de thread 0 e todos os threads da equipe, incluindo o thread mestre, executa a região em paralelo. Se o valor da `if` expressão for zero, a região será serializada.

Para determinar o número de threads solicitados, as regras a seguir serão consideradas na ordem. A primeira regra cuja condição é atendida será aplicada:

1. Se a `num_threads` cláusula estiver presente, o valor da expressão de inteiro será o número de threads solicitados.

1. Se a `omp_set_num_threads` função de biblioteca tiver sido chamada, o valor do argumento na chamada executada mais recentemente será o número de threads solicitados.

1. Se a variável de ambiente `OMP_NUM_THREADS` for definida, o valor dessa variável de ambiente será o número de threads solicitados.

1. Se nenhum dos métodos acima for usado, o número de threads solicitados será definido pela implementação.

Se a `num_threads` cláusula estiver presente, ela substituirá o número de threads solicitados pela `omp_set_num_threads` função de biblioteca ou a `OMP_NUM_THREADS` variável de ambiente somente para a região paralela à qual ele é aplicado. As regiões paralelas posteriores não são afetadas por ela.

O número de threads que executam a região paralela também depende de se o ajuste dinâmico do número de threads está habilitado. Se o ajuste dinâmico estiver desabilitado, o número solicitado de threads executará a região paralela. Se o ajuste dinâmico estiver habilitado, o número solicitado de threads será o número máximo de threads que podem executar a região paralela.

Se uma região paralela for encontrada enquanto o ajuste dinâmico do número de threads estiver desabilitado e o número de threads solicitados para a região paralela for maior que o número que o sistema de tempo de execução pode fornecer, o comportamento do programa será definido pela implementação. Uma implementação pode, por exemplo, interromper a execução do programa ou pode serializar a região paralela.

A `omp_set_dynamic` função de biblioteca e a `OMP_DYNAMIC` variável de ambiente podem ser usadas para habilitar e desabilitar o ajuste dinâmico do número de threads.

O número de processadores físicos que hospedam os threads em um determinado momento é definido pela implementação. Depois de criada, o número de threads na equipe permanece constante durante a região paralela. Ele pode ser alterado explicitamente pelo usuário ou automaticamente pelo sistema de tempo de execução de uma região paralela para outra.

As instruções contidas na extensão dinâmica da região paralela são executadas por cada thread, e cada thread pode executar um caminho de instruções que é diferente dos outros threads. As diretivas encontradas fora da extensão lexical de uma região paralela são chamadas de diretivas órfãs.

Há uma barreira implícita no final de uma região paralela. Somente o thread mestre da equipe continua a execução no final de uma região paralela.

Se um thread em uma equipe que executa uma região paralela encontrar outra construção paralela, ele criará uma nova equipe e se tornará o mestre dessa nova equipe. Regiões paralelas aninhadas são serializadas por padrão. Como resultado, por padrão, uma região paralela aninhada é executada por uma equipe composta de um thread. O comportamento padrão pode ser alterado usando a função de biblioteca de tempo de execução `omp_set_nested` ou a variável de ambiente `OMP_NESTED` . No entanto, o número de threads em uma equipe que executa uma região paralela aninhada é definido pela implementação.

As restrições à `parallel` diretiva são as seguintes:

- No máximo, uma `if` cláusula pode aparecer na diretiva.

- Não é especificado se qualquer efeito colateral dentro da expressão If ou da `num_threads` expressão ocorrer.

- Um `throw` executado dentro de uma região paralela deve fazer com que a execução continue dentro da extensão dinâmica do mesmo bloco estruturado e deve ser detectada pelo mesmo thread que gerou a exceção.

- Apenas uma única `num_threads` cláusula pode aparecer na diretiva. A `num_threads` expressão é avaliada fora do contexto da região paralela e deve ser avaliada como um valor inteiro positivo.

- A ordem de avaliação das `if` `num_threads` cláusulas e não está especificada.

### <a name="cross-references"></a>Referências cruzadas

- `private`cláusulas,,,, `firstprivate` `default` `shared` `copyin` e `reduction` ([seção 2.7.2](#272-data-sharing-attribute-clauses))
- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads) variável de ambiente
- [omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function) função de biblioteca
- [OMP_DYNAMIC](4-environment-variables.md#43-omp_dynamic) variável de ambiente
- função [omp_set_nested](3-run-time-library-functions.md#319-omp_set_nested-function)
- [OMP_NESTED](4-environment-variables.md#44-omp_nested) variável de ambiente
- [omp_set_num_threads](3-run-time-library-functions.md#311-omp_set_num_threads-function) função de biblioteca

## <a name="24-work-sharing-constructs"></a>2,4 constructos de compartilhamento de trabalho

Um constructo de compartilhamento de trabalho distribui a execução da instrução associada entre os membros da equipe que o encontram. As diretivas de compartilhamento de trabalho não iniciam novos threads e não há nenhuma barreira implícita na entrada para um constructo de compartilhamento de trabalho.

A sequência de construções e diretivas de compartilhamento de trabalho `barrier` encontradas deve ser a mesma para cada thread em uma equipe.

O OpenMP define as seguintes construções de compartilhamento de trabalho, e essas construções são descritas nas seções a seguir:

- diretiva [for](#241-for-construct)
- diretiva [Sections](#242-sections-construct)
- diretiva [única](#243-single-construct)

### <a name="241-for-construct"></a>2.4.1 para construção

A `for` diretiva identifica um constructo de compartilhamento de trabalho iterativo que especifica que as iterações do loop associado serão executadas em paralelo. As iterações do `for` loop são distribuídas entre threads que já existem na equipe que executa a construção paralela à qual ele se associa. A sintaxe da `for` construção é a seguinte:

```cpp
#pragma omp for [clause[[,] clause] ... ] new-line for-loop
```

A cláusula é uma das seguintes:

- `private(`*lista de variáveis*`)`
- `firstprivate(`*lista de variáveis*`)`
- `lastprivate(`*lista de variáveis*`)`
- `reduction(`*operador* `:` *lista de variáveis*`)`
- `ordered`
- `schedule(`*tipo* [ `,` *chunk_size*]`)`
- `nowait`

A `for` diretiva impõe restrições na estrutura do `for` loop correspondente. Especificamente, o `for` loop correspondente deve ter uma forma canônica:

`for (`*expressão* `;` de inicialização *var Logical-op b* `;` *incr-expr*`)`

*expressão de inicialização*<br/>
Um dos seguintes:

- *var*  =  *lb*
- var de tipo *de inteiro*  =  *lb*

*INCR-expr*<br/>
Um dos seguintes:

- `++`*var*
- *var*`++`
- `--`*var*
- *var*`--`
- *var* `+=` *incr*
- *var* `-=` *incr*
- *var* `=` *var* `+` *incr*
- *var* `=` *incr* `+` *var*
- *var* `=` *var* `-` *incr*

*var*<br/>
Uma variável de inteiro assinada. Se essa variável for compartilhada de outra forma, ela será implicitamente criada pela duração do `for` . Não modifique essa variável no corpo da `for` instrução. A menos que a variável seja especificada `lastprivate` , seu valor após o loop é indeterminado.

*operação lógica*<br/>
Um dos seguintes:

- `<`
- `<=`
- `>`
- `>=`

*lb*, *b*e *incr*<br>
Expressões de inteiro invariável de loop. Não há sincronização durante a avaliação dessas expressões, portanto, quaisquer efeitos colaterais avaliados produzem resultados indeterminados.

O formulário canônico permite que o número de iterações de loop seja computado na entrada para o loop. Esse cálculo é feito com valores no tipo de *var*, após as promoções integrais. Em particular, se o valor de *b* `-` *lb* `+` *incr* não puder ser representado nesse tipo, o resultado será indeterminado. Além disso, se a *operação lógica* for `<` ou `<=` , então *incr* deverá fazer com que *var* aumente em cada iteração do loop.   Se *a operação lógica* for `>` ou `>=` , então *incr* deverá fazer com que *var* seja menor em cada iteração do loop.

A `schedule` cláusula especifica como as iterações do `for` loop são divididas entre threads da equipe. A exatidão de um programa não deve depender de qual thread executa uma iteração específica. O valor de *chunk_size*, se especificado, deve ser uma expressão de inteiro invariável de loop com um valor positivo. Não há sincronização durante a avaliação desta expressão, portanto, quaisquer efeitos colaterais avaliados produzem resultados indeterminados. O *tipo* de agenda pode ser um dos seguintes valores:

Tabela 2-1: `schedule` valores de *tipo* de cláusula

|Valor|Descrição|
|-|-|
|static|Quando `schedule(static,` *chunk_size* `)` é especificado, as iterações são divididas em partes de um tamanho especificado por *chunk_size*. As partes são atribuídas estaticamente a threads na equipe em um modo Round Robin na ordem do número do thread. Quando nenhum *chunk_size* é especificado, o espaço de iteração é dividido em partes que são aproximadamente iguais em tamanho, com uma parte atribuída a cada thread.|
|dinâmico|Quando `schedule(dynamic,` *chunk_size* `)` é especificado, as iterações são divididas em uma série de partes, cada uma contendo *chunk_size* iterações. Cada parte é atribuída a um thread que está aguardando uma atribuição. O thread executa o bloco de iterações e aguarda sua próxima atribuição, até que nenhuma parte permaneça atribuída. A última parte a ser atribuída pode ter um número menor de iterações. Quando nenhum *chunk_size* é especificado, o padrão é 1.|
|conduzi|Quando `schedule(guided,` *chunk_size* `)` é especificado, as iterações são atribuídas a threads em partes com tamanhos decrescentes. Quando um thread conclui sua parte atribuída de iterações, ele é atribuído dinamicamente a outra parte, até que None seja deixado. Para um *chunk_size* de 1, o tamanho de cada parte é aproximadamente o número de iterações não atribuídas dividida pelo número de threads. Esses tamanhos diminuem de maneira quase exponencial para 1. Para um *chunk_size* com valor *k* maior que 1, os tamanhos diminuem quase exponencialmente para *k*, exceto que a última parte pode ter menos de *k* iterações. Quando nenhum *chunk_size* é especificado, o padrão é 1.|
|runtime|Quando `schedule(runtime)` é especificado, a decisão sobre o agendamento é adiada até o tempo de execução. O *tipo* e o tamanho da agenda das partes podem ser escolhidos em tempo de execução, definindo a variável de ambiente `OMP_SCHEDULE` . Se essa variável de ambiente não estiver definida, a agenda resultante será definida como implementação. Quando  `schedule(runtime)` é especificado, *chunk_size* não deve ser especificado.|

Na ausência de uma cláusula definida explicitamente `schedule` , o padrão `schedule` é definido pela implementação.

Um programa compatível com OpenMP não deve depender de um cronograma específico para a execução correta. Um programa não deve depender de um *tipo* de agenda em conformidade com precisão à descrição fornecida acima, porque é possível ter variações nas implementações do mesmo *tipo* de agenda em diferentes compiladores. As descrições podem ser usadas para selecionar o agendamento apropriado para uma situação específica.

A `ordered` cláusula deve estar presente quando `ordered` as diretivas se vincularem à `for` construção.

Há uma barreira implícita no final de uma `for` construção, a menos que uma `nowait` cláusula seja especificada.

As restrições à `for` diretiva são as seguintes:

- O `for` loop deve ser um bloco estruturado e, além disso, sua execução não deve ser encerrada por uma **`break`** instrução.

- Os valores das expressões de controle de loop do `for` loop associado a uma `for` diretiva devem ser os mesmos para todos os threads da equipe.

- A `for` variável de iteração de loop deve ter um tipo de inteiro assinado.

- Apenas uma única `schedule` cláusula pode aparecer em uma `for` diretiva.

- Apenas uma única `ordered` cláusula pode aparecer em uma `for` diretiva.

- Apenas uma única `nowait` cláusula pode aparecer em uma `for` diretiva.

- Não será especificado se ou com que frequência quaisquer efeitos colaterais dentro das expressões *chunk_size*, *lb*, *b*ou *incr* ocorrerem.

- O valor da expressão de *chunk_size* deve ser o mesmo para todos os threads na equipe.

#### <a name="cross-references"></a>Referências cruzadas

- `private``firstprivate` `lastprivate` cláusulas,, e `reduction` ([seção 2.7.2](#272-data-sharing-attribute-clauses))
- [OMP_SCHEDULE](4-environment-variables.md#41-omp_schedule) variável de ambiente
- construção [ordenada](#266-ordered-construct)
- cláusula de [agendamento](d-using-the-schedule-clause.md)

### <a name="242-sections-construct"></a>construção de seções 2.4.2

A `sections` diretiva identifica um constructo de compartilhamento de trabalho não iterativo que especifica um conjunto de construções que devem ser divididas entre threads em uma equipe. Cada seção é executada uma vez por um thread na equipe. A sintaxe da `sections` diretiva é a seguinte:

```cpp
#pragma omp sections [clause[[,] clause] ...] new-line
   {
   [#pragma omp section new-line]
      structured-block
   [#pragma omp section new-linestructured-block ]
...
}
```

A cláusula é uma das seguintes:

- `private(`*lista de variáveis*`)`
- `firstprivate(`*lista de variáveis*`)`
- `lastprivate(`*lista de variáveis*`)`
- `reduction(`*operador* `:` *lista de variáveis*  `)`
- `nowait`

Cada seção é precedida por uma `section` diretiva, embora a `section` diretiva seja opcional para a primeira seção. As `section` diretivas devem aparecer dentro da extensão lexical da `sections` diretiva. Há uma barreira implícita no final de um `sections` constructo, a menos que um `nowait` seja especificado.

As restrições à `sections` diretiva são as seguintes:

- Uma `section` diretiva não deve aparecer fora da extensão lexical da `sections` diretiva.

- Apenas uma única `nowait` cláusula pode aparecer em uma `sections` diretiva.

#### <a name="cross-references"></a>Referências cruzadas

- `private``firstprivate` `lastprivate` cláusulas,, e `reduction` ([seção 2.7.2](#272-data-sharing-attribute-clauses))

### <a name="243-single-construct"></a>2.4.3 construção única

A `single` diretiva identifica uma construção que especifica que o bloco estruturado associado é executado por apenas um thread na equipe (não necessariamente o thread mestre). A sintaxe da `single` diretiva é a seguinte:

```cpp
#pragma omp single [clause[[,] clause] ...] new-linestructured-block
```

A cláusula é uma das seguintes:

- `private(`*lista de variáveis*`)`
- `firstprivate(`*lista de variáveis*`)`
- `copyprivate(`*lista de variáveis*`)`
- `nowait`

Há uma barreira implícita após a `single` construção, a menos que uma `nowait` cláusula seja especificada.

As restrições à `single` diretiva são as seguintes:

- Apenas uma única `nowait` cláusula pode aparecer em uma `single` diretiva.
- A `copyprivate` cláusula não deve ser usada com a `nowait` cláusula.

#### <a name="cross-references"></a>Referências cruzadas

- `private``firstprivate` `copyprivate` cláusulas and ([seção 2.7.2](#272-data-sharing-attribute-clauses))

## <a name="25-combined-parallel-work-sharing-constructs"></a>2,5 constructos de compartilhamento de trabalho paralelo combinado

As construções de compartilhamento de trabalho paralela combinadas são atalhos para especificar uma região paralela que tenha apenas uma construção de compartilhamento de trabalho. A semântica dessas diretivas é a mesma de especificar explicitamente uma `parallel` diretiva seguida de um único constructo de compartilhamento de trabalho.

As seções a seguir descrevem as construções de compartilhamento de trabalho paralelos combinadas:

- [paralelo para](#251-parallel-for-construct) diretiva
- Diretiva de [seções paralelas](#252-parallel-sections-construct)

### <a name="251-parallel-for-construct"></a>2.5.1 paralelo para construção

A `parallel for` diretiva é um atalho para uma `parallel` região que contém apenas uma única `for` diretiva. A sintaxe da `parallel for` diretiva é a seguinte:

```cpp
#pragma omp parallel for [clause[[,] clause] ...] new-linefor-loop
```

Essa diretiva permite todas as cláusulas da `parallel` diretiva e da `for` diretiva, exceto a `nowait` cláusula, com significações e restrições idênticas. A semântica é a mesma que especificar explicitamente uma `parallel` diretiva imediatamente seguida por uma `for` diretiva.

#### <a name="cross-references"></a>Referências cruzadas

- diretiva [Parallel](#23-parallel-construct)
- diretiva [for](#241-for-construct)
- [Cláusulas de atributo de dados](#272-data-sharing-attribute-clauses)

### <a name="252-parallel-sections-construct"></a>construção de seções paralelas 2.5.2

A `parallel sections` diretiva fornece um formulário de atalho para especificar uma `parallel` região que tenha apenas uma única `sections` diretiva. A semântica é a mesma que especificar explicitamente uma `parallel` diretiva imediatamente seguida por uma `sections` diretiva. A sintaxe da `parallel sections` diretiva é a seguinte:

```cpp
#pragma omp parallel sections  [clause[[,] clause] ...] new-line
   {
   [#pragma omp section new-line]
      structured-block
   [#pragma omp section new-linestructured-block  ]
   ...
}
```

A *cláusula* pode ser uma das cláusulas aceitas pelas `parallel` diretivas e `sections` , exceto a `nowait` cláusula.

#### <a name="cross-references"></a>Referências cruzadas

- diretiva [Parallel](#23-parallel-construct)
- diretiva [Sections](#242-sections-construct)

## <a name="26-master-and-synchronization-directives"></a>diretivas mestre e de sincronização 2,6

As seções a seguir descrevem:

- construção [mestre](#261-master-construct)
- construção [crítica](#262-critical-construct)
- Diretiva de [barreira](#263-barrier-directive)
- construção [atômica](#264-atomic-construct)
- diretiva [flush](#265-flush-directive)
- construção [ordenada](#266-ordered-construct)

### <a name="261-master-construct"></a>construção mestre 2.6.1

A `master` diretiva identifica uma construção que especifica um bloco estruturado que é executado pelo thread mestre da equipe. A sintaxe da `master` diretiva é a seguinte:

```cpp
#pragma omp master new-linestructured-block
```

Outros threads na equipe não executam o bloco estruturado associado. Não há uma barreira implícita na entrada ou saída da construção mestre.

### <a name="262-critical-construct"></a>construção crítica 2.6.2

A `critical` diretiva identifica uma construção que restringe a execução do bloco estruturado associado a um único thread de cada vez. A sintaxe da `critical` diretiva é a seguinte:

```cpp
#pragma omp critical [(name)]  new-linestructured-block
```

Um *nome* opcional pode ser usado para identificar a região crítica. Os identificadores usados para identificar uma região crítica têm vínculo externo e estão em um espaço de nome separado dos espaços de nome usados por rótulos, marcas, membros e identificadores comuns.

Um thread aguarda no início de uma região crítica até que nenhum outro thread esteja executando uma região crítica (em qualquer lugar do programa) com o mesmo nome. Todas as diretivas sem nome são `critical` mapeadas para o mesmo nome não especificado.

### <a name="263-barrier-directive"></a>Diretiva de barreira 2.6.3

A `barrier` diretiva sincroniza todos os threads em uma equipe. Quando encontrado, cada thread da equipe aguarda até que todos os outros cheguem a esse ponto. A sintaxe da `barrier` diretiva é a seguinte:

```cpp
#pragma omp barrier new-line
```

Depois que todos os threads da equipe tiverem encontrado a barreira, cada thread na equipe começará a executar as instruções depois da diretiva de barreira em paralelo. Como a `barrier` diretiva não tem uma instrução de linguagem C como parte de sua sintaxe, há algumas restrições em seu posicionamento dentro de um programa. Para obter mais informações sobre a gramática formal, consulte o [Apêndice C](c-openmp-c-and-cpp-grammar.md). O exemplo a seguir ilustra essas restrições.

```cpp
/* ERROR - The barrier directive cannot be the immediate
*          substatement of an if statement
*/
if (x!=0)
   #pragma omp barrier
...

/* OK - The barrier directive is enclosed in a
*      compound statement.
*/
if (x!=0) {
   #pragma omp barrier
}
```

### <a name="264-atomic-construct"></a>construção atômica 2.6.4

A `atomic` diretiva garante que um local de memória específico seja atualizado atomicamente, em vez de expô-lo à possibilidade de vários threads de gravação simultâneas. A sintaxe da `atomic` diretiva é a seguinte:

```cpp
#pragma omp atomic new-lineexpression-stmt
```

A instrução de expressão deve ter um dos seguintes formatos:

- *x binop* `=` *expr*
- *x*`++`
- `++` *x*
- *x*`--`
- `--` *x*

Nas expressões anteriores:

- *x* é uma expressão lvalue com tipo escalar.

- *expr* é uma expressão com tipo escalar e não faz referência ao objeto designado por *x*.

- *binop* não é um operador sobrecarregado e é um de `+` , `*` , `-` , `/` ,,, `&` `^` `|` , `<<` ou `>>` .

Embora seja definido em implementação se uma implementação substitui todas as `atomic` diretivas com `critical` diretivas que têm o mesmo *nome*exclusivo, a `atomic` diretiva permite melhor otimização. Muitas vezes, há instruções de hardware disponíveis que podem executar a atualização atômica com a menor sobrecarga.

Somente a carga e o repositório do objeto designado por *x* são atômicos; a avaliação de *expr* não é atômica. Para evitar condições de corrida, todas as atualizações do local em paralelo devem ser protegidas com a `atomic` diretiva, exceto aquelas que são conhecidas por serem gratuitas das condições de corrida.

As restrições à `atomic` diretiva são as seguintes:

- Todas as referências atômicas para o local de armazenamento x em todo o programa precisam ter um tipo compatível.

#### <a name="examples"></a>Exemplos

```cpp
extern float a[], *p = a, b;
/* Protect against races among multiple updates. */
#pragma omp atomic
a[index[i]] += b;
/* Protect against races with updates through a. */
#pragma omp atomic
p[i] -= 1.0f;

extern union {int n; float x;} u;
/* ERROR - References through incompatible types. */
#pragma omp atomic
u.n++;
#pragma omp atomic
u.x -= 1.0f;
```

### <a name="265-flush-directive"></a>Diretiva de liberação do 2.6.5

A `flush` diretiva, explícita ou implícita, especifica um ponto de sequência de "thread cruzado" no qual a implementação é necessária para garantir que todos os threads de uma equipe tenham uma exibição consistente de determinados objetos (especificados abaixo) na memória. Isso significa que as avaliações anteriores de expressões que fazem referência a esses objetos são concluídas e as avaliações subsequentes ainda não foram iniciadas. Por exemplo, os compiladores devem restaurar os valores dos objetos de registros para a memória e o hardware pode precisar liberar buffers de gravação para a memória e recarregar os valores dos objetos da memória.

A sintaxe da `flush` diretiva é a seguinte:

```cpp
#pragma omp flush [(variable-list)]  new-line
```

Se os objetos que exigem sincronização puderem ser designados por variáveis, essas variáveis poderão ser especificadas na *lista variável*opcional. Se um ponteiro estiver presente na *lista de variáveis*, o próprio ponteiro será liberado, não o objeto ao qual o ponteiro se refere.

Uma `flush` diretiva sem uma *lista de variáveis* sincroniza todos os objetos compartilhados, exceto objetos inacessíveis com duração de armazenamento automática. (É provável que isso tenha mais sobrecarga do que uma `flush` com uma *lista de variáveis*.) Uma `flush` diretiva sem uma *lista de variáveis* é implícita para as seguintes diretivas:

- `barrier`
- Na entrada e saída de `critical`
- Na entrada e saída de `ordered`
- Na entrada e saída de `parallel`
- Ao sair de `for`
- Ao sair de `sections`
- Ao sair de `single`
- Na entrada e saída de `parallel for`
- Na entrada e saída de `parallel sections`

A diretiva não estará implícita se uma `nowait` cláusula estiver presente. Deve-se observar que a `flush` diretiva não está implícita para qualquer um dos seguintes:

- Na entrada para `for`
- Na entrada ou saída de `master`
- Na entrada para `sections`
- Na entrada para `single`

Uma referência que acessa o valor de um objeto com um tipo qualificado como volátil se comporta como se houvesse uma `flush` diretiva especificando esse objeto no ponto de sequência anterior. Uma referência que modifica o valor de um objeto com um tipo qualificado como volátil se comporta como se houvesse uma `flush` diretiva especificando esse objeto no ponto de sequência subsequente.

Como a `flush` diretiva não tem uma instrução de linguagem C como parte de sua sintaxe, há algumas restrições em seu posicionamento dentro de um programa. Para obter mais informações sobre a gramática formal, consulte o [Apêndice C](c-openmp-c-and-cpp-grammar.md). O exemplo a seguir ilustra essas restrições.

```cpp
/* ERROR - The flush directive cannot be the immediate
*          substatement of an if statement.
*/
if (x!=0)
   #pragma omp flush (x)
...

/* OK - The flush directive is enclosed in a
*      compound statement
*/
if (x!=0) {
   #pragma omp flush (x)
}
```

As restrições à `flush` diretiva são as seguintes:

- Uma variável especificada em uma `flush` diretiva não deve ter um tipo de referência.

### <a name="266-ordered-construct"></a>construção ordenada 2.6.6

O bloco estruturado após uma `ordered` diretiva é executado na ordem em que as iterações seriam executadas em um loop sequencial. A sintaxe da `ordered` diretiva é a seguinte:

```cpp
#pragma omp ordered new-linestructured-block
```

Uma `ordered` diretiva deve estar dentro da extensão dinâmica de uma `for` `parallel for` construção ou. A `for` `parallel for` diretiva ou à qual a `ordered` construção é associada deve ter uma `ordered` cláusula especificada, conforme descrito na [seção 2.4.1](#241-for-construct). Na execução de uma `for` construção ou `parallel for` com uma `ordered` cláusula, as `ordered` construções são executadas estritamente na ordem em que seriam executadas em uma execução sequencial do loop.

As restrições à `ordered` diretiva são as seguintes:

- Uma iteração de um loop com uma `for` construção não deve executar a mesma diretiva ordenada mais de uma vez e não deve executar mais de uma `ordered` diretiva.

## <a name="27-data-environment"></a>ambiente de dados 2,7

Esta seção apresenta uma diretiva e várias cláusulas para controlar o ambiente de dados durante a execução de regiões paralelas, da seguinte maneira:

- Uma diretiva [threadprivate](#271-threadprivate-directive) é fornecida para tornar as variáveis de escopo de arquivo, Namespace-escopo ou estáticas de escopo de bloco locais para um thread.

- As cláusulas que podem ser especificadas nas diretivas para controlar os atributos de compartilhamento de variáveis para a duração das construções paralelas ou de compartilhamento de trabalho são descritas na [seção 2.7.2](#272-data-sharing-attribute-clauses).

### <a name="271-threadprivate-directive"></a>diretiva 2.7.1 threadprivate

A `threadprivate` diretiva torna as variáveis de escopo de arquivo, escopo de namespace ou de escopo de bloco estáticos especificadas na *lista de variáveis* privada para um thread. a *lista variável* é uma lista separada por vírgulas de variáveis que não têm um tipo incompleto. A sintaxe da `threadprivate` diretiva é a seguinte:

```cpp
#pragma omp threadprivate(variable-list) new-line
```

Cada cópia de uma `threadprivate` variável é inicializada uma vez, em um ponto não especificado no programa antes da primeira referência a essa cópia, e da maneira usual (ou seja, como a cópia mestra seria inicializada em uma execução serial do programa). Observe que, se um objeto for referenciado em um inicializador explícito de uma `threadprivate` variável e o valor do objeto for modificado antes da primeira referência a uma cópia da variável, o comportamento será não especificado.

Assim como ocorre com qualquer variável particular, um thread não deve fazer referência a uma cópia de outro thread de um `threadprivate` objeto. Durante as regiões de série e regiões mestras do programa, as referências serão a cópia do objeto mestre do thread.

Depois que a primeira região paralela for executada, os dados nos `threadprivate` objetos terão a garantia de persistir somente se o mecanismo de threads dinâmicos tiver sido desabilitado e se o número de threads permanecer inalterado para todas as regiões paralelas.

As restrições para a `threadprivate` diretiva são as seguintes:

- Uma `threadprivate` diretiva para variáveis de escopo de arquivo ou namespace deve aparecer fora de qualquer definição ou declaração e deve preceder lexicalmente todas as referências a qualquer uma das variáveis em sua lista.

- Cada variável na *lista de variáveis* de uma `threadprivate` diretiva no escopo de arquivo ou de namespace deve se referir a uma declaração de variável no escopo de arquivo ou de namespace que precede lexicalmente a diretiva.

- Uma `threadprivate` diretiva para variáveis de escopo de bloco estáticos deve aparecer no escopo da variável e não em um escopo aninhado. A diretiva deve preceder lexicalmente todas as referências a qualquer uma das variáveis em sua lista.

- Cada variável na *lista de variáveis* de uma `threadprivate` diretiva no escopo de bloco deve se referir a uma declaração de variável no mesmo escopo que precede lexicalmente a diretiva. A declaração de variável deve usar o especificador de classe de armazenamento estático.

- Se uma variável for especificada em uma `threadprivate` diretiva em uma unidade de tradução, ela deverá ser especificada em uma `threadprivate` diretiva em cada unidade de tradução em que seja declarada.

- Uma `threadprivate` variável não deve aparecer em nenhuma cláusula, exceto `copyin` ,,, `copyprivate` `schedule` `num_threads` ou a `if` cláusula.

- O endereço de uma `threadprivate` variável não é uma constante de endereço.

- Uma `threadprivate` variável não deve ter um tipo incompleto ou um tipo de referência.

- Uma `threadprivate` variável com tipo de classe não Pod deve ter um construtor de cópia acessível e não ambíguo se ela for declarada com um inicializador explícito.

O exemplo a seguir ilustra como a modificação de uma variável que aparece em um inicializador pode causar um comportamento não especificado e também como evitar esse problema usando um objeto auxiliar e um construtor de cópia.

```cpp
int x = 1;
T a(x);
const T b_aux(x); /* Capture value of x = 1 */
T b(b_aux);
#pragma omp threadprivate(a, b)

void f(int n) {
   x++;
   #pragma omp parallel for
   /* In each thread:
   * Object a is constructed from x (with value 1 or 2?)
   * Object b is copy-constructed from b_aux
   */
   for (int i=0; i<n; i++) {
      g(a, b); /* Value of a is unspecified. */
   }
}
```

#### <a name="cross-references"></a>Referências cruzadas

- [threads dinâmicos](3-run-time-library-functions.md#317-omp_set_dynamic-function)
- [OMP_DYNAMIC](4-environment-variables.md#43-omp_dynamic) variável de ambiente

### <a name="272-data-sharing-attribute-clauses"></a>cláusulas de atributo de compartilhamento de dados 2.7.2

Várias diretivas aceitam cláusulas que permitem que um usuário controle os atributos de compartilhamento de variáveis para a duração da região. As cláusulas de atributo de compartilhamento se aplicam somente a variáveis na extensão lexical da diretiva na qual a cláusula é exibida. Nem todas as cláusulas a seguir são permitidas em todas as diretivas. A lista de cláusulas que são válidas em uma determinada diretiva são descritas com a diretiva.

Se uma variável estiver visível quando um constructo paralelo ou de compartilhamento de trabalho for encontrado e a variável não for especificada em uma cláusula ou diretiva de atributo de compartilhamento `threadprivate` , a variável será compartilhada. Variáveis estáticas declaradas na extensão dinâmica de uma região paralela são compartilhadas. A memória alocada para heap (por exemplo, usando `malloc()` em C ou C++ ou o **`new`** operador em c++) é compartilhada. (No entanto, o ponteiro para essa memória pode ser privado ou compartilhado.) Variáveis com duração de armazenamento automática declaradas dentro da extensão dinâmica de uma região paralela são privadas.

A maioria das cláusulas aceita um argumento de *lista* de variáveis, que é uma lista separada por vírgulas de variáveis que são visíveis. Se uma variável referenciada em uma cláusula de atributo de compartilhamento de dados tiver um tipo derivado de um modelo e não houver nenhuma outra referência a essa variável no programa, o comportamento será indefinido.

Todas as variáveis que aparecem dentro de cláusulas de diretiva devem estar visíveis. As cláusulas podem ser repetidas conforme necessário, mas nenhuma variável pode ser especificada em mais de uma cláusula, exceto que uma variável pode ser especificada nas duas `firstprivate` `lastprivate` cláusulas e.

As seções a seguir descrevem as cláusulas de atributo de compartilhamento de dados:

- [pessoal](#2721-private)
- [firstprivate](#2722-firstprivate)
- [lastprivate](#2723-lastprivate)
- [compartilhado](#2724-shared)
- [default](#2725-default)
- [redução](#2726-reduction)
- [copyin](#2727-copyin)
- [copyprivate](#2728-copyprivate)

#### <a name="2721-private"></a>2.7.2.1 private

A `private` cláusula declara as variáveis na lista de variáveis para ser privada para cada thread em uma equipe. A sintaxe da `private` cláusula é a seguinte:

```cpp
private(variable-list)
```

O comportamento de uma variável especificada em uma `private` cláusula é o seguinte. Um novo objeto com duração de armazenamento automática é alocado para a construção. O tamanho e o alinhamento do novo objeto são determinados pelo tipo da variável. Essa alocação ocorre uma vez para cada thread na equipe, e um construtor padrão é invocado para um objeto de classe, se necessário; caso contrário, o valor inicial será indeterminado.  O objeto original referenciado pela variável tem um valor indeterminado na entrada para a construção, não deve ser modificado dentro da extensão dinâmica da construção e tem um valor indeterminado após a saída da construção.

Na extensão lexical do constructo de diretiva, a variável faz referência ao novo objeto privado alocado pelo thread.

As restrições à `private` cláusula são as seguintes:

- Uma variável com um tipo de classe que é especificada em uma `private` cláusula deve ter um construtor padrão acessível e não ambíguo.

- Uma variável especificada em uma `private` cláusula não deve ter um **`const`** tipo qualificado, a menos que tenha um tipo de classe com um `mutable` membro.

- Uma variável especificada em uma `private` cláusula não deve ter um tipo incompleto ou um tipo de referência.

- Variáveis que aparecem na `reduction` cláusula de uma `parallel` diretiva não podem ser especificadas em uma `private` cláusula em uma diretiva de compartilhamento de trabalho que se associa à construção paralela.

#### <a name="2722-firstprivate"></a>2.7.2.2 firstprivate

A `firstprivate` cláusula fornece um superconjunto da funcionalidade fornecida pela `private` cláusula. A sintaxe da `firstprivate` cláusula é a seguinte:

```cpp
firstprivate(variable-list)
```

As variáveis especificadas na *lista de variáveis* têm `private` semântica de cláusula, conforme descrito na [seção 2.7.2.1](#2721-private). A inicialização ou construção ocorre como se fosse feita uma vez por thread, antes da execução do thread da construção. Para uma `firstprivate` cláusula em uma construção paralela, o valor inicial do novo objeto particular é o valor do objeto original que existe imediatamente antes da construção paralela para o thread que o encontra. Para uma `firstprivate` cláusula em uma construção de compartilhamento de trabalho, o valor inicial do novo objeto particular para cada thread que executa a construção de compartilhamento de trabalho é o valor do objeto original que existe antes do momento em que o mesmo thread encontra o constructo de compartilhamento de trabalho. Além disso, para objetos C++, o novo objeto particular para cada thread é a cópia construída a partir do objeto original.

As restrições à `firstprivate` cláusula são as seguintes:

- Uma variável especificada em uma `firstprivate` cláusula não deve ter um tipo incompleto ou um tipo de referência.

- Uma variável com um tipo de classe que é especificado como `firstprivate` deve ter um construtor de cópia acessível e não ambíguo.

- Variáveis que são privadas em uma região paralela ou que aparecem na `reduction` cláusula de uma `parallel` diretiva não podem ser especificadas em uma `firstprivate` cláusula em uma diretiva de compartilhamento de trabalho que se associa à construção paralela.

#### <a name="2723-lastprivate"></a>2.7.2.3 lastprivate

A `lastprivate` cláusula fornece um superconjunto da funcionalidade fornecida pela `private` cláusula. A sintaxe da `lastprivate` cláusula é a seguinte:

```cpp
lastprivate(variable-list)
```

As variáveis especificadas na *lista de variáveis* têm `private` semânticas de cláusula. Quando uma `lastprivate` cláusula é exibida na diretiva que identifica uma construção de compartilhamento de trabalho, o valor de cada `lastprivate` variável da última iteração sequencial do loop associado ou a diretiva de seção lexicalmente última, é atribuído ao objeto original da variável. Variáveis que não são atribuídas a um valor pela última iteração do `for` ou `parallel for` , ou pela última seção da `sections` `parallel sections` diretiva ou, têm valores indeterminados após a construção. Subobjetos não atribuídos também têm um valor indeterminado após a construção.

As restrições à `lastprivate` cláusula são as seguintes:

- Todas as restrições para `private` aplicar.

- Uma variável com um tipo de classe que é especificado como `lastprivate` deve ter um operador de atribuição de cópia acessível e não ambíguo.

- Variáveis que são privadas em uma região paralela ou que aparecem na `reduction` cláusula de uma `parallel` diretiva não podem ser especificadas em uma `lastprivate` cláusula em uma diretiva de compartilhamento de trabalho que se associa à construção paralela.

#### <a name="2724-shared"></a>2.7.2.4 shared

Essa cláusula compartilha variáveis que aparecem na *lista de variáveis* entre todos os threads em uma equipe. Todos os threads em uma equipe acessam a mesma área de armazenamento para `shared` variáveis.

A sintaxe da `shared` cláusula é a seguinte:

```cpp
shared(variable-list)
```

#### <a name="2725-default"></a>2.7.2.5 default

A `default` cláusula permite que o usuário afete os atributos de compartilhamento de dados de variáveis. A sintaxe da `default` cláusula é a seguinte:

```cpp
default(shared | none)
```

Especificar `default(shared)` é equivalente a listar explicitamente cada variável visível no momento em uma `shared` cláusula, a menos que seja `threadprivate` ou **`const`** qualificado. Na ausência de uma cláusula explícita `default` , o comportamento padrão é o mesmo que se `default(shared)` fosse especificado.

Especificar `default(none)` requer que pelo menos um dos seguintes deve ser verdadeiro para cada referência a uma variável na extensão lexical da construção paralela:

- A variável é explicitamente listada em uma cláusula de atributo de compartilhamento de dados de um constructo que contém a referência.

- A variável é declarada dentro da construção paralela.

- A variável é `threadprivate` .

- A variável tem um **`const`** tipo qualificado.

- A variável é a variável de controle de loop para um `for` loop que segue imediatamente uma `for` `parallel for` diretiva ou, e a referência de variável aparece dentro do loop.

A especificação de uma variável em uma `firstprivate` `lastprivate` cláusula, ou `reduction` de uma diretiva inclusa causa uma referência implícita à variável no contexto delimitador. Essas referências implícitas também estão sujeitas aos requisitos listados acima.

Apenas uma única `default` cláusula pode ser especificada em uma `parallel` diretiva.

O atributo de compartilhamento de dados padrão de uma variável pode ser substituído usando `private` as `firstprivate` `lastprivate` cláusulas,,, `reduction` e `shared` , conforme demonstrado pelo exemplo a seguir:

```cpp
#pragma  omp  parallel  for  default(shared)  firstprivate(i)\
   private(x)  private(r)  lastprivate(i)
```

#### <a name="2726-reduction"></a>2.7.2.6 reduction

Essa cláusula executa uma redução nas variáveis escalares que aparecem na *lista de variáveis*, com o operador *op*. A sintaxe da `reduction` cláusula é a seguinte:

`reduction(`*op* `:` *lista de variáveis*`)`

Uma redução normalmente é especificada para uma instrução com uma das seguintes formas:

- *x* `=` *expr* de *op* x *x*
- *expr x* *binop* `=` *expr*
- *x* `=` *expr* *op* *x*  (exceto para subtração)
- *x*`++`
- `++` *x*
- *x*`--`
- `--` *x*

onde:

*x*<br/>
Uma das variáveis de redução especificadas na lista.

*lista de variáveis*<br/>
Uma lista separada por vírgulas de variáveis de redução escalar.

*expr*<br/>
Uma expressão com tipo escalar que não faz referência a *x*.

*parar*<br/>
Não é um operador sobrecarregado, mas um de `+` , `*` , `-` , `&` , `^` , `|` , `&&` ou `||` .

*binop*<br/>
Não é um operador sobrecarregado, mas um de `+` , `*` , `-` , `&` , `^` ou `|` .

Veja a seguir um exemplo da `reduction` cláusula:

```cpp
#pragma omp parallel for reduction(+: a, y) reduction(||: am)
for (i=0; i<n; i++) {
   a += b[i];
   y = sum(y, c[i]);
   am = am || b[i] == c[i];
}
```

Conforme mostrado no exemplo, um operador pode estar oculto dentro de uma chamada de função. O usuário deve ter cuidado para que o operador especificado na `reduction` cláusula corresponda à operação de redução.

Embora o operando direito do `||` operador não tenha efeitos colaterais neste exemplo, eles são permitidos, mas devem ser usados com cuidado. Nesse contexto, um efeito colateral que não ocorrerá durante a execução sequencial do loop pode ocorrer durante a execução paralela. Essa diferença pode ocorrer porque a ordem de execução das iterações é indeterminada.

O operador é usado para determinar o valor inicial de quaisquer variáveis privadas usadas pelo compilador para a redução e para determinar o operador de finalização. Especificar o operador explicitamente permite que a instrução de redução esteja fora da extensão lexical da construção. Qualquer número de `reduction` cláusulas pode ser especificado na diretiva, mas uma variável pode aparecer em no máximo uma `reduction` cláusula para essa diretiva.

Uma cópia privada de cada variável na *lista de variáveis* é criada, uma para cada thread, como se a `private` cláusula tivesse sido usada. A cópia privada é inicializada de acordo com o operador (consulte a tabela a seguir).

No final da região para a qual a `reduction` cláusula foi especificada, o objeto original é atualizado para refletir o resultado da combinação de seu valor original com o valor final de cada uma das cópias privadas usando o operador especificado. Os operadores de redução são todos associativos (exceto para subtração), e o compilador pode reassociar livremente a computação do valor final. (Os resultados parciais de uma redução de subtração são adicionados para formar o valor final.)

O valor do objeto original torna-se indeterminado quando o primeiro thread atinge a cláusula de contenção e permanece assim até que a computação de redução seja concluída.  Normalmente, a computação será concluída no final da construção; no entanto, se a `reduction` cláusula for usada em um constructo ao qual `nowait` também é aplicada, o valor do objeto original permanecerá indeterminado até que uma sincronização de barreira tenha sido executada para garantir que todos os threads tenham concluído a `reduction` cláusula.

A tabela a seguir lista os operadores que são válidos e seus valores de inicialização canônicas. O valor de inicialização real será consistente com o tipo de dados da variável de redução.

|Operador|Inicialização|
|--------------|--------------------|
|`+`|0|
|`*`|1|
|`-`|0|
|`&`|~0|
|`|`|0|
|`^`|0|
|`&&`|1|
|`||`|0|

As restrições à `reduction` cláusula são as seguintes:

- O tipo das variáveis na `reduction` cláusula deve ser válido para o operador de redução, exceto que tipos de ponteiro e tipos de referência nunca são permitidos.

- Uma variável especificada na `reduction` cláusula não deve ser **`const`** qualificada.

- Variáveis que são privadas em uma região paralela ou que aparecem na `reduction` cláusula de uma `parallel` diretiva não podem ser especificadas em uma `reduction` cláusula em uma diretiva de compartilhamento de trabalho que se associa à construção paralela.

   ```cpp
   #pragma omp parallel private(y)
   { /* ERROR - private variable y cannot be specified
                in a reduction clause */
      #pragma omp for reduction(+: y)
      for (i=0; i<n; i++)
         y += b[i];
   }

   /* ERROR - variable x cannot be specified in both
              a shared and a reduction clause */
   #pragma omp parallel for shared(x) reduction(+: x)
   ```

#### <a name="2727-copyin"></a>2.7.2.7 copyin

A `copyin` cláusula fornece um mecanismo para atribuir o mesmo valor às `threadprivate` variáveis para cada thread na equipe que executa a região paralela. Para cada variável especificada em uma `copyin` cláusula, o valor da variável no thread mestre da equipe é copiado, como se fosse por atribuição, para as cópias de thread privado no início da região paralela. A sintaxe da `copyin` cláusula é a seguinte:

```cpp

copyin(
variable-list
)
```

As restrições à `copyin` cláusula são as seguintes:

- Uma variável especificada na `copyin` cláusula deve ter um operador de atribuição de cópia acessível e não ambíguo.

- Uma variável que é especificada na `copyin` cláusula deve ser uma `threadprivate` variável.

#### <a name="2728-copyprivate"></a>2.7.2.8 copyprivate

A `copyprivate` cláusula fornece um mecanismo para usar uma variável privada para transmitir um valor de um membro de uma equipe para os outros membros. É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecer uma variável compartilhada como essa seria difícil (por exemplo, em uma recursão que requer uma variável diferente em cada nível). A `copyprivate` cláusula só pode aparecer na `single` diretiva.

A sintaxe da `copyprivate` cláusula é a seguinte:

```cpp

copyprivate(
variable-list
)
```

O efeito da `copyprivate` cláusula nas variáveis em sua lista de variáveis ocorre após a execução do bloco estruturado associado à `single` construção e antes que qualquer um dos threads da equipe tenha deixado a barreira no final da construção. Em seguida, em todos os outros threads da equipe, para cada variável na *lista de variáveis*, essa variável torna-se definida (como se por atribuição) com o valor da variável correspondente no thread que executou o bloco estruturado da construção.

As restrições à `copyprivate` cláusula são as seguintes:

- Uma variável especificada na `copyprivate` cláusula não deve aparecer em uma `private` `firstprivate` cláusula or para a mesma `single` diretiva.

- Se uma `single` diretiva com uma `copyprivate` cláusula for encontrada na extensão dinâmica de uma região paralela, todas as variáveis especificadas na `copyprivate` cláusula deverão ser privadas no contexto delimitador.

- Uma variável especificada na `copyprivate` cláusula deve ter um operador de atribuição de cópia não ambíguo acessível.

## <a name="28-directive-binding"></a>Associação de diretiva 2,8

A vinculação dinâmica de diretivas deve aderir às seguintes regras:

- As `for` diretivas,, `sections` `single` , `master` e são `barrier` associadas ao fechamento dinâmico `parallel` , se houver uma, independentemente do valor de qualquer `if` cláusula que possa estar presente nessa diretiva. Se nenhuma região paralela estiver sendo executada no momento, as diretivas serão executadas por uma equipe composta apenas pelo thread mestre.

- A `ordered` diretiva é ligada ao fechamento dinâmico `for` .

- A `atomic` diretiva impõe acesso exclusivo com relação às `atomic` diretivas em todos os threads, não apenas à equipe atual.

- A `critical` diretiva impõe acesso exclusivo com relação às `critical` diretivas em todos os threads, não apenas à equipe atual.

- Uma diretiva nunca pode ser associada a qualquer diretiva fora do delimitador mais próximo `parallel` .

## <a name="29-directive-nesting"></a>aninhamento de diretiva 2,9

O aninhamento dinâmico de diretivas deve aderir às seguintes regras:

- Uma `parallel` diretiva dinamicamente dentro de outra `parallel` estabelece logicamente uma nova equipe, que é composta apenas pelo thread atual, a menos que o paralelismo aninhado esteja habilitado.

- `for``sections` `single` as diretivas, e que se associam ao mesmo `parallel` não podem ser aninhadas umas nas outras.

- `critical` diretivas com o mesmo nome não podem ser aninhadas umas nas outras. Observe que essa restrição não é suficiente para impedir o deadlock.

- `for``sections` `single` as diretivas, e não são permitidas na extensão dinâmica `critical` das `ordered` regiões, e `master` se as diretivas se associarem ao mesmo `parallel` que as regiões.

- `barrier` as diretivas não são permitidas na extensão dinâmica das regiões,,,, `for` `ordered` `sections` `single` `master` e `critical` se as diretivas se associarem ao mesmo `parallel` que as regiões.

- `master` as diretivas não são permitidas na extensão dinâmica de `for` `sections` diretivas, e `single` se as `master` diretivas se associarem ao mesmo `parallel` que as diretivas de compartilhamento de trabalho.

- `ordered` as diretivas não são permitidas na extensão dinâmica de `critical` regiões se as diretivas se associarem ao mesmo `parallel` que as regiões.

- Qualquer diretiva permitida quando executada dinamicamente dentro de uma região paralela também é permitida quando executada fora de uma região paralela. Quando executado dinamicamente fora de uma região paralela especificada pelo usuário, a diretiva é executada por uma equipe composta apenas pelo thread mestre.
