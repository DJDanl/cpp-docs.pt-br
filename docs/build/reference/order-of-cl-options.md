---
title: Ordem de opções CL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- cl
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler, setting options
ms.assetid: 300908ce-ae00-4b45-964b-e4e69ff6777b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 165e20eefecd20ad9dec9e01b38c5eaa7926e4eb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32372803"
---
# <a name="order-of-cl-options"></a>Ordem de opções CL
Opções podem aparecer em qualquer lugar na linha de comando CL, exceto para a opção /link que deve ocorrer por último. O compilador começa com opções especificadas no [variável de ambiente CL](../../build/reference/cl-environment-variables.md) e lê a linha de comando da esquerda para a direita, processamento de arquivos de comando na ordem encontrá-las. Cada opção se aplica a todos os arquivos na linha de comando. Se CL encontrar opções de conflito, ele usa a opção mais à direita.  
  
## <a name="see-also"></a>Consulte também  
 [Sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)