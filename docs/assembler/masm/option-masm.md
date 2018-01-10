---
title: "OPÇÃO (MASM) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: option
dev_langs: C++
helpviewer_keywords: OPTION directive
ms.assetid: 8e10dabd-e36f-4586-ab01-ada96736b0bd
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f449606b143bfbf188e878b261f3d35017846862
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="option-masm"></a>OPTION (MASM)
Habilita e desabilita recursos do assembler.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
OPTION   
optionlist  
  
```  
  
## <a name="remarks"></a>Comentários  
 As opções disponíveis incluem:  
  
|||||  
|-|-|-|-|  
|**CASEMAP**|**DOTNAME**|**NODOTNAME**|**EMULADOR**|  
|**NOEMULATOR**|**EPÍLOGO**|**EXPR16**|**EXPR32**|  
|**IDIOMA**|**LJMP**|**NOLJMP**|**M510**|  
|**NOM510**|**NOKEYWORD**|**NOSIGNEXTEND**|**DESLOCAMENTO**|  
|**OLDMACROS**|**NOOLDMACROS**|**OLDSTRUCTS**|**NOOLDSTRUCTS**|  
|**PROC**|**PRÓLOGO**|**SOMENTE LEITURA**|**NOREADONLY**|  
|**NO ESCOPO**|**NOSCOPED**|**SEGMENT**|**SETIF2**.|  
  
 A sintaxe de LINGUAGEM é **opção de LINGUAGEM:***x*, onde *x* é C, SYSCALL, STDCALL, PASCAL, FORTRAN ou BASIC.  SYSCALL, PASCAL, FORTRAN e BASIC não têm suporte com usado com [. MODELO](../../assembler/masm/dot-model.md) simples.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)