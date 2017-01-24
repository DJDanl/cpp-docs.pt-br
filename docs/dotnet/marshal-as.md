---
title: "marshal_as | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "marshal_as"
  - "msclr.interop.marshal_as"
  - "msclr::interop::marshal_as"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Modelo marshal_as [C++]"
ms.assetid: 2ed717da-2b11-41e5-981d-47d251771989
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# marshal_as
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Esse método converte dados entre o modo nativo e ambientes gerenciados.  
  
## Sintaxe  
  
```  
To_Type marshal_as<To_Type>(  
   From_Type input   
);  
```  
  
#### Parâmetros  
 \[entrada\] `input`  
 O valor que você deseja gerar marshaling a uma variável de `To_Type` .  
  
## Valor de retorno  
 Uma variável de tipo `To_Type` que é o valor convertido de `input`.  
  
## Comentários  
 Este método é uma forma simplificada de conversão de dados entre o modo nativo e tipos gerenciados.  Para determinar quais tipos de dados têm suporte, consulte [Visão geral de marshaling no C\+\+](../dotnet/overview-of-marshaling-in-cpp.md).  Algumas conversões de dados requer um contexto.  Você pode converter esses tipos de dados usando [Classe marshal\_context](../dotnet/marshal-context-class.md).  
  
 Se você tentar ao marshaling um par de tipos de dados sem suporte, `marshal_as` gerará um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) em tempo de compilação.  Lê a mensagem fornecida com esse erro para obter mais informações.  O erro de `C4996` pode ser gerado para mais do que simplesmente funções substituídas.  Um exemplo desse está tentando o marshaling um par de tipos de dados não suportados.  
  
 A biblioteca marshaling consistir em diversos arquivos de cabeçalho.  Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais se você precisa para as demais conversões.  Para ver que conversões são associadas com que os arquivos, verifique a tabela em `Marshaling Overview`.  Independentemente de qual você deseja fazer conversão, o requisito de namespace é sempre em vigor.  
  
## Exemplo  
 Realiza marshaling deste exemplo de `const char*` a um tipo de variável de `System::String` .  
  
```  
// marshal_as_test.cpp  
// compile with: /clr  
#include <stdlib.h>  
#include <string.h>  
#include <msclr\marshal.h>  
  
using namespace System;  
using namespace msclr::interop;  
  
int main() {  
   const char* message = "Test String to Marshal";  
   String^ result;  
   result = marshal_as<String^>( message );  
   return 0;  
}  
```  
  
## Requisitos  
 msclr \<de**Arquivo de cabeçalho:** \\ marshal.h, msclr\>\<\\ marshal\_windows.h, msclr\>\\ \<marshal\_cppstd.h, ou msclr\>\\ marshal\_atl.h \<\>  
  
 msclr::interop de**Namespace:**  
  
## Consulte também  
 [Visão geral de marshaling no C\+\+](../dotnet/overview-of-marshaling-in-cpp.md)   
 [Classe marshal\_context](../dotnet/marshal-context-class.md)