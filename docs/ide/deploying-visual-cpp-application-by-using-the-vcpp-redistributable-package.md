---
title: Implantar um aplicativo usando o pacote redistribuível (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- walkthrough, deploying a Visual C++ application by using the redistributable package
ms.assetid: e59becbf-b8c6-4c8e-bab3-b69cc1ed3e5e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 37bba00efdf0368973fa4ffbac1cbc6bb6298ce1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="walkthrough-deploying-a-visual-c-application-by-using-the-visual-c-redistributable-package"></a>Instruções passo a passo: implantando um aplicativo do Visual C++ usando o pacote redistribuível do Visual C++
Este artigo passo a passo descreve como usar o pacote redistribuível do Visual C++ para implantar um aplicativo do Visual C++.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Você deve ter esses componentes para concluir este passo a passo:  
  
-   Um computador que tenha instalado o Visual Studio.  
  
-   Um computador adicional que não tenha as bibliotecas do Visual C++.  
  
### <a name="to-use-the-visual-c-redistributable-package-to-deploy-an-application"></a>Para usar o pacote redistribuível do Visual C++ para implantar um aplicativo  
  
1.  Criar e compilar um aplicativo MFC, seguindo as três primeiras etapas no [passo a passo: Implantando um Visual C++ aplicativo usando um projeto de instalação](../ide/deploying-visual-cpp-application-by-using-the-vcpp-redistributable-package.md).  
  
2.  Criar um arquivo, nomeie bat e adicione os seguintes comandos a ele. Alterar `MyMFCApplication` para o nome do seu projeto.  
  
    ```cmd
    @echo off  
    vcredist_x86.exe  
    mkdir "C:\Program Files\MyMFCApplication"  
    copy MyMFCApplication.exe "C:\Program Files\MyMFCApplication"  
    ```  
  
3.  Crie um arquivo de instalação de extração automática:  
  
    1.  No prompt de comando ou no **executar** janela, execute iexpress.exe.  
  
    2.  Selecione **criar novo arquivo de diretiva auto-extraível** e, em seguida, escolha o **próximo** botão.  
  
    3.  Selecione **extrair arquivos e executar um comando de instalação** e, em seguida, escolha **próximo**.  
  
    4.  Na caixa de texto, digite o nome do seu aplicativo do MFC e, em seguida, escolha **próximo**.  
  
    5.  Sobre o **prompt de confirmação** página, selecione **nenhum Prompt** e, em seguida, escolha **próximo**.  
  
    6.  Sobre o **contrato de licença** página, selecione **não tiverem uma licença** e, em seguida, escolha **próximo**.  
  
    7.  Sobre o **os arquivos do pacote** página, adicione os seguintes arquivos e, em seguida, escolha **próximo**.  
  
        -   Seu aplicativo MFC (arquivo .exe).  
  
        -   vcredist_x86.exe. Esse arquivo está localizado em \Program Files\Microsoft SDKs\Windows\v7.0A\Bootstrapper\Packages\vcredist_x86\\.  
  
        -   O arquivo bat que você criou na etapa anterior.  
  
    8.  No **programa de instalação para iniciar o** página, o **instalar o programa** caixa de texto, digite a seguinte linha de comando e, em seguida, escolha **próximo**.  
  
         **cmd.exe /c "bat"**  
  
    9. Sobre o **Mostrar janela** página, selecione **padrão** e, em seguida, escolha **próximo**.  
  
    10. No **mensagem de conclusão** página, selecione **nenhuma mensagem** e, em seguida, escolha **próximo**.  
  
    11. No **nome do pacote e opções** página, insira um nome para o arquivo autoextraível de instalação, selecione o **armazenar arquivos usando o nome de arquivo longo dentro do pacote** opção e, em seguida, escolha **Avançar**. O fim do nome do arquivo deve ser Setup.exe—for exemplo, MyMFCApplicationSetup.exe.  
  
    12. Sobre o **configurar reinicialização** página, selecione **nenhuma reinicialização** e, em seguida, escolha **próximo**.  
  
    13. Sobre o **salvar diretiva auto-extraível** página, selecione **arquivo de diretiva de extração de autoatendimento (SED) salvar** e, em seguida, escolha **próximo**.  
  
    14. No **criar pacote** escolha **próximo**.  
  
4.  Teste o arquivo de instalação de extração automática no computador que não tem as bibliotecas do Visual C++:  
  
    1.  Em outro computador, baixe uma cópia do arquivo de instalação e instalá-lo, em seguida, executá-lo e seguindo as etapas que ele oferece.  
  
    2.  Execute o aplicativo do MFC.  
  
         O arquivo autoextraível do programa de instalação instala o aplicativo do MFC que está na pasta que você especificou na etapa 2. O aplicativo é executado com êxito porque o instalador do pacote redistribuível do Visual C++ está incluído no arquivo de instalação de extração automática.  
  
        > [!IMPORTANT]
        >  Para determinar qual versão do tempo de execução é instalado, o instalador verifica se o registro chave \HKLM\SOFTWARE\Microsoft\VisualStudio\11.0\VC\Runtimes\\[platform]. Se a versão atualmente instalada é mais recente do que a versão que o instalador está tentando instalar, o instalador retorna sucesso sem instalar a versão mais antiga e deixa uma entrada adicional na página de programas instalados no painel de controle.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplos de implantação](../ide/deployment-examples.md)