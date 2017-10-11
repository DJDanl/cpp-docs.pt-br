---
title: operator!= | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 6549656d90a95281cd07de2f4675e53ecf3871f0
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

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


