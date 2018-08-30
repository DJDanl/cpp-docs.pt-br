---
title: .FPO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .FPO
dev_langs:
- C++
helpviewer_keywords:
- .FPO directive
ms.assetid: 35f4cd61-32f9-4262-b657-73f04f775d09
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 234ec5bd703a390d1e2ee60e48d99d346d4aad95
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43203107"
---
# <a name="fpo"></a>.FPO
A. Diretiva FPO controla a emissão de registros de depuração para o segmento de F. Debug$ ou seção.  
  
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
 Número de variáveis locais, um valor sem sinal de 32 bits.  
  
 `cdwParams`  
 Tamanho dos parâmetros no DWORDS, um valor sem sinal de 16 bits.  
  
 *cbProlog*  
 Número de bytes no código de prólogo da função, um valor de 8 bits sem sinal.  
  
 `cbRegs`  
 Número de registros salvos.  
  
 `fUseBP`  
 Indica se o registro EBP foi alocado. 0 ou 1.  
  
 *cbFrame*  
 Indica o tipo de quadro.  Ver [FPO_DATA](/windows/desktop/api/winnt/ns-winnt-_fpo_data) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)