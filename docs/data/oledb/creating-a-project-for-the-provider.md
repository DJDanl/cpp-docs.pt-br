---
title: Criando um projeto para o provedor
ms.date: 10/22/2018
helpviewer_keywords:
- ATL projects, creating
- OLE DB providers, projects
- projects [C++], creating
ms.assetid: 076a75de-1d4b-486a-bcf8-9c0f6b049fa2
ms.openlocfilehash: dc085b1f663369033947ed2a5577f334dd79c0aa
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62361939"
---
# <a name="creating-a-project-for-the-provider"></a>Criando um projeto para o provedor

## <a name="to-create-a-project-in-which-the-ole-db-provider-will-reside"></a>Para criar um projeto no qual o provedor OLE DB residirá

1. No menu **Arquivo**, clique em **Novo** e em **Projeto**.

   A caixa de diálogo **Novo Projeto** é exibida.

1. No **tipos de projeto** painel, clique no **instalado** > **Visual C++** > **MFC/ATL** pasta. No **modelos** painel, clique em **projeto ATL**.

    > [!NOTE]
    > Nas versões anteriores do Visual Studio, localize o tipo de projeto no **Installed** > **modelos** > **Visual C++**  >  **ATL**.

1. No **nome** caixa, digite um nome para o projeto e, em seguida, clique em **Okey**.

   O **ATL Project Wizard** é exibida.

1. No **ATL Project Wizard**, escolha **biblioteca de vínculo dinâmico (DLL)** para **tipo de aplicativo**.

1. Clique em **Finalizar**.

## <a name="see-also"></a>Consulte também

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)