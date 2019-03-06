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
ms.openlocfilehash: 82e18efe66350349c8cbef7f47b7d1fb226674f1
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57420161"
---
# <a name="active-technology-and-dlls"></a>Tecnologia ativa e DLLs

Tecnologia ativa permite que os servidores de objeto sejam implementados completamente dentro de uma DLL. Esse tipo de servidor é chamado de um servidor em processo. MFC não suporta completamente os servidores em processo para todos os recursos de edição visual, principalmente porque a tecnologia do Active Directory não fornece uma maneira para um servidor a ser vinculada ao loop de mensagem principal do contêiner. MFC requer acesso ao loop de mensagem do aplicativo de contêiner para manipular teclas de aceleração e processamento de tempo ocioso.

Se você estiver escrevendo um servidor de automação e o servidor não tem nenhuma interface do usuário, você pode tornar seu servidor de um servidor em processo e colocá-lo completamente em uma DLL.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Servidores de automação](../mfc/automation-servers.md)

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)
