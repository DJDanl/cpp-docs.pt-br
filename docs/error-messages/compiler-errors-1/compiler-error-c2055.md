---
title: Erro do compilador C2055
ms.date: 11/04/2016
f1_keywords:
- C2055
helpviewer_keywords:
- C2055
ms.assetid: 6cec79cc-6bec-443f-9897-fbf5452718c7
ms.openlocfilehash: 9cb6e4d5891c5aefc9d66e7d70a5cd7685ccd393
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302036"
---
# <a name="compiler-error-c2055"></a>Erro do compilador C2055

esperada lista de parâmetros formais, não uma lista de tipos

Uma definição de função contém uma lista de tipos de parâmetros em vez de uma lista de parâmetros formais. O ANSI C requer que os parâmetros formais sejam nomeados, a menos que sejam nulos ou reticências (`...`).

O exemplo a seguir gera C2055:

```c
// C2055.c
// compile with: /c
void func(int, char) {}  // C2055
void func (int i, char c) {}   // OK
```
