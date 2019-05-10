---
title: 'Como: Configurar o Visual Studio C++ plataformas de projetos para o destino de 64 bits, x64'
ms.date: 11/04/2016
helpviewer_keywords:
- platforms [C++], 64-bit
- 64-bit programming [C++], configuring projects
- project configurations [C++]
ms.assetid: 2b9ae001-df36-4750-83b2-982145d632ad
ms.openlocfilehash: a063c2f333a755ab86a4f91c9d14d0c65a6d1414
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65446401"
---
# <a name="how-to-configure-visual-studio-c-projects-to-target-64-bit-x64-platforms"></a>Como: Configurar o Visual Studio C++ plataformas de projetos para o destino de 64 bits, x64

Você pode usar as configurações do projeto no IDE do Visual Studio para configurar plataformas de aplicativos do C++ para ter como destino de 64 bits x64. Também é possível migrar as configurações de projeto do Win32 em uma configuração de projeto de 64 bits.

### <a name="to-set-up-c-applications-to-target-64-bit-platforms"></a>Para configurar aplicativos do C++ para direcionar as plataformas de 64 bits

1. Abra o projeto de C++ que você deseja configurar.

1. Abra as páginas de propriedades para o projeto. Para obter mais informações, consulte [propriedades de compilador e de build definida C++ no Visual Studio](working-with-project-properties.md).

   > [!NOTE]
   > Para projetos do .NET, certifique-se de que o **propriedades de configuração** nó ou um de seus nós filho, é selecionado na  **\<Projectname > páginas de propriedade** caixa de diálogo; caso contrário, o  **Configuration Manager** botão permanece indisponível.

1. Escolha o **Configuration Manager** para abrir o **Configuration Manager** caixa de diálogo.

1. No **plataforma de solução ativa** lista suspensa, selecione o  **\<novo... >** opção para abrir o **nova plataforma de solução** caixa de diálogo.

1. No **digite ou selecione a nova plataforma** lista suspensa, selecione um valor de 64-bit plataforma de destino.

   > [!NOTE]
   > No **nova plataforma de solução** caixa de diálogo, você pode usar o **copiar configurações de** opção para copiar as configurações de projeto existente para a nova configuração de projeto de 64 bits.

1. Escolha o botão **OK**. A plataforma que você selecionou na etapa anterior aparece sob **plataforma de solução ativa** na **Configuration Manager** caixa de diálogo.

1. Escolha o **fechar** botão na **Configuration Manager** caixa de diálogo caixa e, em seguida, escolha o **Okey** botão no  **\<Projectname > Páginas de propriedade** caixa de diálogo.

### <a name="to-copy-win32-project-settings-into-a-64-bit-project-configuration"></a>Para copiar as configurações de projeto do Win32 em uma configuração de projeto de 64 bits

- Quando o **nova plataforma de solução** caixa de diálogo estiver aberta enquanto você configurar um projeto tenha como destino uma plataforma de 64 bits, além de **copiar configurações de** lista suspensa, selecione **Win32**. Essas configurações do projeto são atualizadas automaticamente no nível do projeto:

  - O [/máquina](reference/machine-specify-target-platform.md) opção de vinculador é definida como **/MACHINE:X 64**.

  - **Registrar saída** é desativada. Para obter mais informações, consulte [páginas de propriedade do vinculador](reference/linker-property-pages.md).

  - **Ambiente de destino** é definido como **/env x64**. Para obter mais informações, consulte [páginas de propriedade MIDL: Geral](reference/midl-property-pages-general.md).

  - **Validar parâmetros** é apagado e redefinido para o valor padrão. Para obter mais informações, consulte [páginas de propriedade MIDL: Advanced](reference/midl-property-pages-advanced.md).

  - Se **formato de informações de depuração** foi definida como **/ZI** na configuração do projeto do Win32, em seguida, ele é definido como **/Zi** na configuração do projeto de 64 bits. Para obter mais informações, consulte [/Z7, /Zd, /Zi, /ZI (formato de informação de depuração)](reference/z7-zi-zi-debug-information-format.md).

  > [!NOTE]
  > Nenhuma dessas propriedades de projeto são alteradas se elas são substituídas no nível de arquivo.

## <a name="see-also"></a>Consulte também

[Configurar projetos do C++ para x64 de 64 bits, destinos](configuring-programs-for-64-bit-visual-cpp.md)<br/>
[Depurar aplicativos de 64 bits](/visualstudio/debugger/debug-64-bit-applications)
