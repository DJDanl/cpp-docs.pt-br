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
ms.openlocfilehash: 9633d60520a2a634ffe78d0fb9d48f6dd2ca7333
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57817446"
---
# <a name="active-technology-and-dlls"></a>Tecnologia ativa e DLLs

Tecnologia ativa permite que os servidores de objeto sejam implementados completamente dentro de uma DLL. Esse tipo de servidor é chamado de um servidor em processo. MFC não suporta completamente os servidores em processo para todos os recursos de edição visual, principalmente porque a tecnologia do Active Directory não fornece uma maneira para um servidor a ser vinculada ao loop de mensagem principal do contêiner. MFC requer acesso ao loop de mensagem do aplicativo de contêiner para manipular teclas de aceleração e processamento de tempo ocioso.

Se você estiver escrevendo um servidor de automação e o servidor não tem nenhuma interface do usuário, você pode tornar seu servidor de um servidor em processo e colocá-lo completamente em uma DLL.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Servidores de automação](../mfc/automation-servers.md)

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](dlls-in-visual-cpp.md)
