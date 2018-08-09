---
title: 'Método asyncbase:: Firecompletion | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::FireCompletion
dev_langs:
- C++
helpviewer_keywords:
- FireCompletion method
ms.assetid: b5e29d6d-52e7-4148-a7f3-a313b1359819
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 199d84afe198c4fc41808144105ea704822aa00a
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39646601"
---
# <a name="asyncbasefirecompletion-method"></a>Método AsyncBase::FireCompletion
Invoca o manipulador de eventos de conclusão ou redefine o delegado de progresso interno.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
void FireCompletion(  
   void  
) override;  
  
virtual void FireCompletion();  
```  
  
## <a name="remarks"></a>Comentários  
 A primeira versão do **FireCompletion()** redefine a variável do delegado de progresso interno. A segunda versão invoca o manipulador de eventos de conclusão, se a operação assíncrona for concluída.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)