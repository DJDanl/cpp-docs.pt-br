---
title: srand | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- srand
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-utility-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- srand
dev_langs:
- C++
helpviewer_keywords:
- random starting point
- random starting point, setting
- random numbers, generating
- srand function
- numbers, pseudorandom
- numbers, random
- pseudorandom numbers
- starting points, setting random
- starting points
ms.assetid: 7bf56dc5-5692-4182-a3c1-18af98d2dd1a
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 4b66807016325bd363627fc1104bedb7b980cc83
ms.lasthandoff: 02/25/2017

---
# <a name="srand"></a>srand
Define o valor de semente inicial para o gerador de números pseudoaleatórios.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void srand(  
   unsigned int seed   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `seed`  
 Semente para geração de números pseudoaleatórios  
  
## <a name="remarks"></a>Comentários  
 A função `srand` define o ponto de partida para gerar uma série de inteiros pseudoaleatórios no thread atual. Para reinicializar o gerador para criar a mesma sequência de resultados, chame a função `srand` e use o mesmo argumento `seed` novamente. Qualquer outro valor de `seed` define o gerador para um ponto de partida diferente na sequência de números pseudoaleatórios. `rand` recupera os números pseudoaleatórios que são gerados. Chamar `rand` antes de qualquer chamada para `srand` gera a mesma sequência que chamar `srand` com `seed` passado como 1.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`srand`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [rand](../../c-runtime-library/reference/rand.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [Classe System::Random](https://msdn.microsoft.com/en-us/library/system.random.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [rand](../../c-runtime-library/reference/rand.md)
