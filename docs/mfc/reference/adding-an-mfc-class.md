---
title: Adicionando uma classe MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.classes.adding.mfc
dev_langs:
- C++
helpviewer_keywords:
- classes [MFC], adding MFC
- MFC, adding classes
ms.assetid: 9a96b67f-40bf-43d4-8872-2f8dfc5404f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 86e42ab5c2e8e15f5f56687b5ca99d160270017b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46436358"
---
# <a name="adding-an-mfc-class"></a>Adicionando uma classe do MFC

Para adicionar classes derivadas de classes da biblioteca Microsoft Foundation Class (MFC) ao seu projeto, use o **Add Class** comando disponível no [exibição de classe](/visualstudio/ide/viewing-the-structure-of-code). Especifique o nome da nova classe, selecione a classe base e selecione a ID da caixa de diálogo com a qual ele está associado (se houver). O Assistente de código cria um arquivo de cabeçalho e um arquivo de implementação e os adiciona ao seu projeto.

> [!NOTE]
>  Você pode adicionar classes MFC para um aplicativo ATL COM se você inicialmente [criou o aplicativo com suporte do MFC](../../atl/reference/mfc-support-in-atl-projects.md). Você também pode adicionar classes MFC para projetos do Win32 que têm suporte do MFC.

### <a name="to-add-an-mfc-class-to-your-project"></a>Para adicionar uma classe MFC ao seu projeto

1. Na exibição de classe, clique com botão direito no nome do projeto. Clique em **Add** e, em seguida, clique em **Add Class** para abrir o [Adicionar classe](../../ide/add-class-dialog-box.md) caixa de diálogo.

1. No painel modelos, selecione **classe MFC** e pressione a **Add** botão.

1. Definir as configurações para a nova classe de [MFC Class Wizard](../../mfc/reference/mfc-add-class-wizard.md) caixa de diálogo.

1. Clique em **concluir** para fechar o assistente e exibir a nova classe no modo de exibição de classe. Você também pode exibir os arquivos criados pelo assistente no **Gerenciador de soluções**.

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Visão geral da classe](../../mfc/class-library-overview.md)

