---
title: Configurar projetos do C++ para processadores ARM
ms.date: 07/11/2018
ms.assetid: 3d95f221-656a-480d-9651-9ad263895747
ms.openlocfilehash: 7e6e0c97245c0941abc49096d1693a8d152c1709
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57812467"
---
# <a name="configure-c-projects-for-arm-processors"></a>Configurar projetos do C++ para processadores ARM

Esta seção da documentação contém informações sobre como usar as ferramentas de build do MSVC para destinar hardware ARM.

## <a name="in-this-section"></a>Nesta seção

[Visão geral das convenções ARM ABI](overview-of-arm-abi-conventions.md)<br/>
Descreve a interface binária do aplicativo usada pelo Windows em ARM para registrar uso, convenções de chamada e tratamento de exceções.

[Visão geral das convenções ARM64 ABI](arm64-windows-abi-conventions.md)<br/>
Descreve a interface binária de aplicativo usado pelo Windows arm64 para registrar uso, convenções de chamada e tratamento de exceção.

[Problemas comuns na migração ARM MSVC](common-visual-cpp-arm-migration-issues.md)<br/>
Descreve elementos de código C++ que são comumente considerados como portáteis entre arquiteturas, porém, que produzem resultados diferentes para ARM do que em x86 ou x64.

[Tratamento de exceção do ARM](arm-exception-handling.md)<br/>
Descreve o esquema de codificação para desenrolamento de pilha durante tratamento de exceções estruturado no Windows em ARM.

[Tratamento de exceção do ARM64](arm64-exception-handling.md)<br/>
Descreve o esquema de codificação para desenrolamento de pilha durante manipulação de exceção estruturada no Windows arm64.

## <a name="related-sections"></a>Seções relacionadas

[Intrínsecos do ARM](../intrinsics/arm-intrinsics.md)<br/>
Descreve intrínsecas do compilador para processadores que usam a arquitetura ARM.
