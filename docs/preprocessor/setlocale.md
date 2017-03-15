---
title: "setlocale | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "setlocale_CPP"
  - "vc-pragma.setlocale"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragmas, setlocale"
  - "pragma setlocale"
ms.assetid: e60b43d9-fbdf-4c4e-ac85-805523a13b86
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# setlocale
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define a localidade \(país\/região e idioma\) que será usada na tradução de literais de cadeia de caracteres e constantes de caracteres amplos.  
  
## Sintaxe  
  
```  
  
#pragma setlocale( "[locale-string]" )  
```  
  
## Comentários  
 Como o algoritmo para converter caracteres multibyte para caracteres amplos pode variar de acordo com a localidade ou a compilação pode ocorrer em uma localidade diferente de onde um arquivo executável será executado, esse pragma fornece uma maneira de especificar a localidade de destino no momento da compilação.  Isso garante que as cadeias de caracteres amplos sejam armazenadas no formato correto.  
  
 A *cadeia de caracteres de localidade* padrão é "".  
  
 A localidade “C” mapeia cada caractere na cadeia de caracteres com seu valor como `wchar_t` \(curta sem assinatura\).  Outros valores válidos para `setlocale` são as entradas encontradas na lista de [Cadeias de caracteres de idioma](../c-runtime-library/language-strings.md).  Por exemplo, você pode emitir:  
  
```  
#pragma setlocale("dutch")  
```  
  
 A capacidade de emitir uma cadeia de caracteres de idioma depende da página de código e do suporte à ID de idioma no seu computador.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)