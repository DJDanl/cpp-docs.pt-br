---
title: .DOSSEG | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .DOSSEG
dev_langs:
- C++
helpviewer_keywords:
- .DOSSEG directive
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 33ee0b0b049ece65786c4d4857c2e082a067fee4
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43693226"
---
# <a name="dosseg"></a>.DOSSEG

Ordena os segmentos de acordo com a convenção de segmento do MS-DOS: código primeiro, segmentos, em seguida, não em DGROUP e, em seguida, de segmentos no DGROUP.

## <a name="syntax"></a>Sintaxe

> .DOSSEG

## <a name="remarks"></a>Comentários

Os segmentos no DGROUP siga esta ordem: segmentos não está no BSS ou pilha, segmentos BSS e, finalmente, segmentos de pilha. Usado principalmente para garantir o suporte de CodeView em programas autônomos do MASM. Mesmo que [DOSSEG](../../assembler/masm/dosseg.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>