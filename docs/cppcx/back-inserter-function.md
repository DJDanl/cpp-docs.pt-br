---
title: Função back_inserter | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
f1_keywords:
- collection/Windows::Foundation::Collections::back_inserter
dev_langs:
- C++
helpviewer_keywords:
- back_inserter Function
ms.assetid: 91476338-5548-44b7-bc7e-2150f4fbe31a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6142255c00d9764e4a1a18dab094899b5e9d9e1d
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42589981"
---
# <a name="backinserter-function"></a>Função back_inserter
Retorna um iterador que é usado para inserir elementos no final da coleção especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template <typename T>
Platform::BackInsertIterator<T>   
    back_inserter(IVector<T>^ v);  
  
template<typename T>  
Platform::BackInsertIterator<T>   
   back_inserter(IObservableVector<T>^ v);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Um parâmetro de tipo de modelo.  
  
 `v`  
 Um ponteiro de interface que fornece acesso à coleção subjacente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** collection.h  
  
 **Namespace:** Windows::Foundation::Collections  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Collections](../cppcx/windows-foundation-collections-namespace-c-cx.md)