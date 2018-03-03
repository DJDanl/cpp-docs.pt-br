---
title: 'Arrastar e soltar: Personalizando | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- drag and drop [MFC], implementing in non-OLE applications
- drag and drop [MFC], customizing behavior
- drag and  [MFC], COleDataSource object
- drag and drop [MFC], calling DoDragDrop
- OLE drag and drop [MFC], customizing behavior
ms.assetid: 03369d3e-46bf-4140-b58c-d0c9657cf38a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 387344160cf2009b19ad8de820eabc6063ae1f7c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="drag-and-drop-customizing"></a>Arrastar e soltar: personalizando
A implementação padrão do recurso de arrastar e soltar é suficiente para a maioria dos aplicativos. No entanto, alguns aplicativos podem exigir que esse comportamento padrão seja alterado. Este artigo explica as etapas necessárias para alterar esses padrões. Além disso, você pode usar esta técnica para estabelecer os aplicativos que não dão suporte a documentos compostos como remover fontes.  
  
 Se você estiver personalizando o comportamento padrão de arrastar e soltar OLE, ou você tiver um aplicativo OLE não, você deve criar um `COleDataSource` objeto para conter os dados. Quando o usuário inicia uma operação de arrastar e soltar, seu código deve chamar o `DoDragDrop` função deste objeto, em vez de outras classes que oferecem suporte a operações de arrastar e soltar.  
  
 Opcionalmente, você pode criar um `COleDropSource` objeto para controlar o posicionamento e substituir algumas das suas funções dependendo do tipo de comportamento que você deseja alterar. Esse objeto de origem de soltar é então passado para `COleDataSource::DoDragDrop` para alterar o comportamento padrão dessas funções. Essas opções diferentes permitem um grande flexibilidade em como dar suporte a operações de arrastar e soltar em seu aplicativo. Para obter mais informações sobre fontes de dados, consulte o artigo [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md).  
  
 Você pode substituir as funções a seguir para personalizar as operações de arrastar e soltar:  
  
|Substituições|Para personalizar|  
|--------------|------------------|  
|`OnBeginDrag`|Como arrastar é iniciado depois de chamar `DoDragDrop`.|  
|`GiveFeedback`|Comentários visuais, como a aparência do cursor, para resultados de destino diferente.|  
|`QueryContinueDrag`|O encerramento de uma operação de arrastar e soltar. Esta função permite que você verifique os estados de chave de modificador durante a operação de arrastar.|  
  
## <a name="see-also"></a>Consulte também  
 [Arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md)   
 [Classe COleDropSource](../mfc/reference/coledropsource-class.md)   
 [Classe COleDataSource](../mfc/reference/coledatasource-class.md)
