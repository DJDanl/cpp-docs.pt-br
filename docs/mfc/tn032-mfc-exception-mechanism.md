---
title: 'TN032: Mecanismo de exceção do MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.exceptions
dev_langs:
- C++
helpviewer_keywords:
- TN032
- MFC, exceptions
- CException class [MFC], using
ms.assetid: 0271f0aa-82cb-47a2-b7ea-e88126fc7e43
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: aee8ce02af874e1c3c30243a35e8f36acfce63f0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46414752"
---
# <a name="tn032-mfc-exception-mechanism"></a>TN032: mecanismo de exceção MFC

As versões anteriores do Visual C++ não oferecia suporte para o mecanismo de exceção padrão do C++ e MFC fornecido macros **TRY/CATCH/THROW** que foram usados em vez disso. Esta versão do Visual C++ totalmente compatível com as exceções do C++. Essa observação abordado alguns detalhes de implementação avançada das macros anteriores incluindo como limpar automaticamente a objetos de pilha com base. Porque as exceções do C++ dá suporte a pilha de desenrolamento por padrão, essa observação técnica não é mais necessária.

Consulte a [exceções: usando Macros MFC e exceções do C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) para obter mais informações sobre as diferenças entre as macros MFC e as novas palavras-chave do C++.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

