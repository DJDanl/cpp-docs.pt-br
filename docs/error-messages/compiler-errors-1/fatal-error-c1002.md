---
title: Erro fatal C1002
ms.date: 11/04/2016
f1_keywords:
- C1002
helpviewer_keywords:
- C1002
ms.assetid: bd6d274a-c7b4-43af-8bf2-23c5e442aa22
ms.openlocfilehash: 0588da99994be547742cc530ba435002a2d73359
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50640499"
---
# <a name="fatal-error-c1002"></a>Erro fatal C1002

o compilador está fora do espaço de heap no passo 2

O compilador ficou sem espaço de memória dinâmica durante a segunda fase, provavelmente devido a um programa com muitos símbolos ou expressões complexas.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Divida o arquivo de origem em vários arquivos menores.

1. Divida expressões em subexpressões menores.

1. Remova outros programas ou drivers que consomem memória.