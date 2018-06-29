---
title: Visão geral de Marshaling no C++ | Microsoft Docs
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- marshaling
- marshalling
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, marshaling
- C++ Support Library, marshaling
- marshaling, about marshaling
ms.assetid: 997dd4bc-5f98-408f-b890-f35de9ce3bb8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 76f6721ce4561e9c2b4323fef9c2eed3231f73cb
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37079154"
---
# <a name="overview-of-marshaling-in-c"></a>Visão geral de marshaling no C++
No modo misto, você às vezes deve empacotar os dados entre os tipos nativos e gerenciados. O Visual Studio 2008 introduziu o *biblioteca de marshaling* para ajudar você empacotar e converter os dados de uma maneira simple.  A biblioteca de marshaling consiste em um conjunto de funções e um `marshal_context` classe que realizar marshaling para tipos comuns. A biblioteca é definida nesses cabeçalhos no **incluem/msclr** diretório da sua edição do Visual Studio:

|Cabeçalho|Descrição|  
|---------------|-----------------|
|Marshal.h|`marshal_context` classe e funções de marshaling livre de contexto|
|marshal_atl.h| Funções de marshaling de tipos do ATL|
|marshal_cppstd.h|Funções para realizar marshaling dos tipos C++ padrão|
|marshal_windows.h|Funções de marshaling de tipos do Windows|


O caminho padrão para **msclr** pasta é parecida com esta dependendo de qual edição você tem e o número da compilação:

```cmd
C:\\Program Files (x86)\\Microsoft Visual Studio\\Preview\\Enterprise\\VC\\Tools\\MSVC\\14.15.26528\\include\\msclr
```

 Você pode usar a biblioteca de marshaling com ou sem um [classe marshal_context](../dotnet/marshal-context-class.md). Algumas conversões exigem um contexto. Outras conversões podem ser implementadas usando o [marshal_as](../dotnet/marshal-as.md) função. A tabela a seguir lista as conversões atuais com suporte, se ele requer um contexto e quais arquivos de marshaling que incluem:  
  
|Do tipo|Para o tipo|Método de marshaling|arquivo de inclusão|  
|---------------|-------------|--------------------|------------------|  
|System:: String ^|Const char *|marshal_context|Marshal.h|  
|Const char *|System:: String ^|marshal_as|Marshal.h|  
|char *|System:: String ^|marshal_as|Marshal.h|  
|System:: String ^|wchar_t const *|marshal_context|Marshal.h|  
|wchar_t const *|System:: String ^|marshal_as|Marshal.h|  
|wchar_t *|System:: String ^|marshal_as|Marshal.h|  
|System::IntPtr|IDENTIFICADOR|marshal_as|marshal_windows.h|  
|IDENTIFICADOR|System::IntPtr|marshal_as|marshal_windows.h|  
|System:: String ^|BSTR|marshal_context|marshal_windows.h|  
|BSTR|System:: String ^|marshal_as|Marshal.h|  
|System:: String ^|bstr_t|marshal_as|marshal_windows.h|  
|bstr_t|System:: String ^|marshal_as|marshal_windows.h|  
|System:: String ^|std::String|marshal_as|marshal_cppstd.h|  
|std::String|System:: String ^|marshal_as|marshal_cppstd.h|  
|System:: String ^|std:: wstring|marshal_as|marshal_cppstd.h|  
|std:: wstring|System:: String ^|marshal_as|marshal_cppstd.h|  
|System:: String ^|CStringT\<char >|marshal_as|marshal_atl.h|  
|CStringT\<char >|System:: String ^|marshal_as|marshal_atl.h|  
|System:: String ^|CStringT < wchar_t >|marshal_as|marshal_atl.h|  
|CStringT < wchar_t >|System:: String ^|marshal_as|marshal_atl.h|  
|System:: String ^|CComBSTR|marshal_as|marshal_atl.h|  
|CComBSTR|System:: String ^|marshal_as|marshal_atl.h|  
  
 Marshaling requer um contexto somente quando você realizar marshaling de dados gerenciados para nativo de tipos e o tipo nativo que estiver convertendo não tem um destruidor para automático de limpeza. O contexto de marshaling destrói o tipo de dados nativos alocados no seu destruidor. Portanto, conversões que exigem um contexto será válidas até que o contexto é excluído. Para salvar todos os valores empacotados, você deve copiar os valores para suas próprias variáveis.  
  
> [!NOTE]
>  Se você tiver inserido `NULL`s em sua cadeia de caracteres, o resultado de empacotamento a cadeia de caracteres não é garantido. O item inserido `NULL`s pode fazer com que a cadeia de caracteres a ser truncado ou eles podem ser preservados.  
  
Este exemplo mostra como incluir o diretório msclr em uma declaração de cabeçalho incluem:  
  
 `#include "msclr\marshal_cppstd.h"`  
  
 A biblioteca de marshaling é extensível para que você pode adicionar seus próprios tipos de marshaling. Para obter mais informações sobre como estender a biblioteca de marshaling, consulte [como: estender a biblioteca de Marshaling](../dotnet/how-to-extend-the-marshaling-library.md).  
  
 Em versões anteriores, você pode empacotar dados usando [invocação de plataforma](/dotnet/framework/interop/consuming-unmanaged-dll-functions). Para obter mais informações sobre `PInvoke`, consulte [chamando funções nativas do código gerenciado](../dotnet/calling-native-functions-from-managed-code.md).  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de suporte do C++](../dotnet/cpp-support-library.md)   
 [Como estender a biblioteca de marshaling](../dotnet/how-to-extend-the-marshaling-library.md)
