---
title: Adicionando uma classe por meio de um controle ActiveX (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 09/07/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ActiveX controls [C++], adding classes
- classes [C++], creating
ms.assetid: 729fcb37-54b8-44d5-9b4e-50bb16e0eea4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6f9e7d8ea0e3b21b06d73e187a4f45c53cd896cf
ms.sourcegitcommit: d1527eb2d50156bf923f2a32ec3af9efc7fc4304
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48250478"
---
# <a name="adding-a-class-from-an-activex-control-visual-c"></a>Adicionando uma classe a partir de um controle ActiveX (Visual C++)

Use este assistente para criar uma classe MFC por meio de uma interface em um controle ActiveX disponível. Adicione uma classe MFC a um [aplicativo MFC](../mfc/reference/creating-an-mfc-application.md), uma [DLL do MFC](../mfc/reference/creating-an-mfc-dll-project.md) ou um [controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md).

> [!WARNING]
> No Visual Studio 2017 versão 15.9, esse assistente de código foi preterido e será removido em uma versão futura do Visual Studio. Este assistente é raramente usado. O suporte geral para ATL e MFC não é afetado pela remoção do assistente. Se você quiser compartilhar seus comentários sobre essa alteração, participe [desta pesquisa](https://www.surveymonkey.com/r/QDWKKCN). Seus comentários são importantes para nós.

> [!NOTE]
>  Você não precisa criar seu projeto MFC com a Automação habilitada para adicionar uma classe por meio de um controle ActiveX.

Um controle ActiveX é um componente de software reutilizável baseado no COM (Component Object Model) que dá suporte a uma ampla variedade de funcionalidades OLE e que pode ser personalizado para atender às várias necessidades de software. Os controles ActiveX foram projetados para uso em contêineres comuns de controle ActiveX e na Internet em páginas da World Wide Web.

### <a name="to-add-an-mfc-class-from-an-activex-control"></a>Para adicionar uma classe MFC por meio de um controle ActiveX

1. No **Gerenciador de Soluções** ou em [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome do projeto ao qual deseja adicionar a classe de controle ActiveX.

1. No menu de atalho, clique em **Adicionar** e, em seguida, em **Adicionar Classe**.

1. Na caixa de diálogo [Adicionar Classe](../ide/add-class-dialog-box.md), no painel Modelos, clique em **Classe MFC por meio do controle ActiveX** e, em seguida, clique em **Abrir** para exibir a opção [Assistente para Adicionar Classe por meio de um Controle ActiveX](../ide/add-class-from-activex-control-wizard.md).

No assistente, adicione mais de uma interface em um controle ActiveX. Da mesma forma, crie classes por meio de mais de um controle ActiveX em uma única sessão do assistente.

Adicione classes por meio de controles ActiveX registrados no sistema ou de controles ActiveX localizados em arquivos de biblioteca de tipos (.tlb, .olb, .dll, .ocx ou .exe) sem primeiro registrá-los no sistema. Confira [Registrando controles OLE](../mfc/reference/registering-ole-controls.md) para obter mais informações sobre como registrar controles ActiveX.

O assistente cria uma classe MFC, derivada de [CWnd](../mfc/reference/cwnd-class.md) ou de [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md), para cada interface adicionada por meio do controle ActiveX selecionado.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br>
[Introdução ao COM e à ATL](../atl/introduction-to-com-and-atl.md)