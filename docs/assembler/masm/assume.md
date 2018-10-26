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
ms.openlocfilehash: 6fbba50e56ae06dc3afb64582d4a131bba75a6c8
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055847"
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