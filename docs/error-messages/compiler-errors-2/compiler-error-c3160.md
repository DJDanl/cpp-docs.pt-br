---
title: Erro do compilador C3160 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3160
dev_langs:
- C++
helpviewer_keywords:
- C3160
ms.assetid: a250c433-8adf-43b9-8dee-c3794e09b0a5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bf3ecc18e1afc9b13e47ad8b20bb92f7686d0cfc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46042267"
---
# <a name="compiler-error-c3160"></a>Erro do compilador C3160

'ponteiro': uma classe de WinRT ou membro de dados de um gerenciado não pode ter esse tipo

Ponteiros de coleta de lixo interiores podem apontar para o interior de um ou a classe do WinRT. Como eles são mais lentos que os ponteiros do objeto inteiro e requerem tratamento especial pelo coletor de lixo, você não pode declarar ponteiros gerenciados internos como membros de uma classe.

O exemplo a seguir gera C3160:

```
// C3160.cpp
// compile with: /clr
ref struct A {
   // cannot create interior pointers inside a class
   interior_ptr<int> pg;   // C3160
   int g;   // OK
   int* pg2;   // OK
};

int main() {
   interior_ptr<int> pg2;   // OK
}
```
