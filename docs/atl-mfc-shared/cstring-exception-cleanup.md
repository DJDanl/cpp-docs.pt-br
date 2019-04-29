---
title: Limpeza de exceção de CString
ms.date: 11/04/2016
helpviewer_keywords:
- CString objects, exceptions
- exception handling, cleanup code
ms.assetid: 28b9ce70-be63-4a0d-92a8-44bbfbc95e83
ms.openlocfilehash: d131ce8ebe5158d7f3a567580064068742b63707
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62236622"
---
# <a name="cstring-exception-cleanup"></a>Limpeza de exceção de CString

Nas versões anteriores do MFC, era importante limpar [CString](../atl-mfc-shared/reference/cstringt-class.md) objetos após o uso. Com o MFC versão 3.0 e posterior, limpeza explícita não é mais necessária.

Em que o MFC usa mecanismo de tratamento de exceções de C++, você não precisa se preocupar sobre a limpeza após uma exceção. Para obter uma descrição de como C++ "desenrola" a pilha após uma exceção é detectada, consulte [try, catch e throw instruções](../cpp/try-throw-and-catch-statements-cpp.md). Mesmo se você usar o MFC **tente**/**CATCH** macros em vez das palavras-chave C++ **tente** e **catch**, usa o MFC a C++ mecanismo de exceção abaixo, portanto, você ainda não é necessário limpar explicitamente.

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
