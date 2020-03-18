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
ms.openlocfilehash: b08abdc0e2c17cb61c0c6a14cd712ec32ea816bd
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438013"
---
# <a name="mfc-activex-controls-licensing-an-activex-control"></a>Controles MFC ActiveX: licenciando um controle ActiveX

O suporte a licenciamento, um recurso opcional dos controles ActiveX, permite que você controle quem é capaz de usar ou distribuir o controle. (Para obter mais discussões sobre problemas de licenciamento, consulte problemas de licenciamento em [atualizando um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md).)

> [!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Este artigo aborda os seguintes tópicos:

- [Visão geral do licenciamento do controle ActiveX](#_core_overview_of_activex_control_licensing)

- [Criando um controle licenciado](#_core_creating_a_licensed_control)

- [Suporte a licenciamento](#_core_licensing_support)

- [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control)

Os controles ActiveX que implementam o licenciamento permitem que você, como desenvolvedor de controle, determine como outras pessoas usarão o controle ActiveX. Você fornece o comprador de controle com o controle e. Arquivo Lic., com o acordo que o comprador pode distribuir o controle, mas não o. Arquivo Lic., com um aplicativo que usa o controle. Isso impede que os usuários desse aplicativo gravem novos aplicativos que usam o controle, sem primeiro licenciar o controle de você.

##  <a name="_core_overview_of_activex_control_licensing"></a>Visão geral do licenciamento do controle ActiveX

Para fornecer suporte de licenciamento para controles ActiveX, a classe [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) fornece uma implementação para várias funções na interface `IClassFactory2`: `IClassFactory2::RequestLicKey`, `IClassFactory2::GetLicInfo`e `IClassFactory2::CreateInstanceLic`. Quando o desenvolvedor do aplicativo de contêiner faz uma solicitação para criar uma instância do controle, uma chamada para `GetLicInfo` é feita para verificar se o controle. O arquivo Lic. está presente. Se o controle for licenciado, uma instância do controle poderá ser criada e colocada no contêiner. Depois que o desenvolvedor terminar de construir o aplicativo de contêiner, outra chamada de função, desta vez para `RequestLicKey`, será feita. Essa função retorna uma chave de licença (uma cadeia de caracteres simples) para o aplicativo de contêiner. Em seguida, a chave retornada é inserida no aplicativo.

A figura a seguir demonstra a verificação de licença de um controle ActiveX que será usado durante o desenvolvimento de um aplicativo de contêiner. Conforme mencionado anteriormente, o desenvolvedor do aplicativo de contêiner deve ter o apropriado. Arquivo Lic. instalado no computador de desenvolvimento para criar uma instância do controle.

![Controle ActiveX licenciado verificado no desenvolvimento](../mfc/media/vc374d1.gif "Controle ActiveX licenciado verificado no desenvolvimento") <br/>
Verificação de um controle ActiveX licenciado durante o desenvolvimento

O próximo processo, mostrado na figura a seguir, ocorre quando o usuário final executa o aplicativo de contêiner.

Quando o aplicativo é iniciado, uma instância do controle geralmente precisa ser criada. O contêiner realiza isso fazendo uma chamada para `CreateInstanceLic`, passando a chave de licença inserida como um parâmetro. Uma comparação de cadeia de caracteres é feita entre a chave de licença inserida e a própria cópia do controle da chave de licença. Se a correspondência for bem-sucedida, uma instância do controle será criada e o aplicativo continuará a ser executado normalmente. Observe que o. O arquivo Lic. não precisa estar presente na máquina do usuário de controle.

![Controle ActiveX licenciado verificado na execução](../mfc/media/vc374d2.gif "Controle ActiveX licenciado verificado na execução") <br/>
Verificação de um controle ActiveX licenciado durante a execução

O licenciamento de controle consiste em dois componentes básicos: código específico na DLL de implementação de controle e no arquivo de licença. O código é composto de duas (ou possivelmente três) chamadas de função e uma cadeia de caracteres, em seguida, chamada de "cadeia de caracteres de licença", que contém um aviso de direitos autorais. Essas chamadas e a cadeia de caracteres de licença são encontradas na implementação de controle (. CPP). O arquivo de licença, gerado pelo assistente de controle ActiveX, é um arquivo de texto com uma declaração de direitos autorais. Ele é nomeado usando o nome do projeto com um. Extensão Lic., por exemplo. LIC. Um controle licenciado deve ser acompanhado pelo arquivo de licença se o uso do tempo de design for necessário.

##  <a name="_core_creating_a_licensed_control"></a>Criando um controle licenciado

Quando você usa o assistente de controle ActiveX para criar a estrutura de controle, é fácil incluir suporte a licenciamento. Quando você especifica que o controle deve ter uma licença de tempo de execução, o assistente de controle ActiveX adiciona código à classe de controle para dar suporte ao licenciamento. O código consiste em funções que usam um arquivo de chave e de licença para verificação de licença. Essas funções também podem ser modificadas para personalizar o licenciamento de controle. Para obter mais informações sobre a personalização de licenças, consulte [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control) mais adiante neste artigo.

#### <a name="to-add-support-for-licensing-with-the-activex-control-wizard-when-you-create-your-control-project"></a>Para adicionar suporte para licenciamento com o assistente de controle ActiveX ao criar seu projeto de controle

1. Use as instruções em [criando um controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md). A página **configurações do aplicativo** do assistente de controle ActiveX contém a opção para criar o controle com a licença de tempo de execução.

O assistente de controle ActiveX agora gera uma estrutura de controle ActiveX que inclui suporte a licenciamento básico. Para obter uma explicação detalhada do código de licenciamento, consulte o próximo tópico.

##  <a name="_core_licensing_support"></a>Suporte a licenciamento

Quando você usa o assistente de controle ActiveX para adicionar suporte de licenciamento a um controle ActiveX, o assistente de controle ActiveX adiciona um código que declara e implementa o recurso de licenciamento adicionado ao cabeçalho de controle e aos arquivos de implementação. Esse código é composto por uma função membro `VerifyUserLicense` e uma função membro `GetLicenseKey`, que substituem as implementações padrão encontradas em [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) . Essas funções recuperam e verificam a licença de controle.

> [!NOTE]
>  Uma terceira função de membro, `VerifyLicenseKey` não é gerada pelo assistente de controle ActiveX, mas pode ser substituída para personalizar o comportamento de verificação de chave de licença.

Essas funções de membro são:

- [VerifyUserLicense](../mfc/reference/coleobjectfactory-class.md#verifyuserlicense)

   Verifica se o controle permite o uso de tempo de design verificando o sistema quanto à presença do arquivo de licença de controle. Essa função é chamada pela estrutura como parte do processamento `IClassFactory2::GetLicInfo` e `IClassFactory::CreateInstanceLic`.

- [GetLicenseKey](../mfc/reference/coleobjectfactory-class.md#getlicensekey)

   Solicita uma chave exclusiva da DLL de controle. Essa chave é inserida no aplicativo de contêiner e usada posteriormente, em conjunto com `VerifyLicenseKey`, para criar uma instância do controle. Essa função é chamada pela estrutura como parte do `IClassFactory2::RequestLicKey`de processamento.

- [VerifyLicenseKey](../mfc/reference/coleobjectfactory-class.md#verifylicensekey)

   Verifica se a chave inserida e a chave exclusiva do controle são as mesmas. Isso permite que o contêiner crie uma instância do controle para seu uso. Essa função é chamada pela estrutura como parte do processamento `IClassFactory2::CreateInstanceLic` e pode ser substituída para fornecer a verificação personalizada da chave de licença. A implementação padrão executa uma comparação de cadeia de caracteres. Para obter mais informações, consulte [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control), mais adiante neste artigo.

###  <a name="_core_header_file_modifications"></a>Modificações de arquivo de cabeçalho

O assistente de controle ActiveX coloca o código a seguir no arquivo de cabeçalho de controle. Neste exemplo, duas funções de membro do objeto de `CSampleCtrl``factory` são declaradas, uma que verifica a presença do controle. O arquivo Lic. e outro que recupera a chave de licença a ser usada no aplicativo que contém o controle:

[!code-cpp[NVC_MFC_AxUI#39](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_1.h)]

###  <a name="_core_implementation_file_modifications"></a>Modificações no arquivo de implementação

O assistente de controle ActiveX coloca as duas instruções a seguir no arquivo de implementação de controle para declarar a cadeia de caracteres da licença e o nome de um deles:

[!code-cpp[NVC_MFC_AxUI#40](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_2.cpp)]

> [!NOTE]
>  Se você modificar `szLicString` de alguma forma, também deverá modificar a primeira linha do controle. O arquivo Lic. ou o licenciamento não funcionará corretamente.

O assistente de controle ActiveX coloca o seguinte código no arquivo de implementação de controle para definir a classe de controle ' `VerifyUserLicense` e `GetLicenseKey` funções:

[!code-cpp[NVC_MFC_AxUI#41](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_3.cpp)]

Por fim, o **Assistente de controle ActiveX** modifica o projeto de controle. Arquivo IDL. A palavra-chave **Licensed** é adicionada à declaração coclass do controle, como no exemplo a seguir:

[!code-cpp[NVC_MFC_AxUI#42](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_4.idl)]

##  <a name="_core_customizing_the_licensing_of_an_activex_control"></a>Personalizando o licenciamento de um controle ActiveX

Como `VerifyUserLicense`, `GetLicenseKey`e `VerifyLicenseKey` são declarados como funções membro virtuais da classe Factory de controle, você pode personalizar o comportamento de licenciamento do controle.

Por exemplo, você pode fornecer vários níveis de licenciamento para o controle substituindo as funções de membro `VerifyUserLicense` ou `VerifyLicenseKey`. Dentro dessa função, você pode ajustar quais propriedades ou métodos são expostos ao usuário de acordo com o nível de licença detectado.

Você também pode adicionar código à função `VerifyLicenseKey` que fornece um método personalizado para informar ao usuário que a criação do controle falhou. Por exemplo, em sua função de membro do `VerifyLicenseKey`, você pode exibir uma caixa de mensagem informando que o controle não foi inicializado e por quê.

> [!NOTE]
>  Outra maneira de personalizar a verificação de licença de controle ActiveX é verificar o banco de dados de registro em busca de uma chave de Registro específica, em vez de chamar `AfxVerifyLicFile`. Para obter um exemplo da implementação padrão, consulte a seção [modificações de arquivo de implementação](#_core_implementation_file_modifications) deste artigo.

Para obter mais discussões sobre problemas de licenciamento, consulte problemas de licenciamento na [atualização de um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md).

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Assistente de controle ActiveX do MFC](../mfc/reference/mfc-activex-control-wizard.md)
