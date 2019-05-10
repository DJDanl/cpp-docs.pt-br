---
title: Criando o projeto (Tutorial ATL, parte 1)
ms.custom: get-started-article
ms.date: 05/06/2019
ms.assetid: f6b727d1-390a-4b27-b82f-daadcd9fc059
ms.openlocfilehash: 292faf1769baa2e1c3fc6e52ba6df065cf08766e
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221409"
---
# <a name="creating-the-project-atl-tutorial-part-1"></a>Criando o projeto (Tutorial ATL, parte 1)

Este tutorial orienta você passo a passo por meio de um projeto ATL nonattributed que cria um objeto ActiveX que exibe um polígono. O objeto inclui opções para permitir que o usuário alterar o número de lados que compõe o polígono e o código para atualizar a exibição.

> [!NOTE]
> ATL e MFC não têm suporte em geral nas edições Express do Visual Studio.

> [!NOTE]
> Este tutorial cria o mesmo código-fonte como o exemplo de polígono. Se você quiser evitar inserir manualmente o código-fonte, você pode baixá-lo partir o [abstrata de exemplo de polígono](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/Controls/Polygon). Em seguida, você pode consultar o código-fonte polígono conforme você trabalha com este tutorial, ou usá-lo para verificar se há erros em seu próprio projeto.
> Para compilar, abra o Stdafx. h e substitua:
> ```
> #ifndef WINVER
> #define WINVER 0x0400
> #endif
> ```
> with
> ```
> #ifndef WINVER
> #define WINVER 0x0500
> #define _WIN32_WINNT 0x0500
> #endif
> ```
> O compilador reclamará ainda sobre `regsvr32` não sair corretamente, mas você ainda deve ter a DLL do controle interno e está disponível para uso.

### <a name="to-create-the-initial-atl-project-using-the-atl-project-wizard"></a>Para criar o projeto ATL inicial usando o Assistente de projeto do ATL

1. No Visual Studio 2017 e versões anteriores: **Arquivo** > **novos** > **projeto**. Abrir o **Visual C++**  e selecione **MFC/ATL**. Selecione **projeto da ATL**.

   No Visual Studio de 2019: Escolher **arquivo** > **New** > **projeto**, digite "atl" na caixa de pesquisa e escolha **projeto ATL**.

1. Tipo de *polígono* como o nome do projeto.

    O local para o código-fonte normalmente padrão será \Users\\\<username > \source\repos e uma nova pasta serão criada automaticamente.

1. Clique em **Okey** e o **projeto ATL** assistente é aberto.

1. Clique em **configurações do aplicativo** para ver as opções disponíveis.

1. À medida que você está criando um controle e um controle deve ser um servidor em processo, deixar o **tipo de aplicativo** como uma DLL.

1. Deixe as outras opções com seus valores padrão e, em seguida, clique em **Okey**.

O **ATL Project Wizard** criará o projeto por meio da geração de vários arquivos. Você pode exibir esses arquivos no **Gerenciador de soluções** expandindo o `Polygon` objeto. Os arquivos estão listados abaixo.

|Arquivo|Descrição|
|----------|-----------------|
|Polygon.cpp|Contém a implementação do `DllMain`, `DllCanUnloadNow`, `DllGetClassObject`, `DllRegisterServer`, e `DllUnregisterServer`. Também contém o mapa de objeto, que é uma lista dos objetos em seu projeto ATL. Isso é inicialmente em branco.|
|Polygon.def|Esse arquivo de definição de módulo fornece o vinculador com informações sobre exportações exigida pela sua DLL.|
|Polygon.idl|O interface arquivo linguagem de definição, que descreve as interfaces específicas para seus objetos.|
|Polygon.rgs|Esse script de registro contém informações para registrar a DLL do seu programa.|
|Polygon.rc|O arquivo de recurso, que inicialmente contém as informações de versão e uma cadeia de caracteres que contém o nome do projeto.|
|Resource.h|O arquivo de cabeçalho do arquivo de recurso.|
|Polygonps.def|Esse arquivo de definição de módulo fornece o vinculador com informações sobre exportações exigida pelo código de proxy e stub que dão suporte a chamadas entre apartments.|
|stdafx.cpp|O arquivo que será `#include` os arquivos de implementação de ATL.|
|stdafx.h|O arquivo que será `#include` os arquivos de cabeçalho da ATL.|

1. Na **Gerenciador de soluções**, clique com botão direito do `Polygon` projeto.

1. No menu de atalho, clique em **propriedades**.

1. Clique em **vinculador**. Alterar o **por UserRedirection** opção **Sim**.

1. Clique em **OK**.

A próxima etapa, você adicionará um controle ao seu projeto.

[Para a etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
