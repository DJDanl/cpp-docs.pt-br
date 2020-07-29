---
title: Aviso do compilador C4577
description: Descrição e solução de aviso do compilador C4577.
ms.date: 09/18/2019
f1_keywords:
- C4577
helpviewer_keywords:
- C4577
ms.openlocfilehash: fb9d412196e7764326a397a4bf6e76c8723ac2ae
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87196247"
---
# <a name="compiler-warning-level-1-c4577"></a>Aviso do compilador (nível 1) C4577

> ' noexcept ' usado sem modo de tratamento de exceção especificado; a rescisão na exceção não é garantida. Especificar/EHsc

O compilador detectou uma **`noexcept`** especificação, mas o tratamento de exceção padrão do C++ não foi especificado. O compilador não dá suporte total à manipulação de exceção de acordo com o padrão C++, a menos que a opção de compilador [/EHsc](../../build/reference/eh-exception-handling-model.md) seja especificada. Para resolver esse problema, defina a opção de compilador **/EHsc** .

Esse aviso é novo no Visual Studio 2015 e está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).
