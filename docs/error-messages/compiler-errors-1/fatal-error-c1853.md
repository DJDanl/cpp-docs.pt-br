---
title: Erro fatal C1853
ms.date: 11/04/2016
f1_keywords:
- C1853
helpviewer_keywords:
- C1853
ms.assetid: ceb9b4a5-92bf-4573-8a9f-3109cc7743ce
ms.openlocfilehash: ec2d6bf6bac46cca8bdc2e3b8fe7cc6b7799d78a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165912"
---
# <a name="fatal-error-c1853"></a>Erro fatal C1853

> '*filename*' arquivo de cabeçalho pré-compilado é de uma versão anterior do compilador, ou o cabeçalho pré-compilado é C++ e você estiver usando do C (ou vice-versa)

Possíveis causas:

- O cabeçalho pré-compilado foi compilado com uma versão anterior do compilador. Tente recompilar o cabeçalho com o compilador atual.

- O cabeçalho pré-compilado é C++ e são usá-lo do tente C. recompilar o cabeçalho para uso com o C, especificando um dos [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) opções do compilador ou alterando o sufixo do arquivo de origem para o "c". Para obter mais informações, consulte [duas escolhas para pré-compilar código](../../build/creating-precompiled-header-files.md#two-choices-for-precompiling-code).