---
title: Erro do compilador C2482
ms.date: 09/15/2017
f1_keywords:
- C2482
helpviewer_keywords:
- C2482
ms.assetid: 98c87da2-625c-4cc2-9bf7-78d15921e779
ms.openlocfilehash: 481920fa2d8c32bc872e7b8805188cc674e6fe28
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62375048"
---
# <a name="compiler-error-c2482"></a>Erro do compilador C2482

>'*identificador*': inicialização dinâmica de dados 'thread' não permitidas no código gerenciado/WinRT

## <a name="remarks"></a>Comentários

No gerenciado ou código do WinRT, as variáveis declaradas usando o [__declspec(thread)](../../cpp/thread.md) atributo de modificador de classe de armazenamento ou o [thread_local](../../cpp/storage-classes-cpp.md#thread_local) especificador de classe de armazenamento não pode ser inicializado com uma expressão que requer avaliação em tempo de execução. Uma expressão estática é necessário para inicializar `__declspec(thread)` ou `thread_local` dados nesses ambientes de tempo de execução.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2482 gerenciadas (**/clr**) e, no WinRT (**/ZW**) código:

```cpp
// C2482.cpp
// For managed example, compile with: cl /EHsc /c /clr C2482.cpp
// For WinRT example, compile with: cl /EHsc /c /ZW C2482.cpp
#define Thread __declspec( thread )
Thread int tls_i1 = tls_i1;   // C2482

int j = j;   // OK in C++; C error
Thread int tls_i2 = sizeof( tls_i2 );   // Okay in C and C++
```

Para corrigir esse problema, inicializar o armazenamento local de thread usando uma constante **constexpr**, ou uma expressão estática. Execute qualquer inicialização específicas de thread separadamente.