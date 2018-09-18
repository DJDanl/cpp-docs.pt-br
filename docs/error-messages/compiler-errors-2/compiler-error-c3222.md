---
title: Erro do compilador C3222 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3222
dev_langs:
- C++
helpviewer_keywords:
- C3222
ms.assetid: 5624bde8-2fd0-4b8b-92ce-5dfbaf91cf93
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 30231f74b379cd9d69806fbd4b49ba0cb55ad871
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46048312"
---
# <a name="compiler-error-c3222"></a>Erro do compilador C3222

'parameter': não é possível declarar argumentos padrão para o membro de tipo de WinRT ou funções de um ou funções genéricas

Não é permitido para declarar um parâmetro de método com um argumento padrão. Um formulário sobrecarregado do método é uma maneira de contornar esse problema. Ou seja, definir um método com o mesmo nome sem parâmetros e, em seguida, inicialize a variável no corpo do método.

O exemplo a seguir gera C3222:

```
// C3222_2.cpp
// compile with: /clr
public ref class G {
   void f( int n = 0 );   // C3222
};
```
