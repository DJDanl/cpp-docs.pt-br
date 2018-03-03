---
title: "Compilador (nível 1) de aviso C4650 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4650
dev_langs:
- C++
helpviewer_keywords:
- C4650
ms.assetid: 3190b3e3-dcd6-4846-939b-f900ab652b2a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: af10d05562c0c60c6a010e105441533362d058df
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4650"></a>Compilador C4650 de aviso (nível 1)
informações de depuração não está no cabeçalho pré-compilado; apenas símbolos globais do cabeçalho estarão disponíveis  
  
 O arquivo de cabeçalho pré-compilado não foi compilado com informações de depuração simbólicas de Microsoft.  
  
 Quando vinculado, o arquivo executável ou de vínculo dinâmico biblioteca resultante não incluirá informações de símbolos locais contidas no cabeçalho pré-compilado de depuração.  
  
 Esse aviso pode ser evitado através da recompilação do arquivo de cabeçalho pré-compilado com a [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) opção de linha de comando.