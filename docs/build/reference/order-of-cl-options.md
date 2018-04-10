---
title: Ordem de opções CL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- cl
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler, setting options
ms.assetid: 300908ce-ae00-4b45-964b-e4e69ff6777b
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8ef67792b01d4d4dab535bfb180cd70beb2316b6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="order-of-cl-options"></a>Ordem de opções CL
Opções podem aparecer em qualquer lugar na linha de comando CL, exceto para a opção /link que deve ocorrer por último. O compilador começa com opções especificadas no [variável de ambiente CL](../../build/reference/cl-environment-variables.md) e lê a linha de comando da esquerda para a direita, processamento de arquivos de comando na ordem encontrá-las. Cada opção se aplica a todos os arquivos na linha de comando. Se CL encontrar opções de conflito, ele usa a opção mais à direita.  
  
## <a name="see-also"></a>Consulte também  
 [Sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)