---
title: Declarações de matriz
ms.date: 11/04/2016
helpviewer_keywords:
- multidimensional arrays
- declaring arrays
- arrays [C++], declaring
ms.assetid: 5f958b97-cef0-4058-bbc6-37c460aaed9b
ms.openlocfilehash: 4bc75e86601da77758490544cc5b02c485dcee46
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56147770"
---
# <a name="array-declarations"></a>Declarações de matriz

Uma "declaração de matriz" nomeia a matriz e especifica o tipo dos respectivos elementos. Também pode definir o número de elementos na matriz. Uma variável com tipo de matriz é considerada um ponteiro para o tipo dos elementos da matriz.

## <a name="syntax"></a>Sintaxe

*declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers* *init-declarator-list*<sub>opt</sub> **;**

*init-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-declarator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-declarator-list*  **,**  *init-declarator*

*init-declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declarator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declarator* **=** *initializer*

*declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*direct-declarator*: /\* Um declarador de função \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*direct-declarator*  **[**  *constant-expression*<sub>opt</sub> **]**

Como *constant-expression* é opcional, a sintaxe tem dois formatos:

- O primeiro formato define uma variável de matriz. O argumento *constant-expression* entre colchetes especifica o número de elementos na matriz. O *constant-expression*, se estiver presente, deve ter um tipo integral e um valor maior que zero. Cada elemento tem o tipo indicado por *type-specifier*, que pode ser qualquer tipo exceto `void`. Um elemento de matriz não pode ser um tipo de função.

- O segundo formato declara uma variável que foi definida em outro lugar. Ele omite o argumento *constant-expression* entre colchetes, mas não os colchetes. Você só poderá usar esse formato se tiver inicializado a matriz anteriormente, se a tiver declarado como um parâmetro ou se a tiver declarado como uma referência a uma matriz definida explicitamente em outro lugar no programa.

Nos dois formatos, *direct-declarator* nomeia a variável e pode modificar o tipo dela. Os colchetes (**[ ]**) depois de *direct-declarator* modificam o declarador para um tipo de matriz.

Qualificadores de tipo podem aparecer na declaração de um objeto de tipo de matriz, mas se aplicam aos elementos, e não à própria matriz.

Você pode declarar uma matriz de matrizes (uma matriz "multidimensional") colocando uma lista de expressões de constantes entre colchetes após o declarador de matriz, neste formato:

> *type-specifier* *declarator* **[** *constant-expression* **]** **[** *constant-expression* **]** ...

Cada *constant-expression* entre colchetes define o número de elementos em uma determinada dimensão: as matrizes bidimensionais têm duas expressões entre colchetes, as matrizes tridimensionais têm três e assim por diante. Você poderá omitir a primeira expressão de constante se tiver inicializado a matriz, se a tiver declarado como um parâmetro ou se a tiver declarado como uma referência a uma matriz definida explicitamente em outro lugar no programa.

É possível definir matrizes de ponteiros para diversos tipos de objetos usando declaradores complexos, conforme descrito em [Interpretar declaradores mais complexos](../c-language/interpreting-more-complex-declarators.md).

As matrizes são armazenadas por linha. Por exemplo, a seguinte matriz consiste em duas linhas com três colunas cada:

```C
char A[2][3];
```

As três colunas da primeira linha são armazenadas primeiro, seguidas pelas três colunas da segunda linha. Isso significa que o último subscrito varia mais rapidamente.

Para fazer referência a um elemento individual de uma matriz, use uma expressão de subscrito, conforme descrito em [Operadores pós-fixados](../c-language/postfix-operators.md).

## <a name="examples"></a>Exemplos

Estes exemplos ilustram declarações de matrizes:

```C
float matrix[10][15];
```

A matriz bidimensional nomeada `matrix` tem 150 elementos, cada um deles com o tipo **float**.

```C
struct {
    float x, y;
} complex[100];
```

Essa é uma declaração de uma matriz de estruturas. Essa matriz tem 100 elementos; cada elemento é uma estrutura que contém dois membros.

```C
extern char *name[];
```

Essa instrução declara o tipo e o nome de uma matriz de ponteiros para `char`. A definição real de `name` ocorre em outro lugar.

**Seção específica da Microsoft**

O tipo de inteiro necessário para manter o tamanho máximo de uma matriz é o tamanho de **size_t**. Definido no arquivo de cabeçalho STDDEF.H, **size_t** é um `unsigned int` com o intervalo de 0x00000000 a 0x7CFFFFFF.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Declaradores e declarações de variável](../c-language/declarators-and-variable-declarations.md)
