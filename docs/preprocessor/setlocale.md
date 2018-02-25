---
title: setlocale | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- setlocale_CPP
- vc-pragma.setlocale
dev_langs:
- C++
helpviewer_keywords:
- pragmas, setlocale
- setlocale pragma
ms.assetid: e60b43d9-fbdf-4c4e-ac85-805523a13b86
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c52697fffb27e6fd25936f3c6566f027cc265c18
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="setlocale"></a>setlocale
Define a localidade (país/região e idioma) que será usada na tradução de literais de cadeia de caracteres e constantes de caracteres amplos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma setlocale( "[locale-string]" )  
```  
  
## <a name="remarks"></a>Comentários  
 Como o algoritmo para converter caracteres multibyte para caracteres amplos pode variar de acordo com a localidade ou a compilação pode ocorrer em uma localidade diferente de onde um arquivo executável será executado, esse pragma fornece uma maneira de especificar a localidade de destino no momento da compilação. Isso garante que as cadeias de caracteres amplos sejam armazenadas no formato correto.  
  
 O padrão *cadeia de caracteres de localidade* é "".  
  
 A localidade “C” mapeia cada caractere na cadeia de caracteres com seu valor como `wchar_t` (curta sem assinatura). Outros valores que são válidos para `setlocale` são aquelas entradas que são encontradas no [cadeias de caracteres do idioma](../c-runtime-library/language-strings.md) lista. Por exemplo, você pode emitir:  
  
```  
#pragma setlocale("dutch")  
```  
  
 A capacidade de emitir uma cadeia de caracteres de idioma depende da página de código e do suporte à ID de idioma no seu computador.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)