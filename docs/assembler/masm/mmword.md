---
title: MMWORD | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- MMWORD
dev_langs:
- C++
helpviewer_keywords:
- MMWORD directive
ms.assetid: b4c5a104-9078-4fb4-afc3-d1e63abe562a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e97b1e58116d633519b1a780928e05862ac1771d
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32054774"
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