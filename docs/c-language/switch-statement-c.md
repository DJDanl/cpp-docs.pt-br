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
ms.openlocfilehash: 5858447602a28dcc5573aa3138e869d106b5aa23
ms.sourcegitcommit: 2f9ff2041d70c406df76c5053151192aad3937ea
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2020
ms.locfileid: "82587369"
---
# <a name="switch-statement-c"></a>`switch`Instrução (C)

As __`switch`__ instruções __`case`__ e ajudam a controlar operações condicionais e de ramificação complexas. A __`switch`__ instrução transfere o controle para uma instrução dentro de seu corpo.

## <a name="syntax"></a>Sintaxe

> *`selection-statement`*:<br/>
> &nbsp;&nbsp;&nbsp;&nbsp; __`switch (`__&nbsp;*`expression`* &nbsp;__`)`__&nbsp;*`statement`*

> *`labeled-statement`*:<br/>
> &nbsp;&nbsp;&nbsp;&nbsp; __`case`__&nbsp;*`constant-expression`*&nbsp;__`:`__&nbsp;*`statement`*<br/>
> &nbsp;&nbsp;&nbsp;&nbsp; __`default`__&nbsp;__`:`__&nbsp;*`statement`*

## <a name="remarks"></a>Comentários

Uma __`switch`__ instrução faz com que o controle seja *`labeled-statement`* transferido para um em seu corpo de instrução, dependendo do *`expression`* valor de.

Os valores de *`expression`* e cada *`constant-expression`* devem ter um tipo integral. Um *`constant-expression`* deve ter um valor integral constante não ambíguo no tempo de compilação.

O controle passa para **`case`** a instrução *`constant-expression`* cujo valor corresponde ao valor *`expression`* de. A __`switch`__ instrução pode incluir qualquer número de __`case`__ instâncias. No entanto, *`constant-expression`* dois valores dentro da __`switch`__ mesma instrução podem ter o mesmo valor. A execução do __`switch`__ corpo da instrução começa na primeira instrução no ou após a correspondência *`labeled-statement`*. A execução continua até o fim do corpo ou até que uma __`break`__ instrução transfira o controle para fora do corpo.

O __`switch`__ uso da instrução geralmente é semelhante a este:

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

Você pode usar a __`break`__ instrução para finalizar o processamento de uma instrução rotulada em __`switch`__ particular dentro da instrução. Ele é ramificado para o final __`switch`__ da instrução. Sem __`break`__, o programa continua para a próxima instrução rotulada, executando as instruções até que __`break`__ um ou o final da instrução seja atingido. Essa continuação pode ser desejável em algumas situações.

A __`default`__ instrução será executada se nenhum __`case`__ *`constant-expression`* valor for igual ao valor de *`expression`*. Se não houver nenhuma __`default`__ instrução e nenhuma __`case`__ correspondência for encontrada, nenhuma das instruções no __`switch`__ corpo será executada. Pode haver no máximo uma __`default`__ instrução. A __`default`__ instrução não precisa aparecer no final. Ele pode aparecer em qualquer lugar no corpo da __`switch`__ instrução. Um __`case`__ rótulo __`default`__ ou só pode aparecer dentro de __`switch`__ uma instrução.

O tipo de __`switch`__ *`expression`* e __`case`__ *`constant-expression`* deve ser integral. O valor de cada __`case`__ *`constant-expression`* deve ser exclusivo dentro do corpo da instrução.

Os __`case`__ rótulos __`default`__ e do corpo __`switch`__ da instrução são significativos apenas no teste inicial que determina onde a execução começa no corpo da instrução. __`switch`__ as instruções podem ser aninhadas. Todas as variáveis estáticas são inicializadas antes __`switch`__ de serem executadas em qualquer instrução.

> [!NOTE]
> As declarações podem aparecer no início da instrução composta que formam o __`switch`__ corpo, mas as inicializações incluídas nas declarações não são executadas. A __`switch`__ instrução transfere o controle diretamente para uma instrução executável dentro do corpo, ignorando as linhas que contêm inicializações.

Os exemplos a seguir __`switch`__ ilustram instruções:

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

Todas as três instruções do __`switch`__ corpo neste exemplo `c` serão executadas se for igual a `'A'`, pois nenhuma __`break`__ instrução aparecerá antes do seguinte __`case`__. O controle de execução é transferido para a primeira instrução (`capital_a++;`) e continua em ordem pelo restante do corpo. Se `c` é igual a `'a'`, `letter_a` e `total` são incrementados. Só `total` é incrementado quando `c` não é `'A'` igual `'a'`a ou.

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

Neste exemplo, uma __`break`__ instrução segue cada instrução do __`switch`__ corpo. A __`break`__ instrução força uma saída do corpo da instrução após a execução de uma instrução. Se `i` for igual a -1, apenas `n` será incrementado. A __`break`__ instrução `n++;` a seguir faz com que o controle de execução passe do corpo da instrução, ignorando as instruções restantes. Da mesma forma, se `i` é igual a 0, somente `z` será incrementado; se `i` é igual a 1, somente `p` será incrementado. A instrução __`break`__ final não é estritamente necessária, já que o controle passa do corpo no final da instrução composta. Ele está incluído para fins de consistência.

Uma única instrução pode transportar vários __`case`__ rótulos, como mostra o exemplo a seguir:

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

O Microsoft C não limita o número __`case`__ de valores em __`switch`__ uma instrução. O número é limitado somente pela memória disponível. ANSI C requer pelo menos 257 __`case`__ rótulos serem permitidos em uma __`switch`__ instrução.

O default para Microsoft C é que as extensões da Microsoft estão habilitadas. Use a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) para desabilitar essas extensões.

## <a name="see-also"></a>Confira também

[switchInstrução (C++)](../cpp/switch-statement-cpp.md)
