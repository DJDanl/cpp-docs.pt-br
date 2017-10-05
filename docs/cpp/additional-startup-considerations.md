---
title: "Considerações de inicialização adicionais | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- program startup [C++]
- startup code
- initializing before main
ms.assetid: 0e942aa6-8342-447c-b068-8980ed7622bd
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: cb437729d2c60f15bc798438ecbbba0637bf3d22
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
 [Início e término](../cpp/startup-and-termination-cpp.md)
