---
title: 'Controles MFC ActiveX: Licenciando um controle ActiveX | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- COleObjectFactory
dev_langs:
- C++
helpviewer_keywords:
- COleObjectFactory class [MFC], licensing controls
- MFC ActiveX controls [MFC], licensing
- VerifyLicenseKey method [MFC]
- VerifyUserLicense method [MFC]
- GetLicenseKey method [MFC]
- licensing ActiveX controls
ms.assetid: cacd9e45-701a-4a1f-8f1f-b0b39f6ac303
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f7b90000279e00c9be8f43ecdb33f8e3dedf6b8a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-activex-controls-licensing-an-activex-control"></a>Controles MFC ActiveX: licenciando um controle ActiveX
Suporte de licenciamento, um recurso opcional de controles ActiveX, permite controlar quem pode usar ou distribuir o controle. (Para obter informações adicionais sobre problemas de licenciamento, consulte problemas de licenciamento no [atualizando um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md).)  
  
 Este artigo aborda os seguintes tópicos:  
  
-   [Visão geral do controle ActiveX de licenciamento](#_core_overview_of_activex_control_licensing)  
  
-   [Criando um controle licenciado](#_core_creating_a_licensed_control)  
  
-   [Suporte de licenciamento](#_core_licensing_support)  
  
-   [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control)  
  
 Controles ActiveX que implementam o licenciamento permitir que você, como desenvolvedor do controle, para determinar como outras pessoas usarão o controle ActiveX. Forneça o comprador de controle com o controle e. Arquivo lic., o contrato que o comprador pode distribuir o controle, mas não o. Arquivo lic., com um aplicativo que usa o controle. Isso impede que os usuários desse aplicativo de gravar novos aplicativos que usam o controle, sem primeiro licenciamento o controle do usuário.  
  
##  <a name="_core_overview_of_activex_control_licensing"></a>Visão geral do controle ActiveX de licenciamento  
 Para oferecer suporte a licença para controles ActiveX, o [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) classe fornece uma implementação para várias funções no **IClassFactory2** interface: **IClassFactory2 :: RequestLicKey**, **IClassFactory2::GetLicInfo**, e **IClassFactory2::CreateInstanceLic**. Quando o desenvolvedor do aplicativo recipiente faz uma solicitação para criar uma instância do controle, uma chamada para `GetLicInfo` é feita para verificar se o controle. Arquivo lic. estiver presente. Se o controle é licenciado, uma instância do controle pode ser criada e colocada no contêiner. Depois que o desenvolvedor terminou de criar o aplicativo de contêiner, outra chamada de função, desta vez para `RequestLicKey`, é feita. Essa função retorna uma chave de licença (uma cadeia de caracteres simples) para o aplicativo de contêiner. A chave retornada é então incorporada no aplicativo.  
  
 A figura a seguir demonstra a verificação da licença de um controle ActiveX que será usado durante o desenvolvimento de um aplicativo de contêiner. Conforme mencionado anteriormente, o desenvolvedor do aplicativo de contêiner deve ter o próprio. Arquivo lic. instalado no computador de desenvolvimento para criar uma instância do controle.  
  
 ![Licenciado controle ActiveX verificado em desenvolvimento](../mfc/media/vc374d1.gif "vc374d1")  
Verificação de um controle ActiveX licenciado durante o desenvolvimento  
  
 O próximo processo, mostrado na figura a seguir, ocorre quando o usuário final executa o aplicativo de contêiner.  
  
 Quando o aplicativo é iniciado, uma instância do controle geralmente precisa ser criado. O contêiner consegue isso fazendo uma chamada para `CreateInstanceLic`, passando a chave de licença inserida como um parâmetro. Uma comparação de cadeia de caracteres é feita entre a chave de licença inserida e a cópia do controle da chave de licença. Se a correspondência for bem-sucedida, uma instância do controle é criada e o aplicativo continua sendo executado normalmente. Observe que o. Arquivo lic. não precisa ser presente no computador do usuário do controle.  
  
 ![Licenciado controle ActiveX verificado em execução](../mfc/media/vc374d2.gif "vc374d2")  
Verificação de um controle ActiveX licenciado durante a execução  
  
 Licenciamento de controle consiste em dois componentes básicos: código específico na implementação do controle DLL e o arquivo de licença. O código é composto de dois (ou possivelmente três) chamadas de função e uma cadeia de caracteres, citado como uma "cadeia de licença", que contém um aviso de direitos autorais. Essas chamadas e a cadeia de caracteres de licença são encontradas na implementação de controle (. Arquivo CPP). O arquivo de licença, gerado pelo Assistente de controle ActiveX, é um arquivo de texto com uma declaração de direitos autorais. Ele é nomeado usando o nome do projeto com uma. Extensão de lic., por exemplo, exemplo. LIC. Um controle licenciado deve ser acompanhado pelo arquivo de licença se for necessário usar tempo de design.  
  
##  <a name="_core_creating_a_licensed_control"></a>Criando um controle licenciado  
 Quando você usa o Assistente de controle ActiveX para criar a estrutura de controle, é fácil incluir suporte de licenciamento. Quando você especificar que o controle deve ter uma licença de tempo de execução, o Assistente de controle ActiveX adiciona código para a classe de controle para oferecer suporte ao licenciamento. O código consiste em funções que usam um arquivo de chave de licença para a verificação da licença. Essas funções também podem ser modificadas para personalizar o licenciamento do controle. Para obter mais informações sobre a personalização de licença, consulte [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control) posteriormente neste artigo.  
  
#### <a name="to-add-support-for-licensing-with-the-activex-control-wizard-when-you-create-your-control-project"></a>Para adicionar suporte para licenciamento com o Assistente de controle ActiveX quando você criar o projeto de controle  
  
1.  Use as instruções em [criando um controle ActiveX MFC](../mfc/reference/creating-an-mfc-activex-control.md). O **configurações de aplicativo** página do Assistente de controle ActiveX contém a opção de criar o controle com a licença de tempo de execução.  
  
 O Assistente de controle ActiveX agora gera uma estrutura de controle ActiveX que inclui o suporte básico de licenciamento. Para obter uma explicação detalhada do código de licenciamento, consulte o próximo tópico.  
  
##  <a name="_core_licensing_support"></a>Suporte de licenciamento  
 Quando você usar o Assistente de controle ActiveX para adicionar suporte de licenciamento para um controle ActiveX, o Assistente de controle ActiveX adiciona código que declara e implementa a funcionalidade de licenciamento é adicionado ao cabeçalho de controle e implementação de arquivos. Esse código é composto de um `VerifyUserLicense` função de membro e um `GetLicenseKey` a função de membro, que substituem as implementações padrão encontradas no [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) . Essas funções recuperam e verifique se a licença do controle.  
  
> [!NOTE]
>  Uma função de membro de terceiro, `VerifyLicenseKey` não é gerada pelo Assistente de controle ActiveX, mas pode ser substituído para personalizar o comportamento de verificação da chave de licença.  
  
 Essas funções de membro são:  
  
-   [VerifyUserLicense](../mfc/reference/coleobjectfactory-class.md#verifyuserlicense)  
  
     Verifica se o controle permite a utilização de tempo de design verificando o sistema para verificar a presença do arquivo de licença do controle. Essa função é chamada pelo framework como parte do processamento **IClassFactory2::GetLicInfo** e **IClassFactory::CreateInstanceLic**.  
  
-   [GetLicenseKey](../mfc/reference/coleobjectfactory-class.md#getlicensekey)  
  
     Solicita uma chave exclusiva do controle DLL. Essa chave é inserida no aplicativo de contêiner e posterior, usada em conjunto com `VerifyLicenseKey`, para criar uma instância do controle. Essa função é chamada pelo framework como parte do processamento **IClassFactory2::RequestLicKey**.  
  
-   [VerifyLicenseKey](../mfc/reference/coleobjectfactory-class.md#verifylicensekey)  
  
     Verifica se a chave inserida e chave exclusiva do controle são os mesmos. Isso permite que o contêiner criar uma instância do controle para seu uso. Essa função é chamada pelo framework como parte do processamento **IClassFactory2::CreateInstanceLic** e pode ser substituído para fornecer verificação personalizada da chave de licença. A implementação padrão executa uma comparação de cadeia de caracteres. Para obter mais informações, consulte [Personalizando o licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control), mais adiante neste artigo.  
  
###  <a name="_core_header_file_modifications"></a>Modificações de arquivos de cabeçalho  
 O Assistente de controle ActiveX coloca o código a seguir no arquivo de cabeçalho de controle. Neste exemplo, duas funções de membro de `CSampleCtrl`do objeto `factory` são declaradas, que verifica a presença do controle. Arquivo lic. e outra que recupera a chave de licença a ser usado no aplicativo que contém o controle:  
  
 [!code-cpp[NVC_MFC_AxUI#39](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_1.h)]  
  
###  <a name="_core_implementation_file_modifications"></a>Modificações de arquivos de implementação  
 O Assistente de controle ActiveX coloca as duas instruções a seguir no arquivo de implementação de controle para declarar o nome do arquivo de licença e a cadeia de caracteres de licença:  
  
 [!code-cpp[NVC_MFC_AxUI#40](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_2.cpp)]  
  
> [!NOTE]
>  Se você modificar **szLicString** de qualquer forma, você também deve modificar a primeira linha no controle. Arquivo lic. ou licenciamento não funcionará corretamente.  
  
 O Assistente de controle ActiveX coloca o código a seguir no arquivo de implementação de controle para definir a classe de controle `VerifyUserLicense` e `GetLicenseKey` funções:  
  
 [!code-cpp[NVC_MFC_AxUI#41](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_3.cpp)]  
  
 Por fim, o **Assistente de controle ActiveX** modifica o projeto de controle. Arquivo IDL. O **licenciado** palavra-chave é adicionada à declaração coclass de controle, como no exemplo a seguir:  
  
 [!code-cpp[NVC_MFC_AxUI#42](../mfc/codesnippet/cpp/mfc-activex-controls-licensing-an-activex-control_4.idl)]  
  
##  <a name="_core_customizing_the_licensing_of_an_activex_control"></a>Personalizando o licenciamento de um controle ActiveX  
 Porque `VerifyUserLicense`, `GetLicenseKey`, e `VerifyLicenseKey` são declaradas como funções de membro virtual da classe de fábrica de controle, você pode personalizar o comportamento do controle licenciamento.  
  
 Por exemplo, você pode fornecer vários níveis de licenciamento para o controle, substituindo o `VerifyUserLicense` ou `VerifyLicenseKey` funções de membro. Dentro dessa função, você pode ajustar quais propriedades ou métodos são expostos para o usuário de acordo com o nível de licença que é detectado.  
  
 Você também pode adicionar código para o `VerifyLicenseKey` função que fornece um método personalizado para informar ao usuário que controlam a criação falha. Por exemplo, em seu `VerifyLicenseKey` caixa de função de membro, você pode exibir uma mensagem informando que o controle não conseguiu inicializar e por quê.  
  
> [!NOTE]
>  Outra maneira de personalizar a verificação de licença do controle ActiveX é verificar o banco de dados de registro para uma chave de registro específicos, em vez de chamar `AfxVerifyLicFile`. Para obter um exemplo da implementação do padrão, consulte o [modificações de arquivos de implementação](#_core_implementation_file_modifications) deste artigo.  
  
 Para obter informações adicionais sobre problemas de licenciamento, consulte problemas de licenciamento no [atualizando um controle ActiveX existente](../mfc/upgrading-an-existing-activex-control.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Assistente de controle ActiveX do MFC](../mfc/reference/mfc-activex-control-wizard.md)

