---
title: Instalar o suporte a C11 e C17 no Visual Studio
description: Instalar SDK do Windows e suporte a CRT para C11 e C17 no Visual Studio
ms.date: 09/11/2020
helpviewer_keywords:
- Install preview Windows SDK
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
ms.openlocfilehash: 86de38feb66ab0a057005140d22cf0dd3b03d4cf
ms.sourcegitcommit: b492516cc65120250b9ea23f96f7f63f37f99fae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2020
ms.locfileid: "90079058"
---
# <a name="install-c11-and-c17-support-in-visual-studio"></a>Instalar o suporte a C11 e C17 no Visual Studio

::: moniker range="<=vs-2017"

O suporte para os padrões C11 e C17 requer o Visual Studio 2019 versão 16,8 ou posterior. Para ver a documentação desta versão, defina o controle do seletor de **versão** do Visual Studio para este artigo como Visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end

::: moniker range="vs-2019"

O suporte para os padrões C11 e C17 está disponível a partir do Visual Studio 2019 versão 16,8. O suporte requer um UCRT (tempo de execução universal C) atualizado e as últimas atualizações de SDK do Windows, para funcionar corretamente com o pré-processador () em conformidade [`/Zc:preprocessor`](../build/reference/zc-preprocessor.md) .

As versões SDK do Windows correspondem às versões do sistema operacional Windows. Como não houve uma versão do Windows com essas alterações, você precisará de uma *SDK do Windows Insider Preview*. Essa é uma versão de visualização do SDK do Windows que corresponde ao Windows Builds que estão sendo *comprovados*no momento, ou testados, por parte dos integrantes do Windows. Depois de instalar o SDK do Windows 10 do insider Preview, os projetos do Visual Studio configurados para usar o SDK do Windows mais recente usarão o Insider Preview.

## <a name="prerequisites"></a>Pré-requisitos

