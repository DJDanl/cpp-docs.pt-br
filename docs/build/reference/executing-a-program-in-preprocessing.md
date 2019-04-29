---
title: Executando um programa em pré-processamento
ms.date: 11/04/2016
helpviewer_keywords:
- program execution [C++]
ms.assetid: 5ecf123a-20e5-40cd-b8d8-dd5a9fdd4b24
ms.openlocfilehash: 564e4aebb3a0502f18550fb9d323e8b30f1303f6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62271587"
---
# <a name="executing-a-program-in-preprocessing"></a>Executando um programa em pré-processamento

Para usar um código de saída comando durante o pré-processamento, especifique o comando, com quaisquer argumentos, dentro de colchetes ([]). Todas as macros são expandidas antes que o comando é executado. NMAKE substitui a especificação de comando com o código de saída do comando, que pode ser usado em uma expressão para controlar o pré-processamento.

## <a name="see-also"></a>Consulte também

[Expressões no pré-processamento de makefile](expressions-in-makefile-preprocessing.md)
