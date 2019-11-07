---
title: ASSUME
ms.date: 11/05/2019
f1_keywords:
- ASSUME
helpviewer_keywords:
- ASSUME directive
ms.assetid: cd162070-aee9-4c65-babc-005c6cc73d7c
ms.openlocfilehash: 4bf8f0c41e9ce3e296cf201efd4fd9be2033cbdb
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73702472"
---
# <a name="assume-32-bit-masm"></a>SUPOR (MASM de 32 bits)

Habilita a verificação de erros para os valores de registro. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> SUPOR *segregister*:*Name* [[, *segregister*:*Name*]]...<br/>
> ASSUMIR *o registro de dataregister*:*tipo* [[, *dataregister*:*tipo*]]...<br/>
> ASSUMIR *o registro*: erro [[, *registrar*: erro]]...<br/>
> SUPONHA que [[*Register*:]] nada [[, *Register*: Nothing]]...

## <a name="remarks"></a>Comentários

Depois que um `ASSUME` é colocado em vigor, o Assembler observa as alterações nos valores dos registros fornecidos. **Erro** gerará um erro se o registro for usado. **Nada** remove a verificação de erros de registro. Você pode combinar diferentes tipos de pressuposições em uma instrução.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>