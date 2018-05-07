---
title: Erro Fatal de CVTRES CVT1100 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CVT1100
dev_langs:
- C++
helpviewer_keywords:
- CVT1100
ms.assetid: 886e88dd-5818-4b5f-84f2-d2a3d75f0aaf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 32085c4c37c82567eb78f46b52bcc4a6c41daae5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cvtres-fatal-error-cvt1100"></a>Erro fatal CVT1100 (CVTRES)
recurso duplicado —: tipo, nome:, idiomas:, sinalizadores: sinalizadores, tamanho:  
  
 Determinado recurso foi especificado mais de uma vez.  
  
 Você pode obter esse erro se o vinculador está criando uma biblioteca de tipos e você não especificar [/TLBID](../../build/reference/tlbid-specify-resource-id-for-typelib.md) e um recurso em seu projeto já utiliza 1. Nesse caso, especifique /TLBID e outro número até 65535.