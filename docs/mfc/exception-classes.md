---
title: Classes de exceção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.exception
dev_langs:
- C++
helpviewer_keywords:
- exception classes [MFC]
- exception handling [MFC], exception classes
- MFC, exceptions
ms.assetid: 1a2caf12-b3e9-4189-86d2-bf7a595bf025
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8ce4085d0f5f2dcc73d126d04b7560ef8360ffd9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="exception-classes"></a>Classes de exceção
A biblioteca de classe fornece um mecanismo de tratamento de exceção com base na classe `CException`. A estrutura de aplicativo usa exceções em seu código; Você também pode usá-los nas suas. Para obter mais informações, consulte o artigo [exceções](../mfc/exception-handling-in-mfc.md). Você pode derivar seus próprios tipos de exceção de `CException`.  
  
 MFC fornece uma classe de exceção dos quais você pode derivar seu próprio exceção, bem como classes de exceção para todas as exceções que ele suporta.  
  
 [CException](../mfc/reference/cexception-class.md)  
 A classe base para as exceções.  
  
 [CArchiveException](../mfc/reference/carchiveexception-class.md)  
 Uma exceção de arquivo morto.  
  
 [CDaoException](../mfc/reference/cdaoexception-class.md)  
 Uma exceção resultante de uma falha em uma operação de banco de dados DAO.  
  
 [CDBException](../mfc/reference/cdbexception-class.md)  
 Uma exceção resultante de uma falha no processamento do banco de dados ODBC.  
  
 [CFileException](../mfc/reference/cfileexception-class.md)  
 Uma exceção orientados a arquivos.  
  
 [CMemoryException](../mfc/reference/cmemoryexception-class.md)  
 Uma exceção de falta de memória.  
  
 [CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md)  
 Uma exceção resultante do uso de um recurso sem suporte.  
  
 [COleException](../mfc/reference/coleexception-class.md)  
 Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.  
  
 [COleDispatchException](../mfc/reference/coledispatchexception-class.md)  
 Uma exceção resultantes de um erro durante a automação. Exceções de automação são lançadas por servidores de automação e capturadas por clientes de automação.  
  
 [CResourceException](../mfc/reference/cresourceexception-class.md)  
 Uma exceção resultante de uma falha ao carregar um recurso do Windows.  
  
 [CUserException](../mfc/reference/cuserexception-class.md)  
 Uma exceção usada para parar uma operação iniciada pelo usuário. Normalmente, o usuário foi notificado sobre o problema antes que essa exceção é gerada.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

