---
title: _variant_t::SetString | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _variant_t::SetString
dev_langs:
- C++
helpviewer_keywords:
- SetString method [C++]
ms.assetid: 816b08e5-6830-46ca-b3d7-7689308b3be3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 68ef72cfd256a2676c73223723f37374c50cb56f
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942246"
---
# <a name="varianttsetstring"></a>_variant_t::SetString
**Seção específica da Microsoft**  
  
 Atribui uma cadeia de caracteres a este objeto `_variant_t`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
void SetString(const char* pSrc);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pSrc*  
 Ponteiro para a cadeia de caracteres.  
  
## <a name="remarks"></a>Comentários  
 Converte uma cadeia de caracteres ANSI em uma cadeia de caracteres Unicode `BSTR` e a atribui a este objeto `_variant_t`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)