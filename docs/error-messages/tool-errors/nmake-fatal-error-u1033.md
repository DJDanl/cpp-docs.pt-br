---
title: Erro fatal U1033 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1033
helpviewer_keywords:
- U1033
ms.assetid: c146f7b5-7d5c-4329-a522-28a648546016
ms.openlocfilehash: 4511b15c84479c3531a3bea85964e2768de0181f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173381"
---
# <a name="nmake-fatal-error-u1033"></a>Erro fatal U1033 (NMAKE)

erro de sintaxe: ' String ' inesperado

A cadeia de caracteres não faz parte da sintaxe válida para um makefile.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Se o conjunto de fechamento de colchetes angulares ( **<<** ) para um arquivo embutido não estiver no início de uma linha, o seguinte erro ocorrerá:

    ```
    syntax error : 'EOF' unexpected
    ```

1. Se uma definição de macro no Makefile contiver um sinal de igual ( **=** ) sem um nome anterior ou se o nome que está sendo definido for uma macro que se expande como Nothing, ocorre o seguinte erro:

    ```
    syntax error : '=' unexpected
    ```

1. Se o ponto-e-vírgula ( **;** ) em uma linha de comentário em ferramentas. INI não está no início da linha, o seguinte erro ocorre:

    ```
    syntax error : ';' unexpected
    ```

1. Se o makefile tiver sido formatado por um processador de texto, o seguinte erro poderá ocorrer:

    ```
    syntax error : ':' unexpected
    ```
