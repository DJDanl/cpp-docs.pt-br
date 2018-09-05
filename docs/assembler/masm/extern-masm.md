---
title: EXTERN (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- extern
dev_langs:
- C++
helpviewer_keywords:
- EXTERN directive
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0a9008e8c1153c0a9b06530b14e661436f7e62a9
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43693664"
---
# <a name="extern-masm"></a>EXTERN (MASM)

Define uma ou mais variáveis externas, rótulos ou símbolos chamados *nome* cujo tipo seja *tipo*.

## <a name="syntax"></a>Sintaxe

> EXTERN [[*langtype*]] *nome* [[(*altid*)]]: *tipo* [[, [[*langtype*]]  *nome da* [[(*altid*)]]: *tipo*]]...

## <a name="remarks"></a>Comentários

O *tipo* pode ser [ABS](../../assembler/masm/operator-abs.md), quais importações *nome* como uma constante. Mesmo que [EXTRN](../../assembler/masm/extrn.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>