---
title: 'Método chaininterfaces:: Cancastto | Microsoft Docs'
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
ms.openlocfilehash: 5839edd90f61f9f4aa96ea1d921d2179660be554
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39461204"
---
# <a name="chaininterfacescancastto-method"></a>Método ChainInterfaces::CanCastTo
Indica se a ID de interface especificado pode ser convertida em cada um dos especializações definidas pelos parâmetros de modelo não padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline bool CanCastTo(  
   REFIID riid,  
   _Deref_out_ void **ppv  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *riid*  
 Uma ID de interface.  
  
 *ppv*  
 Um ponteiro para a última ID de interface que foi convertido com êxito.  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se todas as operações de conversão for bem-sucedida; caso contrário, **falso**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)