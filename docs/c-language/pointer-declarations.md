---
title: Declarações de ponteiro
ms.date: 11/04/2016
helpviewer_keywords:
- pointer declarations
- declarations, pointers
- const keyword [C]
- pointers, declarations
ms.assetid: 8b3b7fc7-f44d-480d-b6f9-cebe4e5462a6
ms.openlocfilehash: 31d7e30859537fed1b18f6d30302d83248e17e74
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211756"
---
# <a name="pointer-declarations"></a>Declarações de ponteiro

Uma *declaração de ponteiro* nomeia uma variável de ponteiro e especifica o tipo de objeto para o qual a variável aponta. Uma variável declarada como um ponteiro contém um endereço de memória.

## <a name="syntax"></a>Sintaxe

*Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*Declarador direto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**(** *Declarador* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto* **[** *opt-expressão de constante*<sub>opt</sub> **]**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto* **(** *tipo de parâmetro-lista* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto* **(** *opção identificador-lista*<sub>opt</sub> **)**

*ponteiro*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>\*</strong><sub>opção</sub> *de qualificador de tipo-lista*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>\*</strong><sub>opt</sub> *ponteiro* de *tipo-qualificador de lista de tipos*

*type-qualifier-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*qualificador de tipo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier-list* *type-qualifier*

O *type-specifier* informa o tipo de objeto, que pode ser qualquer tipo básico, de estrutura ou união. As variáveis de ponteiro também podem apontar para funções, matrizes e outros ponteiros. (Para obter informações sobre como declarar e interpretar tipos de ponteiro mais complexos, consulte [Interpretar declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md).)

Ao fazer o *especificador de tipo* **`void`** , você pode atrasar a especificação do tipo ao qual o ponteiro se refere. Esse item é conhecido como "ponteiro para **`void`** " e é escrito como `void *` . Uma variável declarada como um ponteiro para *nulo* pode ser usada para apontar para um objeto de qualquer tipo. No entanto, para realizar a maioria das operações no ponteiro ou no objeto para o qual ele aponta, o tipo para o qual ele aponta deve ser explicitamente especificado para cada operação. (Variáveis do tipo **`char`** <strong>\*</strong> e Type **`void`** <strong>\*</strong> são compatíveis com atribuição sem uma conversão de tipo.) Essa conversão pode ser realizada com uma conversão de tipo (Confira [conversões de conversão de tipo](../c-language/type-cast-conversions.md) para obter mais informações).

O *qualificador de tipo* pode ser **`const`** ou ou **`volatile`** ambos. Eles especificam, respectivamente, que o ponteiro não pode ser modificado pelo próprio programa ( **`const`** ), ou que o ponteiro pode ser modificado legitimamente por algum processo além do controle do programa ( **`volatile`** ). (Consulte [qualificadores de tipo](../c-language/type-qualifiers.md) para obter mais informações sobre **`const`** e **`volatile`** .)

O *declarator* atribui um nome à variável e pode incluir um modificador de tipo. Por exemplo, se o *declarator* representa uma matriz, o tipo do ponteiro é modificado para ser um ponteiro para uma matriz.

Você pode declarar um ponteiro para uma estrutura, união ou tipo de enumeração antes de definir a estrutura, a união ou o tipo de enumeração. Você declara o ponteiro com a marca de estrutura ou de união, conforme mostrado nos exemplos abaixo. Essas declarações são permitidas porque o compilador não precisa saber o tamanho da estrutura ou da união para alocar espaço para a variável de ponteiro.

## <a name="examples"></a>Exemplos

Os exemplos a seguir ilustram as declarações de ponteiro.

```
char *message; /* Declares a pointer variable named message */
```

O ponteiro de *mensagem* aponta para uma variável com o **`char`** tipo.

```
int *pointers[10];  /* Declares an array of pointers */
```

A matriz de *ponteiros* tem 10 elementos; cada elemento é um ponteiro para uma variável com o **`int`** tipo.

```
int (*pointer)[10]; /* Declares a pointer to an array of 10 elements */
```

A variável *pointer* aponta para uma matriz com 10 elementos. Cada elemento nesta matriz tem **`int`** tipo.

```
int const *x;      /* Declares a pointer variable, x,
                      to a constant value */
```

O ponteiro *x* pode ser modificado para apontar para um **`int`** valor diferente, mas o valor para o qual ele aponta não pode ser modificado.

```
const int some_object = 5 ;
int other_object = 37;
int *const y = &fixed_object;
int volatile *const z = &some_object;
int *const volatile w = &some_object;
```

A variável *y* nessas declarações é declarada como um ponteiro constante para um **`int`** valor. O valor para o qual ele aponta pode ser modificado, mas o ponteiro em si deve sempre apontar para o mesmo local: o endereço de *fixed_object*. Da mesma forma, *z* é um ponteiro constante, mas também é declarado para apontar para um **`int`** cujo valor não pode ser modificado pelo programa. O especificador adicional **`volatile`** indica que, embora o valor da **const int** apontada por *z* não possa ser modificado pelo programa, ele pode ser modificado legitimamente por um processo em execução simultaneamente com o programa. A declaração de *w* especifica que o programa não pode alterar o valor para o qual está apontado e que o programa não pode modificar o ponteiro.

```
struct list *next, *previous; /* Uses the tag for list */
```

Este exemplo declara duas variáveis de ponteiro, *next* e *previous*, que apontam para a o tipo de estrutura *list*. Essa declaração pode aparecer antes da definição do tipo de estrutura *list* (consulte o próximo exemplo), desde que a definição de tipo *list* tenha a mesma visibilidade que a declaração.

```
struct list
{
    char *token;
    int count;
    struct list *next;
} line;
```

A variável *line* tem o tipo de estrutura chamado *list*. O tipo de estrutura de *lista* tem três membros: o primeiro membro é um ponteiro para um **`char`** valor, o segundo é um **`int`** valor e o terceiro é um ponteiro para outra estrutura de *lista* .

```
struct id
{
    unsigned int id_no;
    struct name *pname;
} record;
```

O *registro* de variável tem a *ID*de tipo de estrutura. Observe que *pname* é declarado como um ponteiro para outro tipo de estrutura chamado *Name*. Essa declaração pode aparecer antes que o tipo *name* seja definido.

## <a name="see-also"></a>Confira também

[Declaradores e declarações de variáveis](../c-language/declarators-and-variable-declarations.md)
