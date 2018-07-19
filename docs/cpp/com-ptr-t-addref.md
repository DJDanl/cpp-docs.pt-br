---
title: _com_ptr_t::AddRef | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::AddRef
dev_langs:
- C++
helpviewer_keywords:
- AddRef method [C++], interface pointers
ms.assetid: c104dac3-aad3-40bb-a298-75c6cd0e63a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 40ed48b54a3862f7ac5804e7652d98b661bb071d
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37940986"
---
# <a name="comptrtaddref"></a>_com_ptr_t::AddRef
**Seção específica da Microsoft**  
  
 Chamadas a `AddRef` função de membro de `IUnknown` no ponteiro de interface encapsulado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
void AddRef( );  
  
```  
  
## <a name="remarks"></a>Comentários  
 Chamadas `IUnknown::AddRef` no ponteiro de interface encapsulado, gerando um erro E_POINTER se o ponteiro é NULL.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)