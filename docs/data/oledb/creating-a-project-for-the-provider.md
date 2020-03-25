---
title: Criando um projeto para o provedor
ms.date: 10/22/2018
helpviewer_keywords:
- ATL projects, creating
- OLE DB providers, projects
- projects [C++], creating
ms.assetid: 076a75de-1d4b-486a-bcf8-9c0f6b049fa2
ms.openlocfilehash: f2ff42ba8a2e908f672db7e96fc9f24f51a1fd9b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211400"
---
# <a name="creating-a-project-for-the-provider"></a>Criando um projeto para o provedor

## <a name="to-create-a-project-in-which-the-ole-db-provider-will-reside"></a>Para criar um projeto no qual o provedor de OLE DB residirá

1. No menu **Arquivo**, clique em **Novo** e em **Projeto**.

   A caixa de diálogo **Novo Projeto** aparecerá.

1. No painel **tipos de projeto** , clique na **pasta instalado** > **Visual C++**  > **MFC/ATL** . No painel **modelos** , clique em **projeto ATL**.

    > [!NOTE]
    > Nas versões anteriores do Visual Studio, encontre o tipo de projeto em **installed** > **templates** > **Visual C++**  > **ATL**.

1. Na caixa **nome** , insira um nome para o projeto e clique em **OK**.

   O **Assistente de projeto do ATL** é exibido.

1. No **Assistente de projeto do ATL**, escolha biblioteca de **vínculo dinâmico (DLL)** para o **tipo de aplicativo**.

1. Clique em **Concluir**.

## <a name="see-also"></a>Confira também

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)
