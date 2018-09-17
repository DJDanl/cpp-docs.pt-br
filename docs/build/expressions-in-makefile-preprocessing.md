---
title: Expressões no pré-processamento de Makefile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- preprocessing makefiles
- expressions [C++], makefile preprocessing
- makefiles, preprocessing
ms.assetid: 37f0f413-97e0-452c-a83f-3c9002c44c92
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1070eb01802bd4b39f62ae24519ad6dabca7eb90
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45718998"
---
# <a name="expressions-in-makefile-preprocessing"></a>Expressões no pré-processamento de makefile

O **! IF** ou **! ELSE IF** `constantexpression` consiste em comandos, constantes de cadeia de caracteres ou constantes de inteiro (em notação decimal ou linguagem C). Use parênteses para agrupar expressões. Expressões usam C-style inteiro longo com sinal aritmético; números são no formulário de 32 bits complemento de dois no intervalo de – 2147483648 a 2147483647.

As expressões podem usar operadores que agem em valores constantes, códigos de saída de comandos, cadeias de caracteres, macros e caminhos de sistema de arquivos.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Operadores de pré-processamento de makefile](../build/makefile-preprocessing-operators.md)

[Executando um programa em pré-processamento](../build/executing-a-program-in-preprocessing.md)

## <a name="see-also"></a>Consulte também

[Pré-processamento de makefile](../build/makefile-preprocessing.md)