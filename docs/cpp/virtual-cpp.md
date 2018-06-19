---
title: virtual (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- virtual_cpp
- virtual
dev_langs:
- C++
helpviewer_keywords:
- virtual base classes [C++], declaring
- base classes [C++], virtual
- virtual functions [C++], declaring
- virtual keyword [C++]
ms.assetid: c2eb987d-6cf3-43b6-aa0c-29a6f561b1ae
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 909fd3fde92479b2e5407608026cb01ec17fced2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32421790"
---
# <a name="virtual-c"></a>virtual (C++)
A palavra-chave `virtual` declara uma função virtual ou uma classe base virtual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
virtual [type-specifiers] member-function-declarator  
virtual [access-specifier] base-class-name  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `type-specifiers`  
 Especifica o tipo de retorno da função membro virtual.  
  
 `member-function-declarator`  
 Declara uma função membro.  
  
 `access-specifier`  
 Define o nível de acesso à classe base, `public`, `protected` ou `private`. Pode aparecer antes ou depois da palavra-chave `virtual`.  
  
 `base-class-name`  
 Identifica um tipo de classe declarado previamente.  
  
## <a name="remarks"></a>Comentários  
 Consulte [funções virtuais](../cpp/virtual-functions.md) para obter mais informações.  
  
 Consulte também as seguintes palavras-chave: [classe](../cpp/class-cpp.md), [privada](../cpp/private-cpp.md), [pública](../cpp/public-cpp.md), e [protegido](../cpp/protected-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)