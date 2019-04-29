---
title: Consumindo bibliotecas e componentes em projetos do C++
ms.date: 12/10/2018
f1_keywords:
- VC.Project.References
helpviewer_keywords:
- Add References Dialog Box (C++)
- .NET Framework (C++), Add References Dialog Box
ms.assetid: 12b8f571-0f21-40b3-9404-5318a57e9cb5
ms.openlocfilehash: dff057977e6b6ff0c36d3a888bc4d5c3aa778576
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62274783"
---
# <a name="consuming-libraries-and-components"></a>Consumindo bibliotecas e componentes

Geralmente, um projeto C++ precisa chamar funções ou acessar dados em um arquivo binário, como a biblioteca estática (arquivos. lib), DLL, o componente de tempo de execução do Windows, o componente COM ou o assembly .NET. Nesses casos, você precisa configurar o projeto para que ele possa encontrar binário no momento da compilação. As etapas específicas dependem do tipo do seu projeto, o tipo de binário, e se o binário está sendo criado na mesma solução que o seu projeto. 

## <a name="consuming-libraries-downloaded-via-vcpkg"></a>Consumir bibliotecas baixados por meio do vcpkg

Consumir uma biblioteca que você tenha baixado usando o **vcpkg** Gerenciador de pacotes, você pode ignorar as instruções abaixo. Consulte [vcpkg: Um Gerenciador de pacotes de C++ para Windows, Linux e MacOS](vcpkg.md#integrate-with-visual-studio-windows) para obter mais informações.

## <a name="consuming-static-libraries"></a>Consumindo bibliotecas estáticas

Se seu projeto de biblioteca estática está sendo criado na mesma solução:

1. #<a name="include-the-header-files-for-the-static-library-using-quotation-marks-in-a-typical-solution-the-path-will-start-with-library-project-name-intellisense-will-help-you-find-it"></a>inclua os arquivos de cabeçalho para a biblioteca estática usando aspas. Em uma solução típica, o caminho será iniciado com `../<library project name>`. IntelliSense ajudará você a localizá-lo.
2. Adicione uma referência ao projeto de biblioteca estática. Clique duas vezes em **referências** sob o nó de projeto de aplicativo no **Gerenciador de soluções** e escolha **Add Reference**. 

Se a biblioteca estática não é parte da solução:

1. Clique com botão direito no nó do projeto de aplicativo no **Gerenciador de soluções** e, em seguida, escolha **propriedades**. 
2. No **diretórios VC + +** propriedade página, adicione o caminho para o diretório onde o arquivo. lib está localizado em **caminhos de biblioteca** e adicione o caminho para os arquivos de cabeçalho de biblioteca na **diretórios de inclusão** .  
3. No **vinculador > entrada** propriedade página, adicione o nome do arquivo. lib **dependências adicionais**.

## <a name="dynamic-link-libraries"></a>Bibliotecas de vínculo dinâmico

Se a DLL está sendo criada como parte da mesma solução que o aplicativo, siga as mesmas etapas uma biblioteca estática.

Se a DLL não é parte da solução do aplicativo, você precisa que o arquivo DLL, o (s) com protótipos para as funções exportadas e classes e um arquivo. lib que fornece as informações necessárias de vinculação.

1. Copie a DLL para a pasta de saída do seu projeto, ou para outra pasta no caminho de pesquisa padrão do Windows para DLLs. Ver [ordem de pesquisa de biblioteca de vínculo dinâmico](/windows/desktop/dlls/dynamic-link-library-search-order).
2. Siga as etapas 1 a 3 para bibliotecas estáticas fornecer os caminhos para os cabeçalhos e o arquivo. lib.

## <a name="com-objects"></a>objetos COM

Se seu aplicativo C++ nativo precisa consumir um objeto COM, e o objeto está *registrado*, tudo que você precisa fazer é chamar CoCreateInstance e passar o CLSID do objeto. O sistema irá encontrá-lo no registro do Windows e carregá-lo. C + c++ CLI project pode consumir um objeto COM da mesma forma, ou adicionando uma referência a ele da **adicionar referências > COM** lista e consumi-las por meio de seu [(Runtime callable wrapper)](/dotnet/framework/interop/runtime-callable-wrapper). 

## <a name="net-assemblies-and-windows-runtime-components"></a>Assemblies do .NET e componentes de tempo de execução do Windows

Na UWP ou C++projetos /CLI, consumir assemblies do .NET ou componentes de tempo de execução do Windows com a adição de um *referência* para o assembly ou componente. Sob o **referências** nó em uma UWP ou C++projeto /CLI, você verá referências a componentes usados. Com o botão direito no **referências** nó no **Gerenciador de soluções** para abrir o **Gerenciador de referências** e procurar por meio de componentes adicionais que são conhecidos no sistema. Clique o **procurar** botão para navegar para qualquer pasta onde se encontra um componente personalizado. Como assemblies do .NET e componentes de tempo de execução do Windows contêm informações de tipo interno, você pode exibir suas classes e métodos clicando com botão direito e escolhendo **modo de exibição no Pesquisador de objetos**. 

## <a name="reference-properties"></a>Propriedades de referência

Cada tipo de referência tem propriedades. Exiba as propriedades selecionando a referência no Gerenciador de Soluções e pressionando **Alt+Enter** ou clicando com o botão direito do mouse e escolhendo **Propriedades**. Algumas propriedades são somente leitura e algumas podem ser modificadas. No entanto, em geral, você não precisa modificar essas propriedades manualmente.

### <a name="activex-reference-properties"></a>Propriedades de referência do ActiveX

As propriedades de referência do ActiveX estão disponíveis somente para referências a componentes COM. Essas propriedades são exibidas apenas quando um componente COM é selecionado no painel **Referências**. As propriedades não podem ser modificadas.

- **Caminho Completo do Controle**

   Exibe o caminho do diretório do controle referenciado.

- **GUID do Controle**

   Exibe o GUID do controle ActiveX.

- **Versão do Controle**

   Exibe a versão do controle ActiveX referenciado.

- **Nome da Biblioteca de Tipos**

   Exibe o nome da biblioteca de tipos referenciada.

- **Ferramenta Wrapper**

   Exibe a ferramenta usada para compilar o assembly de interoperabilidade da biblioteca COM referenciada ou do controle ActiveX.

### <a name="assembly-reference-properties-ccli"></a>Propriedades de referência de assembly (C++/CLI)

Propriedades da referência do assembly estão disponíveis apenas para as referências aos assemblies do .NET Framework em C++projetos /CLI. Essas propriedades são exibidas apenas quando um assembly do .NET Framework está selecionado na **referências** painel. As propriedades não podem ser modificadas.

- **Caminho Relativo**

   Exibe o caminho relativo do diretório do projeto ao assembly referenciado.

### <a name="build-properties"></a>Propriedades de build

As propriedades a seguir estão disponíveis em vários tipos de referências. Elas permitem que você especifique como compilar com referências.

- **Local da Cópia**

   Especifica se o assembly referenciado será copiado automaticamente para o local de destino durante um build.

- **Copiar Assemblies de satélite de Local (C++/CLI)**

   Especifica se os assemblies satélite serão copiados automaticamente do assembly referenciado para o local de destino durante um build. Usado somente se **Local da cópia** for **true**.

- **Saída do Assembly de Referência**

   Especifica que esse assembly é usado no processo de build. Se for **true**, o assembly será usado na linha de comando do compilador durante o build.

### <a name="project-to-project-reference-properties"></a>Propriedades de referência projeto a projeto

As propriedades a seguir definem um *referência projeto a projeto* do projeto selecionado na **referências** painel para outro projeto na mesma solução. Para obter mais informações, consulte [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).

- **Dependências da Biblioteca de Links**

   Quando essa propriedade é **True**, o sistema de projeto é vinculado ao projeto dependente dos arquivos .lib que são produzidos pelo projeto independente. Normalmente, você especificará **True**.

- **Identificador do Projeto**

   Identifica exclusivamente o projeto independente. O valor da propriedade é um GUID de sistema interno que não pode ser modificado.

- **Usar Entradas de Dependência da Biblioteca**

   Quando essa propriedade é **False**, o sistema de projeto não é vinculado ao projeto dependente dos arquivos .obj para a biblioteca produzidos pelo projeto independente. Consequentemente, esse valor desabilita a vinculação incremental. Em geral, você especificará **False** porque o build do aplicativo pode levar muito tempo se há muitos projetos independentes.

### <a name="read-only-reference-properties-com--net"></a>Propriedades da referência somente leitura (COM e .NET)

As propriedades a seguir são encontradas em referências de assembly .NET e COM e não podem ser modificadas.

- **Nome do assembly**

   Exibe o nome do assembly para o assembly referenciado.

- **Cultura**

   Exibe a cultura da referência selecionada.

- **Descrição**

   Exibe a descrição da referência selecionada.

- **Caminho Completo**

   Exibe o caminho do diretório do assembly referenciado.

- **Identidade**

   Para assemblies .NET Framework, exibe o caminho completo. Para componentes COM, exibe o GUID.

- **Rótulo**

   Exibe o rótulo da referência.

- **Nome**

   Exibe o nome da referência.

- **Token de Chave Pública**

   Exibe o token de chave pública usado para identificar o assembly referenciado.

- **Nome Forte**

   `true` se o assembly referenciado tem um nome forte. Um assembly com nome forte tem uma versão exclusiva.

- **Versão**

   Exibe a versão do assembly referenciado.

## <a name="see-also"></a>Consulte também

[Referência de página de propriedades do projeto C++](reference/property-pages-visual-cpp.md)<br>
[Definição das propriedades de compilação do C++ no Visual Studio](working-with-project-properties.md)