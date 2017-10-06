---
title: _bstr_t::Attach | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _bstr_t::Attach
dev_langs:
- C++
helpviewer_keywords:
- Attach method [C++]
ms.assetid: 8cad867e-40fc-435b-841f-0d412c2f58d3
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 0541fadf224fd3f13377111d1bb1b7f5aca2f995
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="bstrtattach"></a>_bstr_t::Attach
**Seção específica da Microsoft**  
  
 Vincula um wrapper `_bstr_t` a um `BSTR`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void Attach(  
   BSTR s  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *s*  
 Um `BSTR` a ser associado ou atribuído à variável `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 Se o `_bstr_t` estava associado anteriormente a outro `BSTR`, o `_bstr_t` limpará o recurso `BSTR`, se nenhuma outra variável `_bstr_t` estiver usando o `BSTR`.  
  
## <a name="example"></a>Exemplo  
 Consulte [_bstr_t::Assign](../cpp/bstr-t-assign.md) para um exemplo usando **Attach**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)
