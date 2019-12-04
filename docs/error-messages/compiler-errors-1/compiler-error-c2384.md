---
title: Erro do compilador C2384
ms.date: 11/04/2016
f1_keywords:
- C2384
helpviewer_keywords:
- C2384
ms.assetid: 8145f7ad-31b1-406d-ac43-0d557feab635
ms.openlocfilehash: 2ce5c2f2540fbd2aca3509fa1dac55073a002abb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745248"
---
# <a name="compiler-error-c2384"></a>Erro do compilador C2384

' member ': não é possível aplicar __declspec (thread) a um membro de uma classe gerenciada ou WinRT

O modificador de `__declspec` de [thread](../../cpp/thread.md) não pode ser usado em um membro de uma classe gerenciada ou Windows Runtime.

O armazenamento local de thread estático no código gerenciado só pode ser usado para DLLs carregadas estaticamente — a DLL deve ser carregada estaticamente quando o processo é iniciado. Windows Runtime não dá suporte ao armazenamento local de threads.

A linha a seguir gera C2384 e mostra como corrigi-lo C++no código/CLI:

```cpp
// C2384.cpp
// compile with: /clr /c
public ref class B {
public:
   __declspec( thread ) static int tls_i = 1;   // C2384

   // OK - declare with attribute instead
   [System::ThreadStaticAttribute]
   static int tls_j;
};
```
