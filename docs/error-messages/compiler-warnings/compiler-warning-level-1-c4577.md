---
title: Aviso do compilador C4577
description: Descrição e solução de aviso do compilador C4577.
ms.date: 09/18/2019
f1_keywords:
- C4577
helpviewer_keywords:
- C4577
ms.openlocfilehash: e29e47b2a268d86f7f6a280b79a1604fe6eff8a4
ms.sourcegitcommit: 8762a3f9b5476b4dee03f0ee8064ea606550986e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/04/2019
ms.locfileid: "74810561"
---
# <a name="compiler-warning-level-1-c4577"></a>Aviso do compilador (nível 1) C4577

> ' noexcept ' usado sem modo de tratamento de exceção especificado; a rescisão na exceção não é garantida. Especificar/EHsc

O compilador detectou uma especificação de `noexcept` C++ , mas o tratamento de exceção padrão não foi especificado. O compilador não dá suporte total à manipulação de exceção C++ de acordo com o padrão, a menos que a opção de compilador [/EHsc](../../build/reference/eh-exception-handling-model.md) seja especificada. Para resolver esse problema, defina a opção de compilador **/EHsc** .

Esse aviso é novo no Visual Studio 2015 e está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).
