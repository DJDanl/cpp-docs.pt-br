---
title: ASSUME
ms.date: 08/30/2018
f1_keywords:
- ASSUME
helpviewer_keywords:
- ASSUME directive
ms.assetid: cd162070-aee9-4c65-babc-005c6cc73d7c
ms.openlocfilehash: 97a57cc8a1acccf70572ff963e496aa79fa3ab43
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166458"
---
# <a name="assume"></a>ASSUME

Habilita a verificação de erros para os valores do registro.

## <a name="syntax"></a>Sintaxe

> SUPONHA *segregister*:*nome* [[, *segregister*:*nome*]]...<br/>
> SUPONHA *dataregister*:*tipo* [[, *dataregister*:*tipo*]]...<br/>
> ASSUME *register*:ERROR [[, *register*:ERROR]]...<br/>
> ASSUME [[*register*:]] NOTHING [[, *register*:NOTHING]]...

## <a name="remarks"></a>Comentários

Após um `ASSUME` é colocado em vigor, o assembler procura alterações nos valores dos registros de determinado. **Erro** gera um erro se o registro for usado. **NADA** remove registrar verificação de erros. Você pode combinar tipos diferentes de suposições em uma instrução.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>