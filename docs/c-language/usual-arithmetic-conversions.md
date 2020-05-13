---
title: Conversões aritméticas normais
ms.date: 11/04/2016
helpviewer_keywords:
- arithmetic conversions [C++]
- type conversion [C++], arithmetic
- operators [C], arithmetic conversions
- data type conversion [C++], arithmetic
- conversions [C++], arithmetic
- arithmetic operators [C++], type conversions
ms.assetid: bfa49803-0efd-45d0-b987-111412a140d7
ms.openlocfilehash: 729e173c695db3b4970490e84bedfd441e6ff6d3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62344831"
---
# <a name="usual-arithmetic-conversions"></a>Conversões aritméticas normais

A maioria dos operadores C executam conversões de tipos para avançar os operandos de uma expressão para um tipo comum ou estender valores resumidos para o tamanho do inteiro usado em operações do computador. As conversões realizadas por operadores C dependem do operador específico e do tipo dos operandos. Porém, muitos operadores executam conversões semelhantes em operandos dos tipos integral e flutuante. Essas conversões são conhecidas como “conversões aritméticas”. A conversão de um valor de operando em um tipo compatível não faz qualquer alteração em seu valor.

As conversões aritméticas resumidas abaixo são chamadas “conversões aritméticas usuais”. Essas etapas são aplicadas apenas a operadores binários que esperam o tipo aritmético. A finalidade é gerar um tipo comum que também seja o tipo do resultado. Para determinar quais conversões ocorrem realmente, o compilador aplica o seguinte algoritmo a operações binárias à expressão. As etapas abaixo não são uma ordem de precedência.

1. Se qualquer operando for do tipo `long double`, o outro operando será convertido ao tipo `long double`.

1. Se a condição anterior não for atendida e qualquer operando for do tipo **double**, o outro operando será convertido ao tipo **double**.

1. Se as duas condições anteriores não forem atendidas e qualquer operando for do tipo **double**, o outro operando será convertido ao tipo **double**.

1. Se as três condições anteriores não forem atendidas (nenhum dos operandos é dos tipos flutuantes), as conversões integrais são executadas nos operandos como segue:

   - Se qualquer operando for do tipo `unsigned long`, o outro operando será convertido ao tipo `unsigned long`.

   - Se a condição anterior não for atendida e qualquer operando for do tipo **long** e o outro do tipo `unsigned int`, os dois operandos serão convertidos ao tipo `unsigned long`.

   - Se as duas condições anteriores não forem atendidas e qualquer operando for do tipo **long**, o outro operando será convertido ao tipo **long**.

   - Se as três condições anteriores não forem atendidas e qualquer operando for do tipo `unsigned int`, o outro operando será convertido ao tipo `unsigned int`.

   - Se nenhuma das condições anteriores forem atendidas, os dois os operandos serão convertidos ao tipo `int`.

O código a seguir ilustra essas regras de conversão:

```
float   fVal;
double  dVal;
int   iVal;
unsigned long ulVal;

dVal = iVal * ulVal; /* iVal converted to unsigned long
                      * Uses step 4.
                      * Result of multiplication converted to double
                      */
dVal = ulVal + fVal; /* ulVal converted to float
                      * Uses step 3.
                      * Result of addition converted to double
                      */
```

## <a name="see-also"></a>Confira também

[Operadores de C](../c-language/c-operators.md)
