---
title: MMWORD | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- MMWORD
dev_langs:
- C++
helpviewer_keywords:
- MMWORD directive
ms.assetid: b4c5a104-9078-4fb4-afc3-d1e63abe562a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0570a55dc11994e12acedb85d3ae8015abefb54c
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="mmword"></a>MMWORD
Usado para operandos de multimídia de 64 bits com instruções MMX e SSE (XMM).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
MMWORD  
```  
  
## <a name="remarks"></a>Comentários  
 `MMWORD` é um tipo.  Antes de MMWORD que está sendo adicionado para MASM, funcionalidade equivalente pode foi obtida com:  
  
```  
mov mm0, qword ptr [ebx]  
```  
  
 Enquanto trabalha ambas as instruções em operandos de 64 bits, `QWORD` é o tipo para números inteiros sem sinal de 64 bits e `MMWORD` é o tipo para um valor de multimídia de 64 bits.  
  
 `MMWORD` serve para representar o mesmo tipo [m64](../../cpp/m64.md).  
  
## <a name="example"></a>Exemplo  
  
```  
movq     mm0, mmword ptr [ebx]  
```