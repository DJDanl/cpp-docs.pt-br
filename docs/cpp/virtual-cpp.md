---
title: virtual (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- virtual_cpp
- virtual
dev_langs: C++
helpviewer_keywords:
- virtual base classes [C++], declaring
- base classes [C++], virtual
- virtual functions [C++], declaring
- virtual keyword [C++]
ms.assetid: c2eb987d-6cf3-43b6-aa0c-29a6f561b1ae
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 041939197f18861d27d1f99708e27415de2b7787
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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