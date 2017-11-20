---
title: "instrução if_not_exists | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: __if_not_exists_cpp
dev_langs: C++
helpviewer_keywords: __if_not_exists keyword [C++]
ms.assetid: a2f322d4-e96f-4a32-954e-4323d20c6e32
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 5bd11ed833b54082d7ea2a394bdd4cad3c3e1321
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ifnotexists-statement"></a>Instrução __if_not_exists
A instrução `__if_not_exists` testa se o identificador especificado existe. Se o identificador especificado não existir, o bloco de instrução especificado é executado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__if_not_exists ( identifier ) {   
statements  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`identifier`|O identificador cuja existência você deseja testar.|  
|`statements`|Uma ou mais instruções para executar se `identifier` não existe.|  
  
## <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Para obter os resultados mais confiáveis, use a instrução `__if_not_exists` sob as seguintes restrições.  
  
-   Aplique a instrução `__if_not_exists` apenas em tipos simples, não em modelos.  
  
-   Aplique a instrução `__if_not_exists` aos identificadores dentro ou fora de uma classe. Não aplique a instrução `__if_not_exists` às variáveis locais.  
  
-   Use a instrução `__if_not_exists` somente no corpo de uma função. Fora do corpo de uma função, a instrução `__if_not_exists` pode testar apenas tipos totalmente definidos.  
  
-   Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.  
  
 O complemento para o `__if_not_exists` instrução é a [if_exists](../cpp/if-exists-statement.md) instrução.  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo sobre como usar `__if_not_exists`, consulte [if_exists instrução](../cpp/if-exists-statement.md).  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução __if_exists](../cpp/if-exists-statement.md)