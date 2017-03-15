---
title: "Contêiner Class::erase | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- erase method
ms.assetid: abc091c5-5a80-4bd8-93a8-a2d9bde2efec
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
ms.openlocfilehash: 0a28e1ff0def707926a67e1fea77f40e9927c0c4
ms.lasthandoff: 02/25/2017

---
# <a name="container-classerase"></a>Classe de Contêiner::erase
> [!NOTE]
>  Este tópico faz parte da documentação do Visual C++ como um exemplo não funcional de contêineres usados na Biblioteca Padrão C++. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).  
  
 Apaga um elemento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
    iterator erase(
    iterator _Where);

iterator erase(
    iterator first,  
    iterator last);
```  
  
## <a name="remarks"></a>Comentários  
 A primeira função de membro remove o elemento da sequência controlada apontada por _*Where***.** A segunda função de membro remove os elementos da sequência controlada no intervalo [` first`, ` last`). As duas retornarão um iterador que designa o primeiro elemento restante além de todos os elementos removidos ou [end](../standard-library/container-class-end.md) se esse elemento não existir.  
  
 As funções de membro gerarão uma exceção apenas se uma operação de cópia gerar uma exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Classe de contêiner de amostra](../standard-library/sample-container-class.md)

