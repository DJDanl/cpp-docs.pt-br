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
ms.openlocfilehash: 60706a7922d9bea68e2ef4a27afa1401a1cd6920
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377442"
---
# <a name="overview-of-marshaling-in-c"></a>Visão geral de marshaling no C++

No modo misto, você às vezes deve empacotar os dados entre tipos nativos e gerenciados. O Visual Studio 2008 introduziu o *biblioteca de marshaling* para ajudar a realizar marshaling e converter os dados de uma forma simples.  A biblioteca de marshaling consiste em um conjunto de funções e um `marshal_context` classe que realize o marshaling para tipos comuns. A biblioteca é definida nestes cabeçalhos na **incluem/msclr** diretório para sua edição do Visual Studio:

|Cabeçalho|Descrição|
|---------------|-----------------|
|Marshal.h|`marshal_context` classe e funções de marshaling sem contexto|
|marshal_atl.h| Funções de marshaling de tipos do ATL|
|marshal_cppstd.h|Funções de marshaling de tipos C++ padrão|
|marshal_windows.h|Funções de marshaling de tipos do Windows|

O caminho padrão para **msclr** pasta é semelhante ao seguinte, dependendo de qual edição você tem e o número da compilação:

```cmd
C:\\Program Files (x86)\\Microsoft Visual Studio\\Preview\\Enterprise\\VC\\Tools\\MSVC\\14.15.26528\\include\\msclr
```

Você pode usar a biblioteca de marshaling com ou sem um [classe marshal_context](../dotnet/marshal-context-class.md). Algumas conversões exigem um contexto. Outras conversões podem ser implementados usando o [marshal_as](../dotnet/marshal-as.md) função. A tabela a seguir lista as conversões atuais com suporte, se ele requer um contexto e qual arquivo de marshaling, você precisa incluir:

|De tipo|Para o tipo|Método de marshaling|Arquivo de inclusão|
|---------------|-------------|--------------------|------------------|
|System:: String ^|Const char \*|marshal_context|Marshal.h|
|Const char \*|System:: String ^|marshal_as|Marshal.h|
|Char \*|System:: String ^|marshal_as|Marshal.h|
|System:: String ^|Const wchar_t\*|marshal_context|Marshal.h|
|Const wchar_t \*|System:: String ^|marshal_as|Marshal.h|
|wchar_t \*|System:: String ^|marshal_as|Marshal.h|
|System::IntPtr|IDENTIFICADOR|marshal_as|marshal_windows.h|
|IDENTIFICADOR|System::IntPtr|marshal_as|marshal_windows.h|
|System:: String ^|BSTR|marshal_context|marshal_windows.h|
|BSTR|System:: String ^|marshal_as|Marshal.h|
|System:: String ^|bstr_t|marshal_as|marshal_windows.h|
|bstr_t|System:: String ^|marshal_as|marshal_windows.h|
|System:: String ^|std:: String|marshal_as|marshal_cppstd.h|
|std:: String|System:: String ^|marshal_as|marshal_cppstd.h|
|System:: String ^|std:: wstring|marshal_as|marshal_cppstd.h|
|std:: wstring|System:: String ^|marshal_as|marshal_cppstd.h|
|System:: String ^|CStringT\<char >|marshal_as|marshal_atl.h|
|CStringT\<char >|System:: String ^|marshal_as|marshal_atl.h|
|System:: String ^|CStringT < wchar_t >|marshal_as|marshal_atl.h|
|CStringT < wchar_t >|System:: String ^|marshal_as|marshal_atl.h|
|System:: String ^|CComBSTR|marshal_as|marshal_atl.h|
|CComBSTR|System:: String ^|marshal_as|marshal_atl.h|

Marshaling requer um contexto de somente quando você realizar marshaling de dados gerenciados para nativo tipos e o tipo nativo que você está convertendo para não tem um destruidor para automático de limpeza. O contexto de marshaling destrói o tipo de dados nativo alocados em seu destruidor. Portanto, conversões que exigem um contexto será válidas até que o contexto é excluído. Para salvar todos os valores com marshaling, você deve copiar os valores para suas próprias variáveis.

> [!NOTE]
>  Se você tiver inserido `NULL`s na sua cadeia de caracteres, o resultado de marshaling de cadeia de caracteres não é garantido. O embedded `NULL`s pode fazer com que a cadeia de caracteres a ser truncado ou eles podem ser preservados.

Este exemplo mostra como incluir o diretório msclr em uma declaração de cabeçalho de inclusão:

`#include "msclr\marshal_cppstd.h"`

A biblioteca de marshaling é extensível para que você pode adicionar seus próprios tipos de marshaling. Para obter mais informações sobre como estender a biblioteca de marshaling, consulte [como: estender a biblioteca de Marshaling](../dotnet/how-to-extend-the-marshaling-library.md).

Em versões anteriores, você pode realizar marshaling de dados usando [de invocação de plataforma](/dotnet/framework/interop/consuming-unmanaged-dll-functions). Para obter mais informações sobre `PInvoke`, consulte [Calling Native Functions from Managed Code](../dotnet/calling-native-functions-from-managed-code.md).

## <a name="see-also"></a>Consulte também

[Biblioteca de suporte do C++](../dotnet/cpp-support-library.md)<br/>
[Como estender a biblioteca de marshaling](../dotnet/how-to-extend-the-marshaling-library.md)
