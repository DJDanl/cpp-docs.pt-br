---
title: Alterações gerais na linguagem (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 79a70768-225c-4ae2-84d1-178b20a9b042
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9b48ebdf0bf25399b08f8a1cb1240a857cfad352
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46418446"
---
# <a name="general-language-changes-ccli"></a>Alterações gerais em linguagens (C++/CLI)

Um número de recursos de linguagem CLR alterado de extensões gerenciadas para C++ para Visual C++.

As alterações descritas nesta seção são uma espécie de miscellany de idioma. Ele inclui uma alteração na manipulação de literais de cadeia de caracteres, uma alteração na resolução de sobrecarga entre uma elipse e o `Param` de atributo, a alteração do `typeof` para `typeid`, uma alteração na chamada de listas de inicializador de construtor e o Introdução de uma nova notação de conversão de `safe_cast`.

[Literal da cadeia de caracteres](../dotnet/string-literal.md)<br/>
Discute como a manipulação de literais de cadeia de caracteres foi alterada.

[Matriz de parâmetros e reticências](../dotnet/param-array-and-ellipsis.md)<br/>
Discute como `ParamArray` agora tem precedência sobre o botão de reticências (`...`) para resolver as chamadas de função com números de argumentos variáveis.

[typeof torna-se T::typeid](../dotnet/typeof-goes-to-t-typeid.md)<br/>
Discute como o `typeof` operador tem sido suplantado pelo `typeid`.

[Listas de inicializadores](../dotnet/initializer-lists.md)<br/>
Aborda as alterações na ordem de chamada de listas de inicializadores.

[Notação de conversão e introdução de safe_cast<>](../dotnet/cast-notation-and-introduction-of-safe-cast-angles.md)<br/>
Aborda as alterações para notação de conversão e, em particular a introdução de `safe_cast`.

## <a name="see-also"></a>Consulte também

[Primer de migração C++/CLI](../dotnet/cpp-cli-migration-primer.md)