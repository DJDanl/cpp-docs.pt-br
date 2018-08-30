---
title: OPÇÃO (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- option
dev_langs:
- C++
helpviewer_keywords:
- OPTION directive
ms.assetid: 8e10dabd-e36f-4586-ab01-ada96736b0bd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4a2dcbc55d6a2d033cde3b6189618afd67bdc3fb
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221503"
---
# <a name="option-masm"></a>OPTION (MASM)
Habilita e desabilita recursos do montador.  
  
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
|**NOM510**|**NOKEYWORD**|**NOSIGNEXTEND**|**OFFSET**|  
|**OLDMACROS**|**NOOLDMACROS**|**OLDSTRUCTS**|**NOOLDSTRUCTS**|  
|**PROC**|**PRÓLOGO**|**READONLY**|**NOREADONLY**|  
|**SCOPED**|**NOSCOPED**|**SEGMENT**|**SETIF2**.|  
  
 A sintaxe de LINGUAGEM é **opção de LINGUAGEM:**<em>x</em>, onde *x* é um dos C, SYSCALL, STDCALL, PASCAL, FORTRAN ou BASIC.  SYSCALL, PASCAL, FORTRAN e BASIC não têm suporte com usado com [. MODELO](../../assembler/masm/dot-model.md) simples.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)