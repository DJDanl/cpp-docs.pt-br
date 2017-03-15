---
title: "Palavras-chave contextuais (extens&#245;es de componentes C++) | Microsoft Docs"
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
  - "internal_CPP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavras-chave contextuais"
ms.assetid: e33da089-f434-44e9-8cce-4668d05a8939
caps.latest.revision: 19
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Palavras-chave contextuais (extens&#245;es de componentes C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*Palavras\-chave contextuais* são elementos de linguagem que são reconhecidos somente em contextos específicos.  Fora do contexto específico, uma palavra\-chave contextual pode ser um símbolo definido pelo usuário.  
  
## Todos os Tempos de Execução  
 **Comentários**  
  
 Veja uma lista de palavras\-chave contextuais:  
  
-   [abstrata](../windows/abstract-cpp-component-extensions.md)  
  
-   [delegado](../windows/delegate-cpp-component-extensions.md)  
  
-   [evento](../windows/event-cpp-component-extensions.md)  
  
-   [finally](../dotnet/finally.md)  
  
-   [for each, in](../dotnet/for-each-in.md)  
  
-   [initonly](../dotnet/initonly-cpp-cli.md)  
  
-   `internal` \(consulte [Visibilidade de membro](../Topic/Member%20Visibility.md)\)  
  
-   [literal](../windows/literal-cpp-component-extensions.md)  
  
-   [override](../windows/override-cpp-component-extensions.md)  
  
-   [propriedade](../windows/property-cpp-component-extensions.md)  
  
-   [autenticada](../windows/sealed-cpp-component-extensions.md)  
  
-   `where` \(parte de [Generics](../windows/generics-cpp-component-extensions.md)\)  
  
 Para fins de legibilidade, convém limitar o uso de palavras\-chave contextuais como símbolos definidos pelo usuário.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Comentários**  
  
 \(Não há nenhum comentário específico de plataforma para este recurso.\)  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Comentários**  
  
 \(Não há nenhum comentário específico de plataforma para este recurso.\)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código mostra que no contexto apropriado, a palavra\-chave contextual de `property` pode ser usada para definir uma propriedade e uma variável.  
  
```  
// context_sensitive_keywords.cpp  
// compile with: /clr  
public ref class C {  
   int MyInt;  
public:  
   C() : MyInt(99) {}  
  
   property int Property_Block {   // context-sensitive keyword  
      int get() { return MyInt; }  
   }  
};  
  
int main() {  
   int property = 0;               // variable name  
   C ^ MyC = gcnew C();  
   property = MyC->Property_Block;  
   System::Console::WriteLine(++property);  
}  
```  
  
 **Saída**  
  
  **100**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)