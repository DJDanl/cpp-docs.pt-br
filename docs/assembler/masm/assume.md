---
title: ASSUME
ms.date: 08/30/2018
f1_keywords:
- ASSUME
helpviewer_keywords:
- ASSUME directive
ms.assetid: cd162070-aee9-4c65-babc-005c6cc73d7c
ms.openlocfilehash: 97a57cc8a1acccf70572ff963e496aa79fa3ab43
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50500562"
---
# <a name="assume"></a>ASSUME

Habilita a verificação de erros para os valores do registro.

## <a name="syntax"></a>Sintaxe

> SUPONHA *segregister*:*nome* [[, *segregister*:*nome*]]...<br/>
> SUPONHA *dataregister*:*tipo* [[, *dataregister*:*tipo*]]...<br/>
> SUPONHA *registre*: erro [[, *registrar*: erro]]...<br/>
> Suponha que [[*registre*:]] NADA [[, *registrar*: NADA]]...

## <a name="remarks"></a>Comentários

Após um `ASSUME` é colocado em vigor, o assembler procura alterações nos valores dos registros de determinado. **Erro** gera um erro se o registro for usado. **NADA** remove registrar verificação de erros. Você pode combinar tipos diferentes de suposições em uma instrução.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>