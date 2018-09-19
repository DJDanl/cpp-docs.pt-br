---
title: Erro do compilador C3728 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3728
dev_langs:
- C++
helpviewer_keywords:
- C3728
ms.assetid: 6b510cb1-887f-4fcd-9a1f-3bb720417ed1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e412824bd2afdadfc21d71b73f38eb8ba5ace82d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46108411"
---
# <a name="compiler-error-c3728"></a>Erro do compilador C3728

'event': evento não tem um método raise

Metadados criados com uma linguagem como c#, que não permite um evento deve ser gerado de fora da classe na qual ela foi definida, foi incluído com o [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva e um programa do Visual C++ usando a programação de CLR tentou Gere o evento.

Para acionar um evento em um programa desenvolvido em uma linguagem como c#, a classe que contém o evento precisa também definir um método público que gera o evento.