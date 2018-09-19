---
title: Compilador aviso (nível 1) C4010 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4010
dev_langs:
- C++
helpviewer_keywords:
- C4010
ms.assetid: d607a9ff-8f8f-45c0-b07b-3b2f439e5485
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 52449689d329cee45cc69b63c315ce9335befbe0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46073082"
---
# <a name="compiler-warning-level-1-c4010"></a>Compilador aviso (nível 1) C4010

comentário de linha única contém caractere de continuação de linha

Um comentário de linha única, que é apresentado pelo / /, contém uma barra invertida (\\) que serve como um caractere de continuação de linha. O compilador considera que a próxima linha a ser uma continuação e a trata como um comentário.

Alguns sintaxe orientada para editores não indicam a linha após o caractere de continuação como um comentário. Ignore sintaxe colorida em todas as linhas que causam esse aviso.

O exemplo a seguir gera C4010:

```
// C4010.cpp
// compile with: /WX
int main() {
   // the next line is also a comment because of the backslash \
   int a = 3; // C4010
   a++;
}
```