---
title: EQU | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- EQU
dev_langs:
- C++
helpviewer_keywords:
- EQU directive
ms.assetid: 96db466a-1eab-45bd-a3c2-5a59bd754eab
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1d7678cac4c480934fe9f6dd9816e636481c2d64
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="equ"></a>EQU
A primeira diretiva atribui um valor numérico de *expressão* para *nome*.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      name EQU expression  
name EQU <text>  
```  
  
## <a name="remarks"></a>Comentários  
 O *nome* não pode ser redefinido mais tarde.  
  
 O segundo atribuirá diretiva especificado *texto* para *nome*. O *nome* pode ser atribuído um diferentes *texto* mais tarde. Consulte [TEXTEQU](../../assembler/masm/textequ.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)