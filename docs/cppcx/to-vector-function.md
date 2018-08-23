---
title: Função to_vector | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
f1_keywords:
- collection/Windows::Foundation::Collections::to_vector
dev_langs:
- C++
helpviewer_keywords:
- to_vector Function
ms.assetid: 9cdd5123-7243-4def-a1d3-162e0bf6219e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 00ecb00a890629c69994019c9232ff559ea93c96
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42609732"
---
# <a name="tovector-function"></a>Função to_vector
Retorna um `std::vector` cujo valor é igual ao da coleção subjacente ao parâmetro IVector ou IVectorView especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <typename T>  
inline ::std::vector<T> to_vector(IVector<T>^ v); 
 
template <typename T>  
inline ::std::vector<T> to_vector(IVectorView<T>^ v);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O parâmetro de tipo de modelo.  
  
 `v`  
 Uma interface de IVector ou IVectorView que fornece acesso a um objeto Vector ou VectorView subjacente.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** collection.h  
  
 **Namespace:** Windows::Foundation::Collections  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Collections](../cppcx/windows-foundation-collections-namespace-c-cx.md)