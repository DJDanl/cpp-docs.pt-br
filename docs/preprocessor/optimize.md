---
title: otimizar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.optimize
- optimize_CPP
dev_langs:
- C++
helpviewer_keywords:
- pragmas, optimize
- optimize pragma
ms.assetid: cb13c1cc-186a-45bc-bee7-95a8de7381cc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bff0e4cc40bfa0e355f348c02f01cb0c7445b596
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849243"
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