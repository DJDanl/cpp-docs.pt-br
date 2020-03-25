---
title: Erro CXX0021 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0021
helpviewer_keywords:
- CXX0021
- CAN0021
ms.assetid: d6c0c35a-16c2-42c0-a7d2-e910350a47f0
ms.openlocfilehash: a800deb6bacbcae8666a3abad08b87d4f027790f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195833"
---
# <a name="expression-evaluator-error-cxx0021"></a>Erro CXX0021 (avaliador de expressão)

struct ou Union usado como escalar

Uma estrutura ou União foi usada em uma expressão, mas nenhum elemento foi especificado.

Ao manipular uma variável de estrutura ou União, o nome da variável pode aparecer por si só, sem um qualificador de campo. Se uma estrutura ou União for usada em uma expressão, ela deverá ser qualificada com o elemento específico desejado.

Especifique o elemento cujo valor deve ser usado na expressão.

Esse erro é idêntico a CAN0021.
