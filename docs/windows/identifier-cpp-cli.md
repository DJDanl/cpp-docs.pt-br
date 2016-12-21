---
title: "__identifier (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__identifier"
  - "__identifier_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__identifier keyword [C++]"
ms.assetid: 348428af-afa7-4ff3-b571-acf874301cf2
caps.latest.revision: 18
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __identifier (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Habilita o uso de palavras\-chave do Visual C\+\+ como identificadores.  
  
## Todas as Plataformas  
 **Sintaxe**  
  
```  
  
__identifier(  
Visual_C++_keyword  
)  
  
```  
  
 **Comentários**  
  
 O uso da palavra\-chave de `__identifier` para os identificadores que não são palavras\-chave é permitido, mas totalmente desaconselhável como uma questão de estilo.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
### Exemplos  
 **Exemplo**  
  
 No exemplo a seguir, uma classe nomeada `template` é criada no C\# e distribuída como uma DLL.  No programa Visual C\+\+ que usa a classe de `template` , a palavra\-chave de `__identifier` esconde o fato de que `template` é uma palavra\-chave padrão do C\+\+.  
  
```  
// identifier_template.cs  
// compile with: /target:library  
public class template {  
   public void Run() { }  
}  
```  
  
```  
// keyword__identifier.cpp  
// compile with: /ZW  
#using <identifier_template.dll>  
int main() {  
   __identifier(template)^ pTemplate = ref new __identifier(template)();  
   pTemplate->Run();  
}  
```  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Comentários**  
  
 A palavra\-chave de `__identifier` é válido com as opções do compilador de **\/clr** e de **\/clr:oldSyntax** .  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 No exemplo a seguir, uma classe nomeada `template` é criada no C\# e distribuída como uma DLL.  No programa Visual C\+\+ que usa a classe de `template` , a palavra\-chave de `__identifier` esconde o fato de que `template` é uma palavra\-chave padrão do C\+\+.  
  
```  
// identifier_template.cs  
// compile with: /target:library  
public class template {  
   public void Run() { }  
}  
```  
  
```  
// keyword__identifier.cpp  
// compile with: /clr  
#using <identifier_template.dll>  
  
int main() {  
   __identifier(template) ^pTemplate = gcnew __identifier(template)();  
   pTemplate->Run();  
}  
```  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)   
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)