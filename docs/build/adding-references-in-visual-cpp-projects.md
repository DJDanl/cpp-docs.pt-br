---
title: Consumindo bibliotecas e C++ componentes em projetos
ms.date: 12/10/2018
f1_keywords:
- VC.Project.References
helpviewer_keywords:
- Add References Dialog Box (C++)
- .NET Framework (C++), Add References Dialog Box
ms.assetid: 12b8f571-0f21-40b3-9404-5318a57e9cb5
ms.openlocfilehash: a8cd13e27859d09bcaaca1f5f6f1c2750b908fe6
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078781"
---
# <a name="consuming-libraries-and-components"></a>Consumindo bibliotecas e componentes

Geralmente, um C++ projeto precisa chamar funções ou acessar dados em um arquivo binário, como biblioteca estática (arquivos. lib), dll, componente Windows Runtime, componente com ou assembly .net. Nesses casos, você precisa configurar o projeto para que ele possa encontrar esse binário no momento da compilação. As etapas específicas dependem do tipo de seu projeto, do tipo de binário e se o binário está sendo compilado na mesma solução que o seu projeto.

## <a name="consuming-libraries-downloaded-via-vcpkg"></a>Consumindo bibliotecas baixadas via vcpkg

Para consumir uma biblioteca que você baixou usando o Gerenciador de pacotes do **vcpkg** , você pode ignorar as instruções abaixo. Consulte [vcpkg: um C++ Gerenciador de pacotes para Windows, Linux e MacOS](vcpkg.md#integrate-with-visual-studio-windows) para obter mais informações.

## <a name="consuming-static-libraries"></a>Consumindo bibliotecas estáticas

Se seu projeto de biblioteca estática estiver sendo compilado na mesma solução:

1. #<a name="include-the-header-files-for-the-static-library-using-quotation-marks-in-a-typical-solution-the-path-will-start-with-library-project-name-intellisense-will-help-you-find-it"></a>inclua os arquivos de cabeçalho da biblioteca estática usando aspas. Em uma solução típica, o caminho começará com `../<library project name>`. O IntelliSense irá ajudá-lo a encontrá-lo.
2. Adicione uma referência ao projeto de biblioteca estática. Clique com o botão direito do mouse em **referências** no nó do projeto de aplicativo em **Gerenciador de soluções** e escolha **Adicionar referência**.

Se a biblioteca estática não fizer parte da solução:

1. Clique com o botão direito do mouse no nó do projeto de aplicativo em **Gerenciador de soluções** e escolha **Propriedades**.
2. Na página de propriedades **diretórios do vc + +** , adicione o caminho para o diretório em que o arquivo. lib está localizado em **caminhos de biblioteca** e adicione o caminho para os arquivos de cabeçalho de biblioteca nos diretórios de **inclusão**.  
3. Na página de propriedades de **entrada do > do vinculador** , adicione o nome do arquivo. lib a **dependências adicionais**.

## <a name="dynamic-link-libraries"></a>Bibliotecas de vínculo dinâmico

Se a DLL estiver sendo compilada como parte da mesma solução que o aplicativo, siga as mesmas etapas de uma biblioteca estática.

Se a DLL não fizer parte da solução de aplicativo, você precisará do arquivo DLL, dos cabeçalhos com protótipos para as funções e classes exportadas e um arquivo. lib que fornece as informações de vinculação necessárias.

1. Copie a DLL para a pasta de saída do seu projeto ou para outra pasta no caminho de pesquisa padrão do Windows para DLLs. Consulte [ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/dlls/dynamic-link-library-search-order).
2. Siga as etapas 1-3 para bibliotecas estáticas para fornecer os caminhos para os cabeçalhos e o arquivo. lib.

## <a name="com-objects"></a>objetos COM

Se seu aplicativo C++ nativo precisar consumir um objeto com e esse objeto for *registrado*, tudo o que você precisará fazer é chamar COCREATEINSTANCE e passar o CLSID do objeto. O sistema irá encontrá-lo no registro do Windows e carregá-lo. Um C++projeto/CLI pode consumir um objeto com da mesma maneira ou adicionando uma referência a ele na lista de **Adicionar referências > com** e consumindo-o por meio de seu [tempo de execução Callable Wrapper](/dotnet/framework/interop/runtime-callable-wrapper).

## <a name="net-assemblies-and-windows-runtime-components"></a>Assemblies do .NET e componentes do Windows Runtime

Em projetos UWP C++ou/CLI, você consome assemblies .net ou componentes Windows Runtime adicionando uma *referência* ao assembly ou ao componente. No nó **referências** em um projeto UWP ou C++/CLI, você vê referências a componentes usados com frequência. Clique com o botão direito do mouse no nó **referências** em **Gerenciador de soluções** para abrir o **Gerenciador** de referências e navegar pelos componentes adicionais que são conhecidos pelo sistema. Clique no botão **procurar** para navegar para qualquer pasta na qual um componente personalizado está localizado. Como os assemblies do .NET e os componentes do Windows Runtime contêm informações de tipo interno, você pode exibir seus métodos e classes clicando com o botão direito do mouse e escolhendo **Exibir no Pesquisador de objetos**.

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

### <a name="assembly-reference-properties-ccli"></a>Propriedades de referência deC++assembly (/CLI)

As propriedades de referência de assembly estão disponíveis somente para referências a C++.NET Framework assemblies em projetos/CLI. Essas propriedades são exibidas somente quando um .NET Framework assembly é selecionado no painel **referências** . As propriedades não podem ser modificadas.

- **Caminho Relativo**

   Exibe o caminho relativo do diretório do projeto ao assembly referenciado.

### <a name="build-properties"></a>Compilar propriedades

As propriedades a seguir estão disponíveis em vários tipos de referências. Elas permitem que você especifique como compilar com referências.

- **Local da Cópia**

   Especifica se o assembly referenciado será copiado automaticamente para o local de destino durante um build.

- **Para copiar assemblies satélite locaisC++(/CLI)**

   Especifica se os assemblies satélite serão copiados automaticamente do assembly referenciado para o local de destino durante um build. Usado somente se **Local da cópia** for **true**.

- **Saída do Assembly de Referência**

   Especifica que esse assembly é usado no processo de build. Se for **true**, o assembly será usado na linha de comando do compilador durante o build.

### <a name="project-to-project-reference-properties"></a>Propriedades de referência projeto a projeto

As propriedades a seguir definem uma *referência projeto-para-projeto* do projeto selecionado no painel **referências** para outro projeto na mesma solução. Para obter mais informações, consulte [Gerenciando referências em um projeto](/visualstudio/ide/managing-references-in-a-project).

- **Dependências da Biblioteca de Links**

   Quando essa propriedade é **True**, o sistema de projeto é vinculado ao projeto dependente dos arquivos .lib que são produzidos pelo projeto independente. Normalmente, você especificará **True**.

- **Identificador do Projeto**

   Identifica exclusivamente o projeto independente. O valor da propriedade é um GUID de sistema interno que não pode ser modificado.

- **Usar Entradas de Dependência da Biblioteca**

   Quando essa propriedade é **False**, o sistema de projeto não é vinculado ao projeto dependente dos arquivos .obj para a biblioteca produzidos pelo projeto independente. Consequentemente, esse valor desabilita a vinculação incremental. Em geral, você especificará **False** porque o build do aplicativo pode levar muito tempo se há muitos projetos independentes.

### <a name="read-only-reference-properties-com--net"></a>Propriedades de referência somente leitura (COM & .NET)

As propriedades a seguir são encontradas em referências de assembly .NET e COM e não podem ser modificadas.

- **Nome do assembly**

   Exibe o nome do assembly para o assembly referenciado.

- **Cultura**

   Exibe a cultura da referência selecionada.

- **Descrição**

   Exibe a descrição da referência selecionada.

- **Caminho completo**

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

## <a name="see-also"></a>Confira também

[C++referência de página de propriedades do projeto](reference/property-pages-visual-cpp.md)<br>
[Definição das propriedades de compilação do C++ no Visual Studio](working-with-project-properties.md)