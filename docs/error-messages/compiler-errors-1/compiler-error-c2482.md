---
title: C2482 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 09/15/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2482
dev_langs:
- C++
helpviewer_keywords:
- C2482
ms.assetid: 98c87da2-625c-4cc2-9bf7-78d15921e779
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c3dd23069f389d0a02e10d26edb7ee4fd3c373cb
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
ms.locfileid: "34256000"
---
# <a name="compiler-error-c2482"></a>C2482 de erro do compilador

>'*identificador*': inicialização dinâmica de dados 'thread' não é permitidas no código gerenciado/WinRT

## <a name="remarks"></a>Comentários

No gerenciados ou WinRT code, as variáveis declaradas usando o [__declspec(thread)](../../cpp/thread.md) atributo de modificador de classe de armazenamento ou o [thread_local](../../cpp/storage-classes-cpp.md#thread_local) especificador de classe de armazenamento não pode ser inicializado com uma expressão Isso requer avaliação em tempo de execução. Uma expressão estática é necessário para inicializar `__declspec(thread)` ou `thread_local` dados nesses ambientes de tempo de execução.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2482 gerenciadas (**/clr**) e em WinRT (**/ZW**) código:

```cpp
// C2482.cpp
// For managed example, compile with: cl /EHsc /c /clr C2482.cpp
// For WinRT example, compile with: cl /EHsc /c /ZW C2482.cpp
#define Thread __declspec( thread )
Thread int tls_i1 = tls_i1;   // C2482

int j = j;   // OK in C++; C error
Thread int tls_i2 = sizeof( tls_i2 );   // Okay in C and C++
```

Para corrigir esse problema, inicialize o armazenamento local de thread, usando uma constante, **constexpr**, ou uma expressão estática. Execute qualquer inicialização específicas de thread separadamente.