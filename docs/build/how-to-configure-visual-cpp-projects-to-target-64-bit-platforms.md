---
title: 'Como: configurar projetos do Visual C++ para o destino de 64 bits x64 plataformas | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- platforms [C++], 64-bit
- 64-bit programming [C++], configuring projects
- project configurations [C++]
ms.assetid: 2b9ae001-df36-4750-83b2-982145d632ad
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3f1a4c9a27d4fdbbd57348c1fc2ce27301a1a95e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="how-to-configure-visual-c-projects-to-target-64-bit-x64-platforms"></a>Como: configurar projetos do Visual C++ para o destino de 64 bits x64 plataformas

Você pode usar as configurações do projeto no IDE do Visual Studio para configurar aplicativos C++ para o destino de 64 bits x64 plataformas. Você também pode migrar configurações de projeto Win32 em uma configuração de projeto de 64 bits.  
  
### <a name="to-set-up-c-applications-to-target-64-bit-platforms"></a>Para configurar aplicativos C++ para destinar plataformas de 64 bits  
  
1.  Abra o projeto C++ que você deseja configurar.  
  
2.  Abra as páginas de propriedades para o projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
    > [!NOTE]
    >  Para projetos do .NET, certifique-se de que o **propriedades de configuração** nó ou um de seus nós filho, é selecionado no  **\<Projectname > páginas de propriedade** caixa de diálogo; caso contrário, o  **Gerenciador de configuração** permanece indisponível.  
  
3.  Escolha o **do Configuration Manager** para abrir o **do Configuration Manager** caixa de diálogo.  
  
4.  No **plataforma de solução ativa** lista suspensa, selecione o  **\<novo... >** opção para abrir o **nova plataforma de solução** caixa de diálogo.  
  
5.  No **digite ou selecione a nova plataforma** lista suspensa, selecione 64 bits a plataforma de destino.  
  
    > [!NOTE]
    >  No **nova plataforma de solução** caixa de diálogo, você pode usar o **copiar configurações** opção para copiar as configurações de projeto existente para a nova configuração de projeto de 64 bits.  
  
6.  Escolha o botão **OK**. A plataforma que você selecionou na etapa anterior aparece sob **plataforma de solução ativa** no **do Configuration Manager** caixa de diálogo.  
  
7.  Escolha o **fechar** no botão o **do Configuration Manager** caixa de diálogo caixa e, em seguida, escolha o **Okey** no botão o  **\<Projectname > Páginas de propriedade** caixa de diálogo.  
  
### <a name="to-copy-win32-project-settings-into-a-64-bit-project-configuration"></a>Para copiar as configurações de projeto Win32 em uma configuração de projeto de 64 bits  
  
-   Quando o **nova plataforma de solução** caixa de diálogo estiver aberta enquanto você configurar um projeto para o destino de uma plataforma de 64 bits, além de **copiar configurações** lista suspensa, selecione **Win32**. Essas configurações de projeto são atualizadas automaticamente no nível de projeto:  
  
    -   O [/máquina](../build/reference/machine-specify-target-platform.md) opção de vinculador é definida como **/MACHINE:X 64**.  
  
    -   **Registrar saída** está desativado. Para obter mais informações, consulte [páginas de propriedade do vinculador](../ide/linker-property-pages.md).  
  
    -   **Ambiente de destino** é definido como **/env x64**. Para obter mais informações, consulte [páginas de propriedade MIDL: geral](../ide/midl-property-pages-general.md).  
  
    -   **Validar parâmetros** é apagado e redefinido para o valor padrão. Para obter mais informações, consulte [páginas de propriedade MIDL: avançado](../ide/midl-property-pages-advanced.md).  
  
    -   Se **formato informações de depuração** foi definida como **/ZI** na configuração de projeto Win32, em seguida, ele é definido como **/Zi** na configuração do projeto de 64 bits. Para obter mais informações, consulte [/Z7, /Zd, /Zi, /ZI (formato de informação de depuração)](../build/reference/z7-zi-zi-debug-information-format.md).  
  
    > [!NOTE]
    >  Nenhuma dessas propriedades de projeto são alteradas se elas são substituídas no nível de arquivo.  
  
## <a name="see-also"></a>Consulte também  

[Aplicativos de 64 bits do .NET framework](/dotnet/framework/64-bit-apps)   
[Configurar o Visual C++ para x64 de 64 bits, destinos](../build/configuring-programs-for-64-bit-visual-cpp.md)   
[Depurar aplicativos de 64 bits](/visualstudio/debugger/debug-64-bit-applications)