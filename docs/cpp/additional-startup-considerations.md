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
ms.openlocfilehash: c05ce0fa1a80de8f5ab8b9335bbab22628f3f158
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="additional-startup-considerations"></a>Considerações de inicialização adicionais
Em C++, a construção e destruição do objeto podem envolver a execução do código do usuário. Portanto, é importante entender quais inicializações acontecem antes de entrada para **principal** e quais destruidores são chamados após a saída do **principal**. (Para obter informações detalhadas sobre a construção e destruição de objetos, consulte [construtores](../cpp/constructors-cpp.md) e [destruidores](../cpp/destructors-cpp.md).)  
  
 As seguintes inicializações ocorram antes da entrada para **principal**:  
  
-   Inicialização padrão de dados estáticos em zero. Todos os dados estáticos sem inicializadores explícitos são definidos como zero antes de executar qualquer outro código, inclusive a inicialização no tempo de execução. Os membros de dados static ainda devem ser explicitamente definidos.  
  
-   Inicialização de objetos globais estáticos em uma unidade de conversão. Isso pode ocorrer antes da entrada para **principal** ou antes do primeiro uso de qualquer função ou o objeto na unidade de tradução do objeto.  
  
 **Seção específica da Microsoft**  
  
 No Microsoft C++ global objetos estáticos são inicializados antes da entrada para **principal**.  
  
 **Fim da seção específica da Microsoft**  
  
 Os objetos globais estáticos que são mutuamente interdependentes, mas em diferentes unidades de conversão, podem provocar comportamento incorreto.  
  
## <a name="see-also"></a>Consulte também  
 [Inicialização e término](../cpp/startup-and-termination-cpp.md)