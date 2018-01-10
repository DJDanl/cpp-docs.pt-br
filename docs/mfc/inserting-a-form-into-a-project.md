---
title: "Inserindo um formulário em um projeto | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- inserting forms [MFC]
- Insert New dialog box [MFC]
- forms, adding to projects
ms.assetid: f3bd2998-3ce2-496d-ac5c-57ca70eec7cb
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 968c24a4f64b88be6de95f0f1dd98c09eb494a97
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="inserting-a-form-into-a-project"></a>Inserindo um formulário em um projeto
Formulários fornecem um contêiner conveniente para controles. Você pode inserir facilmente um formulário com base em MFC em seu aplicativo enquanto o aplicativo oferece suporte as bibliotecas MFC.  
  
### <a name="to-insert-a-form-into-your-project"></a>Para inserir um formulário em seu projeto  
  
1.  De modo de exibição de classe, selecione o projeto ao qual você deseja adicionar o formulário e clique no botão direito do mouse.  
  
2.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar classe**.  
  
     Se o **novo formulário** comando não estiver disponível, seu projeto pode se basear na biblioteca de modelo ativa (ATL). Para adicionar um formulário para um projeto de ATL, você deve [especificar determinadas configurações](../atl/reference/application-settings-atl-project-wizard.md) ao primeiro criar o projeto.  
  
3.  Do **MFC** pasta, clique em **classe MFC**.  
  
4.  Usando o Assistente de classe MFC, verifique a nova classe derivam [CFormView](../mfc/reference/cformview-class.md).  
  
 Visual C++ adiciona o formulário ao seu aplicativo, abri-lo no editor de caixa de diálogo para que você pode começar a adicionar controles e trabalhar em seu design geral.  
  
 Você talvez queira executar as seguintes etapas adicionais (não aplicáveis para aplicativos com base na caixa de diálogo):  
  
1.  Substituir o `OnUpdate` função de membro.  
  
2.  Implemente uma função de membro para mover dados do modo de exibição para o documento.  
  
3.  Criar um `OnPrint` função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Modos de exibição de formulário](../mfc/form-views-mfc.md)

