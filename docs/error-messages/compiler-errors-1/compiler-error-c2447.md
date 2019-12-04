---
title: Erro do compilador C2447
ms.date: 11/04/2016
f1_keywords:
- C2447
helpviewer_keywords:
- C2447
ms.assetid: d1bd6e9a-ee42-4510-ae5e-6b0378f7b931
ms.openlocfilehash: 14fec374927fc798956a249773d9bec814e7a823
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74744180"
---
# <a name="compiler-error-c2447"></a>Erro do compilador C2447

“{”: cabeçalho de função ausente (lista formal antiga?)

O compilador encontrou uma chave de abertura inesperada no escopo global. Na maioria dos casos, isso é causado por um cabeçalho malformado, uma declaração posicionada incorretamente ou por um ponto-e-vírgula disperso. Para resolver esse problema, verifique se a chave de abertura segue um cabeçalho de função formado corretamente e não é precedida de uma declaração ou um ponto-e-vírgula disperso.

Esse erro também pode ser causado por uma lista de argumentos formais em linguagem C antiga. Para resolver esse problema, refatore a lista de argumentos para usar um estilo moderno, ou seja, incluído entre parênteses.

O exemplo a seguir gera C2447:

```cpp
// C2447.cpp
int c;
{}       // C2447
```
