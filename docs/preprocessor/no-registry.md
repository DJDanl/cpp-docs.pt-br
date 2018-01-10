---
title: no_registry | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: no_registry
dev_langs: C++
helpviewer_keywords: no_registry attribute
ms.assetid: d30de4e2-551c-428c-98fd-951330d578d3
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9d2b4b34a4ebf266f4ae8062bb2fff0f80060a22
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="noregistry"></a>no_registry
`no_registry` informa o compilador não para procurar no registro por bibliotecas de tipo importadas com `#import`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#import filename no_registry  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *filename*  
 Uma biblioteca de tipos.  
  
## <a name="remarks"></a>Comentários  
 Se uma biblioteca de tipos referenciada não for encontrada nos diretórios de inclusão, a compilação falhará mesmo se a biblioteca de tipos no registro.  `no_registry`propaga a outras bibliotecas de tipo implicitamente importadas com `auto_search`.  
  
 O compilador nunca pesquisará o registro por bibliotecas do tipo que são especificadas pelo nome do arquivo e passadas diretamente a `#import`.  
  
 Quando `auto_search` for especificado, o `#import`s adicionais serão gerados com a configuração `no_registry` de `#import` inicial (se a política `#import` inicial foi `no_registry`, um `auto_search` gerado por `#import` também é `no_registry`.)  
  
 `no_registry`é útil se você deseja importar bibliotecas de tipo de referência cruzada sem o risco de compilador encontrar uma versão mais antiga do arquivo no registro.  `no_registry`também é útil se a biblioteca de tipos não está registrada.  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)