---
title: Classes de documento e exibição criadas pelo Assistente de Aplicativo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- document classes [MFC]
- document classes [MFC], created by application wizards
- application wizards [MFC], document/view classes created
- view classes [MFC], created by application wizards
ms.assetid: 70c34a60-2701-4981-acea-c08a5787d8e6
ms.openlocfilehash: 766fe4efb37c199c5babb75ce2cb08ebf676cca6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616047"
---
# <a name="document-and-view-classes-created-by-the-mfc-application-wizard"></a>Classes de documento e exibição criadas pelo Assistente de Aplicativo MFC

O assistente de aplicativo do MFC oferece uma visão inicial do desenvolvimento do programa criando um documento estrutural e classes de exibição para você. Em seguida, você pode [mapear comandos e mensagens para essas classes](reference/mapping-messages-to-functions.md) e usar o editor de código-fonte Visual C++ para gravar suas funções de membro.

A classe de documento criada pelo assistente de aplicativo MFC é derivada da classe [CDocument](reference/cdocument-class.md). A classe View é derivada de [cvisualização](reference/cview-class.md). Os nomes que o assistente de aplicativo fornece essas classes e os arquivos que as contêm são baseados no nome do projeto que você fornece na caixa de diálogo Assistente de aplicativo. No assistente de aplicativo, você pode usar a página classes geradas para alterar os nomes padrão.

Alguns aplicativos podem precisar de mais de uma classe de documento, uma classe de exibição ou uma classe de janela de quadro. Para obter mais informações, consulte [vários tipos de documento, exibições e janelas de quadros](multiple-document-types-views-and-frame-windows.md).

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](document-view-architecture.md)
