---
title: 'TN032: mecanismo de exceção MFC'
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.exceptions
helpviewer_keywords:
- TN032
- MFC, exceptions
- CException class [MFC], using
ms.assetid: 0271f0aa-82cb-47a2-b7ea-e88126fc7e43
ms.openlocfilehash: f3f13bb40151d3b9ef0d57c7e769ca30fa629177
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50633380"
---
# <a name="tn032-mfc-exception-mechanism"></a>TN032: mecanismo de exceção MFC

As versões anteriores do Visual C++ não oferecia suporte para o mecanismo de exceção padrão do C++ e MFC fornecido macros **TRY/CATCH/THROW** que foram usados em vez disso. Esta versão do Visual C++ totalmente compatível com as exceções do C++. Essa observação abordado alguns detalhes de implementação avançada das macros anteriores incluindo como limpar automaticamente a objetos de pilha com base. Porque as exceções do C++ dá suporte a pilha de desenrolamento por padrão, essa observação técnica não é mais necessária.

Consulte a [exceções: usando Macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) para obter mais informações sobre as diferenças entre as macros MFC e as novas palavras-chave do C++.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

