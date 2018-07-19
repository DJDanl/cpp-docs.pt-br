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
ms.openlocfilehash: 3041e8a4ece0ddff813b7ef9cd2ccb258e520a82
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37940476"
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
 `GetBSTR` afeta todos os objetos `_bstr_t` que compartilham um `BSTR`. Mais de um `_bstr_t` podem compartilhar uma `BSTR` por meio do uso do construtor de cópia e e **operador =**.  
  
## <a name="example"></a>Exemplo  
 Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo usando `GetBSTR`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)