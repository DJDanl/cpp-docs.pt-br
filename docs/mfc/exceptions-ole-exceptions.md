---
title: "Exceções: Exceções OLE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE, exceptions
- OLE exceptions [MFC]
- exceptions [MFC], OLE
- exception handling [MFC], OLE
- OLE exceptions [MFC], classes for handling
ms.assetid: 2f8e0161-b94f-48bb-a5a2-6f644b192527
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 67be1947b3fa08c26d659838922ce42a905167a7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exceptions-ole-exceptions"></a>Exceções: exceções OLE
As técnicas e recursos para tratamento de exceções em OLE são os mesmos para lidar com outras exceções. Para obter mais informações sobre o tratamento de exceções, consulte o artigo [manipulação de exceção C++](../cpp/cpp-exception-handling.md).  
  
 Todos os objetos de exceção são derivados da classe base abstrata `CException`. MFC fornece classes para tratamento de exceções OLE:  
  
-   [COleException](../mfc/reference/coleexception-class.md) para tratamento de exceções gerais de OLE.  
  
-   [COleDispatchException](../mfc/reference/coledispatchexception-class.md) para gerar e manipular OLE expedição exceções (automação).  
  
 A diferença entre essas duas classes é a quantidade de informações fornecem e onde eles são usados. `COleException`tem um membro de dados pública que contém o código de status OLE para a exceção. `COleDispatchException`fornece mais informações, incluindo o seguinte:  
  
-   Um código de erro específico do aplicativo  
  
-   Uma descrição do erro, como "Disco cheio"  
  
-   Um contexto de Ajuda que seu aplicativo pode usar para fornecer informações adicionais para o usuário  
  
-   O nome do arquivo de Ajuda do aplicativo  
  
-   O nome do aplicativo que gerou a exceção  
  
 `COleDispatchException`fornece mais informações para que ele pode ser usado com produtos como o Microsoft Visual Basic. A descrição textual do erro pode ser usada em uma caixa de mensagem ou outra notificação; as informações de Ajuda podem ser usadas para ajudar o usuário responder às condições que causou a exceção.  
  
 Duas funções globais correspondem às duas classes de exceção OLE: [AfxThrowOleException](../mfc/reference/exception-processing.md#afxthrowoleexception) e [AfxThrowOleDispatchException](../mfc/reference/exception-processing.md#afxthrowoledispatchexception). Usá-los para lançar exceções gerais de OLE e exceções de expedição OLE, respectivamente.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

