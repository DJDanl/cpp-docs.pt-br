---
title: Estrutura IsSame | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: internal/Microsoft::WRL::Details::IsSame
dev_langs: C++
helpviewer_keywords: IsSame structure
ms.assetid: 1eddbc3f-3cc5-434f-8495-e4477e1f868e
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bae4ecb6f03b7b1cdb0fae02f211dd613e7c39d7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="issame-structure"></a>Estrutura IsSame
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename T1,  
   typename T2  
>  
struct IsSame;  
template <  
   typename T1  
>  
struct IsSame<T1, T1>;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T1`  
 Um tipo.  
  
 `T2`  
 Outro tipo.  
  
## <a name="remarks"></a>Comentários  
 Testes se um tipo especificado é igual a outro tipo especificado.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constants"></a>Constantes públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Constante IsSame::value](../windows/issame-value-constant.md)|Indica se um tipo é igual a outro.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IsSame`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)