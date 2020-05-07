---
title: Diagnóstico impresso pela função assert
ms.date: 11/04/2016
ms.assetid: 78b64200-520d-40da-9a61-71553f411d4f
ms.openlocfilehash: 666ba22d642b772fe8ad336f57ab1bdd82bd2e18
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62234215"
---
# <a name="diagnostic-printed-by-the-assert-function"></a>Diagnóstico impresso pela função assert

**ANSI 4.2** O diagnóstico impresso pela função **assert** e seu comportamento de término

A função **assert** imprimirá uma mensagem de diagnóstico e chamará a rotina **abort** se a expressão for false (0). A mensagem de diagnóstico tem o formato

> **Assertion failed**: <em>expressão</em>**, arquivo ** <em>nome_de_arquivo</em>**, linha ** *número_de_linha*

em que *nome_de_arquivo* é o nome do arquivo de origem e *número_de_linha* é o número de linha da asserção que falhou no arquivo de origem. Nenhuma ação será executada se a *expressão* for true (diferente de zero).

## <a name="see-also"></a>Confira também

[Funções de biblioteca](../c-language/library-functions.md)
