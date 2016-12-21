---
title: "Instru&#231;&#227;o __if_not_exists | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__if_not_exists"
  - "__if_not_exists_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __if_not_exists [C++]"
ms.assetid: a2f322d4-e96f-4a32-954e-4323d20c6e32
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o __if_not_exists
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução `__if_not_exists` testa se o identificador especificado existe.  Se o identificador especificado não existir, o bloco de instrução especificado é executado.  
  
## Sintaxe  
  
```  
__if_not_exists ( identifier ) {   
statements  
};  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`identifier`|O identificador cuja existência você deseja testar.|  
|`statements`|Uma ou mais instruções a serem executadas se `identifier` não existir.|  
  
## Comentários  
  
> [!CAUTION]
>  Para obter os resultados mais confiáveis, use a instrução `__if_not_exists` sob as seguintes restrições.  
  
-   Aplique a instrução `__if_not_exists` apenas em tipos simples, não em modelos.  
  
-   Aplique a instrução `__if_not_exists` aos identificadores dentro ou fora de uma classe.  Não aplique a instrução `__if_not_exists` às variáveis locais.  
  
-   Use a instrução `__if_not_exists` somente no corpo de uma função.  Fora do corpo de uma função, a instrução `__if_not_exists` pode testar apenas tipos totalmente definidos.  
  
-   Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.  
  
 O complemento à instrução `__if_not_exists` é a instrução [\_\_if\_exists](../cpp/if-exists-statement.md).  
  
## Exemplo  
 Para obter um exemplo de como usar `__if_not_exists`, consulte [Instrução \_\_if\_exists](../cpp/if-exists-statement.md).  
  
## Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Instrução \_\_if\_exists](../cpp/if-exists-statement.md)