---
title: Criando um controle ActiveX MFC
ms.date: 09/12/2018
f1_keywords:
- vc.appwiz.activex.project
helpviewer_keywords:
- MFC ActiveX controls [MFC], creating
- ActiveX controls [MFC], creating
ms.assetid: 8bd5a93c-d04d-414e-bb28-163fdc1c0dd5
ms.openlocfilehash: be0b4639fd42461a19db10f88ced336cd1129fb3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50633501"
---
# <a name="creating-an-mfc-activex-control"></a>Criando um controle ActiveX MFC

Programas de controle ActiveX são programas modulares projetados para dar a um tipo específico de funcionalidade a um aplicativo pai. Por exemplo, você pode criar um controle como um botão para uso em uma caixa de diálogo ou barra de ferramentas para uso em uma página da Web.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](../activex-controls.md).

A maneira mais fácil de criar um controle ActiveX do MFC é usar o [Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md).

### <a name="to-create-an-mfc-activex-control-using-the-mfc-activex-control-wizard"></a>Para criar um controle ActiveX do MFC usando o Assistente de controle ActiveX MFC

1. Siga as instruções do tópico da Ajuda [Criando um projeto com um assistente de aplicativo do Visual C++](../../ide/creating-desktop-projects-by-using-application-wizards.md).

1. No **novo projeto** caixa de diálogo, selecione o **controle ActiveX do MFC** ícone no painel de modelos para abrir o Assistente de controle de ActiveX do MFC.

1. Definir sua [configurações do aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md), [nomes de controle](../../mfc/reference/control-names-mfc-activex-control-wizard.md), e [controlar as configurações](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) usando o Assistente de controle de ActiveX do MFC.

    > [!NOTE]
    >  Ignore esta etapa para manter o Assistente de configurações padrão.

1. Clique em **concluir** para fechar o assistente e abrir o novo projeto no ambiente de desenvolvimento.

Depois de ter criado seu projeto, você pode exibir os arquivos criados na **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo gerado pelo projeto Readme. txt. Para obter mais informações sobre os tipos de arquivo, consulte [tipos de arquivo criados para projetos do Visual C++](../../ide/file-types-created-for-visual-cpp-projects.md).

Depois de ter criado seu projeto, você pode usar os assistentes de código para adicionar [funções](../../ide/add-member-function-wizard.md), [variáveis](../../ide/add-member-variable-wizard.md), [eventos](../../ide/add-event-wizard.md), [propriedades](../../ide/names-add-property-wizard.md), e [métodos](../../ide/add-method-wizard.md). Para obter mais informações sobre como personalizar o seu controle ActiveX, consulte [controles ActiveX do MFC](../../mfc/mfc-activex-controls.md).

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedade](../../ide/property-pages-visual-cpp.md)

