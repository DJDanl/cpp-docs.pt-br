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
ms.openlocfilehash: 9c657bb0d583270f81658afa53f36b1be6a4fd4a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493260"
---
# <a name="freelibrary-and-afxfreelibrary"></a>FreeLibrary e AfxFreeLibrary

Processos que se vinculam explicitamente a uma DLL chamam a função [FreeLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) quando o módulo DLL não é mais necessário. Essa função decrementa a contagem de referência do módulo e, se a contagem de referência for zero, desmapeará o espaço de endereço do processo.

Em um aplicativo MFC, use [AfxFreeLibrary](../mfc/reference/application-information-and-management.md#afxfreelibrary) em vez `FreeLibrary` de para descarregar uma DLL de extensão do MFC. A interface (protótipo de função) `AfxFreeLibrary` para é a mesma `FreeLibrary`que.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#linking-implicitly)

- [Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [LoadLibrary e AfxLoadLibrary](loadlibrary-and-afxloadlibrary.md)

- [GetProcAddress](getprocaddress.md)

## <a name="see-also"></a>Consulte também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)<br/>
[FreeLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary)
[AfxFreeLibrary](../mfc/reference/application-information-and-management.md#afxfreelibrary)
