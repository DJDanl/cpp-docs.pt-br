---
title: Classes de exceção
ms.date: 11/04/2016
f1_keywords:
- vc.classes.exception
helpviewer_keywords:
- exception classes [MFC]
- exception handling [MFC], exception classes
- MFC, exceptions
ms.assetid: 1a2caf12-b3e9-4189-86d2-bf7a595bf025
ms.openlocfilehash: 99a2764dcad15267b1aab8a60951f99f21352726
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57286316"
---
# <a name="exception-classes"></a>Classes de exceção

A biblioteca de classes fornece um mecanismo de tratamento de exceções com base na classe `CException`. A estrutura de aplicativo usa as exceções em seu código; Você também pode usá-los na sua. Para obter mais informações, consulte o artigo [exceções](../mfc/exception-handling-in-mfc.md). Você pode derivar seus próprios tipos de exceção de `CException`.

MFC fornece uma classe de exceção dos quais você pode derivar sua própria exceção, bem como classes de exceção para todas as exceções que ele suporta.

[CException](../mfc/reference/cexception-class.md)<br/>
A classe base para as exceções.

[CArchiveException](../mfc/reference/carchiveexception-class.md)<br/>
Uma exceção de arquivo morto.

[CDaoException](../mfc/reference/cdaoexception-class.md)<br/>
Uma exceção resultante de uma falha em uma operação de banco de dados DAO.

[CDBException](../mfc/reference/cdbexception-class.md)<br/>
Uma exceção resultante de uma falha no processamento do banco de dados ODBC.

[CFileException](../mfc/reference/cfileexception-class.md)<br/>
Uma exceção orientado a arquivos.

[CMemoryException](../mfc/reference/cmemoryexception-class.md)<br/>
Uma exceção de falta de memória.

[CNotSupportedException](../mfc/reference/cnotsupportedexception-class.md)<br/>
Uma exceção resultantes do uso de um recurso sem suporte.

[COleException](../mfc/reference/coleexception-class.md)<br/>
Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.

[COleDispatchException](../mfc/reference/coledispatchexception-class.md)<br/>
Uma exceção resultante de um erro durante a automação. Exceções de automação são geradas por servidores de automação e capturadas por clientes de automação.

[CResourceException](../mfc/reference/cresourceexception-class.md)<br/>
Uma exceção resultante de uma falha ao carregar um recurso do Windows.

[CUserException](../mfc/reference/cuserexception-class.md)<br/>
Uma exceção usada para parar uma operação iniciada pelo usuário. Normalmente, o usuário foi notificado do problema antes que essa exceção é lançada.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
