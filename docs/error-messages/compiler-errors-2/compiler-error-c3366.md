---
title: Erro do compilador C3366 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3366
dev_langs:
- C++
helpviewer_keywords:
- C3366
ms.assetid: efc55bcf-c16d-43c1-a36f-87a6165fa2a8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b3638ba2415839c044d9a82d82d0abe8bc2c98e2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46026498"
---
# <a name="compiler-error-c3366"></a>Erro do compilador C3366

'variable': membros de dados estáticos gerenciados ou WinRTtypes devem ser definidos dentro da definição de classe

Você tentou fazer referência a um membro estático de uma classe de WinRT ou .NET ou a interface fora da definição da classe ou interface.

O compilador precisa saber a definição completa da classe (para emitir os metadados após uma passagem) e requer que os membros de dados estáticos sejam inicializados dentro da classe.

Por exemplo, o exemplo a seguir gera C3366 e mostra como corrigi-lo:

```
// C3366.cpp
// compile with: /clr /c
ref class X {
   public:
   static int i;   // initialize i here to avoid C3366
};

int X::i = 5;      // C3366
```
