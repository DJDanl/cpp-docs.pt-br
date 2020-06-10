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
ms.openlocfilehash: 907b34b12ffdaa70c4377a1012a66662fbba12d0
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619514"
---
# <a name="exception-classes"></a>Classes de exceção

A biblioteca de classes fornece um mecanismo de manipulação de exceção baseado na classe `CException` . A estrutura do aplicativo usa exceções em seu código; Você também pode usá-los no seu. Para obter mais informações, consulte o artigo [exceções](exception-handling-in-mfc.md). Você pode derivar seus próprios tipos de exceção do `CException` .

O MFC fornece uma classe de exceção da qual você pode derivar sua própria exceção, bem como classes de exceção para todas as exceções que ele suporta.

[CException](reference/cexception-class.md)<br/>
A classe base para as exceções.

[CArchiveException](reference/carchiveexception-class.md)<br/>
Uma exceção de arquivamento.

[CDaoException](reference/cdaoexception-class.md)<br/>
Uma exceção resultante de uma falha em uma operação de banco de dados DAO.

[CDBException](reference/cdbexception-class.md)<br/>
Uma exceção resultante de uma falha no processamento de banco de dados ODBC.

[CFileException](reference/cfileexception-class.md)<br/>
Uma exceção orientada por arquivo.

[CMemoryException](reference/cmemoryexception-class.md)<br/>
Uma exceção de memória insuficiente.

[CNotSupportedException](reference/cnotsupportedexception-class.md)<br/>
Uma exceção resultante do uso de um recurso sem suporte.

[COleException](reference/coleexception-class.md)<br/>
Uma exceção resultante de uma falha no processamento de OLE. Essa classe é usada por contêineres e servidores.

[COleDispatchException](reference/coledispatchexception-class.md)<br/>
Uma exceção resultante de um erro durante a automação. As exceções de automação são geradas por servidores de automação e detectadas por clientes de automação.

[CResourceException](reference/cresourceexception-class.md)<br/>
Uma exceção resultante de uma falha ao carregar um recurso do Windows.

[CUserException](reference/cuserexception-class.md)<br/>
Uma exceção usada para interromper uma operação iniciada pelo usuário. Normalmente, o usuário foi notificado do problema antes que essa exceção seja gerada.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
