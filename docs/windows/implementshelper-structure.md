---
title: Estrutura ImplementsHelper | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ImplementsHelper
dev_langs:
- C++
helpviewer_keywords:
- ImplementsHelper structure
ms.assetid: b857ba80-81bd-4e53-92b6-210991954243
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 58f27e418946987633f771bc8d2c3224bc2cd7fd
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33875933"
---
# <a name="implementshelper-structure"></a>Estrutura ImplementsHelper
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename RuntimeClassFlagsT,  
   typename ILst,  
   bool IsDelegateToClass  
>  
friend struct Details::ImplementsHelper;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `RuntimeClassFlagsT`  
 Um campo de sinalizadores que especifica um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.  
  
 `ILst`  
 Uma lista de IDs de interface.  
  
 `IsDelegateToClass`  
 Especifique `true` se a instância atual do implementa é uma classe base da primeira ID de interface em `ILst`; caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 Ajuda a implementar o [implementa](../windows/implements-structure.md) estrutura.  
  
 Este modelo percorre uma lista de interfaces e os adiciona como classes base e informações necessárias para habilitar QueryInterface.  
  
## <a name="members"></a>Membros  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ImplementsHelper`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Referência (biblioteca de tempo de execução do Windows)](http://msdn.microsoft.com/en-us/00000000-0000-0000-0000-000000000000)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)