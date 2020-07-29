---
title: :::no-loc(switch):::Instrução (C)
ms.date: 04/25/2020
f1_keywords:
- ':::no-loc(switch):::'
helpviewer_keywords:
- ':::no-loc(switch)::: keyword [C]'
ms.assetid: fbede014-23bd-4ab1-8094-c8d9d9cb963a
no-loc:
- ':::no-loc(switch):::'
- ':::no-loc(case):::'
- ':::no-loc(default):::'
- ':::no-loc(break):::'
ms.openlocfilehash: bdd6885f67728a3c81e395f05c33191156896ad9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220776"
---
# <a name="no-locswitch-statement-c"></a>`:::no-loc(switch):::`Instrução (C)

As **`:::no-loc(switch):::`** **`:::no-loc(case):::`** instruções e ajudam a controlar operações condicionais e de ramificação complexas. A **`:::no-loc(switch):::`** instrução transfere o controle para uma instrução dentro de seu corpo.

## <a name="syntax"></a>Sintaxe

> *`selection-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; **`:::no-loc(switch)::: (`**&nbsp;*`expression`* &nbsp;**`)`**&nbsp;*`statement`*

> *`labeled-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; **`:::no-loc(case):::`**&nbsp;*`constant-expression`*&nbsp;**`:`**&nbsp;*`statement`*\
> &nbsp;&nbsp;&nbsp;&nbsp; **`:::no-loc(default):::`**&nbsp;**`:`**&nbsp;*`statement`*

## <a name="remarks"></a>Comentários

Uma **`:::no-loc(switch):::`** instrução faz com que o controle seja transferido para um *`labeled-statement`* em seu corpo de instrução, dependendo do valor de *`expression`* .

Os valores de *`expression`* e cada *`constant-expression`* devem ter um tipo integral. Um *`constant-expression`* deve ter um valor integral constante não ambíguo no tempo de compilação.

O controle passa para a **`:::no-loc(case):::`** instrução cujo *`constant-expression`* valor corresponde ao valor de *`expression`* . A **`:::no-loc(switch):::`** instrução pode incluir qualquer número de **`:::no-loc(case):::`** instâncias. No entanto, dois *`constant-expression`* valores dentro da mesma **`:::no-loc(switch):::`** instrução podem ter o mesmo valor. A execução do **`:::no-loc(switch):::`** corpo da instrução começa na primeira instrução no ou após a correspondência *`labeled-statement`* . A execução continua até o fim do corpo ou até que uma **`:::no-loc(break):::`** instrução transfira o controle para fora do corpo.

O uso da **`:::no-loc(switch):::`** instrução geralmente é semelhante a este:

```C
:::no-loc(switch)::: ( expression )
{
    // declarations
    // . . .
    :::no-loc(case)::: constant_expression:
        // statements executed if the expression equals the
        // value of this constant_expression
        :::no-loc(break):::;
    :::no-loc(default)::::
        // statements executed if expression does not equal
        // any :::no-loc(case)::: constant_expression
}
```

Você pode usar a **`:::no-loc(break):::`** instrução para finalizar o processamento de uma instrução rotulada em particular dentro da **`:::no-loc(switch):::`** instrução. Ele é ramificado para o final da **`:::no-loc(switch):::`** instrução. Sem **`:::no-loc(break):::`** , o programa continua para a próxima instrução rotulada, executando as instruções até que um **`:::no-loc(break):::`** ou o final da instrução seja atingido. Essa continuação pode ser desejável em algumas situações.

A **`:::no-loc(default):::`** instrução será executada se nenhum **`:::no-loc(case):::`** *`constant-expression`* valor for igual ao valor de *`expression`* . Se não houver nenhuma **`:::no-loc(default):::`** instrução e nenhuma **`:::no-loc(case):::`** correspondência for encontrada, nenhuma das instruções no **`:::no-loc(switch):::`** corpo será executada. Pode haver no máximo uma **`:::no-loc(default):::`** instrução. A **`:::no-loc(default):::`** instrução não precisa aparecer no final. Ele pode aparecer em qualquer lugar no corpo da **`:::no-loc(switch):::`** instrução. Um **`:::no-loc(case):::`** **`:::no-loc(default):::`** rótulo ou só pode aparecer dentro de uma **`:::no-loc(switch):::`** instrução.

