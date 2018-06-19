---
title: raw_property_prefixes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- raw_property_prefixes
dev_langs:
- C++
helpviewer_keywords:
- raw_property_prefixes attribute
ms.assetid: 03a0f48c-c460-4175-a762-9f7f8d84b12f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c1f548c9513a086dd4741a9c61c51acebebb25db
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33840123"
---
# <a name="rawpropertyprefixes"></a>raw_property_prefixes
**Específicas do C++**  
  
 Especifica prefixos alternativos para três métodos da propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
raw_property_prefixes("GetPrefix","PutPrefix","PutRefPrefix")  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `GetPrefix`  
 Prefixo a ser usado para o **propget** métodos.  
  
 `PutPrefix`  
 Prefixo a ser usado para o **propput** métodos.  
  
 `PutRefPrefix`  
 Prefixo a ser usado para o **propputref** métodos.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, de baixo nível **propget**, **propput**, e **propputref** métodos são expostos pelas funções de membro chamadas com prefixos de **get _**, **Put _**, e **putref_** respectivamente. Esses prefixos são compatíveis com os nomes usados nos arquivos de cabeçalho gerados pelo MIDL.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)