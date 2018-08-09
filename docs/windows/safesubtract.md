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
ms.openlocfilehash: a82281f1078acd5e3ed0662964a0171ccd72c336
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40018368"
---
# <a name="safesubtract"></a>SafeSubtract
Subtrai dois números de uma maneira que proteja contra estouro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<typename T, typename U>  
inline bool SafeSubtract (  
   T t,  
   U u,  
   T& result  
) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *t*  
 O primeiro número na subtração. Isso deve ser do tipo `T`.  
  
 [in] *u*  
 O número para subtrair de *t*. Isso deve ser do tipo `U`.  
  
 [out] *resultado*  
 O parâmetro em que **SafeSubtract** armazena o resultado.  
  
## <a name="return-value"></a>Valor de retorno  
 **True** se nenhum erro ocorrer; **falsos** se ocorrer um erro.  
  
## <a name="remarks"></a>Comentários  
 Esse método é parte da [biblioteca SafeInt](../windows/safeint-library.md) e é projetado para uma operação de subtração único sem criar uma instância das [classe SafeInt](../windows/safeint-class.md).  
  
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
 [SafeAdd](../windows/safeadd.md)