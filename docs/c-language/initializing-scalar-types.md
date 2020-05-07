---
title: Inicializando tipos escalares
ms.date: 11/04/2016
helpviewer_keywords:
- initializing scalar types
- register variables
- initialization, scalar types
- initializing variables, scalar types
- scalar types
- static variables, initializing
- automatic storage class, initializing scalar types
- automatic storage class
- types [C], initializing
ms.assetid: 73c516f5-c3ad-4d56-ab3b-f2a82b621104
ms.openlocfilehash: 3cf7eddcf43a65a787de60c391863d6471be7bcf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62232937"
---
# <a name="initializing-scalar-types"></a>Inicializando tipos escalares

Ao inicializar tipos escalares, o valor de *assignment-expression* é atribuído à variável. As regras de conversão para a atribuição se aplicam. (Consulte [Conversões de tipos](../c-language/type-conversions-c.md) para obter informações sobre regras de conversão.)

## <a name="syntax"></a>Sintaxe

*declaração*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers* *init-declarator-list*<sub>opt</sub> **;**

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*init-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-declarator-List* **,** *init-declarator*

*init-Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;\* *inicializador* **=**  / de *Declarador* para inicialização escalar\*/

*inicializador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de atribuição*

Você pode inicializar variáveis de qualquer tipo, desde que obedeça às seguintes regras:

- Variáveis declaradas no nível de escopo de arquivo podem ser inicializadas. Se você não inicializar uma variável explicitamente no nível externo, ela será inicializada como 0 por padrão.

- Uma expressão de constante pode ser usada para inicializar qualquer variável global declarada com o **static** *storage-class-specifier*. Variáveis declaradas para serem **static** são inicializadas quando a execução do programa começa. Se você não inicializar uma variável **static** global explicitamente, ela será inicializada como 0 por padrão; além disso, a cada membro que tiver o tipo ponteiro será atribuído um ponteiro nulo.

- Variáveis declaradas com o especificador de classe de armazenamento **auto** ou **register** são inicializadas cada vez que o controle da execução passa para o bloco em que são declaradas. Se você omitir um inicializador da declaração de uma variável **auto** ou **register**, o valor inicial da variável será indefinido. Para valores automáticos e de registro, o inicializador não está restrito a ser uma constante; ele pode ser qualquer expressão que envolva valores definidos anteriormente, inclusive chamadas de função.

- Os valores iniciais para declarações de variáveis externas e para todas as variáveis **static**, sejam externas ou internas, devem ser expressões de constantes. (Para obter mais informações, consulte [expressões constantes](../c-language/c-constant-expressions.md).) Como o endereço de qualquer variável estática ou declarada externamente é constante, ele pode ser usado para inicializar uma variável de ponteiro **estático** internamente declarada. No entanto, o endereço de uma variável **auto** não pode ser usado como um inicializador estático, pois pode ser diferente para cada execução do bloco. Você pode usar valores de constantes ou de variáveis para inicializar as variáveis **auto** e **register**.

- Se a declaração de um identificador tem o escopo do bloco e o identificador tem vinculação externa, a declaração não pode ter uma inicialização.

## <a name="examples"></a>Exemplos

Os exemplos a seguir ilustram inicializações:

```C
int x = 10;
```

A variável de inteiro `x` é inicializada como a expressão de constante `10`.

```C
register int *px = 0;
```

O ponteiro `px` é inicializado como 0, gerando um ponteiro "nulo".

```C
const int c = (3 * 1024);
```

Esse exemplo usa uma expressão de constante `(3 * 1024)` para inicializar `c` como um valor constante que não pode ser modificado devido à palavra-chave **const**.

```C
int *b = &x;
```

Essa instrução inicializa o ponteiro `b` com o endereço de outra variável, `x`.

```C
int *const a = &z;
```

O ponteiro `a` é inicializado com o endereço de uma variável nomeada `z`. No entanto, como é especificada para ser **const**, a variável `a` só pode ser inicializada, nunca modificada. Ela sempre aponta para o mesmo local.

```C
int GLOBAL ;

int function( void )
{
    int LOCAL ;
    static int *lp = &LOCAL;   /* Illegal initialization */
    static int *gp = &GLOBAL;  /* Legal initialization   */
    register int *rp = &LOCAL; /* Legal initialization   */
}
```

A variável global `GLOBAL` é declarada no nível externo e, por isso, tem tempo de vida global. A variável local `LOCAL` tem a classe de armazenamento **auto** e tem apenas um endereço durante a execução da função em que é declarada. Em consequência, não é permitido tentar inicializar a variável de ponteiro **static**`lp` com o endereço de `LOCAL`. A variável de ponteiro **static**`gp` pode ser inicializada como o endereço de `GLOBAL` porque esse endereço é sempre o mesmo. Da mesma forma, `*rp` pode ser inicializada `rp` porque é uma variável local e pode ter um inicializador não constante. Cada vez que se entra no bloco, `LOCAL` tem um novo endereço, que é então atribuído a `rp`.

## <a name="see-also"></a>Confira também

[Initialization](../c-language/initialization.md)
