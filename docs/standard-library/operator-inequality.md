---
title: operator!= | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::!=
- '!='
- std::operator!=
- std.operator!=
- std.!=
- operator!=
dev_langs:
- C++
helpviewer_keywords:
- '!= operator'
- operator!=
- operator !=
ms.assetid: ef2be7f0-1c94-4edc-b65c-731fddd519f4
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 327cf7f1b8e2e9ad088dd553b96e403650f7182b
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="operator"></a>operator!=
> [!NOTE]
>  Este tópico faz parte da documentação do Visual C++ como um exemplo não funcional de contêineres usados na Biblioteca Padrão C++. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).  
  
 Sobrecarrega `operator!=` para comparar dois objetos da classe de modelo [Container](../standard-library/sample-container-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Ty>  
bool operator!=(
    const Container <Ty>& left,  
    const Container <Ty>& right);
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna `!(left == right)`.  
  
## <a name="see-also"></a>Consulte também  
 [\<sample container>](../standard-library/sample-container.md)


