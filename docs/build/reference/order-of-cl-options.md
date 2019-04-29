---
title: Ordem de opções CL (C++) – Visual Studio
ms.date: 12/14/2018
f1_keywords:
- cl
helpviewer_keywords:
- cl.exe compiler, setting options
ms.assetid: 300908ce-ae00-4b45-964b-e4e69ff6777b
ms.openlocfilehash: 93907265bed8141b5c63edd5e75d632e060351fe
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320936"
---
# <a name="order-of-cl-options"></a>Ordem de opções CL

As opções podem aparecer em qualquer lugar na linha de comando CL, exceto para a opção /link, que deve ocorrer pela última vez. O compilador começa com as opções especificadas na [variável de ambiente CL](cl-environment-variables.md) e, em seguida, lê a linha de comando da esquerda para direita – processamento de arquivos de comando na ordem encontrá-las. Cada opção se aplica a todos os arquivos na linha de comando. Se o CL encontrar opções conflitantes, ele usa a opção mais à direita.

## <a name="see-also"></a>Consulte também

[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
