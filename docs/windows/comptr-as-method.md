---
title: 'Método comptr:: as | Microsoft Docs'
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
ms.openlocfilehash: debf10e3c3d7ca68bd277a32e55c21b3e8bf3421
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39645419"
---
# <a name="comptras-method"></a>Método ComPtr::As
Retorna um **ComPtr** objeto que representa a interface identificada pelo parâmetro de modelo especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename U>  
HRESULT As(  
   _Out_ ComPtr<U>* p  
) const;  
  
template<typename U>  
HRESULT As(  
   _Out_ Details::ComPtrRef<ComPtr<U>> p  
) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *U*  
 A interface a ser representado pelo parâmetro *p*.  
  
 *p*  
 Um **ComPtr** objeto que representa a interface especificada pelo parâmetro *U*. Parâmetro *p* não deve se referir a atual **ComPtr** objeto.  
  
## <a name="remarks"></a>Comentários  
 O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo é uma especialização de auxiliar interno, que dá suporte a recursos da linguagem C++, como o [automática](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)