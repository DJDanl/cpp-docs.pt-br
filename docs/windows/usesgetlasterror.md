---
title: usesgetlasterror | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.usesgetlasterror
dev_langs:
- C++
helpviewer_keywords:
- usesgetlasterror attribute
ms.assetid: d149e33d-35a7-46cb-9137-ae6883d86122
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3e5d7144f7e2a6fa3bf6937a377ccad0a711f746
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39647054"
---
# <a name="usesgetlasterror"></a>usesgetlasterror
Informa ao chamador que se houver um erro ao chamar essa função, em seguida, o chamador pode, em seguida, chamar `GetLastError` para recuperar o código de erro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[usesgetlasterror]  
```  
  
## <a name="remarks"></a>Comentários  
 O **usesgetlasterror** atributo C++ tem a mesma funcionalidade que o [usesgetlasterror](http://msdn.microsoft.com/library/windows/desktop/aa367297) atributo MIDL.  
  
## <a name="example"></a>Exemplo  
 Consulte a [idl_module](../windows/idl-module.md) exemplo para obter um exemplo de como usar **usesgetlasterror**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**módulo** atributo|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de IDL](../windows/idl-attributes.md)   