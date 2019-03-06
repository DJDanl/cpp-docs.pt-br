---
title: Automação em um DLL
ms.date: 11/04/2016
helpviewer_keywords:
- DLLs [C++], Automation
- Automation [C++], DLLs
ms.assetid: 2728ecd1-14e2-4ae0-a946-e749e11dbb74
ms.openlocfilehash: 3cc5ca456842707a2c3de7b2fd74abc73d9a5307
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422280"
---
# <a name="automation-in-a-dll"></a>Automação em um DLL

Quando você escolhe a opção de automação no Assistente de DLL do MFC, o assistente fornece o seguinte:

- Uma linguagem de descrição do objeto inicial (. Arquivo ODL)

- Uma diretiva de inclusão no arquivo Stdafx. h para Afxole.h

- Uma implementação de `DllGetClassObject` função, que chama o **AfxDllGetClassObject** função

- Uma implementação de `DllCanUnloadNow` função, que chama o **AfxDllCanUnloadNow** função

- Uma implementação de `DllRegisterServer` função, que chama o [COleObjectFactory::UpdateRegistryAll](../mfc/reference/coleobjectfactory-class.md#updateregistryall) função

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Servidores de automação](../mfc/automation-servers.md)

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)
