---
title: 'Método comptr:: swap | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::Swap
dev_langs:
- C++
helpviewer_keywords:
- Swap method
ms.assetid: 74275f00-b24e-4b4c-b8b6-ac2aa2dd7ae9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 38fee8186d19d38075abab3bb16e2fcaac59a362
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39649871"
---
# <a name="comptrswap-method"></a>Método ComPtr::Swap
Troca a interface gerenciada pelo atual **ComPtr** com a interface gerenciada pelo especificado **ComPtr**.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
void Swap(  
   _Inout_ ComPtr&& r  
);  
  
void Swap(  
   _Inout_ ComPtr& r  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *r*  
 Um **ComPtr**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)