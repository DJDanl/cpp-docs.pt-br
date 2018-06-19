---
title: Classe RemoveIUnknown | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::RemoveIUnknown
dev_langs:
- C++
ms.assetid: 998e711a-7d1a-44c6-a016-e6167aa40863
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: eb005bc3cbf411a7d5b5ddbfa44cd6aecf802105
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33879536"
---
# <a name="removeiunknown-class"></a>Classe RemoveIUnknown
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename T  
>  
struct RemoveIUnknown;  
  
template <  
   typename T  
>  
class RemoveIUnknown : public T;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe.  
  
## <a name="remarks"></a>Comentários  
 Faz com que um tipo que é equivalente a uma `IUnknown`-baseado em tipo, mas possui não virtuais `QueryInterface`, `AddRef`, e `Release` funções de membro.  
  
 Por padrão, os métodos de fornecem virtual `QueryInterface`, `AddRef`e métodos de versão. No entanto, `ComPtr` não requer a sobrecarga de métodos virtuais. `RemoveIUnknown` elimina essa sobrecarga fornecendo particular, não virtuais `QueryInterface`, `AddRef`, e `Release` métodos.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`ReturnType`|Um sinônimo para um tipo que é equivalente ao parâmetro de modelo `T` , mas tem membros de IUnknown.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `T`  
  
 `RemoveIUnknown`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)