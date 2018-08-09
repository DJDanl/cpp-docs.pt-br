---
title: 'Método asyncbase:: OnClose | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::OnClose
dev_langs:
- C++
helpviewer_keywords:
- OnClose method
ms.assetid: 96766450-c262-4611-8534-7d190b799142
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3c1b888b9d3e3f3c80c3aff40f5fd545ece9cca6
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39650632"
---
# <a name="asyncbaseonclose-method"></a>Método AsyncBase::OnClose
Quando substituído em uma classe derivada, fecha uma operação assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
virtual void OnClose(  
   void  
) = 0;  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)   
 [Método AsyncBase::Close](../windows/asyncbase-close-method.md)