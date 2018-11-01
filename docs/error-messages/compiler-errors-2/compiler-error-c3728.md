---
title: Erro do compilador C3728
ms.date: 11/04/2016
f1_keywords:
- C3728
helpviewer_keywords:
- C3728
ms.assetid: 6b510cb1-887f-4fcd-9a1f-3bb720417ed1
ms.openlocfilehash: 68aa23843b0470f15f409b6f3b58624f979ccfae
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50454581"
---
# <a name="compiler-error-c3728"></a>Erro do compilador C3728

'event': evento não tem um método raise

Metadados criados com uma linguagem como c#, que não permite um evento deve ser gerado de fora da classe na qual ela foi definida, foi incluído com o [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva e um programa do Visual C++ usando a programação de CLR tentou Gere o evento.

Para acionar um evento em um programa desenvolvido em uma linguagem como c#, a classe que contém o evento precisa também definir um método público que gera o evento.