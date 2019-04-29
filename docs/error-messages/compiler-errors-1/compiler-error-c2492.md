---
title: Erro do compilador C2492
ms.date: 11/04/2016
f1_keywords:
- C2492
helpviewer_keywords:
- C2492
ms.assetid: 8c44c9bb-c366-4fe5-a0ab-882e38608aaa
ms.openlocfilehash: e2b08ef3e46681147c4efd77cbffadb096bbfc16
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360704"
---
# <a name="compiler-error-c2492"></a>Erro do compilador C2492

'*variável*': dados com duração de armazenamento de thread podem não ter dll interface

A variável é declarada com o [thread](../../cpp/thread.md) de atributo e com a DLL de interface. O endereço do `thread` variável não é conhecida até o tempo de execução, portanto, ele não pode ser vinculado a uma DLL de importação ou exportação.

O exemplo a seguir gera C2492:

```
// C2492.cpp
// compile with: /c
class C {
public:
   char   ch;
};

__declspec(dllexport) __declspec(thread) C c_1;   // C2492
__declspec(thread) C c_1;   // OK
```