---
title: Erro do compilador C2480
ms.date: 11/04/2016
f1_keywords:
- C2480
helpviewer_keywords:
- C2480
ms.assetid: 1a58d1c2-971b-4084-96fa-f94aa51c02f1
ms.openlocfilehash: 90016b65d4ddd58da3fb3c5ab6d81322dc0ef394
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62187584"
---
# <a name="compiler-error-c2480"></a>Erro do compilador C2480

'identifier': 'thread' só é válido para itens de dados de extensão static

Não é possível usar o `thread` com uma variável automática, o membro de dados não estáticos, o parâmetro de função ou em declarações de função ou definições de atributo.

Use o `thread` atributo para as variáveis globais, membros de dados estáticos e variáveis estáticas locais apenas.

O exemplo a seguir gera C2480:

```
// C2480.cpp
// compile with: /c
__declspec( thread ) void func();   // C2480
__declspec( thread ) static int i;   // OK
```