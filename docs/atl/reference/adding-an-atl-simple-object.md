---
title: Adição de um objeto Simple da ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.classes.adding.atl
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding objects
- objects [ATL]
- ATL, simple objects
ms.assetid: 9c57d2ef-0447-4c84-8982-3304b8e49847
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f757602459c55b7b66e01d9512d9d4cdeb2f3946
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861038"
---
# <a name="adding-an-atl-simple-object"></a>Adição de um objeto Simple da ATL

Para adicionar um objeto ATL (Active Template Library) ao seu projeto, seu projeto deve ter sido criado como um aplicativo ATL ou como um aplicativo do MFC que contém suporte ATL. Use o [Assistente de Projeto ATL](../../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao aplicativo MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte à ATL para um aplicativo MFC.

Você pode definir interfaces COM para seu novo objeto ATL ao primeiro criá-lo ou adicioná-los posteriormente usando o [implementar Interface](../../ide/implement-interface-wizard.md) comando da **Class View** menu de atalho.

## <a name="to-add-an-atl-simple-object-to-your-atl-com-project"></a>Para adicionar um objeto simple da ATL ao seu projeto de ATL COM

1. Em ambos **Gerenciador de soluções** ou [exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique no nome do projeto ao qual você deseja adicionar objeto ATL simples.

1. No menu de atalho, clique em **Adicionar** e, em seguida, em **Adicionar Classe**.

1. No [Add Class](../../ide/add-class-dialog-box.md) na caixa a **modelos** painel, clique em **ATL Simple Object**e, em seguida, clique em **abrir** para exibir o [ATL Simple Object Wizard](../../atl/reference/atl-simple-object-wizard.md).

1. Definir opções adicionais para seu projeto na [opções](../../atl/reference/options-atl-simple-object-wizard.md) página do **ATL Simple Object** assistente.

1. Clique em **concluir** para adicionar o objeto ao seu projeto.

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma nova Interface em um projeto da ATL](../../atl/reference/adding-a-new-interface-in-an-atl-project.md)<br/>
[Adicionando pontos de conexão a um objeto](../../atl/adding-connection-points-to-an-object.md)<br/>
[Adicionando um método](../../ide/adding-a-method-visual-cpp.md)<br/>
[Classe do MFC](../../mfc/reference/adding-an-mfc-class.md)<br/>
[Adicionando uma classe do C++ genérica](../../ide/adding-a-generic-cpp-class.md)
