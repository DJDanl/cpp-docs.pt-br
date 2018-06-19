---
title: ': Booltype operador comptr:: Operator | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: cfba6521-fb30-4fb8-afb2-cfab1cb5e0b8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d5efd641e5c908e5f1c4d4a3cdb78cd146b634f5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33883154"
---
# <a name="comptroperator-microsoftwrldetailsbooltype-operator"></a>ComPtr::operator Microsoft::WRL::Details::BoolType Operador
Indica se há ou não uma ComPtr está gerenciando o tempo de vida do objeto de uma interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW operator Microsoft::WRL::Details::BoolType() const;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Se uma interface está associada este ComPtr, o endereço do [boolstruct::](../windows/boolstruct-member-data-member.md) membro de dados; caso contrário, `nullptr`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)   
 [Método ComPtr::Get](../windows/comptr-get-method.md)