---
title: Estrutura BoolStruct | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::BoolStruct
dev_langs:
- C++
helpviewer_keywords:
- BoolStruct structure
ms.assetid: 666eae78-e81d-4fb7-a9e4-1ba617d6d4cd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: af2827d85a1df647dca2c02c5c6ee5a12a416d51
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33860116"
---
# <a name="boolstruct-structure"></a>Estrutura BoolStruct
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct BoolStruct;  
```  
  
## <a name="remarks"></a>Comentários  
 A estrutura BoolStruct define se um ComPtr está gerenciando o tempo de vida do objeto de uma interface. BoolStruct é usado internamente pelo [BoolType()](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md) operador.  
  
## <a name="members"></a>Membros  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados BoolStruct::Member](../windows/boolstruct-member-data-member.md)|Especifica que um [ComPtr](../windows/comptr-class.md) é ou não, é gerenciar a vida útil de objeto de uma interface.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `BoolStruct`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)   
 [Operador ComPtr::operator Microsoft::WRL::Details::BoolType](../windows/comptr-operator-microsoft-wrl-details-booltype-operator.md)