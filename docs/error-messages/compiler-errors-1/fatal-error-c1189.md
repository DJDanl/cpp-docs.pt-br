---
title: Erro fatal C1189
ms.date: 04/27/2018
f1_keywords:
- C1189
helpviewer_keywords:
- C1189
ms.assetid: 2e5c8a78-edd4-411c-b619-558a96be148a
ms.openlocfilehash: 06d42316a0109ac063bba43cefebd9aab71c2e72
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62229053"
---
# <a name="fatal-error-c1189"></a>Erro fatal C1189

> **\#Erro:** *mensagem de erro fornecida pelo usuário*

## <a name="remarks"></a>Comentários

C1189 é gerado pelo `#error` diretiva. O desenvolvedor que códigos a diretiva especifica o texto da mensagem de erro. Para obter mais informações, consulte [#error diretiva (C/C++)](../../preprocessor/hash-error-directive-c-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C1189. No exemplo, o desenvolvedor emitirá uma mensagem de erro personalizada porque o `_WIN32` identificador não está definido:

```cpp
// C1189.cpp
#undef _WIN32
#if !defined(_WIN32)
#error _WIN32 must be defined   // C1189
#endif
```

## <a name="see-also"></a>Consulte também

[Diretiva #define (C/C++)](../../preprocessor/hash-define-directive-c-cpp.md)