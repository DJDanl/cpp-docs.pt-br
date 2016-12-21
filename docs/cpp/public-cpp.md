---
title: "public (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "public"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave public [C++]"
ms.assetid: f3e10a59-39f6-4bcd-827e-3e99f8f89497
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# public (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
public:  
   [member-list]  
public base-class  
```  
  
## Comentários  
 Quando precede uma lista de membros de classe, a palavra\-chave **public** especifica que esses membros podem ser acessados de qualquer função.  Isso se aplica a todos os membros declarados até o especificador seguinte do acesso ou ao final da classe.  
  
 Para preceder o nome de uma classe base, a palavra\-chave **public** especifica que os membros públicos e protegidos da classe base são membros públicos e protegidos, respectivamente, da classe derivada.  
  
 O acesso padrão dos membros em um classe é particular.  O acesso padrão dos membros em uma estrutura ou união é público.  
  
 O acesso padrão de uma classe base é particular para classes e público para estruturas.  Uniões não podem ter classes base.  
  
 Para obter mais informações, consulte [privado](../Topic/private%20\(C++\).md), [protegido](../Topic/protected%20\(C++\).md), [amigo](../cpp/friend-cpp.md) e a tabela de acesso de membros em [Controlando o acesso aos membros da classe](../misc/controlling-access-to-class-members.md).  
  
## Específico do \/clr  
 Nos tipos de CLR, as palavras\-chave do especificador de acesso de C\+\+ \(**público**, `private` e `protected`\) podem afetar a visibilidade dos tipos e métodos em relação aos assemblies.  Para obter mais informações, consulte [Visibilidade do tipo e do membro](../Topic/Type%20and%20Member%20Visibility.md).  
  
> [!NOTE]
>  Os arquivos compilados com [\/LN](../build/reference/ln-create-msil-module.md) não são afetados por esse comportamento.  Nesse caso, todas as classes gerenciadas \(públicas ou particulares\) serão visíveis.  
  
## Específico de END \/clr  
  
## Exemplo  
  
```  
// keyword_public.cpp  
class BaseClass {  
public:  
   int pubFunc() { return 0; }  
};  
  
class DerivedClass : public BaseClass {};  
  
int main() {  
   BaseClass aBase;  
   DerivedClass aDerived;  
   aBase.pubFunc();       // pubFunc() is accessible   
                          //    from any function  
   aDerived.pubFunc();    // pubFunc() is still public in   
                          //    derived class  
}  
```  
  
## Consulte também  
 [Controlando acesso a membros de classe](../misc/controlling-access-to-class-members.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)