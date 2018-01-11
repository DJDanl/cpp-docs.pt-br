---
title: "Método Activationfactory: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::ActivationFactory::GetIids
dev_langs: C++
helpviewer_keywords: GetIids method
ms.assetid: 0983d709-d155-4d65-aae4-5b2c8bb0fede
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: da0ab5960b84b16f8eb05679e0afdb9a85a1955d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="activationfactorygetiids-method"></a>Método ActivationFactory::GetIids
Recupera uma matriz de IDs de interface implementada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   GetIids  
)(_Out_ ULONG *iidCount, _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `iidCount`  
 Quando a operação for concluída, o número de IDs interace a `iids` matriz.  
  
 `iids`  
 Quando a operação for concluída, uma matriz de implementado IDs de interface.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que descreve a falha. E_OUTOFMEMORY é uma possível falha de HRESULT.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ActivationFactory](../windows/activationfactory-class.md)