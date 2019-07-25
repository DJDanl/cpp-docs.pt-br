---
title: 'Como: Configurar projetos do C++ Visual Studio para direcionar plataformas de 64 bits e x64'
ms.date: 11/04/2016
helpviewer_keywords:
- platforms [C++], 64-bit
- 64-bit programming [C++], configuring projects
- project configurations [C++]
ms.assetid: 2b9ae001-df36-4750-83b2-982145d632ad
ms.openlocfilehash: 762fd5d6ddbb55713cf2fc5e34cb33fb91b08eb9
ms.sourcegitcommit: ce3393846c86e7905ff0c86e4cd6610476809585
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/25/2019
ms.locfileid: "68492238"
---
# <a name="how-to-configure-visual-studio-c-projects-to-target-64-bit-x64-platforms"></a>Como: Configurar projetos do C++ Visual Studio para direcionar plataformas de 64 bits e x64

Você pode usar as configurações do projeto no IDE do Visual Studio para configurar C++ aplicativos para as plataformas de 64 bits e x64 de destino. Você também pode migrar as configurações de projeto do Win32 para uma configuração de projeto de 64 bits.

### <a name="to-set-up-c-applications-to-target-64-bit-platforms"></a>Para configurar C++ aplicativos para plataformas de 64 bits de destino

1. Abra o C++ projeto que você deseja configurar.

1. Abra as páginas de propriedades para esse projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](working-with-project-properties.md).

   > [!NOTE]
   > Para projetos .net, certifique-se de que o nó **Propriedades de configuração** , ou um de seus nós filho, esteja selecionado na caixa de diálogo páginas de propriedades do  **\<ProjectName >** ; caso contrário, o botão **Configuration Manager** permanecerá indisponível.

1. Escolha o botão **Configuration Manager** para abrir a caixa de diálogo **Configuration Manager** .

1. Na lista suspensa **plataforma de solução ativa** , selecione a  **\<nova... >** opção para abrir a caixa de diálogo **nova plataforma de solução** .

1. Na lista suspensa **digite ou selecione a nova plataforma** , selecione uma plataforma de destino de 64 bits.

   > [!NOTE]
   > Na caixa de diálogo **nova plataforma de solução** , você pode usar a opção **copiar configurações de** para copiar as configurações de projeto existentes para a nova configuração de projeto de 64 bits.

1. Escolha o botão **OK**. A plataforma que você selecionou na etapa anterior aparece em **plataforma de solução ativa** na caixa de diálogo **Configuration Manager** .

1. Escolha o botão **fechar** na caixa de diálogo **Configuration Manager** e, em seguida, escolha o botão **OK** na caixa de diálogo páginas de  **\<Propriedades do ProjectName >** .

### <a name="to-copy-win32-project-settings-into-a-64-bit-project-configuration"></a>Para copiar as configurações de projeto do Win32 em uma configuração de projeto de 64 bits

- Quando a caixa de diálogo **nova plataforma de solução** é aberta enquanto você configura um projeto para direcionar uma plataforma de 64 bits, na lista suspensa **configurações de cópia** , selecione **Win32**. Essas configurações de projeto são atualizadas automaticamente no nível do projeto:

  - A opção vinculador [/Machine](reference/machine-specify-target-platform.md) é definida como **/Machine: x64**.

  - A **saída do registro** está desativada. Para obter mais informações, consulte [páginas de propriedades](reference/linker-property-pages.md)do vinculador.

  - O **ambiente de destino** é definido como **/env x64**. Para obter mais informações, consulte [páginas de propriedades de MIDL](reference/midl-property-pages.md).

  - Os **parâmetros de validação** são desmarcados e redefinidos para o valor padrão. Para obter mais informações, consulte [páginas de propriedades de MIDL](reference/midl-property-pages.md).

  - Se o **formato de informações de depuração** tiver sido definido como **/Zi** na configuração de projeto do Win32, ele será definido como **/Zi** na configuração de projeto de 64 bits. Para obter mais informações, consulte [/Z7, /Zd, /Zi, /ZI (formato de informação de depuração)](reference/z7-zi-zi-debug-information-format.md).

  > [!NOTE]
  > Nenhuma dessas propriedades de projeto será alterada se elas forem substituídas no nível de arquivo.

## <a name="see-also"></a>Consulte também

[Configurar projetos C++ para destinos x64 de 64 bits](configuring-programs-for-64-bit-visual-cpp.md)<br/>
[Depurar aplicativos de 64 bits](/visualstudio/debugger/debug-64-bit-applications)
