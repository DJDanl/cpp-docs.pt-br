---
title: Considerações de inicialização adicionais | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- program startup [C++]
- startup code
- initializing before main
ms.assetid: 0e942aa6-8342-447c-b068-8980ed7622bd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c23f18a04010ba62d3651344464ff1668b2127d9
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405065"
---
# <a name="additional-startup-considerations"></a>Considerações de inicialização adicionais
Em C++, a construção e destruição do objeto podem envolver a execução do código do usuário. Portanto, é importante entender que inicializações acontecem antes da entrada em `main` e que destruidores são invocados depois da saída de `main`. (Para obter informações detalhadas sobre a construção e destruição de objetos, consulte [construtores](../cpp/constructors-cpp.md) e [destruidores](../cpp/destructors-cpp.md).)  
  
 As seguintes inicializações ocorrem antes da entrada `main`:  
  
-   Inicialização padrão de dados estáticos em zero. Todos os dados estáticos sem inicializadores explícitos são definidos como zero antes de executar qualquer outro código, inclusive a inicialização no tempo de execução. Os membros de dados static ainda devem ser explicitamente definidos.  
  
-   Inicialização de objetos globais estáticos em uma unidade de conversão. Isso pode ocorrer antes da entrada para `main` ou antes do primeiro uso de qualquer função ou um objeto na unidade de tradução do objeto.  
  
 **Seção específica da Microsoft**  
  
 No Microsoft C++, objetos globais estáticos são inicializados antes da entrada em `main`.  
  
 **Fim da seção específica da Microsoft**  
  
 Os objetos globais estáticos que são mutuamente interdependentes, mas em diferentes unidades de conversão, podem provocar comportamento incorreto.  
  
## <a name="see-also"></a>Consulte também  
 [Inicialização e término](../cpp/startup-and-termination-cpp.md)