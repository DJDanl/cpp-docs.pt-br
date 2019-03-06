---
title: Ordem de opções CL
ms.date: 11/04/2016
f1_keywords:
- cl
helpviewer_keywords:
- cl.exe compiler, setting options
ms.assetid: 300908ce-ae00-4b45-964b-e4e69ff6777b
ms.openlocfilehash: d87e3214d4829f81258acd00abebced34d7d969d
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57423684"
---
# <a name="order-of-cl-options"></a>Ordem de opções CL

As opções podem aparecer em qualquer lugar na linha de comando CL, exceto para a opção /link, que deve ocorrer pela última vez. O compilador começa com as opções especificadas na [variável de ambiente CL](../../build/reference/cl-environment-variables.md) e, em seguida, lê a linha de comando da esquerda para direita – processamento de arquivos de comando na ordem encontrá-las. Cada opção se aplica a todos os arquivos na linha de comando. Se o CL encontrar opções conflitantes, ele usa a opção mais à direita.

## <a name="see-also"></a>Consulte também

[Sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)
