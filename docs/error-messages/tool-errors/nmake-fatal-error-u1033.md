---
title: Erro fatal U1033 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1033
helpviewer_keywords:
- U1033
ms.assetid: c146f7b5-7d5c-4329-a522-28a648546016
ms.openlocfilehash: 3b1df28e3cd7b27a9e7a130d9d71c1af68db9aec
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50445234"
---
# <a name="nmake-fatal-error-u1033"></a>Erro fatal U1033 (NMAKE)

Erro de sintaxe: 'string' inesperado

A cadeia de caracteres não é parte da sintaxe válida para um makefile.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Se o fechamento definido de colchetes angulares (**<<**) para um arquivo embutido não estão no início de uma linha, ocorre o seguinte erro:

    ```
    syntax error : 'EOF' unexpected
    ```

1. Se uma definição de macro no makefile continha um sinal de igual (**=**) sem o nome de um anterior ou se o nome que está sendo definido é uma macro que se expande para nada, ocorre o seguinte erro:

    ```
    syntax error : '=' unexpected
    ```

1. Se o ponto e vírgula (**;**) em uma linha de comentário em ferramentas. INI não está no início da linha, ocorre o seguinte erro:

    ```
    syntax error : ';' unexpected
    ```

1. Se o makefile tiverem sido formatado por um processador de texto, o seguinte erro pode ocorrer:

    ```
    syntax error : ':' unexpected
    ```