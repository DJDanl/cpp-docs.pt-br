---
title: Erro fatal C1189 | Microsoft Docs
ms.custom: ''
ms.date: 04/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1189
dev_langs:
- C++
helpviewer_keywords:
- C1189
ms.assetid: 2e5c8a78-edd4-411c-b619-558a96be148a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 051b7eb965526d12311dfacaeae7a00e4fbe4e75
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1189"></a>Erro fatal C1189

> **\#Erro:** *mensagem de erro fornecido pelo usuário*

## <a name="remarks"></a>Comentários

C1189 é gerado pelo `#error` diretiva. O desenvolvedor que códigos de diretiva especifica o texto da mensagem de erro. Para obter mais informações, consulte [#error diretiva (C/C++)](../../preprocessor/hash-error-directive-c-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C1189. No exemplo, o desenvolvedor emite uma mensagem de erro personalizada porque o `_WIN32` identificador não está definido:

```cpp
// C1189.cpp
#undef _WIN32
#if !defined(_WIN32)
#error _WIN32 must be defined   // C1189
#endif
```

## <a name="see-also"></a>Consulte também

[Diretiva #define (C/C++)](../../preprocessor/hash-define-directive-c-cpp.md)