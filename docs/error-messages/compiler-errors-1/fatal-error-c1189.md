---
title: Erro fatal C1189
ms.date: 04/27/2018
f1_keywords:
- C1189
helpviewer_keywords:
- C1189
ms.assetid: 2e5c8a78-edd4-411c-b619-558a96be148a
ms.openlocfilehash: 2217b865109cc48151e4e96b2d38b88764c0c64f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203615"
---
# <a name="fatal-error-c1189"></a>Erro fatal C1189

> **erro de\#:** *mensagem de erro fornecida pelo usuário*

## <a name="remarks"></a>Comentários

C1189 é gerado pela diretiva `#error`. O desenvolvedor que codifica a diretiva especifica o texto da mensagem de erro. Para obter mais informações, consulte [diretiva de #error (C++C/)](../../preprocessor/hash-error-directive-c-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C1189. No exemplo, o desenvolvedor emite uma mensagem de erro personalizada porque o identificador de `_WIN32` não está definido:

```cpp
// C1189.cpp
#undef _WIN32
#if !defined(_WIN32)
#error _WIN32 must be defined   // C1189
#endif
```

## <a name="see-also"></a>Confira também

[Diretiva #define (C/C++)](../../preprocessor/hash-define-directive-c-cpp.md)
