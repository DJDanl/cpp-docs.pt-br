---
title: Usando o controle RichEdit 1.0 com MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- RichEdit 1.0 control
- rich edit controls, RichEdit 1.0
ms.assetid: 5a9060dd-44d8-4ef3-956e-16152f7e23d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a00642c1aefdce57c37723ef4daf23381cee3c13
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39650742"
---
# <a name="using-the-richedit-10-control-with-mfc"></a>Usando o controle RichEdit 1.0 com MFC
Para usar um controle RichEdit, você deve primeiro chamar [AfxInitRichEdit2](../mfc/reference/application-information-and-management.md#afxinitrichedit2) para carregar o controle RichEdit 2.0 (RICHED20. DLL), ou chamar [AfxInitRichEdit](../mfc/reference/application-information-and-management.md#afxinitrichedit) para carregar o controle de 1.0 RichEdit mais antigos (RICHED32. DLL).  
  
 Você pode usar o atual [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md) classe com o controle RichEdit 1.0 mais antigo, mas `CRichEditCtrl` foi projetado apenas para dar suporte ao controle RichEdit 2.0. A maioria dos métodos funcionará como RichEdit 1.0 e 2.0 de RichEdit são muito semelhantes, No entanto, observe que há algumas diferenças entre os controles de 1.0 e 2.0, portanto, alguns métodos podem funcionar incorretamente ou não funcionar em todos os.  
  
## <a name="requirements"></a>Requisitos  
 MFC  
  
## <a name="see-also"></a>Consulte também  
 [O Editor de caixa de diálogo de solução de problemas](../windows/troubleshooting-the-dialog-editor.md)   
 [Editor de caixa de diálogo](../windows/dialog-editor.md)