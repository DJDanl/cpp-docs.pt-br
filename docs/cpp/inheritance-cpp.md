---
title: "Heran&#231;a (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++], derivado"
  - "classes derivadas"
  - "classes derivadas, sobre classes derivadas"
ms.assetid: 3534ca19-d9ed-4a40-be1b-b921ad0e6956
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Heran&#231;a (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esta seção explica como usar classes derivadas para gerar programas extensíveis.  
  
## Visão geral  
 Novas classes podem ser derivadas de classes existentes por meio de um mecanismo chamado "herança" \(consulte as informações a partir de [Herança única](../cpp/single-inheritance.md)\).  As classes que são usadas para derivação são chamadas "classes base" de uma classe derivada específica.  Uma classe derivada é declarada mediante a seguinte sintaxe:  
  
```  
 class Derived : [virtual] [access-specifier] Base  
{  
   // member list  
};  
 class Derived : [virtual] [access-specifier] Base1,  
 [virtual] [access-specifier] Base2, . . .  
{  
   // member list  
};  
```  
  
 Depois da marca \(nome\) da classe, aparecem dois\-pontos seguidos por uma lista de especificações de base.  As classes base nomeadas dessa forma devem ter sido declaradas anteriormente.  As especificações de base podem conter um especificador de acesso, que é uma das palavras\-chave **public**, `protected` ou `private`.  Esses especificadores de acesso aparecem antes do nome da classe base e só se aplicam a essa classe base.  Esses especificadores controlam a permissão da classe derivada para usar os membros da classe base.  Consulte [Controle de acesso a membros](../cpp/member-access-control-cpp.md) para obter informações sobre o acesso a membros de classes base.  Se o especificador de acesso for omitido, o acesso a essa base será considerado `private`.  As especificações de base podem conter a palavra\-chave **virtual** para indicar uma herança virtual.  Essa palavra\-chave pode aparecer antes ou depois do especificador de acesso, se houver.  Se for usada a herança virtual, a classe base será conhecida como uma classe base virtual.  Para obter mais informações, consulte [Classes base virtuais](../Topic/Virtual%20Base%20Classes.md).  
  
 É possível especificar várias classes base, separadas por vírgulas.  Se uma única classe base for especificada, o modelo de herança será [Herança única](../cpp/single-inheritance.md). Se mais de uma classe base for especificada, o modelo de herança será chamado [Herança múltipla](http://msdn.microsoft.com/pt-br/3b74185e-2beb-4e29-8684-441e51d2a2ca).  
  
 Os seguintes tópicos estão incluídos:  
  
-   [Herança única](../cpp/single-inheritance.md)  
  
-   [Herança múltipla](http://msdn.microsoft.com/pt-br/3b74185e-2beb-4e29-8684-441e51d2a2ca)  
  
-   [Classes base múltiplas](../cpp/multiple-base-classes.md)  
  
-   [Classes base virtuais](../Topic/Virtual%20Base%20Classes.md)  
  
-   [Funções virtuais](../cpp/virtual-functions.md)  
  
-   [Substituições explícitas](../cpp/explicit-overrides-cpp.md)  
  
-   [Classes abstratas](../cpp/abstract-classes-cpp.md)  
  
-   [Resumo de regras de escopo](../cpp/summary-of-scope-rules.md)  
  
 As palavras\-chave [\_\_super](../cpp/super.md) e [\_\_interface](../Topic/__interface.md) estão documentadas nesta seção.  
  
## Consulte também  
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)