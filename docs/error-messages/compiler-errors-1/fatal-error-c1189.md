---
title: Erro fatal C1189 | Microsoft Docs
ms.custom: ''
ms.date: 04/27/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: error-reference
f1_keywords:
- C1189
dev_langs:
- C++
helpviewer_keywords:
- C1189
ms.assetid: 2e5c8a78-edd4-411c-b619-558a96be148a
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b49f227b5fda20ab0ba202d3d7eca99492509b35
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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