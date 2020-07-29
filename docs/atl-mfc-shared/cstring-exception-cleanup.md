---
title: Limpeza de exceção de CString
ms.date: 11/04/2016
helpviewer_keywords:
- CString objects, exceptions
- exception handling, cleanup code
ms.assetid: 28b9ce70-be63-4a0d-92a8-44bbfbc95e83
ms.openlocfilehash: 48c8f1c0040236a4f7bf27a2d5ad985ae343c03a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222050"
---
# <a name="cstring-exception-cleanup"></a>Limpeza de exceção de CString

Nas versões anteriores do MFC, era importante que você limpe os objetos [CString](../atl-mfc-shared/reference/cstringt-class.md) após o uso. Com o MFC versão 3,0 e posterior, a limpeza explícita não é mais necessária.

No mecanismo de manipulação de exceções do C++ que o MFC usa agora, você não precisa se preocupar com a limpeza após uma exceção. Para obter uma descrição de como o C++ "desenrola" a pilha depois que uma exceção é capturada, consulte [as instruções Try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md). Mesmo se você usar o MFC, **tente** / **capturar** macros em vez das palavras-chave do c++ **`try`** e **`catch`** o MFC usará o mecanismo de exceção do c++ abaixo para que você ainda não precise limpá-lo explicitamente.

## <a name="see-also"></a>Confira também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Tratamento de exceção](../mfc/exception-handling-in-mfc.md)
