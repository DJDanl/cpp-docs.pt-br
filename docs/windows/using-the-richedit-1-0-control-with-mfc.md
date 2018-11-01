---
title: Usando o controle RichEdit 1.0 com MFC
ms.date: 11/04/2016
helpviewer_keywords:
- RichEdit 1.0 control
- rich edit controls [C++], RichEdit 1.0
ms.assetid: 5a9060dd-44d8-4ef3-956e-16152f7e23d2
ms.openlocfilehash: 080ad995b9c7a041337d9b296d6ef8906e7f20ec
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50468309"
---
# <a name="using-the-richedit-10-control-with-mfc"></a>Usando o controle RichEdit 1.0 com MFC

Para usar um controle RichEdit, você deve primeiro chamar [AfxInitRichEdit2](../mfc/reference/application-information-and-management.md#afxinitrichedit2) para carregar o controle RichEdit 2.0 (RICHED20. DLL), ou chamar [AfxInitRichEdit](../mfc/reference/application-information-and-management.md#afxinitrichedit) para carregar o controle de 1.0 RichEdit mais antigos (RICHED32. DLL).

Você pode usar o atual [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md) classe com o controle RichEdit 1.0 mais antigo, mas `CRichEditCtrl` foi projetado apenas para dar suporte ao controle RichEdit 2.0. A maioria dos métodos funcionará como RichEdit 1.0 e 2.0 de RichEdit são muito semelhantes, No entanto, observe que há algumas diferenças entre os controles de 1.0 e 2.0, portanto, alguns métodos podem funcionar incorretamente ou não funcionar em todos os.

## <a name="requirements"></a>Requisitos

MFC

## <a name="see-also"></a>Consulte também

[Solução de problemas do Editor de Caixa de Diálogo](../windows/troubleshooting-the-dialog-editor.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)