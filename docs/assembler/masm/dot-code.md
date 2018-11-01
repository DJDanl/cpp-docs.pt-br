---
title: .CODE
ms.date: 08/30/2018
f1_keywords:
- .CODE
helpviewer_keywords:
- .CODE directive
ms.assetid: 2b8c882c-c0d2-4fa3-8335-e6b12717a4f4
ms.openlocfilehash: 65d336d2829c97fdf21e6f4b0fcb3063cc7776ee
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50630796"
---
# <a name="code"></a>.CODE

Quando usado com [. MODELO](../../assembler/masm/dot-model.md), indica o início de um segmento de código.

## <a name="syntax"></a>Sintaxe

> . CÓDIGO [[nome]]

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`name`|Parâmetro opcional que especifica o nome do segmento de código. O nome padrão é Text para simples e pequeno, pequeno, compact [modelos](../../assembler/masm/dot-model.md). O nome padrão é *modulename*Text para outros modelos.|

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>
[.DATA](../../assembler/masm/dot-data.md)<br/>