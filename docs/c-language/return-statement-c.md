---
title: Instrução return (C)
description: A instrução de retorno da linguagem C encerra a execução da função e, opcionalmente, retorna um valor para o chamador.
ms.date: 06/10/2020
helpviewer_keywords:
- ( ) parentheses in return statements
ms.assetid: 18cd82cf-f899-4b28-83ad-4eff353ddcb4
ms.openlocfilehash: 7d518aa17185c96de15c8f9aa9b65ae5c72bd014
ms.sourcegitcommit: 01b911613606c3fc92cbd9ca48cca6046a7e8258
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/11/2020
ms.locfileid: "84716288"
---
# <a name="return-statement-c"></a>Instrução return (C)

Uma **`return`** instrução encerra a execução de uma função e retorna o controle para a função de chamada. A execução é retomada na função de chamada no ponto imediatamente após a chamada. Uma **`return`** instrução pode retornar um valor para a função de chamada. Para obter mais informações, consulte [tipo de retorno](../c-language/return-type.md).

## <a name="syntax"></a>Syntax

> *instrução de salto*: \
> &nbsp;&nbsp;&nbsp;&nbsp;**`return`***expressão*&#8203;<sub>opt</sub>**`;`**

O valor de *expression*, se existir, será retornado à função de chamada. Se o valor de *expression* for omitido, o valor retornado da função será indefinido. A expressão, se presente, será avaliada e convertida no tipo retornado pela função. Quando uma **`return`** instrução contém uma expressão em funções que têm um **`void`** tipo de retorno, o compilador gera um aviso e a expressão não é avaliada.

Se nenhuma **`return`** instrução aparecer em uma definição de função, o controle retornará automaticamente para a função de chamada depois que a última instrução da função chamada for executada. Nesse caso, o valor de retorno da função chamada será indefinido. Se a função tiver um tipo de retorno diferente de **`void`** , trata-se de um bug sério e o compilador imprime uma mensagem de diagnóstico de aviso. Se a função tiver um **`void`** tipo de retorno, esse comportamento será ok, mas poderá ser considerado um estilo ruim. Use uma **`return`** instrução simples para tornar sua intenção clara.

Como uma boa prática de engenharia, sempre especifique um tipo de retorno para suas funções. Se um valor de retorno não for necessário, declare a função para ter o **`void`** tipo de retorno. Se um tipo de retorno não for especificado, o compilador C assumirá um tipo de retorno padrão de **`int`** .

Muitos programadores usam parênteses para colocar o argumento de *expressão* da **`return`** instrução. No entanto, C não exige os parênteses.

O compilador pode emitir uma mensagem de diagnóstico de aviso sobre código inacessível se encontrar quaisquer instruções colocadas após a **`return`** instrução.

Em uma **`main`** função, a **`return`** instrução e a expressão são opcionais. O que acontece com o valor retornado, se um for especificado, depende da implementação. **Específico da Microsoft**: a implementação do Microsoft C retorna o valor da expressão para o processo que invocou o programa, como *`cmd.exe`* . Se nenhuma **`return`** expressão for fornecida, o tempo de execução do Microsoft C retornará um valor que indica êxito (0) ou falha (um valor diferente de zero).

## <a name="example"></a>Exemplo

Este exemplo é um programa em várias partes. Ele demonstra a **`return`** instrução e como ela é usada para encerrar a execução da função e, opcionalmente, retornar um valor.

```C
// C_return_statement.c
// Compile using: cl /W4 C_return_statement.c
#include <limits.h>      // for INT_MAX
#include <stdio.h>       // for printf

long long square( int value )
{
    // Cast one operand to long long to force the
    // expression to be evaluated as type long long.
    // Note that parentheses around the return expression
    // are allowed, but not required here.
    return ( value * (long long) value );
}
```

A `square` função retorna o quadrado de seu argumento, em um tipo mais amplo para evitar um erro aritmético. **Específico da Microsoft**: na implementação do Microsoft C, o **`long long`** tipo é grande o suficiente para conter o produto de dois **`int`** valores sem estouro.

Os parênteses em volta da **`return`** expressão no `square` são avaliados como parte da expressão e não são exigidos pela **`return`** instrução.

```C
double ratio( int numerator, int denominator )
{
    // Cast one operand to double to force floating-point
    // division. Otherwise, integer division is used,
    // then the result is converted to the return type.
    return numerator / (double) denominator;
}
```

A `ratio` função retorna a proporção de seus dois **`int`** argumentos como um valor de ponto flutuante **`double`** . A **`return`** expressão é forçada a usar uma operação de ponto flutuante ao converter um dos operandos para **`double`** . Caso contrário, o operador de divisão de inteiro seria usado e a parte fracionária seria perdida.

```C
void report_square( void )
{
    int value = INT_MAX;
    long long squared = 0LL;
    squared = square( value );
    printf( "value = %d, squared = %lld\n", value, squared );
    return; // Use an empty expression to return void.
}
```

A `report_square` função chama `square` com um valor de parâmetro de `INT_MAX` , o maior valor inteiro assinado que se ajusta a um **`int`** . O **`long long`** resultado é armazenado em `squared` e impresso. A `report_square` função tem um **`void`** tipo de retorno, portanto, não tem uma expressão em sua **`return`** instrução.

```C
void report_ratio( int top, int bottom )
{
    double fraction = ratio( top, bottom );
    printf( "%d / %d = %.16f\n", top, bottom, fraction );
    // It's okay to have no return statement for functions
    // that have void return types.
}
```

A `report_ratio` função chama `ratio` com valores de parâmetro de `1` e `INT_MAX` . O **`double`** resultado é armazenado em `fraction` e impresso. A `report_ratio` função tem um **`void`** tipo de retorno, portanto, não precisa retornar um valor explicitamente. A execução de `report_ratio` "sai da parte inferior" e não retorna nenhum valor para o chamador.

```C
int main()
{
    int n = 1;
    int x = INT_MAX;

    report_square();
    report_ratio( n, x );

    return 0;
}
```

A **`main`** função chama duas funções: `report_square` e `report_ratio` . Como `report_square` não usa parâmetros e retorna **`void`** , não atribuímos seu resultado a uma variável. Da mesma forma, `report_ratio` retorna **`void`** , portanto, não salvamos seu valor de retorno. Depois de cada uma dessas chamadas de função, a execução continua na próxima instrução. Em seguida, **`main`** retorna um valor de `0` (normalmente usado para relatar êxito) para encerrar o programa.

Para compilar o exemplo, crie um arquivo de código-fonte chamado *`C_return_statement.c`* . Em seguida, copie todo o código de exemplo, na ordem mostrada. Salve o arquivo e compile-o em uma janela de prompt de comando do desenvolvedor usando o comando:

**`cl /W4 C_return_statement.c`**

Em seguida, para executar o código de exemplo, digite **`C_return_statement.exe`** no prompt de comando. O resultado do exemplo é semelhante a este:

```Output
value = 2147483647, squared = 4611686014132420609
1 / 2147483647 = 0.0000000004656613
```

## <a name="see-also"></a>Veja também

[Instruções](../c-language/statements-c.md)
