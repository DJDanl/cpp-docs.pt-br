---
title: loop | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- loop_CPP
- vc-pragma.loop
dev_langs:
- C++
ms.assetid: 6d5bb428-cead-47e7-941d-7513bbb162c7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0850a30c0e0e85cd1d90ba5b2399a295a482a3ce
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444665"
---
# <a name="loop"></a>loop
Controla como o código de loop deverá ser considerado pelo paralelizador automático, e/ou exclui um loop de ser considerado pelo vetorizador automático.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma loop( hint_parallel(n) )  
```  
  
```  
#pragma loop( no_vector )  
```  
  
```  
#pragma loop( ivdep )  
```  
  
### <a name="parameters"></a>Parâmetros  
*hint_parallel(n)*  
Indica que o compilador que esse loop deverá ser paralelizado por *n* threads, onde *n* é um literal de inteiro positivo ou zero. Se *n* for zero, o número máximo de threads é usado em tempo de execução. Esta é uma dica para o compilador, não um comando, e não há nenhuma garantia de que o loop será paralelizado. Se o loop tiver dependências de dados ou problemas estruturais - por exemplo, se o loop for armazenado em um escalar usado além do corpo do loop -, o loop não será paralelizado.  
  
O compilador ignora essa opção, a menos que o [/Qpar](../build/reference/qpar-auto-parallelizer.md) comutador de compilador é especificado.  
  
*no_vector*  
Por padrão, o vetorizador automático está ativo e tentará vetorizar todos os loops que, em sua avaliação, beneficiam-se disso. Especifique este pragma para desabilitar o vetorizador automático para o loop que se segue a ele.  
  
*ivdep*  
Indica que o compilador deverá ignorar as dependências de vetor para esse loop. Use em conjunto com *hint_parallel*.  
  
## <a name="remarks"></a>Comentários  
 
Para usar o **loop** pragma, coloque-o imediatamente antes — não em — uma definição de loop. O pragma entra em vigor para o escopo do loop que se segue a ele. Você pode aplicar vários pragmas a um loop, em qualquer ordem, mas deve declarar cada um em uma instrução pragma separada.  
  
## <a name="see-also"></a>Consulte também  
 
[Paralelização automática e vetorização automática](../parallel/auto-parallelization-and-auto-vectorization.md)<br/>
[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)