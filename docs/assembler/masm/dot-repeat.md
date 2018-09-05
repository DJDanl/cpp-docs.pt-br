---
title: . REPITA | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .REPEAT
dev_langs:
- C++
helpviewer_keywords:
- .REPEAT directive
ms.assetid: cb8ad8c6-587b-42f9-a0ad-b5316a24918c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8856ed0e1d86277a413baac2c56e5c5ca2ea9ff0
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43687946"
---
# <a name="repeat"></a>.REPEAT

Gera um código que repete a execução do bloco de *instruções* até que `condition` se torne verdadeira. [. UNTILCXZ](../../assembler/masm/dot-untilcxz.md), que se torna verdadeiro quando CX for zero, pode ser substituído por [. Até que](../../assembler/masm/dot-until.md). O `condition` é opcional com **. UNTILCXZ**.

## <a name="syntax"></a>Sintaxe

> .REPEAT<br/>
> instruções<br/>
> . Até que a condição

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>