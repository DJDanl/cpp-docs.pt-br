---
title: _com_error::_com_error | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::_com_error
dev_langs:
- C++
helpviewer_keywords:
- _com_error method [C++]
ms.assetid: 0a69e46c-caab-49ef-b091-eee401253ce6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ec16faa9881fc1c69dca5f8f39b8797cf0fcff0d
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942228"
---
# <a name="comerrorcomerror"></a>_com_error::_com_error
**Seção específica da Microsoft**  
  
 Constrói um objeto `_com_error`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
_com_error(  
   HRESULT hr,  
   IErrorInfo* perrinfo = NULL,  
   bool fAddRef=false) throw( );  

_com_error( const _com_error& that ) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hr*  
 Informações de HRESULT.  
  
 *perrinfo*  
 Objeto `IErrorInfo`.  
  
 `bool fAddRef=false`  
 Faz com que o construtor chame AddRef em não nulo `IErrorInfo` interface. Isso oferece a contagem de referência correta no caso comum onde a propriedade da interface é passada para o objeto `_com_error`, como:  
  
```cpp 
throw _com_error(hr, perrinfo);  
```  
  
 Se você não quiser que seu código para transferir a propriedade para o `_com_error` objeto e o `AddRef` é necessário para deslocar o `Release` no `_com_error` destruidor, construir o objeto da seguinte maneira:  
  
```cpp 
_com_error err(hr, perrinfo, true);  
```  
  
 *Isso*  
 Um objeto `_com_error` existente.  
  
## <a name="remarks"></a>Comentários  
 O primeiro construtor cria um novo objeto dado um HRESULT e opcional `IErrorInfo` objeto. O segundo cria uma cópia de um objeto `_com_error` existente.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)