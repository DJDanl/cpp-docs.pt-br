---
title: .CODE | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .CODE
dev_langs:
- C++
helpviewer_keywords:
- .CODE directive
ms.assetid: 2b8c882c-c0d2-4fa3-8335-e6b12717a4f4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ff2d66cfc79e84c8c4c7cf92e117c9ac8c84a555
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43682481"
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