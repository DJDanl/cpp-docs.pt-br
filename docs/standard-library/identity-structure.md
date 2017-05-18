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
- identity
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: a7404d2c1a785fd66489421fd7b9689260e0986d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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




