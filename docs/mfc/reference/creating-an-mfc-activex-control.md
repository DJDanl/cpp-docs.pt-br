---
title: Criando um controle ActiveX MFC
ms.date: 08/19/2019
f1_keywords:
- vc.appwiz.activex.project
helpviewer_keywords:
- MFC ActiveX controls [MFC], creating
- ActiveX controls [MFC], creating
ms.assetid: 8bd5a93c-d04d-414e-bb28-163fdc1c0dd5
ms.openlocfilehash: 19e9ca6f985423bb01a8dea38988c5dcf7285683
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91505969"
---
# <a name="creating-an-mfc-activex-control"></a>Criando um controle ActiveX MFC

Os programas de controle ActiveX são programas modulares projetados para fornecer um tipo específico de funcionalidade a um aplicativo pai. Por exemplo, você pode criar um controle como um botão para uso em uma caixa de diálogo ou barra de ferramentas para uso em uma página da Web.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](../activex-controls.md).

A maneira mais fácil de criar um controle ActiveX MFC é usar o [Assistente de controle ActiveX do MFC](../../mfc/reference/mfc-activex-control-wizard.md).

### <a name="to-create-an-mfc-activex-control-using-the-mfc-activex-control-wizard"></a>Para criar um controle ActiveX do MFC usando o assistente de controle ActiveX do MFC

1. Siga as instruções no tópico da ajuda [criando um aplicativo MFC](creating-an-mfc-application.md) , mas escolha **controle ActiveX do MFC** na lista de modelos disponíveis.

1. Defina as [configurações do aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md), os [nomes de controle](../../mfc/reference/control-names-mfc-activex-control-wizard.md)e [as configurações de controle](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) usando o assistente de controle ActiveX do MFC.

    > [!NOTE]
    >  Ignore esta etapa para manter as configurações padrão do assistente.

1. Clique em **Concluir** para fechar o assistente e abrir o novo projeto no ambiente de desenvolvimento.

Depois de criar o projeto, você poderá exibir os arquivos criados no **Gerenciador de soluções**. Para saber mais sobre os arquivos que o assistente cria para seu projeto, veja o arquivo ReadMe.txt gerado pelo projeto. Para saber mais sobre os tipos de arquivo, confira [Tipos de arquivos criados para projetos do Visual Studio C++](../../build/reference/file-types-created-for-visual-cpp-projects.md).

Depois de criar seu projeto, você pode usar os assistentes de código para adicionar [funções](../../ide/adding-a-member-function-visual-cpp.md#add-member-function-wizard), [variáveis](../../ide/adding-a-member-variable-visual-cpp.md#add-member-variable-wizard), [eventos](../../ide/adding-an-event-visual-cpp.md#add-event-wizard), [Propriedades](../../ide/adding-a-property-visual-cpp.md#names-add-property-wizard)e [métodos](../../ide/adding-a-method-visual-cpp.md#add-method-wizard). Para obter mais informações sobre como personalizar o controle ActiveX, consulte [controles ActiveX do MFC](../../mfc/mfc-activex-controls.md).

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Páginas de propriedade](../../build/reference/property-pages-visual-cpp.md)
