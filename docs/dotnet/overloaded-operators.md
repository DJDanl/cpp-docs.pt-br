---
title: "Operadores sobrecarregados | Microsoft Docs"
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
  - "sobrecarga de operador, em uma classe CLR"
  - "operadores [C++], sobrecarga"
ms.assetid: 30391426-afe7-4497-bf22-e4816c1e48c8
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores sobrecarregados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O sobrecarregamento de operador mudou significativamente de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Na declaração de um tipo de referência, por exemplo, em vez de usar a sintaxe nativo de `operator+` , você escreve explicitamente para o nome interno subjacente do operador – nesse caso, `op_Addition`.  Além disso, a invocação de um operador aritmético tiver que ser explicitamente invocada com esse nome, assim impossibilitando os dois benefícios primários de sobrecarregamento de operador: \(a\) a sintaxe intuitiva, e \(b\) a capacidade misturar novos tipos existentes com tipo.  Por exemplo:  
  
```  
public __gc __sealed class Vector {  
public:  
   Vector( double x, double y, double z );  
  
   static bool    op_Equality( const Vector*, const Vector* );  
   static Vector* op_Division( const Vector*, double );  
   static Vector* op_Addition( const Vector*, const Vector* );  
   static Vector* op_Subtraction( const Vector*, const Vector* );  
};  
  
int main()  
{  
   Vector *pa = new Vector( 0.231, 2.4745, 0.023 );  
   Vector *pb = new Vector( 1.475, 4.8916, -1.23 );   
  
   Vector *pc1 = Vector::op_Addition( pa, pb );  
   Vector *pc2 = Vector::op_Subtraction( pa, pc1 );  
   Vector *pc3 = Vector::op_Division( pc1, pc2->x );  
  
   if ( Vector::op_Equality( pc1, pc2 ))  
      ;  
}  
```  
  
 Na nova sintaxe, as expectativas comuns de um programador do C\+\+ nativo são restauradas, na declaração e o uso de operadores estáticos.  Aqui está a classe de `Vector` convertida na nova sintaxe:  
  
```  
public ref class Vector sealed {  
public:  
   Vector( double x, double y, double z );  
  
   static bool    operator ==( const Vector^, const Vector^ );  
   static Vector^ operator /( const Vector^, double );  
   static Vector^ operator +( const Vector^, const Vector^ );  
   static Vector^ operator -( const Vector^, const Vector^ );  
};  
  
int main()  
{  
   Vector^ pa = gcnew Vector( 0.231, 2.4745, 0.023 );  
   Vector^ pb = gcnew Vector( 1.475,4.8916,-1.23 );  
  
   Vector^ pc1 = pa + pb;  
   Vector^ pc2 = pa - pc1;  
   Vector^ pc3 = pc1 / pc2->x;  
  
   if ( pc1 == pc2 )  
      ;  
}  
```  
  
## Consulte também  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)