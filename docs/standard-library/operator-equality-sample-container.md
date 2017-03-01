---
title: operator== (&lt;sample container&gt;) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std.==
- std::==
- operator==
- std.operator==
- std::operator==
- ==
dev_langs:
- C++
helpviewer_keywords:
- operator ==, containers
- operator==, containers
- == operator, with specific standard C++ objects
ms.assetid: d3d8754e-5157-4b8b-bf9c-da41856f5eed
caps.latest.revision: 9
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: e76968b910684d7f8bcb4dd85ae583b81dde5bd3
ms.lasthandoff: 02/25/2017

---
# <a name="operator-ltsample-containergt"></a>operator== (&lt;sample container&gt;)
> [!NOTE]
>  Este tópico faz parte da documentação do Visual C++ como um exemplo não funcional de contêineres usados na Biblioteca Padrão C++. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).  
  
 Sobrecarrega `operator==` para comparar dois objetos da classe de modelo [Container](../standard-library/sample-container-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
    template <class Ty>  
bool operator==(
    const Container <Ty>& left,  
    const Container <Ty>& right);
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna ` left`**.**[size](../standard-library/container-class-size.md) **==** ` right`**.size && equal**(_*Left***.**[begin](../standard-library/container-class-begin.md), ` left`. [end](../standard-library/container-class-end.md)*,  right***.begin**).  
  
## <a name="see-also"></a>Consulte também  
 [\<sample container>](../standard-library/sample-container.md)


