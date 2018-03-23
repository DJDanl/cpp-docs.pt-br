---
title: Função ActivateInstance | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- client/Windows::Foundation::ActivateInstance
- client/ABI::Windows::Foundation::ActivateInstance
dev_langs:
- C++
helpviewer_keywords:
- ActivateInstance function
ms.assetid: 8cfd1dd9-5fda-4cc2-acf8-d40e783b3875
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d4ccf4195ac81188520ced79581c131c564cfbb9
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="activateinstance-function"></a>Função ActivateInstance
Registra e recupera uma instância de um tipo especificado definido em uma ID de classe especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T>  
inline HRESULT ActivateInstance(  
   _In_ HSTRING activatableClassId,  
   _Out_ Microsoft::WRL::Details::ComPtrRef<T> instance  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Um tipo para ativar.  
  
 `activatableClassId`  
 O nome da ID de classe que define o parâmetro `T`.  
  
 `instance`  
 Quando essa operação for concluída, uma referência a uma instância de `T`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um erro HRESULT que indica a causa do erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Windows:: Foundation  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Windows::Foundation](../windows/windows-foundation-namespace.md)