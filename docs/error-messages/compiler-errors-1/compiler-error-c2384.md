---
title: Erro do compilador C2384
ms.date: 11/04/2016
f1_keywords:
- C2384
helpviewer_keywords:
- C2384
ms.assetid: 8145f7ad-31b1-406d-ac43-0d557feab635
ms.openlocfilehash: 1909fb999dd0f60224029b726f773c11fa69ee40
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62347149"
---
# <a name="compiler-error-c2384"></a>Erro do compilador C2384

'member': não é possível aplicar __declspec(thread) a um membro de um ou a classe de WinRT

O [thread](../../cpp/thread.md) `__declspec` modificador não pode ser usado em uma classe de tempo de execução do Windows ou um membro de um.

DLLs carregadas de thread estático armazenamento local no código gerenciado pode somente ser usado para estaticamente — a DLL deve ser carregada estaticamente quando o processo é iniciado. Tempo de execução do Windows não oferece suporte a armazenamento local de thread.

A linha a seguir gera C2384 e mostra como corrigi-lo no C++código /CLI:

```
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