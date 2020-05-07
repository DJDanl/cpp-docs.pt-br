---
title: Operadores relacionais e de igualdade C
ms.date: 10/18/2018
helpviewer_keywords:
- relational operators, syntax
- equality operator
- operators [C], equality
- equality operator, syntax
- operators [C], relational
ms.assetid: c89a3815-a65e-4e0d-8333-0e8dc7fdb30b
ms.openlocfilehash: 25e9bb65492e0c4b100ecd7a800491d238b1dd38
ms.sourcegitcommit: 8bb2bea1384b290b7570b01608a86c7488ae7a02
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2019
ms.locfileid: "67400526"
---
# <a name="c-relational-and-equality-operators"></a>Operadores relacionais e de igualdade C

Os operadores relacionais binários e de igualdade comparam o primeiro operando ao segundo operando para testar a validade da relação especificada. O resultado de uma expressão relacional é 1 se a relação testada for verdadeira e 0 se for falsa. O tipo de resultado é `int`.

**Sintaxe**

*expressão relacional*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*shift-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**&lt;** *expressão de alternância* de *expressão relacional*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**>** *expressão de alternância* de *expressão relacional*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de alternância* de *expressão* ** &lt; ** relacional<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**>=** *expressão de alternância* de *expressão relacional*

*equality-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*relational-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**==** *expressão relacional de* *expressão de igualdade*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*equality-expression* **!=** *relational-expression*

Os operadores relacionais e de igualdade testam as seguintes relações:

|Operador|Relação testada|
|--------------|-------------------------|
|**&lt;**|Primeiro operando menor que o segundo operando|
|**>**|Primeiro operando maior que o segundo operando|
|**&lt;=**|Primeiro operando menor ou igual ao segundo operando|
|**>=**|Primeiro operando maior ou igual ao segundo operando|
|**==**|Primeiro operando igual ao segundo operando|
|**!=**|Primeiro operando não é igual ao segundo operando|

Os primeiros quatro operadores na lista acima têm alta prioridade quanto aos operadores de igualdade (`==` e `!=`). Consulte as informações de precedência na tabela [Precedência e associatividade dos operadores de C](../c-language/precedence-and-order-of-evaluation.md).

Os operandos podem ter o tipo integral, flutuação ou ponteiro. Os tipos dos operandos podem ser diferentes. Os operadores relacionais executam as conversões aritméticas comuns em operandos do tipo integral ou flutuação. Além disso, você pode usar as seguintes combinações de tipos de operando com os operadores relacionais e de igualdade:

- Ambos os operandos de qualquer operador relacional ou de igualdade podem ser ponteiros para o mesmo tipo. Para os operadores de igualdade (`==`) e de desigualdade (`!=`), o resultado da comparação indica se os dois ponteiros endereçam o mesmo local da memória. Para os outros operadores relacionais (**\<**, **>**, **\<**=, e **>**=), o resultado da comparação indica a posição relativa dos dois endereços de memória dos objetos apontados. Os operadores relacionais são apenas deslocamentos.

   A comparação do ponteiro é definida apenas para partes do mesmo objeto. Se os ponteiros fizerem referência aos membros de uma matriz, uma comparação é equivalente à comparação dos subscritos correspondentes. O endereço do primeiro elemento da matriz é "menor que" o endereço do último elemento. No caso de estruturas, os ponteiros para os membros da estrutura declarados posteriormente são ponteiros "maiores que" para os membros declarados anteriormente na estrutura. Os ponteiros para os membros da mesma união são iguais.

- Um valor de ponteiro pode ser comparado ao valor da constante 0 para igualdade (`==`) ou desigualdade (`!=`). Um ponteiro com um valor de 0 é chamado de ponteiro "nulo"; ou seja, ele não aponta para um local de memória válido.

- Os operadores de igualdade seguem as mesmas regras dos operadores relacionais, mas permitem possibilidades adicionais: um ponteiro poderá ser comparado a uma expressão integral constante com o valor 0 ou um ponteiro para `void`. Se os dois ponteiros forem nulos, eles serão comparados como iguais. Os operadores de igualdade comparam o segmento e o deslocamento.

## <a name="examples"></a>Exemplos

Os exemplos a seguir ilustram os operadores relacionais e de igualdade.

```C
int x = 0, y = 0;
if ( x < y )
```

Como `x` e `y` são iguais, a expressão neste exemplo gera o valor 0.

```C
char array[10];
char *p;

for ( p = array; p < &array[10]; p++ )
    *p = '\0';
```

O fragmento neste exemplo define cada elemento de `array` como uma constante de caractere nulo.

```C
enum color { red, white, green } col;
   .
   .
   .
   if ( col == red )
   .
   .
   .
```

Essas instruções declaram uma variável de enumeração chamada `col` com a marca `color`. A qualquer momento, a variável pode conter um valor inteiro de 0, 1, ou 2, que representa um dos elementos do conjunto de enumeração `color`: a cor vermelha, branca ou verde, respectivamente. Se `col` contiver 0 quando a instrução **if** for executada, todas as instruções dependentes de **if** serão executadas.

## <a name="see-also"></a>Confira também

[Operadores relacionais: \<, >, \<= e >=](../cpp/relational-operators-equal-and-equal.md)<br/>
[Operadores de igualdade: == e !=](../cpp/equality-operators-equal-equal-and-exclpt-equal.md)
