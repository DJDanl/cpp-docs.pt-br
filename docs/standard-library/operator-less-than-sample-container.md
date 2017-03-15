---
title: operator&lt; (&lt;sample container&gt;) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::operator<
- operator<
- std.<
- <
- std.operator<
- std::<
dev_langs:
- C++
helpviewer_keywords:
- < operator, comparing specific objects
- operator<, valarrays
- < operator
- operator <, valarrays
ms.assetid: 31027dd6-53be-428b-b950-1dcb25393597
caps.latest.revision: 8
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
ms.openlocfilehash: 216f33d8d23b4d6c626961d1fb3ae98a0ea75c67
ms.lasthandoff: 02/25/2017

---
# <a name="operatorlt-ltsample-containergt"></a>operator&lt; (&lt;sample container&gt;)
> [!NOTE]
>  Este tópico faz parte da documentação do Visual C++ como um exemplo não funcional de contêineres usados na Biblioteca Padrão C++. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).  
  
 Sobrecarrega **operator<** para comparar dois objetos da classe de modelo [Container](../standard-library/sample-container-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
    template <class Ty>  
bool operator<(
    const Container <Ty>& left,  
    const Container <Ty>& right);
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna `lexicographical_compare`(_*Left*. [begin](../standard-library/container-class-begin.md), \_*Left*. [end](../standard-library/container-class-end.md), \_*Right***.begin**, \_*Right*.**end**).  
  
## <a name="see-also"></a>Consulte também  
 [\<sample container>](../standard-library/sample-container.md)


