---
title: _bstr_t::wchar_t *, _bstr_t::char* | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ebe1f3ad7b0fc46e1edba013f4cc986f1771972d
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39409141"
---
# <a name="bstrtwchart-bstrtchar"></a>_bstr_t::wchar_t *, _bstr_t::char*
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