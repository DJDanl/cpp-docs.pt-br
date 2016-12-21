---
title: "Classe hash_compare | Microsoft Docs"
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
  - "hash_set/stdext::hash_compare"
  - "std.hash_compare"
  - "hash_compare"
  - "std::hash_compare"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe hash_compare"
ms.assetid: d502bb59-de57-4585-beb9-00e3a998c0af
caps.latest.revision: 21
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe hash_compare
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que pode ser usado por qualquer um dos contêineres associativos hash — hash\_map, hash\_multimap, hash\_set, ou hash\_multiset — como um padrão**características**o objeto de parâmetro para solicitar e os elementos que contêm o hash.  
  
## Sintaxe  
  
```  
template<class Key, class Traits = less<Key> >  
   class hash_compare  
   {  
   Traits comp;  
public:  
   const size_t bucket_size = 4;  
   const size_t min_buckets = 8;  
   hash_compare( );  
   hash_compare( Traits pred );  
   size_t operator( )( const Key& _Key ) const;  
   bool operator( )(   
      const Key& _Key1,  
      const Key& _Key2  
   ) const;  
   };  
```  
  
## Comentários  
 Cada contêiner associativo hash armazena um objeto de características de hash do tipo**características**\(um parâmetro de modelo\).  Você pode derivar uma classe de uma especialização de hash\_compare substituir seletivamente certas funções e objetos, ou você pode fornecer sua própria versão desta classe se você atender a determinados requisitos mínimos.  Especificamente, para hash\_comp um objeto do tipo**hash\_compare \< chave, características \>**o seguinte comportamento é necessária para os contêineres acima:  
  
-   Todos os valores de`_Key`do tipo**chave**a chamada**hash\_comp**\(`_Key`\) serve como uma função de hash, que produz uma distribuição de valores do tipo**size\_t**.  Retorna a função fornecida pelo hash\_compare`_Key`.  
  
-   Para qualquer valor`_Key1`do tipo**chave**que precede`_Key2`na seqüência e tem o mesmo hash \(valor retornado pela função de hash\),**hash\_comp**\(`_Key2``_Key1`\) é false.  A função deve impor um total de pedidos em valores do tipo**chave**.  Retorna a função fornecida pelo hash\_compare*comp*\(`_Key2``_Key1`\)`,`onde*comp*é um objeto armazenado do tipo**características**que você pode especificar quando você constrói o objeto hash\_comp.  Para o padrão**características**tipo de parâmetro**menos \< chave \>**chaves de classificação nunca diminuem em valor.  
  
-   A constante de inteiro**bucket\_size**Especifica o número médio de elementos por "bucket" \(entrada de tabela de hash\) que o contêiner deve tentar não deve exceder.  Deve ser maior que zero.  O valor fornecido por hash\_compare é 4.  
  
-   A constante de inteiro**min\_buckets**Especifica o número mínimo de buckets para manter a tabela de hash.  Ele deve ser uma potência de dois e maior que zero.  O valor fornecido por hash\_compare é 8.  
  
 No Visual C\+\+ .NET 2003, membros de[\< hash\_map \>](../standard-library/hash-map.md)e[\< hash\_set \>](../standard-library/hash-set.md)arquivos de cabeçalho não estão mais no namespace padrão, mas em vez disso, foram movidos para o namespace stdext.  Consulte [O namespace stdext](../Topic/stdext%20Namespace.md) para obter mais informações.  
  
## Exemplo  
 Consulte exemplos de[hash\_map:: hash\_map](../Topic/hash_map::hash_map.md)[hash\_multimap:: hash\_multimap](../Topic/hash_multimap::hash_multimap.md)[hash\_set:: hash\_set](../Topic/hash_set::hash_set.md)e[hash\_multiset:: hash\_multiset](../Topic/hash_multiset::hash_multiset.md)para obter exemplos de como declarar e usar hash\_compare.  
  
## Requisitos  
 **Cabeçalho:**\< hash\_map \>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)