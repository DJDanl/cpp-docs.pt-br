---
title: "Método Interfacetraits: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::InterfaceTraits::FillArrayWithIid
dev_langs: C++
helpviewer_keywords: FillArrayWithIid method
ms.assetid: 73583177-adc9-4fcb-917d-fa7e6d07c990
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c626955e957bd3db4b4d34255a38751f3339dcf9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="interfacetraitsfillarraywithiid-method"></a>Método InterfaceTraits::FillArrayWithIid
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline static void FillArrayWithIid(  
   _Inout_ unsigned long &index,  
   _In_ IID* iids  
);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `index`  
 Ponteiro para um campo que contém um valor de índice baseado em zero.  
  
 `iids`  
 Uma matriz de IDs de interface.  
  
## <a name="remarks"></a>Comentários  
 Atribui a ID de interface de `Base` ao elemento de matriz especificado pelo argumento de índice.  
  
 Ao contrário do nome dessa API, elemento apenas uma matriz é modificado; não é a matriz inteira.  
  
 Para obter mais informações sobre `Base`, consulte a seção de Typedefs públicos em [estrutura InterfaceTraits](../windows/interfacetraits-structure.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)