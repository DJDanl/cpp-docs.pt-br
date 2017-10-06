---
title: _com_error::ErrorInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_error::ErrorInfo
dev_langs:
- C++
helpviewer_keywords:
- ErrorInfo method [C++]
ms.assetid: 071b446c-4395-4fb8-bd3d-300a8b25f5cd
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
ms.openlocfilehash: e80dafb5d1472ec28631b13ab05a0dea0b4de4ba
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comerrorerrorinfo"></a>_com_error::ErrorInfo
**Seção específica da Microsoft**  
  
 Recupera o **IErrorInfo** objeto transmitido ao construtor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
IErrorInfo * ErrorInfo( ) const throw( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Bruto **IErrorInfo** item passado para o construtor.  
  
## <a name="remarks"></a>Comentários  
 Recupera o encapsulada **IErrorInfo** item em uma `_com_error` objeto, ou **nulo** se nenhum **IErrorInfo** item é registrado. O chamador deve chamar **versão** no objeto retornado quando terminar de usá-lo.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)
