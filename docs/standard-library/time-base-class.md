---
title: Classe time_base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- locale/std::time_base
dev_langs:
- C++
helpviewer_keywords:
- time_base class
ms.assetid: 9ae37f0b-9a42-496e-9870-3d9b71bab8fb
caps.latest.revision: 19
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: c1c7c6c708087827c853234dcbd4519c79fba2bf
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="timebase-class"></a>Classe time_base
A classe serve como uma classe base para facetas da classe de modelo time_get, definindo apenas o tipo enumerado **dateorder** e várias constantes desse tipo.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class time_base : public locale::facet {
public:
    enum dateorder {no_order,
    dmy,
 mdy,
    ymd,
 ydm};
    time_base(
 size_t _Refs = 0)
 ~time_base();

};
```  
  
## <a name="remarks"></a>Comentários  
 Cada constante caracteriza uma maneira diferente de ordenar os componentes de uma data. As constantes são:  
  
- **no_order** não especifica nenhuma ordem específica.  
  
- **dmy** especifica a ordem dia, mês e ano, como em 2 de dezembro de 1979.  
  
- **mdy** especifica a ordem mês, dia e ano, como em dezembro 2 de 1979.  
  
- **ymd** especifica a ordem ano, mês e dia, como em 1979/12/2.  
  
- **ydm** especifica a ordem ano, dia e mês, como em 1979: 2 de dezembro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




