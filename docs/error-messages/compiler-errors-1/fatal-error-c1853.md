---
title: Erro fatal C1853
ms.date: 11/04/2016
f1_keywords:
- C1853
helpviewer_keywords:
- C1853
ms.assetid: ceb9b4a5-92bf-4573-8a9f-3109cc7743ce
ms.openlocfilehash: 056db975fecef4e101dbbba7e2084236489498c7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202859"
---
# <a name="fatal-error-c1853"></a>Erro fatal C1853

> o arquivo de cabeçalho pré-compilado '*filename*' é de uma versão anterior do compilador, ou o cabeçalho pré-compilado é C++ e você o está usando de C (ou vice-versa)

Possíveis causas:

- O cabeçalho pré-compilado foi compilado com uma versão anterior do compilador. Tente recompilar o cabeçalho com o compilador atual.

- O cabeçalho pré-compilado é C++ e você o está usando de c. tente recompilar o cabeçalho para uso com C especificando uma das opções do compilador [/TC](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md) ou alterando o sufixo do arquivo de origem para "C". Para obter mais informações, consulte [duas opções para pré-compilação de código](../../build/creating-precompiled-header-files.md#two-choices-for-precompiling-code).
