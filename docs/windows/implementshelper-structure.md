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
ms.openlocfilehash: eca429578fd9b58a2a3229199d53812a494af045
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40018342"
---
# <a name="implementshelper-structure"></a>Estrutura ImplementsHelper
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <  
   typename RuntimeClassFlagsT,  
   typename ILst,  
   bool IsDelegateToClass  
>  
friend struct Details::ImplementsHelper;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *RuntimeClassFlagsT*  
 Um campo de sinalizadores que especifica um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) enumeradores.  
  
 *ILst*  
 Uma lista de IDs de interface.  
  
 *IsDelegateToClass*  
 Especificar **verdadeira** se a instância atual do `Implements` é uma classe base da primeira ID de interface no *ILst*; caso contrário, **false**.  
  
## <a name="remarks"></a>Comentários  
 Ajuda a implementar o [implementa](../windows/implements-structure.md) estrutura.  
  
 Esse modelo percorre uma lista de interfaces e os adiciona como classes base e como as informações necessárias para habilitar `QueryInterface`.  
  
## <a name="members"></a>Membros  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ImplementsHelper`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Referência (biblioteca de tempo de execução do Windows)](http://msdn.microsoft.com/00000000-0000-0000-0000-000000000000)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)