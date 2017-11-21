---
title: "Função RaiseException | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: internal/Microsoft::WRL::Details::RaiseException
dev_langs: C++
helpviewer_keywords: RaiseException function
ms.assetid: f9c74f6d-112a-4d2e-900f-622f795d5dbf
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0f64d0e38bb92f9ebe3954b47ece29184cbf1a73
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="raiseexception-function"></a>Função RaiseException
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline void __declspec(noreturn)   RaiseException(  
      HRESULT hr,   
      DWORD dwExceptionFlags = EXCEPTION_NONCONTINUABLE);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hr`  
 O código de exceção da exceção que está sendo gerado; ou seja, o HRESULT de uma operação com falha.  
  
 `dwExceptionFlags`  
 Um sinalizador que indica uma exceção noncontinuable (valor de sinalizador é diferente de zero) ou a exceção de continuidade (o valor do sinalizador será zero). Por padrão, a exceção é não continuável.  
  
## <a name="remarks"></a>Comentários  
 Gera uma exceção no thread de chamada.  
  
 Para obter mais informações, consulte o Windows **RaiseException** função.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)