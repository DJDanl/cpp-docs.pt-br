---
title: Classe CUserException | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CUserException
dev_langs:
- C++
helpviewer_keywords:
- operations [C++], stopping
- exceptions, throwing
- CUserException class
- errors [C++], trapping
- operations [C++]
- throwing exceptions, stopping user operations
ms.assetid: 2156ba6d-2cce-415a-9000-6f02c26fcd7d
caps.latest.revision: 23
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
translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: 8548ffa7ad9032e174d650e210a70a29b0e3f19d
ms.lasthandoff: 02/25/2017

---
# <a name="cuserexception-class"></a>Classe CUserException
Lançada para impedir que uma operação do usuário final.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CUserException : public CSimpleException  
```  
  
## <a name="remarks"></a>Comentários  
 Use `CUserException` quando você deseja usar o mecanismo de exceção throw/catch para exceções específicas do aplicativo. "Usuário" no nome da classe pode ser interpretado como "Meu usuário fez algo de que preciso manipular excepcional".  
  
 A `CUserException` geralmente é lançada após chamar a função global `AfxMessageBox` para notificar o usuário que uma operação falhou. Quando você escreve um manipulador de exceção, tratar a exceção, especialmente, desde que o usuário geralmente já foi notificado da falha. O framework lança essa exceção em alguns casos. Para lançar uma `CUserException` , alertar o usuário e, em seguida, chame a função global `AfxThrowUserException`.  
  
 No exemplo a seguir, uma função que contém operações que podem falhar alertará o usuário e lança um `CUserException`. A função de chamada captura a exceção e lida com isso especialmente:  
  
 [!code-cpp[NVC_MFCExceptions&#24;](../../mfc/codesnippet/cpp/cuserexception-class_1.cpp)]  
  
 Para obter mais informações sobre como usar o `CUserException`, consulte o artigo [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CException](../../mfc/reference/cexception-class.md)  
  
 [CSimpleException](../../mfc/reference/csimpleexception-class.md)  
  
 `CUserException`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CException](../../mfc/reference/cexception-class.md)

