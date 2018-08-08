---
title: SafeModulus | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- SafeModulus
dev_langs:
- C++
helpviewer_keywords:
- SafeModulus function
ms.assetid: ae5c81eb-5dcf-45a5-aa76-465fdfe68654
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6eaac98e7794ba9a2475cf7b56641d3a779f84d5
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604879"
---
# <a name="safemodulus"></a>SafeModulus
Executa a operação de módulo em dois números.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T, typename U>  
inline bool SafeModulus (  
   const T t,  
   const U u,  
   T& result  
) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *t*  
 O divisor. Isso deve ser do tipo `T`.  
  
 [in] *u*  
 O dividendo. Isso deve ser do tipo `U`.  
  
 [out] *resultado*  
 O parâmetro em que **SafeModulus** armazena o resultado.  
  
## <a name="return-value"></a>Valor de retorno  
 **True** se nenhum erro ocorrer; **falsos** se ocorrer um erro.  
  
## <a name="remarks"></a>Comentários  
 Esse método é parte da [biblioteca SafeInt](../windows/safeint-library.md) e é projetado para uma operação de módulo único sem criar uma instância das [classe SafeInt](../windows/safeint-class.md).  
  
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
 [SafeDivide](../windows/safedivide.md)