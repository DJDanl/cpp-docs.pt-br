---
title: 'TN032: Mecanismo de exceção MFC'
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.exceptions
helpviewer_keywords:
- TN032
- MFC, exceptions
- CException class [MFC], using
ms.assetid: 0271f0aa-82cb-47a2-b7ea-e88126fc7e43
ms.openlocfilehash: 210e47e117cd602ba77edd330205385f54199ce5
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57288747"
---
# <a name="tn032-mfc-exception-mechanism"></a>TN032: Mecanismo de exceção MFC

As versões anteriores do Visual C++ não oferecia suporte para o mecanismo de exceção padrão do C++ e MFC fornecido macros **TRY/CATCH/THROW** que foram usados em vez disso. Esta versão do Visual C++ totalmente compatível com as exceções do C++. Essa observação abordado alguns detalhes de implementação avançada das macros anteriores incluindo como limpar automaticamente a objetos de pilha com base. Porque as exceções do C++ dá suporte a pilha de desenrolamento por padrão, essa observação técnica não é mais necessária.

Consulte [exceções: Usando Macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) para obter mais informações sobre as diferenças entre as macros MFC e as novas palavras-chave do C++.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
