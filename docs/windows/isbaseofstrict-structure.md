---
title: Estrutura IsBaseOfStrict | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: internal/Microsoft::WRL::Details::IsBaseOfStrict
dev_langs: C++
helpviewer_keywords: IsBaseOfStrict structure
ms.assetid: 6fed7366-c8d4-4991-b4fb-43ed93f8e1bf
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8a8e40bec0f4dedf02aab14b2c8072ccc3e60bbb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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