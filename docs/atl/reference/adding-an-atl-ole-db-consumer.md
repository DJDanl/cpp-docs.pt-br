---
title: Adicionando um consumidor do OLE DB da ATL
ms.date: 11/04/2016
helpviewer_keywords:
- ATL projects, adding ATL OLE DB consumers
- OLE DB, adding ATL OLE DB consumer to projects
- ATL OLE DB consumers
ms.assetid: f940a513-4e42-4148-b521-dd0d7dc89fa2
ms.openlocfilehash: d93bf715f8fd8a03c75b1d1bf2e44f12c1d1b9c0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62261371"
---
# <a name="adding-an-atl-ole-db-consumer"></a>Adicionando um consumidor do OLE DB da ATL

Use este assistente para adicionar um consumidor ATL OLE DB a um projeto. Um consumidor OLE DB da ATL consiste em um banco de dados OLE acessador classe e associações de dados necessárias para acessar uma fonte de dados. O projeto deve ter sido criado como um aplicativo ATL COM ou como um aplicativo MFC ou Win32 que contém suporte ATL (que o ATL OLE DB consumidor assistente adiciona automaticamente).

> [!NOTE]
> Você pode adicionar um consumidor OLE DB a um projeto MFC. Se você fizer isso, o ATL OLE DB consumidor assistente adiciona o suporte COM necessário ao seu projeto. Isso pressupõe que, quando você criou o projeto do MFC, você selecionou o **controles ActiveX** caixa de seleção (na **recursos avançados** página do Assistente de aplicativo MFC projeto), que é marcado por padrão. Selecionar essa opção garante que o aplicativo chama `CoInitialize` e `CoUninitialize`. Se você não selecionou **controles ActiveX** quando você criou o projeto do MFC, você precisará chamar `CoInitialize` e `CoUninitialize` em seu código principal.

## <a name="to-add-an-atl-ole-db-consumer-to-your-project"></a>Para adicionar um consumidor OLE DB da ATL ao seu projeto

1. Na **modo de exibição de classe**, clique com botão direito no projeto. No menu de atalho, clique em **Add** e, em seguida, clique em **Adicionar classe**.

1. Na pasta do Visual C++, clique duas vezes o **ATL OLE DB consumidor** ícone ou selecione-o e clique em **abrir**.

   A ATL OLE DB consumidor assistente é aberto.

1. Definir as configurações conforme descrito em [ATL OLE DB Assistente de consumidor](../../atl/reference/atl-ole-db-consumer-wizard.md).

1. Clique em **concluir** para fechar o assistente. O código de consumidor OLE DB recém-criado será inserido em seu projeto.

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)
