---
title: no_dual_interfaces | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- no_dual_interfaces
dev_langs:
- C++
helpviewer_keywords:
- no_dual_interfaces attribute
ms.assetid: 9acd5d9d-4a49-4cdc-9470-73a2c23cf512
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f1e919e48b79c9fe98a7a33257ebd0f70061d788
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42540357"
---
# <a name="nodualinterfaces"></a>no_dual_interfaces
**Específico do C++**  
  
Altera o modo como o compilador gerenciar funções wrapper para métodos da interface dupla.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
no_dual_interfaces  
```  
  
## <a name="remarks"></a>Comentários  
 
Normalmente, o wrapper chamará o método por meio da tabela de funções virtuais da interface. Com o **no_dual_interfaces**, o wrapper chama `IDispatch::Invoke` para invocar o método.  
  
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)