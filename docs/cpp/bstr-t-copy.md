---
title: _bstr_t::Copy | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::copy
dev_langs:
- C++
helpviewer_keywords:
- Copy method [C++]
- BSTR object [C++], copy
ms.assetid: 00ba7311-e82e-4a79-8106-5329fa2f869a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d23f204e7e8a545fbee7ab516495ed711d7984a9
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942283"
---
# <a name="bstrtcopy"></a>_bstr_t::copy
**Seção específica da Microsoft**  
  
 Constrói uma cópia do `BSTR` encapsulado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
BSTR copy( bool fCopy = true ) const;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *fCopy*  
 Se for TRUE, `copy` retorna uma cópia de independente `BSTR`; caso contrário, `copy` retornará o BSTR real.  
  
## <a name="remarks"></a>Comentários  
 Retorna uma cópia recém-alocada do objeto `BSTR` encapsulado.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
STDMETHODIMP CAlertMsg::get_ConnectionStr(BSTR *pVal){ //  m_bsConStr is _bstr_t  
   *pVal = m_bsConStr.copy();  
}  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)