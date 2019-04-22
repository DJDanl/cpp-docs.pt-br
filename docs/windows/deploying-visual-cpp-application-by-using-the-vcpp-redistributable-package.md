---
title: Implantar um aplicativo usando o Pacote Redistribuível (C++)
ms.date: 09/17/2018
helpviewer_keywords:
- walkthrough, deploying a Visual C++ application by using the redistributable package
ms.assetid: e59becbf-b8c6-4c8e-bab3-b69cc1ed3e5e
ms.openlocfilehash: ccf6b74096894c2e48258e6e0a60b807c7c6c5b4
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58786167"
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-the-visual-c-redistributable-package"></a>Passo a passo: Implantação de um aplicativo em Visual C++ usando o Pacote Redistribuível do Visual C++

Este artigo passo a passo descreve como usar o Pacote Redistribuível do Visual C++ para implantar um aplicativo do Visual C++.

## <a name="prerequisites"></a>Pré-requisitos

É necessário ter estes componentes para concluir este passo a passo:

- Um computador que tenha o Visual Studio instalado.

- Um computador adicional que não tenha as bibliotecas do Visual C++.

### <a name="to-use-the-visual-c-redistributable-package-to-deploy-an-application"></a>Para usar o Pacote Redistribuível do Visual C++ para implantar um aplicativo

1.  Criar e compilar um aplicativo do MFC, seguindo as etapas em [Passo a passo: Implantando um aplicativo em Visual C++ usando um projeto de instalação](walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).

1. Crie um arquivo, nomeie-o setup.bat e adicione a ele os comandos a seguir. Altere `MyMFCApplication` para o nome do projeto.

    ```cmd
    @echo off
    vcredist_x86.exe
    mkdir "C:\Program Files\MyMFCApplication"
    copy MyMFCApplication.exe "C:\Program Files\MyMFCApplication"
    ```

1. Crie um arquivo de instalação autoextraível:

   1. No prompt de comando ou na janela **Executar**, execute iexpress.exe.

   1. Selecione **Criar novo arquivo de Diretiva de Extração Automática** e, em seguida, escolha o botão **Avançar**.

   1. Selecione **Extrair arquivos e executar um comando de instalação** e, em seguida, escolha **Avançar**.

   1. Na caixa de texto, insira o nome do aplicativo MFC e, em seguida, escolha **Avançar**.

   1. Na página **Solicitação de confirmação**, selecione **Nenhuma Solicitação** e, em seguida, escolha **Avançar**.

   1. Na página **Contrato de licença**, selecione **Não exibir uma licença** e, em seguida, escolha **Avançar**.

   1. Na página **Arquivos empacotados**, adicione os arquivos a seguir e, em seguida, escolha **Avançar**.

      - O aplicativo MFC (arquivo .exe).

      - vcredist_x86.exe. O arquivo está localizado em \Arquivos de Programas (x86)\Microsoft Visual Studio versão \<>\SDK\Bootstrapper\Packages\. Também é possível baixar este arquivo da [Microsoft](https://www.microsoft.com/download/confirmation.aspx?id=5555).

      - O arquivo setup.bat criado na etapa anterior.

   1. Na página **Programa de Instalação a ser Iniciado**,na caixa de texto **Programa de Instalação**, insira a linha de comando a seguir e, em seguida, escolha **Avançar**.

      **cmd.exe /c "setup.bat"**

   1. Na página **Mostrar janela**, selecione **Padrão** e, em seguida, escolha **Avançar**.

   1. Na página **Mensagem concluída**, selecione **Nenhuma mensagem** e, em seguida, escolha **Avançar**.

   1. Na página **Nome do Pacote e Opções**, insira um nome para o arquivo de instalação autoextraível, selecione a opção **Armazenar arquivos usando o Nome de Arquivo Longo dentro do pacote** e, em seguida, escolha **Avançar**. O fim do nome do arquivo precisa ser Setup.exe – por exemplo, *MyMFCApplicationSetup.exe*.

   1. Na página **Configurar reinicialização**, selecione **Nenhuma reinicialização** e, em seguida, escolha **Avançar**.

   1. Na página **Salvar Diretiva de Extração Automática**, selecione **Salvar arquivo de SED (Diretiva de Extração Automática)** e, em seguida, escolha **Avançar**.

   1. Na página **Criar pacote**, escolha **Avançar**. Escolha **Concluir**.

1. Teste o arquivo de instalação autoextraível no outro computador, que não tem as bibliotecas do Visual C++:

   1. No outro computador, baixe uma cópia do arquivo de instalação e, em seguida, instale-o executando-o e seguindo as etapas fornecidas. Dependendo das opções selecionadas, a instalação pode exigir o comando **Executar como administrador**.

   1. Execute o aplicativo MFC.

      O arquivo de instalação autoextraível instala o aplicativo MFC que está na pasta especificada na etapa 2. O aplicativo é executado com êxito porque o instalador do Pacote Redistribuível do Visual C++ está incluído no arquivo de instalação autoextraível.

      > [!IMPORTANT]
      > Para determinar qual versão do tempo de execução está instalada, o instalador verifica a chave do Registro \HKLM\SOFTWARE\Microsoft\VisualStudio\\versão\<>\VC\Runtimes\\<platform>. Se a versão atualmente instalada é mais recente do que a versão que o instalador está tentando instalar, o instalador retorna uma mensagem de êxito sem instalar a versão mais antiga e deixa uma entrada adicional na página de programas instalados no Painel de Controle.

## <a name="see-also"></a>Consulte também

[Exemplos de implantação](deployment-examples.md)<br/>
