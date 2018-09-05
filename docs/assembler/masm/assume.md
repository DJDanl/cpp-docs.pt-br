---
title: ASSUME | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- ASSUME
dev_langs:
- C++
helpviewer_keywords:
- ASSUME directive
ms.assetid: cd162070-aee9-4c65-babc-005c6cc73d7c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8a0e43548292d2ffecbebdaead6aa12d6dacc352
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43693802"
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