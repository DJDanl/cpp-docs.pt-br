---
title: Criando um projeto para o provedor | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, creating
- OLE DB providers, projects
- projects [C++], creating
ms.assetid: 076a75de-1d4b-486a-bcf8-9c0f6b049fa2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 86f85b95b4b45624a778bc183cabadda886d002d
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49990064"
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