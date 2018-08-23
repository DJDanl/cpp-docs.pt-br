---
title: pointers_to_members | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- pointers_to_members_CPP
- vc-pragma.pointers_to_members
dev_langs:
- C++
helpviewer_keywords:
- class members, pointers to
- pragmas, pointers_to_members
- members, pointers to
- pointers_to_members pragma
ms.assetid: 8325428c-c90a-4aed-9e82-cb1dda23f4ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 09b0fcd2a00806d075e70d1469b57ba0a0dd5332
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42539348"
---
# <a name="pointerstomembers"></a>pointers_to_members
**Específico do C++**  
  
Especifica se um ponteiro para um membro da classe pode ser declarado antes de sua definição de classe associada e é usado para controlar o tamanho do ponteiro e o código necessários para interpretar o ponteiro.  
  
## <a name="syntax"></a>Sintaxe  
  
```    
#pragma pointers_to_members( pointer-declaration, [most-general-representation] )  
```  
  
## <a name="remarks"></a>Comentários  
 
Você pode colocar uma **pointers_to_members** pragma no arquivo de origem como uma alternativa ao uso de [/vmx](../build/reference/vmb-vmg-representation-method.md) opções do compilador ou o [palavras-chave de herança](../cpp/inheritance-keywords.md).  
  
O *declaração de ponteiro* argumento especifica se você declarou um ponteiro para um membro antes ou após a definição de função associada. O *declaração de ponteiro* argumento é um dos dois símbolos a seguir:  
  
|Argumento|Comentários|  
|--------------|--------------|  
|*full_generality*|Gerencia o código seguro, às vezes não ideal. Você usa *full_generality* se qualquer ponteiro para um membro for declarado antes da definição de classe associada. Este argumento sempre usa a representação de ponteiro especificada pelo *most-general-representation* argumento. Equivalente a /vmg.|  
|*best_case*|Gera o código seguro, ideal usando a melhor representação de letras maiúsculas e minúsculas para todos os ponteiros dos membros. Requer a definição da classe antes de declarar um ponteiro para um membro da classe. O padrão é *best_case*.|  
  
O *most-general-representation* argumento especifica a menor representação de ponteiro que o compilador pode seguramente usar para referenciar qualquer ponteiro para um membro de uma classe em uma unidade de tradução. O argumento pode ser um destes:  
  
|Argumento|Comentários|  
|--------------|--------------|  
|*single_inheritance*|A representação mais geral é de herança única, ponteiro para uma função de membro. Causa um erro se o modelo de herança de uma definição de classe para a qual um ponteiro para um membro é declarado nunca for múltiplo ou virtual.|  
|*multiple_inheritance*|A representação mais geral é de herança múltipla, ponteiro para uma função de membro. Causa um erro se o modelo de herança de uma definição de classe para a qual um ponteiro para um membro é declarado nunca for virtual.|  
|*virtual_inheritance*|A representação mais geral é de herança virtual, ponteiro para uma função de membro. Nunca causa um erro. Esse é o argumento padrão quando `#pragma pointers_to_members(full_generality)` é usado.|  
  
> [!CAUTION]
> Aconselhamos que você coloque os **pointers_to_members** pragma somente no arquivo de código de origem que você deseja afetar e somente após qualquer `#include` diretivas. Essa prática diminui o risco de o pragma afetar outros arquivos e de você especificar acidentalmente várias definições para a mesma variável, função, ou nome da classe.  
  
## <a name="example"></a>Exemplo  
  
```  
//   Specify single-inheritance only  
#pragma pointers_to_members( full_generality, single_inheritance )  
```  
  
## <a name="end-c-specific"></a>FIM de Específico do C++  
  
## <a name="see-also"></a>Consulte também  
 
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)