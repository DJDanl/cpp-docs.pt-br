---
title: Compilador (nível 1) de aviso C4650 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4650
dev_langs:
- C++
helpviewer_keywords:
- C4650
ms.assetid: 3190b3e3-dcd6-4846-939b-f900ab652b2a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6cb1c9979141e7958b6c2802aaf321efe41e9570
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4650"></a>Compilador C4650 de aviso (nível 1)
informações de depuração não está no cabeçalho pré-compilado; apenas símbolos globais do cabeçalho estarão disponíveis  
  
 O arquivo de cabeçalho pré-compilado não foi compilado com informações de depuração simbólicas de Microsoft.  
  
 Quando vinculado, o arquivo executável ou de vínculo dinâmico biblioteca resultante não incluirá informações de símbolos locais contidas no cabeçalho pré-compilado de depuração.  
  
 Esse aviso pode ser evitado através da recompilação do arquivo de cabeçalho pré-compilado com a [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção de linha de comando.