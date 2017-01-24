---
title: "M&#233;todo ComPtr::As | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "client/Microsoft::WRL::ComPtr::As"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método As"
ms.assetid: 2ad6c262-9bdb-4c59-a330-1af8bcd445cc
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo ComPtr::As
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Retorna um objeto ComPtr que representa a interface identificada pelo parâmetro do modelo especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
template<  
   typename U  
>  
HRESULT As(  
   _Out_ ComPtr<U>* p  
) const;  
  
template<  
   typename U  
>  
HRESULT As(  
   _Out_ Details::ComPtrRef<ComPtr<U>> p  
) const;  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `U`  
 A interface a ser representada pelo parâmetro `p`.  
  
 `p`  
 Um objeto ComPtr que representa a interface especificada pelo parâmetro `U`. Parâmetro `p` não deve fazer referência ao objeto ComPtr atual.  
  
## <a name="remarks"></a>Comentários  
 O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo é uma especialização de auxiliar interno, que oferece suporte a recursos da linguagem C++, como o [automático](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, um HRESULT que indica o erro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)