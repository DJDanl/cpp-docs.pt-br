---
title: 'Método Chaininterfaces: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces::CanCastTo
dev_langs:
- C++
helpviewer_keywords:
- CanCastTo method
ms.assetid: 8be44875-53ed-494b-91a0-0f8e399685bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c2286c347fbd68f34fac807e80facca0a0286aa6
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33860288"
---
# <a name="chaininterfacescancastto-method"></a>Método ChainInterfaces::CanCastTo
Indica se a ID de interface especificado pode ser convertida em cada uma das especializações definidas pelos parâmetros de modelo não padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline bool CanCastTo(  
   REFIID riid,  
   _Deref_out_ void **ppv  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 Uma ID de interface.  
  
 `ppv`  
 Um ponteiro para a última ID de interface que foi convertido com êxito.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se todas as operações de conversão for bem-sucedida; Caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)