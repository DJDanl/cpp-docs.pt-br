---
title: Instrução for (C)
ms.date: 11/04/2016
helpviewer_keywords:
- for keyword [C]
ms.assetid: 560a8de4-19db-4868-9f18-dbe51b17900d
ms.openlocfilehash: 91675fbe15ec6abf5aae4548990d9b4e0703e967
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229721"
---
# <a name="for-statement-c"></a>Instrução for (C)

A **`for`** instrução permite repetir uma instrução ou instrução composta um número especificado de vezes. O corpo de uma **`for`** instrução é executado zero ou mais vezes até que uma condição opcional se torne falsa. Você pode usar expressões opcionais dentro da **`for`** instrução para inicializar e alterar valores durante a **`for`** execução da instrução.

## <a name="syntax"></a>Sintaxe

*instrução Iteration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`for`****(** *init-expressão*<sub>opt</sub> **;** *condicional-expressão*<sub>opt</sub> **;** *instrução* *loop-expressão*<sub>opt</sub> **)**

A execução de uma **`for`** instrução continua da seguinte maneira:

1. A *init-expression*, se houver, é avaliada. Isso especifica a inicialização do loop. Não há nenhuma restrição quanto ao tipo da *init-expression*.

1. A *cond-expression*, se houver, é avaliada. Essa expressão deve ter tipo aritmético ou ponteiro. Ela é avaliada antes de cada iteração. Três resultados são possíveis:

   - Se *condicional* for **`true`** (diferente de zero), a *instrução* será executada; em seguida, *a expressão de loop*, se houver, será avaliada. A *loop-expression* é avaliada após cada iteração. Não há nenhuma restrição quanto ao tipo dele. Os efeitos colaterais serão executados na ordem. Em seguida, o processo é iniciado novamente com a avaliação de *cond-expression*.

   - Se *cond-expression* está omitida, *cond-expression* é considerada true e a execução continua exatamente conforme descrita no parágrafo anterior. Uma **`for`** instrução sem um argumento *condicional* é encerrada somente quando uma **`break`** instrução ou **`return`** dentro do corpo da instrução é executada ou quando um **`goto`** (para uma instrução rotulada fora do corpo da **`for`** instrução) é executado.

   - Se *condicional* for **`false`** (0), a execução da instrução será **`for`** encerrada e o controle passará para a próxima instrução no programa.

Uma **`for`** instrução também termina quando uma **`break`** instrução, **`goto`** ou **`return`** dentro do corpo da instrução é executada. Uma **`continue`** instrução em um **`for`** loop faz com que a *expressão de loop* seja avaliada. Quando uma **`break`** instrução é executada dentro de um **`for`** loop, a *expressão de loop* não é avaliada ou executada. Esta instrução

```C
for( ; ; )
```

é a maneira personalizada de produzir um loop infinito que só pode ser encerrado com uma **`break`** instrução, **`goto`** ou **`return`** .

## <a name="example"></a>Exemplo

Este exemplo ilustra a **`for`** instrução:

```C
// c_for.c
int main()
{
   char* line = "H e  \tl\tlo World\0";
   int space = 0;
   int tab = 0;
   int i;
   int max = strlen(line);
   for (i = 0; i < max; i++ )
   {
      if ( line[i] == ' ' )
      {
          space++;
      }
      if ( line[i] == '\t' )
      {
          tab++;
      }
   }

   printf("Number of spaces: %i\n", space);
   printf("Number of tabs: %i\n", tab);
   return 0;
}
```

## <a name="output"></a>Saída

```Output
Number of spaces: 4
Number of tabs: 2
```

## <a name="see-also"></a>Confira também

[Instruções](../c-language/statements-c.md)
