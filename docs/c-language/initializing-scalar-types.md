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
ms.openlocfilehash: 063761abcbb1541893b9cbab463e3d121684d00a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211821"
---
# <a name="initializing-scalar-types"></a>Inicializando tipos escalares

Ao inicializar tipos escalares, o valor de *`assignment-expression`* é atribuído à variável. As regras de conversão para a atribuição se aplicam. (Consulte [Conversões de tipos](../c-language/type-conversions-c.md) para obter informações sobre regras de conversão.)

## <a name="syntax"></a>Sintaxe

*`declaration`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declaration-specifiers`**`init-declarator-list`* <sub>aceitar</sub>**`;`**

*`declaration-specifiers`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`storage-class-specifier`**`declaration-specifiers`* <sub>aceitar</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-specifier`**`declaration-specifiers`* <sub>aceitar</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-qualifier`**`declaration-specifiers`* <sub>aceitar</sub>

*`init-declarator-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`init-declarator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`init-declarator-list`* **`,`** *`init-declarator`*

*`init-declarator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declarator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declarator`***`=`** *`initializer`* /\* Para inicialização escalar\*/

*`initializer`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`assignment-expression`*

Você pode inicializar variáveis de qualquer tipo, desde que obedeça às seguintes regras:

- Variáveis declaradas no nível de escopo de arquivo podem ser inicializadas. Se você não inicializar uma variável explicitamente no nível externo, ela será inicializada como 0 por padrão.

- Uma expressão constante pode ser usada para inicializar qualquer variável global declarada com o **`static`** *`storage-class-specifier`* . Variáveis declaradas para serem **`static`** inicializadas quando a execução do programa é iniciada. Se você não inicializar explicitamente uma variável global **`static`** , ela será inicializada como 0 por padrão e todos os membros que tiverem o tipo de ponteiro receberão um ponteiro nulo.

- Variáveis declaradas com o **`auto`** **`register`** especificador de classe de armazenamento ou são inicializadas cada vez que o controle de execução passa para o bloco no qual elas são declaradas. Se você omitir um inicializador da declaração de **`auto`** uma **`register`** variável ou, o valor inicial da variável será indefinido. Para valores automáticos e de registro, o inicializador não está restrito a ser uma constante; ele pode ser qualquer expressão que envolva valores definidos anteriormente, inclusive chamadas de função.

- Os valores iniciais para declarações de variáveis externas e para todas as **`static`** variáveis, sejam elas externas ou internas, devem ser expressões constantes. (Para obter mais informações, consulte [expressões constantes](../c-language/c-constant-expressions.md).) Como o endereço de qualquer variável estática ou declarada externamente é constante, ele pode ser usado para inicializar uma variável de ponteiro declarada internamente **`static`** . No entanto, o endereço de uma **`auto`** variável não pode ser usado como um inicializador estático porque pode ser diferente para cada execução do bloco. Você pode usar valores constantes ou variáveis para inicializar **`auto`** e **`register`** variáveis.

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

Este exemplo usa uma expressão constante `(3 * 1024)` para inicializar `c` um valor constante que não pode ser modificado devido à **`const`** palavra-chave.

```C
int *b = &x;
```

Essa instrução inicializa o ponteiro `b` com o endereço de outra variável, `x`.

```C
int *const a = &z;
```

O ponteiro `a` é inicializado com o endereço de uma variável nomeada `z`. No entanto, como ele é especificado para ser um **`const`** , a variável `a` só pode ser inicializada, nunca modificada. Ela sempre aponta para o mesmo local.

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

A variável global `GLOBAL` é declarada no nível externo e, por isso, tem tempo de vida global. A variável local `LOCAL` tem a **`auto`** classe de armazenamento e só tem um endereço durante a execução da função na qual ela é declarada. Portanto, **`static`** não é permitido tentar inicializar a variável `lp` de ponteiro com o endereço de `LOCAL` . A **`static`** variável `gp` de ponteiro pode ser inicializada para o endereço de `GLOBAL` porque esse endereço é sempre o mesmo. Da mesma forma, `*rp` pode ser inicializado porque `rp` é uma variável local e pode ter um inicializador não constante. Cada vez que se entra no bloco, `LOCAL` tem um novo endereço, que é então atribuído a `rp`.

## <a name="see-also"></a>Confira também

[Initialization](../c-language/initialization.md)
