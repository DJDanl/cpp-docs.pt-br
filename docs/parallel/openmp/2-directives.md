---
title: 2. Diretivas
ms.date: 01/18/2019
ms.assetid: d1a69374-6c03-45fb-8c86-e91cea8adae8
ms.openlocfilehash: 125d2d83b277e62d007e3a208e426ea717d52790
ms.sourcegitcommit: 382e247c0f1b4cb7c2dab837b8b6fdff24bff47a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/28/2019
ms.locfileid: "55087334"
---
# <a name="2-directives"></a>2. Diretivas

As diretivas se baseiam no `#pragma` diretivas definidas nos padrões de C e C++.  Compiladores que dão suporte a OpenMP C e C++ API inclui uma opção de linha de comando que ativa e permite que a interpretação de todas as diretivas de compilador OpenMP.

## <a name="21-directive-format"></a>2.1 formato de diretiva

A sintaxe de uma diretiva de OpenMP formalmente é especificada pela gramática em [Apêndice C](c-openmp-c-and-cpp-grammar.md)e informalmente da seguinte maneira:

```cpp
#pragma omp directive-name  [clause[ [,] clause]...] new-line
```

Cada diretiva começa com `#pragma omp`, para reduzir o potencial de conflito com outras políticas de pragma (não-OpenMP ou fornecedor de extensões OpenMP) com os mesmos nomes. O restante da diretiva segue as convenções dos padrões de diretivas de compilador C e C++. Em particular, o espaço em branco pode ser usado antes e depois o `#`, e, às vezes, o espaço em branco devem ser usado para separar as palavras em uma diretiva. A seguir de tokens de pré-processamento a `#pragma omp` estão sujeitos a substituição de macro.

As diretivas são diferencia maiusculas de minúsculas. A ordem na qual as cláusulas aparecem nas diretivas não é significativa. Cláusulas sobre as diretivas podem ser repetidas, conforme necessário, de acordo com as restrições listadas na descrição de cada cláusula. Se *lista variável* aparece em uma cláusula, ele deve especificar somente as variáveis. Somente um *nome da diretiva* pode ser especificado por diretiva.  Por exemplo, não é permitida a seguinte diretiva:

```cpp
/* ERROR - multiple directive names not allowed */
#pragma omp parallel barrier
```

Uma diretiva de OpenMP aplica-se a no máximo uma subsequente instrução, que deve ser um bloco estruturado.

## <a name="22-conditional-compilation"></a>2.2 compilação condicional

O `_OPENMP` nome da macro é definida por implementações em conformidade com o OpenMP, como a constante decimal *yyyymm*, que será o ano e mês da especificação de aprovados. Essa macro não deve ser o assunto de um `#define` ou um `#undef` diretiva de pré-processamento.

```cpp
#ifdef _OPENMP
iam = omp_get_thread_num() + index;
#endif
```

Se fornecedores definam ampliações OpenMP, eles podem especificar outras macros predefinidas.

## <a name="23-parallel-construct"></a>2.3 construto parallel

A diretiva a seguir define uma região paralela, o que é uma região do programa que deve ser executado por muitos threads em paralelo. Essa diretiva é a construção fundamental que inicia a execução paralela.

```cpp
#pragma omp parallel [clause[ [, ]clause] ...] new-line   structured-block
```

O *cláusula* é um dos seguintes:

- `if(` *scalar-expression* `)`
- `private(` *variable-list* `)`
- `firstprivate(` *variable-list* `)`
- `default(shared | none)`
- `shared(` *variable-list* `)`
- `copyin(` *variable-list* `)`
- `reduction(` *operator* `:`  *variable-list* `)`
- `num_threads(` *integer-expression* `)`

Quando um thread atinge uma construção paralela, uma equipe de threads é criada, se um dos casos a seguir for verdadeiro:

- Não `if` cláusula estiver presente.
- O `if` expressão é avaliada como um valor diferente de zero.

Esse thread torna-se o thread mestre da equipe, com um número de threads de 0, e todos os threads da equipe, incluindo o thread mestre, executem a região em paralelo. Se o valor da `if` expressão for zero, a região é serializada.

Para determinar o número de threads que são solicitados, as regras a seguir serão consideradas na ordem. A primeira regra cuja condição é atendida será aplicada:

1. Se o `num_threads` cláusula estiver presente, então o valor da expressão de inteiro é o número de threads solicitado.

1. Se o `omp_set_num_threads` biblioteca a função foi chamada e, em seguida, o valor do argumento na chamada executada mais recentemente é o número de threads solicitado.

1. Se a variável de ambiente `OMP_NUM_THREADS` for definida, o valor dessa variável de ambiente é o número de threads solicitado.

1. Se nenhum dos métodos acima for usado, o número de threads solicitado é definido pela implementação.

Se o `num_threads` cláusula estiver presente e em seguida, ele substitui o número de threads solicitado pelo `omp_set_num_threads` função de biblioteca ou o `OMP_NUM_THREADS` variável de ambiente somente para a região paralela, ela é aplicada ao. Mais tarde regiões em paralelo não é afetado por ela.

O número de threads que executam a região paralela também depende se o ajuste dinâmico do número de threads está habilitado. Se o ajuste dinâmico for desabilitado, o número solicitado de threads executará a região paralela. Se o ajuste dinâmico estiver habilitado, em seguida, o número solicitado de threads é o número máximo de threads que podem ser executadas a região paralela.

Se uma região parallel for encontrada enquanto o ajuste dinâmico do número de threads está desabilitado e o número de threads solicitada para a região paralela é mais do que o número que o sistema de tempo de execução pode fornecer, o comportamento do programa é definido pela implementação. Uma implementação pode, por exemplo, interromper a execução do programa, ou ele pode serializar a região paralela.

O `omp_set_dynamic` função de biblioteca e o `OMP_DYNAMIC` variável de ambiente pode ser usada para ativar e desativar o ajuste dinâmico do número de threads.

O número de processadores físicos, hospedagem, na verdade, os threads em um determinado momento é definido pela implementação. Depois de criado, o número de threads na equipe permanece constante durante essa região paralela. Ele pode ser alterado explicitamente pelo usuário ou automaticamente pelo sistema de tempo de execução de uma região paralela para outro.

As instruções contidas em extensão dinâmico da região paralela são executadas por cada thread, e cada thread pode executar um caminho de instruções que é diferente de outros threads. Diretivas encontradas fora a extensão de léxica de uma região paralela são chamadas de diretivas de órfãos.

