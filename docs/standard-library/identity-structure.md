---
title: Estrutura identity | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: utility/std::identity
dev_langs: C++
helpviewer_keywords:
- identity class
- identity structure
ms.assetid: 990756fd-7969-4b39-ad7e-0878e8dac8fd
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 280ce6a24e1de9d0e7206e7f9e5b0d896d8c6787
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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



