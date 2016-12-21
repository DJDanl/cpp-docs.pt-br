---
title: "ref new, gcnew  (C++ Component Extensions) | Microsoft Docs"
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
  - "gcnew"
  - "ref new"
  - "gcnew_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ref new keyword (C++)"
  - "gcnew keyword [C++]"
ms.assetid: 388a62da-c2df-4a94-a9a2-205b53e577da
caps.latest.revision: 24
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ref new, gcnew  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O `ref new` palavra\-chave agregação aloca uma instância de um tipo que será limpo quando o objeto se torna inacessível e que retorna um identificador \([^](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)\) para o objeto alocado.  
  
## Todos os Tempos de Execução  
 Memória para uma instância de um tipo que está alocada por `ref new` é desalocado automaticamente.  
  
 Um `ref new` operação throws `OutOfMemoryException` se não for possível alocar memória.  
  
 Para obter mais informações sobre como a memória para tipos nativos do C\+\+ é alocada e desalocada, consulte [o novo e excluir operadores](../cpp/new-and-delete-operators.md).  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 Use `ref new` ao alocar memória para objetos de tempo de execução do Windows cuja vida útil que você deseja administrar automaticamente.  O objeto será desalocado automaticamente quando sua contagem de referência chega a zero, o que ocorre após a última cópia da referência tiver saído do escopo.  Para obter mais informações, consulte [classes e estruturas Ref](http://msdn.microsoft.com/library/windows/apps/hh699870.aspx).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 Memória para um tipo gerenciado \(tipo de valor ou referência\) está alocada por `gcnew`, e desalocadas por meio da coleta de lixo.  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo a seguir usa `gcnew` para alocar um objeto Message.  
  
```  
// mcppv2_gcnew_1.cpp  
// compile with: /clr  
ref struct Message {  
   System::String^ sender;  
   System::String^ receiver;  
   System::String^ data;  
};  
  
int main() {  
   Message^ h_Message  = gcnew Message;  
  //...  
}  
```  
  
 **Exemplo**  
  
 O exemplo a seguir usa `gcnew` para criar um tipo de valor demarcado para uso como um tipo de referência.  
  
```  
// example2.cpp : main project file.  
// compile with /clr  
using namespace System;  
value class Boxed {  
    public:  
        int i;  
};  
int main()  
{  
    Boxed^ y = gcnew Boxed;  
    y->i = 32;  
    Console::WriteLine(y->i);  
    return 0;  
}  
```  
  
 **Saída**  
  
  **32**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)