Há uma barreira implícita no final de uma região paralela. Somente o thread mestre da equipe continua a execução no final de uma região paralela.

Se um thread em uma equipe de execução de uma região parallel encontrar outro constructo parallel, ele cria uma nova equipe, e ele se torna o mestre da nova equipe. Regiões em paralelo aninhadas são serializadas por padrão. Como resultado, por padrão, uma região paralela aninhada é executada por uma equipe composta de um thread. O comportamento padrão pode ser alterado usando a função de biblioteca de tempo de execução `omp_set_nested` ou a variável de ambiente `OMP_NESTED`. No entanto, o número de threads que executam uma região paralela aninhada em uma equipe é definido pela implementação.

Restrições para o `parallel` diretiva são da seguinte maneira:

- No máximo, um `if` cláusula pode aparecer na diretiva.

- Ele tem não especificado se qualquer lado efeitos dentro do if expressão ou `num_threads` expressão ocorrer.

- Um `throw` executado dentro de uma região parallel deve causar a execução de retomar dentro a extensão dinâmica do mesmo bloco estruturado, e ela deve ser capturada pelo mesmo thread que gerou a exceção.

- Um único `num_threads` cláusula pode aparecer na diretiva. O `num_threads` expressão é avaliada fora do contexto da região paralela e deve ser avaliada como um valor inteiro positivo.

- A ordem de avaliação do `if` e `num_threads` cláusulas não está especificado.

### <a name="cross-references"></a>Referências cruzadas

