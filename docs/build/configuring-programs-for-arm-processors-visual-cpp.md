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
ms.openlocfilehash: fbdf882367deb34570dd5b5ebb1b4001be739297
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373851"
---
# <a name="configure-visual-c-for-arm-processors"></a>Configurar o Visual C++ para processadores ARM

Esta seção da documentação contém informações sobre como utilizar as ferramentas de compilação do Visual C++ para destinar hardware ARM.

## <a name="in-this-section"></a>Nesta seção

[Visão geral das convenções ARM ABI](../build/overview-of-arm-abi-conventions.md)<br/>
Descreve a interface binária do aplicativo usada pelo Windows em ARM para registrar uso, convenções de chamada e tratamento de exceções.

[Visão geral das convenções ARM64 ABI](../build/arm64-windows-abi-conventions.md)<br/>
Descreve a interface binária de aplicativo usado pelo Windows arm64 para registrar uso, convenções de chamada e tratamento de exceção.

[Problemas de migração ARM do Visual C++ comuns](../build/common-visual-cpp-arm-migration-issues.md)<br/>
Descreve elementos de código C++ que são comumente considerados como portáteis entre arquiteturas, porém, que produzem resultados diferentes para ARM do que em x86 ou x64.

[Tratamento de exceção do ARM](../build/arm-exception-handling.md)<br/>
Descreve o esquema de codificação para desenrolamento de pilha durante tratamento de exceções estruturado no Windows em ARM.

[Tratamento de exceção do ARM64](../build/arm64-exception-handling.md)<br/>
Descreve o esquema de codificação para desenrolamento de pilha durante manipulação de exceção estruturada no Windows arm64.

## <a name="related-sections"></a>Seções relacionadas

[Intrínsecos do ARM](../intrinsics/arm-intrinsics.md)<br/>
Descreve intrínsecas do compilador para processadores que usam a arquitetura ARM.
