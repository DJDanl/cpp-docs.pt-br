---
title: Erro CXX0033 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0033
helpviewer_keywords:
- CAN0033
- CXX0033
ms.assetid: 0bd62c5b-de89-481f-9b12-88fe84805afe
ms.openlocfilehash: 8563eb2fbc24c6ad8db639d2e227802412a16090
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50642760"
---
# <a name="expression-evaluator-error-cxx0033"></a>Erro CXX0033 (avaliador de expressão)

Erro nas informações de tipo OMF

O arquivo executável não tinha um formato de módulo de objeto válido (OMF) para depuração.

Esse erro é idêntico ao CAN0033.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O arquivo executável não foi criado com a opção de vinculador lançada com esta versão do Visual C++. Vincular novamente o código de objeto usando a versão atual do LINK.exe.

1. O arquivo .exe pode ter sido corrompido. Recompile e vincular novamente o programa.