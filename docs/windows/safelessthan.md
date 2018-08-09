---
title: SafeLessThan | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeLessThan
dev_langs:
- C++
helpviewer_keywords:
- SafeLessThan function
ms.assetid: 9d85bc0d-8d94-4d59-9b72-ef3c63a120a0
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 923c1f46d8d4212eb61cd9834af1c47d521bf369
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40020034"
---
# <a name="safelessthan"></a>SafeLessThan
Determina se um número é menor que outro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename T, typename U>  
inline bool SafeLessThan (  
   const T t,  
   const U u  
) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *t*  
 O primeiro número. Isso deve ser do tipo `T`.  
  
 [in] *u*  
 O segundo número. Isso deve ser do tipo `U`.  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se *t* é menor que *u*; caso contrário **false**.  
  
## <a name="remarks"></a>Comentários  
 Esse método melhora o operador de comparação padrão, pois **SafeLessThan** permite comparar dois tipos diferentes de número.  
  
 Esse método é parte da [biblioteca SafeInt](../windows/safeint-library.md) e é projetado para uma operação de comparação única sem criar uma instância das [classe SafeInt](../windows/safeint-class.md).  
  
> [!NOTE]
>  Esse método só deve ser usado quando uma operação matemática única deve ser protegida. Se houver várias operações, você deve usar o `SafeInt` classe em vez de chamar as funções individuais de autônomas.  
  
 Para obter mais informações sobre os tipos de modelo `T` e `U`, consulte [funções SafeInt](../windows/safeint-functions.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** safeint  
  
 **Namespace:** Microsoft::Utilities  
  
## <a name="see-also"></a>Consulte também  
 [Funções SafeInt](../windows/safeint-functions.md)   
 [Biblioteca SafeInt](../windows/safeint-library.md)   
 [Classe SafeInt](../windows/safeint-class.md)   
 [SafeLessThanEquals](../windows/safelessthanequals.md)   
 [SafeGreaterThan](../windows/safegreaterthan.md)   
 [SafeGreaterThanEquals](../windows/safegreaterthanequals.md)