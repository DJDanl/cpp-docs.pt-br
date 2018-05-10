---
title: high_property_prefixes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- high_property_prefixes
dev_langs:
- C++
helpviewer_keywords:
- high_property_prefixes attribute
ms.assetid: 91c6cc2b-19b6-4aba-8831-d9e5cccb58b5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7269301fed3892fbf4b7cf6427bacb82d9712ef7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="highpropertyprefixes"></a>high_property_prefixes
**Específicas do C++**  
  
 Especifica prefixos alternativos para três métodos da propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
high_property_prefixes("GetPrefix","PutPrefix","PutRefPrefix")  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `GetPrefix`  
 Prefixo a ser usado para o **propget** métodos.  
  
 `PutPrefix`  
 Prefixo a ser usado para o **propput** métodos.  
  
 `PutRefPrefix`  
 Prefixo a ser usado para o **propputref** métodos.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, tratamento de erros de alto nível **propget**, **propput**, e **propputref** métodos são expostos pelas funções de membro nomeadas com prefixos **obter** , `Put`, e **PutRef**, respectivamente.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)