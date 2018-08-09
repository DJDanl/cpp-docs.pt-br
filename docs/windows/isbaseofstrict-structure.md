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
ms.openlocfilehash: d4690c15adac7be66ca916b1fc0f769e6c50190c
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40017886"
---
# <a name="isbaseofstrict-structure"></a>Estrutura IsBaseOfStrict
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
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