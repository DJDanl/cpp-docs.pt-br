---
title: _com_error::_com_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_error::_com_error
dev_langs:
- C++
helpviewer_keywords:
- _com_error method [C++]
ms.assetid: 0a69e46c-caab-49ef-b091-eee401253ce6
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
ms.openlocfilehash: 81efabf796d8d596326629af999f1932501befb5
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comerrorcomerror"></a>_com_error::_com_error
**Seção específica da Microsoft**  
  
 Constrói um objeto `_com_error`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      _com_error(  
   HRESULT hr,  
   IErrorInfo* perrinfo = NULL,  
   bool fAddRef=false  
) throw( );  
_com_error(  
   const _com_error& that   
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hr`  
 Informações de `HRESULT`.  
  
 `perrinfo`  
 **IErrorInfo** objeto.  
  
 **bool fAddRef = false**  
 Faz com que o construtor chame AddRef não null **IErrorInfo** interface. Isso oferece a contagem de referência correta no caso comum onde a propriedade da interface é passada para o objeto `_com_error`, como:  
  
```  
throw _com_error(hr, perrinfo);  
```  
  
 Se você não quiser que seu código para transferir a propriedade para o `_com_error` objeto e o `AddRef` é necessário para deslocar o **versão** no `_com_error` destruidor, construir o objeto da seguinte maneira:  
  
```  
_com_error err(hr, perrinfo, true);  
```  
  
 `that`  
 Um objeto `_com_error` existente.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor cria um novo objeto, considerando um `HRESULT` e opcionais **IErrorInfo** objeto. O segundo cria uma cópia de um objeto `_com_error` existente.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)
