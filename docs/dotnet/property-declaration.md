---
title: "Declara&#231;&#227;o da propriedade | Microsoft Docs"
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
  - "Palavra-chave __property"
  - "declarando propriedades, C++"
  - "palavra-chave property [C++]"
ms.assetid: de169378-a8b8-49f4-a586-76bffc9b5c9f
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#227;o da propriedade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O modo de declarar uma propriedade em uma classe gerenciada foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 No design gerenciado das extensões, cada propriedade de acessador de `set` ou de `get` é especificado como um método independente.  A declaração de cada método é prefixado com a palavra\-chave de `__property` .  O nome do método inicia com `set_` ou `get_` seguido pelo nome real da propriedade \(como visível ao usuário\).  Assim, `Vector` que fornece uma propriedade de `get` da coordenada de `x` nomeá\-la\-ia `get_x` e o usuário invocar\-o\-&z como `x`.  Essas convenção de nomenclatura e especificação separada dos métodos refletem na verdade a implementação subjacente de tempo de execução da propriedade.  Por exemplo, aqui está nosso `Vector` com um conjunto de propriedades coordenadas:  
  
```  
public __gc __sealed class Vector {  
public:  
   __property double get_x(){ return _x; }  
   __property double get_y(){ return _y; }  
   __property double get_z(){ return _z; }  
  
   __property void set_x( double newx ){ _x = newx; }  
   __property void set_y( double newy ){ _y = newy; }  
   __property void set_z( double newz ){ _z = newz; }  
};  
```  
  
 Isso espalhará out a funcionalidade associada a uma propriedade e exige que o usuário unificar léxica os conjuntos associados e começar.  Além disso, é verbose.  Na nova sintaxe, o que é mais como o C\#, a palavra\-chave de `property` é seguido pelo tipo de propriedade e seu nome unadorned.  Os métodos de acesso de `set` e de `get` são colocados dentro de um bloco depois do nome da propriedade.  Observe que ao contrário de C\#, a assinatura do método de acesso é especificado.  Por exemplo, aqui está o exemplo de código anterior convertido na nova sintaxe.  
  
```  
public ref class Vector sealed {   
public:  
   property double x {  
      double get() {  
         return _x;  
      }  
  
      void set( double newx ) {  
         _x = newx;  
      }  
   } // Note: no semi-colon  
};  
```  
  
 Se os métodos de acesso da propriedade refletem níveis de acesso distintos – como `public``get` e `private` ou `protected``set`, um rótulo explícito de acesso pode ser especificada.  Por padrão, o nível de acesso da propriedade reflete o nível de acesso inclusive.  Por exemplo, na definição de `Vector`acima, os métodos de `get` e de `set` são `public`.  Para fazer o método `protected` ou `private`de `set` , a definição seria examinada como segue:  
  
```  
public ref class Vector sealed {   
public:  
   property double x {  
      double get() {  
         return _x;  
      }  
  
   private:  
      void set( double newx ) {  
         _x = newx;  
      }  
  
   } // note: extent of private culminates here …  
  
// note: dot is a public method of Vector  
double dot( const Vector^ wv );  
  
// etc.  
};  
```  
  
 O escopo de uma palavra\-chave de acesso dentro de uma propriedade estende até a chave de fechamento da propriedade ou a especificação de uma palavra\-chave adicional de acesso.  Não exceda de definição da propriedade no nível de acesso inclusive na qual a propriedade é definida.  Na instrução acima, por exemplo, `Vector::dot()` é um método público.  
  
 Gravando o definir\/obter as propriedades para as três coordenadas de `Vector` envolve três etapas:  
  
1.  declare um membro de estado privado de tipo apropriado.  
  
2.  retorna quando o usuário deseja obter seu valor.  
  
3.  atribuir o novo valor.  
  
 Na nova sintaxe, uma sintaxe da propriedade de taquigrafia está disponível que automatizar o padrão de uso:  
  
```  
public ref class Vector sealed {   
public:  
   // equivalent shorthand property syntax  
   property double x;   
   property double y;  
   property double z;  
};  
```  
  
 O efeito colateral interessante a sintaxe da propriedade de taquigrafia é que embora o membro de estado de bastidores é gerado pelo compilador, não é acessível na classe a não ser que ao definir\/obter acessadores.  
  
## Consulte também  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [property](../windows/property-cpp-component-extensions.md)