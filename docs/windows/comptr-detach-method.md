---
title: 'Método comptr:: Detach | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::Detach
dev_langs:
- C++
helpviewer_keywords:
- Detach method
ms.assetid: b9016775-1ade-4581-be1f-0d6f9c2ca658
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4d4a84131a6159c665e3947d7b642ab0592b2e36
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39465432"
---
# <a name="comptrdetach-method"></a>Método ComPtr::Detach
Desassocia isso **ComPtr** objeto da interface que ele representa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
T* Detach();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a interface que fosse representado por este **ComPtr** objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)