---
title: 'Método: fillarraywithiid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Implements::FillArrayWithIid
dev_langs:
- C++
helpviewer_keywords:
- FillArrayWithIid method
ms.assetid: b2e62e3f-0ab9-4c70-aad7-856268544f44
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e020bd725d0c0f5c65ab1cfb38b45e2b8fbca62e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33875715"
---
# <a name="implementsfillarraywithiid-method"></a>Método Implements::FillArrayWithIid
Insere a ID de interface especificada pelo parâmetro de modelo atual do zero para o elemento da matriz especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline static void FillArrayWithIid(  
   unsigned long &index,  
   _In_ IID* iids  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `index`  
 Um índice de base zero que indica o elemento de matriz inicial para essa operação. Quando essa operação for concluída, `index` é incrementada em 1.  
  
 `iids`  
 Uma matriz do tipo IID.  
  
## <a name="remarks"></a>Comentários  
 Função auxiliar interno.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura Implements](../windows/implements-structure.md)