---
title: Configurar o Visual C++ para processadores ARM | Microsoft Docs
ms.custom: ''
ms.date: 07/11/2018
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 3d95f221-656a-480d-9651-9ad263895747
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3ce0e7e1f7c0936daed0fa6a51f6e254403205e0
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45714955"
---
# <a name="configure-visual-c-for-arm-processors"></a>Configurar o Visual C++ para processadores ARM

Esta seção da documentação contém informações sobre como utilizar as ferramentas de compilação do Visual C++ para destinar hardware ARM.

## <a name="in-this-section"></a>Nesta seção

[Visão geral das convenções do ARM ABI](../build/overview-of-arm-abi-conventions.md) descreve a interface binária de aplicativo usado pelo Windows em ARM para registrar uso, convenções de chamada e tratamento de exceção.

[Visão geral das convenções de ABI ARM64](../build/arm64-windows-abi-conventions.md) descreve a interface binária de aplicativo usado pelo Windows arm64 para registrar uso, convenções de chamada e tratamento de exceção.

[Problemas comuns de migração de ARM do C++ de Visual](../build/common-visual-cpp-arm-migration-issues.md) elementos de código C++ descreve que são comumente considerados como portáteis entre arquiteturas, mas que produzem resultados diferentes para ARM que para x86 e x64.

[Tratamento de exceção ARM](../build/arm-exception-handling.md) descreve o esquema de codificação para desenrolamento de pilha durante tratamento no Windows em ARM de exceções estruturado.

[Tratamento de exceções ARM64](../build/arm64-exception-handling.md) descreve o esquema de codificação para desenrolamento de pilha durante tratamento no Windows arm64 de exceções estruturado.

## <a name="related-sections"></a>Seções relacionadas

[Intrínsecos ARM](../intrinsics/arm-intrinsics.md) descreve intrínsecas do compilador para processadores que usam a arquitetura ARM.
