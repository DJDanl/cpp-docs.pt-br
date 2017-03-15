---
title: "Como criar um arquivo de script de recurso | Microsoft Docs"
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
  - "arquivos RC, criando"
  - "arquivos. RC, criando"
  - "arquivos de script de recurso, criando"
ms.assetid: 82be732a-cdcd-4a58-8de7-976d1418f86b
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar um arquivo de script de recurso
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  O Editor de recursos não está disponível nas edições Express.  
>   
>  Esse material se aplica a aplicativos de área de trabalho do Windows. Projetos em linguagens .NET não usa arquivos de script de recurso. Consulte [arquivos de recurso](../mfc/resource-files-visual-studio.md), para obter mais informações.  
  
### Para criar um novo arquivo de script \(. rc\) do recurso  
  
1.  Colocar o foco na sua pasta de projeto existente no `Solution Explorer`, por exemplo, "MyProject".  
  
    > [!NOTE]
    >  Não confunda a pasta do projeto com a pasta de solução no Solution Explorer. Se você colocar o foco na pasta da solução, suas opções no **Add New Item** caixa de diálogo \(na etapa 3\) será diferente.  
  
2.  Sobre o **projeto** menu clique **Add New Item**.  
  
3.  No **Add New Item** caixa de diálogo, clique o **Visual C\+\+** pasta escolha **arquivo de recurso \(. rc\)** no painel à direita.  
  
4.  Forneça um nome para o arquivo de script recursos o **nome** texto caixa e, em seguida, clique em **Abrir**.  
  
 Agora você pode [criar](../windows/how-to-create-a-resource.md) e adicionar novos recursos ao seu arquivo. rc.  
  
> [!NOTE]
>  Você só pode adicionar um script \(arquivo. rc\) do recurso a um projeto existente que é carregado no IDE do Visual Studio. Você não pode criar um arquivo. RC do autônomo \(um fora do projeto\).[Modelos de recursos](../Topic/How%20to:%20Use%20Resource%20Templates.md) \(arquivos. rct\) podem ser criados a qualquer momento.  
  
 RRequirements  
  
 Win32  
  
## Consulte também  
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)   
 [Editores de recursos](../mfc/resource-editors.md)