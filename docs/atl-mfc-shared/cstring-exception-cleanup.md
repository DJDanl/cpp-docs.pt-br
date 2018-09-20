---
title: Limpeza de exceção de CString | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- CString objects, exceptions
- exception handling, cleanup code
ms.assetid: 28b9ce70-be63-4a0d-92a8-44bbfbc95e83
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 81349135fa822627cb40bdcd2570276d8040e50e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46385515"
---
# <a name="cstring-exception-cleanup"></a>Limpeza de exceção de CString

Nas versões anteriores do MFC, era importante limpar [CString](../atl-mfc-shared/reference/cstringt-class.md) objetos após o uso. Com o MFC versão 3.0 e posterior, limpeza explícita não é mais necessária.

Em que o MFC usa mecanismo de tratamento de exceções de C++, você não precisa se preocupar sobre a limpeza após uma exceção. Para obter uma descrição de como C++ "desenrola" a pilha após uma exceção é detectada, consulte [try, catch e throw instruções](../cpp/try-throw-and-catch-statements-cpp.md). Mesmo se você usar o MFC **tente**/**CATCH** macros em vez das palavras-chave C++ **tente** e **catch**, usa o MFC a C++ mecanismo de exceção abaixo, portanto, você ainda não é necessário limpar explicitamente.

## <a name="see-also"></a>Consulte também

[Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)<br/>
[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

