---
title: Erro do compilador C3859
ms.date: 11/04/2016
f1_keywords:
- C3859
helpviewer_keywords:
- C3859
ms.assetid: 40e93b25-4393-4467-90de-035434a665c7
ms.openlocfilehash: be6ccaab49cb329e862fb6068af1337eddbaac8f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50490266"
---
# <a name="compiler-error-c3859"></a>Erro do compilador C3859

intervalo de memória virtual para PCH excedido; recompile com uma opção de linha de comando de '-Zmvalue' ou superior

O cabeçalho pré-compilado é muito pequeno para a quantidade de dados que o compilador está tentando colocar nele. Use o **/Zm** sinalizador do compilador para especificar um valor maior para o arquivo de cabeçalho pré-compilado. Para obter mais informações, consulte [/Zm (especificar pré-compilado cabeçalho alocação de limite de memória)](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md).