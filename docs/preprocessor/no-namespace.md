---
title: no_namespace | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: no_namespace
dev_langs: C++
helpviewer_keywords: no_namespace attribute
ms.assetid: 5d81b741-a558-451b-b493-1f3b18967337
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: cb41ec2820468180392a42e8f48684624c7d598d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="nonamespace"></a>no_namespace
**Específicas do C++**  
  
 Especifica que o nome do namespace não é gerado pelo compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
no_namespace  
```  
  
## <a name="remarks"></a>Comentários  
 O conteúdo da biblioteca de tipos no arquivo de cabeçalho de `#import` normalmente é definido em um namespace. O nome do namespace é especificado no **biblioteca** instrução do arquivo IDL original. Se o atributo `no_namespace` for especificado, esse namespace não será gerado pelo compilador.  
  
 Se você quiser usar um nome de namespace diferentes, use o [rename_namespace](../preprocessor/rename-namespace.md) atributo em vez disso.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)