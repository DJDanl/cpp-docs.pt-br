---
title: Destruindo janelas com moldura
ms.date: 11/04/2016
f1_keywords:
- PostNcDestroy
helpviewer_keywords:
- Default method [MFC]
- DestroyWindow method [MFC]
- frame windows [MFC], destroying
- OnNcDestroy method, and frame windows
- document frame windows [MFC], destroying
- destroying frame windows
- MFC, frame windows
- windows [MFC], destroying
- OnClose method [MFC]
- PostNcDestroy method [MFC]
ms.assetid: 5affca77-1999-4507-a2b2-9aa226611b4b
ms.openlocfilehash: 20eefa2be6d0e0df4585834bae5c37cd258610a7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214133"
---
# <a name="destroying-frame-windows"></a>Destruindo janelas com moldura

A estrutura MFC gerencia a destruição de janelas, bem como a criação dessas janelas associadas a documentos e exibições da estrutura. Se você criar janelas adicionais, será responsável por destruí-las.

Na estrutura, quando o usuário fecha a janela do quadro, o manipulador [fechamento](reference/cwnd-class.md#onclose) padrão da janela chama [DestroyWindow](reference/cwnd-class.md#destroywindow). A última função de membro chamada quando a janela do Windows é destruída é [OnNcDestroy](reference/cwnd-class.md#onncdestroy), que faz alguma limpeza, chama a função de membro [padrão](reference/cwnd-class.md#default) para executar a limpeza do Windows e chama por último a função de membro virtual [PostNcDestroy](reference/cwnd-class.md#postncdestroy). A implementação de [CFrameWnd](reference/cframewnd-class.md) de `PostNcDestroy` exclui o objeto de janela C++. Você nunca deve usar o **`delete`** operador C++ em uma janela de quadro. Use `DestroyWindow` em vez disso.

Quando a janela principal é fechada, o aplicativo fecha. Se houver documentos não salvos modificados, a estrutura exibirá uma caixa de mensagem para perguntar se os documentos devem ser salvos e garante que os documentos apropriados sejam salvos, se necessário.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Criando janelas com moldura de documento](creating-document-frame-windows.md)

## <a name="see-also"></a>Confira também

[Usando janelas de quadros](using-frame-windows.md)
