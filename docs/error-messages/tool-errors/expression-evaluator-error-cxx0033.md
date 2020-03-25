---
title: Erro CXX0033 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0033
helpviewer_keywords:
- CAN0033
- CXX0033
ms.assetid: 0bd62c5b-de89-481f-9b12-88fe84805afe
ms.openlocfilehash: 2916808d98f1fabc2157fbedc96d76e196661279
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195507"
---
# <a name="expression-evaluator-error-cxx0033"></a>Erro CXX0033 (avaliador de expressão)

erro em informações do tipo OMF

O arquivo executável não tinha um OMF (formato de módulo de objeto) válido para depuração.

Esse erro é idêntico a CAN0033.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O arquivo executável não foi criado com o vinculador lançado com esta versão do Visual C++. Vincule novamente o código do objeto usando a versão atual do LINK. exe.

1. O arquivo. exe pode ter sido corrompido. Recompile e vincule novamente o programa.
