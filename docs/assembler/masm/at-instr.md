---
title: '@InStr | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- '@InStr'
dev_langs:
- C++
helpviewer_keywords:
- '@InStr symbol'
ms.assetid: 980d5b9f-2b88-4306-8955-df6cd2133e68
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d0fb92987de21f653440d6c4cc23d726ad323b69
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="instr"></a>@InStr
Função de macro que localiza a primeira ocorrência do *string2* na *string1*, começando em *posição* em *string1*. Se *posição* não aparecer, a pesquisa começa no início do *string1*. Retorna um inteiro de posição ou 0 se *string2* não foi encontrado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
@InStr( [[position]], string1, string2 )  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de símbolos](../../assembler/masm/symbols-reference.md)