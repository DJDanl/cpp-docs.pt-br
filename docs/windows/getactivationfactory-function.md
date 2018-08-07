---
title: Função GetActivationFactory | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2cbb5be3603f79a7df1cb330ca06775357666854
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570305"
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
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Um parâmetro de modelo que especifica o tipo de alocador de ativação.  
  
 *activatableClassId*  
 O nome da classe que o alocador de ativação pode produzir.  
  
 *fábrica*  
 Quando essa operação for concluída, uma referência para o alocador de ativação para o tipo *T*.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um erro HRESULT que indica por que esta operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Windows:: Foundation  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Windows::Foundation](../windows/windows-foundation-namespace.md)