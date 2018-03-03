---
title: Usando CObject | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CObject
dev_langs:
- C++
helpviewer_keywords:
- examples [MFC], CObject
- root base class for MFC
- derived classes [MFC], from CObject
- MFC, base class
- CObject class [MFC]
ms.assetid: d0cd19bb-2856-4b41-abbc-620fd64cb223
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 17bffb412975cfc6a97eae8b30aff2514a2e1d93
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-cobject"></a>Usando CObject
[CObject](../mfc/reference/cobject-class.md) é a classe base raiz para a maioria da Microsoft Foundation Class Library (MFC). O `CObject` classe contém muitos recursos úteis que você pode incorporar em seus próprios objetos de programa, incluindo suporte a serialização, informações de classe de tempo de execução e saída de diagnóstico do objeto. Se você derivar a classe de `CObject`, sua classe pode explorar essas `CObject` recursos.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer  
  
-   [Derive uma classe de CObject](../mfc/deriving-a-class-from-cobject.md)  
  
-   [Adicionar suporte para serialização de informações de classe de tempo de execução e criação dinâmica a minha classe derivada](../mfc/specifying-levels-of-functionality.md)  
  
-   [Informações de classe de tempo de execução de acesso](../mfc/accessing-run-time-class-information.md)  
  
-   [Criar objetos dinamicamente](../mfc/dynamic-object-creation.md)  
  
-   [Despejar os dados do objeto para fins de diagnóstico](http://msdn.microsoft.com/en-us/727855b1-5a83-44bd-9fe3-f1d535584b59)  
  
-   Validar o estado do objeto interno (consulte [MFC ASSERT_VALID e CObject::AssertValid](http://msdn.microsoft.com/en-us/7654fb75-9e9a-499a-8165-0a96faf2d5e6))  
  
-   [Ter a classe serializar ele mesmo para o armazenamento persistente](../mfc/serialization-in-mfc.md)  
  
-   Consulte uma lista de [perguntas frequentes sobre o CObject](../mfc/cobject-class-frequently-asked-questions.md)  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Estrutura CRuntimeClass](../mfc/reference/cruntimeclass-structure.md)   
 [Arquivos](../mfc/files-in-mfc.md)   
 [Serialização](../mfc/serialization-in-mfc.md)

