---
title: 'Exceções: exceções OLE'
ms.date: 11/04/2016
helpviewer_keywords:
- OLE, exceptions
- OLE exceptions [MFC]
- exceptions [MFC], OLE
- exception handling [MFC], OLE
- OLE exceptions [MFC], classes for handling
ms.assetid: 2f8e0161-b94f-48bb-a5a2-6f644b192527
ms.openlocfilehash: 1606a0f5a86996345e12024cf6416afdf6bdc82b
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246703"
---
# <a name="exceptions-ole-exceptions"></a>Exceções: exceções OLE

As técnicas e os recursos para lidar com exceções no OLE são os mesmos para lidar com outras exceções. Para obter mais informações sobre a manipulação de exceções, consulte o artigo [práticas recomendadas modernas C++ para exceções e tratamento de erros](../cpp/errors-and-exception-handling-modern-cpp.md).

Todos os objetos de exceção são derivados da classe base abstrata `CException`. O MFC fornece duas classes para lidar com exceções OLE:

- [COleException](../mfc/reference/coleexception-class.md) Para lidar com exceções gerais de OLE.

- [COleDispatchException](../mfc/reference/coledispatchexception-class.md) Para gerar e tratar exceções de despacho OLE (automação).

A diferença entre essas duas classes é a quantidade de informações que elas fornecem e onde elas são usadas. `COleException` tem um membro de dados públicos que contém o código de status OLE para a exceção. `COleDispatchException` fornece mais informações, incluindo o seguinte:

- Um código de erro específico do aplicativo

- Uma descrição de erro, como "disco cheio"

- Um contexto de ajuda que seu aplicativo pode usar para fornecer informações adicionais para o usuário

- O nome do arquivo de ajuda do seu aplicativo

- O nome do aplicativo que gerou a exceção

`COleDispatchException` fornece mais informações para que ele possa ser usado com produtos como o Microsoft Visual Basic. A descrição do erro textual pode ser usada em uma caixa de mensagem ou outra notificação; as informações de ajuda podem ser usadas para ajudar o usuário a responder às condições que causaram a exceção.

Duas funções globais correspondem às duas classes de exceção OLE: [AfxThrowOleException](../mfc/reference/exception-processing.md#afxthrowoleexception) e [AfxThrowOleDispatchException](../mfc/reference/exception-processing.md#afxthrowoledispatchexception). Use-os para gerar exceções gerais de OLE e exceções de expedição de OLE, respectivamente.

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
