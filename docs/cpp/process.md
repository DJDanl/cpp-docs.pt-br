---
title: process
ms.date: 11/04/2016
f1_keywords:
- process_cpp
helpviewer_keywords:
- __declspec keyword [C++], process
- process __declspec keyword
ms.assetid: 60eecc2f-4eef-4567-b9db-aaed34733023
ms.openlocfilehash: 049360dddff2b9ca2ea460b96e027e86899f1ecb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50591731"
---
# <a name="process"></a>process

Especifica que o processo de aplicativo gerenciado deve ter uma única cópia de uma determinada variável global, variável de membro estática ou variável local estática compartilhada por todos os domínios de aplicativo no processo. Isso foi destinado principalmente a ser usado ao compilar com **/clr: pure**, que é preterido no Visual Studio 2017 e sem suporte no Visual Studio 2017. Ao compilar com **/clr**, as variáveis globais e estáticas são por processo por padrão e não precisam usar **__declspec(process)**.

Somente uma variável global, uma variável de membro estático ou uma variável local estática do tipo nativo pode ser marcada com **__declspec(process)**.

**processo** só é válido ao compilar com [/clr](../build/reference/clr-common-language-runtime-compilation.md).

Se você quiser que cada domínio de aplicativo tem sua própria cópia de uma variável global, use [appdomain](../cpp/appdomain.md).

Ver [domínios de aplicativo e do Visual C++](../dotnet/application-domains-and-visual-cpp.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
