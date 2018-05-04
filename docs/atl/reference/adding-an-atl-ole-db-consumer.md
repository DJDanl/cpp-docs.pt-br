---
title: Adicionando um consumidor ATL OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding ATL OLE DB consumers
- OLE DB, adding ATL OLE DB consumer to projects
- ATL OLE DB consumers
ms.assetid: f940a513-4e42-4148-b521-dd0d7dc89fa2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 90b16c84c0dc2c921722c4c80a1e2bdf0e091d9c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="adding-an-atl-ole-db-consumer"></a>Adicionando um consumidor ATL OLE DB
Use este assistente para adicionar um consumidor ATL OLE DB a um projeto. Um consumidor ATL OLE DB consiste em um banco de dados OLE acessador classe dados associações e necessárias para acessar uma fonte de dados. O projeto deve ter sido criado como um aplicativo COM ATL ou como um aplicativo MFC ou Win32 que contém suporte ATL (que o ATL OLE DB consumidor assistente adiciona automaticamente).  
  
 **Observação** você pode adicionar um consumidor OLE DB para um projeto MFC. Se você fizer isso, o OLE DB consumidor assistente ATL adiciona o suporte COM necessário ao seu projeto. Isso pressupõe que, quando você criou o projeto MFC, você selecionou o **controles ActiveX** caixa de seleção (no **recursos avançados** página do Assistente de aplicativo MFC projeto), que é marcado por padrão. Selecionar essa opção garante que o aplicativo chama **CoInitialize** e **CoUninitialize**. Se você não selecionou **controles ActiveX** quando você criou o projeto MFC, você precisa chamar **CoInitialize** e **CoUninitialize** em seu código principal.  
  
### <a name="to-add-an-atl-ole-db-consumer-to-your-project"></a>Para adicionar um consumidor OLE DB ATL ao seu projeto  
  
1.  No modo de exibição de classe, clique com botão direito no projeto. No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar classe**.  
  
2.  Na pasta do Visual C++, clique duas vezes o **ATL OLE DB consumidor** ícone ou selecione-o e clique em **abrir**.  
  
     O OLE DB consumidor assistente ATL é aberto.  
  
3.  Definir as configurações, conforme descrito em [ATL OLE DB Assistente de consumidor](../../atl/reference/atl-ole-db-consumer-wizard.md).  
  
4.  Clique em **concluir** para fechar o assistente. O código de consumidor OLE DB recém-criado será inserido em seu projeto.  
  
## <a name="see-also"></a>Consulte também  
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)

