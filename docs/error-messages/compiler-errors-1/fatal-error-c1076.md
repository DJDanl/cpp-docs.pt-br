---
title: Erro fatal C1076 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1076
dev_langs:
- C++
helpviewer_keywords:
- C1076
ms.assetid: 84ac1180-3e8a-48e8-9f77-7f18a778b964
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6b7ec56c0e3d9cdbd954e9277a63d45f2ee42435
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46102197"
---
# <a name="fatal-error-c1076"></a>Erro fatal C1076

limite do compilador: limite do heap interno atingido; use /Zm para especificar um limite maior

Esse erro pode ser causado por muitos símbolos ou por muitas instanciações do modelo.

Para resolver esse erro:

1. Use o [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) opção de definir o limite de memória do compilador como o valor especificado na [C3859](../../error-messages/compiler-errors-2/compiler-error-c3859.md) mensagem de erro. Para obter mais informações sobre como definir esse valor no Visual Studio, consulte a seção comentários no [/Zm (especificar pré-compilado cabeçalho alocação de limite de memória)](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md).

1. Se você estiver usando os compiladores hospedados de 32 bits em um sistema operacional de 64 bits, use os compiladores hospedados de 64 bits. Para obter mais informações, consulte [como: habilitar um 64-Bit Visual C++ conjunto de ferramentas na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md).

1. Elimine arquivos de inclusão desnecessários.

1. Elimine variáveis globais desnecessárias, por exemplo, alocando memória dinamicamente em vez de declarar uma matriz grande.

1. Elimine declarações não usadas.

1. Divida funções grandes em funções menores.

1. Divida classes grandes em classes menores.

1. Divida o arquivo atual em arquivos menores.

Se C1076 ocorrer imediatamente após o build é iniciado, o valor especificado para **/Zm** provavelmente é muito alto para o seu programa. Reduzir a **/Zm** valor.