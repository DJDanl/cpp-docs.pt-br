---
title: Classe conditional | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- type_traits/std::conditional
dev_langs:
- C++
helpviewer_keywords:
- conditional class
- conditional
ms.assetid: ece9f539-fb28-4e26-a79f-3264bc984493
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 2c764bfc42d633a3036f2e567078b9ea39feea8b
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="conditional-class"></a>Classe conditional
Selecione um dos dois tipos, dependendo da condição especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <bool B, class T1, class T2>  
struct conditional;

template <bool _Test, class _T1, class _T2>  
using conditional_t = typename conditional<_Test, _T1, _T2>::type;
```  
  
#### <a name="parameters"></a>Parâmetros  
 `B`  
 O valor que determina o tipo selecionado.  
  
 `T1`  
 O resultado de tipo quando B é true.  
  
 `T2`  
 O resultado de tipo quando B é false.  
  
## <a name="remarks"></a>Comentários  
 O membro de modelo typedef `conditional<B, T1, T2>::type` avalia quanto a `T1` quando `B` avalia quanto a `true` e avalia quanto a `T2` quando `B` avalia quanto a `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<type_traits>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)




