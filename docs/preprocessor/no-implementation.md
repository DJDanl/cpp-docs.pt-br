---
title: no_implementation | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- no_implementation
dev_langs:
- C++
helpviewer_keywords:
- no_implementation attribute
ms.assetid: bdc67785-e131-409c-87bc-f4d2f4abb07b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bf756a411404d2ebb821d5b226818844acfca75b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="noimplementation"></a>no_implementation
**Específicas do C++**  
  
 Suprime geração do cabeçalho .tli, que contém as implementações das funções de membro do wrapper.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
no_implementation  
```  
  
## <a name="remarks"></a>Comentários  
 Se esse atributo for especificado, o cabeçalho .tlh, com as declarações para expor itens do tipo biblioteca, será gerado sem uma instrução `#include` para incluir o arquivo de cabeçalho .tli.  
  
 Este atributo é usado em conjunto com [implementation_only](../preprocessor/implementation-only.md).  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)