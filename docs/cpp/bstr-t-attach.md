---
title: _bstr_t::Attach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::Attach
dev_langs:
- C++
helpviewer_keywords:
- Attach method [C++]
ms.assetid: 8cad867e-40fc-435b-841f-0d412c2f58d3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f9f69811b7b25a793d11ef6d53aaf0638c752a11
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39409101"
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
 Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de uso **Attach**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)