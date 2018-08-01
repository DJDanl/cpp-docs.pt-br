---
title: instrução if_not_exists | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __if_not_exists_cpp
dev_langs:
- C++
helpviewer_keywords:
- __if_not_exists keyword [C++]
ms.assetid: a2f322d4-e96f-4a32-954e-4323d20c6e32
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bee63ace276863a30c4ec81d970ba3bf5fd29e40
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39405279"
---
# <a name="ifnotexists-statement"></a>Instrução __if_not_exists
O **if_not_exists** instrução testa se o identificador especificado existe. Se o identificador especificado não existir, o bloco de instrução especificado é executado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__if_not_exists ( identifier ) {   
statements  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*identifier*|O identificador cuja existência você deseja testar.|  
|*Instruções*|Um ou mais instruções a executar se *identificador* não existe.|  
  
## <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Para obter os resultados mais confiáveis, use o **if_not_exists** instrução sob as restrições a seguir.  
  
-   Aplicar a **if_not_exists** instrução apenas em tipos simples, e não por modelos.  
  
-   Aplicar a **if_not_exists** instrução para identificadores dentro ou fora de uma classe. Não se aplicam a **if_not_exists** instrução para variáveis locais.  
  
-   Use o **if_not_exists** instrução somente no corpo de uma função. Fora do corpo de uma função, o **if_not_exists** instrução pode testar apenas tipos totalmente definidos.  
  
-   Quando você testa funções sobrecarregadas, não é possível testar um formato específico de sobrecarga.  
  
 O complemento para o **if_not_exists** instrução é a [if_exists](../cpp/if-exists-statement.md) instrução.  
  
## <a name="example"></a>Exemplo  
 Para obter um exemplo sobre como usar **if_not_exists**, consulte [if_exists instrução](../cpp/if-exists-statement.md).  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução __if_exists](../cpp/if-exists-statement.md)