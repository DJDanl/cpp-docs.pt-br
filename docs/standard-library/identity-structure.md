---
title: Estrutura identity | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- utility/std::identity
dev_langs:
- C++
helpviewer_keywords:
- identity class
- identity structure
ms.assetid: 990756fd-7969-4b39-ad7e-0878e8dac8fd
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: dd840dba1de5e389e2fa1d8585d677d3be255f8e
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="identity-structure"></a>Estrutura identity
Um struct que fornece uma definição de tipo como o parâmetro do modelo.  
  
## <a name="syntax"></a>Sintaxe  
```  
struct identity {
   typedef Type type;
   Type operator()(const Type& left) const;
   };  
```  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`left`|O valor a ser identificado.|  
  
## <a name="remarks"></a>Comentários  
 A classe contém a definição de tipo público `type`, que é a mesma do parâmetro de modelo Type. Ela é usada em conjunto com a função de modelo [forward](../standard-library/utility-functions.md#forward) para garantir que o parâmetro da função tem o tipo desejado.  
  
 Para compatibilidade com o código anterior, a classe define também a função identity `operator()` que retorna o argumento `left`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<utility>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\<utility>](../standard-library/utility.md)




