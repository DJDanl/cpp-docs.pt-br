---
title: virtual (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- virtual_cpp
- virtual
dev_langs:
- C++
helpviewer_keywords:
- virtual base classes, declaring
- base classes, virtual
- virtual functions, declaring
- virtual keyword [C++]
ms.assetid: c2eb987d-6cf3-43b6-aa0c-29a6f561b1ae
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 851f911dd7c49df1d685afe63ef5134cf0d5f175
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
