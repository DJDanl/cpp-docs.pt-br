---
title: 'Hora atual: Classes de finalidade geral | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
helpviewer_keywords:
- time, setting current
- current time, CTime object
- procedures, getting current time
- initializing objects, with the current time
- time, getting current
ms.assetid: c39e6775-6a92-4b27-95a7-5c86ed371d8a
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a6c43ffd60d837bdd8f061057cf1c36340b6e6af
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="current-time-general-purpose-classes"></a>Hora atual: Classes de finalidade geral
O procedimento a seguir mostra como criar um `CTime` de objeto e inicializá-lo com a hora atual.  
  
#### <a name="to-get-the-current-time"></a>Para obter a hora atual  
  
1.  Alocar um `CTime` do objeto, da seguinte maneira:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#171](../atl-mfc-shared/codesnippet/cpp/current-time-general-purpose-classes_1.cpp)]  
  
    > [!NOTE]
    >  Não inicializado `CTime` objetos não são inicializados para uma hora válida.  
  
2.  Chamar o `CTime::GetCurrentTime` função para obter a hora atual do sistema operacional. Essa função retorna um `CTime` objeto que pode ser usado para definir o valor de `CTime`, da seguinte maneira:  
  
     [!code-cpp[NVC_ATLMFC_Utilities#172](../atl-mfc-shared/codesnippet/cpp/current-time-general-purpose-classes_2.cpp)]  
  
     Como `GetCurrentTime` é uma função de membro estático do `CTime` classe, você deve qualificar o nome com o nome da classe e o operador de resolução do escopo (`::`), `CTime::GetCurrentTime()`.  
  
 Obviamente, as duas etapas descritas anteriormente podem ser combinadas em uma única instrução de programa da seguinte maneira:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#173](../atl-mfc-shared/codesnippet/cpp/current-time-general-purpose-classes_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Data e hora: classes de uso geral](../atl-mfc-shared/date-and-time-general-purpose-classes.md)



