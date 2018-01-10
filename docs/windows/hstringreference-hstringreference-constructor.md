---
title: 'Construtor hstringreference:: Hstringreference | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HStringReference::HStringReference
dev_langs: C++
ms.assetid: 29f5fe11-3928-4f60-9861-f0894247bfcb
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 398ea9403f784c30f8e015101c25b071f1d6fb29
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstringreferencehstringreference-constructor"></a>Construtor HStringReference::HStringReference
Inicializa uma nova instância da classe HStringReference.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<unsigned int sizeDest>  
HStringReference(wchar_t const (&str)[ sizeDest]) throw();  
  
template<unsigned int sizeDest>  
HStringReference(wchar_t const (&str)[ sizeDest],   
                 unsigned int len) throw();  
  
HStringReference(HStringReference&& other) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `sizeDest`  
 Um parâmetro de modelo que especifica o tamanho do buffer de HStringReference de destino.  
  
 `str`  
 Uma referência a uma cadeia de caracteres largos.  
  
 `len`  
 O comprimento máximo do `str` buffer de parâmetro a ser usado nesta operação. Se o `len` parâmetro não for especificado, todo o `str` parâmetro é usado. Se `len` é maior do que `sizeDest`, `len` é definido como `sizeDest`-1.  
  
 `other`  
 Outro objeto HStringReference.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa um novo objeto de HStringReference o mesmo tamanho do parâmetro `str`.  
  
 A segundo inicializa construtor HStringReference um novo objeto que o specifeid tamanho pelo parâmetro `len`.  
  
 O terceiro construtor inicializa um novo objeto de HStringReference para o valor da `other` parâmetro e, em seguida, destrói o `other` parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)