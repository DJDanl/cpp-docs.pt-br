---
title: high_property_prefixes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: high_property_prefixes
dev_langs: C++
helpviewer_keywords: high_property_prefixes attribute
ms.assetid: 91c6cc2b-19b6-4aba-8831-d9e5cccb58b5
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d7678ee6da96c26090d529f8f4b4bfd9b6a7c1bb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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