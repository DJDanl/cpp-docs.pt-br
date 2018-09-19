---
title: Erro do compilador C2011 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2011
dev_langs:
- C++
helpviewer_keywords:
- C2011
ms.assetid: 992c9d51-e850-4d53-b86b-02e73b38249c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 09946a6a3e974293e65a582c735e3de42503f0c3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46115028"
---
# <a name="compiler-error-c2011"></a>Erro do compilador C2011

'identifier': redefinição do tipo 'type'

O identificador já foi definido como `type`. Verifique se há redefinições do identificador.

Você também pode obter C2011 se você importar um arquivo de cabeçalho ou biblioteca de tipos mais de uma vez no mesmo arquivo. Para evitar várias inclusões dos tipos definidos em um arquivo de cabeçalho, use inclua protege ou um `#pragma` [depois que](../../preprocessor/once.md) diretiva no arquivo de cabeçalho.

Se você precisar localizar a declaração inicial do tipo redefinido, você pode usar o [/p](../../build/reference/p-preprocess-to-a-file.md) sinalizador do compilador para gerar a saída pré-processada passados para o compilador. Você pode usar as ferramentas de pesquisa de texto para localizar ocorrências do identificador redefinido no arquivo de saída.

O exemplo a seguir gera C2011 e mostra uma maneira de corrigir isso:

```
// C2011.cpp
// compile with: /c
struct S;
union S;   // C2011
union S2;   // OK
```