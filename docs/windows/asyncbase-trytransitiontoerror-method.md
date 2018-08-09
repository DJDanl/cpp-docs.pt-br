---
title: 'Método asyncbase:: Trytransitiontoerror | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::TryTransitionToError
dev_langs:
- C++
helpviewer_keywords:
- TryTransitionToError method
ms.assetid: f6d11c25-1ce3-43f9-af1c-97c4dc0f6f0f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 61b56472e490d95e22c1013595c5c088d2b58dcd
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39643024"
---
# <a name="asyncbasetrytransitiontoerror-method"></a>Método AsyncBase::TryTransitionToError
Indica se o código de erro especificado pode modificar o estado de erro interno.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
bool TryTransitionToError(  
   const HRESULT error  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *error*  
 Um erro HRESULT.  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o estado de erro interno foi alterado; caso contrário, **falso**.  
  
## <a name="remarks"></a>Comentários  
 Esta operação modifica o estado de erro somente se o estado de erro já está definido como S_OK. Esta operação não tem efeito se o estado de erro já é um erro, cancelado, concluído ou fechada.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)