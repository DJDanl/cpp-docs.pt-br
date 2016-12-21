---
title: "Controles MFC ActiveX: licenciando um controle ActiveX | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "COleObjectFactory"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe COleObjectFactory, licenciando controles"
  - "Método GetLicenseKey"
  - "licenciando controles ActiveX"
  - "Controles ActiveX MFC, licenciamento"
  - "Método VerifyLicenseKey"
  - "Método VerifyUserLicense"
ms.assetid: cacd9e45-701a-4a1f-8f1f-b0b39f6ac303
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles MFC ActiveX: licenciando um controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Licenciamento suporte, um recurso opcional de controles ActiveX, permite controlar quem pode usar ou distribuir o controle. \(Para verificação adicional de licenciamento problemas, consulte licenciamento problemas em [Atualizando um controle ActiveX existente](../Topic/Upgrading%20an%20Existing%20ActiveX%20Control.md).\)  
  
 Este artigo descreve os seguintes tópicos:  
  
-   [Visão geral de licenciamento do controle ActiveX](#_core_overview_of_activex_control_licensing)  
  
-   [Criando um controle licenciado](#_core_creating_a_licensed_control)  
  
-   [Licenciamento suporte](#_core_licensing_support)  
  
-   [Personalizando licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control)  
  
 Os controles ActiveX que implementam licenciamento permitem que você, como o desenvolvedor de controle, determine como outras pessoas usarão o controle ActiveX.  Você fornece o comprador de controle com o controle e arquivo de .LIC, acordo com o que o comprador pode distribuir o controle, mas não o arquivo de .LIC, com um aplicativo que use o controle.  Isso impede os usuários do aplicativo de novos aplicativos de gravação que usam controle, sem primeiro licenciamento o controle do.  
  
##  <a name="_core_overview_of_activex_control_licensing"></a> Visão geral de licenciamento do controle ActiveX  
 Para fornecer licenciamento suporte para controles ActiveX, a classe de [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) fornece uma implementação para várias funções na interface de **IClassFactory2** : **IClassFactory2::RequestLicKey**, **IClassFactory2::GetLicInfo**, e **IClassFactory2::CreateInstanceLic**.  Quando o desenvolvedor de aplicativos do contêiner faz uma solicitação para criar uma instância de controle, uma chamada a `GetLicInfo` é feito para verificar se o arquivo de controle .LIC está presente.  Se o controle é licenciado, uma instância do controle pode ser criada e colocado no contêiner.  Depois que o desenvolvedor terminar de criar o aplicativo de contêiner, outra chamada de função, desta vez a `RequestLicKey`, é feita.  Esta função retorna uma chave de licença \(uma cadeia de caracteres simples\) no aplicativo do contêiner.  A chave retornada é inserida no aplicativo.  
  
 A figura a seguir demonstra a verificação de licença de um controle ActiveX que é usado durante o desenvolvimento de um aplicativo de contêiner.  Conforme mencionado anteriormente, o desenvolvedor de aplicativos do contêiner deve ter o arquivo apropriado de .LIC instalado no computador de desenvolvimento para criar uma instância do controle.  
  
 ![Verificação de desenvolvimento do controle ActiveX licenciado](../mfc/media/vc374d1.png "vc374D1")  
Verificação de um controle ActiveX licenciado durante o desenvolvimento  
  
 O próximo processo, mostrado na seguinte figura, ocorre quando o usuário final executa o aplicativo do contêiner.  
  
 Quando o aplicativo é iniciado, uma instância do controle das necessidades geralmente de ser criado.  O contêiner está fazendo uma chamada para esse `CreateInstanceLic`, passando a chave inserida de licença como um parâmetro.  Uma comparação de cadeia de caracteres é feita entre a chave inserida de licença e cópia do controle da própria chave de licença.  Se a correspondência for bem\-sucedida, uma instância do controle será criada e o aplicativo continua executando normalmente.  Observe que o arquivo de .LIC não precisa estar presente no computador do usuário do controle.  
  
 ![Verificação de execução do controle ActiveX licenciado](../mfc/media/vc374d2.png "vc374D2")  
Verificação de um controle ActiveX licenciado durante a execução  
  
 Licenciamento do controle consiste em dois componentes básicos: o código específico na DLL de implementação de controle e a licença arquivo.  O código é composto de duas ou três \(possivelmente\) chamadas de função e uma cadeia de caracteres, referenciada assim por diante como “uma cadeia de caracteres” licença, contendo um aviso de direitos reservados.  Essas chamadas e a cadeia de caracteres da licença são encontrados no arquivo de implementação de controle \(.CPP\).  O arquivo de licença, gerado pelo assistente de controle ActiveX, é um arquivo de texto com uma instrução de direitos autorais.  É nomeada com o nome do projeto com uma extensão de .LIC, por exemplo SAMPLE.LIC.  Um controle licenciado deve ser controlado do arquivo de licença se o uso de tempo de design será necessário.  
  
##  <a name="_core_creating_a_licensed_control"></a> Criando um controle licenciado  
 Quando você usa o assistente de controle ActiveX para criar a estrutura de controle, é fácil incluir licenciamento suporte.  Quando você especifica que o controle deve ter uma licença de tempo de execução, o assistente de controle ActiveX adiciona o código na classe de controle para oferecer suporte de licenciamento.  O código consiste em funções que usam uma chave e licenciaram os o arquivo para a verificação de licença.  Essas funções também podem ser alteradas para personalizar licenciamento do controle.  Para obter mais informações sobre a personalização de licença, consulte [Personalizando licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control) posteriormente neste artigo.  
  
#### Para adicionar suporte para licenciamento com o assistente de controle ActiveX quando você criar o projeto de controle  
  
1.  Use as instruções em [Criando um controle ActiveX de MFC](../mfc/reference/creating-an-mfc-activex-control.md).  A página de **Configurações do Aplicativo** do assistente do controle ActiveX contém a opção de criar o controle com a licença de tempo de execução.  
  
 O assistente de controle ActiveX gerencia agora uma estrutura de controle ActiveX que inclui o suporte licenciamento básico.  Para obter uma explicação detalhada do código licenciamento do, consulte o tópico a seguir.  
  
##  <a name="_core_licensing_support"></a> Licenciamento suporte  
 Quando você usa o assistente de controle ActiveX para adicionar licenciamento suporte a um controle ActiveX, o assistente do controle ActiveX adiciona o código que declara e implementa o recurso licenciamento são adicionados ao cabeçalho de controle e arquivos de implementação.  Esse código é composto de uma função de membro de `VerifyUserLicense` e de uma função de membro de `GetLicenseKey` , que substituirá as implementações padrão encontradas em [COleObjectFactory](../mfc/reference/coleobjectfactory-class.md) .  Essas funções recuperam e verificam a licença do controle.  
  
> [!NOTE]
>  Uma terceira função de membro, `VerifyLicenseKey` não é gerada pelo assistente de controle ActiveX, mas pode ser substituída para personalizar o comportamento de verificação da chave de licença.  
  
 Essas funções de membro são:  
  
-   [VerifyUserLicense](../Topic/COleObjectFactory::VerifyUserLicense.md)  
  
     Verifica se o controle permite o uso de tempo de design verificando o sistema para a presença do arquivo de licença do controle.  Essa função é chamado pela estrutura como parte do processamento de **IClassFactory2::GetLicInfo** e **IClassFactory::CreateInstanceLic**.  
  
-   [GetLicenseKey](../Topic/COleObjectFactory::GetLicenseKey.md)  
  
     Solicita uma chave exclusiva da DLL do controle.  Essa chave é inserida no aplicativo de contêiner e usada posteriormente, junto com `VerifyLicenseKey`, para criar uma instância do controle.  Essa função é chamado pela estrutura como parte do processamento de **IClassFactory2::RequestLicKey**.  
  
-   [VerifyLicenseKey](../Topic/COleObjectFactory::VerifyLicenseKey.md)  
  
     Verifica se a chave inserida e a chave exclusiva de controle seja a mesma.  Isso permite que o contêiner crie uma instância do controle para seu uso.  Essa função é chamado pela estrutura como parte do processamento de **IClassFactory2::CreateInstanceLic** e pode ser substituída para fornecer a verificação personalizado de chave de licença.  A implementação padrão executa uma comparação de cadeia de caracteres.  Para obter mais informações, consulte [Personalizando licenciamento de um controle ActiveX](#_core_customizing_the_licensing_of_an_activex_control), posteriormente neste artigo.  
  
###  <a name="_core_header_file_modifications"></a> Alterações de Arquivo de cabeçalho  
 O assistente de controle ActiveX coloca o código a seguir no arquivo de cabeçalho do controle.  Neste exemplo, duas funções de membro do objeto `factory` de `CSampleCtrl` são declaradas, um que verifica a presença de arquivos do controle .LIC e outra que recupera a chave de licença a ser usada no aplicativo que contém o controle:  
  
 [!code-cpp[NVC_MFC_AxUI#39](../mfc/codesnippet/CPP/mfc-activex-controls-licensing-an-activex-control_1.h)]  
  
###  <a name="_core_implementation_file_modifications"></a> Alterações do Arquivo de implementação  
 O assistente de controle ActiveX coloca as duas instruções a seguir no arquivo de implementação de controle para declarar o nome do arquivo de licença e para licenciamento a cadeia de caracteres:  
  
 [!code-cpp[NVC_MFC_AxUI#40](../mfc/codesnippet/CPP/mfc-activex-controls-licensing-an-activex-control_2.cpp)]  
  
> [!NOTE]
>  Se você alterar **szLicString** em qualquer modo, você também deve modificar a primeira linha no arquivo de controle .LIC ou licenciamento não funcionará corretamente.  
  
 O assistente de controle ActiveX coloca o código a seguir no arquivo de implementação de controle para definir as funções de `VerifyUserLicense` e de `GetLicenseKey` das classes de controle:  
  
 [!code-cpp[NVC_MFC_AxUI#41](../mfc/codesnippet/CPP/mfc-activex-controls-licensing-an-activex-control_3.cpp)]  
  
 Finalmente, **ActiveX Control Wizard** modificar o arquivo de projeto .IDL do controle.  A palavra\-chave de **licensed** é adicionado à declaração de coclass de controle, como no exemplo a seguir:  
  
 [!code-cpp[NVC_MFC_AxUI#42](../mfc/codesnippet/CPP/mfc-activex-controls-licensing-an-activex-control_4.idl)]  
  
##  <a name="_core_customizing_the_licensing_of_an_activex_control"></a> Personalizando licenciamento de um controle ActiveX  
 Como `VerifyUserLicense`, `GetLicenseKey`, e `VerifyLicenseKey` são declarados como virtual funções de membro de fábrica de controle de classificação, você pode personalizar o comportamento de licenciamento do controle.  
  
 Por exemplo, você pode fornecer vários níveis de licença para o controle substituindo as funções de membro de `VerifyUserLicense` ou de `VerifyLicenseKey` .  Dentro dessa função que você pode ajustar as propriedades ou os métodos são expostos para o usuário de acordo com o nível de licença detectou que você.  
  
 Você também pode adicionar código à função de `VerifyLicenseKey` que fornece um método personalizado para informar o usuário que controla a criação falhou.  Por exemplo, na função de membro de `VerifyLicenseKey` você pode exibir a caixa de mensagem que indica que o controle não foi inicializado e como.  
  
> [!NOTE]
>  Outra maneira de personalizar a verificação de licença do controle ActiveX é verificar o base de dados do registro para uma chave do Registro específica, em vez de chamar `AfxVerifyLicFile`.  Para obter um exemplo da implementação padrão, consulte a seção de [Alterações do Arquivo de implementação](#_core_implementation_file_modifications) deste artigo.  
  
 Para verificação adicional de licenciamento problemas, consulte licenciamento problemas em [Atualizando um controle ActiveX existente](../Topic/Upgrading%20an%20Existing%20ActiveX%20Control.md).  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md)