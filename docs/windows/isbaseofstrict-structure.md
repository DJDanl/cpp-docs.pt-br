---
title: Estrutura IsBaseOfStrict | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::IsBaseOfStrict
dev_langs:
- C++
helpviewer_keywords:
- IsBaseOfStrict structure
ms.assetid: 6fed7366-c8d4-4991-b4fb-43ed93f8e1bf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: db8f315c0589ceb7cd9411873152fe644985818e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33876885"
---
# <a name="isbaseofstrict-structure"></a>Estrutura IsBaseOfStrict
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename Base,  
   typename Derived  
>  
  
struct IsBaseOfStrict;  
template <  
   typename Base  
>  
struct IsBaseOfStrict<Base, Base>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Base`  
 O tipo base.  
  
 `Derived`  
 O tipo derivado.  
  
## <a name="remarks"></a>Comentários  
 Testa se um tipo é a base de outro.  
  
 O primeiro modelo testa se um tipo é derivado de um tipo base, que pode produzir **true** ou **false**. O segundo modelo testa se um tipo é derivado de si mesma, que sempre produz **false**.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante IsBaseOfStrict::value](../windows/isbaseofstrict-value-constant.md)|Indica se um tipo é a base de outro.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IsBaseOfStrict`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)