---
title: SafeAdd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeAdd
dev_langs:
- C++
helpviewer_keywords:
- SafeAdd function
ms.assetid: 3f82b91d-59fe-4ee1-873b-d056182fa8be
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b0450820afdde3eb330948a65f8d052fa54017dc
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892710"
---
# <a name="safeadd"></a>SafeAdd
Adiciona dois números de forma que protege contra estouro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T, typename U>  
inline bool SafeAdd (  
   T t,  
   U u,  
   T& result  
) throw ();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `t`  
 O primeiro número para adicionar. Isso deve ser do tipo T.  
  
 [in] `u`  
 O segundo número para adicionar. Isso deve ser do tipo u  
  
 [out] `result`  
 O parâmetro onde `SafeAdd` armazena o resultado.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se nenhum erro ocorrer; `false` se ocorrer um erro.  
  
## <a name="remarks"></a>Comentários  
 Esse método é parte de [biblioteca SafeInt](../windows/safeint-library.md) e foi projetado para uma operação de adição único sem criar uma instância do [classe SafeInt](../windows/safeint-class.md).  
  
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
 [SafeSubtract](../windows/safesubtract.md)