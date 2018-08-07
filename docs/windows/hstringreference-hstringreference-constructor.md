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
ms.openlocfilehash: 7dce8c6fca14ad26665bf4868681234374c20f85
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39608138"
---
# <a name="hstringreferencehstringreference-constructor"></a>Construtor HStringReference::HStringReference
Inicializa uma nova instância dos **HStringReference** classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<unsigned int sizeDest>  
HStringReference(wchar_t const (&str)[ sizeDest]) throw();  
  
template<unsigned int sizeDest>  
HStringReference(wchar_t const (&str)[ sizeDest],   
                 unsigned int len) throw();  
  
HStringReference(HStringReference&& other) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *sizeDest*  
 Um parâmetro de modelo que especifica o tamanho do destino **HStringReference** buffer.  
  
 *str*  
 Uma referência a uma cadeia de caracteres largos.  
  
 *Len*  
 O comprimento máximo do *str* buffer de parâmetro a ser usado nesta operação. Se o *len* parâmetro não for especificado, todo o *str* parâmetro é usado. Se *len* é maior que *sizeDest*, *len* é definido como *sizeDest*-1.  
  
 *other*  
 Outra **HStringReference** objeto.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa uma nova **HStringReference** objeto do mesmo tamanho como parâmetro *str*.  
  
 O segundo construtor inicializa uma nova **HStringReference** do objeto que o specifeid tamanho pelo parâmetro *len*.  
  
 O terceiro construtor inicializa uma nova **HStringReference** objeto para o valor da *outras* parâmetro e, em seguida, destrói o *outros* parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)