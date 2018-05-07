---
title: Declaração de propriedade de índice | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- indexers
- default indexers
- defaults, indexers
- indexed properties, C++
ms.assetid: d898fdbc-2106-4b6a-8c5c-9f511d80fc2f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 76473ce04cdf5860476b7612ddcbf00b40a0fae1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="property-index-declaration"></a>Declaração do índice de propriedade
A sintaxe para declarar uma propriedade indexada foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 O dois a desvantagem primária do suporte de idioma das extensões gerenciadas de propriedades indexadas é a incapacidade de fornecer o nível de classe de subscrito; ou seja, todas as propriedades indexadas são necessárias para receber um nome e, portanto, não é possível, por exemplo, para fornecer um operador de subscrito gerenciado que pode ser aplicado diretamente a um `Vector` ou `Matrix` objeto de classe. Um segundo menos significativa desvantagem é que é difícil visualmente distinguir uma propriedade de uma propriedade indexada - o número de parâmetros é a única indicação. Por fim, os mesmos problemas que as propriedades indexadas não tem propriedades indexadas - acessadores não são tratados como uma unidade atômica, mas separados em métodos individuais.  Por exemplo:  
  
```  
public __gc class Vector;  
public __gc class Matrix {  
   float mat[,];  
  
public:   
   __property void set_Item( int r, int c, float value);  
   __property float get_Item( int r, int c );  
  
   __property void set_Row( int r, Vector* value );  
   __property Vector* get_Row( int r );  
};  
```  
  
 Como você pode ver aqui, os indexadores se diferenciam apenas pelos parâmetros adicionais para especificar um, dois ou um único índice de dimensão. Na nova sintaxe, os indexadores são diferenciados por colchetes ([,]) após o nome do indexador e indicando o número e tipo de cada índice:  
  
```  
public ref class Vector {};  
public ref class Matrix {  
private:  
   array<float, 2>^ mat;  
  
public:  
   property float Item [int,int] {  
      float get( int r, int c );  
      void set( int r, int c, float value );  
   }  
  
   property Vector^ Row [int] {  
      Vector^ get( int r );  
      void set( int r, Vector^ value );  
   }  
};  
```  
  
 Para indicar um indexador de nível de classe pode ser aplicado diretamente a objetos da classe na nova sintaxe, o `default` palavra-chave é reutilizado para substituir um nome explícito. Por exemplo:  
  
```  
public ref class Matrix {  
private:  
   array<float, 2>^ mat;  
  
public:  
   // ok: class level indexer now  
   //  
   //     Matrix mat;  
   //     mat[ 0, 0 ] = 1;   
   //  
   // invokes the set accessor of the default indexer  
  
   property float default [int,int] {  
      float get( int r, int c );  
      void set( int r, int c, float value );  
   }  
  
   property Vector^ Row [int] {  
      Vector^ get( int r );  
      void set( int r, Vector^ value );  
   }  
};  
```  
  
 Na nova sintaxe, quando o padrão é indexado propriedade for especificada, os dois nomes a seguir são reservados: `get_Item` e `set_Item`. Isso ocorre porque esses são os nomes subjacentes gerados para a propriedade indexada padrão.  
  
 Observe que nenhuma sintaxe simples de índice é semelhante à sintaxe de propriedade simples.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 