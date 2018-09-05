---
title: .FPO | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
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
ms.openlocfilehash: be5e20716ff414eea3eddc8490e2a3f82adeb777
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43687739"
---
# <a name="fpo"></a>.FPO

A. Diretiva FPO controla a emissão de registros de depuração para o segmento de F. Debug$ ou seção.

## <a name="syntax"></a>Sintaxe

> FPO (*cdwLocals*, *cdwParams*, *cbProlog*, *cbRegs*, *fUseBP*,  *cbFrame*)

### <a name="parameters"></a>Parâmetros

*cdwLocals*<br/>
Número de variáveis locais, um valor sem sinal de 32 bits.

*cdwParams*<br/>
Tamanho dos parâmetros no DWORDS, um valor sem sinal de 16 bits.

*cbProlog*<br/>
Número de bytes no código de prólogo da função, um valor de 8 bits sem sinal.

*cbRegs*<br/>
Número de registros salvos.

*fUseBP*<br/>
Indica se o registro EBP foi alocado. 0 ou 1.

*cbFrame*<br/>
Indica o tipo de quadro.  Ver [FPO_DATA](/windows/desktop/api/winnt/ns-winnt-_fpo_data) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>