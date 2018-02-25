---
title: raw_native_types | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- raw_native_types
dev_langs:
- C++
helpviewer_keywords:
- raw_native_types attribute
ms.assetid: 9f38daa8-8dc0-46a5-aff9-f1ff9c1e6f48
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4908f1f06ef0479121d3ec5ac8fa56a797ed05ca
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="rawnativetypes"></a>raw_native_types
**Específicas do C++**  
  
 Desabilita o uso de classes de suporte COM nas funções wrapper de alto nível e força o uso de tipos de dados de nível baixo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
raw_native_types  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, os métodos de manipulação de erros de alto nível usam as classes de suporte COM [bstr_t](../cpp/bstr-t-class.md) e [variant_t](../cpp/variant-t-class.md) em vez do `BSTR` e **VARIANT** tipos de dados e ponteiros de interface COM bruto. Essas classes encapsulam os detalhes da alocação e da desalocação do armazenamento de memória para esses tipos de dados e simplificam significativamente as operações de conversão e de conversão de tipos.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)