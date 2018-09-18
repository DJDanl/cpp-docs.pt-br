---
title: Erro do compilador C3859 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3859
dev_langs:
- C++
helpviewer_keywords:
- C3859
ms.assetid: 40e93b25-4393-4467-90de-035434a665c7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1ac06a09a6ad66384fd2b5423e3df046771f7653
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053382"
---
# <a name="compiler-error-c3859"></a>Erro do compilador C3859

intervalo de memória virtual para PCH excedido; recompile com uma opção de linha de comando de '-Zmvalue' ou superior

O cabeçalho pré-compilado é muito pequeno para a quantidade de dados que o compilador está tentando colocar nele. Use o **/Zm** sinalizador do compilador para especificar um valor maior para o arquivo de cabeçalho pré-compilado. Para obter mais informações, consulte [/Zm (especificar pré-compilado cabeçalho alocação de limite de memória)](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md).