---
title: .FPO
ms.date: 08/30/2018
f1_keywords:
- .FPO
helpviewer_keywords:
- .FPO directive
ms.assetid: 35f4cd61-32f9-4262-b657-73f04f775d09
ms.openlocfilehash: b793b3efa72a676b800c10b98ea06001ddcf10d5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491429"
---
# <a name="fpo"></a>.FPO

Dos. A diretiva FPO controla a emissão de registros de depuração para o segmento. Debug $ F ou a seção.

## <a name="syntax"></a>Sintaxe

> FPO (*cdwLocals*, *cdwParams*, *cbProlog*, *cbRegs*, *fUseBP*, *cbFrame*)

### <a name="parameters"></a>Parâmetros

*cdwLocals*<br/>
Número de variáveis locais, um valor de bit de 32 não assinado.

*cdwParams*<br/>
Tamanho dos parâmetros em DWORDs, um valor de 16 bits não assinado.

*cbProlog*<br/>
Número de bytes no código de prólogo da função, um valor de 8 bits não assinado.

*cbRegs*<br/>
Número de registros salvos.

*fUseBP*<br/>
Indica se o Registro EBP foi alocado. 0 ou 1.

*cbFrame*<br/>
Indica o tipo de quadro.  Consulte [FPO_DATA](/windows/win32/api/winnt/ns-winnt-fpo_data) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>
