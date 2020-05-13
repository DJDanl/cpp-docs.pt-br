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
ms.openlocfilehash: 0c7bf18fa823c6301a79c3f989efa73c9e8f628a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372004"
---
# <a name="overview-of-marshaling-in-ccli"></a>Visão geral do Marshaling em C++/CLI

No modo misto, às vezes você deve reunir seus dados entre tipos nativos e gerenciados. A *biblioteca de marshaling* ajuda você a empacotar e converter dados de uma maneira simples.  A biblioteca de marshaling consiste em um `marshal_context` conjunto de funções e uma classe que executa o marshaling para tipos comuns. A biblioteca é definida nestes cabeçalhos no diretório **include/msclr** para sua edição do Visual Studio:

|Cabeçalho|Descrição|
|---------------|-----------------|
|marshal.h|`marshal_context`funções de empacotamento de classe e contexto livre|
|marshal_atl.h| Funções para empacotar tipos ATL|
|marshal_cppstd.h|Funções para os tipos C++ padrão de empacotamento|
|marshal_windows.h|Funções para empacotar tipos de Windows|

O caminho padrão para pasta **msclr** é algo parecido, dependendo de qual edição você tem e o número de compilação:

```cmd
C:\\Program Files (x86)\\Microsoft Visual Studio\\Preview\\Enterprise\\VC\\Tools\\MSVC\\14.15.26528\\include\\msclr
```

Você pode usar a biblioteca de marshaling com ou sem uma [classe marshal_context](../dotnet/marshal-context-class.md). Algumas conversões requerem um contexto. Outras conversões podem ser implementadas usando a função [marshal_as.](../dotnet/marshal-as.md) A tabela a seguir lista as conversões atuais suportadas, se elas requerem um contexto e qual arquivo federal você tem que incluir:

|Do tipo|Para digitar|Método marechal|Incluir arquivo|
|---------------|-------------|--------------------|------------------|
|Sistema::String^|const char\*|Marshal_context|marshal.h|
|const char\*|Sistema::String^|marshal_as|marshal.h|
|Char\*|Sistema::String^|marshal_as|marshal.h|
|Sistema::String^|const wchar_t\*|Marshal_context|marshal.h|
|const wchar_t\*|Sistema::String^|marshal_as|marshal.h|
|wchar_t \*|Sistema::String^|marshal_as|marshal.h|
|Sistema::IntPtr|Lidar com|marshal_as|marshal_windows.h|
|Lidar com|Sistema::IntPtr|marshal_as|marshal_windows.h|
|Sistema::String^|BSTR|Marshal_context|marshal_windows.h|
|BSTR|Sistema::String^|marshal_as|marshal.h|
|Sistema::String^|bstr_t|marshal_as|marshal_windows.h|
|bstr_t|Sistema::String^|marshal_as|marshal_windows.h|
|Sistema::String^|dst::string|marshal_as|marshal_cppstd.h|
|dst::string|Sistema::String^|marshal_as|marshal_cppstd.h|
|Sistema::String^|std::wstring|marshal_as|marshal_cppstd.h|
|std::wstring|Sistema::String^|marshal_as|marshal_cppstd.h|
|Sistema::String^|> de\<char CstringT|marshal_as|marshal_atl.h|
|> de\<char CstringT|Sistema::String^|marshal_as|marshal_atl.h|
|Sistema::String^|> de wchar_t<Cstringt|marshal_as|marshal_atl.h|
|> de wchar_t<Cstringt|Sistema::String^|marshal_as|marshal_atl.h|
|Sistema::String^|Ccombstr|marshal_as|marshal_atl.h|
|Ccombstr|Sistema::String^|marshal_as|marshal_atl.h|

O marshaling requer um contexto somente quando você empacota de tipos de dados nativos e o tipo nativo para o que você está convertendo não tem um destruidor para limpeza automática. O contexto de empacotamento destrói o tipo de dados nativos alocados em seu destruidor. Portanto, as conversões que requerem um contexto serão válidas apenas até que o contexto seja excluído. Para salvar quaisquer valores empacotados, você deve copiar os valores para suas próprias variáveis.

> [!NOTE]
> Se você `NULL`tiver incorporado s em sua seqüência, o resultado de empacotar a seqüência não é garantido. O `NULL`s incorporado pode fazer com que a corda seja truncada ou ela pode ser preservada.

Este exemplo mostra como incluir o diretório msclr em uma declaração de cabeçalho incluir:

`#include "msclr\marshal_cppstd.h"`

A biblioteca de marshaling é extensível para que você possa adicionar seus próprios tipos de marshaling. Para obter mais informações sobre como estender a biblioteca de marshaling, consulte [Como: Estender a Biblioteca de Marshaling](../dotnet/how-to-extend-the-marshaling-library.md).

## <a name="see-also"></a>Confira também

[Biblioteca de suporte do C++](../dotnet/cpp-support-library.md)<br/>
[Como estender a biblioteca de marshaling](../dotnet/how-to-extend-the-marshaling-library.md)
