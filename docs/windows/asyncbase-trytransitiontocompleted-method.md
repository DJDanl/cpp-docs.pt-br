---
title: 'Método: Trytransitiontocompleted | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::TryTransitionToCompleted
dev_langs:
- C++
helpviewer_keywords:
- TryTransitionToCompleted method
ms.assetid: 8d038e0a-47ec-4cfc-8aeb-6821282df67a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1f628acd1424af11cab5040b2c65d528f1774dff
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33861253"
---
# <a name="asyncbasetrytransitiontocompleted-method"></a>Método AsyncBase::TryTransitionToCompleted
Indica se a operação assíncrona atual foi concluída.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
bool TryTransitionToCompleted(  
   void  
);  
```  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se a operação assíncrona foi concluída; Caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)