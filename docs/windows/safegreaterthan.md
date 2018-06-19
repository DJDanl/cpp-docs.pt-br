---
title: SafeGreaterThan | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeGreaterThan
dev_langs:
- C++
helpviewer_keywords:
- SafeGreaterThan function
ms.assetid: 32cecac9-ba88-43eb-a7a4-30e390456739
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0944feb32f9dbd8b73d0710b248139c003e41410
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33888777"
---
# <a name="safegreaterthan"></a>SafeGreaterThan
Compara dois números.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T, typename U>  
inline bool SafeGreaterThan (  
   const T t,  
   const U u  
) throw ();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `t`  
 O primeiro número a ser comparado. Isso deve ser do tipo T.  
  
 [in] `u`  
 O segundo número a ser comparado. Isso deve ser do tipo u  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se `t` é maior do que `u`; caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 `SafeGreaterThan` estende o operador de comparação regular, permitindo que você compare dois tipos diferentes de números.  
  
 Esse método é parte de [biblioteca SafeInt](../windows/safeint-library.md) e foi projetado para uma operação de comparação simples sem criar uma instância do [classe SafeInt](../windows/safeint-class.md).  
  
> [!NOTE]
>  Este método só deve ser usado quando uma operação matemática único deve ser protegida. Se houver várias operações, você deve usar o `SafeInt` classe em vez de chamar as funções autônomas individuais.  
  
 Para obter mais informações sobre os tipos de modelo T e U, consulte [funções SafeInt](../windows/safeint-functions.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** safeint.h  
  
 **Namespace:** Microsoft::Utilities  
  
## <a name="see-also"></a>Consulte também  
 [Funções (SafeInt)](../windows/safeint-functions.md)   
 [Biblioteca de SafeInt](../windows/safeint-library.md)   
 [Classe SafeInt](../windows/safeint-class.md)   
 [SafeLessThan](../windows/safelessthan.md)   
 [SafeLessThanEquals](../windows/safelessthanequals.md)   
 [SafeGreaterThanEquals](../windows/safegreaterthanequals.md)