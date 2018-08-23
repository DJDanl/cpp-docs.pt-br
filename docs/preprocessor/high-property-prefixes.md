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
ms.openlocfilehash: 2ce21958dbb928a29debe21fb7cfaed4b9036141
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42539929"
---
# <a name="highpropertyprefixes"></a>high_property_prefixes
**Específico do C++**  
  
Especifica prefixos alternativos para três métodos da propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
high_property_prefixes("GetPrefix","PutPrefix","PutRefPrefix")  
```  
  
### <a name="parameters"></a>Parâmetros  
*GetPrefix*  
Prefixo a ser usado para o `propget` métodos.  
  
*PutPrefix*  
Prefixo a ser usado para o `propput` métodos.  
  
*PutRefPrefix*  
Prefixo a ser usado para o `propputref` métodos.  
  
## <a name="remarks"></a>Comentários  
 
Por padrão, tratamento de erros de alto nível `propget`, `propput`, e `propputref` métodos expostos pela funções membro nomeadas com prefixos `Get`, `Put`, e `PutRef`, respectivamente.  
  
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)