---
title: setlocale | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fa6ba2bec5c862bb336d4b9bea0f47aad91fe0c1
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42538200"
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
  
A localidade "C" mapeia cada caractere na cadeia de caracteres para seu valor como um **wchar_t** (curto sem sinal). Outros valores válidos para `setlocale` são as entradas que se encontram em de [cadeias de caracteres de idioma](../c-runtime-library/language-strings.md) lista. Por exemplo, você pode emitir:  
  
```  
#pragma setlocale("dutch")  
```  
  
A capacidade de emitir uma cadeia de caracteres de idioma depende da página de código e do suporte à ID de idioma no seu computador.  
  
## <a name="see-also"></a>Consulte também  
 
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)