O tipo de **`:::no-loc(switch):::`** *`expression`* e **`:::no-loc(case):::`** *`constant-expression`* deve ser integral. O valor de cada **`:::no-loc(case):::`** *`constant-expression`* deve ser exclusivo dentro do corpo da instrução.

Os **`:::no-loc(case):::`** **`:::no-loc(default):::`** rótulos e do **`:::no-loc(switch):::`** corpo da instrução são significativos apenas no teste inicial que determina onde a execução começa no corpo da instrução. **`:::no-loc(switch):::`** as instruções podem ser aninhadas. Todas as variáveis estáticas são inicializadas antes de serem executadas em qualquer **`:::no-loc(switch):::`** instrução.

> [!NOTE]
> As declarações podem aparecer no início da instrução composta que formam o **`:::no-loc(switch):::`** corpo, mas as inicializações incluídas nas declarações não são executadas. A **`:::no-loc(switch):::`** instrução transfere o controle diretamente para uma instrução executável dentro do corpo, ignorando as linhas que contêm inicializações.

Os exemplos a seguir ilustram **`:::no-loc(switch):::`** instruções:

```C
:::no-loc(switch):::( c )
{
    :::no-loc(case)::: 'A':
        capital_a++;
    :::no-loc(case)::: 'a':
        letter_a++;
    :::no-loc(default)::: :
        total++;
}
```

Todas as três instruções do **`:::no-loc(switch):::`** corpo neste exemplo serão executadas se `c` for igual a `'A'` , pois nenhuma **`:::no-loc(break):::`** instrução aparecerá antes do seguinte **`:::no-loc(case):::`** . O controle de execução é transferido para a primeira instrução (`capital_a++;`) e continua em ordem pelo restante do corpo. Se `c` é igual a `'a'`, `letter_a` e `total` são incrementados. Só `total` é incrementado quando `c` não é igual a `'A'` ou `'a'` .

```C
:::no-loc(switch):::( i )
{
    :::no-loc(case)::: -1:
        n++;
        :::no-loc(break):::;
    :::no-loc(case)::: 0 :
        z++;
        :::no-loc(break):::;
    :::no-loc(case)::: 1 :
        p++;
        :::no-loc(break):::;
}
```

Neste exemplo, uma **`:::no-loc(break):::`** instrução segue cada instrução do **`:::no-loc(switch):::`** corpo. A **`:::no-loc(break):::`** instrução força uma saída do corpo da instrução após a execução de uma instrução. Se `i` for igual a -1, apenas `n` será incrementado. A **`:::no-loc(break):::`** instrução a seguir `n++;` faz com que o controle de execução passe do corpo da instrução, ignorando as instruções restantes. Da mesma forma, se `i` é igual a 0, somente `z` será incrementado; se `i` é igual a 1, somente `p` será incrementado. A **`:::no-loc(break):::`** instrução final não é estritamente necessária, já que o controle passa do corpo no final da instrução composta. Ele está incluído para fins de consistência.

Uma única instrução pode transportar vários **`:::no-loc(case):::`** Rótulos, como mostra o exemplo a seguir:

```C
:::no-loc(switch):::( c )
{
    :::no-loc(case)::: 'a' :
    :::no-loc(case)::: 'b' :
    :::no-loc(case)::: 'c' :
    :::no-loc(case)::: 'd' :
    :::no-loc(case)::: 'e' :
    :::no-loc(case)::: 'f' :  convert_hex(c);
}
```

Neste exemplo, se *constant-expression* for igual a qualquer letra entre `'a'` e `'f'`, a função `convert_hex` será chamada.

### <a name="microsoft-specific"></a>Específico da Microsoft

O Microsoft C não limita o número de **`:::no-loc(case):::`** valores em uma **`:::no-loc(switch):::`** instrução. O número é limitado somente pela memória disponível. ANSI C requer pelo menos 257 **`:::no-loc(case):::`** Rótulos serem permitidos em uma **`:::no-loc(switch):::`** instrução.

O :::no-loc(default)::: para Microsoft C é que as extensões da Microsoft estão habilitadas. Use a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) para desabilitar essas extensões.

## <a name="see-also"></a>Confira também

[:::no-loc(switch):::Instrução (C++)](../cpp/:::no-loc(switch):::-statement-cpp.md)
