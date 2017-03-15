---
title: Adicionando um consumidor ATL OLE DB | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding ATL OLE DB consumers
- OLE DB, adding ATL OLE DB consumer to projects
- ATL OLE DB consumers
ms.assetid: f940a513-4e42-4148-b521-dd0d7dc89fa2
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c7202444e1b3aa473060df359dbeb8a8668f65f4
ms.lasthandoff: 02/25/2017

---
# <a name="adding-an-atl-ole-db-consumer"></a>Adicionando um consumidor ATL OLE DB
Use este assistente para adicionar um consumidor ATL OLE DB a um projeto. Um consumidor ATL OLE DB consiste de um OLE DB acessador classe associações e de dados necessários para acessar uma fonte de dados. O projeto deve ter sido criado como um aplicativo COM ATL, ou como um aplicativo MFC ou Win32 que contém suporte ATL (que o ATL OLE DB consumidor Wizard adiciona automaticamente).  
  
 **Observação** você pode adicionar um consumidor OLE DB a um projeto. Nesse caso, o OLE DB consumidor assistente ATL adiciona o suporte COM necessário ao seu projeto. Isso pressupõe que, quando você criou o projeto MFC, você selecionou o **controles ActiveX** caixa de seleção (no **recursos avançados** página do Assistente de aplicativo MFC projeto), que é marcado por padrão. Selecionar essa opção garante que o aplicativo chama **CoInitialize** e **CoUninitialize**. Se você não selecionou **controles ActiveX** quando você criou o projeto MFC, você precisará chamar **CoInitialize** e **CoUninitialize** em seu código principal.  
  
### <a name="to-add-an-atl-ole-db-consumer-to-your-project"></a>Para adicionar um consumidor OLE DB ATL ao seu projeto  
  
1.  No modo de exibição de classe, clique com botão direito no projeto. No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar classe**.  
  
2.  Na pasta do Visual C++, clique duas vezes o **ATL OLE DB consumidor** ícone ou selecione-o e clique em **abrir**.  
  
     O ATL OLE DB consumidor assistente é aberto.  
  
3.  Definir as configurações, conforme descrito em [ATL OLE DB Assistente de consumidor](../../atl/reference/atl-ole-db-consumer-wizard.md).  
  
4.  Clique em **concluir** para fechar o assistente. O código de consumidor OLE DB recém-criado será inserido no seu projeto.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)


