---
title: "Adicionando suporte ATL ao seu projeto MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.adding.atl.mfc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, projetos MFC"
  - "MFC, Suporte ATL"
ms.assetid: b5fe15d6-7752-4818-b9f9-62482ad35c95
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando suporte ATL ao seu projeto MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Se você já tiver criado um aplicativo baseado MFC\-, você pode adicionar suporte para a biblioteca ativa \(ATL\) do modelo facilmente executando o suporte adicionar ATL o assistente de projeto de MFC.  
  
> [!NOTE]
>  ATL e MFC o não têm suporte em geral nas edições express do Visual Studio.  
  
> [!NOTE]
>  Esse suporte só se aplica a objetos COM simples adicionados a um executável MFC ou a um projeto da DLL.  Você pode adicionar outros objetos COM \(inclusive controles ActiveX\) para projetos de MFC, mas os objetos podem não funcionar conforme o esperado.  
  
### Para adicionar suporte de ATL ao seu projeto MFC  
  
1.  No Solution Explorer, clique com o botão direito do mouse no projeto ao qual você deseja adicionar suporte de ATL.  
  
2.  No menu de atalho, clique **Adicionar**, e clique em **Adicionar Classe**.  
  
3.  Selecione o ícone de **Add ATL Support to MFC Project** .  
  
    > [!NOTE]
    >  Esse ícone está localizado na pasta de ATL no painel de **Categorias** .  
  
4.  Quando solicitado, clique em **Sim** para adicionar suporte de ATL.  
  
 Para obter mais informações sobre como adicionar suporte de ATL altera seu código de projeto MFC, consulte [Detalhes de suporte de ATL adicionados pelo assistente de ATL](../../mfc/reference/details-of-atl-support-added-by-the-atl-wizard.md)  
  
## Consulte também  
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)