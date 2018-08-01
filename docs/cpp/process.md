---
title: processo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- process_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], process
- process __declspec keyword
ms.assetid: 60eecc2f-4eef-4567-b9db-aaed34733023
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fdad177231c02d2e6f6fad171ae1811ecb9ccc6c
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39407176"
---
# <a name="process"></a>process

Especifica que o processo de aplicativo gerenciado deve ter uma única cópia de uma determinada variável global, variável de membro estática ou variável local estática compartilhada por todos os domínios de aplicativo no processo. Isso foi destinado principalmente a ser usado ao compilar com **/clr: pure**, que é preterido no Visual Studio 2017 e sem suporte no Visual Studio 2017. Ao compilar com **/clr**, as variáveis globais e estáticas são por processo por padrão e não precisam usar **__declspec(process)**.

Somente uma variável global, uma variável de membro estático ou uma variável local estática do tipo nativo pode ser marcada com **__declspec(process)**.

**processo** só é válido ao compilar com [/clr](../build/reference/clr-common-language-runtime-compilation.md).

Se você quiser que cada domínio de aplicativo tem sua própria cópia de uma variável global, use [appdomain](../cpp/appdomain.md).

Ver [domínios de aplicativo e do Visual C++](../dotnet/application-domains-and-visual-cpp.md) para obter mais informações.

## <a name="see-also"></a>Consulte também
 [__declspec](../cpp/declspec.md)  
 [Palavras-chave](../cpp/keywords-cpp.md)
