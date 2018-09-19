---
title: Erro do compilador C2384 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2384
dev_langs:
- C++
helpviewer_keywords:
- C2384
ms.assetid: 8145f7ad-31b1-406d-ac43-0d557feab635
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f3aa9ec8a6a94f53123c443a1149df7cdbc95c83
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46020453"
---
# <a name="compiler-error-c2384"></a>Erro do compilador C2384

'member': não é possível aplicar __declspec(thread) a um membro de um ou a classe de WinRT

O [thread](../../cpp/thread.md) `__declspec` modificador não pode ser usado em uma classe de tempo de execução do Windows ou um membro de um.

DLLs carregadas de thread estático armazenamento local no código gerenciado pode somente ser usado para estaticamente — a DLL deve ser carregada estaticamente quando o processo é iniciado. Tempo de execução do Windows não oferece suporte a armazenamento local de thread.

A linha a seguir gera C2384 e mostra como corrigi-lo no C + + c++ /CLI código CLI:

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