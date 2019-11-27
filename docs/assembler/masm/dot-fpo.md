---
title: .FPO
ms.date: 11/05/2019
f1_keywords:
- .FPO
helpviewer_keywords:
- .FPO directive
ms.assetid: 35f4cd61-32f9-4262-b657-73f04f775d09
ms.openlocfilehash: 650c69be17c9271c343360edbb90f093841a1047
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74398250"
---
# <a name="fpo-32-bit-masm"></a>. FPO (MASM-bit de 32 bits)

O **.** A diretiva FPO controla a emissão de registros de depuração para o segmento. Debug $ F ou a seção. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **. FPO** (*cdwLocals*, *cdwParams*, *cbProlog*, *cbRegs*, *fUseBP*, *cbFrame*)

### <a name="parameters"></a>Parâmetros

\ *cdwLocals*
Número de variáveis locais, um valor de bit de 32 não assinado.

\ *cdwParams*
Tamanho dos parâmetros em DWORDs, um valor de 16 bits não assinado.

\ *cbProlog*
Número de bytes no código de prólogo da função, um valor de 8 bits não assinado.

\ *cbRegs*
Número de registros salvos.

\ *fUseBP*
Indica se o Registro EBP foi alocado. 0 ou 1.

\ *cbFrame*
Indica o tipo de quadro.  Consulte [FPO_DATA](/windows/win32/api/winnt/ns-winnt-fpo_data) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
