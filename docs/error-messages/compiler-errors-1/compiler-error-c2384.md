---
title: Erro do compilador C2384
ms.date: 11/04/2016
f1_keywords:
- C2384
helpviewer_keywords:
- C2384
ms.assetid: 8145f7ad-31b1-406d-ac43-0d557feab635
ms.openlocfilehash: 321ccd23bc273f5fa548f75fd44bc320bcf4c426
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225508"
---
# <a name="compiler-error-c2384"></a>Erro do compilador C2384

' member ': não é possível aplicar __declspec (thread) a um membro de uma classe gerenciada ou WinRT

O [thread](../../cpp/thread.md) **`__declspec`** modificador de thread não pode ser usado em um membro de uma classe gerenciada ou Windows Runtime.

O armazenamento local de thread estático no código gerenciado só pode ser usado para DLLs carregadas estaticamente — a DLL deve ser carregada estaticamente quando o processo é iniciado. Windows Runtime não dá suporte ao armazenamento local de threads.

A linha a seguir gera C2384 e mostra como corrigi-lo no código C++/CLI:

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
