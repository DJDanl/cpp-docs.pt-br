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
ms.openlocfilehash: da87a87a2e97736d202b7ddb9be2dbec54fed44d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="executing-a-program-in-preprocessing"></a>Executando um programa em pré-processamento
Para usar o código de saída do comando durante o pré-processamento, especifique o comando, com os argumentos, entre colchetes ([]). Todas as macros são expandidas antes do comando é executado. NMAKE substitui a especificação de comando com o código de saída do comando, que pode ser usado em uma expressão para controlar o pré-processamento.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões no pré-processamento de makefile](../build/expressions-in-makefile-preprocessing.md)