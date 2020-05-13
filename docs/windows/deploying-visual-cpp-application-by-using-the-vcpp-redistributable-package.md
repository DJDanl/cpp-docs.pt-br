---
title: Implantar um aplicativo usando o Pacote Redistribuível (C++)
ms.date: 04/23/2019
helpviewer_keywords:
- walkthrough, deploying a Visual C++ application by using the redistributable package
ms.assetid: e59becbf-b8c6-4c8e-bab3-b69cc1ed3e5e
ms.openlocfilehash: d2bd0794a67cf70b9da0499e3d2cafa553531fe1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370251"
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-the-visual-c-redistributable-package"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ usando o pacote redistribuível do Visual C++

Este artigo passo a passo descreve como usar o Pacote Redistribuível do Visual C++ para implantar um aplicativo do Visual C++.

## <a name="prerequisites"></a>Pré-requisitos

É necessário ter estes componentes para concluir este passo a passo:

- Um computador que tenha o Visual Studio instalado.

- Um computador adicional que não tenha as bibliotecas do Visual C++.

### <a name="to-use-the-visual-c-redistributable-package-to-deploy-an-application"></a>Para usar o Pacote Redistribuível do Visual C++ para implantar um aplicativo

1. Crie e compile um aplicativo MFC seguindo as etapas de [Passo a passo: Implantando um aplicativo do Visual C++ usando um projeto de instalação](walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md).

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

      - vcredist_x86.exe. No Visual Studio 2015, este arquivo está localizado em *%VCINSTALLDIR%redist\\1033\\*. No Visual Studio 2017 e visual studio 2019, este arquivo está localizado em *%VCToolsRedistDir%*. Você também pode [baixar o mais recente arquivo redist suportado da Microsoft](https://support.microsoft.com/help/2977003/the-latest-supported-visual-c-downloads).

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
      > Para determinar qual versão do tempo de execução está \\instalada,\\o\\\\instalador\\verifica a chave de registro HKLM SOFTWARE Microsoft VisualStudio_versão_\\VC\\Runtimes\\versão Versão da_plataforma._\\ Se a versão atualmente instalada é mais recente do que a versão que o instalador está tentando instalar, o instalador retorna uma mensagem de êxito sem instalar a versão mais antiga e deixa uma entrada adicional na página de programas instalados no Painel de Controle.

## <a name="see-also"></a>Confira também

[Exemplos de implantação](deployment-examples.md)<br/>
