---
title: "Função CreateClassFactory | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Details::CreateClassFactory
dev_langs: C++
helpviewer_keywords: CreateClassFactory function
ms.assetid: 772d5d1b-8872-4745-81ca-521a39564713
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0ac522c2997f6c170e76c462626bb98a290a7dc4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="createclassfactory-function"></a>Função CreateClassFactory
Cria uma fábrica que produz instâncias da classe especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename Factory>  
inline HRESULT STDMETHODCALLTYPE CreateClassFactory(  
   _In_ unsigned int *flags,   
   _In_ const CreatorMap* entry,   
   REFIID riid,   
   _Outptr_ IUnknown **ppFactory  
) throw();  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `flags`  
 Uma combinação de um ou mais [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valores de enumeração.  
  
 `entry`  
 Ponteiro para um [CreatorMap](../windows/creatormap-structure.md) que contém informações de inicialização e o registro sobre parâmetro `riid`.  
  
 `riid`  
 Referência a uma ID de interface.  
  
 `ppFactory`  
 Se essa operação for concluída com êxito, um ponteiro para uma fábrica de classes.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.  
  
## <a name="remarks"></a>Comentários  
 Um erro de asserção é emitido se o parâmetro de modelo `Factory` não deriva da interface IClassFactory.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers::Details](../windows/microsoft-wrl-wrappers-details-namespace.md)