- `private`, `firstprivate`, `default`, `shared`, `copyin`, e `reduction` cláusulas ([seção 2.7.2](#272-data-sharing-attribute-clauses))
- [OMP_NUM_THREADS](4-environment-variables.md#42-omp_num_threads) variável de ambiente
- [omp_set_dynamic](3-run-time-library-functions.md#317-omp_set_dynamic-function) função de biblioteca
- [OMP_DYNAMIC](4-environment-variables.md#43-omp_dynamic) variável de ambiente
- [omp_set_nested](3-run-time-library-functions.md#319-omp_set_nested-function) function
- [OMP_NESTED](4-environment-variables.md#44-omp_nested) variável de ambiente
- [omp_set_num_threads](3-run-time-library-functions.md#311-omp_set_num_threads-function) função de biblioteca

## <a name="24-work-sharing-constructs"></a>2.4 construtos work-sharing

Uma construção de compartilhamento de trabalho distribui a execução da instrução associada entre os membros da equipe que encontrá-lo. As diretivas de compartilhamento de trabalho não iniciar novos threads e não há nenhum barreira implícita na entrada para uma construção de compartilhamento de trabalho.

Constrói a sequência de compartilhamento de trabalho e `barrier` diretivas encontradas devem ser o mesmo para cada thread em uma equipe.

OpenMP define as seguintes construções de compartilhamento de trabalho, e essas construções são descritas nas seções a seguir:

- [para](#241-for-construct) diretiva
- [seções](#242-sections-construct) diretiva
- [único](#243-single-construct) diretiva

### <a name="241-for-construct"></a>2.4.1 constructo for

O `for` diretiva identifica uma construção de compartilhamento de trabalho iterativa que especifica que as iterações do loop associado serão executadas em paralelo. As iterações do `for` loop são distribuídas entre os threads que já existem na equipe que está executando o constructo paralelo ao qual ele se associa. A sintaxe do `for` construção é da seguinte maneira:

```cpp
#pragma omp for [clause[[,] clause] ... ] new-line for-loop
```

A cláusula é um dos seguintes:

- `private(` *variable-list* `)`
- `firstprivate(` *variable-list* `)`
- `lastprivate(` *variable-list* `)`
- `reduction(` *operator* `:` *variable-list* `)`
- `ordered`
- `schedule(` *kind* [`,` *chunk_size*] `)`
- `nowait`

O `for` diretiva impõe restrições na estrutura da correspondente `for` loop. Especificamente, o correspondente `for` loop deve ter a forma canônica:

`for (` *init-expr* `;` *var  logical-op  b* `;` *incr-expr* `)`

*init-expr*<br/>
Um dos seguintes:

- *var* = *lb*
- *integer-type var* = *lb*

*incr-expr*<br/>
Um dos seguintes:

- `++` *var*
- *var* `++`
- `--` *var*
- *var* `--`
- *var* `+=` *incr*
- *var* `-=` *incr*
- *var* `=` *var* `+` *incr*
- *var* `=` *incr* `+` *var*
- *var* `=` *var* `-` *incr*

*var*<br/>
Uma variável de inteiro com sinal. Se essa variável deve ser compartilhada, ele será implicitamente feito privada para a duração da `for`. Não modifique essa variável dentro do corpo do `for` instrução. A menos que a variável é especificada `lastprivate`, seu valor depois que o loop é indeterminado.

*logical-op*<br/>
Um dos seguintes:

- `<`
- `<=`
- `>`
- `>=`

*balanceamento de carga*, *b*, e *incr*<br>
Expressões de inteiro de invariável de loop. Não há nenhuma sincronização durante a avaliação dessas expressões, para que os efeitos colaterais avaliados produzir resultados indeterminados.

A forma canônica permite que o número de iterações de loop para ser computada na entrada para o loop. Esse cálculo é feito com os valores no tipo de *var*, após as promoções de integral. Em particular, se o valor de *b* `-` *lb* `+` *incr* não pode ser representado nesse tipo, o resultado é indeterminado. Além disso, se *lógico op* é `<` ou `<=`, em seguida, *incr expr* deve fazer com que *var* aumentar em cada iteração do loop.   Se *lógico op* é `>` ou `>=`, em seguida, *incr expr* deve fazer com que *var* a ficar menores em cada iteração do loop.

O `schedule` cláusula Especifica como as iterações do `for` loop são divididas entre os threads da equipe. A correção de um programa não deve depender de qual thread executa uma iteração específica. O valor de *chunk_size*, se especificado, deve ser uma expressão de inteiro de invariável de loop com um valor positivo. Não há nenhuma sincronização durante a avaliação desta expressão, para que os efeitos colaterais avaliados produzir resultados indeterminados. A agenda *tipo* pode ser um dos seguintes valores:

Tabela 2-1: `schedule` cláusula *tipo* valores

|||
|-|-|
|static|Quando `schedule(static,` *chunk_size* `)` for especificado, as iterações são divididas em partes de um tamanho especificado por *chunk_size*. As partes são atribuídas estaticamente a threads da equipe em um estilo round-robin na ordem o número de threads. Quando nenhum *chunk_size* for especificado, o espaço de iteração é dividido em partes que são aproximadamente iguais em tamanho, com uma parte atribuída a cada thread.|
|dinâmica|Quando `schedule(dynamic,` *chunk_size* `)` for especificado, as iterações são divididas em uma série de blocos, cada uma contendo *chunk_size* iterações. Cada parte é atribuído a um thread que está aguardando uma atribuição. O thread executa o fragmento de iterações e, em seguida, aguarda sua atribuição de Avançar, até que nenhum partes permaneçam para ser atribuído. A última parte a ser atribuído pode ter um número menor de iterações. Quando nenhum *chunk_size* for especificado, o padrão será 1.|
|interativa|Quando `schedule(guided,` *chunk_size* `)` for especificado, as iterações são atribuídas aos threads em partes com tamanhos de diminuir. Quando um thread termina seu bloco atribuído de iterações, ela tem atribuído dinamicamente outro bloco, até que nenhum é deixado. Para um *chunk_size* de 1, o tamanho de cada parte é aproximadamente igual ao número de iterações não atribuídos, dividido pelo número de threads. Esses tamanhos diminuem exponencialmente quase como 1. Para um *chunk_size* com o valor *k* maior que 1, os tamanhos de quase exponencialmente para diminuir *k*, exceto que a última parte pode ter menos de *k* iterações. Quando nenhum *chunk_size* for especificado, o padrão será 1.|
|tempo de execução|Quando `schedule(runtime)` for especificado, a decisão sobre agendamento é adiada até o tempo de execução. A agenda *tipo* e o tamanho das partes pode ser escolhido no tempo de execução, definindo a variável de ambiente `OMP_SCHEDULE`. Se essa variável de ambiente não for definido, o agendamento resultante é definido pela implementação. Quando `schedule(runtime)` for especificado, *chunk_size* não deve ser especificado.|

Na ausência de explicitamente definidas `schedule` cláusula, o padrão `schedule` é definido pela implementação.

Um programa de conformidade de OpenMP não deve confiar em um agendamento específico para execução correta. Um programa não deve confiar em um agendamento *tipo* em conformidade com precisão a descrição fornecida acima, porque é possível ter variações nas implementações do mesmo agendamento *tipo* entre compiladores diferentes. As descrições de podem ser usadas para selecionar a agenda que é apropriada para uma determinada situação.

O `ordered` cláusula deve estar presente quando `ordered` diretivas de associar o `for` construir.

Há uma barreira implícita no final de uma `for` construir, a menos que um `nowait` cláusula for especificada.

Restrições para o `for` diretiva são da seguinte maneira:

- O `for` loop deve ser um bloco estruturado e, além disso, sua execução não deve ser terminada por um `break` instrução.

- Os valores do loop de expressões de controlam a `for` loop associado com um `for` diretiva deve ser o mesmo para todos os threads da equipe.

- O `for` variável de iteração do loop deve ter um tipo de inteiro com sinal.

- Um único `schedule` cláusula pode aparecer em um `for` diretiva.

- Um único `ordered` cláusula pode aparecer em um `for` diretiva.

- Um único `nowait` cláusula pode aparecer em um `for` diretiva.

- É se não especificado ou a frequência com que os efeitos de qualquer lado dentro de *chunk_size*, *lb*, *b*, ou *incr* expressões ocorrem.

- O valor de *chunk_size* expressão deve ser o mesmo para todos os threads da equipe.

#### <a name="cross-references"></a>Referências cruzadas

- `private`, `firstprivate`, `lastprivate`, e `reduction` cláusulas ([seção 2.7.2](#272-data-sharing-attribute-clauses))
- [OMP_SCHEDULE](4-environment-variables.md#41-omp_schedule) variável de ambiente
- [ordenado](#266-ordered-construct) construir
- [agenda](d-using-the-schedule-clause.md) cláusula

### <a name="242-sections-construct"></a>2.4.2 seções constructo

O `sections` diretiva identifica uma construção de compartilhamento de trabalho noniterative que especifica um conjunto de construções que devem ser divididos entre os threads em uma equipe. Cada seção é executada uma vez por um thread em que a equipe. A sintaxe do `sections` diretiva é da seguinte maneira:

```cpp
#pragma omp sections [clause[[,] clause] ...] new-line
   {
   [#pragma omp section new-line]
      structured-block
   [#pragma omp section new-linestructured-block ]
...
}
```

A cláusula é um dos seguintes:

- `private(` *variable-list* `)`
- `firstprivate(` *variable-list* `)`
- `lastprivate(` *variable-list* `)`
- `reduction(` *operator* `:`  *variable-list* `)`
- `nowait`

Cada seção é precedida por um `section` diretiva, embora o `section` diretiva é opcional para a primeira seção. O `section` diretivas devem ser exibido entre a extensão léxica do `sections` diretiva. Há uma barreira implícita no final de uma `sections` construir, a menos que um `nowait` é especificado.

Restrições para o `sections` diretiva são da seguinte maneira:

- Um `section` diretiva não pode aparecer fora a extensão léxica do `sections` diretiva.

- Um único `nowait` cláusula pode aparecer em um `sections` diretiva.

#### <a name="cross-references"></a>Referências cruzadas

- `private`, `firstprivate`, `lastprivate`, e `reduction` cláusulas ([seção 2.7.2](#272-data-sharing-attribute-clauses))

### <a name="243-single-construct"></a>2.4.3 constructo single

O `single` diretiva identifica uma construção que especifica que o bloco estruturado associado é executado por apenas um thread na equipe (não necessariamente o thread mestre). A sintaxe do `single` diretiva é da seguinte maneira:

```cpp
#pragma omp single [clause[[,] clause] ...] new-linestructured-block
```

A cláusula é um dos seguintes:

- `private(` *variable-list* `)`
- `firstprivate(` *variable-list* `)`
- `copyprivate(` *variable-list* `)`
- `nowait`

Há uma barreira implícita após o `single` construir, a menos que um `nowait` cláusula for especificada.

Restrições para o `single` diretiva são da seguinte maneira:

- Um único `nowait` cláusula pode aparecer em um `single` diretiva.
- O `copyprivate` cláusula não deve ser usada com o `nowait` cláusula.

#### <a name="cross-references"></a>Referências cruzadas

- `private`, `firstprivate`, e `copyprivate` cláusulas ([seção 2.7.2](#272-data-sharing-attribute-clauses))

## <a name="25-combined-parallel-work-sharing-constructs"></a>2.5 combinado constructos de compartilhamento de trabalho paralelo

Constructos de compartilhamento de trabalho combinados em paralelo são atalhos para especificar uma região paralela que tem apenas um constructo de compartilhamento de trabalho. A semântica dessas diretivas é o mesmo que especificar explicitamente um `parallel` diretiva seguido por um único constructo de compartilhamento de trabalho.

As seções a seguir descrevem as construções de compartilhamento de trabalho paralelas combinadas:

- [paralelo para](#251-parallel-for-construct) diretiva
- [seções em paralelo](#252-parallel-sections-construct) diretiva

### <a name="251-parallel-for-construct"></a>2.5.1 construto parallel for

O `parallel for` diretiva é um atalho para um `parallel` região que contém um único `for` diretiva. A sintaxe do `parallel for` diretiva é da seguinte maneira:

```cpp
#pragma omp parallel for [clause[[,] clause] ...] new-linefor-loop
```

Essa diretiva permite que todas as cláusulas do `parallel` diretiva e a `for` diretiva, exceto o `nowait` cláusula com significados idênticos e restrições. A semântica é o mesmo que especificar explicitamente uma `parallel` diretiva seguida imediatamente por um `for` diretiva.

#### <a name="cross-references"></a>Referências cruzadas

- [paralelo](#23-parallel-construct) diretiva
- [para](#241-for-construct) diretiva
- [Cláusulas de atributo de dados](#272-data-sharing-attribute-clauses)

### <a name="252-parallel-sections-construct"></a>2.5.2 seções paralela constructo

O `parallel sections` diretiva fornece um formulário de atalho para especificar um `parallel` que tem uma única região `sections` diretiva. A semântica é o mesmo que especificar explicitamente uma `parallel` diretiva seguida imediatamente por um `sections` diretiva. A sintaxe do `parallel sections` diretiva é da seguinte maneira:

```cpp
#pragma omp parallel sections  [clause[[,] clause] ...] new-line
   {
   [#pragma omp section new-line]
      structured-block
   [#pragma omp section new-linestructured-block  ]
   ...
}
```

O *cláusula* pode ser uma das cláusulas aceitas pela `parallel` e `sections` diretivas, exceto o `nowait` cláusula.

#### <a name="cross-references"></a>Referências cruzadas

- [paralelo](#23-parallel-construct) diretiva
- [seções](#242-sections-construct) diretiva

## <a name="26-master-and-synchronization-directives"></a>2.6 diretivas mestre e sincronização

As seções a seguir descrevem:

- [mestre](#261-master-construct) construir
- [crítico](#262-critical-construct) construir
- [barrier](#263-barrier-directive) directive
- [Atomic](#264-atomic-construct) construir
- [liberar](#265-flush-directive) diretiva
- [ordenado](#266-ordered-construct) construir

### <a name="261-master-construct"></a>2.6.1 constructo master

O `master` diretiva identifica uma construção que especifica um bloco estruturado que é executado pelo thread principal da equipe. A sintaxe do `master` diretiva é da seguinte maneira:

```cpp
#pragma omp master new-linestructured-block
```

Outros threads da equipe não executem o bloco estruturado associado. Não há nenhum barreira implícita tanto na entrada ou saída da construção de mestre.

### <a name="262-critical-construct"></a>2.6.2 construto critical

O `critical` diretiva identifica uma construção que restringe a execução do bloco estruturado associado a um único thread por vez. A sintaxe do `critical` diretiva é da seguinte maneira:

```cpp
#pragma omp critical [(name)]  new-linestructured-block
```

Um recurso opcional *nome* pode ser usado para identificar a região crítica. Usado para identificar uma região crítica de identificadores têm vinculação externa e estão em um espaço para nome que é separado dos name spaces usados por rótulos, marcas, membros e identificadores comuns.

Um thread aguarda no início de uma região crítica, até que nenhum outro thread está em execução em uma região crítica (em qualquer lugar no programa) com o mesmo nome. Tudo sem nome `critical` diretivas mapeiam para o mesmo nome não especificado.

### <a name="263-barrier-directive"></a>2.6.3 diretiva de barreira

O `barrier` diretiva sincroniza todos os threads em uma equipe. Quando encontrados, cada thread em que a equipe espera até que todos os outros tenham atingido neste ponto. A sintaxe do `barrier` diretiva é da seguinte maneira:

```cpp
#pragma omp barrier new-line
```

Depois que todos os threads da equipe tiveram encontrado a barreira, cada thread em que a equipe começa a executar as instruções após a diretiva de barreira em paralelo. Porque o `barrier` diretiva não tem uma instrução de linguagem C como parte de sua sintaxe, há algumas restrições sobre seu posicionamento dentro de um programa. Para obter mais informações sobre a gramática formal, consulte [Apêndice C](c-openmp-c-and-cpp-grammar.md). O exemplo a seguir ilustra essas restrições.

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

### <a name="264-atomic-construct"></a>2.6.4 constructo atomic

O `atomic` diretiva garante que um local específico da memória é atualizado atomicamente, em vez de expô-lo para a possibilidade de várias simultâneas gravando segmentos. A sintaxe do `atomic` diretiva é da seguinte maneira:

```cpp
#pragma omp atomic new-lineexpression-stmt
```

A instrução da expressão deve ter uma das seguintes formas:

- *x binop* `=` *expr*
- *x* `++`
- `++` *x*
- *x* `--`
- `--` *x*

Nas expressões anteriores:

- *x* é uma expressão de lvalue com tipo escalar.

- *Expr* é uma expressão com um tipo escalar, e ele não faz referência a objeto designado pelo *x*.

- *binop* não é um operador sobrecarregado e é uma das `+`, `*`, `-`, `/`, `&`, `^`, `|`, `<<`, ou `>>`.

Embora seja definido pela implementação se uma implementação substitui todos os `atomic` diretivas com `critical` diretivas que têm o mesmo exclusivo *nome*, o `atomic` diretiva permite uma melhor otimização . Instruções de hardware geralmente estão disponíveis que podem executar a atualização atômica com menos sobrecarga.

Somente o carregamento e o armazenamento de objeto designado pelo *x* são atômicas; avaliação de *expr* não é atômica. Para evitar condições de corrida, todas as atualizações do local em paralelo devem ser protegidas com o `atomic` diretiva, exceto aqueles que são conhecidos por estar livres de condições de corrida.

Restrições para o `atomic` diretiva são da seguinte maneira:

- Todas as referências atômicas para o local de armazenamento em todo o programa x devem ter um tipo compatível.

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

### <a name="265-flush-directive"></a>2.6.5 diretiva flush

O `flush` diretiva, explícita ou implícita, especifica um ponto de sequência de "thread cruzado" em que a implementação é necessário para garantir que todos os threads em uma equipe tenham uma exibição consistente de determinados objetos (especificados abaixo) na memória. Isso significa que avaliações anteriores das expressões que referenciam esses objetos forem concluídas e as avaliações subsequentes ainda não tenham começaram. Por exemplo, os compiladores devem restaurar os valores dos objetos de registros para a memória e hardware talvez seja necessário liberar os buffers de gravação para a memória e recarregar os valores dos objetos da memória.

A sintaxe do `flush` diretiva é da seguinte maneira:

```cpp
#pragma omp flush [(variable-list)]  new-line
```

Se os objetos que requerem sincronização podem ser designados por variáveis, essas variáveis podem ser especificadas na opcional *lista variável*. Se um ponteiro estiver presente na *lista variável*, o ponteiro em si é liberado, não o objeto que o ponteiro se refere a.

Um `flush` diretiva sem uma *lista variável* sincroniza objetos todos compartilhados, exceto objetos inacessíveis com duração automática de armazenamento. (Isso é provavelmente terá mais sobrecarga do que um `flush` com um *lista variável*.) Um `flush` diretiva sem uma *lista variável* é implícita para as seguintes diretivas:

- `barrier`
- Na entrada e saída de `critical`
- Na entrada e saída de `ordered`
- Na entrada e saída de `parallel`
- Na saída de `for`
- Na saída de `sections`
- Na saída de `single`
- Na entrada e saída de `parallel for`
- Na entrada e saída de `parallel sections`

A diretiva não é implícito, se um `nowait` cláusula estiver presente. É importante observar que o `flush` diretiva não está implícito para qualquer um dos seguintes:

- Na entrada para `for`
- Na entrada ou saída de `master`
- Na entrada para `sections`
- Na entrada para `single`

Uma referência que acessa o valor de um objeto com um tipo qualificado como volátil se comporta como se houvesse um `flush` diretiva especificando o objeto no ponto de sequência anterior. Uma referência que modifica o valor de um objeto com um tipo qualificado como volátil se comporta como se houvesse um `flush` diretiva especificando o objeto no ponto de sequência subsequente.

Porque o `flush` diretiva não tem uma instrução de linguagem C como parte de sua sintaxe, há algumas restrições sobre seu posicionamento dentro de um programa. Para obter mais informações sobre a gramática formal, consulte [Apêndice C](c-openmp-c-and-cpp-grammar.md). O exemplo a seguir ilustra essas restrições.

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

Restrições para o `flush` diretiva são da seguinte maneira:

- Uma variável especificada em um `flush` diretiva não deve ter um tipo de referência.

### <a name="266-ordered-construct"></a>2.6.6 construção ordenada

O seguinte bloco estruturado um `ordered` diretiva é executada na ordem em que iterações seriam executadas em um loop sequencial. A sintaxe do `ordered` diretiva é da seguinte maneira:

```cpp
#pragma omp ordered new-linestructured-block
```

Uma `ordered` diretiva deve estar dentro do extensão dinâmico de um `for` ou `parallel for` construir. O `for` ou `parallel for` diretiva para o qual o `ordered` associa constructo deve ter uma `ordered` cláusula especificada conforme descrito na [seção 2.4.1](#241-for-construct). Na execução de um `for` ou `parallel for` construir com um `ordered` cláusula, `ordered` construções são executadas estritamente na ordem em que eles fossem executados em uma execução sequencial do loop.

Restrições para o `ordered` diretiva são da seguinte maneira:

- Uma iteração de um loop com um `for` constructo não deve executar a mesma diretiva ordenada mais de uma vez e não devem executar mais de um `ordered` diretiva.

## <a name="27-data-environment"></a>2.7 ambiente de dados

Esta seção apresenta uma diretiva e várias cláusulas para controlar o ambiente de dados durante a execução de regiões em paralelo, da seguinte maneira:

- Um [threadprivate](#271-threadprivate-directive) diretiva é fornecida para tornar o escopo de arquivo, escopo de namespace ou variáveis estáticas de escopo de bloco local para um thread.

- As cláusulas que podem ser especificadas em que as diretivas para controlar os atributos de compartilhamento de variáveis para a duração das construções paralelas ou compartilhamento de trabalho são descritas em [seção 2.7.2](#272-data-sharing-attribute-clauses).

### <a name="271-threadprivate-directive"></a>2.7.1 diretiva threadprivate

O `threadprivate` diretiva torna o escopo de arquivo nomeado, escopo de namespace ou variáveis estáticas de escopo de bloco especificadas na *lista variável* privada para um thread. *lista de variável* é uma lista separada por vírgulas de variáveis que não têm um tipo incompleto. A sintaxe do `threadprivate` diretiva é da seguinte maneira:

```cpp
#pragma omp threadprivate(variable-list) new-line
```

Cada cópia de um `threadprivate` variável é inicializada uma vez, em um ponto especificado no programa antes da primeira referência para a cópia e da maneira usual (ou seja, como a cópia mestra deve ser inicializada em uma execução serial do programa). Observe que, se um objeto é referenciado no inicializador explícito de um `threadprivate` variável e o valor do objeto é modificado antes da primeira referência a uma cópia da variável e, em seguida, o comportamento é especificado.

Como com qualquer variável particular, um thread não deve fazer referência a cópia do outro thread de um `threadprivate` objeto. Durante a regiões seriais e mestre do programa, referências será a cópia mestre do segmento do objeto.

Depois que a primeira região paralela é executada, os dados no `threadprivate` objetos é garantido para manter somente se o mecanismo de threads de dinâmica foi desabilitada e, se o número de threads permanece inalterado para todas as regiões em paralelo.

As restrições para o `threadprivate` diretiva são da seguinte maneira:

- Um `threadprivate` diretiva para variáveis de escopo de arquivo ou o escopo de namespace deve aparecer fora de qualquer definição ou declaração e deve preceder lexicalmente todas as referências a qualquer uma das variáveis em sua lista.

- Cada variável na *variável-list* de um `threadprivate` diretiva no escopo de namespace ou arquivo deve se referir a uma declaração de variável no escopo de namespace ou arquivo que precede lexicalmente a diretiva.

- Um `threadprivate` diretiva para variáveis estáticas de escopo de bloco deve aparecer no escopo da variável e não em um escopo aninhado. A diretiva deve preceder lexicalmente todas as referências a qualquer uma das variáveis em sua lista.

- Cada variável na *variável-list* de um `threadprivate` diretiva no escopo de bloco deve se referir a uma declaração de variável no mesmo escopo que precede lexicalmente a diretiva. A declaração de variável deve usar o especificador de classe de armazenamento estático.

- Se uma variável for especificada em uma `threadprivate` diretiva em uma unidade de conversão, ele deve ser especificado em um `threadprivate` diretiva em cada unidade de tradução na qual ela é declarada.

- Um `threadprivate` variável não deve aparecer em qualquer cláusula, exceto o `copyin`, `copyprivate`, `schedule`, `num_threads`, ou o `if` cláusula.

- O endereço de um `threadprivate` variável não for uma constante de endereço.

- Um `threadprivate` variável não deve ter um tipo incompleto ou um tipo de referência.

- Um `threadprivate` variável com tipo de classe não POD deve ter um construtor de cópia acessível e não ambígua, se ela for declarada com um inicializador explícito.

O exemplo a seguir ilustra como modificar uma variável que é exibido em um inicializador que pode causar um comportamento não especificado e também como evitar esse problema usando um objeto auxiliar e um construtor de cópia.

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

### <a name="272-data-sharing-attribute-clauses"></a>2.7.2 cláusulas de atributo de compartilhamento de dados

Várias diretivas aceitam as cláusulas que permitem que um usuário controlar os atributos de compartilhamento de variáveis para a duração da região. Cláusulas de atributo de compartilhamento se aplicam somente a variáveis na extensão de léxico da diretiva na qual a cláusula é exibida. Nem todas as cláusulas a seguir são permitidas em todas as diretivas. A lista de cláusulas que são válidos em uma determinada diretiva são descritas com a diretiva.

Se uma variável é visível quando um paralelo ou construção de compartilhamento de trabalho for encontrada e a variável não for especificada em uma cláusula de atributo de compartilhamento ou `threadprivate` diretiva, em seguida, a variável é compartilhada. Variáveis estáticas declaradas dentro de extensão dinâmica de uma região paralela são compartilhadas. A memória alocado do heap (por exemplo, usando `malloc()` em C ou C++ ou o `new` operador em C++) é compartilhado. (O ponteiro para essa memória, no entanto, pode ser particulares ou compartilhados.) Variáveis com duração de armazenamento automático declarada dentro de extensão dinâmica de uma região paralela são privadas.

A maioria das cláusulas de aceita um *lista variável* argumento, que é uma lista separada por vírgulas de variáveis que são visíveis. Se uma variável é referenciada em uma cláusula de compartilhamento de dados de atributo tem um tipo derivado de um modelo e existem outras referências a essa variável no programa, o comportamento será indefinido.

Todas as variáveis que aparecem em cláusulas de diretiva devem estar visíveis. As cláusulas podem ser repetidas, conforme necessário, mas nenhuma variável pode ser especificado mais de uma cláusula, exceto pelo fato de uma variável pode ser especificada em ambos um `firstprivate` e um `lastprivate` cláusula.

As seções a seguir descrevem as cláusulas de atributo de compartilhamento de dados:

- [private](#2721-private)
- [firstprivate](#2722-firstprivate)
- [lastprivate](#2723-lastprivate)
- [shared](#2724-shared)
- [default](#2725-default)
- [reduction](#2726-reduction)
- [copyin](#2727-copyin)
- [copyprivate](#2728-copyprivate)

#### <a name="2721-private"></a>2.7.2.1 private

O `private` cláusula declara as variáveis na lista de variável a ser privadas para cada thread em uma equipe. A sintaxe do `private` cláusula é da seguinte maneira:

```cpp
private(variable-list)
```

O comportamento de uma variável especificada em um `private` cláusula é da seguinte maneira. Um novo objeto com duração automática de armazenamento é alocado para a construção. O tamanho e o alinhamento do novo objeto são determinados pelo tipo da variável. Essa alocação ocorre uma vez para cada thread na equipe, e um construtor padrão é invocado para um objeto de classe, se necessário; Caso contrário, o valor inicial é indeterminado.  O objeto original referenciado pela variável de tem um valor indeterminado durante a entrada para a construção, não deve ser modificado na extensão dinâmico da construção e tem um valor indeterminado após a saída da construção.

Na extensão de léxica da construção de diretiva, a variável referenciar o novo objeto privado alocado pelo thread.

As restrições para o `private` cláusula são da seguinte maneira:

- Uma variável com um tipo de classe que é especificado em um `private` cláusula deve ter um construtor padrão acessível, não ambígua.

- Uma variável especificada em uma `private` cláusula não deve ter um `const`-qualificado tipo, a menos que ele tem uma classe de tipo com um `mutable` membro.

- Uma variável especificada em um `private` cláusula não deve ter um tipo incompleto ou um tipo de referência.

- Variáveis que aparecem o `reduction` cláusula de uma `parallel` diretiva não pode ser especificada em uma `private` cláusula em uma diretiva de compartilhamento de trabalho que está associado a construção parallel.

#### <a name="2722-firstprivate"></a>2.7.2.2 firstprivate

O `firstprivate` cláusula fornece um superconjunto da funcionalidade fornecida pelo `private` cláusula. A sintaxe do `firstprivate` cláusula é da seguinte maneira:

```cpp
firstprivate(variable-list)
```

As variáveis especificadas no *variável-list* ter `private` semântica de cláusula, conforme descrito em [seção 2.7.2.1](#2721-private). A inicialização ou na construção ocorre como se ele foi feito uma vez por thread, antes da execução do thread da construção. Para um `firstprivate` cláusula em uma construção paralela, o valor inicial do novo objeto privado é o valor do objeto original que existe imediatamente antes da construção paralela para o thread que encontra. Para um `firstprivate` cláusula em uma construção de compartilhamento de trabalho, o valor inicial do novo objeto privado para cada thread que executa a construção de compartilhamento de trabalho é o valor do objeto original que existe antes do ponto no tempo que o mesmo thread encontra o construção de compartilhamento de trabalho. Além disso, para objetos de C++, o novo objeto privado para cada thread é cópia criada do objeto original.

As restrições para o `firstprivate` cláusula são da seguinte maneira:

- Uma variável especificada em um `firstprivate` cláusula não deve ter um tipo incompleto ou um tipo de referência.

- Uma variável com um tipo de classe que é especificado como `firstprivate` devem ter um construtor de cópia acessível inequívoca.

- Variáveis que são particulares dentro de uma região paralela ou que aparecem na `reduction` cláusula de uma `parallel` diretiva não pode ser especificada em uma `firstprivate` cláusula em uma diretiva de compartilhamento de trabalho que está associado a construção parallel.

#### <a name="2723-lastprivate"></a>2.7.2.3 lastprivate

O `lastprivate` cláusula fornece um superconjunto da funcionalidade fornecida pelo `private` cláusula. A sintaxe do `lastprivate` cláusula é da seguinte maneira:

```cpp
lastprivate(variable-list)
```

As variáveis especificadas na *variável-list* ter `private` semântica de cláusula. Quando um `lastprivate` cláusula é exibida sobre a diretiva que identifica uma construção de compartilhamento de trabalho, o valor de cada `lastprivate` variável de sequencialmente última iteração de loop associado ou lexicalmente última diretiva de seção, é atribuído à objeto de original da variável. Variáveis que não são atribuídas a um valor, a última iteração do `for` ou `parallel for`, ou por lexicalmente última seção de `sections` ou `parallel sections` diretiva, têm valores indeterminados após a construção. Não atribuídos subobjetos também tem um valor de indeterminado após a construção.

As restrições para o `lastprivate` cláusula são da seguinte maneira:

- Todas as restrições para `private` se aplicam.

- Uma variável com um tipo de classe que é especificado como `lastprivate` deve ter um operador de atribuição de cópia acessível inequívoca.

- Variáveis que são particulares dentro de uma região paralela ou que aparecem na `reduction` cláusula de uma `parallel` diretiva não pode ser especificada em uma `lastprivate` cláusula em uma diretiva de compartilhamento de trabalho que está associado a construção parallel.

#### <a name="2724-shared"></a>2.7.2.4 shared

Essa cláusula compartilha as variáveis que aparecem na *lista variável* entre todos os threads em uma equipe. Todos os threads em uma equipe de acessem a área de armazenamento para `shared` variáveis.

A sintaxe do `shared` cláusula é da seguinte maneira:

```cpp
shared(variable-list)
```

#### <a name="2725-default"></a>2.7.2.5 default

O `default` cláusula permite que o usuário afetar os atributos de compartilhamento de dados de variáveis. A sintaxe do `default` cláusula é da seguinte maneira:

```cpp
default(shared | none)
```

Especificando `default(shared)` é equivalente a listando explicitamente cada variável visível no momento em um `shared` cláusula, a menos que ele seja `threadprivate` ou `const`-qualificado. Na ausência de um explícito `default` cláusula, o comportamento padrão é o mesmo que se `default(shared)` foram especificadas.

Especificando `default(none)` requer que pelo menos um dos seguintes deve ser verdadeiro para todas as referências a uma variável na extensão de léxico da construção paralela:

- A variável é listada explicitamente em uma cláusula de atributo de compartilhamento de dados de uma construção que contém a referência.

- A variável é declarada dentro a construção parallel.

- A variável é `threadprivate`.

- A variável tem um `const`-qualificado do tipo.

- A variável é a variável de controle de loop para um `for` loop que segue imediatamente uma `for` ou `parallel for` diretiva e a referência de variável é exibida dentro do loop.

Especificando uma variável em uma `firstprivate`, `lastprivate`, ou `reduction` cláusula de uma diretiva incluída faz com que uma referência implícita a variável no contexto do delimitador. Essas referências implícitas também estão sujeitos aos requisitos listados acima.

Um único `default` cláusula pode ser especificada em um `parallel` diretiva.

Padrão de uma variável atributo de compartilhamento de dados pode ser substituído usando o `private`, `firstprivate`, `lastprivate`, `reduction`, e `shared` cláusulas, como demonstrado pelo exemplo a seguir:

```cpp
#pragma  omp  parallel  for  default(shared)  firstprivate(i)\
   private(x)  private(r)  lastprivate(i)
```

#### <a name="2726-reduction"></a>2.7.2.6 reduction

Essa cláusula executa uma redução nas variáveis escalares que aparecem no *variável-list*, com o operador *op*. A sintaxe do `reduction` cláusula é da seguinte maneira:

`reduction(` *op* `:` *variable-list* `)`

Uma redução geralmente é especificada para uma instrução com uma das seguintes formas:

- *x* `=` *x* *op* *expr*
- *x* *binop* `=` *expr*
- *x* `=` *expr* *op* *x* (com exceção de subtração)
- *x* `++`
- `++` *x*
- *x* `--`
- `--` *x*

em que:

*x*<br/>
Uma das variáveis de redução especificadas na lista.

*variable-list*<br/>
Uma lista separada por vírgulas de variáveis de redução escalar.

*expr*<br/>
Uma expressão com um tipo escalar que não faz referência a *x*.

*op*<br/>
Não é um operador sobrecarregado, mas um dos `+`, `*`, `-`, `&`, `^`, `|`, `&&`, ou `||`.

*binop*<br/>
Não é um operador sobrecarregado, mas um dos `+`, `*`, `-`, `&`, `^`, ou `|`.

A seguir está um exemplo de como o `reduction` cláusula:

```cpp
#pragma omp parallel for reduction(+: a, y) reduction(||: am)
for (i=0; i<n; i++) {
   a += b[i];
   y = sum(y, c[i]);
   am = am || b[i] == c[i];
}
```

Conforme mostrado no exemplo, um operador pode estar oculto dentro de uma chamada de função. O usuário deve ter cuidado que o operador especificado no `reduction` cláusula coincide com a operação de redução.

Embora o operando direito do `||` operador não tem efeitos colaterais neste exemplo, eles são permitidos, mas devem ser usados com cuidado. Nesse contexto, um efeito colateral que tem garantia de não ocorrem durante a execução sequencial do loop pode ocorrer durante a execução paralela. Essa diferença pode ocorrer porque a ordem de execução das iterações é indeterminada.

O operador é usado para determinar o valor inicial de quaisquer variáveis privadas usadas pelo compilador para a redução de e para determinar o operador de finalização. Especificar explicitamente o operador permite que a instrução de redução para estar fora a extensão de léxica da construção. Qualquer número de `reduction` cláusulas podem ser especificadas na diretiva, mas uma variável pode aparecer no máximo um `reduction` cláusula para essa diretiva.

Uma cópia privada de cada variável *variável-list* é criado, um para cada thread, como se o `private` cláusula tivesse sido usada. A cópia particular é inicializada de acordo com o operador (consulte a tabela a seguir).

No final da região para o qual o `reduction` cláusula foi especificada, o objeto original é atualizado para refletir o resultado da combinação de seu valor original com o valor final de cada uma das cópias privadas usando o operador especificado. Os operadores de redução são associativos tudo (exceto para subtração) e o compilador pode livremente reassociar o cálculo do valor final. (Os resultados parciais de uma redução de subtração são adicionados para formar o valor final).

O valor do objeto original se torna indeterminado quando o primeiro thread atinge a cláusula recipiente e permanece isso até que o cálculo de redução for concluído.  Normalmente, o cálculo será concluído no final da construção; No entanto, se o `reduction` cláusula é usada em uma construção que `nowait` é também é aplicado, o valor do objeto original permanece indeterminado até que uma sincronização de barreira foi executada para garantir que todos os threads concluiu a `reduction`cláusula.

A tabela a seguir lista os operadores que são válidos e seus valores de inicialização canônico. O valor de inicialização real será consistente com o tipo de dados da variável de redução.

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

As restrições para o `reduction` cláusula são da seguinte maneira:

- O tipo das variáveis de `reduction` cláusula deve ser válida para o operador de redução, exceto que os tipos de ponteiro e tipos de referência nunca são permitidos.

- Uma variável que é especificada na `reduction` cláusula não deve ser `const`-qualificado.

- Variáveis que são particulares dentro de uma região paralela ou que aparecem na `reduction` cláusula de uma `parallel` diretiva não pode ser especificada em uma `reduction` cláusula em uma diretiva de compartilhamento de trabalho que está associado a construção parallel.

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

O `copyin` cláusula fornece um mecanismo para atribuir o mesmo valor para `threadprivate` variáveis para cada thread em que a equipe a região paralela em execução. Para cada variável especificada em um `copyin` cláusula, o valor da variável no thread principal da equipe é copiada, como se por atribuição às cópias privadas de thread no início da região paralela. A sintaxe do `copyin` cláusula é da seguinte maneira:

```cpp

copyin(
variable-list
)
```

As restrições para o `copyin` cláusula são da seguinte maneira:

- Uma variável que é especificada no `copyin` cláusula deve ter um operador de atribuição de cópia acessível inequívoca.

- Uma variável que é especificada na `copyin` cláusula deve ser um `threadprivate` variável.

#### <a name="2728-copyprivate"></a>2.7.2.8 copyprivate

O `copyprivate` cláusula fornece um mecanismo para usar uma variável particular para transmitir um valor de um membro de uma equipe para os outros membros. É uma alternativa ao uso de uma variável compartilhada para o valor ao fornecimento de uma variável compartilhada como seria difícil (por exemplo, em uma necessidade de uma variável diferente em cada nível de recursão). O `copyprivate` cláusula só pode aparecer no `single` diretiva.

A sintaxe do `copyprivate` cláusula é da seguinte maneira:

```cpp

copyprivate(
variable-list
)
```

O efeito do `copyprivate` cláusula nas variáveis em sua lista de variável ocorre após a execução do bloco estruturado associado com o `single` construir, e antes de qualquer um dos threads na equipe tenha deixado a barreira no final da construção. Em seguida, em todos os outros threads da equipe, para cada variável na *lista variável*, essa variável se torna definida (como se por atribuição) com o valor da variável no thread que executou a construção do estruturado bloco.

Restrições para o `copyprivate` cláusula são da seguinte maneira:

- Uma variável que é especificada na `copyprivate` cláusula não pode aparecer em uma `private` ou `firstprivate` cláusula para o mesmo `single` diretiva.

- Se um `single` diretiva com um `copyprivate` cláusula for encontrada na extensão dinâmica de uma região paralela, todas as variáveis especificadas no `copyprivate` cláusula deve ser private em contexto delimitador.

- Uma variável que é especificada no `copyprivate` cláusula deve ter um operador de atribuição de cópia não ambígua acessível.

## <a name="28-directive-binding"></a>2.8 associação de diretiva

Associação dinâmica de diretivas deve cumprir as regras a seguir:

- O `for`, `sections`, `single`, `master`, e `barrier` diretivas associar dinamicamente delimitador `parallel`, se houver, independentemente do valor de qualquer `if` cláusula que pode estar presente em que diretiva. Se nenhuma região paralela está sendo executada no momento, as diretivas são executadas por uma equipe composta de apenas o thread mestre.

- O `ordered` diretiva vincula a dinamicamente delimitador `for`.

- O `atomic` diretiva garante o acesso exclusivo com relação ao `atomic` diretivas em todos os threads, não apenas a equipe atual.

- O `critical` diretiva garante o acesso exclusivo com relação ao `critical` diretivas em todos os threads, não apenas a equipe atual.

- Uma diretiva nunca pode vincular dinamicamente para qualquer uma das diretivas fora o mais próximo circunscrição `parallel`.

## <a name="29-directive-nesting"></a>2.9 aninhamento de diretiva

Aninhamento dinâmico das diretivas deve cumprir as regras a seguir:

- Um `parallel` diretiva dinamicamente dentro de outro `parallel` logicamente estabelece uma nova equipe é composta de apenas o thread atual, exceto se aninhados paralelismo está habilitada.

- `for`, `sections`, e `single` diretivas que se associam à mesma `parallel` não podem ser aninhados dentro uns aos outros.

- `critical` diretivas com o mesmo nome não podem ser aninhados dentro uns aos outros. Observe que essa restrição não é suficiente para evitar o deadlock.

- `for`, `sections`, e `single` diretivas não são permitidas na extensão de dinâmico `critical`, `ordered`, e `master` regiões se as diretivas que se associar à mesma `parallel` como as regiões.

- `barrier` diretivas não são permitidas na extensão do dynamic `for`, `ordered`, `sections`, `single`, `master`, e `critical` regiões se as diretivas que se associar à mesma `parallel` como as regiões.

- `master` diretivas não são permitidas na extensão de dinâmico `for`, `sections`, e `single` diretivas se o `master` diretivas associar ao mesmo `parallel` como as diretivas de compartilhamento de trabalho.

- `ordered` diretivas não são permitidas na extensão do dynamic `critical` regiões se as diretivas que se associar à mesma `parallel` como as regiões.

- Qualquer uma das diretivas que é permitida quando executado dinamicamente dentro de uma região parallel também é permitida quando executado fora de uma região paralela. Quando executado dinamicamente fora de uma região paralela especificada pelo usuário, a diretiva é executada por uma equipe composta de apenas o thread mestre.
