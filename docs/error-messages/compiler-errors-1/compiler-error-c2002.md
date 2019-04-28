---
title: Erro do compilador C2002
ms.date: 11/04/2016
f1_keywords:
- C2002
helpviewer_keywords:
- C2002
ms.assetid: 91982314-203a-4de1-b884-94e39a623f61
ms.openlocfilehash: 30f472aa7a9475a19eea0e92fe5c2ea0d54e382b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62209030"
---
# <a name="compiler-error-c2002"></a>Erro do compilador C2002

constante de caractere largo inválida

A constante de caracteres multibyte não é válida.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. A constante de caractere largo contiver mais bytes que o esperado.

1. O cabeçalho padrão stddef. h não está incluído.

1. Caracteres largos não podem ser concatenados com literais de cadeia de caracteres comum.

1. Uma constante de caractere largo deve ser precedida pelo caractere "L":

    ```
    L'mbconst'
    ```

1. Para o Microsoft C++, os argumentos de texto de uma diretiva de pré-processador devem ser ASCII. Por exemplo, a diretiva `#pragma message(L"string")`, não é válido.