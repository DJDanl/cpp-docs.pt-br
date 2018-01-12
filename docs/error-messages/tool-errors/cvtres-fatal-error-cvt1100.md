---
title: Erro Fatal de CVTRES CVT1100 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: CVT1100
dev_langs: C++
helpviewer_keywords: CVT1100
ms.assetid: 886e88dd-5818-4b5f-84f2-d2a3d75f0aaf
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 906e03b778276196d36a04e6b9e2f02a2d5944bc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cvtres-fatal-error-cvt1100"></a>Erro fatal CVT1100 (CVTRES)
recurso duplicado —: tipo, nome:, idiomas:, sinalizadores: sinalizadores, tamanho:  
  
 Determinado recurso foi especificado mais de uma vez.  
  
 Você pode obter esse erro se o vinculador está criando uma biblioteca de tipos e você não especificar [/TLBID](../../build/reference/tlbid-specify-resource-id-for-typelib.md) e um recurso em seu projeto já utiliza 1. Nesse caso, especifique /TLBID e outro número até 65535.