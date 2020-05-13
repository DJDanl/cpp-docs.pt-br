---
title: Visão geral das declarações
ms.date: 11/04/2016
helpviewer_keywords:
- declarations, about declarations
- type qualifiers
ms.assetid: fcd2364c-c2a5-4fbf-9027-19dac4144cb5
ms.openlocfilehash: 0ffda6522e632533b0aaa4ba146e8fad082ed435
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857054"
---
# <a name="overview-of-declarations"></a>Visão geral das declarações

Uma "declaração" especifica a interpretação e os atributos de um conjunto de identificadores. Uma declaração que também causa a reserva do armazenamento para o objeto ou a função nomeada pelo identificador é chamada de uma "definição". As declarações de C para variáveis, funções e tipos têm esta sintaxe:

## <a name="syntax"></a>Sintaxe

*declaração*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração-especificadores* *atributo-Seq*<sub>opt</sub> *init-Declaration-List*<sub>opt</sub>**;**

/\**atributo-Seq*<sub>opt</sub> é específico da Microsoft */

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*init-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-declarator-List* **,** *init-declarator*

*init-Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*inicializador* de *Declarador* **=**

> [!NOTE]
> Esta sintaxe para *declaration* não é repetida nas seções a seguir. A sintaxe nas seguintes seções normalmente inicia com *declarator* não terminal.

As declarações na *init-declarator-list* contêm os identificadores que estão sendo nomeados; *init* é uma abreviação para o inicializador. A *init-declarator-list* é uma sequência de declaradores separada por vírgulas, em que cada um pode ter informações adicionais do tipo ou um inicializador ou ambos. O *declarator* contém os identificadores, caso haja algum, que estão sendo declarados. Não terminal *declaration-specifiers* consiste de uma sequência dos especificadores de tipo e classe de armazenamento que indicam vinculação, a duração de armazenamento e ao menos parte do tipo de entidades que os declaradores denotam. Portanto, as declarações são constituídas de uma combinação de especificadores de classe de armazenamento, especificadores de tipo, qualificadores de tipo, declaradores e inicializadores.

As declarações podem conter um ou mais dos atributos opcionais listados em *attribute-seq*; *seq* é uma abreviação para sequência. Esses atributos específicos da Microsoft executam uma variedade de funções, que são discutidas em detalhes ao longo deste documento.

No formato geral de uma declaração variável, o *especificador de tipo* fornece o tipo de dados da variável. O *type-specifier* pode ser um composto, como quando o tipo é modificado por **const** ou por `volatile`. O `declarator` fornece o nome da variável, possivelmente modificado para declarar uma matriz ou um tipo de ponteiro. Por exemplo,

```C
int const *fp;
```

declara uma variável chamada `fp` como um ponteiro para um valor não modificável (**const**) `int` . Você pode definir mais de uma variável em uma declaração usando vários declaradores, separados por vírgulas.

Uma declaração deve ter pelo menos um declarador ou seu especificador de tipo deve declarar uma marca de estrutura, marca de união ou membros de uma enumeração. Os declaradores fornecem toda quaisquer outras informações sobre um identificador. Um declarador é um identificador que pode ser modificado com colchetes (**[ ]**), asteriscos (<strong>\*</strong>) ou parênteses ( **( )** ) para declarar uma matriz, ponteiro ou um tipo de função, respectivamente. Quando você declara variáveis simples (como o caractere, inteiro e itens de ponto flutuante), ou estruturas e uniões de variáveis simples, `declarator` é apenas um identificador. Para obter mais informações sobre os declaradores, consulte [Declaradores e declarações de variável](../c-language/declarators-and-variable-declarations.md).

Todas as definições são implicitamente declarações, mas nem todas as declarações são definições. Por exemplo, as declarações de variáveis que começam com o especificador de classe de armazenamento `extern` "fazem referência", ao invés de "definir" declarações. Se uma variável externa deve ser chamada antes que tenha sido definida, ou se é definida em outro arquivo de origem do onde é usada, uma declaração `extern` é necessária. O armazenamento não é alocado "referenciando" declarações, nem as variáveis podem ser inicializados em declarações.

Uma classe de armazenamento ou um tipo (ou ambos) são necessários em declarações de variáveis. Com exceção de `__declspec`, apenas um especificador de classe de armazenamento é permitido em uma declaração e nem todos os especificadores de armazenamento classe são permitidos em cada contexto. A classe de armazenamento `__declspec` é permitida com outros especificadores de classe de armazenamento, e ela é permitida mais de uma vez. O especificador de classe de armazenamento de uma declaração afeta como o item declarado é armazenado e inicializado, e quais partes de um programa podem fazer referência ao item.

Os terminais de *storage-class-specifier* definidos em C incluem **auto**, `extern`, **register**, **static** e `typedef`. Além disso, o Microsoft C inclui o terminal de *storage-class-specifier*`__declspec`. Todos os terminais de *storage-class-specifier*, exceto `typedef` e `__declspec` são discutidos em [Classes de armazenamento](../c-language/c-storage-classes.md). Consulte [Declarações de typedef](../c-language/typedef-declarations.md) para obter informações sobre `typedef`. Consulte [Atributos estendidos de classe de armazenamento](../c-language/c-extended-storage-class-attributes.md) para obter informações sobre `__declspec`.

O local da declaração no programa de origem e da presença ou ausência de outras instruções da variável são fatores importantes na determinação de diversas variáveis. Pode haver várias redeclarações mas apenas uma definição. No entanto, uma definição pode aparecer em mais de uma unidade de tradução. Para objetos com vinculação interna, esta regra é aplicada separadamente a cada unidade de tradução, pois os objetos internamente vinculados são exclusivos para uma unidade de tradução. Para objetos com vinculação externa, essa regra se aplica ao programa inteiro. Consulte [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md) para obter mais informações sobre visibilidade.

Os especificadores do tipo fornecem algumas informações sobre os tipos de dados de identificadores. O especificador do tipo padrão é `int`. Para obter mais informações, consulte [Especificadores de tipos](../c-language/c-type-specifiers.md). Os especificadores de tipo também podem definir marcas de tipo, estruturas e nomes de componentes da união, além de constantes da enumeração. Para obter mais informações, consulte [Declarações de enumeração](../c-language/c-enumeration-declarations.md), [Declarações de estrutura](../c-language/structure-declarations.md) e [Declarações de união](../c-language/union-declarations.md).

Há dois terminais de *type-qualifier*: **const** e `volatile`. Esses qualificadores especificam propriedades adicionais dos tipos que só são relevantes apenas no acesso de objetos desse tipo por valores l. Para obter mais informações sobre **const** e `volatile`, consulte [Qualificadores do tipo](../c-language/type-qualifiers.md). Para uma definição de l-values, consulte [Expressões de l-value e r-value](../c-language/l-value-and-r-value-expressions.md).

## <a name="see-also"></a>Confira também

[Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md)<br/>
[Declarações e tipos](../c-language/declarations-and-types.md)<br/>
[Resumo de declarações](../c-language/summary-of-declarations.md)
