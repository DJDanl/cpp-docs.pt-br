---
title: Função RaiseException | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::RaiseException
dev_langs:
- C++
helpviewer_keywords:
- RaiseException function
ms.assetid: f9c74f6d-112a-4d2e-900f-622f795d5dbf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5426d639ffb8655466239232da7672b89564bfae
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40020103"
---
# <a name="raiseexception-function"></a>Função RaiseException
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline void __declspec(noreturn)   RaiseException(  
      HRESULT hr,   
      DWORD dwExceptionFlags = EXCEPTION_NONCONTINUABLE);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *hr*  
 O código de exceção da exceção que está sendo gerado; ou seja, o HRESULT de uma operação com falha.  
  
 *dwExceptionFlags*  
 Um sinalizador que indica uma exceção noncontinuable (o valor do sinalizador é diferente de zero) ou a exceção de continuidade (o valor do sinalizador é zero). Por padrão, a exceção é não continuável.  
  
## <a name="remarks"></a>Comentários  
 Gera uma exceção no thread de chamada.  
  
 Para obter mais informações, consulte o Windows `RaiseException` função.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)