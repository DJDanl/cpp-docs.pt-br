---
title: _variant_t::SetString | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- _variant_t::SetString
dev_langs:
- C++
helpviewer_keywords:
- SetString method [C++]
ms.assetid: 816b08e5-6830-46ca-b3d7-7689308b3be3
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9c433aafbe9799486d141e04ca747cbb4f7c3e22
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="varianttsetstring"></a>_variant_t::SetString
**Seção específica da Microsoft**  
  
 Atribui uma cadeia de caracteres a este objeto `_variant_t`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void SetString(  
   const char* pSrc   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pSrc`  
 Ponteiro para a cadeia de caracteres.  
  
## <a name="remarks"></a>Comentários  
 Converte uma cadeia de caracteres ANSI em uma cadeia de caracteres Unicode `BSTR` e a atribui a este objeto `_variant_t`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)