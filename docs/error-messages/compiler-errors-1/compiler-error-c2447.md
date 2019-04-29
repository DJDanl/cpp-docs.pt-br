---
title: Erro do compilador C2447
ms.date: 11/04/2016
f1_keywords:
- C2447
helpviewer_keywords:
- C2447
ms.assetid: d1bd6e9a-ee42-4510-ae5e-6b0378f7b931
ms.openlocfilehash: 64dca8313af8b640b7b03c1ab27a1a31fa90de09
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301962"
---
# <a name="compiler-error-c2447"></a>Erro do compilador C2447

“{”: cabeçalho de função ausente (lista formal antiga?)

O compilador encontrou uma chave de abertura inesperada no escopo global. Na maioria dos casos, isso é causado por um cabeçalho malformado, uma declaração posicionada incorretamente ou por um ponto-e-vírgula disperso. Para resolver esse problema, verifique se a chave de abertura segue um cabeçalho de função formado corretamente e não é precedida de uma declaração ou um ponto-e-vírgula disperso.

Esse erro também pode ser causado por uma lista de argumentos formais em linguagem C antiga. Para resolver esse problema, refatore a lista de argumentos para usar um estilo moderno, ou seja, incluído entre parênteses.

O exemplo a seguir gera C2447:

```
// C2447.cpp
int c;
{}       // C2447
```