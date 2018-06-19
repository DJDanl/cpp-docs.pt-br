---
title: Classe DontUseNewUseMake | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::DontUseNewUseMake
dev_langs:
- C++
helpviewer_keywords:
- DontUseNewUseMake class
ms.assetid: 8b38d07b-fc14-4cea-afb9-4c1a7dde0093
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f343d0b47d50cd375d186c29ff55b91898aa9c61
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33872322"
---
# <a name="dontusenewusemake-class"></a>Classe DontUseNewUseMake
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class DontUseNewUseMake;  
```  
  
## <a name="remarks"></a>Comentários  
 Impede o uso de operador `new` em RuntimeClass. Consequentemente, você deve usar o [função Make](../windows/make-function.md) em vez disso.  
  
## <a name="members"></a>Membros  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador DontUseNewUseMake::operator new](../windows/dontusenewusemake-operator-new-operator.md)|Sobrecargas de operador `new` e impede que ele seja usado em RuntimeClass.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `DontUseNewUseMake`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)   
 [Função Make](../windows/make-function.md)