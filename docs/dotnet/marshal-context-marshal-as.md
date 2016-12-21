---
title: "marshal_context::marshal_as | Microsoft Docs"
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
  - "marshal_context::marshal_as"
  - "marshal_context.marshal_as"
  - "msclr.interop.marshal_context.marshal_as"
  - "msclr::interop::marshal_context::marshal_as"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe marshal_context [C++], operações"
ms.assetid: 24a1afee-51c0-497c-948c-f77fe43635c8
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# marshal_context::marshal_as
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Realiza marshaling em um objeto de dados específico para convertê\-los entre um tipo de dados gerenciado e nativo.  
  
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
 Essa função executa o marshaling em um objeto de dados específico.  Use essa função só com as conversões indicadas por tabela em [Visão geral de marshaling no C\+\+](../dotnet/overview-of-marshaling-in-cpp.md).  
  
 Se você tentar ao marshaling um par de tipos de dados sem suporte, `marshal_as` gerará um erro [C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md) em tempo de compilação.  Lê a mensagem fornecida com esse erro para obter mais informações.  O erro de `C4996` pode ser gerado para mais do que simplesmente funções substituídas.  Duas condições que gerarão esse erro estão tentando o marshaling um par de tipos de dados que não são suportados e são tentando\-os usar `marshal_as` para uma conversão que requer um contexto.  
  
 A biblioteca marshaling consistir em diversos arquivos de cabeçalho.  Qualquer conversão requer apenas um arquivo, mas você pode incluir arquivos adicionais se você precisa para as demais conversões.  A tabela em `Marshaling Overview in C++` indica que o marshaling arquivo deve ser incluído para cada conversão.  
  
## Exemplo  
 Este exemplo cria um contexto para o marshaling de `System::String` a um tipo de variável de `const char *` .  Os dados convertidos não serão válidos depois da linha que exclui o contexto.  
  
```  
// marshal_context_test.cpp  
// compile with: /clr  
#include <stdlib.h>  
#include <string.h>  
#include <msclr\marshal.h>  
  
using namespace System;  
using namespace msclr::interop;  
  
int main() {  
   marshal_context^ context = gcnew marshal_context();  
   String^ message = gcnew String("Test String to Marshal");  
   const char* result;  
   result = context->marshal_as<const char*>( message );  
   delete context;  
   return 0;  
}  
```  
  
## Requisitos  
 msclr \<de**Arquivo de cabeçalho:** \\ marshal.h, msclr\>\<\\ marshal\_windows.h, msclr\>\\ \<marshal\_cppstd.h, ou msclr\>\\ marshal\_atl.h \<\>  
  
 msclr::interop de**Namespace:**  
  
## Consulte também  
 [Visão geral de marshaling no C\+\+](../dotnet/overview-of-marshaling-in-cpp.md)   
 [marshal\_as](../dotnet/marshal-as.md)   
 [Classe marshal\_context](../dotnet/marshal-context-class.md)