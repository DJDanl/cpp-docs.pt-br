---
title: .FPO | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- .FPO
dev_langs:
- C++
helpviewer_keywords:
- .FPO directive
ms.assetid: 35f4cd61-32f9-4262-b657-73f04f775d09
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 76f3fb3d06e3d09cdd63e48ef2ab8a6ce95c81e6
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fpo"></a>.FPO
A. Diretiva FPO controla a emissão de registros de depuração para o segmento de F $. Debug ou seção.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
FPO (  
cdwLocals  
,   
cdwParams  
,   
cbProlog  
,   
cbRegs  
,   
fUseBP  
,   
cbFrame  
)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `cdwLocals`  
 Número de variáveis locais, um valor de 32 bits sem sinal.  
  
 `cdwParams`  
 Tamanho dos parâmetros no DWORDS, um valor de 16 bits sem sinal.  
  
 *cbProlog*  
 Número de bytes no código de prólogo da função, um valor de 8 bits sem sinal.  
  
 `cbRegs`  
 Número de registros salvados.  
  
 `fUseBP`  
 Indica se o registro EBP foi alocado. 0 ou 1.  
  
 *cbFrame*  
 Indica o tipo de quadro.  Consulte [FPO_DATA](http://msdn.microsoft.com/library/windows/desktop/ms679352) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)