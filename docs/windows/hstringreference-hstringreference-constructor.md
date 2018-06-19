---
title: 'Construtor hstringreference:: Hstringreference | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::HStringReference
dev_langs:
- C++
ms.assetid: 29f5fe11-3928-4f60-9861-f0894247bfcb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dc88ea32d4384b36559a4a10da0a5975345bf0d7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33876001"
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