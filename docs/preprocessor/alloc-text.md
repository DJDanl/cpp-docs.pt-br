---
title: alloc_text | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc-pragma.alloc_text
- alloc_text_CPP
dev_langs: C++
helpviewer_keywords:
- alloc_text pragma
- pragmas, alloc_text
ms.assetid: 1fd7be18-e4f7-4f70-b079-6326f72b871a
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b54008652c036530135ca6d180398cb328fdb2da
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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