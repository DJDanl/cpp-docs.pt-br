---
title: ALIAS (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- Alias
dev_langs:
- C++
helpviewer_keywords:
- ALIAS directive
ms.assetid: d9725c49-58de-41da-ab01-b06a56cf5cf2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7b14e1c41a448d0cb7014dabc50a42305249938f
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32049161"
---
# <a name="alias-masm"></a>ALIAS (MASM)
O **ALIAS** diretiva cria um nome alternativo para uma função.  Isso permite que você crie vários nomes para uma função ou bibliotecas que permitem que o vinculador (LINK.exe) para mapear uma função antiga para uma nova função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
ALIAS  <  
alias  
> = <  
actual-name  
>  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `actual-name`  
 O nome real da função ou procedimento.  Os colchetes são necessários.  
  
 `alias`  
 O nome de alias ou alternativo.  Os colchetes são necessários.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)