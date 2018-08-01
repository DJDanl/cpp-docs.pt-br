---
title: _bstr_t::GetAddress | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::GetAddress
dev_langs:
- C++
helpviewer_keywords:
- GetAddress method [C++]
ms.assetid: 09bc9180-867e-4ee5-b22a-8339dc663142
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eaa3921d0f1f89df11cf5e3809c9e90e4a03dd3b
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39408460"
---
# <a name="bstrtgetaddress"></a>_bstr_t::GetAddress
**Seção específica da Microsoft**  
  
 Libera qualquer cadeia de caracteres existente e retorna o endereço de uma cadeia de caracteres recém-alocada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
BSTR* GetAddress( );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `BSTR` encapsulado por `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 **GetAddress** afeta todos os `_bstr_t` objetos que compartilham um `BSTR`. Mais de um `_bstr_t` podem compartilhar uma `BSTR` por meio do uso do construtor de cópia e e **operador =**.  
  
## <a name="example"></a>Exemplo  
 Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo usando **GetAddress**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)