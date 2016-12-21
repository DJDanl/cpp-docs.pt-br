---
title: "Declara&#231;&#227;o do &#237;ndice de propriedade | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "índices padrão"
  - "padrões, indexadores"
  - "propriedades indexadas, C++"
  - "indexadores"
ms.assetid: d898fdbc-2106-4b6a-8c5c-9f511d80fc2f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#227;o do &#237;ndice de propriedade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A sintaxe para declarar uma propriedade indexada foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 O defeito dois primário de suporte gerenciado de linguagem DMX de propriedades indexadas é a incapacidade fornecer a subscrição classe de nível; ou seja, todas as propriedades indexadas são necessárias para receber um nome, e assim não há como, por exemplo, de fornecer um operador subscrito gerenciado que pode ser aplicado diretamente a um objeto da classe de `Vector` ou de `Matrix` .  Um defeito menos significativo do segundo é visualmente que é difícil distinguir uma propriedade de uma propriedade indexada – o número de parâmetros é a única indicação.  Finalmente, as propriedades indexadas sofrem dos mesmos problemas que as de propriedades não indexadas – os acessadores não são tratados como uma unidade atômica, mas são separados em métodos individuais.  Por exemplo:  
  
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
  
 Como você pode ver aqui, os indicadores só são diferenciados pelos parâmetros adicionais para especificar um ou dois para escolher o índice da dimensão.  Na nova sintaxe, os indicadores são distinguidos por colchetes \(\[\]\), depois do nome do medidor e de indicar o número e o tipo de cada índice:  
  
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
  
 Para indicar um indicador de nível da classe que possa ser aplicado diretamente aos objetos da classe na nova sintaxe, a palavra\-chave de `default` é reutilizado para substituir um nome explícito.  Por exemplo:  
  
```  
public ref class Matrix {  
private:  
   array<float, 2>^ mat;  
  
public:  
   // ok: class level indexer now  
   //  
   //     Matrix mat …  
   //     mat[ 0, 0 ] = 1;   
   //  
   // invokes the set accessor of the default indexer …  
  
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
  
 Na nova sintaxe, quando a propriedade indexada opção for especificada, os dois seguintes nomes são permitidas: `get_Item` e `set_Item`.  Isso é porque esses são os nomes subjacentes gerados para a propriedade indexada padrão.  
  
 Observe que não há nenhuma sintaxe simples de índice análoga à sintaxe simples da propriedade.  
  
## Consulte também  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [Como usar propriedades indexadas](../misc/how-to-use-indexed-properties.md)