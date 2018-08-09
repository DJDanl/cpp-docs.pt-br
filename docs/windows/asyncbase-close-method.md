---
title: 'Método asyncbase:: Close | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::Close
dev_langs:
- C++
helpviewer_keywords:
- Close method
ms.assetid: a52b1124-754b-4393-b491-64aae0c22f1c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3ce391e95aa9e08ae7d99e3cbdf064721ce21dbe
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39643531"
---
# <a name="asyncbaseclose-method"></a>Método AsyncBase::Close
Fecha a operação assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
STDMETHOD(  
   Close  
)(void) override;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se a operação fecha ou já está fechado; Caso contrário, E_ILLEGAL_STATE_CHANGE.  
  
## <a name="remarks"></a>Comentários  
 **Close ()** é uma implementação padrão de `IAsyncInfo::Close`, e não faz nenhum trabalho real. Para realmente fechar uma operação assíncrona, substituir o `OnClose()` método virtual puro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)