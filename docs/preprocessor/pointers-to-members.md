---
title: pointers_to_members | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4313aaa38d410b8e6f46594cd9ce11269b523073
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="pointerstomembers"></a>pointers_to_members
**Específicas do C++**  
  
 Especifica se um ponteiro para um membro da classe pode ser declarado antes de sua definição de classe associada e é usado para controlar o tamanho do ponteiro e o código necessários para interpretar o ponteiro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma pointers_to_members( pointer-declaration, [most-general-representation] )  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode colocar um **pointers_to_members** pragma no arquivo de origem como uma alternativa ao uso de [/vmx](../build/reference/vmb-vmg-representation-method.md) opções do compilador ou [palavras-chave de herança](../cpp/inheritance-keywords.md).  
  
 O *ponteiro declaração* argumento especifica se você declarar um ponteiro para um membro antes ou depois da definição de função associada. O *ponteiro declaração* argumento é uma das duas seguintes símbolos:  
  
|Argumento|Comentários|  
|--------------|--------------|  
|**full_generality**|Gerencia o código seguro, às vezes não ideal. Você usa **full_generality** se qualquer ponteiro para um membro é declarado antes da definição de classe associada. Esse argumento sempre usa a representação de ponteiro especificada pelo *maioria de geral de representação* argumento. Equivalente a /vmg.|  
|**best_case**|Gera o código seguro, ideal usando a melhor representação de letras maiúsculas e minúsculas para todos os ponteiros dos membros. Requer a definição da classe antes de declarar um ponteiro para um membro da classe. O padrão é **best_case**.|  
  
 O *maioria de geral de representação* argumento especifica a representação de ponteiro menor que o compilador pode usar com segurança para fazer referência a qualquer ponteiro para um membro de uma classe em uma unidade de conversão. O argumento pode ser um destes:  
  
|Argumento|Comentários|  
|--------------|--------------|  
|**single_inheritance**|A representação mais geral é de herança única, ponteiro para uma função de membro. Causa um erro se o modelo de herança de uma definição de classe para a qual um ponteiro para um membro é declarado nunca for múltiplo ou virtual.|  
|**multiple_inheritance**|A representação mais geral é de herança múltipla, ponteiro para uma função de membro. Causa um erro se o modelo de herança de uma definição de classe para a qual um ponteiro para um membro é declarado nunca for virtual.|  
|**virtual_inheritance**|A representação mais geral é de herança virtual, ponteiro para uma função de membro. Nunca causa um erro. Esse é o argumento padrão quando **#pragma pointers_to_members(full_generality)** é usado.|  
  
> [!CAUTION]
>  Nós recomendamos que você coloque o pragma `pointers_to_members` somente no arquivo de origem que deseja afetar e somente depois de todas políticas de `#include`. Essa prática diminui o risco de o pragma afetar outros arquivos e de você especificar acidentalmente várias definições para a mesma variável, função, ou nome da classe.  
  
## <a name="example"></a>Exemplo  
  
```  
//   Specify single-inheritance only  
#pragma pointers_to_members( full_generality, single_inheritance )  
```  
  
## <a name="end-c-specific"></a>FIM de Específico do C++  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)