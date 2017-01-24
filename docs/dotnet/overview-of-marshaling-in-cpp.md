---
title: "Vis&#227;o geral de marshaling no C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "marshaling"
  - "marshalling"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Biblioteca de suporte do C++, marshaling"
  - "marshaling, sobre realização de marshaling"
  - "Visual C++, marshaling"
ms.assetid: 997dd4bc-5f98-408f-b890-f35de9ce3bb8
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral de marshaling no C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No modo misto, no você deve algumas vezes o marshaling os dados entre o modo nativo e tipos gerenciados.  [!INCLUDE[vs_orcas_long](../atl/reference/includes/vs_orcas_long_md.md)] o introduziu a biblioteca marshaling para ajudar dados de marshaling e de conversão de uma maneira simples.  
  
 Você pode usar a biblioteca marshaling com ou sem [Classe marshal\_context](../dotnet/marshal-context-class.md).  Algumas conversões exigem um contexto.  As demais conversões podem ser implementadas usando a função de [marshal\_as](../dotnet/marshal-as.md) .  A tabela a seguir lista as conversões atuais suporte, se exigem um contexto, e que marshaling o arquivo você tem que incluir:  
  
|Do tipo|Para digitar|Método de marshaling|Inclua o arquivo|  
|-------------|------------------|--------------------------|----------------------|  
|System::String^|const char \*|marshal\_context|marshal.h|  
|const char \*|System::String^|marshal\_as|marshal.h|  
|char \*|System::String^|marshal\_as|marshal.h|  
|System::String^|wchar\_t\* de const|marshal\_context|marshal.h|  
|const wchar\_t \*|System::String^|marshal\_as|marshal.h|  
|wchar\_t \*|System::String^|marshal\_as|marshal.h|  
|System::IntPtr|MANIPULAR|marshal\_as|marshal\_windows.h|  
|MANIPULAR|System::IntPtr|marshal\_as|marshal\_windows.h|  
|System::String^|BSTR|marshal\_context|marshal\_windows.h|  
|BSTR|System::String^|marshal\_as|marshal.h|  
|System::String^|bstr\_t|marshal\_as|marshal\_windows.h|  
|bstr\_t|System::String^|marshal\_as|marshal\_windows.h|  
|System::String^|std::string|marshal\_as|marshal\_cppstd.h|  
|std::string|System::String^|marshal\_as|marshal\_cppstd.h|  
|System::String^|std::wstring|marshal\_as|marshal\_cppstd.h|  
|std::wstring|System::String^|marshal\_as|marshal\_cppstd.h|  
|System::String^|CStringTchar\<\>|marshal\_as|marshal\_atl.h|  
|CStringTchar\<\>|System::String^|marshal\_as|marshal\_atl.h|  
|System::String^|CStringTwchar\_t\<\>|marshal\_as|marshal\_atl.h|  
|CStringTwchar\_t\<\>|System::String^|marshal\_as|marshal\_atl.h|  
|System::String^|CComBSTR|marshal\_as|marshal\_atl.h|  
|CComBSTR|System::String^|marshal\_as|marshal\_atl.h|  
  
 Marshaling requer um contexto somente quando você marshaling de gerenciado para tipos de dados nativos e o tipo nativo que você está convertendo não tiver um destruidor para limpar o automático.  O contexto marshaling destrói o tipo de dados nativo atribuído em seu destruidor.  Em virtude disso, as conversões que exigem um contexto serão válidos apenas até que o contexto seja excluído.  Para salvar todos os valores marshaling, você deve copiar os valores a suas próprias variáveis.  
  
> [!NOTE]
>  Se você digitou `NULL`s em sua cadeia de caracteres, o resultado do marshaling a cadeia de caracteres não é garantido.  `NULL`inserido s pode causar a cadeia de caracteres a ser truncada ou podem ser preservados.  
  
 Os cabeçalhos marshaling da biblioteca são localizados no diretório incluir no subdiretório de msclr.  Este exemplo mostra como incluir o diretório de msclr em uma declaração de cabeçalho incluir:  
  
 `#include "msclr\marshal_cppstd.h"`  
  
 A biblioteca marshaling é extensível de forma que você pode adicionar seus próprios tipos marshaling.  Para obter mais informações sobre como estender a biblioteca marshaling, consulte [Como estender a biblioteca de marshaling](../dotnet/how-to-extend-the-marshaling-library.md).  
  
 Em versões anteriores, você poderia dados de marshaling usando [Invocação de plataforma](../Topic/Consuming%20Unmanaged%20DLL%20Functions.md).  Para obter mais informações sobre `PInvoke`, consulte [Chamando funções nativas a partir do código gerenciado](../dotnet/calling-native-functions-from-managed-code.md).  
  
## Consulte também  
 [Biblioteca de suporte do C\+\+](../dotnet/cpp-support-library.md)   
 [Como estender a biblioteca de marshaling](../dotnet/how-to-extend-the-marshaling-library.md)