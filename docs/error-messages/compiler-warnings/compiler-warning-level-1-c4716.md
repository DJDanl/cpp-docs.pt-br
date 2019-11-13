---
title: Aviso do compilador (nível 1) C4716
ms.date: 11/04/2016
f1_keywords:
- C4716
helpviewer_keywords:
- C4716
ms.assetid: d95ecfe5-870f-461f-a746-7913af98414b
ms.openlocfilehash: 5215e8fd0bdd44c9bdfc731d2b74499d38853e80
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052470"
---
# <a name="compiler-warning-level-1-c4716"></a>Aviso do compilador (nível 1) C4716

' function ' deve retornar um valor

A função fornecida não retornou um valor.

Somente funções com um tipo de retorno de void podem usar o comando Return sem um valor de retorno que acompanha.

Um valor indefinido será retornado quando essa função for chamada.

Esse aviso é promovido automaticamente para um erro. Se você quiser modificar esse comportamento, use [#pragma Aviso](../../preprocessor/warning.md).

O exemplo a seguir gera C4716:

```cpp
// C4716.cpp
// compile with: /c /W1
// C4716 expected
#pragma warning(default:4716)
int test() {
   // uncomment the following line to resolve
   // return 0;
}
```