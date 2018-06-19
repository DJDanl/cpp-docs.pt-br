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
ms.openlocfilehash: d18d10d517a6c5b0d075a7fb0ed113448625b698
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32355500"
---
# <a name="cstring-exception-cleanup"></a>Limpeza de exceção de CString
Em versões anteriores do MFC, era importante limpar [CString](../atl-mfc-shared/reference/cstringt-class.md) objetos após o uso. Com MFC versão 3.0 e posterior, limpeza explícita não é mais necessária.  
  
 Sob o mecanismo MFC agora usa de manipulação de exceções de C++, você não precisa se preocupar sobre a limpeza após uma exceção. Para obter uma descrição de como C++ "esvazia" a pilha após uma exceção for detectada, consulte [try, catch e instruções throw](../cpp/try-throw-and-catch-statements-cpp.md). Mesmo se você usar o MFC **tente**/**CATCH** macros em vez das palavras-chave C++ **tente** e **catch**, MFC usa C++ mecanismo de exceção abaixo, para que você ainda não é necessário limpar explicitamente.  
  
## <a name="see-also"></a>Consulte também  
 [Cadeias de caracteres (ATL/MFC)](../atl-mfc-shared/strings-atl-mfc.md)   
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

