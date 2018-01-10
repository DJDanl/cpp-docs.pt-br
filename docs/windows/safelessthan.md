---
title: SafeLessThan | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: SafeLessThan
dev_langs: C++
helpviewer_keywords: SafeLessThan function
ms.assetid: 9d85bc0d-8d94-4d59-9b72-ef3c63a120a0
caps.latest.revision: "6"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4c490f02f6c27d517095ab3f75a31bb03fe14f63
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="safelessthan"></a>SafeLessThan
Determina se um número é menor que outro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T, typename U>  
inline bool SafeLessThan (  
   const T t,  
   const U u  
) throw ();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `t`  
 O primeiro número. Isso deve ser do tipo T.  
  
 [in] `u`  
 O segundo número. Isso deve ser do tipo u  
  
## <a name="return-value"></a>Valor de retorno  
 `true`Se `t` é menor que `u`; caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 Esse método aprimora o operador de comparação padrão porque `SafeLessThan` permite comparar dois tipos diferentes de número.  
  
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
 [SafeLessThanEquals](../windows/safelessthanequals.md)   
 [SafeGreaterThan](../windows/safegreaterthan.md)   
 [SafeGreaterThanEquals](../windows/safegreaterthanequals.md)