---
title: "Método: fillarraywithiid | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Implements::FillArrayWithIid
dev_langs: C++
helpviewer_keywords: FillArrayWithIid method
ms.assetid: b2e62e3f-0ab9-4c70-aad7-856268544f44
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a53a7eb9a05e1f4583c49b42fa10efdf1ee815ab
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura Implements](../windows/implements-structure.md)