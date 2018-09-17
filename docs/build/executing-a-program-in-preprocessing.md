---
title: Executando um programa em pré-processamento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- program execution [C++]
ms.assetid: 5ecf123a-20e5-40cd-b8d8-dd5a9fdd4b24
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e2b0571e67e7c5d24cf31dce6fce548735cad966
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45721455"
---
# <a name="executing-a-program-in-preprocessing"></a>Executando um programa em pré-processamento

Para usar um código de saída comando durante o pré-processamento, especifique o comando, com quaisquer argumentos, dentro de colchetes ([]). Todas as macros são expandidas antes que o comando é executado. NMAKE substitui a especificação de comando com o código de saída do comando, que pode ser usado em uma expressão para controlar o pré-processamento.

## <a name="see-also"></a>Consulte também

[Expressões no pré-processamento de makefile](../build/expressions-in-makefile-preprocessing.md)