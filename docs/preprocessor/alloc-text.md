---
title: alloc_text | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.alloc_text
- alloc_text_CPP
dev_langs:
- C++
helpviewer_keywords:
- alloc_text pragma
- pragmas, alloc_text
ms.assetid: 1fd7be18-e4f7-4f70-b079-6326f72b871a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a1e07b630254d7691321443a74973e06ed50ae2d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33912765"
---
# <a name="alloctext"></a>alloc_text
Nomeia a seção de código onde as definições de função especificadas devem residir. O pragma deve estar entre um declarador de função e a definição de função para as funções nomeadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma alloc_text( "  
textsection  
", function1, ... )  
```  
  
## <a name="remarks"></a>Comentários  
 O **alloc_text** pragma não lida com funções de membro de C++ ou sobrecarregado. É aplicável somente às funções declaradas com vínculo a C — ou seja, as funções declaradas com o **extern "C"** especificação de vinculação. Se você tentar usar esse pragma em uma função com vinculação C++, um erro do compilador será gerado.  
  
 Função endereçamento usando `__based` não é suportada, especificando os locais de seção requer o uso do **alloc_text** pragma. O nome especificado pelo *textsection* devem ser colocados entre aspas duplas.  
  
 O **alloc_text** pragma deve aparecer após as declarações de qualquer uma das funções especificadas e antes das definições dessas funções.  
  
 As funções referenciadas em uma **alloc_text** pragma deve ser definido no mesmo módulo como o pragma. Se isso não for feito e uma função indefinida for compilada posteriormente em uma seção de texto diferente, o erro poderá ou não ser detectado. Embora o programa seja executado corretamente no geral, a função não será alocada nas seções desejadas.  
  
 Outras limitações em **alloc_text** são da seguinte maneira:  
  
-   Não pode ser usado dentro de uma função.  
  
-   Deve ser usado depois que a função é declarada, mas antes de a função ser definida.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)