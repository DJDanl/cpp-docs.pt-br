---
title: "Inicializando e limpando documentos e exibições | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- initializing documents [MFC]
- views [MFC], cleaning up
- documents [MFC], initializing
- documents [MFC], cleaning up
- views [MFC], initializing
- initializing objects [MFC], document objects
- document objects [MFC], life cycle of
- initializing views [MFC]
ms.assetid: 95d6f09b-a047-4079-856a-ae7d0548e9d2
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0546bfc0a5226c6cd22497acae1bb364ceba107b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="initializing-and-cleaning-up-documents-and-views"></a>Inicializando e limpando documentos e exibições
Use as diretrizes a seguir para inicializar e limpeza após seus documentos e exibições:  
  
-   A estrutura MFC inicializa documentos e exibições; você inicializar quaisquer dados que você adicionar a eles.  
  
-   A estrutura limpa como documentos e exibições fechar; toda a memória alocada no heap de dentro das funções de membro desses documentos e modos de exibição deve ser desalocada.  
  
> [!NOTE]
>  Lembre-se de que a inicialização para o aplicativo inteiro é melhor executado em sua substituição do [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) função de membro de classe `CWinApp`, e a limpeza para o aplicativo inteiro é melhor executada em sua substituição da `CWinApp`função de membro [ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance).  
  
 O ciclo de vida de um documento (e sua janela do quadro e modo de exibição ou exibições) em um MDI aplicativo é o seguinte:  
  
1.  Durante a criação dinâmica, o construtor de documento é chamado.  
  
2.  Para do cada novo documento, o documento [OnNewDocument](../mfc/reference/cdocument-class.md#onnewdocument) ou [OnOpenDocument](../mfc/reference/cdocument-class.md#onopendocument) é chamado.  
  
3.  O usuário interage com o documento durante seu tempo de vida. Normalmente, isso acontece, o usuário trabalha em dados de documentos por meio da exibição, selecionar e editar os dados. O modo de exibição passa as alterações para o documento para armazenamento e atualização de outros modos de exibição. Durante esse tempo, o documento e o modo de exibição podem tratar de comandos.  
  
4.  A estrutura chama [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) para excluir dados específicos a um documento.  
  
5.  Destruidor do documento é chamado.  
  
 Em um aplicativo SDI, etapa 1 é executada uma vez, quando o documento é criado pela primeira vez. Em seguida, as etapas 2 a 4 são executadas várias vezes sempre que um novo documento for aberto. O novo documento reutiliza o objeto de documento existente. Por fim, a etapa 5 é executada quando o aplicativo termina.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Inicializando documentos e exibições](../mfc/initializing-documents-and-views.md)  
  
-   [Limpando documentos e exibições](../mfc/cleaning-up-documents-and-views.md)  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

