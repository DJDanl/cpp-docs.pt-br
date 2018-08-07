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
ms.openlocfilehash: f9066a9cd8985b132c1fbd9f6a97bcd0654003d2
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604497"
---
# <a name="isbaseofstrict-structure"></a>Estrutura IsBaseOfStrict
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 *Base de dados de*  
 O tipo base.  
  
 *Derivado*  
 O tipo derivado.  
  
## <a name="remarks"></a>Comentários  
 Testa se um tipo é a base de outro.  
  
 O primeiro modelo testa se um tipo é derivado de um tipo base, que pode produzir **verdadeira** ou **falso**. O segundo modelo testa se um tipo é derivado de si mesma, que sempre produz **falsos**.  
  
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