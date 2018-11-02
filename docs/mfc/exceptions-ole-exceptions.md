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
ms.openlocfilehash: 2732f571d305fda2b739be02661ab9558f8bc653
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515405"
---
# <a name="exceptions-ole-exceptions"></a>Exceções: exceções OLE

As técnicas e recursos para tratamento de exceções em OLE são os mesmos para lidar com outras exceções. Para obter mais informações sobre a manipulação de exceção, consulte o artigo [tratamento de exceções de C++](../cpp/cpp-exception-handling.md).

Todos os objetos de exceção são derivados da classe base abstrata `CException`. MFC fornece classes para tratamento de exceções OLE:

- [COleException](../mfc/reference/coleexception-class.md) para tratamento de exceções gerais do OLE.

- [COleDispatchException](../mfc/reference/coledispatchexception-class.md) para gerando e manipulando OLE expedir exceções (automação).

A diferença entre essas duas classes é a quantidade de informações que eles fornecem e onde eles são usados. `COleException` tem um membro de dados públicos que contém o código de status OLE para a exceção. `COleDispatchException` fornece mais informações, incluindo o seguinte:

- Um código de erro específicas do aplicativo

- Uma descrição de erro, como "Disco cheio"

- Um contexto de Ajuda que seu aplicativo pode usar para fornecer informações adicionais para o usuário

- O nome do arquivo de Ajuda do seu aplicativo

- O nome do aplicativo que gerou a exceção

`COleDispatchException` fornece mais informações para que ele pode ser usado com os produtos, como o Microsoft Visual Basic. A descrição textual do erro pode ser usada em uma caixa de mensagem ou outra notificação; as informações de Ajuda podem ser usadas para ajudar o usuário responder às condições que causou a exceção.

Duas funções globais correspondem às duas classes de exceção de OLE: [AfxThrowOleException](../mfc/reference/exception-processing.md#afxthrowoleexception) e [AfxThrowOleDispatchException](../mfc/reference/exception-processing.md#afxthrowoledispatchexception). Usá-los para lançar exceções gerais de OLE e exceções de expedição OLE, respectivamente.

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

