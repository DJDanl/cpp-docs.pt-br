---
title: Visão geral das funções
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C++]
- control flow, function calls
ms.assetid: b6f4637f-02b9-49d8-8601-1f886bd2cfb9
ms.openlocfilehash: 1c54dcdeec1bad1ffbd335d411e39c77be0ad961
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56150318"
---
# <a name="overview-of-functions"></a>Visão geral das funções

As funções devem ter uma definição e uma declaração, embora uma definição possa servir como uma declaração se a declaração aparecer antes que a função seja chamada. A definição de função inclui o corpo da função — o código executado quando a função é chamada.

Uma declaração de função estabelece o nome, o tipo de retorno e os atributos de uma função que é definida em outro lugar no programa. Uma declaração de função deve preceder a chamada para a função. É por isso que os arquivos de cabeçalho que contêm as declarações para as funções de tempo de execução são incluídos em seu código antes de uma chamada a uma função de tempo de execução. Se a declaração tiver informações sobre os tipos e o número de parâmetros, a declaração é um protótipo. Consulte [Protótipos de função](../c-language/function-prototypes.md) para obter mais informações.

O compilador usa o protótipo para comparar os tipos de argumentos em chamadas subsequentes à função com os parâmetros da função, e para converter os tipos dos argumentos nos tipos dos parâmetros sempre que necessário.

Uma chamada de função passa o controle de execução da função de chamada para a função chamada. Os argumentos, se houver, são passados por valor à função chamada. A execução de uma instrução `return` na função chamada retornará o controle e possivelmente um valor para a função de chamada.

## <a name="see-also"></a>Consulte também

[Funções](../c-language/functions-c.md)
