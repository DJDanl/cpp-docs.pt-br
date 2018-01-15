---
title: Classe CUserException | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: CUserException
dev_langs: C++
helpviewer_keywords:
- operations [MFC], stopping
- exceptions [MFC], throwing
- CUserException class [MFC]
- errors [MFC], trapping
- operations [MFC]
- throwing exceptions [MFC], stopping user operations
ms.assetid: 2156ba6d-2cce-415a-9000-6f02c26fcd7d
caps.latest.revision: "23"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4613f2ba06ffa697df219172b98a5cf193c1f3b2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cuserexception-class"></a>Classe CUserException
Gerada para interromper uma operação do usuário final.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CUserException : public CSimpleException  
```  
  
## <a name="remarks"></a>Comentários  
 Use `CUserException` quando você deseja usar o mecanismo de exceção throw/catch para exceções específicas do aplicativo. "Usuário" no nome da classe pode ser interpretado como "Meu usuário fez algo excepcional que preciso tratar."  
  
 Um `CUserException` geralmente é lançada após chamar a função global `AfxMessageBox` para notificar o usuário que houve falha na operação. Quando você escreve um manipulador de exceção, lidar com a exceção, especialmente, desde que o usuário geralmente já foi notificado da falha. A estrutura gera essa exceção em alguns casos. Para lançar uma `CUserException` por conta própria, alertar o usuário e, em seguida, chame a função global `AfxThrowUserException`.  
  
 No exemplo a seguir, uma função que contém operações que podem falhar alerta o usuário e lança um `CUserException`. A função de chamada captura a exceção e manipule especialmente:  
  
 [!code-cpp[NVC_MFCExceptions#24](../../mfc/codesnippet/cpp/cuserexception-class_1.cpp)]  
  
 Para obter mais informações sobre como usar `CUserException`, consulte o artigo [de tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CUserException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)
