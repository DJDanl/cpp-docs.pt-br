---
title: 2.7.2.6 reduction
ms.date: 11/04/2016
ms.assetid: e7630a15-2978-4dbe-a29b-3a46371a0151
ms.openlocfilehash: 54b326feb4e4ccf1f1da5c8152ffc8d1e4bd13b2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456011"
---
# <a name="2726-reduction"></a>2.7.2.6 reduction

Essa cláusula executa uma redução nas variáveis escalares que aparecem no *variável-list*, com o operador *op*. A sintaxe do `reduction` cláusula é da seguinte maneira:

> reduction(*op*: *variable-list*)

Uma redução geralmente é especificada para uma instrução com uma das seguintes formas:

> *x* = *x* *op* *expr*
> *x* *binop* = *expr*
> *x* = *expr* *op* *x* (exceto para subtração) *x*++
> ++*x*
> *x*--
> --*x*

em que:

*x*<br/>
Uma das variáveis de redução especificadas no `list`.

*variable-list*<br/>
Uma lista separada por vírgulas de variáveis de redução escalar.

*expr*<br/>
Uma expressão com um tipo escalar que não faz referência a *x*.

*op*<br/>
Não é um operador sobrecarregado, mas um dos +, &#42;, -, &amp;, ^, &#124;, &amp; &amp;, ou &#124; &#124;.

*binop*<br/>
Não é um operador sobrecarregado, mas um dos +, &#42;, -, &amp;, ^, ou &#124;.

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

Embora o operando direito do &#124; &#124; operador não tem efeitos colaterais neste exemplo, são permitidos, mas deve ser usadas com cuidado. Nesse contexto, um efeito colateral que não é garantido que ocorrem durante a execução sequencial do loop pode ocorrer durante a execução paralela. Essa diferença pode ocorrer porque a ordem de execução das iterações é indeterminada.

O operador é usado para determinar o valor inicial de quaisquer variáveis privadas usadas pelo compilador para a redução de e para determinar o operador de finalização. Especificar explicitamente o operador permite que a instrução de redução para estar fora a extensão de léxica da construção. Qualquer número de `reduction` cláusulas podem ser especificadas na diretiva, mas uma variável pode aparecer no máximo um `reduction` cláusula para essa diretiva.

Uma cópia privada de cada variável *variável-list* é criado, um para cada thread, como se o `private` cláusula tivesse sido usada. A cópia particular é inicializada de acordo com o operador (consulte a tabela a seguir).

No final da região para o qual o `reduction` cláusula foi especificada, o objeto original é atualizado para refletir o resultado da combinação de seu valor original com o valor final de cada uma das cópias privadas usando o operador especificado. Os operadores de redução são associativos tudo (exceto para subtração) e o compilador pode livremente reassociar o cálculo do valor final. (Os resultados parciais de uma redução de subtração são adicionados para formar o valor final).

O valor do objeto original se torna indeterminado quando o primeiro thread atinge a cláusula recipiente e permanece isso até que o cálculo de redução for concluído.  Normalmente, o cálculo será concluído no final da construção; No entanto, se o `reduction` cláusula é usada em uma construção que `nowait` é também é aplicado, o valor do objeto original permanece indeterminado até que uma sincronização de barreira foi executada para garantir que todos os threads concluiu a `reduction`cláusula.

A tabela a seguir lista os operadores que são válidos e seus valores de inicialização canônico. O valor de inicialização real será consistente com o tipo de dados da variável de redução.

|Operador|Inicialização|
|--------------|--------------------|
|+|0|
|&#42;|1|
|-|0|
|&amp;|~0|
|&#124;|0|
|^|0|
|&amp;&amp;|1|
|&#124;&#124;|0|

As restrições para o `reduction` cláusula são da seguinte maneira:

- O tipo das variáveis de `reduction` cláusula deve ser válida para o operador de redução, exceto que os tipos de ponteiro e tipos de referência nunca são permitidos.

- Uma variável que é especificada na `reduction` cláusula não deve ser **const**-qualificado.

- Variáveis que são particulares dentro de uma região paralela ou que aparecem na `reduction` cláusula de uma **paralela** diretiva não pode ser especificada em uma `reduction` cláusula em uma diretiva de compartilhamento de trabalho que está associado a construção parallel.

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
