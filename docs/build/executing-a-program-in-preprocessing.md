---
title: Executando um programa em pré-processamento
ms.date: 11/04/2016
helpviewer_keywords:
- program execution [C++]
ms.assetid: 5ecf123a-20e5-40cd-b8d8-dd5a9fdd4b24
ms.openlocfilehash: d95079349981b073533bb00abcd053454542a044
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57413297"
---
# <a name="executing-a-program-in-preprocessing"></a>Executando um programa em pré-processamento

Para usar um código de saída comando durante o pré-processamento, especifique o comando, com quaisquer argumentos, dentro de colchetes ([]). Todas as macros são expandidas antes que o comando é executado. NMAKE substitui a especificação de comando com o código de saída do comando, que pode ser usado em uma expressão para controlar o pré-processamento.

## <a name="see-also"></a>Consulte também

[Expressões no pré-processamento de makefile](../build/expressions-in-makefile-preprocessing.md)
