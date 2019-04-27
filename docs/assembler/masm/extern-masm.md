---
title: EXTERN (MASM)
ms.date: 08/30/2018
f1_keywords:
- extern
helpviewer_keywords:
- EXTERN directive
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
ms.openlocfilehash: 30d1b3ae7c6676aeb97b91c7627da859525b9ce1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62203609"
---
# <a name="extern-masm"></a>EXTERN (MASM)

Define uma ou mais variáveis externas, rótulos ou símbolos chamados *nome* cujo tipo seja *tipo*.

## <a name="syntax"></a>Sintaxe

> EXTERN [[*langtype*]] *nome* [[(*altid*)]]: *tipo* [[, [[*langtype*]]  *nome da* [[(*altid*)]]: *tipo*]]...

## <a name="remarks"></a>Comentários

O *tipo* pode ser [ABS](../../assembler/masm/operator-abs.md), quais importações *nome* como uma constante. Mesmo que [EXTRN](../../assembler/masm/extrn.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>