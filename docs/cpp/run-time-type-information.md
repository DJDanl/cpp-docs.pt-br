---
title: "Informações de tipo de tempo de execução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: 'index-page '
dev_langs: C++
helpviewer_keywords:
- RTTI compiler option
- run-time type information
- run time, type checking
- type information, run-time type checking
- run-time checks, type checking
ms.assetid: becbd0e5-0439-4c61-854f-8a74f7160c54
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4fb5f7413f613aab2d02ee2548a460adfca57b90
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="run-time-type-information"></a>Informações de tipo de tempo de execução
As informações de tipo em tempo de execução (RTTI) são um mecanismo que permite que o tipo de um objeto seja determinado durante a execução do programa. A RTTI foi adicionada à linguagem C++ porque muitos fornecedores de bibliotecas de classes implementavam essa funcionalidade de maneira independente. Isso causou incompatibilidades entre as bibliotecas. Assim, ficou claro que era necessário o suporte a informações de tipo em tempo de execução no nível da linguagem.  
  
 Para uma questão de clareza, esta discussão sobre a RTTI é quase que totalmente restrita a ponteiros. No entanto, os conceitos abordados também se aplicam a referências.  
  
 Há três principais elementos de linguagem C++ para as informações de tipo em tempo de execução:  
  
-   O [dynamic_cast](../cpp/dynamic-cast-operator.md) operador.  
  
     Usado para a conversão de tipos polimorfos.  
  
-   O [typeid](../cpp/typeid-operator.md) operador.  
  
     Usado para identificar o tipo exato de um objeto.  
  
-   O [type_info](../cpp/type-info-class.md) classe.  
  
     Usada para manter as informações de tipo retornadas pelo operador `typeid`.  
  
## <a name="see-also"></a>Consulte também  
 [Conversão](../cpp/casting.md)