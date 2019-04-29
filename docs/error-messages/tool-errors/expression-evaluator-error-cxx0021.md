---
title: Erro CXX0021 (avaliador de expressão)
ms.date: 11/04/2016
f1_keywords:
- CXX0021
helpviewer_keywords:
- CXX0021
- CAN0021
ms.assetid: d6c0c35a-16c2-42c0-a7d2-e910350a47f0
ms.openlocfilehash: 373829e7200a556b3f832b1da127b4e33aa75749
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62359872"
---
# <a name="expression-evaluator-error-cxx0021"></a>Erro CXX0021 (avaliador de expressão)

struct ou União usada como escalar

Uma estrutura ou união foi usado em uma expressão, mas nenhum elemento foi especificado.

Ao manipular uma estrutura ou variável de união, o nome da variável pode aparecer por si só, sem um qualificador de campo. Se uma estrutura ou união é usado em uma expressão, ele deve ser qualificado com o elemento específico desejado.

Especifica o elemento cujo valor deve ser usado na expressão.

Esse erro é idêntico ao CAN0021.