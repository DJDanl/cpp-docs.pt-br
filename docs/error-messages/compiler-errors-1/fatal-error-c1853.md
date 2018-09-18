---
title: Erro fatal C1853 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- devlang-cpp
ms.topic: error-reference
f1_keywords:
- C1853
dev_langs:
- C++
helpviewer_keywords:
- C1853
ms.assetid: ceb9b4a5-92bf-4573-8a9f-3109cc7743ce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 016e5bbf064643ddff0f63c5e16a967ed914f3e2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044945"
---
# <a name="fatal-error-c1853"></a>Erro fatal C1853

> '*filename*' arquivo de cabeçalho pré-compilado é de uma versão anterior do compilador, ou o cabeçalho pré-compilado é C++ e você estiver usando do C (ou vice-versa)

Possíveis causas:

- O cabeçalho pré-compilado foi compilado com uma versão anterior do compilador. Tente recompilar o cabeçalho com o compilador atual.

- O cabeçalho pré-compilado é C++ e são usá-lo do tente C. recompilar o cabeçalho para uso com o C, especificando um dos [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) opções do compilador ou alterando o sufixo do arquivo de origem para o "c". Para obter mais informações, consulte [duas escolhas para pré-compilar código](../../build/reference/creating-precompiled-header-files.md#two-choices-for-precompiling-code).