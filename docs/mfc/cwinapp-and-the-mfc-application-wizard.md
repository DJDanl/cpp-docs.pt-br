---
title: CWinApp e o Assistente de aplicativo MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CWinApp
dev_langs: C++
helpviewer_keywords:
- application wizards [MFC], and CWinApp
- CWinApp class [MFC], and MFC Application Wizard
- MFC, wizards
ms.assetid: f8ac0491-3302-4e46-981d-0790624eb8a2
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 603504025bf4069f7a56b705e50a176975dbf244
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cwinapp-and-the-mfc-application-wizard"></a>CWinApp e o Assistente de Aplicativo MFC
Quando ele cria um aplicativo de esqueleto, o Assistente de aplicativo MFC declara um aplicativo de classe derivada de [CWinApp](../mfc/reference/cwinapp-class.md). O Assistente de aplicativo MFC também gera um arquivo de implementação que contém os seguintes itens:  
  
-   Um mapa de mensagem para a classe do aplicativo.  
  
-   Um construtor de classe vazia.  
  
-   Uma variável que declara um e apenas o objeto da classe.  
  
-   Uma implementação padrão de seu `InitInstance` função de membro.  
  
 A classe do aplicativo é colocada no cabeçalho do projeto e arquivos de origem principal. Os nomes da classe e os arquivos criados são baseados no nome do projeto que você fornece no Assistente de aplicativo MFC. É a maneira mais fácil de exibir o código para essas classes por meio de [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925).  
  
 O mapa de mensagem fornecida e implementações padrão são adequadas para muitos propósitos, mas você pode modificá-los conforme necessário. É mais interessante dessas implementações de `InitInstance` função de membro. Normalmente, você adicionará um código para a implementação do esqueleto de `InitInstance`.  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: A classe do aplicativo](../mfc/cwinapp-the-application-class.md)   
 [Funções de membro CWinApp substituíveis](../mfc/overridable-cwinapp-member-functions.md)   
 [Serviços CWinApp especiais](../mfc/special-cwinapp-services.md)

