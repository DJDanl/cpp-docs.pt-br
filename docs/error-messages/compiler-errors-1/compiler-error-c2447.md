---
title: Erro do compilador C2447 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2447
dev_langs:
- C++
helpviewer_keywords:
- C2447
ms.assetid: d1bd6e9a-ee42-4510-ae5e-6b0378f7b931
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e9cc18c8e6ffb31de062957e16f6f3a6573379ee
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46035130"
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