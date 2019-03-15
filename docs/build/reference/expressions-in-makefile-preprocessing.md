---
title: Expressões no pré-processamento de makefile
ms.date: 11/04/2016
helpviewer_keywords:
- preprocessing makefiles
- expressions [C++], makefile preprocessing
- makefiles, preprocessing
ms.assetid: 37f0f413-97e0-452c-a83f-3c9002c44c92
ms.openlocfilehash: 3d668492441eb2fc09be378dbebfe2b18c1b5753
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824615"
---
# <a name="expressions-in-makefile-preprocessing"></a>Expressões no pré-processamento de makefile

O **! IF** ou **! ELSE IF** `constantexpression` consiste em comandos, constantes de cadeia de caracteres ou constantes de inteiro (em notação decimal ou linguagem C). Use parênteses para agrupar expressões. Expressões usam C-style inteiro longo com sinal aritmético; números são no formulário de 32 bits complemento de dois no intervalo de – 2147483648 a 2147483647.

As expressões podem usar operadores que agem em valores constantes, códigos de saída de comandos, cadeias de caracteres, macros e caminhos de sistema de arquivos.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Operadores de pré-processamento de makefile](makefile-preprocessing-operators.md)

[Executando um programa em pré-processamento](executing-a-program-in-preprocessing.md)

## <a name="see-also"></a>Consulte também

[Pré-processamento de makefile](makefile-preprocessing.md)
