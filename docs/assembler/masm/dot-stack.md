---
title: .STACK
ms.date: 11/05/2019
f1_keywords:
- .STACK
helpviewer_keywords:
- .STACK directive
ms.assetid: 70019463-5d4f-41b6-8464-023a8ac2466f
ms.openlocfilehash: 78c089c771e8e5a8c82905578ec2377246a44a0e
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73703535"
---
# <a name="stack-32-bit-masm"></a>. PILHA (MASM de 32 bits)

Quando usado com [. MODELO](../../assembler/masm/dot-model.md), define um segmento de pilha (com o nome de segmento pilha). O `size` opcional especifica o número de bytes para a pilha (padrão 1.024). A diretiva `.STACK` fecha automaticamente a instrução Stack. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> . PILHA [[tamanho]]

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>