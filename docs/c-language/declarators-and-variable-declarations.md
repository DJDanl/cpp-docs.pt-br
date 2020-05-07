---
title: Declaradores e declarações variáveis
ms.date: 11/04/2016
helpviewer_keywords:
- declaring variables, declarators
- declarators, definition
- declaring variables, declaration statements
ms.assetid: 5fd67a6a-3a6a-4ec9-b257-3f7390a48d40
ms.openlocfilehash: 928de4b1724577a9fdb282f5109b4b5d0b31c4e6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62234502"
---
# <a name="declarators-and-variable-declarations"></a>Declaradores e declarações variáveis

O restante desta seção descreve o formato e o significado das declarações para os tipos de variável resumidos nesta lista. Em particular, as demais seções explicam como declarar o seguinte:

|Tipo de variável|Descrição|
|----------------------|-----------------|
|[Variáveis simples](../c-language/simple-variable-declarations.md)|Variáveis de valor único com tipo integral ou de ponto flutuante|
|[Matrizes](../c-language/array-declarations.md)|Variáveis compostas de uma coleção de elementos com o mesmo tipo|
|[Ponteiros](../c-language/pointer-declarations.md)|Variáveis que apontam para outras variáveis e contêm locais de variáveis (na forma de endereços) em vez de valores|
|[Variáveis de enumeração](../c-language/c-enumeration-declarations.md)|Variáveis simples com tipo integral que mantêm um único valor de um conjunto de constantes de inteiro nomeadas|
|[Estruturas](../c-language/structure-declarations.md)|Variáveis compostas de uma coleção de valores que podem ter tipos diferentes|
|[Uniões](../c-language/union-declarations.md)|Variáveis compostas de vários valores de tipos diferentes que ocupam o mesmo espaço de armazenamento|

Um declarador é a parte de uma declaração que especifica o nome a ser introduzido no programa. Ele pode incluir modificadores como <strong>\*</strong> (ponteiro-para) e qualquer uma das palavras-chave da Convenção de chamada da Microsoft.

**Específico da Microsoft**

No declarador

```C
__declspec(thread) char *var;
```

`char` é o especificador de tipo, `__declspec(thread)` e `*` são os modificadores, e `var` é o nome do identificador.

**FINAL específico da Microsoft**

Você usa declaradores para declarar matrizes de valores, ponteiros para valores e funções que retornam valores de um tipo especificado. Os declaradores aparecem nas declarações de matrizes e de ponteiros descritas posteriormente nesta seção.

## <a name="syntax"></a>Sintaxe

*Declarador*:<br/>
&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*Declarador direto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**(**  *Declarador*  **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto***[***opt-expressão de constante*<sub>opt</sub> **]**    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto*  **(**  *tipo de parâmetro-lista*  **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto***(***opção identificador-lista*<sub>opt</sub> **)**    

*ponteiro*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>\*</strong><sub>opção</sub> *de qualificador de tipo-lista*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>\*</strong><sub>opt</sub> *ponteiro* de *tipo-qualificador de lista de tipos*

*type-qualifier-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*qualificador de tipo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier-list type-qualifier*

> [!NOTE]
> Consulte a sintaxe de *declaration* na [Visão Geral de Declarações](../c-language/overview-of-declarations.md) ou em [Resumo da Sintaxe da Linguagem C](../c-language/c-language-syntax-summary.md) para a sintaxe que se refere a *declarator*.

Quando um declarador consiste em um identificador não modificado, o item que está sendo declarado tem um tipo de base. Se um asterisco (<strong>\*</strong>) aparecer à esquerda de um identificador, o tipo será modificado para um tipo de ponteiro. Se o identificador for seguido por colchetes (**[ ]**), o tipo será modificado para um tipo de matriz. Se o identificador for seguido por parênteses, o tipo será modificado para um tipo de função. Para obter mais informações sobre como interpretar a precedência em declarações, consulte [Interpretação de declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md).

Cada declarador declara pelo menos um identificador. Um declarador deve incluir um especificador de tipo para ser uma declaração completa. O especificador de tipo fornece o tipo dos elementos de um tipo de matriz, o tipo de objeto tratado por um tipo ponteiro ou o tipo de retorno de uma função.

As declarações de [matrizes](../c-language/array-declarations.md) e de [ponteiros](../c-language/pointer-declarations.md) são discutidas em mais detalhes posteriormente nesta seção. Os exemplos a seguir ilustram alguns formatos simples de declaradores:

```C
int list[20]; // Declares an array of 20 int values named list
char *cp;     // Declares a pointer to a char value
double func( void ); // Declares a function named func, with no
                     // arguments, that returns a double value
int *aptr[10] // Declares an array of 10 pointers
```

**Específico da Microsoft**

O compilador de C da Microsoft não limita o número de declaradores que podem modificar um tipo aritmético, de estrutura ou de união. O número é limitado somente pela memória disponível.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
