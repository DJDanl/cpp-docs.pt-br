---
title: "Classe value_compare (&lt;map&gt;) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::value_compare"
  - "std.value_compare"
  - "map/std::value_compare"
  - "value_compare"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe value_compare"
ms.assetid: ea97c1d0-04b2-4d42-8d96-23522c04cc41
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe value_compare (&lt;map&gt;)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fornece um objeto de função que pode comparar os elementos de um mapa comparando os valores das chaves para determinar a ordem relativa no mapa.  
  
## Sintaxe  
  
```  
class value_compare : public binary_function<value_type, value_type, bool>  
{  
public:  
   bool operator()(const value_type& _Left, const value_type& _Right) const;  
   value_compare(key_compare _Pred) : comp(_Pred);  
   protected:  
      key_compare comp;  
};  
```  
  
## Comentários  
 O critério de comparação fornecido por `value_compare` entre **value\_types** inteiros dos elementos contidos por um mapa é induzido de uma comparação entre as chaves dos elementos respectivos pela construção auxiliar da classe.  O operador da função de membro usa o objeto **comp** do tipo `key_compare` armazenado no objeto da função fornecido por `value_compare` para comparar os componentes do tipo chave de dois elementos.  
  
 Para os clusters e os multisets, que são contêineres simples em que os valores de chave são idênticos aos valores de elemento, `value_compare` é equivalente a `key_compare`; para mapas e não são multimaps, porque o valor dos elementos de `pair` de tipo não é idêntico ao valor da chave do elemento.  
  
## Exemplo  
 Consulte o exemplo de [value\_comp](../Topic/map::value_comp.md) para obter um exemplo de como declarar e usar `value_compare`.  
  
## Requisitos  
 mapa \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Struct binary\_function](../Topic/binary_function%20Struct.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)