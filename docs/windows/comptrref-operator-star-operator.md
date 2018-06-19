---
title: 'Operador comptrref:: Operator * | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::Details::ComPtrRef::operator*
dev_langs:
- C++
helpviewer_keywords:
- operator* operator
ms.assetid: 0287ca7a-4ce1-47f7-bab6-714fca3e04bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 03de935ab9195cddf3ea9936b694b55ba2cec34c
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33883466"
---
# <a name="comptrrefoperator-operator"></a>Operador ComPtrRef::operator*
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
InterfaceType* operator *();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Ponteiro para a interface representado pelo objeto ComPtrRef atual.  
  
## <a name="remarks"></a>Comentários  
 Recupera o ponteiro para a interface representado pelo objeto ComPtrRef atual.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtrRef](../windows/comptrref-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)