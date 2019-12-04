---
title: Erro do compilador C2011
ms.date: 11/04/2016
f1_keywords:
- C2011
helpviewer_keywords:
- C2011
ms.assetid: 992c9d51-e850-4d53-b86b-02e73b38249c
ms.openlocfilehash: dc13829a267deea1f412eb2d8f86057f01dc0e1c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74752412"
---
# <a name="compiler-error-c2011"></a>Erro do compilador C2011

' identifier ': a redefinição do tipo ' type '

O identificador já foi definido como `type`. Verifique se há redefinições do identificador.

Você também poderá obter C2011 se importar um arquivo de cabeçalho ou uma biblioteca de tipos mais de uma vez no mesmo arquivo. Para evitar várias inclusões dos tipos definidos em um arquivo de cabeçalho, use a diretiva incluir proteções ou uma `#pragma`uma [vez](../../preprocessor/once.md) no arquivo de cabeçalho.

Se você precisar localizar a declaração inicial do tipo redefinido, poderá usar o sinalizador de compilador [/p](../../build/reference/p-preprocess-to-a-file.md) para gerar a saída pré-processada passada para o compilador. Você pode usar ferramentas de pesquisa de texto para localizar instâncias do identificador redefinido no arquivo de saída.

O exemplo a seguir gera C2011 e mostra uma maneira de corrigi-lo:

```cpp
// C2011.cpp
// compile with: /c
struct S;
union S;   // C2011
union S2;   // OK
```
