---
title: Erro fatal C1104
ms.date: 11/04/2016
f1_keywords:
- C1104
helpviewer_keywords:
- C1104
ms.assetid: 45bd85c4-77d3-4d3c-b167-49c563aefb4d
ms.openlocfilehash: a26e65e98b44a69eb14daf6d835fafb23362dfa2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747326"
---
# <a name="fatal-error-c1104"></a>Erro fatal C1104

erro fatal ao importar LIBID: ' message '

O compilador detectou um problema ao importar uma biblioteca de tipos.  Por exemplo, você não pode especificar uma biblioteca de tipos com LIBID e também especificar `no_registry`.

Para obter mais informações, consulte [#import diretiva](../../preprocessor/hash-import-directive-cpp.md).

O exemplo a seguir gerará C1104:

```cpp
// C1104.cpp
#import "libid:11111111.1111.1111.1111.111111111111" version("4.0") lcid("9") no_registry auto_search   // C1104
```
