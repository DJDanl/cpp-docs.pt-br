---
title: Função GetActivationFactory | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::GetActivationFactory
- client/ABI::Windows::Foundation::GetActivationFactory
- client/Windows::Foundation::GetActivationFactory
dev_langs:
- C++
helpviewer_keywords:
- GetActivationFactory function
ms.assetid: 5736d285-6beb-42aa-8788-e261c0010afe
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dd269b8c2e1c671944305d385064d60e8bf9b8a1
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="getactivationfactory-function"></a>Função GetActivationFactory
Recupera um alocador de ativação para o tipo especificado pelo parâmetro de modelo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T>  
inline HRESULT GetActivationFactory(  
   _In_ HSTRING activatableClassId,  
   _Out_ Microsoft::WRL::Details::ComPtrRef<T> factory  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Um parâmetro de modelo que especifica o tipo do alocador de ativação.  
  
 `activatableClassId`  
 O nome da classe que pode gerar o alocador de ativação.  
  
 `factory`  
 Quando essa operação for concluída, uma referência para o alocador de ativação para o tipo `T`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um erro HRESULT que indica o motivo pelo qual esta operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Windows:: Foundation  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Windows::Foundation](../windows/windows-foundation-namespace.md)