---
title: 'Comptrref:: Operator InterfaceType * * operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRef::operator InterfaceType**
dev_langs:
- C++
helpviewer_keywords:
- operator InterfaceType** operator
ms.assetid: b32e3240-a4f0-4998-a55f-d4e35dc9a15a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 416b30c55027debddc153c44e55c7a4be512703d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33870506"
---
# <a name="comptrrefoperator-interfacetype-operator"></a>ComPtrRef::operator InterfaceType** Operador
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
operator InterfaceType**();  
```  
  
## <a name="remarks"></a>Comentários  
 Exclui o objeto ComPtrRef atual e retorna um ponteiro-para-um-ponteiro para a interface que foi representada pelo objeto ComPtrRef.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtrRef](../windows/comptrref-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)