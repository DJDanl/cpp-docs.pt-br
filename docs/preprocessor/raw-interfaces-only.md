---
title: raw_interfaces_only | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- raw_interfaces_only
dev_langs:
- C++
helpviewer_keywords:
- raw_interfaces_only attribute
ms.assetid: 87056c6d-3f34-4248-af58-f5775a35bfb7
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eff60ded57ae66b43dee4b3b95699ad498fa0358
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="rawinterfacesonly"></a>raw_interfaces_only
**Específicas do C++**  
  
 Suprime a geração de funções de invólucro de tratamento de erros e [propriedade](../cpp/property-cpp.md) declarações que usam essas funções de wrapper.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
raw_interfaces_only  
```  
  
## <a name="remarks"></a>Comentários  
 O atributo `raw_interfaces_only` também faz com que o prefixo padrão usado na nomenclatura das funções que não são da propriedade seja removido. Normalmente, o prefixo é **raw_**. Se esse atributo for especificado, os nomes de função serão diretamente da biblioteca de tipos.  
  
 Esse atributo permite que você exiba somente o conteúdo de nível baixo da biblioteca de tipos.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)