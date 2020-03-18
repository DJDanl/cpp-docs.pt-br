---
title: Ordem das opções CL (C++) – Visual Studio
ms.date: 12/14/2018
helpviewer_keywords:
- cl.exe compiler, setting options
ms.assetid: 300908ce-ae00-4b45-964b-e4e69ff6777b
ms.openlocfilehash: 6c57a68dd15d82a9d6a01bfe145374bda6eb1510
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439206"
---
# <a name="order-of-cl-options"></a>Ordem de opções CL

As opções podem aparecer em qualquer lugar na linha de comando CL, exceto para a opção/link, que deve ocorrer por último. O compilador começa com as opções especificadas na [variável de ambiente CL](cl-environment-variables.md) e, em seguida, lê a linha de comando da esquerda para a direita — Processando arquivos de comando na ordem em que encontrar. Cada opção se aplica a todos os arquivos na linha de comando. Se o CL encontrar opções conflitantes, ele usará a opção mais à direita.

## <a name="see-also"></a>Consulte também

[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
