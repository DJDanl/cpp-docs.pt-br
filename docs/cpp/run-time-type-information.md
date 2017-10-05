---
title: "Informações de tipo de tempo de execução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: 'index-page '
dev_langs:
- C++
helpviewer_keywords:
- RTTI compiler option
- run-time type information
- run time, type checking
- type information, run-time type checking
- run-time checks, type checking
ms.assetid: becbd0e5-0439-4c61-854f-8a74f7160c54
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
ms.openlocfilehash: ec36acfdba274a0eaf36c099da11f4462f2aad70
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