- Visual Studio 2019 versão 16,8 Preview 3 ou posterior instalado e em execução no seu computador. Na instalação, inclua o desenvolvimento de desktop com carga de trabalho do C++. Você pode baixar a versão prévia mais recente na página de [visualização do Visual Studio](https://visualstudio.microsoft.com/vs/preview/) . Se o Visual Studio ainda não estiver instalado, consulte [Instalar suporte a C++ no Visual Studio](../build/vscpp-step-0-installation.md) para obter instruções de instalação.

## <a name="step-1-sign-in-by-using-an-insider-microsoft-account"></a>Etapa 1: entrar usando uma conta do Microsoft Insider

Qualquer pessoa pode criar um [conta Microsoft](https://signup.live.com/) gratuito e, em seguida, optar pelo programa Insider. Acesse a página do [programa Windows Insider para desenvolvedores](https://insider.windows.com/for-developers) , escolha **registrar**e entre.

Depois de se registrar, você terá uma opção para iniciar o Flighting Insider versões do Windows. Essa etapa não é necessária para baixar e usar o SDK do Windows 10 do insider. Quando você se registra no Windows Insider, ele não aceita automaticamente que seus computadores baixem novos vôos do Windows.

Quando chegar à página **Bem-vindo ao programa Windows Insider** , você não precisará escolher **voo agora**. Continue na próxima etapa para baixar o SDK do Windows 10 do insider Preview.

## <a name="step-2-download-the-insider-preview-windows-10-sdk"></a>Etapa 2: baixar o SDK do Windows 10 do insider Preview

Você pode instalar o SDK do Windows do insider Preview na página de [downloads do Windows Insider Preview](https://www.microsoft.com/software-download/windowsinsiderpreviewSDK) . Se você vir uma mensagem dizendo "você precisa ser um membro do programa Windows Insider", verifique se você entrou. Use o mesmo conta Microsoft usado para o programa Insider. Se você vir uma mensagem dizendo "Lamentamos, a página solicitada não pode ser encontrada", tente alterar a localidade na URL para *en-US*.

A página Insider Claims que usa um sistema operacional Windows 10 Insider Preview é necessária. Ele só é válido para alguns dos conteúdos incluídos na SDK do Windows. Esse conteúdo pode depender de novas APIs que não estão presentes em versões anteriores do Windows. No entanto, os cabeçalhos de tempo de execução do Windows e do universal C podem ser instalados e utilizáveis sem um sistema operacional Insider.

Escolha **obter SDK Insider Preview – compilação 20211** (ou posterior) para iniciar o download. As versões posteriores do SDK do Windows também funcionarão.

## <a name="step-3-install-the-insider-preview-windows-10-sdk"></a>Etapa 3: instalar o SDK do Windows 10 do insider Preview

O Insider Preview SDK do Windows é baixado como um *`.iso`* arquivo. Abra a pasta que contém o arquivo baixado no explorador de arquivos. Monte o *`.iso`* arquivo e execute *`WinSDKSetup.exe`* para iniciar a instalação.

Na página **especificar local** , selecione **instalar o kit de desenvolvimento de software do Windows – \<version> para este computador**e, em seguida, escolha **Avançar**. Na página de **privacidade dos kits do Windows** , selecione se deseja permitir que a Microsoft colete informações para os kits do Windows 10 e escolha **Avançar**. Escolha **aceitar** para aceitar o contrato de licença. Na página **selecionar os recursos que você deseja instalar** , selecione apenas estes recursos:  

- Ferramentas de assinatura SDK do Windows para aplicativos da área de trabalho

- SDK do Windows para aplicativos gerenciados por UWP

- SDK do Windows para aplicativos UWP C++

- SDK do Windows para aplicativos desktop C++ x86 (se você planeja Compilar para x86)

- SDK do Windows para aplicativos do Desktop C++ amd64 (se você planeja Compilar para AMD64)

- SDK do Windows para aplicativos de ARM de Desktop C++ (se você planeja Compilar para ARM)

- SDK do Windows para aplicativos desktop C++ arm64 (se você planeja Compilar para arm64)

![Uma captura de tela do instalador do SDK do Windows, mostrando os componentes selecionados para instalação](media/c11-7-windows-sdk-installer-select-features.png)

Escolha **instalar** para instalar os componentes do SDK selecionados. O SDK leva alguns minutos para concluir a instalação. Ao concluir, abra o Visual Studio.

## <a name="step-4-configuring-c11-or-c17-mode-in-visual-studio"></a>Etapa 4: Configurando o modo C11 ou C17 no Visual Studio

No Visual Studio, abra um projeto C novo ou existente e, em seguida, abra a caixa de diálogo **páginas de propriedades** do projeto.

Defina o projeto para usar o SDK de visualização do Windows 10 para os lados. Na página **Propriedades de configuração**  >  **geral** , defina a propriedade **SDK do Windows versão** como **10,0 (versão mais recente instalada)** ou para a versão de visualização específica que você instalou.

Você também verá uma nova opção: **C Language Standard**. Defina essa propriedade como **ISO C11 Standard ( `/std:c11` )** ou **ISO C17 (2018) Standard ( `/std:c17` )**.  

![Uma captura de tela da caixa de diálogo páginas de propriedades na página Propriedades de configuração geral, mostrando a seleção suspensa da propriedade padrão C Language como ISO C 17](media/c11-9-project-property-page-c-language-standard.png)

O padrão de linguagem C++ é usado quando o idioma é C++. É o padrão quando a extensão de arquivo é *`.cpp`* . A versão padrão da linguagem C é usada quando o idioma é C. É o padrão quando a extensão de arquivo é *`.c`* . Para criar usando C11 ou C17, coloque o código-fonte em um *`.c`* arquivo ou defina o código para compilar como C. Você pode definir essa propriedade para seu projeto na página de **Propriedades de configuração**  >  **C/C++**  >  **Advanced** . Defina a propriedade **compile as** para **Compilar como código C (/TC)**.

Parabéns, você configurou tudo o que precisa para criar o C11 e o código C17 no Visual Studio 2019 versão 16,8 Preview 3!

## <a name="see-also"></a>Confira também

[`/std` (Especifique a versão padrão do idioma)](../build/reference/std-specify-language-standard-version.md)

::: moniker-end
