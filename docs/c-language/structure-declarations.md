---
title: Declarações de estrutura
ms.date: 11/04/2016
helpviewer_keywords:
- structure declarations
- anonymous structures
- types [C], declarations
- structure members
- embedded structures
ms.assetid: 5be3be77-a236-4153-b574-7aa77675df7f
ms.openlocfilehash: a17bb996f13fdbe11bb569c8af5669a9d0c5363f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62157782"
---
# <a name="structure-declarations"></a>Declarações de estrutura

Uma "declaração de estrutura" nomeia um tipo e especifica uma sequência de valores variáveis (chamados de "membros" ou "campos" da estrutura) que podem ter tipos diferentes. Um identificador opcional, chamado de "marca", fornece o nome do tipo de estrutura e pode ser usado em referências subsequentes ao tipo. Uma variável desse tipo de estrutura mantém a sequência inteira definida por esse tipo. As estruturas em C são semelhantes aos tipos conhecidos como "registros" em outras linguagens.

## <a name="syntax"></a>Sintaxe

*especificador de struct-ou-Union*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador struct-or-Union* *identifier*<sub>opt</sub> **{** *struct-declaração-List* **}**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*struct-or-union* *identifier*

*struct-or-union*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**struct**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**unida**

*struct-declaration-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração de struct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*struct-declaration-list* *struct-declaration*

*declaração de struct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*specifier-qualifier-list* *struct-declarator-list* **;**

*specifier-qualifier-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *specifier-qualifier-list*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *specifier-qualifier-list*<sub>opt</sub>

*struct-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;struct *-* Declarador *struct-declarator-List* **,** *struct-declarator*

*estrutura-declaradora*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*tipo de* *Declarador*de especificador<sub>opt</sub> **:** *expressão Constant*

A declaração de um tipo de estrutura não reserva espaço para uma estrutura. É apenas um modelo para declarações posteriores de variáveis da estrutura.

Um *identifier* (marca) definido anteriormente pode ser usado para fazer referência a um tipo de estrutura definido em outro lugar. Nesse caso, *struct-declaration-list* não poderá ser repetida enquanto a definição estiver visível. Declarações de ponteiros para estruturas e typedefs de tipos de estrutura podem usar a marca de estrutura antes que o tipo de estrutura seja definido. No entanto, a definição da estrutura deve ser encontrada antes de qualquer uso real do tamanho dos campos. Essa é uma definição incompleta do tipo e da marca de tipo. Para que essa definição fique completa, uma definição de tipo deve aparecer depois no mesmo escopo.

A *struct-declaration-list* especifica os tipos e nomes dos membros da estrutura. Um argumento *struct-declaration-list* contém uma ou mais declarações de variável ou de campo de bits.

Cada variável declarada em *struct-declaration-list* é definida como um membro do tipo de estrutura. As declarações de variáveis em *struct-declaration-list* têm o mesmo formato que outras declarações de variável abordadas nesta seção, com exceção de que as declarações não podem conter inicializadores nem especificadores de classe de armazenamento. Os membros da estrutura podem ter qualquer tipo de variável, exceto o tipo `void`, um tipo incompleto ou um tipo de função.

Um membro não pode ser declarado para ter o tipo da estrutura em que aparece. Porém, um membro pode ser declarado como um ponteiro para o tipo de estrutura em que aparece, desde que o tipo tenha uma marca. Isso permite criar listas vinculadas de estruturas.

As estruturas seguem o mesmo escopo que outros identificadores. Os identificadores de estruturas devem ser distintos de outras marcas de estrutura, união e enumeração com a mesma visibilidade.

Cada *struct-declaration* em uma *struct-declaration-list* deve ser exclusivo na lista. No entanto, os nomes de identificadores em uma *struct-declaration-list* não precisam ser distintos de nomes de variáveis comuns ou de identificadores em outras listas de declarações de estrutura.

Também é possível acessar estruturas aninhadas como se fossem declaradas no nível do escopo do arquivo. Por exemplo, dada esta declaração:

```C
struct a
{
    int x;
    struct b
    {
      int y;
    } var2;
} var1;
```

estas duas declarações são válidas:

```C
struct a var3;
struct b var4;
```

## <a name="examples"></a>Exemplos

Estes exemplos ilustram declarações de estruturas:

```C
struct employee   /* Defines a structure variable named temp */
{
    char name[20];
    int id;
    long class;
} temp;
```

A estrutura `employee` tem três membros: `name`, `id` e `class`. O membro `name` é uma matriz de 20 elementos e `id` e `class` são membros simples com o tipo `int` e **long**, respectivamente. O identificador `employee` é o identificador da estrutura.

```C
struct employee student, faculty, staff;
```

Esse exemplo define três variáveis de estrutura: `student`, `faculty` e `staff`. Cada estrutura tem a mesma lista de três membros. Os membros são declarados para ter o tipo de estrutura `employee`, definido no exemplo anterior.

```C
struct           /* Defines an anonymous struct and a */
{                /* structure variable named complex  */
    float x, y;
} complex;
```

A estrutura `complex` tem dois membros do tipo **float**, `x` e `y`. O tipo de estrutura não tem marcas e, portanto, é não nomeado ou anônimo.

```C
struct sample   /* Defines a structure named x */
{
    char c;
    float *pf;
    struct sample *next;
} x;
```

Os dois primeiros membros da estrutura são uma variável `char` e um ponteiro para um valor **float**. O terceiro membro, `next`, é declarado como um ponteiro para o tipo de estrutura que está sendo definido (`sample`).

As estruturas anônimas podem ser úteis quando a marca nomeada não é necessária. Esse é o caso quando uma declaração define todas as instâncias da estrutura. Por exemplo: 

```C
struct
{
    int x;
    int y;
} mystruct;
```

As estruturas inseridas são frequentemente anônimas.

```C
struct somestruct
{
    struct    /* Anonymous structure */
    {
        int x, y;
    } point;
    int type;
} w;
```

**Específico da Microsoft**

O compilador permite uma matriz não dimensionada ou de tamanho zero como o último membro de uma estrutura. Isso poderá ser útil se uma matriz constante tiver tamanhos diferentes quando usada em situações variadas. A declaração de uma estrutura assim é semelhante a esta:

**identificador struct** *identifier* **{** *conjunto de declarações* *tipo* <em>array-Name</em>**\[];};**

As matrizes não dimensionadas só podem aparecer como o último membro de uma estrutura. As estruturas que contêm declarações de matrizes não dimensionadas podem ser aninhadas em outras estruturas, desde que nenhum membro adicional seja declarado em nenhuma das estruturas de inclusão. Matrizes dessas estruturas não são permitidas. O operador `sizeof`, quando aplicado a uma variável desse tipo ou ao próprio tipo, pressupõe 0 como o tamanho da matriz.

Declarações de estruturas também podem ser especificadas sem um declarador quando são membros de outra estrutura ou união. Os nomes de campos são promovidos na estrutura de inclusão. Por exemplo, uma estrutura sem nome tem aparência semelhante a esta:

```C
struct s
{
    float y;
    struct
    {
        int a, b, c;
    };
    char str[10];
} *p_s;
.
.
.
p_s->b = 100;  /* A reference to a field in the s structure */
```

Consulte [Membros de estruturas e uniões](../c-language/structure-and-union-members.md) para obter informações sobre referências de estrutura.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Declaradores e declarações variáveis](../c-language/declarators-and-variable-declarations.md)
