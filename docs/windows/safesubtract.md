---
title: SafeSubtract | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeSubtract
dev_langs:
- C++
helpviewer_keywords:
- SafeSubtract function
ms.assetid: c2712ddc-173f-46a1-b09c-e7ebbd9e68b2
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 300959fe64d280ff3e2c19fd579e8f447a2402eb
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889202"
---
# <a name="safesubtract"></a>SafeSubtract
Subtrai dois números de forma que protege contra estouro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T, typename U>  
inline bool SafeSubtract (  
   T t,  
   U u,  
   T& result  
) throw ();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `t`  
 O primeiro número de subtração. Isso deve ser do tipo T.  
  
 [in] `u`  
 O número para subtrair de `t`. Isso deve ser do tipo u  
  
 [out] `result`  
 O parâmetro onde `SafeSubtract` armazena o resultado.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se nenhum erro ocorrer; `false` se ocorrer um erro.  
  
## <a name="remarks"></a>Comentários  
 Esse método é parte de [biblioteca SafeInt](../windows/safeint-library.md) e foi projetado para uma operação de subtração único sem criar uma instância do [classe SafeInt](../windows/safeint-class.md).  
  
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
 [SafeAdd](../windows/safeadd.md)