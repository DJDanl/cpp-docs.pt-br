---
title: Classe value_compare (&lt;map&gt;) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::value_compare
- std.value_compare
- map/std::value_compare
- value_compare
dev_langs: C++
helpviewer_keywords: std::value_compare
ms.assetid: ea97c1d0-04b2-4d42-8d96-23522c04cc41
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: dedc859a140b99d76b98a5109f9fdc56c1c1f90c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="valuecompare-class-ltmapgt"></a>Classe value_compare (&lt;map&gt;)
Fornece um objeto de função que pode comparar os elementos de um mapa ao comparar os valores de suas chaves para determinar sua ordem relativa no mapa.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class value_compare : public binary_function<value_type, value_type, bool>
{
public:
    bool operator()(const value_type& left, const value_type& right) const;
    value_compare(key_compare pred) : comp(pred);
protected:
    key_compare comp;
};
```  
  
## <a name="remarks"></a>Comentários  
 O critério de comparação fornecido por `value_compare` entre **value_types** de elementos inteiros contidos por um mapa é induzido de uma comparação entre as chaves dos respectivos elementos pela construção da classe auxiliar. O operador da função membro usa o objeto **comp** do tipo `key_compare` armazenado no objeto de função fornecido por `value_compare` para comparar os componentes da chave de classificação de dois elementos.  
  
 Para conjuntos e multiconjuntos, que são contêineres simples nos quais os valores de chave são idênticos aos valores dos elementos, `value_compare` é equivalente a `key_compare`; para mapas e multimapas eles não são, uma vez que o valor dos elementos do tipo `pair` não é idêntico ao valor da chave do elemento.  
  
## <a name="example"></a>Exemplo  
  Consulte o exemplo de [value_comp](../standard-library/map-class.md#value_comp) para obter um exemplo de como declarar e usar `value_compare`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<map>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Struct binary_function](../standard-library/binary-function-struct.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



