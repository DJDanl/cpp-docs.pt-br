---
title: "Função end | Microsoft Docs"
ms.custom: 
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- collection/Windows::Foundation::Collections::end
dev_langs:
- C++
helpviewer_keywords:
- end Function
ms.assetid: fb837bff-fc76-4bae-9096-facf0e03041c
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 264ffdad3d55ae9d2df44646240d42ac02d5fcb1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="end-function"></a>Função end
Retorna um iterador que aponta além do fim de uma coleção que é acessada pelo parâmetro de interface especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template <typename T>  
    ::Platform::Collections::VectorIterator<T>   
    end(  
        IVector<T>^ v       );  
  
template <typename T>  
    ::Platform::Collections::VectorViewIterator<T>   
    end(  
        IVectorView<T>^ v  
       );  
template <typename T>   
    ::Platform::Collections::InputIterator<T>   
    end(  
        IIterable<T>^ i  
       );  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Um parâmetro de tipo de modelo.  
  
 `v`  
 Uma coleção de vetor\<T > ou VectorView\<T > objetos que são acessados por um IVector\<T >, ou IVectorView\<T > interface.  
  
 `i`  
 Objetos de uma coleção de tempo de execução do Windows que são acessados por um IIterable\<T > interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um iterador que aponta para além do fim da coleção.  
  
### <a name="remarks"></a>Comentários  
 Os primeiros dois iteradores de retorno de funções do modelo e a terceira função do modelo retornam um iterador de entrada.  
  
 O objeto [Platform::Collections::VectorViewIterator](../cppcx/platform-collections-vectorviewiterator-class.md) que é retornado por `end` é um iterador proxy que armazena elementos do tipo `VectorProxy<T>`. Entretanto, o objeto proxy quase nunca é visível ao código do usuário. Para obter mais informações, consulte [Coleções (C++/CX)](../cppcx/collections-c-cx.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** collection.h  
  
 **Namespace:** Windows::Foundation::Collections  
  
## <a name="see-also"></a>Consulte também  
 [Collections Namespace](../cppcx/windows-foundation-collections-namespace-c-cx.md)