---
title: SafeAdd | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: SafeAdd
dev_langs: C++
helpviewer_keywords: SafeAdd function
ms.assetid: 3f82b91d-59fe-4ee1-873b-d056182fa8be
caps.latest.revision: "5"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e8b668f5b164934cff6643d73d9b4b6169a9d4b5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 `true`Se nenhum erro ocorrer; `false` se ocorrer um erro.  
  
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