---
title: Função ActivateInstance | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Windows::Foundation::ActivateInstance
- client/ABI::Windows::Foundation::ActivateInstance
dev_langs:
- C++
helpviewer_keywords:
- ActivateInstance function
ms.assetid: 8cfd1dd9-5fda-4cc2-acf8-d40e783b3875
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 93b1c8fa12e06984a2bffdd90419c481d8897b94
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39646235"
---
# <a name="activateinstance-function"></a>Função ActivateInstance
Registra e recupera uma instância de um tipo especificado definido em uma ID de classe especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename T>  
inline HRESULT ActivateInstance(  
   _In_ HSTRING activatableClassId,  
   _Out_ Microsoft::WRL::Details::ComPtrRef<T> instance  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Um tipo para ativar.  
  
 *activatableClassId*  
 A ID da classe que define o parâmetro *T*.  
  
 *instância*  
 Quando essa operação for concluída, uma referência a uma instância do *T*.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um erro HRESULT que indica a causa do erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Windows:: Foundation  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Windows::Foundation](../windows/windows-foundation-namespace.md)