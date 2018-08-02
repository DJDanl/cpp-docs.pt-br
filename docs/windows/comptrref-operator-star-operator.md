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
ms.openlocfilehash: 55d4fa6156c4ef2032111c0306c3cff8dce14059
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39461446"
---
# <a name="comptrrefoperator-operator"></a>Operador ComPtrRef::operator*
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
InterfaceType* operator *();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Ponteiro para a interface representado pelo atual **ComPtrRef** objeto.  
  
## <a name="remarks"></a>Comentários  
 Recupera o ponteiro para a interface representado pelo atual **ComPtrRef** objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtrRef](../windows/comptrref-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)