---
title: Instrução switch (C)
ms.date: 11/04/2016
f1_keywords:
- switch
helpviewer_keywords:
- switch keyword [C]
ms.assetid: fbede014-23bd-4ab1-8094-c8d9d9cb963a
ms.openlocfilehash: 0f781147bf4ed020cf925ca29c2ba1b0f601cde1
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56148186"
---
# <a name="switch-statement-c"></a>Instrução switch (C)

As instruções `switch` e **case** ajudam a controlar operações complexas condicionais e de ramificação. A instrução `switch` transfere o controle para uma instrução dentro do corpo.

## <a name="syntax"></a>Sintaxe

*selection-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**switch (** *expression* **)** *statement*

*labeled-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**case**  *constant-expression*  **:**  *statement*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**default :**  *statement*

O controle passa para a instrução cuja **case** *constant-expression* corresponde ao valor de **switch (** *expression* **)**. A instrução `switch` pode incluir qualquer número de instâncias de **case**, mas duas constantes de case dentro da mesma instrução `switch` não podem ter o mesmo valor. A execução do corpo da instrução começa na instrução selecionada e continua até o final do corpo ou até que uma instrução **break** transfira o controle para fora do corpo.

O uso da instrução `switch` geralmente tem essa aparência:

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

Você pode usar a instrução **break** para encerrar o processamento de um caso específico dentro da instrução `switch` e para ramificar ao final da instrução `switch`. Sem **break**, o programa passa para os próximos casos, executando as instruções até **break** ou até que o final da instrução seja atingido. Em algumas situações, essa continuação pode ser desejável.

A instrução **default** será executada se nenhum **case** *constant-expression* for igual ao valor de **switch (** *expression* **)**. Se a instrução **default** for omitida e nenhuma correspondência de **case** for encontrada, nenhuma das instruções no corpo de `switch` será executada. Pode haver, no máximo, uma instrução **default**. A instrução **default** não precisa ficar no final; ela pode aparecer em qualquer local do corpo da instrução `switch`. Um rótulo **case** ou **default** pode ser exibido apenas dentro de uma instrução `switch`.

O tipo de `switch` *expression* e **case** *constant-expression* deve ser integral. O valor de cada **case** *constant-expression* deve ser exclusivo dentro do corpo da instrução.

Os rótulos **case** e **default** do corpo da instrução `switch` são significativos apenas no teste inicial que determina onde a execução começa no corpo da instrução. As instruções de alternância podem ser aninhadas. Todas as variáveis estáticas são inicializadas antes da execução em qualquer `switch` instrução.

> [!NOTE]
> As declarações podem aparecer no início da instrução composta que forma o corpo de `switch`, mas as inicializações incluídas nas declarações não serão executadas. A instrução `switch` transfere o controle diretamente para uma instrução executável dentro do corpo, ignorando as linhas que contêm inicializações.

Os exemplos a seguir ilustram as instruções `switch`:

```C
switch( c )
{
    case 'A':
        capa++;
    case 'a':
        lettera++;
    default :
        total++;
}
```

Neste exemplo, as três instruções do corpo de `switch` são executadas se `c` for igual a `'A'`, contanto que uma instrução **break** não apareça antes do seguinte caso. O controle de execução é transferido para a primeira instrução (`capa++;`) e continua em ordem pelo restante do corpo. Se `c` é igual a `'a'`, `lettera` e `total` são incrementados. Apenas `total` é incrementado se `c` não é igual a `'A'` ou a `'a'`.

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

Neste exemplo, uma instrução **break** segue cada instrução do corpo de `switch`. A instrução **break** força uma saída do corpo da instrução depois que uma instrução é executada. Se `i` for igual a -1, apenas `n` será incrementado. A instrução **break** que segue a instrução `n++;` faz com que o controle de execução seja passado para fora do corpo da instrução, ignorando as instruções restantes. Da mesma forma, se `i` é igual a 0, somente `z` será incrementado; se `i` é igual a 1, somente `p` será incrementado. A instrução de **break** final não é estritamente necessária, pois o controle passa para fora do corpo no final da instrução composta, mas é incluído para manter a consistência.

Uma única instrução pode portar vários rótulos de **case**, conforme mostrado no exemplo a seguir:

```C
case 'a' :
case 'b' :
case 'c' :
case 'd' :
case 'e' :
case 'f' :  hexcvt(c);
```

Neste exemplo, se *constant-expression* for igual a qualquer letra entre `'a'` e `'f'`, a função `hexcvt` será chamada.

**Seção específica da Microsoft**

O Microsoft C não limita o número de valores de case em uma instrução `switch`. O número é limitado somente pela memória disponível. O ANSI C requer que pelo menos 257 rótulos case sejam permitidos em uma instrução `switch`.

O padrão do Microsoft C é que as extensões da Microsoft sejam habilitadas. Use a opção de compilador /Za para desativar essas extensões.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Instrução switch (C++)](../cpp/switch-statement-cpp.md)
