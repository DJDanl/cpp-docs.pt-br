---
title: NMAKE aviso U4010 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U4010
dev_langs:
- C++
helpviewer_keywords:
- U4010
ms.assetid: 99d8eb9a-ae31-40d1-b8c5-8c66732127d3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc8c99bb4a9b5daf7f630771d0f240479aaf5f3a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="nmake-warning-u4010"></a>Aviso U4010 (NMAKE)
'target': compilação falhou; /K especificado, continuando...  
  
 Um comando no bloco de comandos para o destino fornecido retornou um código de saída diferente de zero. A opção /K informado NMAKE para continuar o processamento relacionados partes da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.  
  
 Se o destino especificado é, em si, um dependente de outro destino, NMAKE emite o aviso [U4011](../../error-messages/tool-errors/nmake-warning-u4011.md) após este aviso.