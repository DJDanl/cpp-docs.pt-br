---
title: "Contêiner Class::swap | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- swap method
ms.assetid: 898c219c-bc8e-4d14-a149-6240426c693f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 62acdf7bf8278dfba3cf85bc9d5ced26a0f3fcea
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="container-classswap"></a>Classe de Contêiner::swap
> [!NOTE]
>  Este tópico faz parte da documentação do Visual C++ como um exemplo não funcional de contêineres usados na Biblioteca Padrão C++. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).  
  
Troca as sequências controladas entre **\*este** e seu argumento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void swap(Container& right);
```  
  
## <a name="remarks"></a>Comentários  
Se for **\*this.get\_allocator ==** _right_**.get_allocator**, ele fará uma troca em tempo constante. Caso contrário, executará uma série de atribuições de elemento e de chamadas do construtor proporcional ao número de elementos nas duas sequências controladas.  
  
## <a name="see-also"></a>Consulte também  
[Classe de contêiner de amostra](../standard-library/sample-container-class.md)
