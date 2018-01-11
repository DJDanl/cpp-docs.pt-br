---
title: Classe time_base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: locale/std::time_base
dev_langs: C++
helpviewer_keywords: time_base class
ms.assetid: 9ae37f0b-9a42-496e-9870-3d9b71bab8fb
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8a91d10a1705e14663443c1471397478aad85b68
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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



