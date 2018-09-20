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
ms.openlocfilehash: 6f188cd833551542e636e764e76784635ae2ccf2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46422760"
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
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)