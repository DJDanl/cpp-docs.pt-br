---
title: _com_ptr_t::Detach | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::Detach
dev_langs:
- C++
helpviewer_keywords:
- Detach method [C++]
ms.assetid: 0652053e-af37-44e9-a278-2522212ebfed
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: f61b0fb05f182ef2723fdcc564fd697f490aed20
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comptrtdetach"></a>_com_ptr_t::Detach
**Seção específica da Microsoft**  
  
 Extrai e retorna o ponteiro de interface encapsulado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
Interface* Detach( ) throw( );  
  
```  
  
## <a name="remarks"></a>Comentários  
 Extrai e retorna o ponteiro de interface encapsulados e limpa o armazenamento de ponteiro encapsulada **nulo**. Isso remove o ponteiro de interface do encapsulamento. Cabe a você chamar **versão** no ponteiro de interface retornado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
