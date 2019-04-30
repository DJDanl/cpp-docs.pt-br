---
title: 'Como: Usar winmdidl.exe e midlrt.exe para criar arquivos. h de metadados do windows'
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 4be8ba11-c223-44ad-9256-7e1edae9a7bc
ms.openlocfilehash: b9016f05b82e3eb04474d370bd069e8008de5278
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62398102"
---
# <a name="how-to-use-winmdidlexe-and-midlrtexe-to-create-h-files-from-windows-metadata"></a>Como: Usar winmdidl.exe e midlrt.exe para criar arquivos. h de metadados do windows

Winmdidl.exe e midlrt.exe permitem a interação de nível COM entre código C++ nativo e os componentes de tempo de execução do Windows. Winmdidl.exe o utiliza como entrada um arquivo. winmd que contém metadados para um componente de tempo de execução do Windows e produz um arquivo IDL. Midlrt.exe converte o arquivo IDL em arquivos de cabeçalho que o código C++ pode consumir. Ambas as ferramentas são executadas na linha de comando.

Você pode usar essas ferramentas em dois cenários principais:

- Criando arquivos de cabeçalho e IDL personalizado para que um aplicativo C++ gravado usando a biblioteca de modelos de tempo de execução do Windows (WRL) pode consumir um componente de tempo de execução do Windows personalizado.

- Gerando arquivos de proxy e stub para tipos de evento definido pelo usuário em um componente de tempo de execução do Windows. Para obter mais informações, consulte [eventos personalizados e acessadores de evento nos componentes de tempo de execução do Windows](/windows/uwp/winrt-components/custom-events-and-event-accessors-in-windows-runtime-components).

Essas ferramentas são necessárias apenas para analisar arquivos. winmd personalizado. Os arquivos. idl e. h para componentes do sistema operacional Windows já são gerados para você. Por padrão no Windows 8.1, estão localizados em \Program arquivos (x86) \Windows Kits\8.1\Include\winrt\\.

## <a name="location-of-the-tools"></a>Local das ferramentas

Por padrão em [Windows 8.1, winmdidl.exe e midlrt.exe estão localizados em C:\Program Files (x86) \Windows Kits\8.1\\. Versões das ferramentas também estão disponíveis nas pastas \bin\x86\ e \bin\x64\.

## <a name="winmdidl-command-line-arguments"></a>Argumentos de linha de comando Winmdidl

```
Winmdidl.exe [/nologo] [/suppressversioncheck] [/time] [/outdir:dir] [/banner:file] [/utf8] Winmdfile
```

**/nologo**<br/>
Impede a exibição do console do winmdidl mensagem de direitos autorais e o número de versão.

**/suppressversioncheck**<br/>
Não usado.

**/time**<br/>
Exibe o tempo de execução total na saída do console.

**/outdir:**<em>dir</em><br/>
Especifica um diretório de saída. Se o caminho contiver espaços, use aspas. O diretório de saída padrão é  *\<unidade >*: \Users\\*\<username >* \AppData\Local\VirtualStore\Program arquivos (x86) \Microsoft Visual Studio 12.0\\.

**/banner:**<em>file</em><br/>
Especifica um arquivo que contém o texto personalizado a ser precedido de mensagem de direitos autorais do padrão e o número de versão de winmdidl na parte superior do arquivo. idl gerado. Se o caminho contiver espaços, use aspas.

**/utf8**<br/>
Faz com que o arquivo a ser formatado como UTF-8.

*Winmdfile*<br/>
O nome do arquivo. winmd para analisar. Se o caminho contiver espaços, use aspas.

## <a name="midlrt-command-line-arguments"></a>Argumentos de linha de comando do Midlrt

Ver [MIDLRT e do Windows Runtime components](/windows/desktop/Midl/midlrt-and-windows-runtime-components).

## <a name="examples"></a>Exemplos

O exemplo a seguir mostra um comando winmdidl em um prompt de comando do Visual Studio x86. Especifica um diretório de saída e um arquivo que contém o texto da faixa especiais para adicionar ao arquivo. idl gerado.

`C:\Program Files (x86)\Microsoft Visual Studio 12.0>winmdidl /nologo /outdir:c:\users\giraffe\documents\ /banner:c:\users\giraffe\documents\banner.txt "C:\Users\giraffe\Documents\Visual Studio 2013\Projects\Test_for_winmdidl\Debug\Test_for_winmdidl\test_for_winmdidl.winmd"`

O exemplo a seguir mostra a exibição do console do winmdidl que indica que a operação foi bem-sucedida.

**Generating c:\users\giraffe\documents\\\Test_for_winmdidl.idl**

Em seguida, o midlrt é executado no arquivo IDL gerado. Observe que o **metadata_dir** argumento é especificado após o nome do arquivo. idl. O caminho de \WinMetadata\ é obrigatório — ele é o local de winmd.

`C:\Program Files (x86)\Microsoft Visual Studio 12.0> midlrt "c:\users\mblome\documents\test_for_winmdidl.idl" /metadata_dir "C:\Windows\System32\WinMetadata"`

## <a name="remarks"></a>Comentários

O arquivo de saída de uma operação de winmdidl tem o mesmo nome como o arquivo de entrada, mas tem a extensão de nome de arquivo. idl.

Se você estiver desenvolvendo um componente de tempo de execução do Windows que será acessado a partir do WRL, você pode especificar winmdidl.exe e midlrt.exe para ser executado como etapas pós-build para que os arquivos. idl e. h são gerados em cada compilação. Por exemplo, consulte [gerando eventos em componentes de tempo de execução do Windows](/windows/uwp/winrt-components/raising-events-in-windows-runtime-components).