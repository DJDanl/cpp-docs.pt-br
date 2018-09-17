---
title: Versão de correção de problemas na compilação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- release builds, troubleshooting
- debug builds, memory overwrites
- memory, overwrites
- troubleshooting Visual C++, release builds
- troubleshooting release builds
ms.assetid: a0c0818e-4c47-4fe0-a611-50d61a41bd88
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b9b304fa6bcc9b0b248719ea44b28e9dae5c76a6
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726525"
---
# <a name="fixing-release-build-problems"></a>Corrigindo problemas de build da versão

Se seu código gera erros de compilação depois de alternar do build de depuração para o build de lançamento, há algumas áreas que você deve verificar.

Você pode receber avisos do compilador durante uma compilação otimizada (lançamento) que não tenha recebido durante uma compilação de depuração.

- [Examine instruções ASSERT](../../build/reference/using-verify-instead-of-assert.md)

- [Use o Build de depuração para verificar se há memória substitui](../../build/reference/using-the-debug-build-to-check-for-memory-overwrite.md)

- [Ativar a geração de informações de depuração para o Build de versão](../../build/reference/how-to-debug-a-release-build.md)

- [Verificação de substituição de memória](../../build/reference/checking-for-memory-overwrites.md)

## <a name="see-also"></a>Consulte também

[Builds de versão](../../build/reference/release-builds.md)<br/>
[Problemas comuns durante a criação de um build de versão](../../build/reference/common-problems-when-creating-a-release-build.md)<br/>
[Otimizando seu código](../../build/reference/optimizing-your-code.md)