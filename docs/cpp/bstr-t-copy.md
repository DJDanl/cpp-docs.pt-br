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
ms.openlocfilehash: 5b7032d9344ec9375059d5584d080854ffe5c775
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405334"
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
 Se for TRUE, **cópia** retorna uma cópia de independente `BSTR`; caso contrário, **cópia** retornará o BSTR real.  
  
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