---
title: "Funções &lt;random&gt; | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: random/std::generate_canonical
ms.assetid: 2ac9ec59-619b-4b85-a425-f729277c1bc8
helpviewer_keywords: std::generate_canonical
caps.latest.revision: "10"
manager: ghogen
ms.openlocfilehash: 0929e7c6749af19065f42f10ee6c15ab4d4a3e88
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ltrandomgt-functions"></a>Funções &lt;random&gt;
  
##  <a name="generate_canonical"></a>  generate_canonical  
 Retorna um valor de ponto flutuante de uma sequência aleatória.  
  
> [!NOTE]
>  O Padrão ISO C++ determina que essa função deve retornar valores no intervalo [ `0`, `1`). O Visual Studio ainda não é compatível com essa restrição. Como solução alternativa para gerar valores nesse intervalo, use [uniform_real_distribution](../standard-library/uniform-real-distribution-class.md).  
  
```  
template <class RealType, size_t Bits, class Generator>  
RealType generate_canonical(Generator& Gen);
```  
  
### <a name="parameters"></a>Parâmetros  
 `RealType`  
 O tipo integral de ponto flutuante. Para ver os tipos possíveis, consulte [\<random>](../standard-library/random.md).  
  
 `Bits`  
 O gerador de número aleatório.  
  
 `Gen`  
 O gerador de número aleatório.  
  
### <a name="remarks"></a>Comentários  
 A função de modelo chama `operator()` de `Gen` repetidamente e empacota os valores retornados para um valor de ponto flutuante `x` do tipo `RealType`, até coletar o número especificado de bits mantissa em `x`. O número especificado é o menor de `Bits` (que deve ser diferente de zero) e o número total de bits mantissa em `RealType`. A primeira chamada fornece os bits de ordem inferior. A função retorna `x`.  
  
## <a name="see-also"></a>Consulte também  
 [\<random>](../standard-library/random.md)

