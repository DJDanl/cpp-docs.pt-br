---
title: Erro do compilador C2002
ms.date: 11/04/2016
f1_keywords:
- C2002
helpviewer_keywords:
- C2002
ms.assetid: 91982314-203a-4de1-b884-94e39a623f61
ms.openlocfilehash: c37a9b94be837248c8025a4fc069d8a242128542
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208241"
---
# <a name="compiler-error-c2002"></a>Erro do compilador C2002

constante de caractere largo inválida

A constante de multibyte caracteres não é válida.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. A constante de caractere largo contém mais bytes do que o esperado.

1. O cabeçalho padrão STDDEF. h não está incluído.

1. Caracteres largos não podem ser concatenados com literais de cadeia de caracteres comuns.

1. Uma constante de caractere largo deve ser precedida pelo caractere ' L':

    ```
    L'mbconst'
    ```

1. Para a C++Microsoft, os argumentos de texto de uma diretiva de pré-processador devem ser ASCII. Por exemplo, a diretiva, `#pragma message(L"string")`, não é válida.
