---
title: 'Controles MFC ActiveX: licenciando um controle ActiveX'
ms.date: 11/19/2018
helpviewer_keywords:
- COleObjectFactory class [MFC], licensing controls
- MFC ActiveX controls [MFC], licensing
- VerifyLicenseKey method [MFC]
- VerifyUserLicense method [MFC]
- GetLicenseKey method [MFC]
- licensing ActiveX controls
ms.assetid: cacd9e45-701a-4a1f-8f1f-b0b39f6ac303
ms.openlocfilehash: aaab4ae3bb13790784a66d53b41dbc3a7cdaec89
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364615"
---
# <a name="mfc-activex-controls-licensing-an-activex-control"></a>Controles MFC ActiveX: licenciando um controle ActiveX

O suporte ao licenciamento, um recurso opcional dos controles ActiveX, permite controlar quem é capaz de usar ou distribuir o controle. (Para discussão adicional de problemas de licenciamento, consulte Problemas de licenciamento [na atualização de um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md).)

> [!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Este artigo discute os seguintes tópicos:

- [Visão geral do licenciamento de controle activex](#_core_overview_of_activex_control_licensing)

- [Criando um controle licenciado](#_core_creating_a_licensed_control)

- [Suporte de licenciamento](#_core_licensing_support)

- [Personalização do licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control)

Os controles ActiveX que implementam o licenciamento permitem que você, como desenvolvedor de controle, determine como outras pessoas usarão o controle ActiveX. Você fornece ao comprador de controle o controle e . Arquivo LIC, com o acordo de que o comprador pode distribuir o controle, mas não o . Arquivo LIC, com um aplicativo que usa o controle. Isso impede que os usuários desse aplicativo escrevam novos aplicativos que usam o controle, sem antes licenciar o controle de você.

## <a name="overview-of-activex-control-licensing"></a><a name="_core_overview_of_activex_control_licensing"></a>Visão geral do licenciamento de controle activex

Para fornecer suporte de licenciamento para controles ActiveX, a classe [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) fornece `IClassFactory2::GetLicInfo`uma `IClassFactory2::CreateInstanceLic`implementação para várias funções na `IClassFactory2` interface: `IClassFactory2::RequestLicKey`, e . Quando o desenvolvedor de aplicativos de contêiner faz uma solicitação `GetLicInfo` para criar uma instância do controle, uma chamada é feita para verificar se o controle . Arquivo LIC está presente. Se o controle for licenciado, uma instância do controle pode ser criada e colocada no recipiente. Depois que o desenvolvedor terminar de construir o aplicativo `RequestLicKey`de contêiner, outra chamada de função, desta vez para , é feita. Esta função retorna uma chave de licença (uma seqüência de caracteres simples) para o aplicativo de contêiner. A chave retornada é então incorporada no aplicativo.

A figura abaixo demonstra a verificação de licença de um controle ActiveX que será usado durante o desenvolvimento de um aplicativo de contêiner. Como mencionado anteriormente, o desenvolvedor de aplicativos de contêiner deve ter o devido . Arquivo LIC instalado na máquina de desenvolvimento para criar uma instância do controle.

![Controle ActiveX licenciado verificado no desenvolvimento](../mfc/media/vc374d1.gif "Controle ActiveX licenciado verificado no desenvolvimento") <br/>
Verificação de um controle ActiveX licenciado durante o desenvolvimento

O próximo processo, mostrado na figura a seguir, ocorre quando o usuário final executa o aplicativo do contêiner.

Quando o aplicativo é iniciado, uma instância do controle geralmente precisa ser criada. O contêiner realiza isso fazendo `CreateInstanceLic`uma chamada para , passando a chave de licença incorporada como um parâmetro. Uma comparação de strings é então feita entre a chave de licença incorporada e a própria cópia da chave de licença do controle. Se a correspondência for bem sucedida, uma instância do controle será criada e o aplicativo continuará a ser executado normalmente. Note que o . O arquivo LIC não precisa estar presente na máquina do usuário de controle.

![Controle ActiveX licenciado verificado na execução](../mfc/media/vc374d2.gif "Controle ActiveX licenciado verificado na execução") <br/>
Verificação de um controle ActiveX licenciado durante a execução

O licenciamento de controle consiste em dois componentes básicos: código específico na implementação de controle DLL e no arquivo de licença. O código é composto por duas (ou possivelmente três) chamadas de função e uma seqüência de caracteres, doravante referida como uma "string de licença", contendo um aviso de direitos autorais. Essas chamadas e a seqüência de licenças são encontradas na implementação do controle (. CPP) arquivo. O arquivo de licença, gerado pelo ActiveX Control Wizard, é um arquivo de texto com uma declaração de direitos autorais. Ele é nomeado usando o nome do projeto com um . Extensão lic, por exemplo SAMPLE. Lic. Um controle licenciado deve ser acompanhado pelo arquivo de licença se o uso do tempo de projeto for necessário.

## <a name="creating-a-licensed-control"></a><a name="_core_creating_a_licensed_control"></a>Criando um controle licenciado

Quando você usa o ActiveX Control Wizard para criar a estrutura de controle, é fácil incluir suporte de licenciamento. Quando você especifica que o controle deve ter uma licença de tempo de execução, o ActiveX Control Wizard adiciona código à classe de controle para suportar o licenciamento. O código consiste em funções que usam uma chave e um arquivo de licença para verificação de licença. Essas funções também podem ser modificadas para personalizar o licenciamento de controle. Para obter mais informações sobre a personalização da licença, consulte [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control) mais tarde neste artigo.

#### <a name="to-add-support-for-licensing-with-the-activex-control-wizard-when-you-create-your-control-project"></a>Para adicionar suporte para licenciamento com o Assistente de Controle ActiveX quando você criar seu projeto de controle

1. Use as instruções na [criação de um controle MFC ActiveX](../mfc/reference/creating-an-mfc-activex-control.md). A **página Configurações** do Aplicativo do Assistente de Controle ActiveX contém a opção de criar o controle com a licença de tempo de execução.

O ActiveX Control Wizard agora gera uma estrutura de controle ActiveX que inclui suporte básico de licenciamento. Para obter uma explicação detalhada do código de licenciamento, consulte o próximo tópico.

## <a name="licensing-support"></a><a name="_core_licensing_support"></a>Suporte de licenciamento

Quando você usa o ActiveX Control Wizard para adicionar suporte de licenciamento a um controle ActiveX, o ActiveX Control Wizard adiciona código que declara e implementa o recurso de licenciamento é adicionado aos arquivos de cabeçalho de controle e implementação. Este código é `VerifyUserLicense` composto por `GetLicenseKey` uma função de membro e uma função de membro, que anulam as implementações padrão encontradas no [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) . Essas funções recuperam e verificam a licença de controle.

> [!NOTE]
> Uma função de `VerifyLicenseKey` terceiro membro, não é gerada pelo Assistente de Controle ActiveX, mas pode ser substituída para personalizar o comportamento de verificação da chave de licença.

Estas funções de membro são:

- [Verifyuserlicense](../mfc/reference/coleobjectfactory-class.md#verifyuserlicense)

   Verifica se o controle permite o uso do tempo de projeto verificando o sistema para a presença do arquivo de licença de controle. Esta função é chamada pela estrutura `IClassFactory2::GetLicInfo` como `IClassFactory::CreateInstanceLic`parte do processamento e .

- [Getlicensekey](../mfc/reference/coleobjectfactory-class.md#getlicensekey)

   Solicita uma chave única do controle DLL. Esta chave é incorporada na aplicação do contêiner `VerifyLicenseKey`e usada posteriormente, em conjunto com , para criar uma instância do controle. Esta função é chamada pela estrutura `IClassFactory2::RequestLicKey`como parte do processamento.

- [Verifylicensekey](../mfc/reference/coleobjectfactory-class.md#verifylicensekey)

   Verifica se a chave incorporada e a chave única do controle são as mesmas. Isso permite que o contêiner crie uma instância do controle para seu uso. Esta função é chamada pela estrutura `IClassFactory2::CreateInstanceLic` como parte do processamento e pode ser substituída para fornecer verificação personalizada da chave de licença. A implementação padrão realiza uma comparação de strings. Para obter mais informações, consulte [Personalizando o Licenciamento de um Controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control), mais tarde neste artigo.

### <a name="header-file-modifications"></a><a name="_core_header_file_modifications"></a>Modificações de arquivo de cabeçalho

O Assistente de Controle ActiveX coloca o seguinte código no arquivo de cabeçalho de controle. Neste exemplo, são declaradas `CSampleCtrl`duas `factory` funções de membro do objeto ', uma que verifica a presença do controle . Arquivo LIC e outro que recupera a chave de licença a ser usada no aplicativo que contém o controle:

[!code-cpp[NVC_MFC_AxUI#39](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_1.h)]

### <a name="implementation-file-modifications"></a><a name="_core_implementation_file_modifications"></a>Modificações de arquivos de implementação

O ActiveX Control Wizard coloca as duas seguintes instruções no arquivo de implementação de controle para declarar o nome do arquivo de licença e a seqüência de licença:

[!code-cpp[NVC_MFC_AxUI#40](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_2.cpp)]

> [!NOTE]
> Se você `szLicString` modificar de alguma forma, você também deve modificar a primeira linha no controle . O arquivo lic ou o licenciamento não funcionarão corretamente.

O Assistente de Controle ActiveX coloca o seguinte código no `VerifyUserLicense` arquivo `GetLicenseKey` de implementação de controle para definir a classe de controle e funções:

[!code-cpp[NVC_MFC_AxUI#41](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_3.cpp)]

Finalmente, o **Assistente de Controle ActiveX** modifica o projeto de controle . Arquivo IDL. A palavra-chave **licenciada** é adicionada à declaração de coclasse do controle, como no exemplo a seguir:

[!code-cpp[NVC_MFC_AxUI#42](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_4.idl)]

## <a name="customizing-the-licensing-of-an-activex-control"></a><a name="_core_customizing_the_licensing_of_an_activex_control"></a>Personalização do licenciamento de um controle ActiveX

Porque `VerifyUserLicense` `GetLicenseKey`, `VerifyLicenseKey` e são declarados como funções de membro virtual da classe de fábrica de controle, você pode personalizar o comportamento de licenciamento do controle.

Por exemplo, você pode fornecer vários níveis de `VerifyUserLicense` licenciamento `VerifyLicenseKey` para o controle, substituindo as funções ou membros. Dentro desta função você pode ajustar quais propriedades ou métodos são expostos ao usuário de acordo com o nível de licença que você detectou.

Você também pode adicionar `VerifyLicenseKey` código à função que fornece um método personalizado para informar o usuário de que a criação de controle falhou. Por exemplo, `VerifyLicenseKey` na sua função de membro você pode exibir uma caixa de mensagem afirmando que o controle falhou em inicializar e por quê.

> [!NOTE]
> Outra maneira de personalizar a verificação da licença de controle ActiveX `AfxVerifyLicFile`é verificar o banco de dados de registro para obter uma chave de registro específica, em vez de ligar . Para um exemplo da implementação padrão, consulte a seção Modificações de arquivo de [implementação](#_core_implementation_file_modifications) deste artigo.

Para discussão adicional de problemas de licenciamento, consulte Problemas de licenciamento [na atualização de um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md).

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md)
