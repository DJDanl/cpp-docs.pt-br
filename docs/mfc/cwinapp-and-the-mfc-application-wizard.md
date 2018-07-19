---
title: CWinApp e o Assistente de aplicativo do MFC | Microsoft Docs
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
ms.openlocfilehash: 702c20fc9f303670d2add4ebf840785acff7750d
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39026479"
---
# <a name="cwinapp-and-the-mfc-application-wizard"></a>CWinApp e o Assistente de Aplicativo MFC
Quando ele cria um aplicativo de esqueleto, o Assistente de aplicativo do MFC declara uma classe de aplicativo derivada de [CWinApp](../mfc/reference/cwinapp-class.md). O Assistente de aplicativo do MFC também gera um arquivo de implementação que contém os seguintes itens:  
  
-   Um mapa de mensagem para a classe de aplicativo.  
  
-   Um construtor de classe vazia.  
  
-   Uma variável que declara um e apenas o objeto da classe.  
  
-   Uma implementação padrão de seu `InitInstance` função de membro.  
  
 A classe do aplicativo é colocada no cabeçalho do projeto e arquivos de origem principal. Os nomes da classe e os arquivos criados são baseados no nome do projeto que você fornecer no Assistente de aplicativo MFC. A maneira mais fácil para exibir o código para essas classes é por meio [modo de exibição de classe](http://msdn.microsoft.com/8d7430a9-3e33-454c-a9e1-a85e3d2db925).  
  
 O mapa de mensagem fornecida e implementações padrão são adequadas para muitas finalidades, mas você pode modificá-los conforme necessário. Essas implementações mais interessantes é a `InitInstance` função de membro. Normalmente, você adicionará código para a implementação de esqueleto de `InitInstance`.  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: A classe de aplicativo](../mfc/cwinapp-the-application-class.md)   
 [Funções de membro CWinApp substituíveis](../mfc/overridable-cwinapp-member-functions.md)   
 [Serviços CWinApp especiais](../mfc/special-cwinapp-services.md)

