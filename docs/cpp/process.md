---
title: process
ms.date: 11/04/2016
f1_keywords:
- process_cpp
helpviewer_keywords:
- __declspec keyword [C++], process
- process __declspec keyword
ms.assetid: 60eecc2f-4eef-4567-b9db-aaed34733023
ms.openlocfilehash: f684c9c2ddfcb0aa166e1240c5f928ee52218f45
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227199"
---
# `process`

Especifica que o processo de aplicativo gerenciado deve ter uma única cópia de uma determinada variável global, variável de membro estática ou variável local estática compartilhada por todos os domínios de aplicativo no processo. Isso foi projetado principalmente para ser usado durante a compilação com **`/clr:pure`** , que foi preterido no visual studio 2015 e sem suporte no visual studio 2017. Ao compilar com **`/clr`** , as variáveis global e estática são por processo por padrão e não precisam usar **`__declspec(process)`** .

Somente uma variável global, uma variável de membro estático ou uma variável local estática do tipo nativo podem ser marcadas com **`__declspec(process)`** .

**`process`** Só é válida durante a compilação com [`/clr`](../build/reference/clr-common-language-runtime-compilation.md) .

Se você quiser que cada domínio de aplicativo tenha sua própria cópia de uma variável global, use [AppDomain](../cpp/appdomain.md).

Consulte [domínios e Visual C++ do aplicativo](../dotnet/application-domains-and-visual-cpp.md) para obter mais informações.

## <a name="see-also"></a>Confira também

[`__declspec`](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
