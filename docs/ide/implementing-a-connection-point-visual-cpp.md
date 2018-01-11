---
title: "Implementando um ponto de Conexão (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Implement Connection Point Wizard [C++]
- connection points [C++], implementing
ms.assetid: 5b37e4f9-73c9-4bef-b26d-365bc0662260
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ab065c78d8ea5d2de105abdc2fa651e05f9d1875
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="implementing-a-connection-point-visual-c"></a>Implementando um ponto de conexão (Visual C++)
Para implementar um ponto de conexão usando o Assistente para implementar ponto de Conexão, você deve ter criado um projeto como um aplicativo COM ATL ou como um aplicativo MFC que contém suporte ATL. Você pode usar o [Assistente de projeto de ATL](../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL, ou [adicionar um objeto ATL ao seu aplicativo do MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo do MFC.  
  
> [!NOTE]
>  Para obter informações sobre como implementar pontos de conexão para um projeto MFC, consulte [pontos de Conexão](../mfc/connection-points.md).  
  
 Depois de criar o projeto, para implementar um ponto de conexão, adicione primeiro um objeto ATL. Consulte [adicionando objetos e controles para um projeto de ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter uma lista de assistentes que adicionar objetos ao seu projeto ATL.  
  
> [!NOTE]
>  O assistente não oferece suporte para as caixas de diálogo do ATL XML Web services criados com servidor ATL, objetos de desempenho ou os contadores de desempenho.  
  
 Um objeto conectável (ou seja, uma fonte) pode expor um ponto de conexão para cada uma das suas interfaces de saída. Cada interface de saída pode ser implementado por um cliente em um objeto (ou seja, um coletor). Para obter mais informações, consulte [pontos de Conexão de ATL](../atl/atl-connection-points.md).  
  
### <a name="to-implement-a-connection-point"></a>Para implementar um ponto de conexão  
  
1.  No modo de exibição de classe, clique no nome de classe para seu objeto ATL.  
  
2.  Clique em **adicionar** do menu de atalho e clique **Adicionar ponto de Conexão** para exibir o [Assistente de implementação de ponto de Conexão](../ide/implement-connection-point-wizard.md).  
  
3.  Selecione as interfaces de ponto de conexão para implementar das bibliotecas de tipo apropriado e clique em **concluir**.  
  
4.  No modo de exibição de classe, examine as classes de proxy criadas para cada ponto de conexão. As classes aparecem como CProxy*InterfaceName*\<T > e são derivados de [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md).  
  
5.  Clique duas vezes a classe de ponto de conexão para exibir a definição de classe do ponto de conexão.  
  
    -   Se você implementar um ponto de conexão para a interface do seu próprio projeto, será exibida a seguinte definição  
  
        ```  
        template< class T >  
        class CProxyInterfaceName :  
           public IConnectionPointImpl< T, &IID_InterfaceName >  
        {  
        public:  
        };  
        ```  
  
         Se você implementar uma interface local, métodos e propriedades aparecem no corpo da classe.  
  
    -   Se você implementar um ponto de conexão para outra interface, a definição inclui métodos da interface, cada precedido por `Fire_`.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando pontos de conexão a um objeto](../atl/adding-connection-points-to-an-object.md)