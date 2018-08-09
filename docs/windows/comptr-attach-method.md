---
title: 'Método comptr:: Attach | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::Attach
dev_langs:
- C++
helpviewer_keywords:
- Attach method
ms.assetid: 5b911f2d-9830-4dc7-b9e3-527abd55d2c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 78b5039268bd122ade815ed6040a1df546e0f293
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39641324"
---
# <a name="comptrattach-method"></a>Método ComPtr::Attach
Associa isso **ComPtr** com o tipo de interface especificado pelo parâmetro de tipo de modelo atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
void Attach(  
   _In_opt_ InterfaceType* other  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *other*  
 Um tipo de interface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)