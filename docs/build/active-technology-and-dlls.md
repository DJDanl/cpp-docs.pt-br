---
title: Tecnologia ativa e DLLs
ms.date: 11/04/2016
helpviewer_keywords:
- in-process server DLLs
- Automation [C++], DLLs
- DLLs [C++], Active Technology
- Active technology [C++]
- MFC DLLs [C++], Active Technology
ms.assetid: 3ed27f8d-164a-4562-ad61-9f2333404cc7
ms.openlocfilehash: f67fb9548601ac705ceda08d20d3049f0bf1e0a5
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221003"
---
# <a name="active-technology-and-dlls"></a>Tecnologia ativa e DLLs

A tecnologia ativa permite que os servidores de objetos sejam completamente implementados dentro de uma DLL. Esse tipo de servidor é chamado de servidor em processo. O MFC não dá suporte completo a servidores em processo para todos os recursos de edição visual, principalmente porque a tecnologia ativa não fornece uma maneira para um servidor conectar-se ao loop de mensagem principal do contêiner. O MFC requer acesso ao loop de mensagem do aplicativo de contêiner para manipular chaves de acelerador e processamento em tempo ocioso.

Se você estiver gravando um servidor de automação e o servidor não tiver nenhuma interface do usuário, você poderá tornar o servidor um servidor em processo e colocá-lo completamente em uma DLL.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Servidores de automação](../mfc/automation-servers.md)

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
