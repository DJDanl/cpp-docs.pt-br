---
title: 'Método chaininterfaces:: Fillarraywithiid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces::FillArrayWithIid
dev_langs:
- C++
helpviewer_keywords:
- FillArrayWithIid method
ms.assetid: f1ce699c-dfb6-40a9-9ea0-e6703d3cf971
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6bd9f899457c3a6045d7a5525c9fb560e23f10d3
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39461030"
---
# <a name="chaininterfacesfillarraywithiid-method"></a>Método ChainInterfaces::FillArrayWithIid
Armazena a ID de interface definida pelo *I0* parâmetro de modelo em um local especificado em uma matriz especificada de IDs de interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline static void FillArrayWithIid(  
   _Inout_ unsigned long &index,  
   _In_ IID* iids  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *index*  
 Ponteiro para um valor de índice para o *iids* matriz.  
  
 *IIDs*  
 Uma matriz de IDs de interface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)