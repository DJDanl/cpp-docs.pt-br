---
title: Erro do compilador C2480
ms.date: 11/04/2016
f1_keywords:
- C2480
helpviewer_keywords:
- C2480
ms.assetid: 1a58d1c2-971b-4084-96fa-f94aa51c02f1
ms.openlocfilehash: 3e495a8019405a558511637467133877dae1183e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743517"
---
# <a name="compiler-error-c2480"></a>Erro do compilador C2480

' identifier ': ' thread ' só é válido para itens de dados de extensão static

Você não pode usar o atributo `thread` com uma variável automática, um membro de dados não estático, um parâmetro de função ou em declarações ou definições de função.

Use o atributo `thread` para variáveis globais, membros de dados estáticos e variáveis estáticas locais somente.

O exemplo a seguir gera C2480:

```cpp
// C2480.cpp
// compile with: /c
__declspec( thread ) void func();   // C2480
__declspec( thread ) static int i;   // OK
```
