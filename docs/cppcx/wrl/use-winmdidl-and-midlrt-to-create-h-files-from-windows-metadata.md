---
title: Como usar winmdidl.exe e midlrt.exe para criar arquivos .h a partir de metadados do Windows
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 4be8ba11-c223-44ad-9256-7e1edae9a7bc
ms.openlocfilehash: 3aa7cd28a37ec7187cc3c87927a83e45eeda2a4e
ms.sourcegitcommit: 5f276064779d90a4cfda758f89e0c0f1e4d1a188
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/09/2020
ms.locfileid: "75791664"
---
# <a name="how-to-use-winmdidlexe-and-midlrtexe-to-create-h-files-from-windows-metadata"></a>Como usar winmdidl.exe e midlrt.exe para criar arquivos .h a partir de metadados do Windows

O Winmdidl. exe e o midlrt. exe permitem a interação de nível C++ com entre o código nativo e os componentes do Windows Runtime. O Winmdidl. exe usa como entrada um arquivo. winmd que contém metadados para um componente Windows Runtime e gera um arquivo IDL. Midlrt. exe converte esse arquivo IDL em arquivos de cabeçalho que C++ o código pode consumir. Ambas as ferramentas são executadas na linha de comando.

Você usa essas ferramentas em dois cenários principais:

- Criar arquivos IDL e de cabeçalho personalizados para que C++ um aplicativo escrito usando a WRL (biblioteca de modelos de Windows Runtime) possa consumir um componente de Windows Runtime personalizado.

- Gerando arquivos de proxy e stub para tipos de eventos definidos pelo usuário em um componente Windows Runtime. Para obter mais informações, consulte [eventos personalizados e acessadores de eventos em componentes do Windows Runtime](/windows/uwp/winrt-components/custom-events-and-event-accessors-in-windows-runtime-components).

Essas ferramentas são necessárias apenas para a análise de arquivos. winmd personalizados. Os arquivos. idl e. h dos componentes do sistema operacional Windows já foram gerados para você. Por padrão, no Windows 8.1, eles estão localizados em \Program Files (x86) \Windows Kits\8.1\Include\winrt\\.

## <a name="location-of-the-tools"></a>Local das ferramentas

Por padrão, em [Windows 8.1, winmdidl. exe e midlrt. exe estão localizados em C:\Arquivos de programas (x86) \Windows Kits\8.1\\. As versões das ferramentas também estão disponíveis nas pastas \bin\x86\ e \bin\x64\.

## <a name="winmdidl-command-line-arguments"></a>Argumentos de linha de comando Winmdidl

```
Winmdidl.exe [/nologo] [/suppressversioncheck] [/time] [/outdir:dir] [/banner:file] [/utf8] Winmdfile
```

**/nologo**<br/>
Impede a exibição do console da mensagem de direitos autorais e do número de versão do winmdidl.

**/suppressversioncheck**<br/>
Não usado.

**/time**<br/>
Exibe o tempo de execução total na saída do console.

**/OutDir:** <em>dir</em><br/>
Especifica um diretório de saída. Se o caminho contiver espaços, use aspas. O diretório de saída padrão é *\<unidade >* : \users\\ *\<nome de usuário >* arquivos \AppData\Local\VirtualStore\Program (x86) \microsoft Visual Studio 12,0\\.

**/banner:** <em>file</em><br/>
Especifica um arquivo que contém texto personalizado para preceder a mensagem de direitos autorais padrão e o número de versão winmdidl na parte superior do arquivo. idl gerado. Se o caminho contiver espaços, use aspas.

**/utf8**<br/>
Faz com que o arquivo seja formatado como UTF-8.

*Winmdfile*<br/>
O nome do arquivo. winmd a ser analisado. Se o caminho contiver espaços, use aspas.

## <a name="midlrt-command-line-arguments"></a>Argumentos de linha de comando Midlrt

Consulte [MIDLRT e componentes de Windows Runtime](/windows/win32/Midl/midlrt-and-windows-runtime-components).

## <a name="examples"></a>Exemplos

O exemplo a seguir mostra um comando winmdidl em um prompt de comando do Visual Studio x86. Ele especifica um diretório de saída e um arquivo que contém texto de faixa especial para adicionar ao arquivo. idl gerado.

`C:\Program Files (x86)\Microsoft Visual Studio 12.0>winmdidl /nologo /outdir:c:\users\giraffe\documents\ /banner:c:\users\giraffe\documents\banner.txt "C:\Users\giraffe\Documents\Visual Studio 2013\Projects\Test_for_winmdidl\Debug\Test_for_winmdidl\test_for_winmdidl.winmd"`

O exemplo a seguir mostra a exibição do console de winmdidl que indica que a operação foi bem-sucedida.

**Gerando c:\users\giraffe\documents\\\ Test_for_winmdidl. idl**

Em seguida, midlrt é executado no arquivo IDL gerado. Observe que o argumento **metadata_dir** é especificado após o nome do arquivo. idl. O caminho de \WinMetadata\ é necessário — é o local para Windows. winmd.

`C:\Program Files (x86)\Microsoft Visual Studio 12.0> midlrt "c:\users\username\documents\test_for_winmdidl.idl" /metadata_dir "C:\Windows\System32\WinMetadata"`

## <a name="remarks"></a>Comentários

O arquivo de saída de uma operação winmdidl tem o mesmo nome que o arquivo de entrada, mas tem a extensão de nome de arquivo. idl.

Se você estiver desenvolvendo um componente Windows Runtime que será acessado por meio do WRL, poderá especificar winmdidl. exe e midlrt. exe para executar como etapas de pós-compilação para que os arquivos. idl e. h sejam gerados em cada compilação. Para obter um exemplo, consulte [gerando eventos em componentes Windows Runtime](/windows/uwp/winrt-components/raising-events-in-windows-runtime-components).