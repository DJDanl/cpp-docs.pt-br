---
title: Estrutura duration_values | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- chrono/std::chrono::duration_values
- chrono/std::chrono::duration_values::max
- chrono/std::chrono::duration_values::min
- chrono/std::chrono::duration_values::zero
dev_langs:
- C++
ms.assetid: 7f66d2e3-1faf-47c3-b47e-08f2a87f20e8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 996e0b02ade2f6c88c1f46ee9f84bbb28cfffdd7
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="durationvalues-structure"></a>Estrutura duration_values
Fornece valores específicos para o parâmetro de modelo [duration](../standard-library/duration-class.md) `Rep`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Rep>  
struct duration_values;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[max](#max)|Estático. Especifica o limite superior para um valor de tipo `Rep`.|  
|[min](#min)|Estático. Especifica o limite inferior para um valor de tipo `Rep`.|  
|[zero](#zero)|Estático. Retorna `Rep(0)`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<chrono >  
  
 **Namespace:** std::chrono  
  
##  <a name="max"></a>  duration_values::max  
 Método estático que retorna o limite superior para valores do tipo `Ref`.  
  
```  
static constexpr Rep max();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Na verdade, retorna `numeric_limits<Rep>::max()`.  
  
### <a name="remarks"></a>Comentários  
 Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve ser maior que [duration_values::zero](#zero).  
  
##  <a name="min"></a>  duration_values::min  
 Método estático que retorna o limite inferior para valores do tipo `Ref`.  
  
```  
static constexpr Rep min();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Na verdade, retorna `numeric_limits<Rep>::lowest()`.  
  
### <a name="remarks"></a>Comentários  
 Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve ser menor ou igual a [duration_values::zero](#zero).  
  
##  <a name="zero"></a>  duration_values::zero  
 Retorna `Rep(0)`.  
  
```  
static constexpr Rep zero();
```  
  
### <a name="remarks"></a>Comentários  
 Quando `Rep` é um tipo definido pelo usuário, o valor retornado deve representar o infinito aditivo.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono>](../standard-library/chrono.md)

