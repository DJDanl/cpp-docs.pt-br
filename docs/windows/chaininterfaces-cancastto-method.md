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
ms.openlocfilehash: ff24ac92e5e84cb85127ef6e33805928fabd6f60
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39647525"
---
# <a name="chaininterfacescancastto-method"></a>Método ChainInterfaces::CanCastTo
Indica se a ID de interface especificado pode ser convertida em cada um dos especializações definidas pelos parâmetros de modelo não padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
__forceinline bool CanCastTo(  
   REFIID riid,  
   _Deref_out_ void **ppv  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
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