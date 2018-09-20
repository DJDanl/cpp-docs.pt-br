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
ms.openlocfilehash: c882a8d4eb2510969401b4280eb66116ad220c77
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46440830"
---
# <a name="noimplementation"></a>no_implementation
**Específico do C++**  
  
Suprime geração do cabeçalho .tli, que contém as implementações das funções de membro do wrapper.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
no_implementation  
```  
  
## <a name="remarks"></a>Comentários  
 
Se esse atributo for especificado, o cabeçalho .tlh, com as declarações para expor itens do tipo biblioteca, será gerado sem uma instrução `#include` para incluir o arquivo de cabeçalho .tli.  
  
Esse atributo é usado em conjunto com [implementation_only](../preprocessor/implementation-only.md).  
  
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)