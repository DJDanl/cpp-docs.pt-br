---
title: Visão geral das declarações
ms.date: 11/04/2016
helpviewer_keywords:
- declarations, about declarations
- type qualifiers
ms.assetid: fcd2364c-c2a5-4fbf-9027-19dac4144cb5
ms.openlocfilehash: 066c0fd307c7562d70c57c31dff23960a6305f2c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217071"
---
# <a name="overview-of-declarations"></a>Visão geral das declarações

Uma "declaração" especifica a interpretação e os atributos de um conjunto de identificadores. Uma declaração que também causa a reserva do armazenamento para o objeto ou a função nomeada pelo identificador é chamada de uma "definição". As declarações de C para variáveis, funções e tipos têm esta sintaxe:

## <a name="syntax"></a>Sintaxe

*`declaration`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declaration-specifiers`* optar por *`attribute-seq`* <sub>aceitar</sub> *`init-declarator-list`* <sub>opt</sub>**`;`**

/\**`attribute-seq`* a <sub>opção opt</sub> é específica da Microsoft */

*`declaration-specifiers`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`storage-class-specifier`**`declaration-specifiers`* <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-specifier`**`declaration-specifiers`* <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-qualifier`**`declaration-specifiers`* <sub>aceitar</sub>

*`init-declarator-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`init-declarator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`init-declarator-list`* **`,`** *`init-declarator`*

*`init-declarator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declarator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declarator`* **`=`** *`initializer`*

> [!NOTE]
> Essa sintaxe para *`declaration`* não é repetida nas seções a seguir. A sintaxe nas seções a seguir geralmente começa com o não *`declarator`* terminal.

As declarações no *`init-declarator-list`* contêm os identificadores que estão sendo nomeados; *`init`* é uma abreviação para o inicializador. O *`init-declarator-list`* é uma sequência de declaradores separados por vírgula, cada um dos quais pode ter informações de tipo adicionais, ou um inicializador, ou ambos. O *`declarator`* contém os identificadores, se houver, que estão sendo declarados. O *`declaration-specifiers`* nonterminal consiste em uma sequência do tipo e especificadores de classe de armazenamento que indicam a ligação, a duração do armazenamento e, pelo menos, parte do tipo das entidades que os declaradores denotam. As declarações são feitas de alguma combinação de especificadores de classe de armazenamento, especificadores de tipo, qualificadores de tipo, declaradores e inicializadores.

Declarações podem conter um ou mais dos atributos opcionais listados em *`attribute-seq`* ; *`seq`* é uma abreviação para Sequence. Esses atributos específicos da Microsoft executam várias funções, que são discutidas em detalhes em todo este livro.

Na forma geral de uma declaração de variável, *`type-specifier`* fornece o tipo de dados da variável. O *`type-specifier`* pode ser um composto, como quando o tipo é modificado por **`const`** ou **`volatile`** . O `declarator` fornece o nome da variável, possivelmente modificado para declarar uma matriz ou um tipo de ponteiro. Por exemplo:

```C
int const *fp;
```

declara uma variável chamada `fp` como um ponteiro para um valor não modificável ( **`const`** ) **`int`** . Você pode definir mais de uma variável em uma declaração usando vários declaradores, separados por vírgulas.

Uma declaração deve ter pelo menos um declarador ou seu especificador de tipo deve declarar uma marca de estrutura, marca de união ou membros de uma enumeração. Os declaradores fornecem toda quaisquer outras informações sobre um identificador. Um Declarador é um identificador que pode ser modificado com colchetes ( **`[ ]`** ), asteriscos ( <strong>`*`</strong> ) ou parênteses ( **`( )`** ) para declarar um tipo de matriz, ponteiro ou função, respectivamente. Quando você declara variáveis simples (como o caractere, inteiro e itens de ponto flutuante), ou estruturas e uniões de variáveis simples, `declarator` é apenas um identificador. Para obter mais informações sobre os declaradores, consulte [Declaradores e declarações de variável](../c-language/declarators-and-variable-declarations.md).

Todas as definições são implicitamente declarações, mas nem todas as declarações são definições. Por exemplo, as declarações de variáveis que começam com o **`extern`** especificador de classe de armazenamento são "referenciando", em vez de "definindo" declarações. Se uma variável externa for referenciada antes de ser definida, ou se ela for definida em outro arquivo de origem daquele em que é usada, uma **`extern`** declaração será necessária. O armazenamento não é alocado "referenciando" declarações, nem as variáveis podem ser inicializados em declarações.

Uma classe de armazenamento ou um tipo (ou ambos) são necessários em declarações de variáveis. Exceto para **`__declspec`** , somente um especificador de classe de armazenamento é permitido em uma declaração e nem todos os especificadores de classe de armazenamento são permitidos em cada contexto. A **`__declspec`** classe de armazenamento é permitida com outros especificadores de classe de armazenamento e é permitida mais de uma vez. O especificador de classe de armazenamento de uma declaração afeta como o item declarado é armazenado e inicializado, e quais partes de um programa podem fazer referência ao item.

Os *`storage-class-specifier`* terminais definidos em C incluem **`auto`** , **`extern`** , **`register`** , **`static`** e **`typedef`** . O Microsoft C também inclui o *`storage-class-specifier`* terminal **`__declspec`** . Todos os *`storage-class-specifier`* terminais exceto **`typedef`** e **`__declspec`** são discutidos em classes de [armazenamento](../c-language/c-storage-classes.md). Para obter informações sobre o **`typedef`** , consulte [ `typedef` declarações](../c-language/typedef-declarations.md). Para obter informações sobre o **`__declspec`** , consulte [atributos de classe de armazenamento estendidos](../c-language/c-extended-storage-class-attributes.md).

O local da declaração no programa de origem e da presença ou ausência de outras instruções da variável são fatores importantes na determinação de diversas variáveis. Pode haver várias redeclarações mas apenas uma definição. No entanto, uma definição pode aparecer em mais de uma unidade de tradução. Para objetos com vinculação interna, esta regra é aplicada separadamente a cada unidade de tradução, pois os objetos internamente vinculados são exclusivos para uma unidade de tradução. Para objetos com vinculação externa, essa regra se aplica ao programa inteiro. Para obter mais informações sobre visibilidade, consulte [tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md).

Os especificadores do tipo fornecem algumas informações sobre os tipos de dados de identificadores. O especificador de tipo padrão é **`int`** . Para obter mais informações, consulte [Especificadores de tipos](../c-language/c-type-specifiers.md). Os especificadores de tipo também podem definir marcas de tipo, estruturas e nomes de componentes da união, além de constantes da enumeração. Para obter mais informações, consulte [declarações de enumeração](../c-language/c-enumeration-declarations.md), declarações de [estrutura](../c-language/structure-declarations.md)e declarações de [União](../c-language/union-declarations.md).

Há dois *`type-qualifier`* terminais: **`const`** e **`volatile`** . Esses qualificadores especificam propriedades adicionais dos tipos que só são relevantes apenas no acesso de objetos desse tipo por valores l. Para obter mais informações sobre o **`const`** e o **`volatile`** , consulte [qualificadores de tipo](../c-language/type-qualifiers.md). Para uma definição de l-values, consulte [Expressões de l-value e r-value](../c-language/l-value-and-r-value-expressions.md).

## <a name="see-also"></a>Confira também

[Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md)<br/>
[Declarações e tipos](../c-language/declarations-and-types.md)<br/>
[Resumo de declarações](../c-language/summary-of-declarations.md)
