---
title: .FPO
ms.date: 08/30/2018
f1_keywords:
- .FPO
helpviewer_keywords:
- .FPO directive
ms.assetid: 35f4cd61-32f9-4262-b657-73f04f775d09
ms.openlocfilehash: 83d6e81ea7dd35038f27f2721f3cc41fe49ef1bc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50570490"
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