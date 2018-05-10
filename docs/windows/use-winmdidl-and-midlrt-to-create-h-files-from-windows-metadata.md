---
title: 'Como: usar winmdidl.exe e midlrt.exe para criar arquivos. h de metadados do windows | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 4be8ba11-c223-44ad-9256-7e1edae9a7bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 06fef7449a540fbd3cddc2d38c9ce7483a7b5d55
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="how-to-use-winmdidlexe-and-midlrtexe-to-create-h-files-from-windows-metadata"></a>Como usar winmdidl.exe e midlrt.exe para criar arquivos .h a partir de metadados do Windows
Winmdidl.exe e midlrt.exe habilitar a interação COM nível entre o código C++ nativo e componentes de tempo de execução do Windows. Winmdidl.exe o utiliza como entrada um arquivo. winmd que contém metadados para um componente de tempo de execução do Windows e produz um arquivo IDL. Midlrt.exe converte o arquivo IDL em arquivos de cabeçalho que pode consumir o código C++. Execute as ferramentas na linha de comando.  
  
 Você pode usar essas ferramentas em dois cenários principais:  
  
-   Criando arquivos de cabeçalho e IDL personalizado para que um aplicativo C++ gravado usando a biblioteca de modelo de tempo de execução do Windows (WRL) pode consumir um componente personalizado do Windows Runtime.  
  
-   Gerar arquivos de proxy e stub para tipos de evento definido pelo usuário em um componente de tempo de execução do Windows. Para obter mais informações, consulte [eventos personalizados e acessadores de evento nos componentes do Windows Runtime](/uwp/winrt-components/custom-events-and-event-accessors-in-windows-runtime-components).  
  
 Essas ferramentas são necessárias somente para analisar arquivos. winmd personalizado. Os arquivos. idl e. h para componentes do sistema operacional Windows já são gerados para você. Por padrão em [!INCLUDE[win81](../misc/includes/win81_md.md)], eles estão localizados em \Program arquivos (x86) \Windows Kits\8.1\Include\winrt\\.  
  
## <a name="location-of-the-tools"></a>Local das ferramentas  
 Por padrão em [!INCLUDE[win81](../misc/includes/win81_md.md)], winmdidl.exe e midlrt.exe estão localizados em C:\Program Files (x86) \Windows Kits\8.1\\. Versões das ferramentas também estão disponíveis nas pastas \bin\x86\ e \bin\x64\.  
  
## <a name="winmdidl-command-line-arguments"></a>Argumentos de linha de comando Winmdidl  
  
```  
Winmdidl.exe [/nologo] [/supressversioncheck] [/time] [/outdir:dir] [/banner:file] [/utf8] Winmdfile  
```  
  
 `/nologo`  
 Impede a exibição do console do winmdidl mensagem de direitos autorais e o número de versão.  
  
 `/supressversioncheck`  
 Não usado.  
  
 `/time`  
 Exibe o tempo de execução total na saída do console.  
  
 /outdir:\<dir >  
 Especifica um diretório de saída. Se o caminho contiver espaços, use aspas. O diretório de saída padrão é  *\<drive >*: \Users\\*\<nome de usuário >* \AppData\Local\VirtualStore\Program arquivos (x86) \Microsoft Visual Studio 12.0\\.  
  
 `/banner:<file>`  
 Especifica um arquivo que contém o texto personalizado precede a mensagem de direitos autorais padrão e o número da versão winmdidl na parte superior do arquivo. idl gerado. Se o caminho contiver espaços, use aspas.  
  
 `/utf8`  
 Faz com que o arquivo a ser formatado como UTF-8.  
  
 `Winmdfile`  
 O nome do arquivo. winmd para analisar. Se o caminho contiver espaços, use aspas.  
  
## <a name="midlrt-command-line-arguments"></a>Argumentos de linha de comando Midlrt  
 Consulte [componentes de tempo de execução do Windows e MIDLRT](http://msdn.microsoft.com/library/windows/desktop/hh869900\(v=vs.85\).aspx).  
  
## <a name="examples"></a>Exemplos  
 O exemplo a seguir mostra um comando winmdidl em um prompt de comando do Visual Studio x86. Especifica um diretório de saída e um arquivo que contém o texto da faixa especiais para adicionar ao arquivo. idl gerado.  
  
 **C:\Program arquivos (x86) \Microsoft 12.0 do Visual Studio > winmdidl /nologo /outdir:c:\users\giraffe\documents\ /banner:c:\users\giraffe\documents\banner.txt "C:\Users\giraffe\Documents\Visual Studio 2013\Projects\Test_for_winmdidl\Debug\ Test_for_winmdidl\test_for_winmdidl.winmd"**  
  
 O exemplo a seguir mostra a exibição do console de winmdidl que indica que a operação foi bem-sucedida.  
  
 **Gerando c:\users\giraffe\documents\\\Test_for_winmdidl.idl**  
  
 Em seguida, midlrt é executado no arquivo IDL gerado. Observe que o **metadata_dir** argumento for especificado após o nome do arquivo. idl. O caminho de \WinMetadata\ é obrigatório — é o local para winmd.  
  
 **C:\Program arquivos (x86) \Microsoft 12.0 do Visual Studio > midlrt "c:\users\mblome\documents\test_for_winmdidl.idl" /metadata_dir "C:\Windows\System32\WinMetadata"**  
  
## <a name="remarks"></a>Comentários  
 O arquivo de saída de uma operação de winmdidl tem o mesmo nome como o arquivo de entrada, mas tem a extensão de nome de arquivo. idl.  
  
 Se você estiver desenvolvendo um componente de tempo de execução do Windows que será acessado a partir de WRL, você pode especificar winmdidl.exe e midlrt.exe para ser executado como etapas de pós-compilação para que os arquivos. idl e h são gerados em cada compilação. Para obter um exemplo, consulte [acionando eventos em componentes de tempo de execução do Windows](/uwp/winrt-components/raising-events-in-windows-runtime-components).