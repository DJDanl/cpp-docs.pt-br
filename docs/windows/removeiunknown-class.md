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
ms.openlocfilehash: 69775303c5a12f82ef2a31cc61112af4b14d3aad
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39606163"
---
# <a name="removeiunknown-class"></a>Classe RemoveIUnknown
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Uma classe.  
  
## <a name="remarks"></a>Comentários  
 Cria um tipo que é equivalente a um `IUnknown`-tipo com base, mas tem não virtuais `QueryInterface`, `AddRef`, e `Release` funções de membro.  
  
 Por padrão, os métodos fornecem virtual `QueryInterface`, `AddRef`, e `Release` métodos. No entanto, `ComPtr` não requer a sobrecarga de métodos virtuais. `RemoveIUnknown` elimina essa sobrecarga, fornecendo privado e não virtuais `QueryInterface`, `AddRef`, e `Release` métodos.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`ReturnType`|Um sinônimo para um tipo que é equivalente ao parâmetro de modelo *T* , mas tem não virtuais `IUnknown` membros.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `T`  
  
 `RemoveIUnknown`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)