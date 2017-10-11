---
title: _bstr_t::wchar_t *, _bstr_t::char * | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _bstr_t::wchar_t*
- _bstr_t::char*
dev_langs:
- C++
helpviewer_keywords:
- operator wchar_t* [C++]
- operator char* [C++]
ms.assetid: acd9f4a7-b427-42c2-aaae-acae21cab317
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 159186e053a43396c4589fafd142c78a75dbebde
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="bstrtwchart-bstrtchar"></a>_bstr_t::wchar_t*, _bstr_t::char*
**Seção específica da Microsoft**  
  
 Retorna os caracteres BSTR como uma matriz de caracteres estreitos ou largos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      operator const wchar_t*( ) const throw( );   
operator wchar_t*( ) const throw( );   
operator const char*( ) const;   
operator char*( ) const;  
```  
  
## <a name="remarks"></a>Comentários  
 Esses operadores podem ser usados para extrair os dados de caractere que são encapsuladas pelo objeto `BSTR`. Atribuir um novo valor para o ponteiro retornado não altera os dados originais de BSTR.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)
