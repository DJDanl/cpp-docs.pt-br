---
title: .FPO
ms.date: 11/05/2019
f1_keywords:
- .FPO
helpviewer_keywords:
- .FPO directive
ms.assetid: 35f4cd61-32f9-4262-b657-73f04f775d09
ms.openlocfilehash: 3938d9194c35d567ea670e0b92a731193ccd2254
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73703796"
---
# <a name="fpo-32-bit-masm"></a>. FPO (MASM-bit de 32 bits)

Dos. A diretiva FPO controla a emissão de registros de depuração para o segmento. Debug $ F ou a seção. (somente MASM de 32 bits.)

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
