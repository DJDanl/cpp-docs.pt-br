---
title: Erro do compilador C2002 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2002
dev_langs:
- C++
helpviewer_keywords:
- C2002
ms.assetid: 91982314-203a-4de1-b884-94e39a623f61
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b87a7fe1513c695344676624ae1968060097c885
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46116913"
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