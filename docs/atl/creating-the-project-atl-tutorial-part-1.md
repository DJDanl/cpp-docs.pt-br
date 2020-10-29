---
title: Criando o projeto (Tutorial ATL, parte 1)
ms.custom: get-started-article
ms.date: 08/19/2019
ms.assetid: f6b727d1-390a-4b27-b82f-daadcd9fc059
ms.openlocfilehash: 8a0374fcaf9a18c82e90bde2abc032158ecc537a
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923868"
---
# <a name="creating-the-project-atl-tutorial-part-1"></a>Criando o projeto (Tutorial ATL, parte 1)

Este tutorial orienta você passo a passo por meio de um projeto ATL não atribuído que cria um objeto ActiveX que exibe um polígono. O objeto inclui opções para permitir que o usuário altere o número de lados que compõem o polígono e o código para atualizar a exibição.

> [!NOTE]
> Este tutorial cria o mesmo código-fonte do exemplo de polígono. Se você quiser evitar inserir o código-fonte manualmente, poderá baixá-lo do [Resumo de exemplo de polígono](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/Controls/Polygon). Em seguida, você pode consultar o código-fonte do polígono enquanto trabalha no tutorial ou usá-lo para verificar se há erros em seu próprio projeto.
> Para compilar, abra *PCH. h* ( *stdafx. h* no Visual Studio 2017 e anterior) e substitua:
>
> ```
> #ifndef WINVER
> #define WINVER 0x0400
> #endif
> ```
>
> por
>
> ```
> #ifndef WINVER
> #define WINVER 0x0500
> #define _WIN32_WINNT 0x0500
> #endif
> ```
>
> O compilador ainda se queixará de `regsvr32` não estar saindo corretamente, mas você ainda deve ter a DLL do controle criada e disponível para uso.

### <a name="to-create-the-initial-atl-project-using-the-atl-project-wizard"></a>Para criar o projeto ATL inicial usando o assistente de projeto ATL

1. No Visual Studio 2017 e anterior: **arquivo**  >  **novo**  >  **projeto** . Abra a guia **Visual C++** e selecione **MFC/ATL** . Selecione **projeto ATL** .

   No Visual Studio 2019: escolha **arquivo**  >  **novo**  >  **projeto** , digite "ATL" na caixa de pesquisa e escolha **projeto ATL** .

1. Digite *Polygon* como o nome do projeto.

    O local para o código-fonte geralmente será padrão para \Users \\ \<username> \source\repos e uma nova pasta será criada automaticamente.

1. No Visual Studio 2019, aceite os valores padrão e clique em **OK** .
   No Visual Studio 2017, clique em **OK** para abrir o assistente de **projeto do ATL** . Clique em **configurações do aplicativo** para ver as opções disponíveis. Como esse projeto cria um controle e um controle deve ser um servidor em processo, deixe o tipo de **aplicativo** como uma dll. Clique em **OK** .

O Visual Studio criará o projeto gerando vários arquivos. Você pode exibir esses arquivos em **Gerenciador de soluções** expandindo o `Polygon` objeto. Os arquivos estão listados abaixo.

::: moniker range="<=msvc-150"

|Arquivo|Descrição|
|----------|-----------------|
|Polygon. cpp|Contém a implementação de `DllMain` , `DllCanUnloadNow` , `DllGetClassObject` , `DllRegisterServer` e `DllUnregisterServer` . Também contém o mapa de objetos, que é uma lista dos objetos ATL em seu projeto. Inicialmente, isso está em branco.|
|Polygon. def|Esse arquivo de definição de módulo fornece ao vinculador informações sobre as exportações exigidas pela sua DLL.|
|Polygon. idl|O arquivo de linguagem de definição de interface, que descreve as interfaces específicas para seus objetos.|
|Polígono. rgs|Esse script de registro contém informações para registrar a DLL do seu programa.|
|Polygon. rc|O arquivo de recurso, que inicialmente contém as informações de versão e uma cadeia de caracteres que contém o nome do projeto.|
|Resource.h|O arquivo de cabeçalho do arquivo de recurso.|
|Polygonps. def|Esse arquivo de definição de módulo fornece ao vinculador informações sobre as exportações exigidas pelo proxy e pelo código stub que dão suporte a chamadas em Apartments.|
|stdafx.cpp|O arquivo que irá `#include` *stdafx. h* .|
|stdafx.h|O arquivo que irá `#include` e precompilar os arquivos de cabeçalho da ATL.|

::: moniker-end

::: moniker range=">=msvc-160"

|Arquivo|Descrição|
|----------|-----------------|
|Polygon. cpp|Contém a implementação de `DllMain` , `DllCanUnloadNow` , `DllGetClassObject` , `DllRegisterServer` e `DllUnregisterServer` . Também contém o mapa de objetos, que é uma lista dos objetos ATL em seu projeto. Inicialmente, isso está em branco.|
|Polygon. def|Esse arquivo de definição de módulo fornece ao vinculador informações sobre as exportações exigidas pela sua DLL.|
|Polygon. idl|O arquivo de linguagem de definição de interface, que descreve as interfaces específicas para seus objetos.|
|Polígono. rgs|Esse script de registro contém informações para registrar a DLL do seu programa.|
|Polygon. rc|O arquivo de recurso, que inicialmente contém as informações de versão e uma cadeia de caracteres que contém o nome do projeto.|
|Resource.h|O arquivo de cabeçalho do arquivo de recurso.|
|Polygonps. def|Esse arquivo de definição de módulo fornece ao vinculador informações sobre as exportações exigidas pelo proxy e pelo código stub que dão suporte a chamadas em Apartments.|
|PCH. cpp|O arquivo que será `#include` *PCH. h* .|
|PCH. h|O arquivo que irá `#include` e precompilar os arquivos de cabeçalho da ATL.|

::: moniker-end

1. Em **Gerenciador de soluções** , clique com o botão direito do mouse no `Polygon` projeto.

1. No menu de atalho, clique em **Propriedades** .

1. Clique em **vinculador** . Altere a opção **por redirecionamento** para **Sim** .

1. Clique em **OK** .

Na próxima etapa, você adicionará um controle ao seu projeto.

[Na etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md)

## <a name="see-also"></a>Veja também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
