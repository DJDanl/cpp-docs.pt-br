---
title: 'Controles ActiveX MFC: Licenciando um controle ActiveX'
ms.date: 11/19/2018
f1_keywords:
- COleObjectFactory
helpviewer_keywords:
- COleObjectFactory class [MFC], licensing controls
- MFC ActiveX controls [MFC], licensing
- VerifyLicenseKey method [MFC]
- VerifyUserLicense method [MFC]
- GetLicenseKey method [MFC]
- licensing ActiveX controls
ms.assetid: cacd9e45-701a-4a1f-8f1f-b0b39f6ac303
ms.openlocfilehash: eda2ea08c6bd3526befb71c704aa20eba6935b04
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304620"
---
# <a name="mfc-activex-controls-licensing-an-activex-control"></a>Controles ActiveX MFC: Licenciando um controle ActiveX

Suporte de licenciamento, um recurso opcional de controles do ActiveX permite controlar quem é capaz de usar ou distribuir o controle. (Para obter informações adicionais sobre problemas de licenciamento, consulte os problemas de licenciamento na [atualizando um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md).)

> [!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Este artigo aborda os seguintes tópicos:

- [Visão geral do controle ActiveX de licenciamento](#_core_overview_of_activex_control_licensing)

- [Criando um controle licenciado](#_core_creating_a_licensed_control)

- [Suporte de licença](#_core_licensing_support)

- [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control)

Controles ActiveX que implementam licenciamento permitem que você, como desenvolvedor de controle, para determinar como outras pessoas usarão o controle ActiveX. Forneça o comprador de controle com o controle e. Arquivo lic., com o contrato que o comprador pode distribuir o controle, mas não o. Arquivo lic., com um aplicativo que usa o controle. Isso impede que os usuários desse aplicativo de criação de novos aplicativos que usam o controle, sem primeiro licenciando o controle de você.

##  <a name="_core_overview_of_activex_control_licensing"></a> Visão geral do controle ActiveX de licenciamento

Para fornecer suporte de licença para controles ActiveX, o [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) classe fornece uma implementação para várias funções na `IClassFactory2` interface: `IClassFactory2::RequestLicKey`, `IClassFactory2::GetLicInfo`, e `IClassFactory2::CreateInstanceLic`. Quando o desenvolvedor do aplicativo de contêiner faz uma solicitação para criar uma instância do controle, uma chamada para `GetLicInfo` é feita para verificar se o controle. Lic. arquivo está presente. Se o controle é licenciado, uma instância do controle pode ser criada e colocada no contêiner. Depois que o desenvolvedor terminar a construir o aplicativo de contêiner, outra chamada de função, desta vez para `RequestLicKey`, é feita. Essa função retorna uma chave de licença (uma cadeia de caracteres simples) para o aplicativo de contêiner. A chave retornada é, em seguida, inserida no aplicativo.

A figura a seguir demonstra a verificação de licença de um controle ActiveX que será usado durante o desenvolvimento de um aplicativo de contêiner. Conforme mencionado anteriormente, o desenvolvedor do aplicativo de contêiner deve ter as devidas. Arquivo lic. instalado na máquina de desenvolvimento para criar uma instância do controle.

![Licenciado verificado no desenvolvimento de controle de ActiveX](../mfc/media/vc374d1.gif "verificado no desenvolvimento de controle de ActiveX licenciado") <br/>
Verificação de um controle ActiveX licenciado durante o desenvolvimento

O próximo processo, mostrado na figura a seguir ocorre quando o usuário final executar o aplicativo de contêiner.

Quando o aplicativo é iniciado, uma instância do controle geralmente precisa ser criado. O contêiner consegue isso fazendo uma chamada para `CreateInstanceLic`, passando a chave de licença incorporado como um parâmetro. Uma comparação de cadeia de caracteres, em seguida, é feita entre a chave de licença inserida e a cópia do controle a chave de licença. Se a correspondência for bem-sucedida, uma instância do controle é criada e o aplicativo continua sendo executado normalmente. Observe que o. Arquivo lic. não precisa ser presente no computador do usuário do controle.

![Licenciado verificado na execução de controle de ActiveX](../mfc/media/vc374d2.gif "controle ActiveX licenciado verificado em execução") <br/>
Verificação de um controle ActiveX licenciado durante a execução

Licenciamento de controle consiste em dois componentes básicos: o arquivo de licença e de código específicos na DLL de implementação do controle. O código é composto de dois (ou, possivelmente, três) chamadas de função e uma cadeia de caracteres, citado como uma "cadeia de licença", que contém um aviso de direitos autorais. Essas chamadas e a cadeia de caracteres de licença são encontradas na implementação do controle (. Arquivo CPP). O arquivo de licença, gerado pelo Assistente de controle ActiveX, é um arquivo de texto com uma declaração de direitos autorais. Ela é nomeada usando o nome do projeto com um. Extensão lic., por exemplo, exemplo. LIC. Um controle licenciado deve ser acompanhado pelo arquivo de licença, se é necessário usar tempo de design.

##  <a name="_core_creating_a_licensed_control"></a> Criando um controle licenciado

Quando você usa o Assistente de controle ActiveX para criar a estrutura de controle, é fácil incluir suporte de licenciamento. Quando você especifica que o controle deve ter uma licença de tempo de execução, o Assistente de controle ActiveX adiciona código à classe do controle para dar suporte ao licenciamento. O código consiste em funções que usam um arquivo de chave e a licença para a verificação de licença. Essas funções também podem ser modificadas para personalizar o licenciamento de controle. Para obter mais informações sobre a personalização de licença, consulte [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control) mais adiante neste artigo.

#### <a name="to-add-support-for-licensing-with-the-activex-control-wizard-when-you-create-your-control-project"></a>Para adicionar suporte para licenciamento com o Assistente de controle ActiveX, quando você cria seu projeto de controle

1. Use as instruções em [criando um controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md). O **configurações do aplicativo** página do Assistente de controle ActiveX contém a opção de criar o controle com a licença de tempo de execução.

O Assistente de controle ActiveX agora gera uma estrutura de controle ActiveX que inclui o suporte básico de licenciamento. Para obter uma explicação detalhada do código de licenciamento, consulte o próximo tópico.

##  <a name="_core_licensing_support"></a> Suporte de licença

Quando você usa o Assistente de controle ActiveX para adicionar suporte de licença a um controle ActiveX, o Assistente de controle ActiveX adiciona código que declara e implementa a funcionalidade de licenciamento é adicionado ao cabeçalho de controle e implementação de arquivos. Esse código é composto de um `VerifyUserLicense` função de membro e um `GetLicenseKey` função de membro, que substituem as implementações padrão encontradas no [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) . Essas funções recuperam e verifique se a licença do controle.

> [!NOTE]
>  Uma terceira função membro, `VerifyLicenseKey` não é gerada pelo Assistente de controle ActiveX, mas pode ser substituído para personalizar o comportamento de verificação da chave de licença.

Essas funções de membro são:

- [VerifyUserLicense](../mfc/reference/coleobjectfactory-class.md#verifyuserlicense)

   Verifica se o controle permite que o uso de tempo de design, verificando o sistema para verificar a presença do arquivo de licença do controle. Essa função é chamada pelo framework como parte do processamento `IClassFactory2::GetLicInfo` e `IClassFactory::CreateInstanceLic`.

- [GetLicenseKey](../mfc/reference/coleobjectfactory-class.md#getlicensekey)

   Solicita uma chave exclusiva da DLL de controle. Essa chave é inserida no aplicativo de contêiner e posterior, usado em conjunto com `VerifyLicenseKey`, para criar uma instância do controle. Essa função é chamada pelo framework como parte do processamento `IClassFactory2::RequestLicKey`.

- [VerifyLicenseKey](../mfc/reference/coleobjectfactory-class.md#verifylicensekey)

   Verifica se a chave inserida e do controle exclusivo são os mesmos. Isso permite que o contêiner criar uma instância do controle para seu uso. Essa função é chamada pelo framework como parte do processamento `IClassFactory2::CreateInstanceLic` e pode ser substituído para fornecer verificação personalizado da chave de licença. A implementação padrão executa uma comparação de cadeia de caracteres. Para obter mais informações, consulte [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control), mais adiante neste artigo.

###  <a name="_core_header_file_modifications"></a> Modificações de arquivos de cabeçalho

O Assistente de controle ActiveX coloca o código a seguir no arquivo de cabeçalho do controle. Neste exemplo, duas funções de membro `CSampleCtrl`do objeto `factory` são declarados, que verifica a presença do controle. Arquivo lic. e outra que recupera a chave de licença a ser usado no aplicativo que contém o controle:

[!code-cpp[NVC_MFC_AxUI#39](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_1.h)]

###  <a name="_core_implementation_file_modifications"></a> Modificações de arquivos de implementação

O Assistente de controle ActiveX coloca as duas instruções a seguir no arquivo de implementação de controle para declarar o nome do arquivo de licença e a cadeia de caracteres de licença:

[!code-cpp[NVC_MFC_AxUI#40](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_2.cpp)]

> [!NOTE]
>  Se você modificar `szLicString` de qualquer forma, você também deve modificar a primeira linha no controle. Arquivo lic. ou licenciamento não funcionará corretamente.

O Assistente de controle ActiveX coloca o código a seguir no arquivo de implementação de controle para definir a classe de controle `VerifyUserLicense` e `GetLicenseKey` funções:

[!code-cpp[NVC_MFC_AxUI#41](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_3.cpp)]

Por fim, o **Assistente de controle ActiveX** modifica o projeto de controle. Arquivo IDL. O **licenciado** palavra-chave é adicionada à declaração de coclass do controle, como no exemplo a seguir:

[!code-cpp[NVC_MFC_AxUI#42](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_4.idl)]

##  <a name="_core_customizing_the_licensing_of_an_activex_control"></a> Personalizando o licenciamento de um controle ActiveX

Porque `VerifyUserLicense`, `GetLicenseKey`, e `VerifyLicenseKey` são declarados como funções de membro virtual da classe de fábrica de controle, você pode personalizar o comportamento do controle licenciamento.

Por exemplo, você pode fornecer vários níveis de licenciamento para o controle, substituindo o `VerifyUserLicense` ou `VerifyLicenseKey` funções de membro. Dentro dessa função, você pode ajustar quais métodos ou propriedades são expostos para o usuário de acordo com o nível de licença que é detectado.

Você também pode adicionar código para o `VerifyLicenseKey` função que fornece um método personalizado para informar ao usuário que controlam a criação falhou. Por exemplo, em seu `VerifyLicenseKey` caixa de função de membro, você poderia exibir uma mensagem informando que o controle não conseguiu inicializar e por quê.

> [!NOTE]
>  Outra maneira de personalizar a verificação de licença do controle ActiveX é verificar o banco de dados de registro para uma chave de registro específicos, em vez de chamar `AfxVerifyLicFile`. Para obter um exemplo da implementação padrão, consulte a [modificações de arquivos de implementação](#_core_implementation_file_modifications) seção deste artigo.

Para obter informações adicionais sobre problemas de licenciamento, consulte os problemas de licenciamento na [atualizando um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md).

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Assistente de controle ActiveX do MFC](../mfc/reference/mfc-activex-control-wizard.md)
