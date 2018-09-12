---
title: Instrução return para (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- ( ) parentheses in return statements
ms.assetid: 18cd82cf-f899-4b28-83ad-4eff353ddcb4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2bd1f1a9f441a8c4b5e2cf9418653a6a0544380e
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43759077"
---
# <a name="return-statement-c"></a>Instrução return (C)
A instrução `return` encerra a execução de uma função e devolve o controle para a função de chamada. A execução é retomada na função de chamada no ponto imediatamente após a chamada. Uma instrução `return` também pode retornar um valor à função de chamada. Consulte [Tipo de Retorno](../c-language/return-type.md) para obter mais informações.  
  
## <a name="syntax"></a>Sintaxe

*jump-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**return** *expression*<sub>opt</sub> **;**

O valor de *expression*, se existir, será retornado à função de chamada. Se o valor de *expression* for omitido, o valor retornado da função será indefinido. A expressão, se presente, será avaliada e convertida no tipo retornado pela função. Se a função foi declarada com o tipo de retorno `void`, uma instrução `return` que contém uma expressão gera um aviso e a expressão não é avaliada.  
  
Se nenhuma instrução `return` aparecer em uma definição de função, o controle retornará automaticamente à função de chamada depois que a última instrução da função chamada for executada. Nesse caso, o valor de retorno da função chamada será indefinido. Se um valor de retorno não for necessário, declare a função para ter o tipo de retorno `void`; caso contrário, o tipo de retorno padrão será `int`.  
  
Muitos programadores colocam o argumento *expression* da instrução `return` entre parênteses. No entanto, C não requer parênteses.  
  
Este exemplo demonstra a instrução `return`:  
  
```  
#include <limits.h>  
#include <stdio.h>  
  
void draw( int i, long long ll );  
long long sq( int s );  
  
int main()  
{  
    long long y;  
    int x = INT_MAX;  
  
    y = sq( x );  
    draw( x, y );  
    return x;  
}  
  
long long sq( int s )  
{  
    // Note that parentheses around the return expression   
    // are allowed but not required here.  
    return( s * (long long)s );  
}  
  
void draw( int i, long long ll )  
{  
    printf( "i = %d, ll = %lld\n", i, ll );  
    return;  
}  
  
```  
  
Neste exemplo, a função `main` chamada duas funções: `sq` e `draw`. A função `sq` retorna o valor de `x * x` para `main`, onde o valor de retorno será atribuído a `y`. Os parênteses ao redor da expressão de retorno em `sq` são avaliados como parte da expressão, e não são exigidos pela instrução de retorno. Como a expressão de retorno é avaliada antes de ser convertida no tipo de retorno, `sq` força o tipo de expressão a ser o tipo de retorno com uma conversão para evitar um possível estouro de inteiros, o que pode levar a resultados inesperados. A função `draw` é declarada como uma função `void`. Imprime os valores de seus parâmetros e a instrução de retorno vazia encerra a função e não retorna um valor. Uma tentativa de atribuir o valor de retorno de `draw` geraria uma mensagem de diagnóstico. A função `main` retorna o valor de `x` ao sistema operacional.  
  
O resultado do exemplo é semelhante a este:  
  
```Output  
i = 2147483647, ll = 4611686014132420609  
```  
  
## <a name="see-also"></a>Consulte também  
[Instruções](../c-language/statements-c.md)