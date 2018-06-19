---
title: 'Método Comptr: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::As
dev_langs:
- C++
helpviewer_keywords:
- As method
ms.assetid: 2ad6c262-9bdb-4c59-a330-1af8bcd445cc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fb9fd0ff09f6775a95ff881d9f8cbaa3edc61065
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33857266"
---
# <a name="comptras-method"></a>Método ComPtr::As
Retorna um objeto ComPtr que representa a interface identificada pelo parâmetro de modelo especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template<typename U>  
HRESULT As(  
   _Out_ ComPtr<U>* p  
) const;  
  
template<typename U>  
HRESULT As(  
   _Out_ Details::ComPtrRef<ComPtr<U>> p  
) const;  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `U`  
 A interface para ser representado pelo parâmetro `p`.  
  
 `p`  
 Um objeto ComPtr que representa a interface especificada pelo parâmetro `U`. Parâmetro `p` não devem se referir ao objeto ComPtr atual.  
  
## <a name="remarks"></a>Comentários  
 O primeiro modelo é o formulário que você deve usar em seu código. O segundo é uma especialização de auxiliar interno, que dá suporte a recursos de linguagem do C++, como o [automática](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)