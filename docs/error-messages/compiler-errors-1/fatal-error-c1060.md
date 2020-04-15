---
title: Erro fatal C1060
ms.date: 11/04/2016
f1_keywords:
- C1060
helpviewer_keywords:
- C1060
ms.assetid: feaf305c-c84c-4160-b974-50e283412849
ms.openlocfilehash: 83135b77ceb75b4c2b05211260d1aed8fac6777f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320290"
---
# <a name="fatal-error-c1060"></a>Erro fatal C1060

o compilador está fora do espaço de heap

O sistema operacional ou a biblioteca de tempo de execução não pode preencher uma solicitação de memória.

### <a name="to-fix-this-error-try-the-following-possible-solutions"></a>Para corrigir esse erro tente as seguintes soluções possíveis

1. Se o compilador também emitir erros [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md) e [C3859,](../../error-messages/compiler-errors-2/compiler-error-c3859.md)use a opção [compilador /Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) para diminuir o limite de alocação de memória. Mais espaço de heap está disponível para o aplicativo se você diminuir a alocação da memória restante.

   Se a opção [/Zm](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) já estiver definida, tente removê-la. O espaço de heap pode se esgotar porque o limite de alocação de memória especificado na opção é muito alto. O compilador usa um limite padrão se você remover a opção [/Zm.](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md)

1. Se você estiver compilando em uma plataforma de 64 bits, use o conjunto de ferramentas do compilador de 64 bits. Para obter informações, consulte [Como: Ativar um conjunto de ferramentas Visual C++ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md).

1. No Windows de 32 bits, tente usar o switch inicial.ini de [3GB.](https://support.microsoft.com/help/833721/available-switch-options-for-the-windows-xp-and-the-windows-server-200)

1. Aumente o tamanho do arquivo de permuta do Windows.

1. Feche outros programas em execução.

1. Elimine arquivos de inclusão desnecessários.

1. Elimine variáveis globais desnecessárias, por exemplo, alocando memória dinamicamente em vez de declarar uma matriz grande.

1. Elimine declarações não usadas.

1. Divida o arquivo atual em arquivos menores.
