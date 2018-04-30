---
title: LOCAL (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- Local
dev_langs:
- C++
helpviewer_keywords:
- LOCAL directive
ms.assetid: 76147e2d-23ca-4f1e-8817-81428becd113
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed9926d23f2e1e8636f31a6f586609ae22d38acd
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="local-masm"></a>LOCAL (MASM)
Na primeira diretiva, dentro de uma macro, **LOCAL** define rótulos que são exclusivos para cada instância da macro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      LOCAL localname [[, localname]]...  
LOCAL label [[ [count ] ]] [[:type]] [[, label [[ [count] ]] [[type]]]]...  
```  
  
## <a name="remarks"></a>Comentários  
 Na segunda diretiva, dentro de uma definição de procedimento (**PROC**), **LOCAL** cria variáveis com base em pilha que existem para a duração do procedimento. O *rótulo* pode ser uma variável simple ou uma matriz contendo *contagem* elementos.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)