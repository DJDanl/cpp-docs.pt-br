---
title: otimizar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc-pragma.optimize
- optimize_CPP
dev_langs: C++
helpviewer_keywords:
- pragmas, optimize
- optimize pragma
ms.assetid: cb13c1cc-186a-45bc-bee7-95a8de7381cc
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 35b5147b3561df409906af9134ae4ec921a7d16b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="optimize"></a>optimize
Especifica as otimizações a serem executadas em uma base de função por função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma optimize( "[optimization-list]", {on | off} )  
```  
  
## <a name="remarks"></a>Comentários  
 O **otimizar** pragma deve aparecer fora de uma função e entra em vigor na primeira função definida após o pragma é visto. O **na** e **off** argumentos ativar opções especificadas no *otimização lista* ativado ou desativado.  
  
 O *otimização lista* pode ser zero ou mais dos parâmetros mostrados na tabela a seguir.  
  
### <a name="parameters-of-the-optimize-pragma"></a>Parâmetros do pragma de otimização  
  
|Parâmetro(s)|Tipo de otimização|  
|--------------------|--------------------------|  
|**g**|Habilita as otimizações globais.|  
|**s** ou **t**|Especifica sequências curtas ou rápidas de código de máquina.|  
|**y**|Gera ponteiros de quadro na pilha de programa.|  
  
 Essas são as mesmas letras usadas com o [/O](../build/reference/o-options-optimize-code.md) opções do compilador. Por exemplo, o seguinte pragma é equivalente ao **/Os** opção de compilador:  
  
```  
#pragma optimize( "ts", on )  
```  
  
 Usando o **otimizar** pragma com a cadeia de caracteres vazia (**""**) é uma forma especial da diretiva:  
  
 Quando você usa o **off** parâmetro, ele transforma as otimizações, listadas na tabela neste tópico, off.  
  
 Quando você usa o **na** parâmetro, ele redefine as otimizações para aqueles que você especificou com o [/O](../build/reference/o-options-optimize-code.md) opção de compilador.  
  
```  
#pragma optimize( "", off )  
.  
.  
.  
#pragma optimize( "", on )   
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)