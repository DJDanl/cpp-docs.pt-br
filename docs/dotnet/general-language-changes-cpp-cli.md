---
title: "Alterações gerais em linguagens (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 79a70768-225c-4ae2-84d1-178b20a9b042
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 87ff7f55b67c4e8a84d15099432962ee0939d13a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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