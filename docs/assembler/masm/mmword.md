---
title: MMWORD | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: MMWORD
dev_langs: C++
helpviewer_keywords: MMWORD directive
ms.assetid: b4c5a104-9078-4fb4-afc3-d1e63abe562a
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 86668a03778eb78298ed226c628a8b2270cc9d75
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="mmword"></a>MMWORD
Usado para operandos de multimídia de 64 bits com instruções MMX e SSE (XMM).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
MMWORD  
```  
  
## <a name="remarks"></a>Comentários  
 `MMWORD`é um tipo.  Antes de MMWORD que está sendo adicionado para MASM, funcionalidade equivalente pode foi obtida com:  
  
```  
mov mm0, qword ptr [ebx]  
```  
  
 Enquanto trabalha ambas as instruções em operandos de 64 bits, `QWORD` é o tipo para números inteiros sem sinal de 64 bits e `MMWORD` é o tipo para um valor de multimídia de 64 bits.  
  
 `MMWORD`serve para representar o mesmo tipo [m64](../../cpp/m64.md).  
  
## <a name="example"></a>Exemplo  
  
```  
movq     mm0, mmword ptr [ebx]  
```