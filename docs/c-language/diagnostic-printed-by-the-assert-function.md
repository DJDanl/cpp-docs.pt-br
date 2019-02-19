---
title: Diagnóstico impresso pela função assert
ms.date: 11/04/2016
ms.assetid: 78b64200-520d-40da-9a61-71553f411d4f
ms.openlocfilehash: 666ba22d642b772fe8ad336f57ab1bdd82bd2e18
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56150994"
---
# <a name="diagnostic-printed-by-the-assert-function"></a>Diagnóstico impresso pela função assert

**ANSI 4.2** O diagnóstico impresso pela função **assert** e seu comportamento de término

A função **assert** imprimirá uma mensagem de diagnóstico e chamará a rotina **abort** se a expressão for false (0). A mensagem de diagnóstico tem o formato

> **Assertion failed**: <em>expressão</em>**, arquivo** <em>nome_de_arquivo</em>**, linha** *número_de_linha*

em que *nome_de_arquivo* é o nome do arquivo de origem e *número_de_linha* é o número de linha da asserção que falhou no arquivo de origem. Nenhuma ação será executada se a *expressão* for true (diferente de zero).

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)
