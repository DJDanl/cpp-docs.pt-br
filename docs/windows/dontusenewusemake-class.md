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
ms.openlocfilehash: 351b38a002c470dcd3f53e8336e393f845fdb3cf
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39569563"
---
# <a name="dontusenewusemake-class"></a>Classe DontUseNewUseMake
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class DontUseNewUseMake;  
```  
  
## <a name="remarks"></a>Comentários  
 Impeça o uso de operador **novo** em RuntimeClass. Consequentemente, você deve usar o [tornar função](../windows/make-function.md) em vez disso.  
  
## <a name="members"></a>Membros  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador DontUseNewUseMake::operator new](../windows/dontusenewusemake-operator-new-operator.md)|Sobrecarrega o operador **novo** e impede que ele seja usado em RuntimeClass.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `DontUseNewUseMake`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)   
 [Função Make](../windows/make-function.md)