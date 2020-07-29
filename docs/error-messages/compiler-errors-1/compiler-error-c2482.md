---
title: Erro do compilador C2482
ms.date: 09/15/2017
f1_keywords:
- C2482
helpviewer_keywords:
- C2482
ms.assetid: 98c87da2-625c-4cc2-9bf7-78d15921e779
ms.openlocfilehash: a68c3f06daf977bda4700a293803859d4aa96771
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216200"
---
# <a name="compiler-error-c2482"></a>Erro do compilador C2482

>'*Identifier*': inicialização dinâmica de dados de ' thread ' não permitida em código gerenciado/WinRT

## <a name="remarks"></a>Comentários

Em código gerenciado ou WinRT, as variáveis declaradas usando o atributo modificador da classe de armazenamento [__declspec (thread)](../../cpp/thread.md) ou o especificador de classe de armazenamento [thread_local](../../cpp/storage-classes-cpp.md#thread_local) não podem ser inicializadas com uma expressão que requer avaliação em tempo de execução. Uma expressão estática é necessária para inicializar `__declspec(thread)` ou **`thread_local`** dados nesses ambientes de tempo de execução.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2482 no código gerenciado (**/CLR**) e no WinRT (**/zw**):

```cpp
// C2482.cpp
// For managed example, compile with: cl /EHsc /c /clr C2482.cpp
// For WinRT example, compile with: cl /EHsc /c /ZW C2482.cpp
#define Thread __declspec( thread )
Thread int tls_i1 = tls_i1;   // C2482

int j = j;   // OK in C++; C error
Thread int tls_i2 = sizeof( tls_i2 );   // Okay in C and C++
```

Para corrigir esse problema, inicialize o armazenamento local de thread usando uma **`constexpr`** expressão estática, ou constante. Execute qualquer inicialização específica ao thread separadamente.
