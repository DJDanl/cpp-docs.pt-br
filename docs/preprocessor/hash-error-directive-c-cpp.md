---
title: '#Erro de diretiva (C/C++) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- '#error'
dev_langs:
- C++
helpviewer_keywords:
- '#error directive'
- preprocessor, directives
- error directive (#error directive)
ms.assetid: d550a802-ff19-4347-9597-688935d23b2b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e449da64b5221ccddee34dd850a987b28a2f39df
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="error-directive-cc"></a>Diretiva #error (C/C++)
A política `#error` emite uma mensagem de erro especificada pelo usuário em tempo de compilação e finaliza a compilação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#errortoken-string  
```  
  
## <a name="remarks"></a>Comentários  
 A mensagem de erro que essa diretiva emite inclui o *cadeia de caracteres de token* parâmetro. O parâmetro `token-string` não está sujeito à expansão macro. Essa política é mais útil durante o pré-processamento para notificar o desenvolvedor de uma inconsistência do programa ou de uma violação de restrição. O exemplo a seguir demonstra o processamento do erro durante pré-processamento:  
  
```  
#if !defined(__cplusplus)  
#error C++ compiler required.  
#endif  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)