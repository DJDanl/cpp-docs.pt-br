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
ms.openlocfilehash: abc30204969464323d4995310cee0866139734fc
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39648003"
---
# <a name="comptrdetach-method"></a>Método ComPtr::Detach
Desassocia isso **ComPtr** objeto da interface que ele representa.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
T* Detach();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a interface que fosse representado por este **ComPtr** objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)