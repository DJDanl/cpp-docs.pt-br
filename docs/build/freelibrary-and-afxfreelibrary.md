---
title: FreeLibrary e AfxFreeLibrary
ms.date: 11/04/2016
f1_keywords:
- FreeLibrary
- AfxFreeLibrary
helpviewer_keywords:
- extension DLLs [C++], unloading
- AfxFreeLibrary method
- unloading DLLs
- FreeLibrary method
- DLLs [C++], linking
- explicit linking [C++]
- DLLs [C++], unloading
ms.assetid: 4a48d290-3971-43e9-8e97-ba656cd0c8f8
ms.openlocfilehash: 59deb75ad77b0a80efc69d9991e093ecef95c51e
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221418"
---
# <a name="freelibrary-and-afxfreelibrary"></a>FreeLibrary e AfxFreeLibrary

Processos que vincule explicitamente para uma DLL chamam a [FreeLibrary](/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary) funcionar quando o módulo DLL não é mais necessário. Essa função diminui a contagem de referência do módulo e, se a contagem de referência é zero, unmaps-lo do espaço de endereço do processo.

Em um aplicativo do MFC, use [AfxFreeLibrary](../mfc/reference/application-information-and-management.md#afxfreelibrary) em vez de `FreeLibrary` para descarregar uma DLL de extensão do MFC. A interface (protótipo de função) para `AfxFreeLibrary` é o mesmo que `FreeLibrary`.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#linking-implicitly)

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [LoadLibrary e AfxLoadLibrary](loadlibrary-and-afxloadlibrary.md)

- [GetProcAddress](getprocaddress.md)

## <a name="see-also"></a>Consulte também

[Criar DLLs de C/C++ no Visual Studio](dlls-in-visual-cpp.md)<br/>
[FreeLibrary](/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary)
[AfxFreeLibrary](../mfc/reference/application-information-and-management.md#afxfreelibrary)
