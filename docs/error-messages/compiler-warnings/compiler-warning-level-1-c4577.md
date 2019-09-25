---
title: Aviso do compilador C4577
description: Descrição e solução de aviso do compilador C4577.
ms.date: 09/18/2019
helpviewer_keywords:
- C4577
ms.openlocfilehash: 637023f4c27f93238fbbd13b4a0e652e6cd958e0
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/24/2019
ms.locfileid: "71241097"
---
# <a name="compiler-warning-level-1-c4577"></a>Aviso do compilador (nível 1) C4577

> ' noexcept ' usado sem modo de tratamento de exceção especificado; a rescisão na exceção não é garantida. Especificar/EHsc

O compilador detectou uma `noexcept` especificação, mas o tratamento de exceção padrão C++ não foi especificado. O compilador não dá suporte total à manipulação de exceção C++ de acordo com o padrão, a menos que a opção de compilador [/EHsc](../../build/reference/eh-exception-handling-model.md) seja especificada. Para resolver esse problema, defina a opção de compilador **/EHsc** .

Esse aviso é novo no Visual Studio 2015 e está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).
