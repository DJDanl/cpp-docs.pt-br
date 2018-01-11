---
title: Estrutura treat_as_floating_point | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: chrono/std::chrono::treat_as_floating_point
dev_langs: C++
ms.assetid: d0a2161c-bbb2-4924-8961-7568d5ad5434
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1679f6819da685a2c49587d703659b941bf45db6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="treatasfloatingpoint-structure"></a>Estrutura treat_as_floating_point
Especifica se `Rep` pode ser tratado como um tipo de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Rep>  
struct treat_as_floating_point : is_floating_point<Rep>;  
```  
  
## <a name="remarks"></a>Comentários  
 `Rep` pode ser tratado como um tipo de ponto flutuante somente quando a especialização `treat_as_floating_point<Rep>` é derivada de [true_type](../standard-library/type-traits-typedefs.md#true_type). A classe de modelo pode ser especializada para um tipo definido pelo usuário.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<chrono >  
  
 **Namespace:** std::chrono  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<chrono>](../standard-library/chrono.md)

