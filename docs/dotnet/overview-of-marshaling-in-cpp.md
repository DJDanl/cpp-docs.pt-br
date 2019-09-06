---
title: Visão geral de marshaling no C++
ms.date: 07/12/2019
ms.topic: reference
f1_keywords:
- marshaling
- marshalling
helpviewer_keywords:
- Visual C++, marshaling
- C++ Support Library, marshaling
- marshaling, about marshaling
ms.assetid: 997dd4bc-5f98-408f-b890-f35de9ce3bb8
ms.openlocfilehash: 937fbdf4b3ed09344e69a8f1eb731565c36794ae
ms.sourcegitcommit: 0e3da5cea44437c132b5c2ea522bd229ea000a10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/12/2019
ms.locfileid: "70311704"
---
# <a name="overview-of-marshaling-in-ccli"></a>Visão geral do marshaling C++em/CLI

No modo misto, às vezes você deve realizar marshaling dos dados entre tipos nativos e gerenciados. A *biblioteca de marshaling* ajuda você a realizar marshaling e converter dados de uma maneira simples.  A biblioteca de marshaling consiste em um conjunto de funções e `marshal_context` uma classe que executa o marshaling para tipos comuns. A biblioteca é definida nesses cabeçalhos no diretório **include/msclr** para sua edição do Visual Studio:

|Cabeçalho|Descrição|
|---------------|-----------------|
|marshal.h|`marshal_context`funções de empacotamento de classe e sem contexto|
|marshal_atl.h| Funções para empacotamento de tipos ATL|
|marshal_cppstd.h|Funções para empacotamento de C++ tipos padrão|
|marshal_windows.h|Funções para empacotamento de tipos do Windows|

O caminho padrão para a pasta **msclr** é algo assim, dependendo de qual edição você tem e o número de Build:

```cmd
C:\\Program Files (x86)\\Microsoft Visual Studio\\Preview\\Enterprise\\VC\\Tools\\MSVC\\14.15.26528\\include\\msclr
```

Você pode usar a biblioteca de marshaling com ou sem uma [classe marshal_context](../dotnet/marshal-context-class.md). Algumas conversões exigem um contexto. Outras conversões podem ser implementadas usando a função [marshal_as](../dotnet/marshal-as.md) . A tabela a seguir lista as conversões atuais com suporte, se elas exigem um contexto e qual arquivo de marshaling você precisa incluir:

|Do tipo|Para o tipo|Método Marshal|Arquivo de inclusão|
|---------------|-------------|--------------------|------------------|
|Sistema:: cadeia de caracteres ^|caractere const\*|marshal_context|marshal.h|
|caractere const\*|Sistema:: cadeia de caracteres ^|marshal_as|marshal.h|
|º\*|Sistema:: cadeia de caracteres ^|marshal_as|marshal.h|
|Sistema:: cadeia de caracteres ^|const wchar_t\*|marshal_context|marshal.h|
|wchar_t const\*|Sistema:: cadeia de caracteres ^|marshal_as|marshal.h|
|wchar_t \*|Sistema:: cadeia de caracteres ^|marshal_as|marshal.h|
|System::IntPtr|PROCESSAMENTO|marshal_as|marshal_windows.h|
|PROCESSAMENTO|System::IntPtr|marshal_as|marshal_windows.h|
|Sistema:: cadeia de caracteres ^|BSTR|marshal_context|marshal_windows.h|
|BSTR|Sistema:: cadeia de caracteres ^|marshal_as|marshal.h|
|Sistema:: cadeia de caracteres ^|bstr_t|marshal_as|marshal_windows.h|
|bstr_t|Sistema:: cadeia de caracteres ^|marshal_as|marshal_windows.h|
|Sistema:: cadeia de caracteres ^|std::string|marshal_as|marshal_cppstd.h|
|std::string|Sistema:: cadeia de caracteres ^|marshal_as|marshal_cppstd.h|
|Sistema:: cadeia de caracteres ^|std::wstring|marshal_as|marshal_cppstd.h|
|std::wstring|Sistema:: cadeia de caracteres ^|marshal_as|marshal_cppstd.h|
|Sistema:: cadeia de caracteres ^|>\<Char CStringT|marshal_as|marshal_atl.h|
|>\<Char CStringT|Sistema:: cadeia de caracteres ^|marshal_as|marshal_atl.h|
|Sistema:: cadeia de caracteres ^|CStringT<wchar_t>|marshal_as|marshal_atl.h|
|CStringT<wchar_t>|Sistema:: cadeia de caracteres ^|marshal_as|marshal_atl.h|
|Sistema:: cadeia de caracteres ^|CComBSTR|marshal_as|marshal_atl.h|
|CComBSTR|Sistema:: cadeia de caracteres ^|marshal_as|marshal_atl.h|

O marshaling requer um contexto somente quando você realiza marshaling de tipos de dados gerenciados para nativos e o tipo nativo para o qual você está convertendo não tem um destruidor para limpeza automática. O contexto de marshaling destrói o tipo de dados nativo alocado em seu destruidor. Portanto, as conversões que exigem um contexto serão válidas somente até que o contexto seja excluído. Para salvar os valores de marshaling, você deve copiar os valores para suas próprias variáveis.

> [!NOTE]
>  Se você tiver inserido `NULL`s em sua cadeia de caracteres, o resultado do marshaling da cadeia de caracteres não será garantido. Os s `NULL`incorporados podem fazer com que a cadeia de caracteres seja truncada ou pode ser preservada.

Este exemplo mostra como incluir o diretório msclr em uma declaração de cabeçalho include:

`#include "msclr\marshal_cppstd.h"`

A biblioteca de marshaling é extensível para que você possa adicionar seus próprios tipos de marshaling. Para obter mais informações sobre como estender a biblioteca de marshaling, consulte [como: Estenda a biblioteca](../dotnet/how-to-extend-the-marshaling-library.md)de marshaling.

## <a name="see-also"></a>Consulte também

[Biblioteca de suporte do C++](../dotnet/cpp-support-library.md)<br/>
[Como: estender a biblioteca de marshaling](../dotnet/how-to-extend-the-marshaling-library.md)
