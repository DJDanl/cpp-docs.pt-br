---
title: "TN032: Mecanismo de exceção MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.mfc.exceptions
dev_langs: C++
helpviewer_keywords:
- TN032
- MFC, exceptions
- CException class [MFC], using
ms.assetid: 0271f0aa-82cb-47a2-b7ea-e88126fc7e43
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d2be26d5a3c5ab456d745119d540276edeed2d0e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="tn032-mfc-exception-mechanism"></a>TN032: mecanismo de exceção MFC
Versões anteriores do Visual C++ não oferecia suporte para o mecanismo de exceção padrão do C++ e MFC fornecido macros **TRY/CATCH/THROW** que foram usados. Esta versão do Visual C++ totalmente dá suporte a exceções C++. Esta anotação coberto alguns dos detalhes de implementação avançada de macros anteriores incluindo como objetos de pilha com base em limpeza automaticamente. Como as exceções do C++ oferecem suporte a pilha de desenrolamento por padrão, essa observação técnica não é mais necessária.  
  
 Consulte [exceções: usando Macros de MFC e exceções de C++](../mfc/exceptions-using-mfc-macros-and-cpp-exceptions.md) para obter mais informações sobre as diferenças entre as macros MFC e as novas palavras-chave C++.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

