---
title: "Implementando um ponto de conex&#227;o (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pontos de conexão [C++], implementando"
  - "Assistente de Implementação de Pontos de Conexão [C++]"
ms.assetid: 5b37e4f9-73c9-4bef-b26d-365bc0662260
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando um ponto de conex&#227;o (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para implementar um ponto de conexão usando o Assistente para implementar o ponto de conexão, você deve ter criado um projeto como um aplicativo COM ATL ou como um aplicativo MFC que contém suporte ATL.  Você pode usar o  [ATL Project Wizard](../Topic/ATL%20Project%20Wizard.md) para criar um aplicativo ATL, ou  [Adicionar um objeto ATL para seu aplicativo MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo MFC.  
  
> [!NOTE]
>  Para obter informações sobre como implementar os pontos de conexão para um projeto MFC, consulte  [Pontos de conexão](../mfc/connection-points.md).  
  
 Depois de criar o projeto, para implementar um ponto de conexão, você deve adicionar um objeto ATL.  Consulte  [adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter uma lista de assistentes que adicionar objetos ao seu projeto ATL.  
  
> [!NOTE]
>  O assistente não oferece suporte a caixas de diálogo do ATL, XML Web services criados com servidor ATL, objetos de desempenho ou contadores de desempenho.  
  
 Um objeto conectável \(ou seja, uma fonte\) pode expor um ponto de conexão para cada uma das suas interfaces de saída.  Cada interface de saída pode ser implementado por um cliente em um objeto \(ou seja, um coletor\).  Para obter mais informações, consulte  [Pontos de conexão de ATL](../atl/atl-connection-points.md).  
  
### Para implementar um ponto de conexão  
  
1.  No modo de exibição de classe, com o botão direito no nome da classe para seu objeto ATL.  
  
2.  Clique em  **Add** partir no menu de atalho e, em seguida, clique  **Adicionar ponto de conexão**  para exibir o  [O Assistente para ponto de conexão de implementar](../ide/implement-connection-point-wizard.md).  
  
3.  Selecione as interfaces de ponto de conexão para implementar das bibliotecas do tipo apropriado e clique em  **Concluir**.  
  
4.  No modo de exibição de classe, examine as classes de proxy criadas para cada ponto de conexão.  As classes aparecem como CProxy*InterfaceName*\<T\> e são derivados de  [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md).  
  
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
  
    -   Se você implementar um ponto de conexão para outra interface, a definição inclui métodos da interface, cada uma precedida por `Fire_`.  
  
## Consulte também  
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando pontos de conexão a um objeto](../atl/adding-connection-points-to-an-object.md)