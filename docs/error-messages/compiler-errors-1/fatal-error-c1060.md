---
title: Erro fatal C1060
ms.date: 11/04/2016
f1_keywords:
- C1060
helpviewer_keywords:
- C1060
ms.assetid: feaf305c-c84c-4160-b974-50e283412849
ms.openlocfilehash: f1a7c3ccab716a9281d4520f4c5fce2afff60187
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204432"
---
# <a name="fatal-error-c1060"></a>Erro fatal C1060

o compilador está fora do espaço de heap

O sistema operacional ou a biblioteca de tempo de execução não pode preencher uma solicitação de memória.

### <a name="to-fix-this-error-try-the-following-possible-solutions"></a>Para corrigir esse erro tente as seguintes soluções possíveis

1. Se o compilador também emitir erros [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md) e [C3859](../../error-messages/compiler-errors-2/compiler-error-c3859.md), use a opção de compilador [/ZM](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) para reduzir o limite de alocação de memória. Mais espaço de heap está disponível para o aplicativo se você diminuir a alocação da memória restante.

   Se a opção [/ZM](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) já estiver definida, tente removê-la. O espaço de heap pode se esgotar porque o limite de alocação de memória especificado na opção é muito alto. O compilador usará um limite padrão se você remover a opção [/ZM](../../build/reference/zm-specify-precompiled-header-memory-allocation-limit.md) .

1. Se você estiver compilando em uma plataforma de 64 bits, use o conjunto de ferramentas do compilador de 64 bits. Para obter informações, consulte [como habilitar um conjunto de ferramentas do Visual C++ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md).

1. No Windows de 32 bits, tente usar a opção [/3GB](https://support.microsoft.com/help/833721/available-switch-options-for-the-windows-xp-and-the-windows-server-200) boot. ini.

1. Aumente o tamanho do arquivo de permuta do Windows.

1. Feche outros programas em execução.

1. Elimine arquivos de inclusão desnecessários.

1. Elimine variáveis globais desnecessárias, por exemplo, alocando memória dinamicamente em vez de declarar uma matriz grande.

1. Elimine declarações não usadas.

9. Divida o arquivo atual em arquivos menores.
