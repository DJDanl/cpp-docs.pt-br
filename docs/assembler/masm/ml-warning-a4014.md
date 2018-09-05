---
title: Aviso de ML A4014 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A4014
dev_langs:
- C++
helpviewer_keywords:
- A4014
ms.assetid: 11bc8920-3255-4ac8-999a-b9ea9c15bc81
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d3108d961c213ca5035cdba5ca9e7c5c8c10317b
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43692145"
---
# <a name="ml-warning-a4014"></a>Aviso A4014 (ML)

instruções e dados inicializados não tem suportados em segmentos BSS

Foi feita uma tentativa para definir dados inicializados dentro de uma seção BSS.  Uma seção BSS é definida como uma classe cujo nome é BSS.  Isso inclui o segmento simplificado `.data?`.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>