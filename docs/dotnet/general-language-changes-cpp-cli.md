---
title: Alterações gerais em linguagens (C + + CLI) | Microsoft Docs
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
ms.openlocfilehash: aede6cc0d4bd8e50d8662f301ffdfb7b6179a230
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33109132"
---
# <a name="general-language-changes-ccli"></a>Alterações gerais em linguagens (C++/CLI)
Um número de recursos de linguagem CLR alterado de extensões gerenciadas para C++ para Visual C++.  
  
 As alterações descritas nesta seção são um tipo de miscellany de idioma. Ele inclui uma alteração na manipulação de literais de cadeia de caracteres, uma alteração na resolução de sobrecarga entre um botão de reticências e `Param` atributo, a alteração de `typeof` para `typeid`, uma alteração na chamada de listas de inicializadores de construtor e o Introdução de uma nova notação de conversão de `safe_cast`.  
  
 [Literal da cadeia de caracteres](../dotnet/string-literal.md)  
 Discute como a manipulação de cadeias de caracteres literais foi alterado.  
  
 [Matriz de parâmetros e reticências](../dotnet/param-array-and-ellipsis.md)  
 Discute como `ParamArray` agora tem precedência sobre as reticências (`...`) para resolver as chamadas de função diferentes com um número de argumentos.  
  
 [typeof torna-se T::typeid](../dotnet/typeof-goes-to-t-typeid.md)  
 Discute como o `typeof` operador tem sido suplantado por `typeid`.  
  
 [Listas de inicializadores](../dotnet/initializer-lists.md)  
 Aborda as alterações na ordem de listas de inicializadores a chamada.  
  
 [Notação de conversão e introdução de safe_cast<>](../dotnet/cast-notation-and-introduction-of-safe-cast-angles.md)  
 Aborda as alterações a notação de conversão e, em particular a introdução de `safe_cast`.  
  
## <a name="see-also"></a>Consulte também  
 [Primer de migração C++/CLI](../dotnet/cpp-cli-migration-primer.md)