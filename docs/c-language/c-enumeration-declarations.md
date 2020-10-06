---
title: Declarações de enumeração C
description: Declarações de enumeração na linguagem de programação C.
ms.date: 10/02/2020
helpviewer_keywords:
- declarations, enumerations
- define directive (#define), alternative to
- enumerators, declaring
- '#define directive, alternative to'
- named constants, enumeration declarations
- declaring enumerations
ms.assetid: bd18f673-4dda-4bc1-92fd-d1ce10074910
ms.openlocfilehash: b7df41475a630b9f6e1d735f5454f6d9601cdd16
ms.sourcegitcommit: 30792632548d1c71894f9fecbe2f554294b86020
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/06/2020
ms.locfileid: "91765210"
---
# <a name="c-enumeration-declarations"></a>Declarações de enumeração C

Uma enumeração consiste em um conjunto de constantes de número inteiro nomeadas. Uma declaração de tipo de enumeração fornece o nome da marca de enumeração (opcional). E define o conjunto de identificadores de inteiro nomeados (chamado de *conjunto de enumeração*, *constantes de enumerador*, *enumeradores*ou *Membros*). Uma variável do tipo de enumeração armazena um dos valores do conjunto de enumeração definido por esse tipo.

Variáveis do **`enum`** tipo podem ser usadas em expressões de indexação e como operandos de todos os operadores aritméticos e relacionais. As enumerações fornecem uma alternativa à política de pré-processador de `#define` com a vantagem de que os valores podem ser gerados para você e obedecer regras normais de escopo.

No ANSI C, as expressões que definem o valor de uma constante de enumerador sempre têm o **`int`** tipo. Isso significa que o armazenamento associado a uma variável de enumeração é o armazenamento necessário para um único **`int`** valor. Uma constante de enumeração ou um valor do tipo enumerado podem ser usados em qualquer lugar em que a linguagem C permita uma expressão de inteiro.

## <a name="syntax"></a>Sintaxe

*`enum-specifier`*:\
&emsp;**`enum`***`identifier`* <sub>opt</sub> **`{`** aceitar *`enumerator-list`***`}`**\
&emsp;**`enum`** *`identifier`*

*`enumerator-list`*:\
&emsp;*`enumerator`*\
&emsp;*`enumerator-list`* **`,`** *`enumerator`*

*`enumerator`*:\
&emsp;*`enumeration-constant`*\
&emsp;*`enumeration-constant`* **`=`** *`constant-expression`*

*`enumeration-constant`*:\
&emsp;*`identifier`*

Os nomes opcionais *`identifier`* do tipo de enumeração definido por *`enumerator-list`* . Esse identificador é geralmente chamado de a "marca" de enumeração especificada pela lista. Um especificador de tipo declara `identifier` ser a marca da enumeração especificada pelo não *`enumerator-list`* terminal, como visto aqui:

```C
enum identifier
{
    // enumerator-list
}
```

O *`enumerator-list`* define os membros do conjunto de enumeração.

Se a declaração de uma marca estiver visível, as declarações posteriores que usam a marca, mas omitam, *`enumerator-list`* especificam o tipo enumerado declarado anteriormente. A marca deve se referir a um tipo definido da enumeração, e esse tipo de enumeração deve estar no escopo atual. Como o tipo de enumeração é definido em outro lugar, o *`enumerator-list`* não aparece nessa declaração. Declarações de tipos derivados de enumerações e **`typedef`** declarações para tipos de enumeração podem usar a marca de enumeração antes que o tipo de enumeração seja definido.

Cada *`enumeration-constant`* *`enumerator-list`* um deles nomeia um valor do conjunto de enumeração. Por padrão, a primeira *`enumeration-constant`* é associada ao valor 0. O próximo *`enumeration-constant`* na lista é associado ao valor de ( *`constant-expression`* + 1), a menos que você o associe explicitamente a outro valor. O nome de um *`enumeration-constant`* é equivalente ao seu valor.

Você pode usar *`enumeration-constant`*  =  *`constant-expression`* para substituir a sequência padrão de valores. Ou seja, se *`enumeration-constant`*  =  *`constant-expression`* aparecer no *`enumerator-list`* , o *`enumeration-constant`* será associado ao valor fornecido por *`constant-expression`* . O *`constant-expression`* deve ter o **`int`** tipo e pode ser negativo.

As regras a seguir se aplicam aos membros de um conjunto de enumerações:

- Um conjunto de enumerações pode conter valores duplicados de constantes. Por exemplo, você pode associar o valor 0 a dois identificadores diferentes, por exemplo, membros chamados `null` e `zero` , no mesmo conjunto.

- Os identificadores na lista de enumeração devem ser diferentes de outros identificadores no mesmo escopo com a mesma visibilidade. Isso inclui nomes de variáveis e identificadores comuns em outras listas de enumeração.

- As marcas de enumeração obedecem as regras normais de escopo. Elas devem ser distintas de outras marcas de enumerações, estruturas, e união com a mesma visibilidade.

## <a name="examples"></a>Exemplos

Esses exemplos ilustram declarações de enumeração:

```C
enum DAY            /* Defines an enumeration type    */
{
    saturday,       /* Names day and declares a       */
    sunday = 0,     /* variable named workday with    */
    monday,         /* that type                      */
    tuesday,
    wednesday,      /* wednesday is associated with 3 */
    thursday,
    friday
} workday;
```

O valor 0 é associado a `saturday` por padrão. O identificador `sunday` é explicitamente definido como 0. Os identificadores restantes recebem valores de 1 a 5 por padrão.

Neste exemplo, um valor do conjunto `DAY` é atribuído à variável `today`.

```C
enum DAY today = wednesday;
```

O nome da constante de enumeração é usado para atribuir o valor. Como o tipo de enumeração `DAY` foi declarado anteriormente, somente a marca de enumeração `DAY` é necessária.

Para atribuir explicitamente um valor inteiro a uma variável de tipo de dados enumerado, use uma conversão de tipo:

```C
workday = ( enum DAY ) ( day_value - 1 );
```

Essa conversão é recomendada em C, mas não é necessária.

```C
enum BOOLEAN  /* Declares an enumeration data type called BOOLEAN */
{
    false,     /* false = 0, true = 1 */
    true
};

enum BOOLEAN end_flag, match_flag; /* Two variables of type BOOLEAN */
```

Essa declaração também pode ser especificada como

```C
enum BOOLEAN { false, true } end_flag, match_flag;\
```

ou como

```C
enum BOOLEAN { false, true } end_flag;
enum BOOLEAN match_flag;
```

Um exemplo que usa essas variáveis pode ter esta aparência:

```C
if ( match_flag == false )
    {
     .
     .   /* statement */
     .
    }
    end_flag = true;
```

Os tipos de dados de enumerador sem nome também podem ser declarados. O nome do tipo de dados é omitido, mas as variáveis podem ser declaradas. A variável `response` é uma variável de tipo definida:

```C
enum { yes, no } response;
```

## <a name="see-also"></a>Confira também

[Enumerações](../cpp/enumerations-cpp.md)
