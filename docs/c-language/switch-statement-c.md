---
title: switchInstrução (C)
ms.date: 04/25/2020
f1_keywords:
- switch
helpviewer_keywords:
- switch keyword [C]
ms.assetid: fbede014-23bd-4ab1-8094-c8d9d9cb963a
no-loc:
- switch
- case
- default
- break
ms.openlocfilehash: 12163e85110092e3e372fa496cf42efd7574ea8d
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82167670"
---
# <a name="opno-locswitch-statement-c"></a>switchInstrução (C)

As **switch** instruções **case** e ajudam a controlar operações condicionais e de ramificação complexas. A **switch** instrução transfere o controle para uma instrução dentro de seu corpo.

## <a name="syntax"></a>Sintaxe

*selection-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`switch (`***expression* **`)`** *instrução* de expressão

*rotulado-instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`case`**  *instrução de expressão***`:`***statement* de constante    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`default :`**  *privacidade*

O controle passa para a instrução **case** *expressão constante* corresponde ao valor de ** switch (** *expressão* **)**. A **switch** instrução pode incluir qualquer número de **case** instâncias. No entanto, case duas constantes dentro da **switch** mesma instrução podem ter o mesmo valor. A execução do corpo da instrução começa na instrução selecionada. Ele continua até o final do corpo ou até que uma **break** instrução transfira o controle para fora do corpo.

O **switch** uso da instrução geralmente é semelhante a este:

```C
switch ( expression )
{
    // declarations
    // . . .
    case constant_expression:
        // statements executed if the expression equals the
        // value of this constant_expression
        break;
    default:
        // statements executed if expression does not equal
        // any case constant_expression
}
```

Você pode usar a **break** instrução para finalizar o processamento de uma instrução rotulada em **switch** particular dentro da instrução. Ele é ramificado para o final **switch** da instrução. Sem **break**, o programa continua para a próxima instrução rotulada, executando as instruções até que **break** um ou o final da instrução seja atingido. Essa continuação pode ser desejável em algumas situações.

A **default** instrução será executada se nenhuma **case** *expressão constante* for igual ao valor de ** switch (** *expressão* **)**. Se não houver nenhuma **default** instrução e nenhuma **case** correspondência for encontrada, nenhuma das instruções no **switch** corpo será executada. Pode haver no máximo uma **default** instrução. A **default** instrução não precisa aparecer no final. Ele pode aparecer em qualquer lugar no corpo da **switch** instrução. Um **case** rótulo **default** ou só pode aparecer dentro de **switch** uma instrução.

O tipo de **switch** *expressão* e **case** a *expressão de constante* devem ser integrais. O valor de cada **case** *expressão de constante* deve ser exclusivo dentro do corpo da instrução.

Os **case** rótulos **default** e do corpo **switch** da instrução são significativos apenas no teste inicial que determina onde a execução começa no corpo da instrução. **switch** as instruções podem ser aninhadas. Todas as variáveis estáticas são inicializadas antes **switch** de serem executadas em qualquer instrução.

> [!NOTE]
> As declarações podem aparecer no início da instrução composta que formam o **switch** corpo, mas as inicializações incluídas nas declarações não são executadas. A **switch** instrução transfere o controle diretamente para uma instrução executável dentro do corpo, ignorando as linhas que contêm inicializações.

Os exemplos a seguir **switch** ilustram instruções:

```C
switch( c )
{
    case 'A':
        capital_a++;
    case 'a':
        letter_a++;
    default :
        total++;
}
```

Todas as três instruções do **switch** corpo neste exemplo `c` serão executadas se for igual a `'A'`, pois nenhuma **break** instrução aparecerá antes do seguinte case. O controle de execução é transferido para a primeira instrução (`capital_a++;`) e continua em ordem pelo restante do corpo. Se `c` é igual a `'a'`, `letter_a` e `total` são incrementados. Só `total` é incrementado quando `c` não é `'A'` igual `'a'`a ou.

```C
switch( i )
{
    case -1:
        n++;
        break;
    case 0 :
        z++;
        break;
    case 1 :
        p++;
        break;
}
```

Neste exemplo, uma **break** instrução segue cada instrução do **switch** corpo. A **break** instrução força uma saída do corpo da instrução após a execução de uma instrução. Se `i` for igual a -1, apenas `n` será incrementado. A **break** instrução `n++;` a seguir faz com que o controle de execução passe do corpo da instrução, ignorando as instruções restantes. Da mesma forma, se `i` é igual a 0, somente `z` será incrementado; se `i` é igual a 1, somente `p` será incrementado. A instrução **break** final não é estritamente necessária, já que o controle passa do corpo no final da instrução composta. Ele está incluído para fins de consistência.

Uma única instrução pode transportar vários **case** rótulos, como mostra o exemplo a seguir:

```C
switch( c )
{
    case 'a' :
    case 'b' :
    case 'c' :
    case 'd' :
    case 'e' :
    case 'f' :  convert_hex(c);
}
```

Neste exemplo, se *constant-expression* for igual a qualquer letra entre `'a'` e `'f'`, a função `convert_hex` será chamada.

### <a name="microsoft-specific"></a>Específico da Microsoft

O Microsoft C não limita o número case de valores em **switch** uma instrução. O número é limitado somente pela memória disponível. ANSI C requer pelo menos 257 case rótulos serem permitidos em uma **switch** instrução.

O default para Microsoft C é que as extensões da Microsoft estão habilitadas. Use a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) para desabilitar essas extensões.

## <a name="see-also"></a>Confira também

[switchInstrução (C++)](../cpp/switch-statement-cpp.md)
