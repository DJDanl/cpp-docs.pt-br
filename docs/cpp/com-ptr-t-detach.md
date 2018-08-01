---
title: _com_ptr_t::Detach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::Detach
dev_langs:
- C++
helpviewer_keywords:
- Detach method [C++]
ms.assetid: 0652053e-af37-44e9-a278-2522212ebfed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cf38e433f7042707b502a4cba2088db9412adb29
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405828"
---
# <a name="comptrtdetach"></a>_com_ptr_t::Detach
**Seção específica da Microsoft**  
  
 Extrai e retorna o ponteiro de interface encapsulado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
Interface* Detach( ) throw( );  
```  
  
## <a name="remarks"></a>Comentários  
 Extrai e retorna o ponteiro de interface encapsulado e, em seguida, limpa o armazenamento de ponteiro encapsulado como NULL. Isso remove o ponteiro de interface do encapsulamento. Cabe a você chamar `Release` no ponteiro de interface retornado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)