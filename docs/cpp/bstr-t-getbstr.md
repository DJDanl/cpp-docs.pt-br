---
title: _bstr_t::GetBSTR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::GetBSTR
dev_langs:
- C++
helpviewer_keywords:
- GetBSTR method [C++]
ms.assetid: 0c62ff16-4433-4183-a03c-d5a0a9b731ef
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8863f3a6c37693ec28f931c2af4cb0d299788daa
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402657"
---
# <a name="bstrtgetbstr"></a>_bstr_t::GetBSTR
**Seção específica da Microsoft**  
  
 Aponta para o início do `BSTR` encapsulado por `_bstr_t`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
BSTR& GetBSTR( );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O início do `BSTR` encapsulado por `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 **GetBSTR** afeta todos os `_bstr_t` objetos que compartilham um `BSTR`. Mais de um `_bstr_t` podem compartilhar uma `BSTR` por meio do uso do construtor de cópia e e **operador =**.  
  
## <a name="example"></a>Exemplo  
 Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de uso **GetBSTR**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)