---
title: CWinApp e o Assistente de aplicativo MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CWinApp
dev_langs:
- C++
helpviewer_keywords:
- application wizards [MFC], and CWinApp
- CWinApp class [MFC], and MFC Application Wizard
- MFC, wizards
ms.assetid: f8ac0491-3302-4e46-981d-0790624eb8a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d40f314c7717d2e69b2b4802bf9c2c5468511db5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33341255"
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

