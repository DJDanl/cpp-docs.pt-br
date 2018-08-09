---
title: SafeNotEquals | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeNotEquals
dev_langs:
- C++
helpviewer_keywords:
- SafeNotEquals function
ms.assetid: 032e45a8-4159-4b55-b7cc-ecd27f4e4788
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 769c09d39d8640826607d954ae6e6f4672e23647
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40014569"
---
# <a name="safenotequals"></a>SafeNotEquals
Determina se dois números não são iguais.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename T, typename U>  
inline bool SafeNotEquals (  
   const T t,  
   const U u  
) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *t*  
 O primeiro número a ser comparado. Isso deve ser do tipo `T`.  
  
 [in] *u*  
 O segundo número a ser comparado. Isso deve ser do tipo `U`.  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se *t* e *u* não forem iguais; caso contrário **false**.  
  
## <a name="remarks"></a>Comentários  
 O método aprimora `!=` porque **SafeNotEquals** permite comparar dois tipos diferentes de números.  
  
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
 [SafeEquals](../windows/safeequals.md)