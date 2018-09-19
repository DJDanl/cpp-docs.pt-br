---
title: Erro do compilador C2055 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2055
dev_langs:
- C++
helpviewer_keywords:
- C2055
ms.assetid: 6cec79cc-6bec-443f-9897-fbf5452718c7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d6c63d79325417fbd9b1f451fb4a51f13957b4df
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46019336"
---
# <a name="compiler-error-c2055"></a>Erro do compilador C2055

esperada lista de parâmetros formais, não uma lista de tipos

Uma definição de função contém uma lista de tipos de parâmetro em vez de uma lista de parâmetros formais. ANSI C requer parâmetros formais para ser chamado, a menos que sejam void ou um sinal de reticências (`...`).

O exemplo a seguir gera C2055:

```
// C2055.c
// compile with: /c
void func(int, char) {}  // C2055
void func (int i, char c) {}   // OK
```