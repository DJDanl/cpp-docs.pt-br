---
title: 'Método: Trytransitiontoerror | Microsoft Docs'
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
ms.openlocfilehash: 97fcade98e82a289c172c7651f62f3de0394fe16
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33863498"
---
# <a name="asyncbasetrytransitiontoerror-method"></a>Método AsyncBase::TryTransitionToError
Indica se o código de erro especificado pode modificar o estado de erro interno.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
bool TryTransitionToError(  
   const HRESULT error  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `error`  
 Um erro HRESULT.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se o estado de erro interno foi alterado; Caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 Esta operação modifica o estado de erro somente se o estado de erro já está definido como S_OK. Esta operação não tem efeito se o estado de erro já é um erro, cancelado, concluído ou fechado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)